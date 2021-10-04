#include <Register.hpp>

namespace ETHERNET_DMA
{
    struct ethernet_dma_t{};

    constexpr std::uint32_t ETHERNET_DMA_BASE_ADDRESS = 0x40029000u;

    constexpr auto SR = BitField<ethernet_dma_t, 0, 1, "SR">{}; // bit offset: 0, bit width: 1, Software reset
    constexpr auto DA = BitField<ethernet_dma_t, 1, 1, "DA">{}; // bit offset: 1, bit width: 1, DMA Arbitration
    constexpr auto DSL = BitField<ethernet_dma_t, 2, 5, "DSL">{}; // bit offset: 2, bit width: 5, Descriptor skip length
    constexpr auto EDFE = BitField<ethernet_dma_t, 7, 1, "EDFE">{}; // bit offset: 7, bit width: 1, Enhanced descriptor format enable
    constexpr auto PBL = BitField<ethernet_dma_t, 8, 6, "PBL">{}; // bit offset: 8, bit width: 6, Programmable burst length
    constexpr auto RTPR = BitField<ethernet_dma_t, 14, 2, "RTPR">{}; // bit offset: 14, bit width: 2, Rx Tx priority ratio
    constexpr auto FB = BitField<ethernet_dma_t, 16, 1, "FB">{}; // bit offset: 16, bit width: 1, Fixed burst
    constexpr auto RDP = BitField<ethernet_dma_t, 17, 6, "RDP">{}; // bit offset: 17, bit width: 6, Rx DMA PBL
    constexpr auto USP = BitField<ethernet_dma_t, 23, 1, "USP">{}; // bit offset: 23, bit width: 1, Use separate PBL
    constexpr auto FPM = BitField<ethernet_dma_t, 24, 1, "FPM">{}; // bit offset: 24, bit width: 1, 4xPBL mode
    constexpr auto AAB = BitField<ethernet_dma_t, 25, 1, "AAB">{}; // bit offset: 25, bit width: 1, Address-aligned beats
    constexpr auto MB = BitField<ethernet_dma_t, 26, 1, "MB">{}; // bit offset: 26, bit width: 1, Mixed burst
    static Register<std::uint32_t, ETHERNET_DMA_BASE_ADDRESS + 0x00000000u, 131329, READWRITE, "DMABMR", decltype(SR), decltype(DA), decltype(DSL), decltype(EDFE), decltype(PBL), decltype(RTPR), decltype(FB), decltype(RDP), decltype(USP), decltype(FPM), decltype(AAB), decltype(MB)> DMABMR; // Ethernet DMA bus mode register

    constexpr auto TPD = BitField<ethernet_dma_t, 0, 32, "TPD">{}; // bit offset: 0, bit width: 32, Transmit poll demand
    static Register<std::uint32_t, ETHERNET_DMA_BASE_ADDRESS + 0x00000004u, 0, READWRITE, "DMATPDR", decltype(TPD)> DMATPDR; // Ethernet DMA transmit poll demand register

    constexpr auto RPD = BitField<ethernet_dma_t, 0, 32, "RPD">{}; // bit offset: 0, bit width: 32, Receive poll demand
    static Register<std::uint32_t, ETHERNET_DMA_BASE_ADDRESS + 0x00000008u, 0, READWRITE, "DMARPDR", decltype(RPD)> DMARPDR; // EHERNET DMA receive poll demand register

    constexpr auto SRL = BitField<ethernet_dma_t, 0, 32, "SRL">{}; // bit offset: 0, bit width: 32, Start of receive list
    static Register<std::uint32_t, ETHERNET_DMA_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, "DMARDLAR", decltype(SRL)> DMARDLAR; // Ethernet DMA receive descriptor list address register

    constexpr auto STL = BitField<ethernet_dma_t, 0, 32, "STL">{}; // bit offset: 0, bit width: 32, Start of transmit list
    static Register<std::uint32_t, ETHERNET_DMA_BASE_ADDRESS + 0x00000010u, 0, READWRITE, "DMATDLAR", decltype(STL)> DMATDLAR; // Ethernet DMA transmit descriptor list address register

    constexpr auto TS = BitField<ethernet_dma_t, 0, 1, "TS", READWRITE>{}; // bit offset: 0, bit width: 1, Transmit status
    constexpr auto TPSS = BitField<ethernet_dma_t, 1, 1, "TPSS", READWRITE>{}; // bit offset: 1, bit width: 1, Transmit process stopped status
    constexpr auto TBUS = BitField<ethernet_dma_t, 2, 1, "TBUS", READWRITE>{}; // bit offset: 2, bit width: 1, Transmit buffer unavailable status
    constexpr auto TJTS = BitField<ethernet_dma_t, 3, 1, "TJTS", READWRITE>{}; // bit offset: 3, bit width: 1, Transmit jabber timeout status
    constexpr auto ROS = BitField<ethernet_dma_t, 4, 1, "ROS", READWRITE>{}; // bit offset: 4, bit width: 1, Receive overflow status
    constexpr auto TUS = BitField<ethernet_dma_t, 5, 1, "TUS", READWRITE>{}; // bit offset: 5, bit width: 1, Transmit underflow status
    constexpr auto RS = BitField<ethernet_dma_t, 6, 1, "RS", READWRITE>{}; // bit offset: 6, bit width: 1, Receive status
    constexpr auto RBUS = BitField<ethernet_dma_t, 7, 1, "RBUS", READWRITE>{}; // bit offset: 7, bit width: 1, Receive buffer unavailable status
    constexpr auto RPSS = BitField<ethernet_dma_t, 8, 1, "RPSS", READWRITE>{}; // bit offset: 8, bit width: 1, Receive process stopped status
    constexpr auto PWTS = BitField<ethernet_dma_t, 9, 1, "PWTS", READWRITE>{}; // bit offset: 9, bit width: 1, Receive watchdog timeout status
    constexpr auto ETS = BitField<ethernet_dma_t, 10, 1, "ETS", READWRITE>{}; // bit offset: 10, bit width: 1, Early transmit status
    constexpr auto FBES = BitField<ethernet_dma_t, 13, 1, "FBES", READWRITE>{}; // bit offset: 13, bit width: 1, Fatal bus error status
    constexpr auto ERS = BitField<ethernet_dma_t, 14, 1, "ERS", READWRITE>{}; // bit offset: 14, bit width: 1, Early receive status
    constexpr auto AIS = BitField<ethernet_dma_t, 15, 1, "AIS", READWRITE>{}; // bit offset: 15, bit width: 1, Abnormal interrupt summary
    constexpr auto NIS = BitField<ethernet_dma_t, 16, 1, "NIS", READWRITE>{}; // bit offset: 16, bit width: 1, Normal interrupt summary
    constexpr auto RPS = BitField<ethernet_dma_t, 17, 3, "RPS", READONLY>{}; // bit offset: 17, bit width: 3, Receive process state
    constexpr auto TPS = BitField<ethernet_dma_t, 20, 3, "TPS", READONLY>{}; // bit offset: 20, bit width: 3, Transmit process state
    constexpr auto EBS = BitField<ethernet_dma_t, 23, 3, "EBS", READONLY>{}; // bit offset: 23, bit width: 3, Error bits status
    constexpr auto MMCS = BitField<ethernet_dma_t, 27, 1, "MMCS", READONLY>{}; // bit offset: 27, bit width: 1, MMC status
    constexpr auto PMTS = BitField<ethernet_dma_t, 28, 1, "PMTS", READONLY>{}; // bit offset: 28, bit width: 1, PMT status
    constexpr auto TSTS = BitField<ethernet_dma_t, 29, 1, "TSTS", READONLY>{}; // bit offset: 29, bit width: 1, Time stamp trigger status
    static Register<std::uint32_t, ETHERNET_DMA_BASE_ADDRESS + 0x00000014u, 0, READWRITE, "DMASR", decltype(TS), decltype(TPSS), decltype(TBUS), decltype(TJTS), decltype(ROS), decltype(TUS), decltype(RS), decltype(RBUS), decltype(RPSS), decltype(PWTS), decltype(ETS), decltype(FBES), decltype(ERS), decltype(AIS), decltype(NIS), decltype(RPS), decltype(TPS), decltype(EBS), decltype(MMCS), decltype(PMTS), decltype(TSTS)> DMASR; // Ethernet DMA status register

    constexpr auto SR = BitField<ethernet_dma_t, 1, 1, "SR">{}; // bit offset: 1, bit width: 1, SR
    constexpr auto OSF = BitField<ethernet_dma_t, 2, 1, "OSF">{}; // bit offset: 2, bit width: 1, OSF
    constexpr auto RTC = BitField<ethernet_dma_t, 3, 2, "RTC">{}; // bit offset: 3, bit width: 2, RTC
    constexpr auto FUGF = BitField<ethernet_dma_t, 6, 1, "FUGF">{}; // bit offset: 6, bit width: 1, FUGF
    constexpr auto FEF = BitField<ethernet_dma_t, 7, 1, "FEF">{}; // bit offset: 7, bit width: 1, FEF
    constexpr auto ST = BitField<ethernet_dma_t, 13, 1, "ST">{}; // bit offset: 13, bit width: 1, ST
    constexpr auto TTC = BitField<ethernet_dma_t, 14, 3, "TTC">{}; // bit offset: 14, bit width: 3, TTC
    constexpr auto FTF = BitField<ethernet_dma_t, 20, 1, "FTF">{}; // bit offset: 20, bit width: 1, FTF
    constexpr auto TSF = BitField<ethernet_dma_t, 21, 1, "TSF">{}; // bit offset: 21, bit width: 1, TSF
    constexpr auto DFRF = BitField<ethernet_dma_t, 24, 1, "DFRF">{}; // bit offset: 24, bit width: 1, DFRF
    constexpr auto RSF = BitField<ethernet_dma_t, 25, 1, "RSF">{}; // bit offset: 25, bit width: 1, RSF
    constexpr auto DTCEFD = BitField<ethernet_dma_t, 26, 1, "DTCEFD">{}; // bit offset: 26, bit width: 1, DTCEFD
    static Register<std::uint32_t, ETHERNET_DMA_BASE_ADDRESS + 0x00000018u, 0, READWRITE, "DMAOMR", decltype(SR), decltype(OSF), decltype(RTC), decltype(FUGF), decltype(FEF), decltype(ST), decltype(TTC), decltype(FTF), decltype(TSF), decltype(DFRF), decltype(RSF), decltype(DTCEFD)> DMAOMR; // Ethernet DMA operation mode register

    constexpr auto TIE = BitField<ethernet_dma_t, 0, 1, "TIE">{}; // bit offset: 0, bit width: 1, Transmit interrupt enable
    constexpr auto TPSIE = BitField<ethernet_dma_t, 1, 1, "TPSIE">{}; // bit offset: 1, bit width: 1, Transmit process stopped interrupt enable
    constexpr auto TBUIE = BitField<ethernet_dma_t, 2, 1, "TBUIE">{}; // bit offset: 2, bit width: 1, Transmit buffer unavailable interrupt enable
    constexpr auto TJTIE = BitField<ethernet_dma_t, 3, 1, "TJTIE">{}; // bit offset: 3, bit width: 1, Transmit jabber timeout interrupt enable
    constexpr auto ROIE = BitField<ethernet_dma_t, 4, 1, "ROIE">{}; // bit offset: 4, bit width: 1, Overflow interrupt enable
    constexpr auto TUIE = BitField<ethernet_dma_t, 5, 1, "TUIE">{}; // bit offset: 5, bit width: 1, Underflow interrupt enable
    constexpr auto RIE = BitField<ethernet_dma_t, 6, 1, "RIE">{}; // bit offset: 6, bit width: 1, Receive interrupt enable
    constexpr auto RBUIE = BitField<ethernet_dma_t, 7, 1, "RBUIE">{}; // bit offset: 7, bit width: 1, Receive buffer unavailable interrupt enable
    constexpr auto RPSIE = BitField<ethernet_dma_t, 8, 1, "RPSIE">{}; // bit offset: 8, bit width: 1, Receive process stopped interrupt enable
    constexpr auto RWTIE = BitField<ethernet_dma_t, 9, 1, "RWTIE">{}; // bit offset: 9, bit width: 1, receive watchdog timeout interrupt enable
    constexpr auto ETIE = BitField<ethernet_dma_t, 10, 1, "ETIE">{}; // bit offset: 10, bit width: 1, Early transmit interrupt enable
    constexpr auto FBEIE = BitField<ethernet_dma_t, 13, 1, "FBEIE">{}; // bit offset: 13, bit width: 1, Fatal bus error interrupt enable
    constexpr auto ERIE = BitField<ethernet_dma_t, 14, 1, "ERIE">{}; // bit offset: 14, bit width: 1, Early receive interrupt enable
    constexpr auto AISE = BitField<ethernet_dma_t, 15, 1, "AISE">{}; // bit offset: 15, bit width: 1, Abnormal interrupt summary enable
    constexpr auto NISE = BitField<ethernet_dma_t, 16, 1, "NISE">{}; // bit offset: 16, bit width: 1, Normal interrupt summary enable
    static Register<std::uint32_t, ETHERNET_DMA_BASE_ADDRESS + 0x0000001cu, 0, READWRITE, "DMAIER", decltype(TIE), decltype(TPSIE), decltype(TBUIE), decltype(TJTIE), decltype(ROIE), decltype(TUIE), decltype(RIE), decltype(RBUIE), decltype(RPSIE), decltype(RWTIE), decltype(ETIE), decltype(FBEIE), decltype(ERIE), decltype(AISE), decltype(NISE)> DMAIER; // Ethernet DMA interrupt enable register

    constexpr auto MFC = BitField<ethernet_dma_t, 0, 16, "MFC">{}; // bit offset: 0, bit width: 16, Missed frames by the controller
    constexpr auto OMFC = BitField<ethernet_dma_t, 16, 1, "OMFC">{}; // bit offset: 16, bit width: 1, Overflow bit for missed frame counter
    constexpr auto MFA = BitField<ethernet_dma_t, 17, 11, "MFA">{}; // bit offset: 17, bit width: 11, Missed frames by the application
    constexpr auto OFOC = BitField<ethernet_dma_t, 28, 1, "OFOC">{}; // bit offset: 28, bit width: 1, Overflow bit for FIFO overflow counter
    static Register<std::uint32_t, ETHERNET_DMA_BASE_ADDRESS + 0x00000020u, 0, READWRITE, "DMAMFBOCR", decltype(MFC), decltype(OMFC), decltype(MFA), decltype(OFOC)> DMAMFBOCR; // Ethernet DMA missed frame and buffer overflow counter register

    constexpr auto RSWTC = BitField<ethernet_dma_t, 0, 8, "RSWTC">{}; // bit offset: 0, bit width: 8, Receive status watchdog timer count
    static Register<std::uint32_t, ETHERNET_DMA_BASE_ADDRESS + 0x00000024u, 0, READWRITE, "DMARSWTR", decltype(RSWTC)> DMARSWTR; // Ethernet DMA receive status watchdog timer register

    constexpr auto HTDAP = BitField<ethernet_dma_t, 0, 32, "HTDAP">{}; // bit offset: 0, bit width: 32, Host transmit descriptor address pointer
    static Register<std::uint32_t, ETHERNET_DMA_BASE_ADDRESS + 0x00000048u, 0, READONLY, "DMACHTDR", decltype(HTDAP)> DMACHTDR; // Ethernet DMA current host transmit descriptor register

    constexpr auto HRDAP = BitField<ethernet_dma_t, 0, 32, "HRDAP">{}; // bit offset: 0, bit width: 32, Host receive descriptor address pointer
    static Register<std::uint32_t, ETHERNET_DMA_BASE_ADDRESS + 0x0000004cu, 0, READONLY, "DMACHRDR", decltype(HRDAP)> DMACHRDR; // Ethernet DMA current host receive descriptor register

    constexpr auto HTBAP = BitField<ethernet_dma_t, 0, 32, "HTBAP">{}; // bit offset: 0, bit width: 32, Host transmit buffer address pointer
    static Register<std::uint32_t, ETHERNET_DMA_BASE_ADDRESS + 0x00000050u, 0, READONLY, "DMACHTBAR", decltype(HTBAP)> DMACHTBAR; // Ethernet DMA current host transmit buffer address register

    constexpr auto HRBAP = BitField<ethernet_dma_t, 0, 32, "HRBAP">{}; // bit offset: 0, bit width: 32, Host receive buffer address pointer
    static Register<std::uint32_t, ETHERNET_DMA_BASE_ADDRESS + 0x00000054u, 0, READONLY, "DMACHRBAR", decltype(HRBAP)> DMACHRBAR; // Ethernet DMA current host receive buffer address register

} // namespace ETHERNET_DMA