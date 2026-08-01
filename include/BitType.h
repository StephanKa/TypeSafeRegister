#pragma once

#include <string_view>

/** @brief Owns the display access type associated with a register field. */
struct BitType
{
    /** @brief Construct the default type, `N/A`. */
    constexpr BitType() : type("N/A")
    {}

    /**
     * @brief Construct a type from a null-terminated character string.
     * @param data Access type text, such as `R`, `W`, or `R/W`.
     */
    constexpr explicit BitType(const char *data) : type{ data, std::char_traits<char>::length(data) }
    {}

    /**
     * @brief Construct a type from a string view.
     * @param data Access type text.
     */
    constexpr explicit BitType(const std::string_view data) : type{ data }
    {}

    /**
     * @brief Compare two access type labels.
     * @param rhs Type label to compare.
     * @return `true` when both labels are equal.
     */
    constexpr bool operator==(const BitType &rhs) const = default;

    /** @brief Display access type. */
    std::string_view type;
};
