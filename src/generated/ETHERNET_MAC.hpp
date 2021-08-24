#include <Register.hpp>




namespace ETHERNET_MAC
{
    struct ethernet_mac_t{};

    constexpr std::uint32_t ETHERNET_MAC_BASE_ADDRESS = 0x40028000u;

    constexpr auto RE = BitField<ethernet_mac_t, 2, 1>{}; // bit offset: 2, bit width: 1, RE
    constexpr auto TE = BitField<ethernet_mac_t, 3, 1>{}; // bit offset: 3, bit width: 1, TE
    constexpr auto DC = BitField<ethernet_mac_t, 4, 1>{}; // bit offset: 4, bit width: 1, DC
    constexpr auto BL = BitField<ethernet_mac_t, 5, 2>{}; // bit offset: 5, bit width: 2, BL
    constexpr auto APCS = BitField<ethernet_mac_t, 7, 1>{}; // bit offset: 7, bit width: 1, APCS
    constexpr auto RD = BitField<ethernet_mac_t, 9, 1>{}; // bit offset: 9, bit width: 1, RD
    constexpr auto IPCO = BitField<ethernet_mac_t, 10, 1>{}; // bit offset: 10, bit width: 1, IPCO
    constexpr auto DM = BitField<ethernet_mac_t, 11, 1>{}; // bit offset: 11, bit width: 1, DM
    constexpr auto LM = BitField<ethernet_mac_t, 12, 1>{}; // bit offset: 12, bit width: 1, LM
    constexpr auto ROD = BitField<ethernet_mac_t, 13, 1>{}; // bit offset: 13, bit width: 1, ROD
    constexpr auto FES = BitField<ethernet_mac_t, 14, 1>{}; // bit offset: 14, bit width: 1, FES
    constexpr auto CSD = BitField<ethernet_mac_t, 16, 1>{}; // bit offset: 16, bit width: 1, CSD
    constexpr auto IFG = BitField<ethernet_mac_t, 17, 3>{}; // bit offset: 17, bit width: 3, IFG
    constexpr auto JD = BitField<ethernet_mac_t, 22, 1>{}; // bit offset: 22, bit width: 1, JD
    constexpr auto WD = BitField<ethernet_mac_t, 23, 1>{}; // bit offset: 23, bit width: 1, WD
    constexpr auto CSTF = BitField<ethernet_mac_t, 25, 1>{}; // bit offset: 25, bit width: 1, CSTF
    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x00000000u, 32768, READWRITE, decltype(RE), decltype(TE), decltype(DC), decltype(BL), decltype(APCS), decltype(RD), decltype(IPCO), decltype(DM), decltype(LM), decltype(ROD), decltype(FES), decltype(CSD), decltype(IFG), decltype(JD), decltype(WD), decltype(CSTF)> MACCR; // Ethernet MAC configuration register

    constexpr auto PM = BitField<ethernet_mac_t, 0, 1>{}; // bit offset: 0, bit width: 1, Promiscuous mode
    constexpr auto HU = BitField<ethernet_mac_t, 1, 1>{}; // bit offset: 1, bit width: 1, Hash unicast
    constexpr auto HM = BitField<ethernet_mac_t, 2, 1>{}; // bit offset: 2, bit width: 1, Hash multicast
    constexpr auto DAIF = BitField<ethernet_mac_t, 3, 1>{}; // bit offset: 3, bit width: 1, Destination address inverse filtering
    constexpr auto PAM = BitField<ethernet_mac_t, 4, 1>{}; // bit offset: 4, bit width: 1, Pass all multicast
    constexpr auto BFD = BitField<ethernet_mac_t, 5, 1>{}; // bit offset: 5, bit width: 1, Broadcast frames disable
    constexpr auto PCF = BitField<ethernet_mac_t, 6, 1>{}; // bit offset: 6, bit width: 1, Pass control frames
    constexpr auto SAIF = BitField<ethernet_mac_t, 8, 1>{}; // bit offset: 8, bit width: 1, Source address inverse filtering
    constexpr auto SAF = BitField<ethernet_mac_t, 9, 1>{}; // bit offset: 9, bit width: 1, Source address filter
    constexpr auto HPF = BitField<ethernet_mac_t, 10, 1>{}; // bit offset: 10, bit width: 1, Hash or perfect filter
    constexpr auto RA = BitField<ethernet_mac_t, 31, 1>{}; // bit offset: 31, bit width: 1, Receive all
    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x00000004u, 0, READWRITE, decltype(PM), decltype(HU), decltype(HM), decltype(DAIF), decltype(PAM), decltype(BFD), decltype(PCF), decltype(SAIF), decltype(SAF), decltype(HPF), decltype(RA)> MACFFR; // Ethernet MAC frame filter register

    constexpr auto HTH = BitField<ethernet_mac_t, 0, 32>{}; // bit offset: 0, bit width: 32, Hash table high
    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x00000008u, 0, READWRITE, decltype(HTH)> MACHTHR; // Ethernet MAC hash table high register

    constexpr auto HTL = BitField<ethernet_mac_t, 0, 32>{}; // bit offset: 0, bit width: 32, Hash table low
    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, decltype(HTL)> MACHTLR; // Ethernet MAC hash table low register

    constexpr auto MB = BitField<ethernet_mac_t, 0, 1>{}; // bit offset: 0, bit width: 1, MII busy
    constexpr auto MW = BitField<ethernet_mac_t, 1, 1>{}; // bit offset: 1, bit width: 1, MII write
    constexpr auto CR = BitField<ethernet_mac_t, 2, 3>{}; // bit offset: 2, bit width: 3, Clock range
    constexpr auto MR = BitField<ethernet_mac_t, 6, 5>{}; // bit offset: 6, bit width: 5, MII register
    constexpr auto PA = BitField<ethernet_mac_t, 11, 5>{}; // bit offset: 11, bit width: 5, PHY address
    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x00000010u, 0, READWRITE, decltype(MB), decltype(MW), decltype(CR), decltype(MR), decltype(PA)> MACMIIAR; // Ethernet MAC MII address register

    constexpr auto MD = BitField<ethernet_mac_t, 0, 16>{}; // bit offset: 0, bit width: 16, MII data
    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x00000014u, 0, READWRITE, decltype(MD)> MACMIIDR; // Ethernet MAC MII data register

    constexpr auto FCB = BitField<ethernet_mac_t, 0, 1>{}; // bit offset: 0, bit width: 1, Flow control busy/back pressure activate
    constexpr auto TFCE = BitField<ethernet_mac_t, 1, 1>{}; // bit offset: 1, bit width: 1, Transmit flow control enable
    constexpr auto RFCE = BitField<ethernet_mac_t, 2, 1>{}; // bit offset: 2, bit width: 1, Receive flow control enable
    constexpr auto UPFD = BitField<ethernet_mac_t, 3, 1>{}; // bit offset: 3, bit width: 1, Unicast pause frame detect
    constexpr auto PLT = BitField<ethernet_mac_t, 4, 2>{}; // bit offset: 4, bit width: 2, Pause low threshold
    constexpr auto ZQPD = BitField<ethernet_mac_t, 7, 1>{}; // bit offset: 7, bit width: 1, Zero-quanta pause disable
    constexpr auto PT = BitField<ethernet_mac_t, 16, 16>{}; // bit offset: 16, bit width: 16, Pause time
    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x00000018u, 0, READWRITE, decltype(FCB), decltype(TFCE), decltype(RFCE), decltype(UPFD), decltype(PLT), decltype(ZQPD), decltype(PT)> MACFCR; // Ethernet MAC flow control register

    constexpr auto VLANTI = BitField<ethernet_mac_t, 0, 16>{}; // bit offset: 0, bit width: 16, VLAN tag identifier
    constexpr auto VLANTC = BitField<ethernet_mac_t, 16, 1>{}; // bit offset: 16, bit width: 1, 12-bit VLAN tag comparison
    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x0000001cu, 0, READWRITE, decltype(VLANTI), decltype(VLANTC)> MACVLANTR; // Ethernet MAC VLAN tag register

    constexpr auto PD = BitField<ethernet_mac_t, 0, 1>{}; // bit offset: 0, bit width: 1, Power down
    constexpr auto MPE = BitField<ethernet_mac_t, 1, 1>{}; // bit offset: 1, bit width: 1, Magic Packet enable
    constexpr auto WFE = BitField<ethernet_mac_t, 2, 1>{}; // bit offset: 2, bit width: 1, Wakeup frame enable
    constexpr auto MPR = BitField<ethernet_mac_t, 5, 1>{}; // bit offset: 5, bit width: 1, Magic packet received
    constexpr auto WFR = BitField<ethernet_mac_t, 6, 1>{}; // bit offset: 6, bit width: 1, Wakeup frame received
    constexpr auto GU = BitField<ethernet_mac_t, 9, 1>{}; // bit offset: 9, bit width: 1, Global unicast
    constexpr auto WFFRPR = BitField<ethernet_mac_t, 31, 1>{}; // bit offset: 31, bit width: 1, Wakeup frame filter register pointer reset
    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x0000002cu, 0, READWRITE, decltype(PD), decltype(MPE), decltype(WFE), decltype(MPR), decltype(WFR), decltype(GU), decltype(WFFRPR)> MACPMTCSR; // Ethernet MAC PMT control and status register

    constexpr auto MMRPEA = BitField<ethernet_mac_t, 0, 1>{}; // bit offset: 0, bit width: 1, MAC MII receive protocol engine active
    constexpr auto MSFRWCS = BitField<ethernet_mac_t, 1, 1>{}; // bit offset: 1, bit width: 1, MAC small FIFO read / write controllers status
    constexpr auto RFWRA = BitField<ethernet_mac_t, 4, 1>{}; // bit offset: 4, bit width: 1, Rx FIFO write controller active
    constexpr auto RFRCS = BitField<ethernet_mac_t, 5, 1>{}; // bit offset: 5, bit width: 1, Rx FIFO read controller status
    constexpr auto RFFL = BitField<ethernet_mac_t, 8, 1>{}; // bit offset: 8, bit width: 1, Rx FIFO fill level
    constexpr auto MMTEA = BitField<ethernet_mac_t, 16, 1>{}; // bit offset: 16, bit width: 1, MAC MII transmit engine active
    constexpr auto MTFCS = BitField<ethernet_mac_t, 17, 2>{}; // bit offset: 17, bit width: 2, MAC transmit frame controller status
    constexpr auto MTP = BitField<ethernet_mac_t, 19, 1>{}; // bit offset: 19, bit width: 1, MAC transmitter in pause
    constexpr auto TFRS = BitField<ethernet_mac_t, 20, 2>{}; // bit offset: 20, bit width: 2, Tx FIFO read status
    constexpr auto TFWA = BitField<ethernet_mac_t, 22, 1>{}; // bit offset: 22, bit width: 1, Tx FIFO write active
    constexpr auto TFNE = BitField<ethernet_mac_t, 24, 1>{}; // bit offset: 24, bit width: 1, Tx FIFO not empty
    constexpr auto TFF = BitField<ethernet_mac_t, 25, 1>{}; // bit offset: 25, bit width: 1, Tx FIFO full
    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x00000034u, 0, READONLY, decltype(MMRPEA), decltype(MSFRWCS), decltype(RFWRA), decltype(RFRCS), decltype(RFFL), decltype(MMTEA), decltype(MTFCS), decltype(MTP), decltype(TFRS), decltype(TFWA), decltype(TFNE), decltype(TFF)> MACDBGR; // Ethernet MAC debug register

    constexpr auto PMTS = BitField<ethernet_mac_t, 3, 1, READONLY>{}; // bit offset: 3, bit width: 1, PMT status
    constexpr auto MMCS = BitField<ethernet_mac_t, 4, 1, READONLY>{}; // bit offset: 4, bit width: 1, MMC status
    constexpr auto MMCRS = BitField<ethernet_mac_t, 5, 1, READONLY>{}; // bit offset: 5, bit width: 1, MMC receive status
    constexpr auto MMCTS = BitField<ethernet_mac_t, 6, 1, READONLY>{}; // bit offset: 6, bit width: 1, MMC transmit status
    constexpr auto TSTS = BitField<ethernet_mac_t, 9, 1, READWRITE>{}; // bit offset: 9, bit width: 1, Time stamp trigger status
    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x00000038u, 0, READWRITE, decltype(PMTS), decltype(MMCS), decltype(MMCRS), decltype(MMCTS), decltype(TSTS)> MACSR; // Ethernet MAC interrupt status register

    constexpr auto PMTIM = BitField<ethernet_mac_t, 3, 1>{}; // bit offset: 3, bit width: 1, PMT interrupt mask
    constexpr auto TSTIM = BitField<ethernet_mac_t, 9, 1>{}; // bit offset: 9, bit width: 1, Time stamp trigger interrupt mask
    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x0000003cu, 0, READWRITE, decltype(PMTIM), decltype(TSTIM)> MACIMR; // Ethernet MAC interrupt mask register

    constexpr auto MACA0H = BitField<ethernet_mac_t, 0, 16, READWRITE>{}; // bit offset: 0, bit width: 16, MAC address0 high
    constexpr auto MO = BitField<ethernet_mac_t, 31, 1, READONLY>{}; // bit offset: 31, bit width: 1, MO
    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x00000040u, 1114111, READWRITE, decltype(MACA0H), decltype(MO)> MACA0HR; // Ethernet MAC address 0 high register

    constexpr auto MACA0L = BitField<ethernet_mac_t, 0, 32>{}; // bit offset: 0, bit width: 32, MAC address0 low
    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x00000044u, 4294967295, READWRITE, decltype(MACA0L)> MACA0LR; // Ethernet MAC address 0 low register

    constexpr auto MACA1H = BitField<ethernet_mac_t, 0, 16>{}; // bit offset: 0, bit width: 16, MAC address1 high
    constexpr auto MBC = BitField<ethernet_mac_t, 24, 6>{}; // bit offset: 24, bit width: 6, Mask byte control
    constexpr auto SA = BitField<ethernet_mac_t, 30, 1>{}; // bit offset: 30, bit width: 1, Source address
    constexpr auto AE = BitField<ethernet_mac_t, 31, 1>{}; // bit offset: 31, bit width: 1, Address enable
    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x00000048u, 65535, READWRITE, decltype(MACA1H), decltype(MBC), decltype(SA), decltype(AE)> MACA1HR; // Ethernet MAC address 1 high register

    constexpr auto MACA1LR_ = BitField<ethernet_mac_t, 0, 32>{}; // bit offset: 0, bit width: 32, MAC address1 low
    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x0000004cu, 4294967295, READWRITE, decltype(MACA1LR_)> MACA1LR; // Ethernet MAC address1 low register

    constexpr auto MAC2AH = BitField<ethernet_mac_t, 0, 16>{}; // bit offset: 0, bit width: 16, MAC address2 high
    constexpr auto MBC = BitField<ethernet_mac_t, 24, 6>{}; // bit offset: 24, bit width: 6, Mask byte control
    constexpr auto SA = BitField<ethernet_mac_t, 30, 1>{}; // bit offset: 30, bit width: 1, Source address
    constexpr auto AE = BitField<ethernet_mac_t, 31, 1>{}; // bit offset: 31, bit width: 1, Address enable
    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x00000050u, 65535, READWRITE, decltype(MAC2AH), decltype(MBC), decltype(SA), decltype(AE)> MACA2HR; // Ethernet MAC address 2 high register

    constexpr auto MACA2L = BitField<ethernet_mac_t, 0, 31>{}; // bit offset: 0, bit width: 31, MAC address2 low
    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x00000054u, 4294967295, READWRITE, decltype(MACA2L)> MACA2LR; // Ethernet MAC address 2 low register

    constexpr auto MACA3H = BitField<ethernet_mac_t, 0, 16>{}; // bit offset: 0, bit width: 16, MAC address3 high
    constexpr auto MBC = BitField<ethernet_mac_t, 24, 6>{}; // bit offset: 24, bit width: 6, Mask byte control
    constexpr auto SA = BitField<ethernet_mac_t, 30, 1>{}; // bit offset: 30, bit width: 1, Source address
    constexpr auto AE = BitField<ethernet_mac_t, 31, 1>{}; // bit offset: 31, bit width: 1, Address enable
    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x00000058u, 65535, READWRITE, decltype(MACA3H), decltype(MBC), decltype(SA), decltype(AE)> MACA3HR; // Ethernet MAC address 3 high register

    constexpr auto MBCA3L = BitField<ethernet_mac_t, 0, 32>{}; // bit offset: 0, bit width: 32, MAC address3 low
    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x0000005cu, 4294967295, READWRITE, decltype(MBCA3L)> MACA3LR; // Ethernet MAC address 3 low register

    static Register<std::uint32_t, ETHERNET_MAC_BASE_ADDRESS + 0x00000028u, 0, READWRITE> MACRWUFFR; // Ethernet MAC remote wakeup frame filter register

} // namespace ETHERNET_MAC