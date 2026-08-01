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