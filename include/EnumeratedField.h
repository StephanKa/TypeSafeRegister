#pragma once
#include <SvdTypes.h>
#include <cstdint>
#include <details.h>
#include <utility>

/**
 * @brief Describes an SVD field whose values are represented by an enum.
 *
 * @tparam Enum The generated enum class containing unshifted field values.
 * @tparam BitOffset Least-significant field bit.
 * @tparam BitWidth Number of field bits.
 * @tparam Name Generated field name.
 * @tparam FieldType SVD access permission type.
 * @tparam RegisterWidth Unsigned storage type of the owning register.
 * @tparam ModifiedWrite SVD modified-write policy.
 * @tparam Read SVD read-side-effect policy.
 */
template<typename Enum,
  size_t BitOffset,
  size_t BitWidth,
  details::FixedString Name,
  typename FieldType = READWRITE,
  typename RegisterWidth = std::uint32_t,
  details::ModifiedWriteValue ModifiedWrite = details::ModifiedWriteValue::None,
  details::ReadAction Read = details::ReadAction::None>
struct EnumeratedField
{
    static constexpr auto bitOffset = BitOffset;
    static constexpr auto bitWidth = BitWidth;
    static constexpr auto mask = details::getMask<RegisterWidth>(BitOffset, BitWidth);
    static constexpr auto modifiedWriteValue = ModifiedWrite;
    static constexpr auto readAction = Read;
    static constexpr char const *name = Name;
    constexpr static FieldType Type{};
    using EnumType = Enum;

    /**
     * @brief Encode an unshifted enum value at this field's bit position.
     * @param value Generated enum value to encode.
     * @return Masked register-width value.
     */
    [[nodiscard]] static constexpr RegisterWidth encode(const Enum value)
    {
        return static_cast<RegisterWidth>((std::to_underlying(value) << bitOffset) & mask);
    }
};
