#pragma once
#include <cstdint>
#include <fmt/format.h>
#include <limits>
#include <map>
#include <string_view>
#include <tuple>
#include <type_traits>
#include <array>
#include <typeindex>

class READONLY
{};
class WRITEONLY
{};
class READWRITE : public READONLY, public WRITEONLY
{};

template<typename Type> constexpr auto getMask(std::size_t bitOffset, std::size_t bitWidth)
{
    Type mask = 0u;
    for (std::size_t i = 0; i < bitWidth; i++)
    {
        mask |= 1 << (bitOffset + i);
    }
    return mask;
}

template<typename T>
concept WriteConcept = std::is_same_v<T, READWRITE> || std::is_same_v<T, WRITEONLY>;

template<typename T>
concept ReadConcept = std::is_same_v<T, READWRITE> || std::is_same_v<T, READONLY>;

template<typename T, typename U>
concept NotSameType = !std::is_same_v<T, U> && std::is_class_v<T> && std::is_class_v<U>;

template<unsigned N> struct FixedString
{
    char buf[N+1]{};
    constexpr FixedString(char const* s)
    {
        for (unsigned i = 0; i != N; ++i)
            buf[i] = s[i];
    }
    constexpr operator char const*() const { return buf; }
};
template<unsigned N> FixedString(const char (&)[N]) -> FixedString<N - 1>;

// for embedded access
template<typename T, size_t BitOffset, size_t BitWidth, FixedString Name, typename FieldType = READWRITE> struct BitField
{
    static constexpr std::size_t bitOffset = BitOffset;
    static constexpr std::size_t bitWidth = BitWidth;
    static constexpr std::uint32_t mask = getMask<std::uint32_t>(BitOffset, BitWidth);
    static constexpr char const* name = Name;
    constexpr static FieldType Type{};

    template<typename U>
    requires NotSameType<T, U>
    constexpr std::uint32_t operator|(U lhs) const { return mask | lhs.mask; }

    template<typename U>
    requires NotSameType<T, U>
    constexpr std::uint32_t operator&(U lhs) const { return mask & lhs.mask; }
};

struct BitInfo
{
    BitInfo(size_t bitWidth = 0, std::string_view type = "R/W", std::string_view name = "Reserved") : bitWidth(bitWidth), type(type), name(name) {}
    ~BitInfo() = default;
    size_t bitWidth;
    std::string_view type;
    std::string_view name;
};

std::map<std::type_index, std::string_view> typeMap = {{typeid(READONLY), "R"}, {typeid(WRITEONLY), "W"}, {typeid(READWRITE), "R/W"}};

// dummy for non embedded access
template<typename RegisterWidth, std::uint32_t, RegisterWidth ResetValue, typename RegisterType, FixedString Name, typename... Fields> class Register
{
public:
    Register& operator=(RegisterWidth bitMask) { write<RegisterType>(bitMask); }

    RegisterWidth operator()(const RegisterWidth mask) const { return read<RegisterType>(mask); }

    template<typename Value>
    requires ReadConcept<RegisterType> RegisterWidth read()
    const { return read<RegisterType>(Value::mask) >> Value::bitOffset; }

    RegisterWidth operator()() const { return read<RegisterType>(std::numeric_limits<int>::max()); }

    void operator|=(RegisterWidth bitMask) { orAssign<RegisterType>(bitMask); }

    template<typename Field> void operator|=(Field field)
    {
        static_assert((std::is_same_v<const Field, Fields> || ...), "Bitfield not defined for register");
        static_assert(!std::is_same_v<decltype(field.Type), READONLY>, "bitfield is readonly");
        static_assert(field.bitWidth == 1u, "bitWidth is greater 1, please call write operation!");
        orAssign<RegisterType>(static_cast<RegisterWidth>(Field::mask));
    }

    void operator&=(RegisterWidth bitMask) { andAssign<RegisterType>(bitMask); }

    template<typename Field> void operator&=(Field field)
    {
        static_assert((std::is_same_v<const Field, Fields> || ...), "Bitfield not defined for register");
        static_assert(!std::is_same_v<decltype(field.Type), READONLY>, "bitfield is readonly");
        static_assert(field.bitWidth == 1u, "bitWidth is greater 1, please call write operation!");
        orAssign<RegisterType>(static_cast<RegisterWidth>(Field::mask));
    }

    template<typename Field> void write(Field field, RegisterWidth value)
    {
        static_assert((std::is_same_v<const Field, Fields> || ...), "Bitfield not defined for register");
        static_assert(!std::is_same_v<decltype(field.Type), READONLY>, "bitfield is readonly");
        static_assert(field.bitWidth > 1u, "bitWidth is equal to 1, use | or & operator!");
        orAssign<RegisterType>(static_cast<RegisterWidth>((value << field.bitOffset) & field.mask));
    }

    void reset() { raw = ResetValue; }

    void dump()
    {
        if constexpr (sizeof...(Fields) > 0)
        {
            fmt::print("Register {:^12}\n", name);
            std::array<BitInfo, std::numeric_limits<RegisterWidth>::digits> r;
            std::apply([&](auto&...) { ((r[Fields::bitOffset] = BitInfo{Fields::bitWidth, typeMap[typeid(Fields::Type)], Fields::name}), ...); }, r);
            size_t offset = 0;
            for (auto iter = r.begin(); iter != r.end(); iter++, offset++)
            {
                fmt::print("| {:-^20}|\n", "");
                fmt::print("|{0:^10}{1:^10} | <-- Bit {2}\n", iter->name, iter->type, offset);
                for (size_t i = 1; i < iter->bitWidth; i++)
                {
                    offset++;
                    iter++;
                    fmt::print("|{0:^20} |\n", "");
                }
            }
            fmt::print("| {:-^20}|\n", "");
        }
    }

private:
    template<WriteConcept T> void write(RegisterWidth bitMask) { *rawPtr = bitMask; }

    template<ReadConcept T> RegisterWidth read(RegisterWidth mask) const { return *rawPtr & mask; }
    template<ReadConcept T> RegisterWidth read() const { return *rawPtr; }

    template<WriteConcept T> void orAssign(RegisterWidth bitMask) { *rawPtr |= bitMask; }

    template<WriteConcept T> void andAssign(RegisterWidth bitMask) { *rawPtr &= bitMask; }

    RegisterWidth raw = {ResetValue};
    RegisterWidth* rawPtr = reinterpret_cast<RegisterWidth*>(&raw);

    static constexpr char const* name = Name;
};
