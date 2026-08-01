#pragma once
#include <SvdTypes.h>
#include <cstdint>
#include <details.h>

/**
 * @brief Describes a non-enumerated SVD register field at compile time.
 *
 * The descriptor retains the field mask, access permission, and SVD read/write
 * side-effect policies without storing runtime state.
 * @tparam T Owning generated peripheral tag type.
 * @tparam BitOffset Least-significant field bit.
 * @tparam BitWidth Number of field bits.
 * @tparam Name Generated field name.
 * @tparam FieldType SVD access permission type.
 * @tparam RegisterWidth Unsigned storage type of the owning register.
 * @tparam ModifiedWrite SVD modified-write policy.
 * @tparam Read SVD read-side-effect policy.
 */
template<typename T,
  size_t BitOffset,
  size_t BitWidth,
  details::FixedString Name,
  typename FieldType = READWRITE,
  typename RegisterWidth = std::uint32_t,
  details::ModifiedWriteValue ModifiedWrite = details::ModifiedWriteValue::None,
  details::ReadAction Read = details::ReadAction::None>
struct BitField
{
    static_assert(std::is_unsigned_v<RegisterWidth>, "Register width must be an unsigned integral type");
    static_assert(BitOffset <= std::numeric_limits<RegisterWidth>::digits && BitWidth <= std::numeric_limits<RegisterWidth>::digits - BitOffset,
      "Bit field exceeds register width");

    /** @brief Least-significant bit of the field. */
    static constexpr auto bitOffset = BitOffset;
    /** @brief Width of the field in bits. */
    static constexpr auto bitWidth = BitWidth;
    /** @brief Register-width mask covering the field. */
    static constexpr auto mask = details::getMask<RegisterWidth>(BitOffset, BitWidth);
    static constexpr auto modifiedWriteValue = ModifiedWrite;
    static constexpr auto readAction = Read;
    static constexpr char const *name = Name;
    constexpr static FieldType Type{};

    template<typename U>
        requires details::NotSameType<T, U>
    /**
     * @brief Combine two compatible single-bit field masks.
     * @tparam U Type of the other field descriptor.
     * @param lhs Other field descriptor.
     * @return Combined register mask.
     */
    consteval auto operator|(U lhs) const
    {
        return mask | lhs.mask;
    }

    template<typename U>
        requires details::NotSameType<T, U>
    /**
     * @brief Intersect two compatible field masks.
     * @tparam U Type of the other field descriptor.
     * @param lhs Other field descriptor.
     * @return Intersected register mask.
     */
    consteval auto operator&(U lhs) const
    {
        return mask & lhs.mask;
    }
};
