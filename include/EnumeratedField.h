#pragma once
#include <cstdint>
#include <details.h>
#include <SvdTypes.h>

template<typename Enum, size_t BitOffset, size_t BitWidth, details::FixedString Name, typename FieldType = READWRITE, typename RegisterWidth = std::uint32_t,
         details::ModifiedWriteValue ModifiedWrite = details::ModifiedWriteValue::None, details::ReadAction Read = details::ReadAction::None>
struct EnumeratedField {
    static constexpr auto bitOffset = BitOffset;
    static constexpr auto bitWidth = BitWidth;
    static constexpr auto mask = details::getMask<RegisterWidth>(BitOffset, BitWidth);
    static constexpr auto modifiedWriteValue = ModifiedWrite;
    static constexpr auto readAction = Read;
    static constexpr char const *name = Name;
    constexpr static FieldType Type{};
    using EnumType = Enum;

    [[nodiscard]] static constexpr RegisterWidth encode(const Enum value)
    {
        return static_cast<RegisterWidth>((std::to_underlying(value) << bitOffset) & mask);
    }
};
