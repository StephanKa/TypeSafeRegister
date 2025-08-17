#pragma once

#include <type_traits>
#ifdef USE_FMT

#include <fmt/format.h>

#endif

struct BitType
{
    constexpr BitType() : type("N/A")
    {}

    constexpr explicit BitType(const char *data) : type{ data, std::char_traits<char>::length(data) }
    {}

#ifdef USE_FMT

    constexpr explicit BitType(const std::string_view data) : type{ data }
    {}

    constexpr bool operator==(const BitType &rhs) const
    {
        return rhs.type == type;
    }

#endif

    std::string_view type;
};
