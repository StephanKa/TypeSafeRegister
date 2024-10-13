#pragma once
#ifdef USE_FMT

#include <fmt/format.h>
#include <array>

#endif
#include <AssignmentOperations.h>
#include <BitName.h>
#include <BitInfo.h>
#include <cstdint>
#include <details.h>
#include <limits>
#include <string_view>


// dummy for non embedded access
template<typename RegisterWidth, std::uintptr_t BaseAddress, RegisterWidth ResetValue, typename RegisterType, details::FixedString Name, typename... Fields>
class Register
{
  public:
    Register &operator=(RegisterWidth bitMask)
    {
        write<RegisterType>(bitMask);
        return *this;
    }

    template<typename T = RegisterType>
        requires details::ReadConcept<T>
    RegisterWidth operator()(const RegisterWidth mask) const
    {
        return rawPtr & mask;
    }

    [[nodiscard]] RegisterWidth read([[maybe_unused]] auto value) const
        requires details::ReadConcept<RegisterType>
    {
        using BitFieldType = decltype(value);
        static_assert((std::is_same_v<std::remove_cvref_t<BitFieldType>, std::remove_cvref_t<Fields>> || ...), "Bitfield not defined for register");
        return (rawPtr & BitFieldType::mask) >> BitFieldType::bitOffset;
    }

    [[nodiscard]] RegisterWidth operator()() const
        requires details::ReadConcept<RegisterType>
    {
        return static_cast<RegisterWidth>(rawPtr & static_cast<decltype(rawPtr)>(std::numeric_limits<RegisterWidth>::max()));
    }

    void operator|=(RegisterWidth bitMask)
        requires details::WriteConcept<RegisterType>
    {
        rawPtr |= bitMask;
    }

    template<typename Field>
        requires details::WriteConcept<decltype(Field::Type)>
    void operator|=([[maybe_unused]] Field field)
    {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...), "Bitfield not defined for register");
        static_assert(field.bitWidth == 1U, "bitWidth is greater 1, please call write operation!");
        rawPtr |= static_cast<RegisterWidth>(Field::mask);
    }

    template<typename Field>
        requires details::WriteConcept<decltype(Field::Type)>
    void operator&=(RegisterWidth bitMask)
    {
        rawPtr &= bitMask;
    }

    template<typename Field>
        requires details::WriteConcept<decltype(Field::Type)>
    void operator&=([[maybe_unused]] Field field)
    {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...), "Bitfield not defined for register");
        static_assert(field.bitWidth == 1U, "bitWidth is greater 1, please call write operation!");
        rawPtr &= static_cast<RegisterWidth>(Field::mask);
    }

    template<typename Field>
        requires details::WriteConcept<decltype(Field::Type)>
    void operator^=(RegisterWidth bitMask)
    {
        rawPtr ^= bitMask;
    }

    template<typename Field>
        requires details::WriteConcept<decltype(Field::Type)>
    void operator^=([[maybe_unused]] Field field)
    {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...), "Bitfield not defined for register");
        static_assert(field.bitWidth == 1U, "bitWidth is greater 1, please call write operation!");
        rawPtr ^= static_cast<RegisterWidth>(Field::mask);
    }

    template<typename Field, typename Operator = OrAssign>
        requires details::WriteConcept<decltype(Field::Type)>
    void write(Field field, RegisterWidth value, [[maybe_unused]] Operator operation)
    {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...), "Bitfield not defined for register");
        static_assert(field.bitWidth > 1U, "bitWidth is equal to 1, use | or & operator!");
        if constexpr (std::is_same_v<Operator, OrAssign>) {
            rawPtr |= static_cast<RegisterWidth>((value << field.bitOffset) & field.mask);
        } else if constexpr (std::is_same_v<Operator, AndAssign>) {
            rawPtr &= static_cast<RegisterWidth>((value << field.bitOffset) & field.mask);
        } else if constexpr (std::is_same_v<Operator, ExclusiveOrAssign>) {
            rawPtr ^= static_cast<RegisterWidth>((value << field.bitOffset) & field.mask);
        }
    }

    void reset()
    {
#ifdef USE_FMT
        rawPtr = ResetValue;
#endif
    }

    void dump()
    {
#ifdef USE_FMT
        using namespace std::string_view_literals;
        if constexpr (sizeof...(Fields) > 0) {
            constexpr auto horizontalLine = "|{:-^41}|\n"sv;
            constexpr auto bitContentSingleWidth = "|{0:^20}{1:^20} | <-- Bit {2}\n"sv;
            constexpr auto bitContentMultipleWidth = "|{0:^20}{1:^20} | <-- Bit {2} - {3}\n"sv;
            fmt::print("Register name: {:^12}\n", name);
            std::array<BitInfo, std::numeric_limits<RegisterWidth>::digits> bitInfos;
            std::apply(
              [&](auto &...) {
                  ((bitInfos[Fields::bitOffset] = BitInfo{ Fields::bitWidth, details::TypeMap[typeid(Fields::Type)], BitName{ Fields::name } }), ...);
              },
              bitInfos);
            size_t offset = 0;
            for (auto iter = bitInfos.begin(); iter != bitInfos.end(); ++iter, ++offset) {
                fmt::print(horizontalLine, "");
                if (iter->bitWidth > 1) {
                    fmt::print(bitContentMultipleWidth, iter->name, iter->type, offset, offset + iter->bitWidth - 1);
                } else {
                    fmt::print(bitContentSingleWidth, iter->name, iter->type, offset);
                }
                for (size_t i = 1; i < iter->bitWidth; i++) {
                    ++offset;
                    ++iter;
                    fmt::print("|{0:^40} |\n", "");
                }
            }
            fmt::print(horizontalLine, "");
        }
#endif
    }

  private:
#ifdef USE_FMT
    std::uintptr_t rawPtr{ ResetValue };

    static constexpr char const *name = Name;
#else
    std::uintptr_t rawPtr{ BaseAddress };
#endif
};
