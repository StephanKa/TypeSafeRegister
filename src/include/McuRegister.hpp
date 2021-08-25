#pragma once
#include <cstdint>
#include <tuple>
#include <type_traits>
#include <limits>

class READONLY
{};
class WRITEONLY
{};
class READWRITE : public READONLY, public WRITEONLY
{};

template<typename T>
concept WriteConcept = std::is_same_v<T, READWRITE> || std::is_same_v<T, WRITEONLY>;

template<typename T>
concept ReadConcept = std::is_same_v<T, READWRITE> || std::is_same_v<T, WRITEONLY>;

template<typename T, typename U>
concept NotSameType = !std::is_same_v<T, U>;

template<typename Type> consteval auto getMask(std::size_t bitOffset, std::size_t bitWidth)
{
    Type mask = 0u;
    for (std::size_t i = 0; i < bitWidth; i++)
    {
        mask |= 1 << (bitOffset + i);
    }
    return mask;
}

template<typename T, typename U>
requires NotSameType<T, U>
consteval std::uint32_t operator|(T rhs, U lhs) { return rhs.mask | lhs.mask; }

template<typename T, typename U>
requires NotSameType<T, U>
consteval std::uint32_t operator&(T rhs, T lhs) { return rhs.mask & lhs.mask; }

// for embedded access
template<typename T, std::size_t BitOffset, std::size_t BitWidth, typename FieldType = READWRITE> struct BitField
{
    static constexpr std::size_t bitOffset = BitOffset;
    static constexpr std::size_t bitWidth = BitWidth;
    static constexpr std::uint32_t mask = getMask<std::uint32_t>(BitOffset, BitWidth);
    constexpr static FieldType Type{};
};

// dummy for non embedded access
template<typename RegisterWidth, std::uint32_t RegisterAddress, RegisterWidth ResetValue, typename RegisterType, typename... Fields> class Register
{
public:
    Register& operator=(RegisterWidth bitMask) { write<RegisterType>(bitMask); }

    RegisterWidth operator()(const RegisterWidth mask) const { return read<RegisterType>(mask); }

    template<typename Value>
    requires ReadConcept<RegisterType> std::uint32_t read()
    const { return read<RegisterType>(Value::mask); }

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

private:
    template<WriteConcept T> void write(RegisterWidth bitMask) { *rawPtr = bitMask; }

    template<ReadConcept T> RegisterWidth read(std::uint32_t mask) const { return *rawPtr & mask; }
    template<ReadConcept T> RegisterWidth read() const { return *rawPtr; }

    template<WriteConcept T> void orAssign(RegisterWidth bitMask) { *rawPtr |= bitMask; }

    template<WriteConcept T> void andAssign(RegisterWidth bitMask) { *rawPtr &= bitMask; }

    RegisterWidth* rawPtr{reinterpret_cast<RegisterWidth*>(RegisterAddress)};
};