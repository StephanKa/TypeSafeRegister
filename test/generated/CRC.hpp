#include <Register.hpp>

namespace CRC
{
    struct crc_t{};

    constexpr std::uint32_t CRC_BASE_ADDRESS = 0x40023000u;

    constexpr auto DR_ = BitField<crc_t, 0, 32, "DR">{}; // bit offset: 0, bit width: 32, Data register bits
    static Register<std::uint32_t, CRC_BASE_ADDRESS + 0x00000000u, 4294967295, READWRITE, "DR", decltype(DR_)> DR; // Data register

    constexpr auto IDR_ = BitField<crc_t, 0, 8, "IDR">{}; // bit offset: 0, bit width: 8, General-purpose 8-bit data register bits
    static Register<std::uint32_t, CRC_BASE_ADDRESS + 0x00000004u, 0, READWRITE, "IDR", decltype(IDR_)> IDR; // Independent data register

    constexpr auto RESET = BitField<crc_t, 0, 1, "RESET">{}; // bit offset: 0, bit width: 1, reset bit
    static Register<std::uint32_t, CRC_BASE_ADDRESS + 0x00000008u, 0, WRITEONLY, "CR", decltype(RESET)> CR; // Control register

} // namespace CRC