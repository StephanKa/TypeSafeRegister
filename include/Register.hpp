#pragma once
#ifdef USE_FMT

#include <fmt/format.h>

#endif

#include <array>
#include <cstdint>
#include <limits>
#include <map>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <typeindex>

struct READONLY {
};

struct WRITEONLY {
};

struct READWRITE
        : READONLY, WRITEONLY {
};

struct BitType {
    constexpr BitType()
            : type("N/A") {
    }

    constexpr explicit BitType(const char *data)
            : type{data, std::char_traits<char>::length(data)} {
    }

#ifdef USE_FMT

    explicit BitType(const std::string_view data)
            : type{data} {
    }

#endif

    std::string_view type;
};

struct BitName {
    constexpr BitName()
            : name("Reserved") {
    }

    constexpr explicit BitName(const char *data)
            : name{data, std::char_traits<char>::length(data)} {
    }

    std::string_view name;
};

namespace details {
    template<typename T>
    concept WriteConcept = std::is_same_v<std::remove_cvref_t<T>, READWRITE> ||
                           std::is_same_v<std::remove_cvref_t<T>, WRITEONLY>;

    template<typename T>
    concept ReadConcept = std::is_same_v<std::remove_cvref_t<T>, READWRITE> ||
                          std::is_same_v<std::remove_cvref_t<T>, READONLY>;

    template<typename T, typename U>
    concept NotSameType = !std::is_same_v<std::remove_cvref_t<T>, U> && std::is_class_v<std::remove_cvref_t<T>> &&
                          std::is_class_v<U>;

    template<typename Type>
    [[nodiscard]] constexpr auto getMask(const std::size_t bitOffset, const std::size_t bitWidth) {
        Type mask = 0U;
        for (std::size_t i = 0; i < bitWidth; i++) {
            mask |= static_cast<Type>(1U << (bitOffset + i));
        }
        return mask;
    }

    template<unsigned N>
    struct FixedString {
        std::array<char, N + 1> buf{};

        consteval FixedString(char const *input) {
            for (unsigned i = 0; i != N; ++i) {
                buf[i] = input[i];
            }
        }

        [[nodiscard]] constexpr operator char const *() const {
            return buf.data();
        }
    };

    template<unsigned N>
    FixedString(const char (&)[N]) -> FixedString<N - 1>;

#ifdef USE_FMT
    using namespace std::string_view_literals;
    static std::map<std::type_index, BitType> TypeMap = {{typeid(READONLY),  BitType{"R"sv}},
                                                         {typeid(WRITEONLY), BitType{"W"sv}},
                                                         {typeid(READWRITE), BitType{"R/W"sv}}};
#endif

}// namespace details

// for embedded access
template<typename T, size_t BitOffset, size_t BitWidth, details::FixedString Name, typename FieldType = READWRITE>
struct BitField {
    static constexpr auto bitOffset = BitOffset;
    static constexpr auto bitWidth = BitWidth;
    static constexpr auto mask = details::getMask<std::uint32_t>(BitOffset, BitWidth);
    static constexpr char const *name = Name;
    constexpr static FieldType Type{};

    template<typename U>
    requires details::NotSameType<T, U>
    consteval auto operator|(U lhs) const {
        return mask | lhs.mask;
    }

    template<typename U>
    requires details::NotSameType<T, U>
    consteval auto operator&(U lhs) const {
        return mask & lhs.mask;
    }
};

template<typename Enum, size_t BitOffset, size_t BitWidth, details::FixedString Name, typename FieldType = READWRITE>
struct EnumeratedField {
    static constexpr auto bitOffset = BitOffset;
    static constexpr auto bitWidth = BitWidth;
    static constexpr char const *name = Name;
    constexpr static FieldType Type{};
    using EnumType = Enum;
};

struct BitInfo {
    explicit BitInfo(const size_t width = 0, const BitType bitType = {}, const BitName bitName = {})
            : bitWidth(width), type(bitType.type), name(bitName.name) {
    }

    size_t bitWidth;
    std::string_view type;
    std::string_view name;
};

struct OrAssign {
};
struct AndAssign {
};
struct ExclusieOrAssign {
};

// dummy for non embedded access
template<typename RegisterWidth, std::uintptr_t BaseAddress, RegisterWidth ResetValue, typename RegisterType, details::FixedString Name, typename... Fields>
class Register {
public:

    Register &operator=(RegisterWidth bitMask) {
        write<RegisterType>(bitMask);
        return *this;
    }

    template<typename T = RegisterType>
    requires details::ReadConcept<T>
    RegisterWidth operator()(const RegisterWidth mask) const {
        return rawPtr & mask;
    }

    [[nodiscard]] RegisterWidth read([[maybe_unused]] auto value) const requires details::ReadConcept<RegisterType> {
        using BitFieldType = decltype(value);
        static_assert((std::is_same_v<std::remove_cvref_t<BitFieldType>, std::remove_cvref_t<Fields>> || ...),
                      "Bitfield not defined for register");
        return (static_cast<RegisterWidth>(*rawPtr) & BitFieldType::mask) >> BitFieldType::bitOffset;
    }

    [[nodiscard]] RegisterWidth operator()() const requires details::ReadConcept<RegisterType> {
        return static_cast<RegisterWidth>(*rawPtr) & std::numeric_limits<RegisterWidth>::max();
    }

    void operator|=(RegisterWidth bitMask) requires details::WriteConcept<RegisterType> {
        rawPtr |= bitMask;
    }

    template<typename Field>
    requires details::WriteConcept<decltype(Field::Type)>
    void operator|=([[maybe_unused]] Field field) {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...),
                      "Bitfield not defined for register");
        static_assert(field.bitWidth == 1U, "bitWidth is greater 1, please call write operation!");
        rawPtr |= static_cast<RegisterWidth>(Field::mask);
    }

    template<typename Field>
    requires details::WriteConcept<decltype(Field::Type)>
    void operator&=(RegisterWidth bitMask) {
        rawPtr &= bitMask;
    }

    template<typename Field>
    requires details::WriteConcept<decltype(Field::Type)>
    void operator&=([[maybe_unused]] Field field) {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...),
                      "Bitfield not defined for register");
        static_assert(field.bitWidth == 1U, "bitWidth is greater 1, please call write operation!");
        rawPtr &= static_cast<RegisterWidth>(Field::mask);
    }

    template<typename Field>
    requires details::WriteConcept<decltype(Field::Type)>
    void operator^=(RegisterWidth bitMask) {
        rawPtr ^= bitMask;
    }

    template<typename Field>
    requires details::WriteConcept<decltype(Field::Type)>
    void operator^=([[maybe_unused]] Field field) {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...),
                      "Bitfield not defined for register");
        static_assert(field.bitWidth == 1U, "bitWidth is greater 1, please call write operation!");
        *rawPtr ^= static_cast<RegisterWidth>(Field::mask);
    }

    template<typename Field, typename Operator = OrAssign>
    requires details::WriteConcept<decltype(Field::Type)>
    void write(Field field, RegisterWidth value, [[maybe_unused]] Operator operation) {
        static_assert((std::is_same_v<std::remove_cvref_t<Field>, std::remove_cvref_t<Fields>> || ...),
                      "Bitfield not defined for register");
        static_assert(field.bitWidth > 1U, "bitWidth is equal to 1, use | or & operator!");
        if constexpr (std::is_same_v<Operator, OrAssign>) {
            *rawPtr |= static_cast<RegisterWidth>((value << field.bitOffset) & field.mask);
        } else if constexpr (std::is_same_v<Operator, AndAssign>) {
            *rawPtr &= static_cast<RegisterWidth>((value << field.bitOffset) & field.mask);
        } else if constexpr (std::is_same_v<Operator, ExclusieOrAssign>) {
            *rawPtr ^= static_cast<RegisterWidth>((value << field.bitOffset) & field.mask);
        }
    }

    void reset() {
#ifdef USE_FMT
        raw = ResetValue;
#endif
    }

    void dump() {
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
                        ((bitInfos[Fields::bitOffset] = BitInfo{Fields::bitWidth,
                                                                details::TypeMap[typeid(Fields::Type)],
                                                                BitName{Fields::name}}), ...);
                    },
                    bitInfos);
            size_t offset = 0;
            for (auto iter = bitInfos.begin(); iter != bitInfos.end(); ++iter, offset++) {
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
    RegisterWidth raw = {ResetValue};
    RegisterWidth* rawPtr = reinterpret_cast<RegisterWidth*>(&raw);

    static constexpr char const *name = Name;
#else
    std::uintptr_t rawPtr{BaseAddress};
#endif
};
