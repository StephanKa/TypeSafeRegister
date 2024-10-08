#pragma once
#include <string_view>

struct BitName
{
    constexpr BitName() : name("Reserved")
    {}

    constexpr explicit BitName(const char *data) : name{ data, std::char_traits<char>::length(data) }
    {}

    std::string_view name;
};
