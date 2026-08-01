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


// dummy for non embedded access
template<typename RegisterWidth, std::uintptr_t BaseAddress, RegisterWidth ResetValue, typename RegisterType, details::FixedString Name, typename... Fields>
class Register
{
  public:
    Register &operator=(RegisterWidth bitMask)
        requires details::WriteConcept<RegisterType>
    {
        assign(bitMask);
        return *this;
    }

    template<typename T = RegisterType>
        requires details::ReadConcept<T>
    RegisterWidth operator()(const RegisterWidth mask) const
    {
        return value() & mask;
    }

    [[nodiscard]] RegisterWidth read([[maybe_unused]] auto value) const
        requires details::ReadConcept<RegisterType> && (decltype(value)::readAction == details::ReadAction::None)
    {
        using BitFieldType = decltype(value);
        static_assert((std::is_same_v<std::remove_cvref_t<BitFieldType>, std::remove_cvref_t<Fields>> || ...), "Bitfield not defined for register");
        return (this->value() & BitFieldType::mask) >> BitFieldType::bitOffset;
    }

    [[nodiscard]] RegisterWidth operator()() const
        requires details::ReadConcept<RegisterType>
    {
        return value();
    }

    void operator|=(RegisterWidth bitMask)
        requires details::WriteConcept<RegisterType>
    {
        assign(static_cast<RegisterWidth>(value() | bitMask));
    }

    template<typename Field>
        requires details::WriteConcept<RegisterType> && details::WriteConcept<decltype(Field::Type)>
    void operator|=([[maybe_unused]] Field field)
    {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...), "Bitfield not defined for register");
        static_assert(field.bitWidth == 1U, "bitWidth is greater 1, please call write operation!");
        assign(static_cast<RegisterWidth>(value() | Field::mask));
    }

    void operator&=(RegisterWidth bitMask)
        requires details::WriteConcept<RegisterType>
    {
        assign(static_cast<RegisterWidth>(value() & bitMask));
    }

    template<typename Field>
        requires details::WriteConcept<RegisterType> && details::WriteConcept<decltype(Field::Type)>
    void operator&=([[maybe_unused]] Field field)
    {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...), "Bitfield not defined for register");
        static_assert(field.bitWidth == 1U, "bitWidth is greater 1, please call write operation!");
        assign(static_cast<RegisterWidth>(value() & Field::mask));
    }

    void operator^=(RegisterWidth bitMask)
        requires details::WriteConcept<RegisterType>
    {
        assign(static_cast<RegisterWidth>(value() ^ bitMask));
    }

    template<typename Field>
        requires details::WriteConcept<RegisterType> && details::WriteConcept<decltype(Field::Type)>
    void operator^=([[maybe_unused]] Field field)
    {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...), "Bitfield not defined for register");
        static_assert(field.bitWidth == 1U, "bitWidth is greater 1, please call write operation!");
        assign(static_cast<RegisterWidth>(value() ^ Field::mask));
    }

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

    template<typename Field>
        requires details::WriteConcept<RegisterType> && details::WriteConcept<decltype(Field::Type)>
    void replace([[maybe_unused]] Field field, const RegisterWidth fieldValue)
    {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...), "Bitfield not defined for register");
        const auto encodedValue = static_cast<RegisterWidth>((fieldValue << Field::bitOffset) & Field::mask);
        assign(static_cast<RegisterWidth>((value() & ~Field::mask) | encodedValue));
    }

    template<typename Field>
        requires details::WriteConcept<RegisterType> && details::WriteConcept<decltype(Field::Type)>
              && requires { typename Field::EnumType; }
    void set([[maybe_unused]] Field field, const typename Field::EnumType fieldValue)
    {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...), "Bitfield not defined for register");
        assign(static_cast<RegisterWidth>((value() & ~Field::mask) | Field::encode(fieldValue)));
    }

    template<typename Field>
        requires details::WriteConcept<RegisterType> && details::WriteConcept<decltype(Field::Type)>
              && (Field::modifiedWriteValue == details::ModifiedWriteValue::OneToClear)
    void clear([[maybe_unused]] Field field)
    {
        assign(static_cast<RegisterWidth>(Field::mask));
    }

    template<typename Field>
        requires details::WriteConcept<RegisterType> && details::WriteConcept<decltype(Field::Type)>
              && (Field::modifiedWriteValue == details::ModifiedWriteValue::OneToSet)
    void set([[maybe_unused]] Field field)
    {
        assign(static_cast<RegisterWidth>(Field::mask));
    }

    template<typename Field>
        requires details::WriteConcept<RegisterType> && details::WriteConcept<decltype(Field::Type)>
              && (Field::modifiedWriteValue == details::ModifiedWriteValue::OneToToggle)
    void toggle([[maybe_unused]] Field field)
    {
        assign(static_cast<RegisterWidth>(Field::mask));
    }

    template<typename Field>
        requires details::ReadConcept<RegisterType> && (Field::readAction == details::ReadAction::Clear)
    [[nodiscard]] RegisterWidth readAndClear([[maybe_unused]] Field field) const
    {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...), "Bitfield not defined for register");
        return (value() & Field::mask) >> Field::bitOffset;
    }

    void reset()
    {
#ifndef TYPESAFE_REGISTER_MMIO
    rawPtr = ResetValue;
#endif
    }

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
    RegisterWidth rawPtr{ ResetValue };
#endif
};
