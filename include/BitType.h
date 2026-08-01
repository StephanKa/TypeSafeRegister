#pragma once

#include <string_view>

struct BitType
{
    constexpr BitType() : type("N/A")
    {}

    constexpr explicit BitType(const char *data) : type{ data, std::char_traits<char>::length(data) }
    {}

    constexpr explicit BitType(const std::string_view data) : type{ data }
    {}

    constexpr bool operator==(const BitType &rhs) const = default;

    std::string_view type;
};
