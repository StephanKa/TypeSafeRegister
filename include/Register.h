#pragma once
#ifdef ENABLE_OUTPUT

#include <array>
#include <Output.h>

#endif
#include <AssignmentOperations.h>
#include <BitName.h>
#include <BitInfo.h>
#include <cstdint>
#include <details.h>
#include <limits>
#include <SvdTypes.h>
#include <string_view>


/**
 * @brief Type-safe view of an SVD register.
 *
 * Host builds store a simulated register value initialized from @p ResetValue.
 * Builds with `TYPESAFE_REGISTER_MMIO` access the volatile hardware address.
 * @tparam RegisterWidth Unsigned storage type of the register.
 * @tparam BaseAddress Memory-mapped address of the hardware register.
 * @tparam ResetValue SVD reset value used by host simulation.
 * @tparam RegisterType SVD access permission type.
 * @tparam Name Generated register name.
 * @tparam Fields Generated field descriptor types owned by this register.
 */
template<typename RegisterWidth, std::uintptr_t BaseAddress, RegisterWidth ResetValue, typename RegisterType, details::FixedString Name, typename... Fields>
class Register
{
  public:
    /**
     * @brief Replace the complete register value.
     * @param bitMask New register value.
     * @return Reference to this register.
     */
    Register &operator=(RegisterWidth bitMask)
        requires details::WriteConcept<RegisterType>
    {
        assign(bitMask);
        return *this;
    }

    /**
     * @brief Read the register with an additional mask applied.
     * @tparam T Access type used to constrain reading.
     * @param mask Bits to retain from the register value.
     * @return Masked register value.
     */
    template<typename T = RegisterType>
        requires details::ReadConcept<T>
    RegisterWidth operator()(const RegisterWidth mask) const
    {
        return value() & mask;
    }

    /**
     * @brief Read one field as an unshifted value when it has no read side effect.
     * @param value Generated field descriptor.
     * @return Unshifted field value.
     */
    [[nodiscard]] RegisterWidth read([[maybe_unused]] auto value) const
        requires details::ReadConcept<RegisterType> && (decltype(value)::readAction == details::ReadAction::None)
    {
        using BitFieldType = decltype(value);
        static_assert((std::is_same_v<std::remove_cvref_t<BitFieldType>, std::remove_cvref_t<Fields>> || ...), "Bitfield not defined for register");
        return (this->value() & BitFieldType::mask) >> BitFieldType::bitOffset;
    }

    /**
     * @brief Read the complete register value.
     * @return Current register value.
     */
    [[nodiscard]] RegisterWidth operator()() const
        requires details::ReadConcept<RegisterType>
    {
        return value();
    }

    /**
     * @brief Set all bits selected by @p bitMask.
     * @param bitMask Bits to set.
     */
    void operator|=(RegisterWidth bitMask)
        requires details::WriteConcept<RegisterType>
    {
        assign(static_cast<RegisterWidth>(value() | bitMask));
    }

    /**
     * @brief Set a single-bit field.
     * @tparam Field Field descriptor type.
     * @param field Field to set.
     */
    template<typename Field>
        requires details::WriteConcept<RegisterType> && details::WriteConcept<decltype(Field::Type)>
    void operator|=([[maybe_unused]] Field field)
    {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...), "Bitfield not defined for register");
        static_assert(field.bitWidth == 1U, "bitWidth is greater 1, please call write operation!");
        assign(static_cast<RegisterWidth>(value() | Field::mask));
    }

    /**
     * @brief Clear bits selected by @p bitMask.
     * @param bitMask Bits retained by the AND operation.
     */
    void operator&=(RegisterWidth bitMask)
        requires details::WriteConcept<RegisterType>
    {
        assign(static_cast<RegisterWidth>(value() & bitMask));
    }

    /**
     * @brief Apply an AND operation using a single-bit field mask.
     * @tparam Field Field descriptor type.
     * @param field Field mask.
     */
    template<typename Field>
        requires details::WriteConcept<RegisterType> && details::WriteConcept<decltype(Field::Type)>
    void operator&=([[maybe_unused]] Field field)
    {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...), "Bitfield not defined for register");
        static_assert(field.bitWidth == 1U, "bitWidth is greater 1, please call write operation!");
        assign(static_cast<RegisterWidth>(value() & Field::mask));
    }

    /**
     * @brief Toggle bits selected by @p bitMask.
     * @param bitMask Bits to toggle.
     */
    void operator^=(RegisterWidth bitMask)
        requires details::WriteConcept<RegisterType>
    {
        assign(static_cast<RegisterWidth>(value() ^ bitMask));
    }

    /**
     * @brief Toggle a single-bit field.
     * @tparam Field Field descriptor type.
     * @param field Field to toggle.
     */
    template<typename Field>
        requires details::WriteConcept<RegisterType> && details::WriteConcept<decltype(Field::Type)>
    void operator^=([[maybe_unused]] Field field)
    {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...), "Bitfield not defined for register");
        static_assert(field.bitWidth == 1U, "bitWidth is greater 1, please call write operation!");
        assign(static_cast<RegisterWidth>(value() ^ Field::mask));
    }

    /**
     * @brief Apply a selected assignment operation to a multi-bit field.
     * @tparam Field Field descriptor type.
     * @tparam Operator Assignment operation tag.
     * @param field Field to update.
     * @param value Unshifted field value.
     * @param operation Selects OR, AND, or XOR assignment.
     */
    template<typename Field, typename Operator = OrAssign>
        requires details::WriteConcept<RegisterType> && details::WriteConcept<decltype(Field::Type)>
    void write(Field field, RegisterWidth value, [[maybe_unused]] Operator operation)
    {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...), "Bitfield not defined for register");
        static_assert(field.bitWidth > 1U, "bitWidth is equal to 1, use | or & operator!");
        if constexpr (std::is_same_v<Operator, OrAssign>) {
            assign(static_cast<RegisterWidth>(this->value() | ((value << field.bitOffset) & field.mask)));
        } else if constexpr (std::is_same_v<Operator, AndAssign>) {
            assign(static_cast<RegisterWidth>(this->value() & ((value << field.bitOffset) & field.mask)));
        } else if constexpr (std::is_same_v<Operator, ExclusiveOrAssign>) {
            assign(static_cast<RegisterWidth>(this->value() ^ ((value << field.bitOffset) & field.mask)));
        }
    }

    /**
     * @brief Replace a multi-bit field without modifying neighboring bits.
     * @tparam Field Field descriptor type.
     * @param field Field to replace.
     * @param fieldValue Unshifted replacement value.
     */
    template<typename Field>
        requires details::WriteConcept<RegisterType> && details::WriteConcept<decltype(Field::Type)>
    void replace([[maybe_unused]] Field field, const RegisterWidth fieldValue)
    {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...), "Bitfield not defined for register");
        const auto encodedValue = static_cast<RegisterWidth>((fieldValue << Field::bitOffset) & Field::mask);
        assign(static_cast<RegisterWidth>((value() & ~Field::mask) | encodedValue));
    }

    /**
     * @brief Replace an enumerated field with a generated enum value.
     * @tparam Field Enumerated field descriptor type.
     * @param field Field to replace.
     * @param fieldValue Generated enum value.
     */
    template<typename Field>
        requires details::WriteConcept<RegisterType> && details::WriteConcept<decltype(Field::Type)>
              && requires { typename Field::EnumType; }
    void set([[maybe_unused]] Field field, const typename Field::EnumType fieldValue)
    {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...), "Bitfield not defined for register");
        assign(static_cast<RegisterWidth>((value() & ~Field::mask) | Field::encode(fieldValue)));
    }

    /**
     * @brief Issue a write-one-to-clear command for an SVD field.
     * @tparam Field Field descriptor type.
     * @param field Field to clear.
     */
    template<typename Field>
        requires details::WriteConcept<RegisterType> && details::WriteConcept<decltype(Field::Type)>
              && (Field::modifiedWriteValue == details::ModifiedWriteValue::OneToClear)
    void clear([[maybe_unused]] Field field)
    {
        assign(static_cast<RegisterWidth>(Field::mask));
    }

    /**
     * @brief Issue a write-one-to-set command for an SVD field.
     * @tparam Field Field descriptor type.
     * @param field Field to set.
     */
    template<typename Field>
        requires details::WriteConcept<RegisterType> && details::WriteConcept<decltype(Field::Type)>
              && (Field::modifiedWriteValue == details::ModifiedWriteValue::OneToSet)
    void set([[maybe_unused]] Field field)
    {
        assign(static_cast<RegisterWidth>(Field::mask));
    }

    /**
     * @brief Issue a write-one-to-toggle command for an SVD field.
     * @tparam Field Field descriptor type.
     * @param field Field to toggle.
     */
    template<typename Field>
        requires details::WriteConcept<RegisterType> && details::WriteConcept<decltype(Field::Type)>
              && (Field::modifiedWriteValue == details::ModifiedWriteValue::OneToToggle)
    void toggle([[maybe_unused]] Field field)
    {
        assign(static_cast<RegisterWidth>(Field::mask));
    }

    /**
     * @brief Read a field whose SVD readAction clears it.
     * @tparam Field Field descriptor type.
     * @param field Field to read.
     * @return Unshifted field value before the SVD side effect.
     */
    template<typename Field>
        requires details::ReadConcept<RegisterType> && (Field::readAction == details::ReadAction::Clear)
    [[nodiscard]] RegisterWidth readAndClear([[maybe_unused]] Field field) const
    {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...), "Bitfield not defined for register");
        const auto registerValue = value();
    #ifndef TYPESAFE_REGISTER_MMIO
        rawPtr = static_cast<RegisterWidth>(registerValue & ~Field::mask);
    #endif
        return (registerValue & Field::mask) >> Field::bitOffset;
    }

    /** @brief Restore the SVD reset value in host simulation builds. */
    void reset()
    {
#ifndef TYPESAFE_REGISTER_MMIO
    rawPtr = ResetValue;
#endif
    }

    /** @brief Print a register field map when `ENABLE_OUTPUT` is enabled. */
    void dump()
    {
#ifdef ENABLE_OUTPUT
        using namespace std::string_view_literals;
        if constexpr (sizeof...(Fields) > 0) {
            constexpr auto horizontalLine = "|{:-^41}|\n"sv;
            constexpr auto bitContentSingleWidth = "|{0:^20}{1:^20} | <-- Bit {2}\n"sv;
            constexpr auto bitContentMultipleWidth = "|{0:^20}{1:^20} | <-- Bit {2} - {3}\n"sv;
            details::print("Register name: {:^12}\n", name);
            std::array<BitInfo, std::numeric_limits<RegisterWidth>::digits> bitInfos;
            std::apply(
              [&](auto &...) {
                  ((bitInfos[Fields::bitOffset] = BitInfo{ Fields::bitWidth, details::TypeMap.getValue(&typeid(Fields::Type)).value(), BitName{ Fields::name } }), ...);
              },
              bitInfos);
            size_t offset = 0;
            for (auto iter = bitInfos.begin(); iter != bitInfos.end(); ++iter, ++offset) {
                details::print(horizontalLine, "");
                if (iter->bitWidth > 1) {
                    details::print(bitContentMultipleWidth, iter->name, iter->type, offset, offset + iter->bitWidth - 1);
                } else {
                    details::print(bitContentSingleWidth, iter->name, iter->type, offset);
                }
                for (size_t i = 1; i < iter->bitWidth; i++) {
                    ++offset;
                    ++iter;
                    details::print("|{0:^40} |\n", "");
                }
            }
            details::print(horizontalLine, "");
        }
#endif
    }

  private:
    [[nodiscard]] RegisterWidth value() const
    {
#ifdef TYPESAFE_REGISTER_MMIO
        return *reinterpret_cast<volatile const RegisterWidth *>(BaseAddress);
#else
        return rawPtr;
#endif
    }

    void assign(const RegisterWidth registerValue)
    {
#ifdef TYPESAFE_REGISTER_MMIO
        *reinterpret_cast<volatile RegisterWidth *>(BaseAddress) = registerValue;
#else
        rawPtr = registerValue;
#endif
    }

    static constexpr char const *name = Name;
#ifndef TYPESAFE_REGISTER_MMIO
    mutable RegisterWidth rawPtr{ ResetValue };
#endif
};
