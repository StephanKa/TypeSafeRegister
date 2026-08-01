#pragma once

#include <cstddef>
#include <cstdint>
#include <string_view>

namespace details {

/** @brief Access permission declared by an SVD register or field. */
enum class Access
{
    ReadOnly,
    WriteOnly,
    ReadWrite,
};

/** @brief Write side effect declared by an SVD modifiedWriteValues element. */
enum class ModifiedWriteValue
{
    None,
    Clear,
    Set,
    Modify,
    OneToClear,
    OneToSet,
    OneToToggle,
    ZeroToClear,
    ZeroToSet,
    ZeroToToggle,
};

/** @brief Read side effect declared by an SVD readAction element. */
enum class ReadAction
{
    None,
    Clear,
    Set,
    Modify,
};

/** @brief Compile-time metadata for one generated register. */
struct RegisterInfo
{
    std::string_view name;
    std::string_view description;
    std::uintptr_t address;
    std::uint64_t resetValue;
    std::uint8_t width;
    Access access;
    ModifiedWriteValue modifiedWriteValue;
    ReadAction readAction;
};

/** @brief Address range declared by an SVD addressBlock element. */
struct AddressBlockInfo
{
    std::uintptr_t address;
    std::size_t size;
    std::string_view usage;
};

/** @brief Interrupt metadata declared by an SVD peripheral. */
struct InterruptInfo
{
    std::string_view name;
    std::string_view description;
    std::int32_t value;
};

/** @brief Compile-time metadata for one generated peripheral. */
struct PeripheralInfo
{
    std::string_view name;
    std::string_view description;
    std::string_view groupName;
    std::uintptr_t baseAddress;
    std::size_t registerCount;
};

}// namespace details