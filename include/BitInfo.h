#pragma once
#include <BitName.h>
#include <BitType.h>

struct BitInfo
{
    explicit BitInfo(const size_t width = 0, const BitType bitType = {}, const BitName bitName = {}) : bitWidth(width), type(bitType.type), name(bitName.name)
    {}

    size_t bitWidth;
    std::string_view type;
    std::string_view name;
};
