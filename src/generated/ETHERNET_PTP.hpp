#include <Register.hpp>




namespace ETHERNET_PTP
{
    struct ethernet_ptp_t{};

    constexpr std::uint32_t ETHERNET_PTP_BASE_ADDRESS = 0x40028700u;

    constexpr auto TSE = BitField<ethernet_ptp_t, 0, 1>{}; // bit offset: 0, bit width: 1, Time stamp enable
    constexpr auto TSFCU = BitField<ethernet_ptp_t, 1, 1>{}; // bit offset: 1, bit width: 1, Time stamp fine or coarse update
    constexpr auto TSSTI = BitField<ethernet_ptp_t, 2, 1>{}; // bit offset: 2, bit width: 1, Time stamp system time initialize
    constexpr auto TSSTU = BitField<ethernet_ptp_t, 3, 1>{}; // bit offset: 3, bit width: 1, Time stamp system time update
    constexpr auto TSITE = BitField<ethernet_ptp_t, 4, 1>{}; // bit offset: 4, bit width: 1, Time stamp interrupt trigger enable
    constexpr auto TTSARU = BitField<ethernet_ptp_t, 5, 1>{}; // bit offset: 5, bit width: 1, Time stamp addend register update
    constexpr auto TSSARFE = BitField<ethernet_ptp_t, 8, 1>{}; // bit offset: 8, bit width: 1, Time stamp snapshot for all received frames enable
    constexpr auto TSSSR = BitField<ethernet_ptp_t, 9, 1>{}; // bit offset: 9, bit width: 1, Time stamp subsecond rollover: digital or binary rollover control
    constexpr auto TSPTPPSV2E = BitField<ethernet_ptp_t, 10, 1>{}; // bit offset: 10, bit width: 1, Time stamp PTP packet snooping for version2 format enable
    constexpr auto TSSPTPOEFE = BitField<ethernet_ptp_t, 11, 1>{}; // bit offset: 11, bit width: 1, Time stamp snapshot for PTP over ethernet frames enable
    constexpr auto TSSIPV6FE = BitField<ethernet_ptp_t, 12, 1>{}; // bit offset: 12, bit width: 1, Time stamp snapshot for IPv6 frames enable
    constexpr auto TSSIPV4FE = BitField<ethernet_ptp_t, 13, 1>{}; // bit offset: 13, bit width: 1, Time stamp snapshot for IPv4 frames enable
    constexpr auto TSSEME = BitField<ethernet_ptp_t, 14, 1>{}; // bit offset: 14, bit width: 1, Time stamp snapshot for event message enable
    constexpr auto TSSMRME = BitField<ethernet_ptp_t, 15, 1>{}; // bit offset: 15, bit width: 1, Time stamp snapshot for message relevant to master enable
    constexpr auto TSCNT = BitField<ethernet_ptp_t, 16, 2>{}; // bit offset: 16, bit width: 2, Time stamp clock node type
    constexpr auto TSPFFMAE = BitField<ethernet_ptp_t, 18, 1>{}; // bit offset: 18, bit width: 1, Time stamp PTP frame filtering MAC address enable
    static Register<std::uint32_t, ETHERNET_PTP_BASE_ADDRESS + 0x00000000u, 8192, READWRITE, decltype(TSE), decltype(TSFCU), decltype(TSSTI), decltype(TSSTU), decltype(TSITE), decltype(TTSARU), decltype(TSSARFE), decltype(TSSSR), decltype(TSPTPPSV2E), decltype(TSSPTPOEFE), decltype(TSSIPV6FE), decltype(TSSIPV4FE), decltype(TSSEME), decltype(TSSMRME), decltype(TSCNT), decltype(TSPFFMAE)> PTPTSCR; // Ethernet PTP time stamp control register

    constexpr auto STSSI = BitField<ethernet_ptp_t, 0, 8>{}; // bit offset: 0, bit width: 8, System time subsecond increment
    static Register<std::uint32_t, ETHERNET_PTP_BASE_ADDRESS + 0x00000004u, 0, READWRITE, decltype(STSSI)> PTPSSIR; // Ethernet PTP subsecond increment register

    constexpr auto STS = BitField<ethernet_ptp_t, 0, 32>{}; // bit offset: 0, bit width: 32, System time second
    static Register<std::uint32_t, ETHERNET_PTP_BASE_ADDRESS + 0x00000008u, 0, READONLY, decltype(STS)> PTPTSHR; // Ethernet PTP time stamp high register

    constexpr auto STSS = BitField<ethernet_ptp_t, 0, 31>{}; // bit offset: 0, bit width: 31, System time subseconds
    constexpr auto STPNS = BitField<ethernet_ptp_t, 31, 1>{}; // bit offset: 31, bit width: 1, System time positive or negative sign
    static Register<std::uint32_t, ETHERNET_PTP_BASE_ADDRESS + 0x0000000cu, 0, READONLY, decltype(STSS), decltype(STPNS)> PTPTSLR; // Ethernet PTP time stamp low register

    constexpr auto TSUS = BitField<ethernet_ptp_t, 0, 32>{}; // bit offset: 0, bit width: 32, Time stamp update second
    static Register<std::uint32_t, ETHERNET_PTP_BASE_ADDRESS + 0x00000010u, 0, READWRITE, decltype(TSUS)> PTPTSHUR; // Ethernet PTP time stamp high update register

    constexpr auto TSUSS = BitField<ethernet_ptp_t, 0, 31>{}; // bit offset: 0, bit width: 31, Time stamp update subseconds
    constexpr auto TSUPNS = BitField<ethernet_ptp_t, 31, 1>{}; // bit offset: 31, bit width: 1, Time stamp update positive or negative sign
    static Register<std::uint32_t, ETHERNET_PTP_BASE_ADDRESS + 0x00000014u, 0, READWRITE, decltype(TSUSS), decltype(TSUPNS)> PTPTSLUR; // Ethernet PTP time stamp low update register

    constexpr auto TSA = BitField<ethernet_ptp_t, 0, 32>{}; // bit offset: 0, bit width: 32, Time stamp addend
    static Register<std::uint32_t, ETHERNET_PTP_BASE_ADDRESS + 0x00000018u, 0, READWRITE, decltype(TSA)> PTPTSAR; // Ethernet PTP time stamp addend register

    constexpr auto TTSH = BitField<ethernet_ptp_t, 0, 32>{}; // bit offset: 0, bit width: 32, Target time stamp high
    static Register<std::uint32_t, ETHERNET_PTP_BASE_ADDRESS + 0x0000001cu, 0, READWRITE, decltype(TTSH)> PTPTTHR; // Ethernet PTP target time high register

    constexpr auto TTSL = BitField<ethernet_ptp_t, 0, 32>{}; // bit offset: 0, bit width: 32, Target time stamp low
    static Register<std::uint32_t, ETHERNET_PTP_BASE_ADDRESS + 0x00000020u, 0, READWRITE, decltype(TTSL)> PTPTTLR; // Ethernet PTP target time low register

    constexpr auto TSSO = BitField<ethernet_ptp_t, 0, 1>{}; // bit offset: 0, bit width: 1, Time stamp second overflow
    constexpr auto TSTTR = BitField<ethernet_ptp_t, 1, 1>{}; // bit offset: 1, bit width: 1, Time stamp target time reached
    static Register<std::uint32_t, ETHERNET_PTP_BASE_ADDRESS + 0x00000028u, 0, READONLY, decltype(TSSO), decltype(TSTTR)> PTPTSSR; // Ethernet PTP time stamp status register

    constexpr auto PPSFREQ = BitField<ethernet_ptp_t, 0, 4>{}; // bit offset: 0, bit width: 4, PPS frequency selection
    static Register<std::uint32_t, ETHERNET_PTP_BASE_ADDRESS + 0x0000002cu, 0, READONLY, decltype(PPSFREQ)> PTPPPSCR; // Ethernet PTP PPS control register

} // namespace ETHERNET_PTP