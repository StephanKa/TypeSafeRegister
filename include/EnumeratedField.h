#pragma once
#include <cstdint>
#include <details.h>

template<typename Enum, size_t BitOffset, size_t BitWidth, details::FixedString Name, typename FieldType = READWRITE>
struct EnumeratedField {
    static constexpr auto bitOffset = BitOffset;
    static constexpr auto bitWidth = BitWidth;
    static constexpr char const *name = Name;
    constexpr static FieldType Type{};
    using EnumType = Enum;
};
