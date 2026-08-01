#pragma once
#include <cstdint>
#include <details.h>
#include <SvdTypes.h>

template<typename T, size_t BitOffset, size_t BitWidth, details::FixedString Name, typename FieldType = READWRITE, typename RegisterWidth = std::uint32_t,
         details::ModifiedWriteValue ModifiedWrite = details::ModifiedWriteValue::None, details::ReadAction Read = details::ReadAction::None>
struct BitField {
    static_assert(std::is_unsigned_v<RegisterWidth>, "Register width must be an unsigned integral type");
    static_assert(BitOffset <= std::numeric_limits<RegisterWidth>::digits
                    && BitWidth <= std::numeric_limits<RegisterWidth>::digits - BitOffset,
                  "Bit field exceeds register width");

    static constexpr auto bitOffset = BitOffset;
    static constexpr auto bitWidth = BitWidth;
    static constexpr auto mask = details::getMask<RegisterWidth>(BitOffset, BitWidth);
    static constexpr auto modifiedWriteValue = ModifiedWrite;
    static constexpr auto readAction = Read;
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
