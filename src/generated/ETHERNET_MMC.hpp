#include <Register.hpp>




namespace ETHERNET_MMC
{
    struct ethernet_mmc_t{};

    constexpr std::uint32_t ETHERNET_MMC_BASE_ADDRESS = 0x40028100u;

    constexpr auto CR = BitField<ethernet_mmc_t, 0, 1>{}; // bit offset: 0, bit width: 1, Counter reset
    constexpr auto CSR = BitField<ethernet_mmc_t, 1, 1>{}; // bit offset: 1, bit width: 1, Counter stop rollover
    constexpr auto ROR = BitField<ethernet_mmc_t, 2, 1>{}; // bit offset: 2, bit width: 1, Reset on read
    constexpr auto MCF = BitField<ethernet_mmc_t, 3, 1>{}; // bit offset: 3, bit width: 1, MMC counter freeze
    constexpr auto MCP = BitField<ethernet_mmc_t, 4, 1>{}; // bit offset: 4, bit width: 1, MMC counter preset
    constexpr auto MCFHP = BitField<ethernet_mmc_t, 5, 1>{}; // bit offset: 5, bit width: 1, MMC counter Full-Half preset
    static Register<std::uint32_t, ETHERNET_MMC_BASE_ADDRESS + 0x00000000u, 0, READWRITE, decltype(CR), decltype(CSR), decltype(ROR), decltype(MCF), decltype(MCP), decltype(MCFHP)> MMCCR; // Ethernet MMC control register

    constexpr auto RFCES = BitField<ethernet_mmc_t, 5, 1>{}; // bit offset: 5, bit width: 1, Received frames CRC error status
    constexpr auto RFAES = BitField<ethernet_mmc_t, 6, 1>{}; // bit offset: 6, bit width: 1, Received frames alignment error status
    constexpr auto RGUFS = BitField<ethernet_mmc_t, 17, 1>{}; // bit offset: 17, bit width: 1, Received Good Unicast Frames Status
    static Register<std::uint32_t, ETHERNET_MMC_BASE_ADDRESS + 0x00000004u, 0, READWRITE, decltype(RFCES), decltype(RFAES), decltype(RGUFS)> MMCRIR; // Ethernet MMC receive interrupt register

    constexpr auto TGFSCS = BitField<ethernet_mmc_t, 14, 1>{}; // bit offset: 14, bit width: 1, Transmitted good frames single collision status
    constexpr auto TGFMSCS = BitField<ethernet_mmc_t, 15, 1>{}; // bit offset: 15, bit width: 1, Transmitted good frames more single collision status
    constexpr auto TGFS = BitField<ethernet_mmc_t, 21, 1>{}; // bit offset: 21, bit width: 1, Transmitted good frames status
    static Register<std::uint32_t, ETHERNET_MMC_BASE_ADDRESS + 0x00000008u, 0, READWRITE, decltype(TGFSCS), decltype(TGFMSCS), decltype(TGFS)> MMCTIR; // Ethernet MMC transmit interrupt register

    constexpr auto RFCEM = BitField<ethernet_mmc_t, 5, 1>{}; // bit offset: 5, bit width: 1, Received frame CRC error mask
    constexpr auto RFAEM = BitField<ethernet_mmc_t, 6, 1>{}; // bit offset: 6, bit width: 1, Received frames alignment error mask
    constexpr auto RGUFM = BitField<ethernet_mmc_t, 17, 1>{}; // bit offset: 17, bit width: 1, Received good unicast frames mask
    static Register<std::uint32_t, ETHERNET_MMC_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, decltype(RFCEM), decltype(RFAEM), decltype(RGUFM)> MMCRIMR; // Ethernet MMC receive interrupt mask register

    constexpr auto TGFSCM = BitField<ethernet_mmc_t, 14, 1>{}; // bit offset: 14, bit width: 1, Transmitted good frames single collision mask
    constexpr auto TGFMSCM = BitField<ethernet_mmc_t, 15, 1>{}; // bit offset: 15, bit width: 1, Transmitted good frames more single collision mask
    constexpr auto TGFM = BitField<ethernet_mmc_t, 21, 1>{}; // bit offset: 21, bit width: 1, Transmitted good frames mask
    static Register<std::uint32_t, ETHERNET_MMC_BASE_ADDRESS + 0x00000010u, 0, READWRITE, decltype(TGFSCM), decltype(TGFMSCM), decltype(TGFM)> MMCTIMR; // Ethernet MMC transmit interrupt mask register

    constexpr auto TGFSCC = BitField<ethernet_mmc_t, 0, 32>{}; // bit offset: 0, bit width: 32, Transmitted good frames single collision counter
    static Register<std::uint32_t, ETHERNET_MMC_BASE_ADDRESS + 0x0000004cu, 0, READONLY, decltype(TGFSCC)> MMCTGFSCCR; // Ethernet MMC transmitted good frames after a single collision counter

    constexpr auto TGFMSCC = BitField<ethernet_mmc_t, 0, 32>{}; // bit offset: 0, bit width: 32, Transmitted good frames more single collision counter
    static Register<std::uint32_t, ETHERNET_MMC_BASE_ADDRESS + 0x00000050u, 0, READONLY, decltype(TGFMSCC)> MMCTGFMSCCR; // Ethernet MMC transmitted good frames after more than a single collision

    constexpr auto TGFC = BitField<ethernet_mmc_t, 0, 32>{}; // bit offset: 0, bit width: 32, Transmitted good frames counter
    static Register<std::uint32_t, ETHERNET_MMC_BASE_ADDRESS + 0x00000068u, 0, READONLY, decltype(TGFC)> MMCTGFCR; // Ethernet MMC transmitted good frames counter register

    constexpr auto RFCFC = BitField<ethernet_mmc_t, 0, 32>{}; // bit offset: 0, bit width: 32, Received frames CRC error counter
    static Register<std::uint32_t, ETHERNET_MMC_BASE_ADDRESS + 0x00000094u, 0, READONLY, decltype(RFCFC)> MMCRFCECR; // Ethernet MMC received frames with CRC error counter register

    constexpr auto RFAEC = BitField<ethernet_mmc_t, 0, 32>{}; // bit offset: 0, bit width: 32, Received frames alignment error counter
    static Register<std::uint32_t, ETHERNET_MMC_BASE_ADDRESS + 0x00000098u, 0, READONLY, decltype(RFAEC)> MMCRFAECR; // Ethernet MMC received frames with alignment error counter register

    constexpr auto RGUFC = BitField<ethernet_mmc_t, 0, 32>{}; // bit offset: 0, bit width: 32, Received good unicast frames counter
    static Register<std::uint32_t, ETHERNET_MMC_BASE_ADDRESS + 0x000000c4u, 0, READONLY, decltype(RGUFC)> MMCRGUFCR; // MMC received good unicast frames counter register

} // namespace ETHERNET_MMC