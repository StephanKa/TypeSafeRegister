#include <Register.hpp>

namespace OTG_FS_GLOBAL
{
    struct otg_fs_global_t{};

    constexpr std::uint32_t OTG_FS_GLOBAL_BASE_ADDRESS = 0x50000000u;

    constexpr auto SRQSCS = BitField<otg_fs_global_t, 0, 1, "SRQSCS", READONLY>{}; // bit offset: 0, bit width: 1, Session request success
    constexpr auto SRQ = BitField<otg_fs_global_t, 1, 1, "SRQ", READWRITE>{}; // bit offset: 1, bit width: 1, Session request
    constexpr auto HNGSCS = BitField<otg_fs_global_t, 8, 1, "HNGSCS", READONLY>{}; // bit offset: 8, bit width: 1, Host negotiation success
    constexpr auto HNPRQ = BitField<otg_fs_global_t, 9, 1, "HNPRQ", READWRITE>{}; // bit offset: 9, bit width: 1, HNP request
    constexpr auto HSHNPEN = BitField<otg_fs_global_t, 10, 1, "HSHNPEN", READWRITE>{}; // bit offset: 10, bit width: 1, Host set HNP enable
    constexpr auto DHNPEN = BitField<otg_fs_global_t, 11, 1, "DHNPEN", READWRITE>{}; // bit offset: 11, bit width: 1, Device HNP enabled
    constexpr auto CIDSTS = BitField<otg_fs_global_t, 16, 1, "CIDSTS", READONLY>{}; // bit offset: 16, bit width: 1, Connector ID status
    constexpr auto DBCT = BitField<otg_fs_global_t, 17, 1, "DBCT", READONLY>{}; // bit offset: 17, bit width: 1, Long/short debounce time
    constexpr auto ASVLD = BitField<otg_fs_global_t, 18, 1, "ASVLD", READONLY>{}; // bit offset: 18, bit width: 1, A-session valid
    constexpr auto BSVLD = BitField<otg_fs_global_t, 19, 1, "BSVLD", READONLY>{}; // bit offset: 19, bit width: 1, B-session valid
    static Register<std::uint32_t, OTG_FS_GLOBAL_BASE_ADDRESS + 0x00000000u, 2048, READWRITE, "FS_GOTGCTL", decltype(SRQSCS), decltype(SRQ), decltype(HNGSCS), decltype(HNPRQ), decltype(HSHNPEN), decltype(DHNPEN), decltype(CIDSTS), decltype(DBCT), decltype(ASVLD), decltype(BSVLD)> FS_GOTGCTL; // OTG_FS control and status register (OTG_FS_GOTGCTL)

    constexpr auto SEDET = BitField<otg_fs_global_t, 2, 1, "SEDET">{}; // bit offset: 2, bit width: 1, Session end detected
    constexpr auto SRSSCHG = BitField<otg_fs_global_t, 8, 1, "SRSSCHG">{}; // bit offset: 8, bit width: 1, Session request success status change
    constexpr auto HNSSCHG = BitField<otg_fs_global_t, 9, 1, "HNSSCHG">{}; // bit offset: 9, bit width: 1, Host negotiation success status change
    constexpr auto HNGDET = BitField<otg_fs_global_t, 17, 1, "HNGDET">{}; // bit offset: 17, bit width: 1, Host negotiation detected
    constexpr auto ADTOCHG = BitField<otg_fs_global_t, 18, 1, "ADTOCHG">{}; // bit offset: 18, bit width: 1, A-device timeout change
    constexpr auto DBCDNE = BitField<otg_fs_global_t, 19, 1, "DBCDNE">{}; // bit offset: 19, bit width: 1, Debounce done
    static Register<std::uint32_t, OTG_FS_GLOBAL_BASE_ADDRESS + 0x00000004u, 0, READWRITE, "FS_GOTGINT", decltype(SEDET), decltype(SRSSCHG), decltype(HNSSCHG), decltype(HNGDET), decltype(ADTOCHG), decltype(DBCDNE)> FS_GOTGINT; // OTG_FS interrupt register (OTG_FS_GOTGINT)

    constexpr auto GINT = BitField<otg_fs_global_t, 0, 1, "GINT">{}; // bit offset: 0, bit width: 1, Global interrupt mask
    constexpr auto TXFELVL = BitField<otg_fs_global_t, 7, 1, "TXFELVL">{}; // bit offset: 7, bit width: 1, TxFIFO empty level
    constexpr auto PTXFELVL = BitField<otg_fs_global_t, 8, 1, "PTXFELVL">{}; // bit offset: 8, bit width: 1, Periodic TxFIFO empty level
    static Register<std::uint32_t, OTG_FS_GLOBAL_BASE_ADDRESS + 0x00000008u, 0, READWRITE, "FS_GAHBCFG", decltype(GINT), decltype(TXFELVL), decltype(PTXFELVL)> FS_GAHBCFG; // OTG_FS AHB configuration register (OTG_FS_GAHBCFG)

    constexpr auto TOCAL = BitField<otg_fs_global_t, 0, 3, "TOCAL", READWRITE>{}; // bit offset: 0, bit width: 3, FS timeout calibration
    constexpr auto PHYSEL = BitField<otg_fs_global_t, 6, 1, "PHYSEL", WRITEONLY>{}; // bit offset: 6, bit width: 1, Full Speed serial transceiver select
    constexpr auto SRPCAP = BitField<otg_fs_global_t, 8, 1, "SRPCAP", READWRITE>{}; // bit offset: 8, bit width: 1, SRP-capable
    constexpr auto HNPCAP = BitField<otg_fs_global_t, 9, 1, "HNPCAP", READWRITE>{}; // bit offset: 9, bit width: 1, HNP-capable
    constexpr auto TRDT = BitField<otg_fs_global_t, 10, 4, "TRDT", READWRITE>{}; // bit offset: 10, bit width: 4, USB turnaround time
    constexpr auto FHMOD = BitField<otg_fs_global_t, 29, 1, "FHMOD", READWRITE>{}; // bit offset: 29, bit width: 1, Force host mode
    constexpr auto FDMOD = BitField<otg_fs_global_t, 30, 1, "FDMOD", READWRITE>{}; // bit offset: 30, bit width: 1, Force device mode
    constexpr auto CTXPKT = BitField<otg_fs_global_t, 31, 1, "CTXPKT", READWRITE>{}; // bit offset: 31, bit width: 1, Corrupt Tx packet
    static Register<std::uint32_t, OTG_FS_GLOBAL_BASE_ADDRESS + 0x0000000cu, 2560, READWRITE, "FS_GUSBCFG", decltype(TOCAL), decltype(PHYSEL), decltype(SRPCAP), decltype(HNPCAP), decltype(TRDT), decltype(FHMOD), decltype(FDMOD), decltype(CTXPKT)> FS_GUSBCFG; // OTG_FS USB configuration register (OTG_FS_GUSBCFG)

    constexpr auto CSRST = BitField<otg_fs_global_t, 0, 1, "CSRST", READWRITE>{}; // bit offset: 0, bit width: 1, Core soft reset
    constexpr auto HSRST = BitField<otg_fs_global_t, 1, 1, "HSRST", READWRITE>{}; // bit offset: 1, bit width: 1, HCLK soft reset
    constexpr auto FCRST = BitField<otg_fs_global_t, 2, 1, "FCRST", READWRITE>{}; // bit offset: 2, bit width: 1, Host frame counter reset
    constexpr auto RXFFLSH = BitField<otg_fs_global_t, 4, 1, "RXFFLSH", READWRITE>{}; // bit offset: 4, bit width: 1, RxFIFO flush
    constexpr auto TXFFLSH = BitField<otg_fs_global_t, 5, 1, "TXFFLSH", READWRITE>{}; // bit offset: 5, bit width: 1, TxFIFO flush
    constexpr auto TXFNUM = BitField<otg_fs_global_t, 6, 5, "TXFNUM", READWRITE>{}; // bit offset: 6, bit width: 5, TxFIFO number
    constexpr auto AHBIDL = BitField<otg_fs_global_t, 31, 1, "AHBIDL", READONLY>{}; // bit offset: 31, bit width: 1, AHB master idle
    static Register<std::uint32_t, OTG_FS_GLOBAL_BASE_ADDRESS + 0x00000010u, 536870912, READWRITE, "FS_GRSTCTL", decltype(CSRST), decltype(HSRST), decltype(FCRST), decltype(RXFFLSH), decltype(TXFFLSH), decltype(TXFNUM), decltype(AHBIDL)> FS_GRSTCTL; // OTG_FS reset register (OTG_FS_GRSTCTL)

    constexpr auto CMOD = BitField<otg_fs_global_t, 0, 1, "CMOD", READONLY>{}; // bit offset: 0, bit width: 1, Current mode of operation
    constexpr auto MMIS = BitField<otg_fs_global_t, 1, 1, "MMIS", READWRITE>{}; // bit offset: 1, bit width: 1, Mode mismatch interrupt
    constexpr auto OTGINT = BitField<otg_fs_global_t, 2, 1, "OTGINT", READONLY>{}; // bit offset: 2, bit width: 1, OTG interrupt
    constexpr auto SOF = BitField<otg_fs_global_t, 3, 1, "SOF", READWRITE>{}; // bit offset: 3, bit width: 1, Start of frame
    constexpr auto RXFLVL = BitField<otg_fs_global_t, 4, 1, "RXFLVL", READONLY>{}; // bit offset: 4, bit width: 1, RxFIFO non-empty
    constexpr auto NPTXFE = BitField<otg_fs_global_t, 5, 1, "NPTXFE", READONLY>{}; // bit offset: 5, bit width: 1, Non-periodic TxFIFO empty
    constexpr auto GINAKEFF = BitField<otg_fs_global_t, 6, 1, "GINAKEFF", READONLY>{}; // bit offset: 6, bit width: 1, Global IN non-periodic NAK effective
    constexpr auto GOUTNAKEFF = BitField<otg_fs_global_t, 7, 1, "GOUTNAKEFF", READONLY>{}; // bit offset: 7, bit width: 1, Global OUT NAK effective
    constexpr auto ESUSP = BitField<otg_fs_global_t, 10, 1, "ESUSP", READWRITE>{}; // bit offset: 10, bit width: 1, Early suspend
    constexpr auto USBSUSP = BitField<otg_fs_global_t, 11, 1, "USBSUSP", READWRITE>{}; // bit offset: 11, bit width: 1, USB suspend
    constexpr auto USBRST = BitField<otg_fs_global_t, 12, 1, "USBRST", READWRITE>{}; // bit offset: 12, bit width: 1, USB reset
    constexpr auto ENUMDNE = BitField<otg_fs_global_t, 13, 1, "ENUMDNE", READWRITE>{}; // bit offset: 13, bit width: 1, Enumeration done
    constexpr auto ISOODRP = BitField<otg_fs_global_t, 14, 1, "ISOODRP", READWRITE>{}; // bit offset: 14, bit width: 1, Isochronous OUT packet dropped interrupt
    constexpr auto EOPF = BitField<otg_fs_global_t, 15, 1, "EOPF", READWRITE>{}; // bit offset: 15, bit width: 1, End of periodic frame interrupt
    constexpr auto IEPINT = BitField<otg_fs_global_t, 18, 1, "IEPINT", READONLY>{}; // bit offset: 18, bit width: 1, IN endpoint interrupt
    constexpr auto OEPINT = BitField<otg_fs_global_t, 19, 1, "OEPINT", READONLY>{}; // bit offset: 19, bit width: 1, OUT endpoint interrupt
    constexpr auto IISOIXFR = BitField<otg_fs_global_t, 20, 1, "IISOIXFR", READWRITE>{}; // bit offset: 20, bit width: 1, Incomplete isochronous IN transfer
    constexpr auto IPXFR_INCOMPISOOUT = BitField<otg_fs_global_t, 21, 1, "IPXFR_INCOMPISOOUT", READWRITE>{}; // bit offset: 21, bit width: 1, Incomplete periodic transfer(Host mode)/Incomplete isochronous OUT transfer(Device mode)
    constexpr auto HPRTINT = BitField<otg_fs_global_t, 24, 1, "HPRTINT", READONLY>{}; // bit offset: 24, bit width: 1, Host port interrupt
    constexpr auto HCINT = BitField<otg_fs_global_t, 25, 1, "HCINT", READONLY>{}; // bit offset: 25, bit width: 1, Host channels interrupt
    constexpr auto PTXFE = BitField<otg_fs_global_t, 26, 1, "PTXFE", READONLY>{}; // bit offset: 26, bit width: 1, Periodic TxFIFO empty
    constexpr auto CIDSCHG = BitField<otg_fs_global_t, 28, 1, "CIDSCHG", READWRITE>{}; // bit offset: 28, bit width: 1, Connector ID status change
    constexpr auto DISCINT = BitField<otg_fs_global_t, 29, 1, "DISCINT", READWRITE>{}; // bit offset: 29, bit width: 1, Disconnect detected interrupt
    constexpr auto SRQINT = BitField<otg_fs_global_t, 30, 1, "SRQINT", READWRITE>{}; // bit offset: 30, bit width: 1, Session request/new session detected interrupt
    constexpr auto WKUPINT = BitField<otg_fs_global_t, 31, 1, "WKUPINT", READWRITE>{}; // bit offset: 31, bit width: 1, Resume/remote wakeup detected interrupt
    static Register<std::uint32_t, OTG_FS_GLOBAL_BASE_ADDRESS + 0x00000014u, 67108896, READWRITE, "FS_GINTSTS", decltype(CMOD), decltype(MMIS), decltype(OTGINT), decltype(SOF), decltype(RXFLVL), decltype(NPTXFE), decltype(GINAKEFF), decltype(GOUTNAKEFF), decltype(ESUSP), decltype(USBSUSP), decltype(USBRST), decltype(ENUMDNE), decltype(ISOODRP), decltype(EOPF), decltype(IEPINT), decltype(OEPINT), decltype(IISOIXFR), decltype(IPXFR_INCOMPISOOUT), decltype(HPRTINT), decltype(HCINT), decltype(PTXFE), decltype(CIDSCHG), decltype(DISCINT), decltype(SRQINT), decltype(WKUPINT)> FS_GINTSTS; // OTG_FS core interrupt register (OTG_FS_GINTSTS)

    constexpr auto MMISM = BitField<otg_fs_global_t, 1, 1, "MMISM", READWRITE>{}; // bit offset: 1, bit width: 1, Mode mismatch interrupt mask
    constexpr auto OTGINT = BitField<otg_fs_global_t, 2, 1, "OTGINT", READWRITE>{}; // bit offset: 2, bit width: 1, OTG interrupt mask
    constexpr auto SOFM = BitField<otg_fs_global_t, 3, 1, "SOFM", READWRITE>{}; // bit offset: 3, bit width: 1, Start of frame mask
    constexpr auto RXFLVLM = BitField<otg_fs_global_t, 4, 1, "RXFLVLM", READWRITE>{}; // bit offset: 4, bit width: 1, Receive FIFO non-empty mask
    constexpr auto NPTXFEM = BitField<otg_fs_global_t, 5, 1, "NPTXFEM", READWRITE>{}; // bit offset: 5, bit width: 1, Non-periodic TxFIFO empty mask
    constexpr auto GINAKEFFM = BitField<otg_fs_global_t, 6, 1, "GINAKEFFM", READWRITE>{}; // bit offset: 6, bit width: 1, Global non-periodic IN NAK effective mask
    constexpr auto GONAKEFFM = BitField<otg_fs_global_t, 7, 1, "GONAKEFFM", READWRITE>{}; // bit offset: 7, bit width: 1, Global OUT NAK effective mask
    constexpr auto ESUSPM = BitField<otg_fs_global_t, 10, 1, "ESUSPM", READWRITE>{}; // bit offset: 10, bit width: 1, Early suspend mask
    constexpr auto USBSUSPM = BitField<otg_fs_global_t, 11, 1, "USBSUSPM", READWRITE>{}; // bit offset: 11, bit width: 1, USB suspend mask
    constexpr auto USBRST = BitField<otg_fs_global_t, 12, 1, "USBRST", READWRITE>{}; // bit offset: 12, bit width: 1, USB reset mask
    constexpr auto ENUMDNEM = BitField<otg_fs_global_t, 13, 1, "ENUMDNEM", READWRITE>{}; // bit offset: 13, bit width: 1, Enumeration done mask
    constexpr auto ISOODRPM = BitField<otg_fs_global_t, 14, 1, "ISOODRPM", READWRITE>{}; // bit offset: 14, bit width: 1, Isochronous OUT packet dropped interrupt mask
    constexpr auto EOPFM = BitField<otg_fs_global_t, 15, 1, "EOPFM", READWRITE>{}; // bit offset: 15, bit width: 1, End of periodic frame interrupt mask
    constexpr auto EPMISM = BitField<otg_fs_global_t, 17, 1, "EPMISM", READWRITE>{}; // bit offset: 17, bit width: 1, Endpoint mismatch interrupt mask
    constexpr auto IEPINT = BitField<otg_fs_global_t, 18, 1, "IEPINT", READWRITE>{}; // bit offset: 18, bit width: 1, IN endpoints interrupt mask
    constexpr auto OEPINT = BitField<otg_fs_global_t, 19, 1, "OEPINT", READWRITE>{}; // bit offset: 19, bit width: 1, OUT endpoints interrupt mask
    constexpr auto IISOIXFRM = BitField<otg_fs_global_t, 20, 1, "IISOIXFRM", READWRITE>{}; // bit offset: 20, bit width: 1, Incomplete isochronous IN transfer mask
    constexpr auto IPXFRM_IISOOXFRM = BitField<otg_fs_global_t, 21, 1, "IPXFRM_IISOOXFRM", READWRITE>{}; // bit offset: 21, bit width: 1, Incomplete periodic transfer mask(Host mode)/Incomplete isochronous OUT transfer mask(Device mode)
    constexpr auto PRTIM = BitField<otg_fs_global_t, 24, 1, "PRTIM", READONLY>{}; // bit offset: 24, bit width: 1, Host port interrupt mask
    constexpr auto HCIM = BitField<otg_fs_global_t, 25, 1, "HCIM", READWRITE>{}; // bit offset: 25, bit width: 1, Host channels interrupt mask
    constexpr auto PTXFEM = BitField<otg_fs_global_t, 26, 1, "PTXFEM", READWRITE>{}; // bit offset: 26, bit width: 1, Periodic TxFIFO empty mask
    constexpr auto CIDSCHGM = BitField<otg_fs_global_t, 28, 1, "CIDSCHGM", READWRITE>{}; // bit offset: 28, bit width: 1, Connector ID status change mask
    constexpr auto DISCINT = BitField<otg_fs_global_t, 29, 1, "DISCINT", READWRITE>{}; // bit offset: 29, bit width: 1, Disconnect detected interrupt mask
    constexpr auto SRQIM = BitField<otg_fs_global_t, 30, 1, "SRQIM", READWRITE>{}; // bit offset: 30, bit width: 1, Session request/new session detected interrupt mask
    constexpr auto WUIM = BitField<otg_fs_global_t, 31, 1, "WUIM", READWRITE>{}; // bit offset: 31, bit width: 1, Resume/remote wakeup detected interrupt mask
    static Register<std::uint32_t, OTG_FS_GLOBAL_BASE_ADDRESS + 0x00000018u, 0, READWRITE, "FS_GINTMSK", decltype(MMISM), decltype(OTGINT), decltype(SOFM), decltype(RXFLVLM), decltype(NPTXFEM), decltype(GINAKEFFM), decltype(GONAKEFFM), decltype(ESUSPM), decltype(USBSUSPM), decltype(USBRST), decltype(ENUMDNEM), decltype(ISOODRPM), decltype(EOPFM), decltype(EPMISM), decltype(IEPINT), decltype(OEPINT), decltype(IISOIXFRM), decltype(IPXFRM_IISOOXFRM), decltype(PRTIM), decltype(HCIM), decltype(PTXFEM), decltype(CIDSCHGM), decltype(DISCINT), decltype(SRQIM), decltype(WUIM)> FS_GINTMSK; // OTG_FS interrupt mask register (OTG_FS_GINTMSK)

    constexpr auto EPNUM = BitField<otg_fs_global_t, 0, 4, "EPNUM">{}; // bit offset: 0, bit width: 4, Endpoint number
    constexpr auto BCNT = BitField<otg_fs_global_t, 4, 11, "BCNT">{}; // bit offset: 4, bit width: 11, Byte count
    constexpr auto DPID = BitField<otg_fs_global_t, 15, 2, "DPID">{}; // bit offset: 15, bit width: 2, Data PID
    constexpr auto PKTSTS = BitField<otg_fs_global_t, 17, 4, "PKTSTS">{}; // bit offset: 17, bit width: 4, Packet status
    constexpr auto FRMNUM = BitField<otg_fs_global_t, 21, 4, "FRMNUM">{}; // bit offset: 21, bit width: 4, Frame number
    static Register<std::uint32_t, OTG_FS_GLOBAL_BASE_ADDRESS + 0x0000001cu, 0, READONLY, "FS_GRXSTSR_DEVICE", decltype(EPNUM), decltype(BCNT), decltype(DPID), decltype(PKTSTS), decltype(FRMNUM)> FS_GRXSTSR_DEVICE; // OTG_FS Receive status debug read(Device mode)

    constexpr auto EPNUM = BitField<otg_fs_global_t, 0, 4, "EPNUM">{}; // bit offset: 0, bit width: 4, Endpoint number
    constexpr auto BCNT = BitField<otg_fs_global_t, 4, 11, "BCNT">{}; // bit offset: 4, bit width: 11, Byte count
    constexpr auto DPID = BitField<otg_fs_global_t, 15, 2, "DPID">{}; // bit offset: 15, bit width: 2, Data PID
    constexpr auto PKTSTS = BitField<otg_fs_global_t, 17, 4, "PKTSTS">{}; // bit offset: 17, bit width: 4, Packet status
    constexpr auto FRMNUM = BitField<otg_fs_global_t, 21, 4, "FRMNUM">{}; // bit offset: 21, bit width: 4, Frame number
    static Register<std::uint32_t, OTG_FS_GLOBAL_BASE_ADDRESS + 0x0000001cu, 0, READONLY, "FS_GRXSTSR_HOST", decltype(EPNUM), decltype(BCNT), decltype(DPID), decltype(PKTSTS), decltype(FRMNUM)> FS_GRXSTSR_HOST; // OTG_FS Receive status debug read(Host mode)

    constexpr auto RXFD = BitField<otg_fs_global_t, 0, 16, "RXFD">{}; // bit offset: 0, bit width: 16, RxFIFO depth
    static Register<std::uint32_t, OTG_FS_GLOBAL_BASE_ADDRESS + 0x00000024u, 512, READWRITE, "FS_GRXFSIZ", decltype(RXFD)> FS_GRXFSIZ; // OTG_FS Receive FIFO size register (OTG_FS_GRXFSIZ)

    constexpr auto TX0FSA = BitField<otg_fs_global_t, 0, 16, "TX0FSA">{}; // bit offset: 0, bit width: 16, Endpoint 0 transmit RAM start address
    constexpr auto TX0FD = BitField<otg_fs_global_t, 16, 16, "TX0FD">{}; // bit offset: 16, bit width: 16, Endpoint 0 TxFIFO depth
    static Register<std::uint32_t, OTG_FS_GLOBAL_BASE_ADDRESS + 0x00000028u, 512, READWRITE, "FS_GNPTXFSIZ_DEVICE", decltype(TX0FSA), decltype(TX0FD)> FS_GNPTXFSIZ_DEVICE; // OTG_FS non-periodic transmit FIFO size register (Device mode)

    constexpr auto NPTXFSA = BitField<otg_fs_global_t, 0, 16, "NPTXFSA">{}; // bit offset: 0, bit width: 16, Non-periodic transmit RAM start address
    constexpr auto NPTXFD = BitField<otg_fs_global_t, 16, 16, "NPTXFD">{}; // bit offset: 16, bit width: 16, Non-periodic TxFIFO depth
    static Register<std::uint32_t, OTG_FS_GLOBAL_BASE_ADDRESS + 0x00000028u, 512, READWRITE, "FS_GNPTXFSIZ_HOST", decltype(NPTXFSA), decltype(NPTXFD)> FS_GNPTXFSIZ_HOST; // OTG_FS non-periodic transmit FIFO size register (Host mode)

    constexpr auto NPTXFSAV = BitField<otg_fs_global_t, 0, 16, "NPTXFSAV">{}; // bit offset: 0, bit width: 16, Non-periodic TxFIFO space available
    constexpr auto NPTQXSAV = BitField<otg_fs_global_t, 16, 8, "NPTQXSAV">{}; // bit offset: 16, bit width: 8, Non-periodic transmit request queue space available
    constexpr auto NPTXQTOP = BitField<otg_fs_global_t, 24, 7, "NPTXQTOP">{}; // bit offset: 24, bit width: 7, Top of the non-periodic transmit request queue
    static Register<std::uint32_t, OTG_FS_GLOBAL_BASE_ADDRESS + 0x0000002cu, 524800, READONLY, "FS_GNPTXSTS", decltype(NPTXFSAV), decltype(NPTQXSAV), decltype(NPTXQTOP)> FS_GNPTXSTS; // OTG_FS non-periodic transmit FIFO/queue status register (OTG_FS_GNPTXSTS)

    constexpr auto PWRDWN = BitField<otg_fs_global_t, 16, 1, "PWRDWN">{}; // bit offset: 16, bit width: 1, Power down
    constexpr auto VBUSASEN = BitField<otg_fs_global_t, 18, 1, "VBUSASEN">{}; // bit offset: 18, bit width: 1, Enable the VBUS sensing device
    constexpr auto VBUSBSEN = BitField<otg_fs_global_t, 19, 1, "VBUSBSEN">{}; // bit offset: 19, bit width: 1, Enable the VBUS sensing device
    constexpr auto SOFOUTEN = BitField<otg_fs_global_t, 20, 1, "SOFOUTEN">{}; // bit offset: 20, bit width: 1, SOF output enable
    static Register<std::uint32_t, OTG_FS_GLOBAL_BASE_ADDRESS + 0x00000038u, 0, READWRITE, "FS_GCCFG", decltype(PWRDWN), decltype(VBUSASEN), decltype(VBUSBSEN), decltype(SOFOUTEN)> FS_GCCFG; // OTG_FS general core configuration register (OTG_FS_GCCFG)

    constexpr auto PRODUCT_ID = BitField<otg_fs_global_t, 0, 32, "PRODUCT_ID">{}; // bit offset: 0, bit width: 32, Product ID field
    static Register<std::uint32_t, OTG_FS_GLOBAL_BASE_ADDRESS + 0x0000003cu, 4096, READWRITE, "FS_CID", decltype(PRODUCT_ID)> FS_CID; // core ID register

    constexpr auto PTXSA = BitField<otg_fs_global_t, 0, 16, "PTXSA">{}; // bit offset: 0, bit width: 16, Host periodic TxFIFO start address
    constexpr auto PTXFSIZ = BitField<otg_fs_global_t, 16, 16, "PTXFSIZ">{}; // bit offset: 16, bit width: 16, Host periodic TxFIFO depth
    static Register<std::uint32_t, OTG_FS_GLOBAL_BASE_ADDRESS + 0x00000100u, 33555968, READWRITE, "FS_HPTXFSIZ", decltype(PTXSA), decltype(PTXFSIZ)> FS_HPTXFSIZ; // OTG_FS Host periodic transmit FIFO size register (OTG_FS_HPTXFSIZ)

    constexpr auto INEPTXSA = BitField<otg_fs_global_t, 0, 16, "INEPTXSA">{}; // bit offset: 0, bit width: 16, IN endpoint FIFO2 transmit RAM start address
    constexpr auto INEPTXFD = BitField<otg_fs_global_t, 16, 16, "INEPTXFD">{}; // bit offset: 16, bit width: 16, IN endpoint TxFIFO depth
    static Register<std::uint32_t, OTG_FS_GLOBAL_BASE_ADDRESS + 0x00000104u, 33555456, READWRITE, "FS_DIEPTXF1", decltype(INEPTXSA), decltype(INEPTXFD)> FS_DIEPTXF1; // OTG_FS device IN endpoint transmit FIFO size register (OTG_FS_DIEPTXF2)

    constexpr auto INEPTXSA = BitField<otg_fs_global_t, 0, 16, "INEPTXSA">{}; // bit offset: 0, bit width: 16, IN endpoint FIFO3 transmit RAM start address
    constexpr auto INEPTXFD = BitField<otg_fs_global_t, 16, 16, "INEPTXFD">{}; // bit offset: 16, bit width: 16, IN endpoint TxFIFO depth
    static Register<std::uint32_t, OTG_FS_GLOBAL_BASE_ADDRESS + 0x00000108u, 33555456, READWRITE, "FS_DIEPTXF2", decltype(INEPTXSA), decltype(INEPTXFD)> FS_DIEPTXF2; // OTG_FS device IN endpoint transmit FIFO size register (OTG_FS_DIEPTXF3)

    constexpr auto INEPTXSA = BitField<otg_fs_global_t, 0, 16, "INEPTXSA">{}; // bit offset: 0, bit width: 16, IN endpoint FIFO4 transmit RAM start address
    constexpr auto INEPTXFD = BitField<otg_fs_global_t, 16, 16, "INEPTXFD">{}; // bit offset: 16, bit width: 16, IN endpoint TxFIFO depth
    static Register<std::uint32_t, OTG_FS_GLOBAL_BASE_ADDRESS + 0x0000010cu, 33555456, READWRITE, "FS_DIEPTXF3", decltype(INEPTXSA), decltype(INEPTXFD)> FS_DIEPTXF3; // OTG_FS device IN endpoint transmit FIFO size register (OTG_FS_DIEPTXF4)

} // namespace OTG_FS_GLOBAL