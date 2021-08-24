#include <Register.hpp>




namespace OTG_HS_GLOBAL
{
    struct otg_hs_global_t{};

    constexpr std::uint32_t OTG_HS_GLOBAL_BASE_ADDRESS = 0x40040000u;

    constexpr auto SRQSCS = BitField<otg_hs_global_t, 0, 1, READONLY>{}; // bit offset: 0, bit width: 1, Session request success
    constexpr auto SRQ = BitField<otg_hs_global_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, Session request
    constexpr auto HNGSCS = BitField<otg_hs_global_t, 8, 1, READONLY>{}; // bit offset: 8, bit width: 1, Host negotiation success
    constexpr auto HNPRQ = BitField<otg_hs_global_t, 9, 1, READWRITE>{}; // bit offset: 9, bit width: 1, HNP request
    constexpr auto HSHNPEN = BitField<otg_hs_global_t, 10, 1, READWRITE>{}; // bit offset: 10, bit width: 1, Host set HNP enable
    constexpr auto DHNPEN = BitField<otg_hs_global_t, 11, 1, READWRITE>{}; // bit offset: 11, bit width: 1, Device HNP enabled
    constexpr auto CIDSTS = BitField<otg_hs_global_t, 16, 1, READONLY>{}; // bit offset: 16, bit width: 1, Connector ID status
    constexpr auto DBCT = BitField<otg_hs_global_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, Long/short debounce time
    constexpr auto ASVLD = BitField<otg_hs_global_t, 18, 1, READONLY>{}; // bit offset: 18, bit width: 1, A-session valid
    constexpr auto BSVLD = BitField<otg_hs_global_t, 19, 1, READONLY>{}; // bit offset: 19, bit width: 1, B-session valid
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x00000000u, 2048, READWRITE, decltype(SRQSCS), decltype(SRQ), decltype(HNGSCS), decltype(HNPRQ), decltype(HSHNPEN), decltype(DHNPEN), decltype(CIDSTS), decltype(DBCT), decltype(ASVLD), decltype(BSVLD)> OTG_HS_GOTGCTL; // OTG_HS control and status register

    constexpr auto SEDET = BitField<otg_hs_global_t, 2, 1>{}; // bit offset: 2, bit width: 1, Session end detected
    constexpr auto SRSSCHG = BitField<otg_hs_global_t, 8, 1>{}; // bit offset: 8, bit width: 1, Session request success status change
    constexpr auto HNSSCHG = BitField<otg_hs_global_t, 9, 1>{}; // bit offset: 9, bit width: 1, Host negotiation success status change
    constexpr auto HNGDET = BitField<otg_hs_global_t, 17, 1>{}; // bit offset: 17, bit width: 1, Host negotiation detected
    constexpr auto ADTOCHG = BitField<otg_hs_global_t, 18, 1>{}; // bit offset: 18, bit width: 1, A-device timeout change
    constexpr auto DBCDNE = BitField<otg_hs_global_t, 19, 1>{}; // bit offset: 19, bit width: 1, Debounce done
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x00000004u, 0, READWRITE, decltype(SEDET), decltype(SRSSCHG), decltype(HNSSCHG), decltype(HNGDET), decltype(ADTOCHG), decltype(DBCDNE)> OTG_HS_GOTGINT; // OTG_HS interrupt register

    constexpr auto GINT = BitField<otg_hs_global_t, 0, 1>{}; // bit offset: 0, bit width: 1, Global interrupt mask
    constexpr auto HBSTLEN = BitField<otg_hs_global_t, 1, 4>{}; // bit offset: 1, bit width: 4, Burst length/type
    constexpr auto DMAEN = BitField<otg_hs_global_t, 5, 1>{}; // bit offset: 5, bit width: 1, DMA enable
    constexpr auto TXFELVL = BitField<otg_hs_global_t, 7, 1>{}; // bit offset: 7, bit width: 1, TxFIFO empty level
    constexpr auto PTXFELVL = BitField<otg_hs_global_t, 8, 1>{}; // bit offset: 8, bit width: 1, Periodic TxFIFO empty level
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x00000008u, 0, READWRITE, decltype(GINT), decltype(HBSTLEN), decltype(DMAEN), decltype(TXFELVL), decltype(PTXFELVL)> OTG_HS_GAHBCFG; // OTG_HS AHB configuration register

    constexpr auto TOCAL = BitField<otg_hs_global_t, 0, 3, READWRITE>{}; // bit offset: 0, bit width: 3, FS timeout calibration
    constexpr auto PHYSEL = BitField<otg_hs_global_t, 6, 1, WRITEONLY>{}; // bit offset: 6, bit width: 1, USB 2.0 high-speed ULPI PHY or USB 1.1 full-speed serial transceiver select
    constexpr auto SRPCAP = BitField<otg_hs_global_t, 8, 1, READWRITE>{}; // bit offset: 8, bit width: 1, SRP-capable
    constexpr auto HNPCAP = BitField<otg_hs_global_t, 9, 1, READWRITE>{}; // bit offset: 9, bit width: 1, HNP-capable
    constexpr auto TRDT = BitField<otg_hs_global_t, 10, 4, READWRITE>{}; // bit offset: 10, bit width: 4, USB turnaround time
    constexpr auto PHYLPCS = BitField<otg_hs_global_t, 15, 1, READWRITE>{}; // bit offset: 15, bit width: 1, PHY Low-power clock select
    constexpr auto ULPIFSLS = BitField<otg_hs_global_t, 17, 1, READWRITE>{}; // bit offset: 17, bit width: 1, ULPI FS/LS select
    constexpr auto ULPIAR = BitField<otg_hs_global_t, 18, 1, READWRITE>{}; // bit offset: 18, bit width: 1, ULPI Auto-resume
    constexpr auto ULPICSM = BitField<otg_hs_global_t, 19, 1, READWRITE>{}; // bit offset: 19, bit width: 1, ULPI Clock SuspendM
    constexpr auto ULPIEVBUSD = BitField<otg_hs_global_t, 20, 1, READWRITE>{}; // bit offset: 20, bit width: 1, ULPI External VBUS Drive
    constexpr auto ULPIEVBUSI = BitField<otg_hs_global_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, ULPI external VBUS indicator
    constexpr auto TSDPS = BitField<otg_hs_global_t, 22, 1, READWRITE>{}; // bit offset: 22, bit width: 1, TermSel DLine pulsing selection
    constexpr auto PCCI = BitField<otg_hs_global_t, 23, 1, READWRITE>{}; // bit offset: 23, bit width: 1, Indicator complement
    constexpr auto PTCI = BitField<otg_hs_global_t, 24, 1, READWRITE>{}; // bit offset: 24, bit width: 1, Indicator pass through
    constexpr auto ULPIIPD = BitField<otg_hs_global_t, 25, 1, READWRITE>{}; // bit offset: 25, bit width: 1, ULPI interface protect disable
    constexpr auto FHMOD = BitField<otg_hs_global_t, 29, 1, READWRITE>{}; // bit offset: 29, bit width: 1, Forced host mode
    constexpr auto FDMOD = BitField<otg_hs_global_t, 30, 1, READWRITE>{}; // bit offset: 30, bit width: 1, Forced peripheral mode
    constexpr auto CTXPKT = BitField<otg_hs_global_t, 31, 1, READWRITE>{}; // bit offset: 31, bit width: 1, Corrupt Tx packet
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x0000000cu, 2560, READWRITE, decltype(TOCAL), decltype(PHYSEL), decltype(SRPCAP), decltype(HNPCAP), decltype(TRDT), decltype(PHYLPCS), decltype(ULPIFSLS), decltype(ULPIAR), decltype(ULPICSM), decltype(ULPIEVBUSD), decltype(ULPIEVBUSI), decltype(TSDPS), decltype(PCCI), decltype(PTCI), decltype(ULPIIPD), decltype(FHMOD), decltype(FDMOD), decltype(CTXPKT)> OTG_HS_GUSBCFG; // OTG_HS USB configuration register

    constexpr auto CSRST = BitField<otg_hs_global_t, 0, 1, READWRITE>{}; // bit offset: 0, bit width: 1, Core soft reset
    constexpr auto HSRST = BitField<otg_hs_global_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, HCLK soft reset
    constexpr auto FCRST = BitField<otg_hs_global_t, 2, 1, READWRITE>{}; // bit offset: 2, bit width: 1, Host frame counter reset
    constexpr auto RXFFLSH = BitField<otg_hs_global_t, 4, 1, READWRITE>{}; // bit offset: 4, bit width: 1, RxFIFO flush
    constexpr auto TXFFLSH = BitField<otg_hs_global_t, 5, 1, READWRITE>{}; // bit offset: 5, bit width: 1, TxFIFO flush
    constexpr auto TXFNUM = BitField<otg_hs_global_t, 6, 5, READWRITE>{}; // bit offset: 6, bit width: 5, TxFIFO number
    constexpr auto DMAREQ = BitField<otg_hs_global_t, 30, 1, READONLY>{}; // bit offset: 30, bit width: 1, DMA request signal
    constexpr auto AHBIDL = BitField<otg_hs_global_t, 31, 1, READONLY>{}; // bit offset: 31, bit width: 1, AHB master idle
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x00000010u, 536870912, READWRITE, decltype(CSRST), decltype(HSRST), decltype(FCRST), decltype(RXFFLSH), decltype(TXFFLSH), decltype(TXFNUM), decltype(DMAREQ), decltype(AHBIDL)> OTG_HS_GRSTCTL; // OTG_HS reset register

    constexpr auto CMOD = BitField<otg_hs_global_t, 0, 1, READONLY>{}; // bit offset: 0, bit width: 1, Current mode of operation
    constexpr auto MMIS = BitField<otg_hs_global_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, Mode mismatch interrupt
    constexpr auto OTGINT = BitField<otg_hs_global_t, 2, 1, READONLY>{}; // bit offset: 2, bit width: 1, OTG interrupt
    constexpr auto SOF = BitField<otg_hs_global_t, 3, 1, READWRITE>{}; // bit offset: 3, bit width: 1, Start of frame
    constexpr auto RXFLVL = BitField<otg_hs_global_t, 4, 1, READONLY>{}; // bit offset: 4, bit width: 1, RxFIFO nonempty
    constexpr auto NPTXFE = BitField<otg_hs_global_t, 5, 1, READONLY>{}; // bit offset: 5, bit width: 1, Nonperiodic TxFIFO empty
    constexpr auto GINAKEFF = BitField<otg_hs_global_t, 6, 1, READONLY>{}; // bit offset: 6, bit width: 1, Global IN nonperiodic NAK effective
    constexpr auto BOUTNAKEFF = BitField<otg_hs_global_t, 7, 1, READONLY>{}; // bit offset: 7, bit width: 1, Global OUT NAK effective
    constexpr auto ESUSP = BitField<otg_hs_global_t, 10, 1, READWRITE>{}; // bit offset: 10, bit width: 1, Early suspend
    constexpr auto USBSUSP = BitField<otg_hs_global_t, 11, 1, READWRITE>{}; // bit offset: 11, bit width: 1, USB suspend
    constexpr auto USBRST = BitField<otg_hs_global_t, 12, 1, READWRITE>{}; // bit offset: 12, bit width: 1, USB reset
    constexpr auto ENUMDNE = BitField<otg_hs_global_t, 13, 1, READWRITE>{}; // bit offset: 13, bit width: 1, Enumeration done
    constexpr auto ISOODRP = BitField<otg_hs_global_t, 14, 1, READWRITE>{}; // bit offset: 14, bit width: 1, Isochronous OUT packet dropped interrupt
    constexpr auto EOPF = BitField<otg_hs_global_t, 15, 1, READWRITE>{}; // bit offset: 15, bit width: 1, End of periodic frame interrupt
    constexpr auto IEPINT = BitField<otg_hs_global_t, 18, 1, READONLY>{}; // bit offset: 18, bit width: 1, IN endpoint interrupt
    constexpr auto OEPINT = BitField<otg_hs_global_t, 19, 1, READONLY>{}; // bit offset: 19, bit width: 1, OUT endpoint interrupt
    constexpr auto IISOIXFR = BitField<otg_hs_global_t, 20, 1, READWRITE>{}; // bit offset: 20, bit width: 1, Incomplete isochronous IN transfer
    constexpr auto PXFR_INCOMPISOOUT = BitField<otg_hs_global_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, Incomplete periodic transfer
    constexpr auto DATAFSUSP = BitField<otg_hs_global_t, 22, 1, READWRITE>{}; // bit offset: 22, bit width: 1, Data fetch suspended
    constexpr auto HPRTINT = BitField<otg_hs_global_t, 24, 1, READONLY>{}; // bit offset: 24, bit width: 1, Host port interrupt
    constexpr auto HCINT = BitField<otg_hs_global_t, 25, 1, READONLY>{}; // bit offset: 25, bit width: 1, Host channels interrupt
    constexpr auto PTXFE = BitField<otg_hs_global_t, 26, 1, READONLY>{}; // bit offset: 26, bit width: 1, Periodic TxFIFO empty
    constexpr auto CIDSCHG = BitField<otg_hs_global_t, 28, 1, READWRITE>{}; // bit offset: 28, bit width: 1, Connector ID status change
    constexpr auto DISCINT = BitField<otg_hs_global_t, 29, 1, READWRITE>{}; // bit offset: 29, bit width: 1, Disconnect detected interrupt
    constexpr auto SRQINT = BitField<otg_hs_global_t, 30, 1, READWRITE>{}; // bit offset: 30, bit width: 1, Session request/new session detected interrupt
    constexpr auto WKUINT = BitField<otg_hs_global_t, 31, 1, READWRITE>{}; // bit offset: 31, bit width: 1, Resume/remote wakeup detected interrupt
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x00000014u, 67108896, READWRITE, decltype(CMOD), decltype(MMIS), decltype(OTGINT), decltype(SOF), decltype(RXFLVL), decltype(NPTXFE), decltype(GINAKEFF), decltype(BOUTNAKEFF), decltype(ESUSP), decltype(USBSUSP), decltype(USBRST), decltype(ENUMDNE), decltype(ISOODRP), decltype(EOPF), decltype(IEPINT), decltype(OEPINT), decltype(IISOIXFR), decltype(PXFR_INCOMPISOOUT), decltype(DATAFSUSP), decltype(HPRTINT), decltype(HCINT), decltype(PTXFE), decltype(CIDSCHG), decltype(DISCINT), decltype(SRQINT), decltype(WKUINT)> OTG_HS_GINTSTS; // OTG_HS core interrupt register

    constexpr auto MMISM = BitField<otg_hs_global_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, Mode mismatch interrupt mask
    constexpr auto OTGINT = BitField<otg_hs_global_t, 2, 1, READWRITE>{}; // bit offset: 2, bit width: 1, OTG interrupt mask
    constexpr auto SOFM = BitField<otg_hs_global_t, 3, 1, READWRITE>{}; // bit offset: 3, bit width: 1, Start of frame mask
    constexpr auto RXFLVLM = BitField<otg_hs_global_t, 4, 1, READWRITE>{}; // bit offset: 4, bit width: 1, Receive FIFO nonempty mask
    constexpr auto NPTXFEM = BitField<otg_hs_global_t, 5, 1, READWRITE>{}; // bit offset: 5, bit width: 1, Nonperiodic TxFIFO empty mask
    constexpr auto GINAKEFFM = BitField<otg_hs_global_t, 6, 1, READWRITE>{}; // bit offset: 6, bit width: 1, Global nonperiodic IN NAK effective mask
    constexpr auto GONAKEFFM = BitField<otg_hs_global_t, 7, 1, READWRITE>{}; // bit offset: 7, bit width: 1, Global OUT NAK effective mask
    constexpr auto ESUSPM = BitField<otg_hs_global_t, 10, 1, READWRITE>{}; // bit offset: 10, bit width: 1, Early suspend mask
    constexpr auto USBSUSPM = BitField<otg_hs_global_t, 11, 1, READWRITE>{}; // bit offset: 11, bit width: 1, USB suspend mask
    constexpr auto USBRST = BitField<otg_hs_global_t, 12, 1, READWRITE>{}; // bit offset: 12, bit width: 1, USB reset mask
    constexpr auto ENUMDNEM = BitField<otg_hs_global_t, 13, 1, READWRITE>{}; // bit offset: 13, bit width: 1, Enumeration done mask
    constexpr auto ISOODRPM = BitField<otg_hs_global_t, 14, 1, READWRITE>{}; // bit offset: 14, bit width: 1, Isochronous OUT packet dropped interrupt mask
    constexpr auto EOPFM = BitField<otg_hs_global_t, 15, 1, READWRITE>{}; // bit offset: 15, bit width: 1, End of periodic frame interrupt mask
    constexpr auto EPMISM = BitField<otg_hs_global_t, 17, 1, READWRITE>{}; // bit offset: 17, bit width: 1, Endpoint mismatch interrupt mask
    constexpr auto IEPINT = BitField<otg_hs_global_t, 18, 1, READWRITE>{}; // bit offset: 18, bit width: 1, IN endpoints interrupt mask
    constexpr auto OEPINT = BitField<otg_hs_global_t, 19, 1, READWRITE>{}; // bit offset: 19, bit width: 1, OUT endpoints interrupt mask
    constexpr auto IISOIXFRM = BitField<otg_hs_global_t, 20, 1, READWRITE>{}; // bit offset: 20, bit width: 1, Incomplete isochronous IN transfer mask
    constexpr auto PXFRM_IISOOXFRM = BitField<otg_hs_global_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, Incomplete periodic transfer mask
    constexpr auto FSUSPM = BitField<otg_hs_global_t, 22, 1, READWRITE>{}; // bit offset: 22, bit width: 1, Data fetch suspended mask
    constexpr auto PRTIM = BitField<otg_hs_global_t, 24, 1, READONLY>{}; // bit offset: 24, bit width: 1, Host port interrupt mask
    constexpr auto HCIM = BitField<otg_hs_global_t, 25, 1, READWRITE>{}; // bit offset: 25, bit width: 1, Host channels interrupt mask
    constexpr auto PTXFEM = BitField<otg_hs_global_t, 26, 1, READWRITE>{}; // bit offset: 26, bit width: 1, Periodic TxFIFO empty mask
    constexpr auto CIDSCHGM = BitField<otg_hs_global_t, 28, 1, READWRITE>{}; // bit offset: 28, bit width: 1, Connector ID status change mask
    constexpr auto DISCINT = BitField<otg_hs_global_t, 29, 1, READWRITE>{}; // bit offset: 29, bit width: 1, Disconnect detected interrupt mask
    constexpr auto SRQIM = BitField<otg_hs_global_t, 30, 1, READWRITE>{}; // bit offset: 30, bit width: 1, Session request/new session detected interrupt mask
    constexpr auto WUIM = BitField<otg_hs_global_t, 31, 1, READWRITE>{}; // bit offset: 31, bit width: 1, Resume/remote wakeup detected interrupt mask
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x00000018u, 0, READWRITE, decltype(MMISM), decltype(OTGINT), decltype(SOFM), decltype(RXFLVLM), decltype(NPTXFEM), decltype(GINAKEFFM), decltype(GONAKEFFM), decltype(ESUSPM), decltype(USBSUSPM), decltype(USBRST), decltype(ENUMDNEM), decltype(ISOODRPM), decltype(EOPFM), decltype(EPMISM), decltype(IEPINT), decltype(OEPINT), decltype(IISOIXFRM), decltype(PXFRM_IISOOXFRM), decltype(FSUSPM), decltype(PRTIM), decltype(HCIM), decltype(PTXFEM), decltype(CIDSCHGM), decltype(DISCINT), decltype(SRQIM), decltype(WUIM)> OTG_HS_GINTMSK; // OTG_HS interrupt mask register

    constexpr auto CHNUM = BitField<otg_hs_global_t, 0, 4>{}; // bit offset: 0, bit width: 4, Channel number
    constexpr auto BCNT = BitField<otg_hs_global_t, 4, 11>{}; // bit offset: 4, bit width: 11, Byte count
    constexpr auto DPID = BitField<otg_hs_global_t, 15, 2>{}; // bit offset: 15, bit width: 2, Data PID
    constexpr auto PKTSTS = BitField<otg_hs_global_t, 17, 4>{}; // bit offset: 17, bit width: 4, Packet status
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x0000001cu, 0, READONLY, decltype(CHNUM), decltype(BCNT), decltype(DPID), decltype(PKTSTS)> OTG_HS_GRXSTSR_HOST; // OTG_HS Receive status debug read register (host mode)

    constexpr auto CHNUM = BitField<otg_hs_global_t, 0, 4>{}; // bit offset: 0, bit width: 4, Channel number
    constexpr auto BCNT = BitField<otg_hs_global_t, 4, 11>{}; // bit offset: 4, bit width: 11, Byte count
    constexpr auto DPID = BitField<otg_hs_global_t, 15, 2>{}; // bit offset: 15, bit width: 2, Data PID
    constexpr auto PKTSTS = BitField<otg_hs_global_t, 17, 4>{}; // bit offset: 17, bit width: 4, Packet status
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x00000020u, 0, READONLY, decltype(CHNUM), decltype(BCNT), decltype(DPID), decltype(PKTSTS)> OTG_HS_GRXSTSP_HOST; // OTG_HS status read and pop register (host mode)

    constexpr auto RXFD = BitField<otg_hs_global_t, 0, 16>{}; // bit offset: 0, bit width: 16, RxFIFO depth
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x00000024u, 512, READWRITE, decltype(RXFD)> OTG_HS_GRXFSIZ; // OTG_HS Receive FIFO size register

    constexpr auto NPTXFSA = BitField<otg_hs_global_t, 0, 16>{}; // bit offset: 0, bit width: 16, Nonperiodic transmit RAM start address
    constexpr auto NPTXFD = BitField<otg_hs_global_t, 16, 16>{}; // bit offset: 16, bit width: 16, Nonperiodic TxFIFO depth
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x00000028u, 512, READWRITE, decltype(NPTXFSA), decltype(NPTXFD)> OTG_HS_GNPTXFSIZ_HOST; // OTG_HS nonperiodic transmit FIFO size register (host mode)

    constexpr auto TX0FSA = BitField<otg_hs_global_t, 0, 16>{}; // bit offset: 0, bit width: 16, Endpoint 0 transmit RAM start address
    constexpr auto TX0FD = BitField<otg_hs_global_t, 16, 16>{}; // bit offset: 16, bit width: 16, Endpoint 0 TxFIFO depth
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x00000028u, 512, READWRITE, decltype(TX0FSA), decltype(TX0FD)> OTG_HS_TX0FSIZ_PERIPHERAL; // Endpoint 0 transmit FIFO size (peripheral mode)

    constexpr auto NPTXFSAV = BitField<otg_hs_global_t, 0, 16>{}; // bit offset: 0, bit width: 16, Nonperiodic TxFIFO space available
    constexpr auto NPTQXSAV = BitField<otg_hs_global_t, 16, 8>{}; // bit offset: 16, bit width: 8, Nonperiodic transmit request queue space available
    constexpr auto NPTXQTOP = BitField<otg_hs_global_t, 24, 7>{}; // bit offset: 24, bit width: 7, Top of the nonperiodic transmit request queue
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x0000002cu, 524800, READONLY, decltype(NPTXFSAV), decltype(NPTQXSAV), decltype(NPTXQTOP)> OTG_HS_GNPTXSTS; // OTG_HS nonperiodic transmit FIFO/queue status register

    constexpr auto PWRDWN = BitField<otg_hs_global_t, 16, 1>{}; // bit offset: 16, bit width: 1, Power down
    constexpr auto I2CPADEN = BitField<otg_hs_global_t, 17, 1>{}; // bit offset: 17, bit width: 1, Enable I2C bus connection for the external I2C PHY interface
    constexpr auto VBUSASEN = BitField<otg_hs_global_t, 18, 1>{}; // bit offset: 18, bit width: 1, Enable the VBUS sensing device
    constexpr auto VBUSBSEN = BitField<otg_hs_global_t, 19, 1>{}; // bit offset: 19, bit width: 1, Enable the VBUS sensing device
    constexpr auto SOFOUTEN = BitField<otg_hs_global_t, 20, 1>{}; // bit offset: 20, bit width: 1, SOF output enable
    constexpr auto NOVBUSSENS = BitField<otg_hs_global_t, 21, 1>{}; // bit offset: 21, bit width: 1, VBUS sensing disable option
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x00000038u, 0, READWRITE, decltype(PWRDWN), decltype(I2CPADEN), decltype(VBUSASEN), decltype(VBUSBSEN), decltype(SOFOUTEN), decltype(NOVBUSSENS)> OTG_HS_GCCFG; // OTG_HS general core configuration register

    constexpr auto PRODUCT_ID = BitField<otg_hs_global_t, 0, 32>{}; // bit offset: 0, bit width: 32, Product ID field
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x0000003cu, 4608, READWRITE, decltype(PRODUCT_ID)> OTG_HS_CID; // OTG_HS core ID register

    constexpr auto PTXSA = BitField<otg_hs_global_t, 0, 16>{}; // bit offset: 0, bit width: 16, Host periodic TxFIFO start address
    constexpr auto PTXFD = BitField<otg_hs_global_t, 16, 16>{}; // bit offset: 16, bit width: 16, Host periodic TxFIFO depth
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x00000100u, 33555968, READWRITE, decltype(PTXSA), decltype(PTXFD)> OTG_HS_HPTXFSIZ; // OTG_HS Host periodic transmit FIFO size register

    constexpr auto INEPTXSA = BitField<otg_hs_global_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN endpoint FIFOx transmit RAM start address
    constexpr auto INEPTXFD = BitField<otg_hs_global_t, 16, 16>{}; // bit offset: 16, bit width: 16, IN endpoint TxFIFO depth
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x00000104u, 33555456, READWRITE, decltype(INEPTXSA), decltype(INEPTXFD)> OTG_HS_DIEPTXF1; // OTG_HS device IN endpoint transmit FIFO size register

    constexpr auto INEPTXSA = BitField<otg_hs_global_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN endpoint FIFOx transmit RAM start address
    constexpr auto INEPTXFD = BitField<otg_hs_global_t, 16, 16>{}; // bit offset: 16, bit width: 16, IN endpoint TxFIFO depth
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x00000108u, 33555456, READWRITE, decltype(INEPTXSA), decltype(INEPTXFD)> OTG_HS_DIEPTXF2; // OTG_HS device IN endpoint transmit FIFO size register

    constexpr auto INEPTXSA = BitField<otg_hs_global_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN endpoint FIFOx transmit RAM start address
    constexpr auto INEPTXFD = BitField<otg_hs_global_t, 16, 16>{}; // bit offset: 16, bit width: 16, IN endpoint TxFIFO depth
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x0000011cu, 33555456, READWRITE, decltype(INEPTXSA), decltype(INEPTXFD)> OTG_HS_DIEPTXF3; // OTG_HS device IN endpoint transmit FIFO size register

    constexpr auto INEPTXSA = BitField<otg_hs_global_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN endpoint FIFOx transmit RAM start address
    constexpr auto INEPTXFD = BitField<otg_hs_global_t, 16, 16>{}; // bit offset: 16, bit width: 16, IN endpoint TxFIFO depth
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x00000120u, 33555456, READWRITE, decltype(INEPTXSA), decltype(INEPTXFD)> OTG_HS_DIEPTXF4; // OTG_HS device IN endpoint transmit FIFO size register

    constexpr auto INEPTXSA = BitField<otg_hs_global_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN endpoint FIFOx transmit RAM start address
    constexpr auto INEPTXFD = BitField<otg_hs_global_t, 16, 16>{}; // bit offset: 16, bit width: 16, IN endpoint TxFIFO depth
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x00000124u, 33555456, READWRITE, decltype(INEPTXSA), decltype(INEPTXFD)> OTG_HS_DIEPTXF5; // OTG_HS device IN endpoint transmit FIFO size register

    constexpr auto INEPTXSA = BitField<otg_hs_global_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN endpoint FIFOx transmit RAM start address
    constexpr auto INEPTXFD = BitField<otg_hs_global_t, 16, 16>{}; // bit offset: 16, bit width: 16, IN endpoint TxFIFO depth
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x00000128u, 33555456, READWRITE, decltype(INEPTXSA), decltype(INEPTXFD)> OTG_HS_DIEPTXF6; // OTG_HS device IN endpoint transmit FIFO size register

    constexpr auto INEPTXSA = BitField<otg_hs_global_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN endpoint FIFOx transmit RAM start address
    constexpr auto INEPTXFD = BitField<otg_hs_global_t, 16, 16>{}; // bit offset: 16, bit width: 16, IN endpoint TxFIFO depth
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x0000012cu, 33555456, READWRITE, decltype(INEPTXSA), decltype(INEPTXFD)> OTG_HS_DIEPTXF7; // OTG_HS device IN endpoint transmit FIFO size register

    constexpr auto EPNUM = BitField<otg_hs_global_t, 0, 4>{}; // bit offset: 0, bit width: 4, Endpoint number
    constexpr auto BCNT = BitField<otg_hs_global_t, 4, 11>{}; // bit offset: 4, bit width: 11, Byte count
    constexpr auto DPID = BitField<otg_hs_global_t, 15, 2>{}; // bit offset: 15, bit width: 2, Data PID
    constexpr auto PKTSTS = BitField<otg_hs_global_t, 17, 4>{}; // bit offset: 17, bit width: 4, Packet status
    constexpr auto FRMNUM = BitField<otg_hs_global_t, 21, 4>{}; // bit offset: 21, bit width: 4, Frame number
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x0000001cu, 0, READONLY, decltype(EPNUM), decltype(BCNT), decltype(DPID), decltype(PKTSTS), decltype(FRMNUM)> OTG_HS_GRXSTSR_PERIPHERAL; // OTG_HS Receive status debug read register (peripheral mode mode)

    constexpr auto EPNUM = BitField<otg_hs_global_t, 0, 4>{}; // bit offset: 0, bit width: 4, Endpoint number
    constexpr auto BCNT = BitField<otg_hs_global_t, 4, 11>{}; // bit offset: 4, bit width: 11, Byte count
    constexpr auto DPID = BitField<otg_hs_global_t, 15, 2>{}; // bit offset: 15, bit width: 2, Data PID
    constexpr auto PKTSTS = BitField<otg_hs_global_t, 17, 4>{}; // bit offset: 17, bit width: 4, Packet status
    constexpr auto FRMNUM = BitField<otg_hs_global_t, 21, 4>{}; // bit offset: 21, bit width: 4, Frame number
    static Register<std::uint32_t, OTG_HS_GLOBAL_BASE_ADDRESS + 0x00000020u, 0, READONLY, decltype(EPNUM), decltype(BCNT), decltype(DPID), decltype(PKTSTS), decltype(FRMNUM)> OTG_HS_GRXSTSP_PERIPHERAL; // OTG_HS status read and pop register (peripheral mode)

} // namespace OTG_HS_GLOBAL