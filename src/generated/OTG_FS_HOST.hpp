#include <Register.hpp>




namespace OTG_FS_HOST
{
    struct otg_fs_host_t{};

    constexpr std::uint32_t OTG_FS_HOST_BASE_ADDRESS = 0x50000400u;

    constexpr auto FSLSPCS = BitField<otg_fs_host_t, 0, 2, READWRITE>{}; // bit offset: 0, bit width: 2, FS/LS PHY clock select
    constexpr auto FSLSS = BitField<otg_fs_host_t, 2, 1, READONLY>{}; // bit offset: 2, bit width: 1, FS- and LS-only support
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000000u, 0, READWRITE, decltype(FSLSPCS), decltype(FSLSS)> FS_HCFG; // OTG_FS host configuration register (OTG_FS_HCFG)

    constexpr auto FRIVL = BitField<otg_fs_host_t, 0, 16>{}; // bit offset: 0, bit width: 16, Frame interval
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000004u, 60000, READWRITE, decltype(FRIVL)> HFIR; // OTG_FS Host frame interval register

    constexpr auto FRNUM = BitField<otg_fs_host_t, 0, 16>{}; // bit offset: 0, bit width: 16, Frame number
    constexpr auto FTREM = BitField<otg_fs_host_t, 16, 16>{}; // bit offset: 16, bit width: 16, Frame time remaining
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000008u, 16383, READONLY, decltype(FRNUM), decltype(FTREM)> FS_HFNUM; // OTG_FS host frame number/frame time remaining register (OTG_FS_HFNUM)

    constexpr auto PTXFSAVL = BitField<otg_fs_host_t, 0, 16, READWRITE>{}; // bit offset: 0, bit width: 16, Periodic transmit data FIFO space available
    constexpr auto PTXQSAV = BitField<otg_fs_host_t, 16, 8, READONLY>{}; // bit offset: 16, bit width: 8, Periodic transmit request queue space available
    constexpr auto PTXQTOP = BitField<otg_fs_host_t, 24, 8, READONLY>{}; // bit offset: 24, bit width: 8, Top of the periodic transmit request queue
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000010u, 524544, READWRITE, decltype(PTXFSAVL), decltype(PTXQSAV), decltype(PTXQTOP)> FS_HPTXSTS; // OTG_FS_Host periodic transmit FIFO/queue status register (OTG_FS_HPTXSTS)

    constexpr auto HAINT_ = BitField<otg_fs_host_t, 0, 16>{}; // bit offset: 0, bit width: 16, Channel interrupts
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000014u, 0, READONLY, decltype(HAINT_)> HAINT; // OTG_FS Host all channels interrupt register

    constexpr auto HAINTM = BitField<otg_fs_host_t, 0, 16>{}; // bit offset: 0, bit width: 16, Channel interrupt mask
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000018u, 0, READWRITE, decltype(HAINTM)> HAINTMSK; // OTG_FS host all channels interrupt mask register

    constexpr auto PCSTS = BitField<otg_fs_host_t, 0, 1, READONLY>{}; // bit offset: 0, bit width: 1, Port connect status
    constexpr auto PCDET = BitField<otg_fs_host_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, Port connect detected
    constexpr auto PENA = BitField<otg_fs_host_t, 2, 1, READWRITE>{}; // bit offset: 2, bit width: 1, Port enable
    constexpr auto PENCHNG = BitField<otg_fs_host_t, 3, 1, READWRITE>{}; // bit offset: 3, bit width: 1, Port enable/disable change
    constexpr auto POCA = BitField<otg_fs_host_t, 4, 1, READONLY>{}; // bit offset: 4, bit width: 1, Port overcurrent active
    constexpr auto POCCHNG = BitField<otg_fs_host_t, 5, 1, READWRITE>{}; // bit offset: 5, bit width: 1, Port overcurrent change
    constexpr auto PRES = BitField<otg_fs_host_t, 6, 1, READWRITE>{}; // bit offset: 6, bit width: 1, Port resume
    constexpr auto PSUSP = BitField<otg_fs_host_t, 7, 1, READWRITE>{}; // bit offset: 7, bit width: 1, Port suspend
    constexpr auto PRST = BitField<otg_fs_host_t, 8, 1, READWRITE>{}; // bit offset: 8, bit width: 1, Port reset
    constexpr auto PLSTS = BitField<otg_fs_host_t, 10, 2, READONLY>{}; // bit offset: 10, bit width: 2, Port line status
    constexpr auto PPWR = BitField<otg_fs_host_t, 12, 1, READWRITE>{}; // bit offset: 12, bit width: 1, Port power
    constexpr auto PTCTL = BitField<otg_fs_host_t, 13, 4, READWRITE>{}; // bit offset: 13, bit width: 4, Port test control
    constexpr auto PSPD = BitField<otg_fs_host_t, 17, 2, READONLY>{}; // bit offset: 17, bit width: 2, Port speed
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000040u, 0, READWRITE, decltype(PCSTS), decltype(PCDET), decltype(PENA), decltype(PENCHNG), decltype(POCA), decltype(POCCHNG), decltype(PRES), decltype(PSUSP), decltype(PRST), decltype(PLSTS), decltype(PPWR), decltype(PTCTL), decltype(PSPD)> FS_HPRT; // OTG_FS host port control and status register (OTG_FS_HPRT)

    constexpr auto MPSIZ = BitField<otg_fs_host_t, 0, 11>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto EPNUM = BitField<otg_fs_host_t, 11, 4>{}; // bit offset: 11, bit width: 4, Endpoint number
    constexpr auto EPDIR = BitField<otg_fs_host_t, 15, 1>{}; // bit offset: 15, bit width: 1, Endpoint direction
    constexpr auto LSDEV = BitField<otg_fs_host_t, 17, 1>{}; // bit offset: 17, bit width: 1, Low-speed device
    constexpr auto EPTYP = BitField<otg_fs_host_t, 18, 2>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto MCNT = BitField<otg_fs_host_t, 20, 2>{}; // bit offset: 20, bit width: 2, Multicount
    constexpr auto DAD = BitField<otg_fs_host_t, 22, 7>{}; // bit offset: 22, bit width: 7, Device address
    constexpr auto ODDFRM = BitField<otg_fs_host_t, 29, 1>{}; // bit offset: 29, bit width: 1, Odd frame
    constexpr auto CHDIS = BitField<otg_fs_host_t, 30, 1>{}; // bit offset: 30, bit width: 1, Channel disable
    constexpr auto CHENA = BitField<otg_fs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Channel enable
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000100u, 0, READWRITE, decltype(MPSIZ), decltype(EPNUM), decltype(EPDIR), decltype(LSDEV), decltype(EPTYP), decltype(MCNT), decltype(DAD), decltype(ODDFRM), decltype(CHDIS), decltype(CHENA)> FS_HCCHAR0; // OTG_FS host channel-0 characteristics register (OTG_FS_HCCHAR0)

    constexpr auto MPSIZ = BitField<otg_fs_host_t, 0, 11>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto EPNUM = BitField<otg_fs_host_t, 11, 4>{}; // bit offset: 11, bit width: 4, Endpoint number
    constexpr auto EPDIR = BitField<otg_fs_host_t, 15, 1>{}; // bit offset: 15, bit width: 1, Endpoint direction
    constexpr auto LSDEV = BitField<otg_fs_host_t, 17, 1>{}; // bit offset: 17, bit width: 1, Low-speed device
    constexpr auto EPTYP = BitField<otg_fs_host_t, 18, 2>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto MCNT = BitField<otg_fs_host_t, 20, 2>{}; // bit offset: 20, bit width: 2, Multicount
    constexpr auto DAD = BitField<otg_fs_host_t, 22, 7>{}; // bit offset: 22, bit width: 7, Device address
    constexpr auto ODDFRM = BitField<otg_fs_host_t, 29, 1>{}; // bit offset: 29, bit width: 1, Odd frame
    constexpr auto CHDIS = BitField<otg_fs_host_t, 30, 1>{}; // bit offset: 30, bit width: 1, Channel disable
    constexpr auto CHENA = BitField<otg_fs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Channel enable
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000120u, 0, READWRITE, decltype(MPSIZ), decltype(EPNUM), decltype(EPDIR), decltype(LSDEV), decltype(EPTYP), decltype(MCNT), decltype(DAD), decltype(ODDFRM), decltype(CHDIS), decltype(CHENA)> FS_HCCHAR1; // OTG_FS host channel-1 characteristics register (OTG_FS_HCCHAR1)

    constexpr auto MPSIZ = BitField<otg_fs_host_t, 0, 11>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto EPNUM = BitField<otg_fs_host_t, 11, 4>{}; // bit offset: 11, bit width: 4, Endpoint number
    constexpr auto EPDIR = BitField<otg_fs_host_t, 15, 1>{}; // bit offset: 15, bit width: 1, Endpoint direction
    constexpr auto LSDEV = BitField<otg_fs_host_t, 17, 1>{}; // bit offset: 17, bit width: 1, Low-speed device
    constexpr auto EPTYP = BitField<otg_fs_host_t, 18, 2>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto MCNT = BitField<otg_fs_host_t, 20, 2>{}; // bit offset: 20, bit width: 2, Multicount
    constexpr auto DAD = BitField<otg_fs_host_t, 22, 7>{}; // bit offset: 22, bit width: 7, Device address
    constexpr auto ODDFRM = BitField<otg_fs_host_t, 29, 1>{}; // bit offset: 29, bit width: 1, Odd frame
    constexpr auto CHDIS = BitField<otg_fs_host_t, 30, 1>{}; // bit offset: 30, bit width: 1, Channel disable
    constexpr auto CHENA = BitField<otg_fs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Channel enable
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000140u, 0, READWRITE, decltype(MPSIZ), decltype(EPNUM), decltype(EPDIR), decltype(LSDEV), decltype(EPTYP), decltype(MCNT), decltype(DAD), decltype(ODDFRM), decltype(CHDIS), decltype(CHENA)> FS_HCCHAR2; // OTG_FS host channel-2 characteristics register (OTG_FS_HCCHAR2)

    constexpr auto MPSIZ = BitField<otg_fs_host_t, 0, 11>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto EPNUM = BitField<otg_fs_host_t, 11, 4>{}; // bit offset: 11, bit width: 4, Endpoint number
    constexpr auto EPDIR = BitField<otg_fs_host_t, 15, 1>{}; // bit offset: 15, bit width: 1, Endpoint direction
    constexpr auto LSDEV = BitField<otg_fs_host_t, 17, 1>{}; // bit offset: 17, bit width: 1, Low-speed device
    constexpr auto EPTYP = BitField<otg_fs_host_t, 18, 2>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto MCNT = BitField<otg_fs_host_t, 20, 2>{}; // bit offset: 20, bit width: 2, Multicount
    constexpr auto DAD = BitField<otg_fs_host_t, 22, 7>{}; // bit offset: 22, bit width: 7, Device address
    constexpr auto ODDFRM = BitField<otg_fs_host_t, 29, 1>{}; // bit offset: 29, bit width: 1, Odd frame
    constexpr auto CHDIS = BitField<otg_fs_host_t, 30, 1>{}; // bit offset: 30, bit width: 1, Channel disable
    constexpr auto CHENA = BitField<otg_fs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Channel enable
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000160u, 0, READWRITE, decltype(MPSIZ), decltype(EPNUM), decltype(EPDIR), decltype(LSDEV), decltype(EPTYP), decltype(MCNT), decltype(DAD), decltype(ODDFRM), decltype(CHDIS), decltype(CHENA)> FS_HCCHAR3; // OTG_FS host channel-3 characteristics register (OTG_FS_HCCHAR3)

    constexpr auto MPSIZ = BitField<otg_fs_host_t, 0, 11>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto EPNUM = BitField<otg_fs_host_t, 11, 4>{}; // bit offset: 11, bit width: 4, Endpoint number
    constexpr auto EPDIR = BitField<otg_fs_host_t, 15, 1>{}; // bit offset: 15, bit width: 1, Endpoint direction
    constexpr auto LSDEV = BitField<otg_fs_host_t, 17, 1>{}; // bit offset: 17, bit width: 1, Low-speed device
    constexpr auto EPTYP = BitField<otg_fs_host_t, 18, 2>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto MCNT = BitField<otg_fs_host_t, 20, 2>{}; // bit offset: 20, bit width: 2, Multicount
    constexpr auto DAD = BitField<otg_fs_host_t, 22, 7>{}; // bit offset: 22, bit width: 7, Device address
    constexpr auto ODDFRM = BitField<otg_fs_host_t, 29, 1>{}; // bit offset: 29, bit width: 1, Odd frame
    constexpr auto CHDIS = BitField<otg_fs_host_t, 30, 1>{}; // bit offset: 30, bit width: 1, Channel disable
    constexpr auto CHENA = BitField<otg_fs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Channel enable
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000180u, 0, READWRITE, decltype(MPSIZ), decltype(EPNUM), decltype(EPDIR), decltype(LSDEV), decltype(EPTYP), decltype(MCNT), decltype(DAD), decltype(ODDFRM), decltype(CHDIS), decltype(CHENA)> FS_HCCHAR4; // OTG_FS host channel-4 characteristics register (OTG_FS_HCCHAR4)

    constexpr auto MPSIZ = BitField<otg_fs_host_t, 0, 11>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto EPNUM = BitField<otg_fs_host_t, 11, 4>{}; // bit offset: 11, bit width: 4, Endpoint number
    constexpr auto EPDIR = BitField<otg_fs_host_t, 15, 1>{}; // bit offset: 15, bit width: 1, Endpoint direction
    constexpr auto LSDEV = BitField<otg_fs_host_t, 17, 1>{}; // bit offset: 17, bit width: 1, Low-speed device
    constexpr auto EPTYP = BitField<otg_fs_host_t, 18, 2>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto MCNT = BitField<otg_fs_host_t, 20, 2>{}; // bit offset: 20, bit width: 2, Multicount
    constexpr auto DAD = BitField<otg_fs_host_t, 22, 7>{}; // bit offset: 22, bit width: 7, Device address
    constexpr auto ODDFRM = BitField<otg_fs_host_t, 29, 1>{}; // bit offset: 29, bit width: 1, Odd frame
    constexpr auto CHDIS = BitField<otg_fs_host_t, 30, 1>{}; // bit offset: 30, bit width: 1, Channel disable
    constexpr auto CHENA = BitField<otg_fs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Channel enable
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x000001a0u, 0, READWRITE, decltype(MPSIZ), decltype(EPNUM), decltype(EPDIR), decltype(LSDEV), decltype(EPTYP), decltype(MCNT), decltype(DAD), decltype(ODDFRM), decltype(CHDIS), decltype(CHENA)> FS_HCCHAR5; // OTG_FS host channel-5 characteristics register (OTG_FS_HCCHAR5)

    constexpr auto MPSIZ = BitField<otg_fs_host_t, 0, 11>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto EPNUM = BitField<otg_fs_host_t, 11, 4>{}; // bit offset: 11, bit width: 4, Endpoint number
    constexpr auto EPDIR = BitField<otg_fs_host_t, 15, 1>{}; // bit offset: 15, bit width: 1, Endpoint direction
    constexpr auto LSDEV = BitField<otg_fs_host_t, 17, 1>{}; // bit offset: 17, bit width: 1, Low-speed device
    constexpr auto EPTYP = BitField<otg_fs_host_t, 18, 2>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto MCNT = BitField<otg_fs_host_t, 20, 2>{}; // bit offset: 20, bit width: 2, Multicount
    constexpr auto DAD = BitField<otg_fs_host_t, 22, 7>{}; // bit offset: 22, bit width: 7, Device address
    constexpr auto ODDFRM = BitField<otg_fs_host_t, 29, 1>{}; // bit offset: 29, bit width: 1, Odd frame
    constexpr auto CHDIS = BitField<otg_fs_host_t, 30, 1>{}; // bit offset: 30, bit width: 1, Channel disable
    constexpr auto CHENA = BitField<otg_fs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Channel enable
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x000001c0u, 0, READWRITE, decltype(MPSIZ), decltype(EPNUM), decltype(EPDIR), decltype(LSDEV), decltype(EPTYP), decltype(MCNT), decltype(DAD), decltype(ODDFRM), decltype(CHDIS), decltype(CHENA)> FS_HCCHAR6; // OTG_FS host channel-6 characteristics register (OTG_FS_HCCHAR6)

    constexpr auto MPSIZ = BitField<otg_fs_host_t, 0, 11>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto EPNUM = BitField<otg_fs_host_t, 11, 4>{}; // bit offset: 11, bit width: 4, Endpoint number
    constexpr auto EPDIR = BitField<otg_fs_host_t, 15, 1>{}; // bit offset: 15, bit width: 1, Endpoint direction
    constexpr auto LSDEV = BitField<otg_fs_host_t, 17, 1>{}; // bit offset: 17, bit width: 1, Low-speed device
    constexpr auto EPTYP = BitField<otg_fs_host_t, 18, 2>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto MCNT = BitField<otg_fs_host_t, 20, 2>{}; // bit offset: 20, bit width: 2, Multicount
    constexpr auto DAD = BitField<otg_fs_host_t, 22, 7>{}; // bit offset: 22, bit width: 7, Device address
    constexpr auto ODDFRM = BitField<otg_fs_host_t, 29, 1>{}; // bit offset: 29, bit width: 1, Odd frame
    constexpr auto CHDIS = BitField<otg_fs_host_t, 30, 1>{}; // bit offset: 30, bit width: 1, Channel disable
    constexpr auto CHENA = BitField<otg_fs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Channel enable
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x000001e0u, 0, READWRITE, decltype(MPSIZ), decltype(EPNUM), decltype(EPDIR), decltype(LSDEV), decltype(EPTYP), decltype(MCNT), decltype(DAD), decltype(ODDFRM), decltype(CHDIS), decltype(CHENA)> FS_HCCHAR7; // OTG_FS host channel-7 characteristics register (OTG_FS_HCCHAR7)

    constexpr auto XFRC = BitField<otg_fs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed
    constexpr auto CHH = BitField<otg_fs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted
    constexpr auto STALL = BitField<otg_fs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt
    constexpr auto NAK = BitField<otg_fs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt
    constexpr auto ACK = BitField<otg_fs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt
    constexpr auto TXERR = BitField<otg_fs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error
    constexpr auto BBERR = BitField<otg_fs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error
    constexpr auto FRMOR = BitField<otg_fs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun
    constexpr auto DTERR = BitField<otg_fs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000108u, 0, READWRITE, decltype(XFRC), decltype(CHH), decltype(STALL), decltype(NAK), decltype(ACK), decltype(TXERR), decltype(BBERR), decltype(FRMOR), decltype(DTERR)> FS_HCINT0; // OTG_FS host channel-0 interrupt register (OTG_FS_HCINT0)

    constexpr auto XFRC = BitField<otg_fs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed
    constexpr auto CHH = BitField<otg_fs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted
    constexpr auto STALL = BitField<otg_fs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt
    constexpr auto NAK = BitField<otg_fs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt
    constexpr auto ACK = BitField<otg_fs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt
    constexpr auto TXERR = BitField<otg_fs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error
    constexpr auto BBERR = BitField<otg_fs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error
    constexpr auto FRMOR = BitField<otg_fs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun
    constexpr auto DTERR = BitField<otg_fs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000128u, 0, READWRITE, decltype(XFRC), decltype(CHH), decltype(STALL), decltype(NAK), decltype(ACK), decltype(TXERR), decltype(BBERR), decltype(FRMOR), decltype(DTERR)> FS_HCINT1; // OTG_FS host channel-1 interrupt register (OTG_FS_HCINT1)

    constexpr auto XFRC = BitField<otg_fs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed
    constexpr auto CHH = BitField<otg_fs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted
    constexpr auto STALL = BitField<otg_fs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt
    constexpr auto NAK = BitField<otg_fs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt
    constexpr auto ACK = BitField<otg_fs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt
    constexpr auto TXERR = BitField<otg_fs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error
    constexpr auto BBERR = BitField<otg_fs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error
    constexpr auto FRMOR = BitField<otg_fs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun
    constexpr auto DTERR = BitField<otg_fs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000148u, 0, READWRITE, decltype(XFRC), decltype(CHH), decltype(STALL), decltype(NAK), decltype(ACK), decltype(TXERR), decltype(BBERR), decltype(FRMOR), decltype(DTERR)> FS_HCINT2; // OTG_FS host channel-2 interrupt register (OTG_FS_HCINT2)

    constexpr auto XFRC = BitField<otg_fs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed
    constexpr auto CHH = BitField<otg_fs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted
    constexpr auto STALL = BitField<otg_fs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt
    constexpr auto NAK = BitField<otg_fs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt
    constexpr auto ACK = BitField<otg_fs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt
    constexpr auto TXERR = BitField<otg_fs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error
    constexpr auto BBERR = BitField<otg_fs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error
    constexpr auto FRMOR = BitField<otg_fs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun
    constexpr auto DTERR = BitField<otg_fs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000168u, 0, READWRITE, decltype(XFRC), decltype(CHH), decltype(STALL), decltype(NAK), decltype(ACK), decltype(TXERR), decltype(BBERR), decltype(FRMOR), decltype(DTERR)> FS_HCINT3; // OTG_FS host channel-3 interrupt register (OTG_FS_HCINT3)

    constexpr auto XFRC = BitField<otg_fs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed
    constexpr auto CHH = BitField<otg_fs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted
    constexpr auto STALL = BitField<otg_fs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt
    constexpr auto NAK = BitField<otg_fs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt
    constexpr auto ACK = BitField<otg_fs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt
    constexpr auto TXERR = BitField<otg_fs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error
    constexpr auto BBERR = BitField<otg_fs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error
    constexpr auto FRMOR = BitField<otg_fs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun
    constexpr auto DTERR = BitField<otg_fs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000188u, 0, READWRITE, decltype(XFRC), decltype(CHH), decltype(STALL), decltype(NAK), decltype(ACK), decltype(TXERR), decltype(BBERR), decltype(FRMOR), decltype(DTERR)> FS_HCINT4; // OTG_FS host channel-4 interrupt register (OTG_FS_HCINT4)

    constexpr auto XFRC = BitField<otg_fs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed
    constexpr auto CHH = BitField<otg_fs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted
    constexpr auto STALL = BitField<otg_fs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt
    constexpr auto NAK = BitField<otg_fs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt
    constexpr auto ACK = BitField<otg_fs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt
    constexpr auto TXERR = BitField<otg_fs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error
    constexpr auto BBERR = BitField<otg_fs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error
    constexpr auto FRMOR = BitField<otg_fs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun
    constexpr auto DTERR = BitField<otg_fs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x000001a8u, 0, READWRITE, decltype(XFRC), decltype(CHH), decltype(STALL), decltype(NAK), decltype(ACK), decltype(TXERR), decltype(BBERR), decltype(FRMOR), decltype(DTERR)> FS_HCINT5; // OTG_FS host channel-5 interrupt register (OTG_FS_HCINT5)

    constexpr auto XFRC = BitField<otg_fs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed
    constexpr auto CHH = BitField<otg_fs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted
    constexpr auto STALL = BitField<otg_fs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt
    constexpr auto NAK = BitField<otg_fs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt
    constexpr auto ACK = BitField<otg_fs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt
    constexpr auto TXERR = BitField<otg_fs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error
    constexpr auto BBERR = BitField<otg_fs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error
    constexpr auto FRMOR = BitField<otg_fs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun
    constexpr auto DTERR = BitField<otg_fs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x000001c8u, 0, READWRITE, decltype(XFRC), decltype(CHH), decltype(STALL), decltype(NAK), decltype(ACK), decltype(TXERR), decltype(BBERR), decltype(FRMOR), decltype(DTERR)> FS_HCINT6; // OTG_FS host channel-6 interrupt register (OTG_FS_HCINT6)

    constexpr auto XFRC = BitField<otg_fs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed
    constexpr auto CHH = BitField<otg_fs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted
    constexpr auto STALL = BitField<otg_fs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt
    constexpr auto NAK = BitField<otg_fs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt
    constexpr auto ACK = BitField<otg_fs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt
    constexpr auto TXERR = BitField<otg_fs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error
    constexpr auto BBERR = BitField<otg_fs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error
    constexpr auto FRMOR = BitField<otg_fs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun
    constexpr auto DTERR = BitField<otg_fs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x000001e8u, 0, READWRITE, decltype(XFRC), decltype(CHH), decltype(STALL), decltype(NAK), decltype(ACK), decltype(TXERR), decltype(BBERR), decltype(FRMOR), decltype(DTERR)> FS_HCINT7; // OTG_FS host channel-7 interrupt register (OTG_FS_HCINT7)

    constexpr auto XFRCM = BitField<otg_fs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed mask
    constexpr auto CHHM = BitField<otg_fs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted mask
    constexpr auto STALLM = BitField<otg_fs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt mask
    constexpr auto NAKM = BitField<otg_fs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt mask
    constexpr auto ACKM = BitField<otg_fs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt mask
    constexpr auto NYET = BitField<otg_fs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, response received interrupt mask
    constexpr auto TXERRM = BitField<otg_fs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error mask
    constexpr auto BBERRM = BitField<otg_fs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error mask
    constexpr auto FRMORM = BitField<otg_fs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun mask
    constexpr auto DTERRM = BitField<otg_fs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error mask
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x0000010cu, 0, READWRITE, decltype(XFRCM), decltype(CHHM), decltype(STALLM), decltype(NAKM), decltype(ACKM), decltype(NYET), decltype(TXERRM), decltype(BBERRM), decltype(FRMORM), decltype(DTERRM)> FS_HCINTMSK0; // OTG_FS host channel-0 mask register (OTG_FS_HCINTMSK0)

    constexpr auto XFRCM = BitField<otg_fs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed mask
    constexpr auto CHHM = BitField<otg_fs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted mask
    constexpr auto STALLM = BitField<otg_fs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt mask
    constexpr auto NAKM = BitField<otg_fs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt mask
    constexpr auto ACKM = BitField<otg_fs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt mask
    constexpr auto NYET = BitField<otg_fs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, response received interrupt mask
    constexpr auto TXERRM = BitField<otg_fs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error mask
    constexpr auto BBERRM = BitField<otg_fs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error mask
    constexpr auto FRMORM = BitField<otg_fs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun mask
    constexpr auto DTERRM = BitField<otg_fs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error mask
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x0000012cu, 0, READWRITE, decltype(XFRCM), decltype(CHHM), decltype(STALLM), decltype(NAKM), decltype(ACKM), decltype(NYET), decltype(TXERRM), decltype(BBERRM), decltype(FRMORM), decltype(DTERRM)> FS_HCINTMSK1; // OTG_FS host channel-1 mask register (OTG_FS_HCINTMSK1)

    constexpr auto XFRCM = BitField<otg_fs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed mask
    constexpr auto CHHM = BitField<otg_fs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted mask
    constexpr auto STALLM = BitField<otg_fs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt mask
    constexpr auto NAKM = BitField<otg_fs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt mask
    constexpr auto ACKM = BitField<otg_fs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt mask
    constexpr auto NYET = BitField<otg_fs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, response received interrupt mask
    constexpr auto TXERRM = BitField<otg_fs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error mask
    constexpr auto BBERRM = BitField<otg_fs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error mask
    constexpr auto FRMORM = BitField<otg_fs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun mask
    constexpr auto DTERRM = BitField<otg_fs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error mask
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x0000014cu, 0, READWRITE, decltype(XFRCM), decltype(CHHM), decltype(STALLM), decltype(NAKM), decltype(ACKM), decltype(NYET), decltype(TXERRM), decltype(BBERRM), decltype(FRMORM), decltype(DTERRM)> FS_HCINTMSK2; // OTG_FS host channel-2 mask register (OTG_FS_HCINTMSK2)

    constexpr auto XFRCM = BitField<otg_fs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed mask
    constexpr auto CHHM = BitField<otg_fs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted mask
    constexpr auto STALLM = BitField<otg_fs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt mask
    constexpr auto NAKM = BitField<otg_fs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt mask
    constexpr auto ACKM = BitField<otg_fs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt mask
    constexpr auto NYET = BitField<otg_fs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, response received interrupt mask
    constexpr auto TXERRM = BitField<otg_fs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error mask
    constexpr auto BBERRM = BitField<otg_fs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error mask
    constexpr auto FRMORM = BitField<otg_fs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun mask
    constexpr auto DTERRM = BitField<otg_fs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error mask
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x0000016cu, 0, READWRITE, decltype(XFRCM), decltype(CHHM), decltype(STALLM), decltype(NAKM), decltype(ACKM), decltype(NYET), decltype(TXERRM), decltype(BBERRM), decltype(FRMORM), decltype(DTERRM)> FS_HCINTMSK3; // OTG_FS host channel-3 mask register (OTG_FS_HCINTMSK3)

    constexpr auto XFRCM = BitField<otg_fs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed mask
    constexpr auto CHHM = BitField<otg_fs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted mask
    constexpr auto STALLM = BitField<otg_fs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt mask
    constexpr auto NAKM = BitField<otg_fs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt mask
    constexpr auto ACKM = BitField<otg_fs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt mask
    constexpr auto NYET = BitField<otg_fs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, response received interrupt mask
    constexpr auto TXERRM = BitField<otg_fs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error mask
    constexpr auto BBERRM = BitField<otg_fs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error mask
    constexpr auto FRMORM = BitField<otg_fs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun mask
    constexpr auto DTERRM = BitField<otg_fs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error mask
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x0000018cu, 0, READWRITE, decltype(XFRCM), decltype(CHHM), decltype(STALLM), decltype(NAKM), decltype(ACKM), decltype(NYET), decltype(TXERRM), decltype(BBERRM), decltype(FRMORM), decltype(DTERRM)> FS_HCINTMSK4; // OTG_FS host channel-4 mask register (OTG_FS_HCINTMSK4)

    constexpr auto XFRCM = BitField<otg_fs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed mask
    constexpr auto CHHM = BitField<otg_fs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted mask
    constexpr auto STALLM = BitField<otg_fs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt mask
    constexpr auto NAKM = BitField<otg_fs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt mask
    constexpr auto ACKM = BitField<otg_fs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt mask
    constexpr auto NYET = BitField<otg_fs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, response received interrupt mask
    constexpr auto TXERRM = BitField<otg_fs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error mask
    constexpr auto BBERRM = BitField<otg_fs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error mask
    constexpr auto FRMORM = BitField<otg_fs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun mask
    constexpr auto DTERRM = BitField<otg_fs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error mask
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x000001acu, 0, READWRITE, decltype(XFRCM), decltype(CHHM), decltype(STALLM), decltype(NAKM), decltype(ACKM), decltype(NYET), decltype(TXERRM), decltype(BBERRM), decltype(FRMORM), decltype(DTERRM)> FS_HCINTMSK5; // OTG_FS host channel-5 mask register (OTG_FS_HCINTMSK5)

    constexpr auto XFRCM = BitField<otg_fs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed mask
    constexpr auto CHHM = BitField<otg_fs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted mask
    constexpr auto STALLM = BitField<otg_fs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt mask
    constexpr auto NAKM = BitField<otg_fs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt mask
    constexpr auto ACKM = BitField<otg_fs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt mask
    constexpr auto NYET = BitField<otg_fs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, response received interrupt mask
    constexpr auto TXERRM = BitField<otg_fs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error mask
    constexpr auto BBERRM = BitField<otg_fs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error mask
    constexpr auto FRMORM = BitField<otg_fs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun mask
    constexpr auto DTERRM = BitField<otg_fs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error mask
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x000001ccu, 0, READWRITE, decltype(XFRCM), decltype(CHHM), decltype(STALLM), decltype(NAKM), decltype(ACKM), decltype(NYET), decltype(TXERRM), decltype(BBERRM), decltype(FRMORM), decltype(DTERRM)> FS_HCINTMSK6; // OTG_FS host channel-6 mask register (OTG_FS_HCINTMSK6)

    constexpr auto XFRCM = BitField<otg_fs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed mask
    constexpr auto CHHM = BitField<otg_fs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted mask
    constexpr auto STALLM = BitField<otg_fs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt mask
    constexpr auto NAKM = BitField<otg_fs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt mask
    constexpr auto ACKM = BitField<otg_fs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt mask
    constexpr auto NYET = BitField<otg_fs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, response received interrupt mask
    constexpr auto TXERRM = BitField<otg_fs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error mask
    constexpr auto BBERRM = BitField<otg_fs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error mask
    constexpr auto FRMORM = BitField<otg_fs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun mask
    constexpr auto DTERRM = BitField<otg_fs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error mask
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x000001ecu, 0, READWRITE, decltype(XFRCM), decltype(CHHM), decltype(STALLM), decltype(NAKM), decltype(ACKM), decltype(NYET), decltype(TXERRM), decltype(BBERRM), decltype(FRMORM), decltype(DTERRM)> FS_HCINTMSK7; // OTG_FS host channel-7 mask register (OTG_FS_HCINTMSK7)

    constexpr auto XFRSIZ = BitField<otg_fs_host_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_fs_host_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto DPID = BitField<otg_fs_host_t, 29, 2>{}; // bit offset: 29, bit width: 2, Data PID
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000110u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(DPID)> FS_HCTSIZ0; // OTG_FS host channel-0 transfer size register

    constexpr auto XFRSIZ = BitField<otg_fs_host_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_fs_host_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto DPID = BitField<otg_fs_host_t, 29, 2>{}; // bit offset: 29, bit width: 2, Data PID
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000130u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(DPID)> FS_HCTSIZ1; // OTG_FS host channel-1 transfer size register

    constexpr auto XFRSIZ = BitField<otg_fs_host_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_fs_host_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto DPID = BitField<otg_fs_host_t, 29, 2>{}; // bit offset: 29, bit width: 2, Data PID
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000150u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(DPID)> FS_HCTSIZ2; // OTG_FS host channel-2 transfer size register

    constexpr auto XFRSIZ = BitField<otg_fs_host_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_fs_host_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto DPID = BitField<otg_fs_host_t, 29, 2>{}; // bit offset: 29, bit width: 2, Data PID
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000170u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(DPID)> FS_HCTSIZ3; // OTG_FS host channel-3 transfer size register

    constexpr auto XFRSIZ = BitField<otg_fs_host_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_fs_host_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto DPID = BitField<otg_fs_host_t, 29, 2>{}; // bit offset: 29, bit width: 2, Data PID
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x00000190u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(DPID)> FS_HCTSIZ4; // OTG_FS host channel-x transfer size register

    constexpr auto XFRSIZ = BitField<otg_fs_host_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_fs_host_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto DPID = BitField<otg_fs_host_t, 29, 2>{}; // bit offset: 29, bit width: 2, Data PID
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x000001b0u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(DPID)> FS_HCTSIZ5; // OTG_FS host channel-5 transfer size register

    constexpr auto XFRSIZ = BitField<otg_fs_host_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_fs_host_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto DPID = BitField<otg_fs_host_t, 29, 2>{}; // bit offset: 29, bit width: 2, Data PID
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x000001d0u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(DPID)> FS_HCTSIZ6; // OTG_FS host channel-6 transfer size register

    constexpr auto XFRSIZ = BitField<otg_fs_host_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_fs_host_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto DPID = BitField<otg_fs_host_t, 29, 2>{}; // bit offset: 29, bit width: 2, Data PID
    static Register<std::uint32_t, OTG_FS_HOST_BASE_ADDRESS + 0x000001f0u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(DPID)> FS_HCTSIZ7; // OTG_FS host channel-7 transfer size register

} // namespace OTG_FS_HOST