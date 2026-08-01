#pragma once

#include <cstddef>
#include <cstdint>
#include <string_view>

namespace details {

enum class Access
{
    ReadOnly,
    WriteOnly,
    ReadWrite,
};

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

enum class ReadAction
{
    None,
    Clear,
    Set,
    Modify,
};

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

struct AddressBlockInfo
{
    std::uintptr_t address;
    std::size_t size;
    std::string_view usage;
};

struct InterruptInfo
{
    std::string_view name;
    std::string_view description;
    std::int32_t value;
};

struct PeripheralInfo
{
    std::string_view name;
    std::string_view description;
    std::string_view groupName;
    std::uintptr_t baseAddress;
    std::size_t registerCount;
};

}// namespace details