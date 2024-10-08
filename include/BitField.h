#pragma once
#include <cstdint>
#include <details.h>

template<typename T, size_t BitOffset, size_t BitWidth, details::FixedString Name, typename FieldType = READWRITE>
struct BitField {
    static constexpr auto bitOffset = BitOffset;
    static constexpr auto bitWidth = BitWidth;
    static constexpr auto mask = details::getMask<std::uint32_t>(BitOffset, BitWidth);
    static constexpr char const *name = Name;
    constexpr static FieldType Type{};

    template<typename U>
    requires details::NotSameType<T, U>
    consteval auto operator|(U lhs) const {
        return mask | lhs.mask;
    }

    template<typename U>
    requires details::NotSameType<T, U>
    consteval auto operator&(U lhs) const {
        return mask & lhs.mask;
    }
};
