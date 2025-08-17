#pragma once
#include <CompileTimeMap.h>
#include <BitType.h>
#include <map>
#include <type_traits>
#include <typeindex>
#include <array>

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
[[nodiscard]] constexpr auto getMask(const std::size_t bitOffset, const std::size_t bitWidth)
{
    Type mask = 0U;
    for (std::size_t i = 0; i < bitWidth; i++) {
        mask |= static_cast<Type>(1U << (bitOffset + i));
    }
    return mask;
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

#ifdef USE_FMT
using namespace std::string_view_literals;

constexpr auto TypeMap = CompileTimeMap<const std::type_info*, BitType>(
    Element{.key=&typeid(READONLY), .value=BitType{ "R"sv }},
    Element{.key=&typeid(READONLY), .value=BitType{ "W"sv }},
    Element{.key=&typeid(READONLY), .value=BitType{ "R/W"sv }});
#endif

}// namespace details
