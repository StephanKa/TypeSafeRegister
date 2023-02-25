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

struct READONLY
{
};

struct WRITEONLY
{
};

struct READWRITE
  : public READONLY
  , public WRITEONLY
{
};

class BitType
{
  public:
    consteval BitType() : type("N/A") {}
    consteval explicit BitType(const char *data) : type{ data, std::char_traits<char>::length(data) } {}
#ifdef USE_FMT
    explicit BitType(std::string_view data) : type{ data } {}
#endif

    std::string_view type;
};

class BitName
{
  public:
    consteval BitName() : name("Reserved") {}
    consteval explicit BitName(const char *data) : name{ data, std::char_traits<char>::length(data) } {}

    std::string_view name;
};

namespace details {
template<typename T>
concept WriteConcept = std::is_same_v<T, READWRITE> || std::is_same_v<T, WRITEONLY>;

template<typename T>
concept ReadConcept = std::is_same_v<T, READWRITE> || std::is_same_v<T, READONLY>;

template<typename T, typename U>
concept NotSameType = !std::is_same_v<T, U> && std::is_class_v<T> && std::is_class_v<U>;

template<typename Type> consteval auto getMask(std::size_t bitOffset, std::size_t bitWidth)
{
    Type mask = 0u;
    for (std::size_t i = 0; i < bitWidth; i++) { mask |= static_cast<Type>(1 << (bitOffset + i)); }
    return mask;
}

template<unsigned N> struct FixedString
{
    std::array<char, N + 1> buf{};
    consteval FixedString(char const *input)
    {
        for (unsigned i = 0; i != N; ++i) { buf[i] = input[i]; }
    }
    constexpr operator char const *() const { return buf.data(); }
};
template<unsigned N> FixedString(const char (&)[N]) -> FixedString<N - 1>;

#ifdef USE_FMT
using namespace std::string_view_literals;
std::map<std::type_index, BitType> typeMap = { { typeid(READONLY), BitType{ "R"sv } }, { typeid(WRITEONLY), BitType{ "W"sv } }, { typeid(READWRITE), BitType{ "R/W"sv } } };
#endif

}// namespace detail

// for embedded access
template<typename T, size_t BitOffset, size_t BitWidth, details::FixedString Name, typename FieldType = READWRITE> struct BitField
{
    static constexpr std::size_t bitOffset = BitOffset;
    static constexpr std::size_t bitWidth = BitWidth;
    static constexpr auto mask = details::getMask<std::uint32_t>(BitOffset, BitWidth);
    static constexpr char const *name = Name;
    constexpr static FieldType Type{};

    template<typename U>
        requires details::NotSameType<T, U>
    consteval auto operator|(U lhs) const
    {
        return mask | lhs.mask;
    }

    template<typename U>
        requires details::NotSameType<T, U>
    consteval auto operator&(U lhs) const
    {
        return mask & lhs.mask;
    }
};

template<typename Enum, size_t BitOffset, size_t BitWidth, details::FixedString Name, typename FieldType = READWRITE> struct EnumeratedField
{
    static constexpr auto bitOffset = BitOffset;
    static constexpr auto  bitWidth = BitWidth;
    static constexpr char const *name = Name;
    constexpr static FieldType Type{};
    using EnumType = Enum;
};

struct BitInfo
{
    explicit BitInfo(size_t width = 0, BitType bitType = {}, BitName bitName = {}) : bitWidth(width), type(bitType.type), name(bitName.name) {}
    size_t bitWidth;
    std::string_view type;
    std::string_view name;
};

// dummy for non embedded access
template<typename RegisterWidth, std::uint32_t, RegisterWidth ResetValue, typename RegisterType, details::FixedString Name, typename... Fields> class Register
{
  public:
    Register &operator=(RegisterWidth bitMask) { write<RegisterType>(bitMask); }

    RegisterWidth operator()(const RegisterWidth mask) const { return read<RegisterType>(mask); }

    template<typename Value>
        requires details::ReadConcept<RegisterType>
    RegisterWidth read() const
    {
        return read<RegisterType>(Value::mask) >> Value::bitOffset;
    }

    RegisterWidth operator()() const { return read<RegisterType>(std::numeric_limits<int>::max()); }

    void operator|=(RegisterWidth bitMask) { orAssign<RegisterType>(bitMask); }

    template<typename Field> void operator|=([[maybe_unused]] Field field)
    {
        static_assert((std::is_same_v<const Field, Fields> || ...), "Bitfield not defined for register");
        static_assert(!std::is_same_v<decltype(field.Type), READONLY>, "bitfield is readonly");
        static_assert(field.bitWidth == 1U, "bitWidth is greater 1, please call write operation!");
        orAssign<RegisterType>(static_cast<RegisterWidth>(Field::mask));
    }

    void operator&=(RegisterWidth bitMask) { andAssign<RegisterType>(bitMask); }

    template<typename Field> void operator&=([[maybe_unused]] Field field)
    {
        static_assert((std::is_same_v<const Field, Fields> || ...), "Bitfield not defined for register");
        static_assert(!std::is_same_v<decltype(field.Type), READONLY>, "bitfield is readonly");
        static_assert(field.bitWidth == 1U, "bitWidth is greater 1, please call write operation!");
        orAssign<RegisterType>(static_cast<RegisterWidth>(Field::mask));
    }

    template<typename Field> void write(Field field, RegisterWidth value)
    {
        static_assert((std::is_same_v<const Field, Fields> || ...), "Bitfield not defined for register");
        static_assert(!std::is_same_v<decltype(field.Type), READONLY>, "bitfield is readonly");
        static_assert(field.bitWidth > 1U, "bitWidth is equal to 1, use | or & operator!");
        orAssign<RegisterType>(static_cast<RegisterWidth>((value << field.bitOffset) & field.mask));
    }

    void reset() { raw = ResetValue; }

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
            std::apply([&](auto &...) { ((bitInfos[Fields::bitOffset] = BitInfo{ Fields::bitWidth, details::typeMap[typeid(Fields::Type)], BitName{ Fields::name } }), ...); }, bitInfos);
            size_t offset = 0;
            for (auto iter = bitInfos.begin(); iter != bitInfos.end(); iter++, offset++) {
                fmt::print(horizontalLine, "");
                if (iter->bitWidth > 1) {
                    fmt::print(bitContentMultipleWidth, iter->name, iter->type, offset, offset + iter->bitWidth - 1);
                } else {
                    fmt::print(bitContentSingleWidth, iter->name, iter->type, offset);
                }
                for (size_t i = 1; i < iter->bitWidth; i++) {
                    offset++;
                    iter++;
                    fmt::print("|{0:^40} |\n", "");
                }
            }
            fmt::print(horizontalLine, "");
        }
#endif
    }

  private:
    template<details::WriteConcept T> void write(RegisterWidth bitMask) { *rawPtr = bitMask; }

    template<details::ReadConcept T> RegisterWidth read(RegisterWidth mask) const { return *rawPtr & mask; }
    template<details::ReadConcept T> RegisterWidth read() const { return *rawPtr; }

    template<details::WriteConcept T> void orAssign(RegisterWidth bitMask) { *rawPtr |= bitMask; }

    template<details::WriteConcept T> void andAssign(RegisterWidth bitMask) { *rawPtr &= bitMask; }

    RegisterWidth raw = { ResetValue };
    RegisterWidth *rawPtr = reinterpret_cast<RegisterWidth *>(&raw);

#ifdef USE_FMT
    static constexpr char const *name = Name;
#endif
};
