#pragma once

#ifdef ENABLE_OUTPUT

#if defined(TYPESAFE_REGISTER_USE_STD_FORMAT)
#include <format>
#include <iostream>
#else
#include <fmt/format.h>
#endif

#include <utility>

namespace details {

/**
 * @brief Print a formatted message when `ENABLE_OUTPUT` is enabled.
 *
 * C++20 and newer builds use `std::format`; legacy format builds use `{fmt}`.
 * @tparam Args Argument types accepted by the format string.
 * @param format Compile-time checked format string.
 * @param args Values substituted into @p format.
 */
template<typename... Args>
#if defined(TYPESAFE_REGISTER_USE_STD_FORMAT)
void print(const std::format_string<Args...> format, Args &&...args)
{
    std::cout << std::format(format, std::forward<Args>(args)...);
}
#else
void print(const fmt::format_string<Args...> format, Args &&...args)
{
    fmt::print(format, std::forward<Args>(args)...);
}
#endif

}// namespace details

#endif