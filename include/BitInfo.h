#pragma once
#include <BitName.h>
#include <BitType.h>

/** @brief Display metadata for one bit or contiguous register field. */
struct BitInfo
{
    /**
     * @brief Construct field metadata for register-map output.
     * @param width Number of bits occupied by the field.
     * @param bitType Display access type.
     * @param bitName Display field name.
     */
    explicit BitInfo(const size_t width = 0, const BitType bitType = {}, const BitName bitName = {}) : bitWidth(width), type(bitType.type), name(bitName.name)
    {}

    /** @brief Number of bits occupied by the field. */
    size_t bitWidth;
    /** @brief Display access type. */
    std::string_view type;
    /** @brief Display field name. */
    std::string_view name;
};
