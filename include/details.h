#pragma once
#include <CompileTimeMap.h>
#include <BitType.h>
#include <map>
#include <type_traits>
#include <typeindex>
#include <array>
#include <limits>
#include <stdexcept>
#include <string_view>

struct READONLY
{
};

struct WRITEONLY
{
};

struct READWRITE
  : READONLY
  , WRITEONLY
{
};

namespace details {
template<typename T>
concept WriteConcept = std::is_same_v<std::remove_cvref_t<T>, READWRITE> || std::is_same_v<std::remove_cvref_t<T>, WRITEONLY>;

template<typename T>
concept ReadConcept = std::is_same_v<std::remove_cvref_t<T>, READWRITE> || std::is_same_v<std::remove_cvref_t<T>, READONLY>;

template<typename T, typename U>
concept NotSameType = !std::is_same_v<std::remove_cvref_t<T>, U> && std::is_class_v<std::remove_cvref_t<T>> && std::is_class_v<U>;

template<typename Type>
[[nodiscard]] constexpr Type getMask(const std::size_t bitOffset, const std::size_t bitWidth)
{
    static_assert(std::is_unsigned_v<Type>, "Register masks require an unsigned integral type");

    constexpr auto digits = std::numeric_limits<Type>::digits;
    if (bitOffset > digits || bitWidth > digits - bitOffset) {
        throw std::out_of_range("Bit field exceeds register width");
    }
    if (bitWidth == 0U) {
        return Type{ 0 };
    }

    const auto unshiftedMask = bitWidth == digits
      ? std::numeric_limits<Type>::max()
      : static_cast<Type>((Type{ 1 } << bitWidth) - Type{ 1 });
    return static_cast<Type>(unshiftedMask << bitOffset);
}

template<unsigned N>
struct FixedString
{
    std::array<char, N + 1> buf{};
    consteval FixedString(char const *input)
    {
        std::copy_n(input, N, buf.data());
    }

    [[nodiscard]] explicit constexpr operator std::string_view() const
    {
        return {buf.data(), N};
    }
};

template<unsigned N>
FixedString(const char (&)[N]) -> FixedString<N - 1>;

#ifdef ENABLE_OUTPUT
using namespace std::string_view_literals;

constexpr auto TypeMap = CompileTimeMap<const std::type_info*, BitType>(
    Element{.key=&typeid(READONLY), .value=BitType{ "R"sv }},
    Element{.key=&typeid(WRITEONLY), .value=BitType{ "W"sv }},
    Element{.key=&typeid(READWRITE), .value=BitType{ "R/W"sv }});
#endif

}// namespace details
