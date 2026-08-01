#pragma once
#include <string_view>

/** @brief Owns the display name associated with a register field. */
struct BitName
{
    /** @brief Construct the default name, `Reserved`. */
    constexpr BitName() : name("Reserved")
    {}

    /**
     * @brief Construct a field name from a null-terminated character string.
     * @param data Field name supplied by the SVD.
     */
    constexpr explicit BitName(const char *data) : name{ data, std::char_traits<char>::length(data) }
    {}

    /** @brief Display name of the field. */
    std::string_view name;
};
