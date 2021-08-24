#include <Register.hpp>




namespace OTG_HS_HOST
{
    struct otg_hs_host_t{};

    constexpr std::uint32_t OTG_HS_HOST_BASE_ADDRESS = 0x40040400u;

    constexpr auto FSLSPCS = BitField<otg_hs_host_t, 0, 2, READWRITE>{}; // bit offset: 0, bit width: 2, FS/LS PHY clock select
    constexpr auto FSLSS = BitField<otg_hs_host_t, 2, 1, READONLY>{}; // bit offset: 2, bit width: 1, FS- and LS-only support
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000000u, 0, READWRITE, decltype(FSLSPCS), decltype(FSLSS)> OTG_HS_HCFG; // OTG_HS host configuration register

    constexpr auto FRIVL = BitField<otg_hs_host_t, 0, 16>{}; // bit offset: 0, bit width: 16, Frame interval
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000004u, 60000, READWRITE, decltype(FRIVL)> OTG_HS_HFIR; // OTG_HS Host frame interval register

    constexpr auto FRNUM = BitField<otg_hs_host_t, 0, 16>{}; // bit offset: 0, bit width: 16, Frame number
    constexpr auto FTREM = BitField<otg_hs_host_t, 16, 16>{}; // bit offset: 16, bit width: 16, Frame time remaining
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000008u, 16383, READONLY, decltype(FRNUM), decltype(FTREM)> OTG_HS_HFNUM; // OTG_HS host frame number/frame time remaining register

    constexpr auto PTXFSAVL = BitField<otg_hs_host_t, 0, 16, READWRITE>{}; // bit offset: 0, bit width: 16, Periodic transmit data FIFO space available
    constexpr auto PTXQSAV = BitField<otg_hs_host_t, 16, 8, READONLY>{}; // bit offset: 16, bit width: 8, Periodic transmit request queue space available
    constexpr auto PTXQTOP = BitField<otg_hs_host_t, 24, 8, READONLY>{}; // bit offset: 24, bit width: 8, Top of the periodic transmit request queue
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000010u, 524544, READWRITE, decltype(PTXFSAVL), decltype(PTXQSAV), decltype(PTXQTOP)> OTG_HS_HPTXSTS; // OTG_HS_Host periodic transmit FIFO/queue status register

    constexpr auto HAINT = BitField<otg_hs_host_t, 0, 16>{}; // bit offset: 0, bit width: 16, Channel interrupts
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000014u, 0, READONLY, decltype(HAINT)> OTG_HS_HAINT; // OTG_HS Host all channels interrupt register

    constexpr auto HAINTM = BitField<otg_hs_host_t, 0, 16>{}; // bit offset: 0, bit width: 16, Channel interrupt mask
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000018u, 0, READWRITE, decltype(HAINTM)> OTG_HS_HAINTMSK; // OTG_HS host all channels interrupt mask register

    constexpr auto PCSTS = BitField<otg_hs_host_t, 0, 1, READONLY>{}; // bit offset: 0, bit width: 1, Port connect status
    constexpr auto PCDET = BitField<otg_hs_host_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, Port connect detected
    constexpr auto PENA = BitField<otg_hs_host_t, 2, 1, READWRITE>{}; // bit offset: 2, bit width: 1, Port enable
    constexpr auto PENCHNG = BitField<otg_hs_host_t, 3, 1, READWRITE>{}; // bit offset: 3, bit width: 1, Port enable/disable change
    constexpr auto POCA = BitField<otg_hs_host_t, 4, 1, READONLY>{}; // bit offset: 4, bit width: 1, Port overcurrent active
    constexpr auto POCCHNG = BitField<otg_hs_host_t, 5, 1, READWRITE>{}; // bit offset: 5, bit width: 1, Port overcurrent change
    constexpr auto PRES = BitField<otg_hs_host_t, 6, 1, READWRITE>{}; // bit offset: 6, bit width: 1, Port resume
    constexpr auto PSUSP = BitField<otg_hs_host_t, 7, 1, READWRITE>{}; // bit offset: 7, bit width: 1, Port suspend
    constexpr auto PRST = BitField<otg_hs_host_t, 8, 1, READWRITE>{}; // bit offset: 8, bit width: 1, Port reset
    constexpr auto PLSTS = BitField<otg_hs_host_t, 10, 2, READONLY>{}; // bit offset: 10, bit width: 2, Port line status
    constexpr auto PPWR = BitField<otg_hs_host_t, 12, 1, READWRITE>{}; // bit offset: 12, bit width: 1, Port power
    constexpr auto PTCTL = BitField<otg_hs_host_t, 13, 4, READWRITE>{}; // bit offset: 13, bit width: 4, Port test control
    constexpr auto PSPD = BitField<otg_hs_host_t, 17, 2, READONLY>{}; // bit offset: 17, bit width: 2, Port speed
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000040u, 0, READWRITE, decltype(PCSTS), decltype(PCDET), decltype(PENA), decltype(PENCHNG), decltype(POCA), decltype(POCCHNG), decltype(PRES), decltype(PSUSP), decltype(PRST), decltype(PLSTS), decltype(PPWR), decltype(PTCTL), decltype(PSPD)> OTG_HS_HPRT; // OTG_HS host port control and status register

    constexpr auto MPSIZ = BitField<otg_hs_host_t, 0, 11>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto EPNUM = BitField<otg_hs_host_t, 11, 4>{}; // bit offset: 11, bit width: 4, Endpoint number
    constexpr auto EPDIR = BitField<otg_hs_host_t, 15, 1>{}; // bit offset: 15, bit width: 1, Endpoint direction
    constexpr auto LSDEV = BitField<otg_hs_host_t, 17, 1>{}; // bit offset: 17, bit width: 1, Low-speed device
    constexpr auto EPTYP = BitField<otg_hs_host_t, 18, 2>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto MC = BitField<otg_hs_host_t, 20, 2>{}; // bit offset: 20, bit width: 2, Multi Count (MC) / Error Count (EC)
    constexpr auto DAD = BitField<otg_hs_host_t, 22, 7>{}; // bit offset: 22, bit width: 7, Device address
    constexpr auto ODDFRM = BitField<otg_hs_host_t, 29, 1>{}; // bit offset: 29, bit width: 1, Odd frame
    constexpr auto CHDIS = BitField<otg_hs_host_t, 30, 1>{}; // bit offset: 30, bit width: 1, Channel disable
    constexpr auto CHENA = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Channel enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000100u, 0, READWRITE, decltype(MPSIZ), decltype(EPNUM), decltype(EPDIR), decltype(LSDEV), decltype(EPTYP), decltype(MC), decltype(DAD), decltype(ODDFRM), decltype(CHDIS), decltype(CHENA)> OTG_HS_HCCHAR0; // OTG_HS host channel-0 characteristics register

    constexpr auto MPSIZ = BitField<otg_hs_host_t, 0, 11>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto EPNUM = BitField<otg_hs_host_t, 11, 4>{}; // bit offset: 11, bit width: 4, Endpoint number
    constexpr auto EPDIR = BitField<otg_hs_host_t, 15, 1>{}; // bit offset: 15, bit width: 1, Endpoint direction
    constexpr auto LSDEV = BitField<otg_hs_host_t, 17, 1>{}; // bit offset: 17, bit width: 1, Low-speed device
    constexpr auto EPTYP = BitField<otg_hs_host_t, 18, 2>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto MC = BitField<otg_hs_host_t, 20, 2>{}; // bit offset: 20, bit width: 2, Multi Count (MC) / Error Count (EC)
    constexpr auto DAD = BitField<otg_hs_host_t, 22, 7>{}; // bit offset: 22, bit width: 7, Device address
    constexpr auto ODDFRM = BitField<otg_hs_host_t, 29, 1>{}; // bit offset: 29, bit width: 1, Odd frame
    constexpr auto CHDIS = BitField<otg_hs_host_t, 30, 1>{}; // bit offset: 30, bit width: 1, Channel disable
    constexpr auto CHENA = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Channel enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000120u, 0, READWRITE, decltype(MPSIZ), decltype(EPNUM), decltype(EPDIR), decltype(LSDEV), decltype(EPTYP), decltype(MC), decltype(DAD), decltype(ODDFRM), decltype(CHDIS), decltype(CHENA)> OTG_HS_HCCHAR1; // OTG_HS host channel-1 characteristics register

    constexpr auto MPSIZ = BitField<otg_hs_host_t, 0, 11>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto EPNUM = BitField<otg_hs_host_t, 11, 4>{}; // bit offset: 11, bit width: 4, Endpoint number
    constexpr auto EPDIR = BitField<otg_hs_host_t, 15, 1>{}; // bit offset: 15, bit width: 1, Endpoint direction
    constexpr auto LSDEV = BitField<otg_hs_host_t, 17, 1>{}; // bit offset: 17, bit width: 1, Low-speed device
    constexpr auto EPTYP = BitField<otg_hs_host_t, 18, 2>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto MC = BitField<otg_hs_host_t, 20, 2>{}; // bit offset: 20, bit width: 2, Multi Count (MC) / Error Count (EC)
    constexpr auto DAD = BitField<otg_hs_host_t, 22, 7>{}; // bit offset: 22, bit width: 7, Device address
    constexpr auto ODDFRM = BitField<otg_hs_host_t, 29, 1>{}; // bit offset: 29, bit width: 1, Odd frame
    constexpr auto CHDIS = BitField<otg_hs_host_t, 30, 1>{}; // bit offset: 30, bit width: 1, Channel disable
    constexpr auto CHENA = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Channel enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000140u, 0, READWRITE, decltype(MPSIZ), decltype(EPNUM), decltype(EPDIR), decltype(LSDEV), decltype(EPTYP), decltype(MC), decltype(DAD), decltype(ODDFRM), decltype(CHDIS), decltype(CHENA)> OTG_HS_HCCHAR2; // OTG_HS host channel-2 characteristics register

    constexpr auto MPSIZ = BitField<otg_hs_host_t, 0, 11>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto EPNUM = BitField<otg_hs_host_t, 11, 4>{}; // bit offset: 11, bit width: 4, Endpoint number
    constexpr auto EPDIR = BitField<otg_hs_host_t, 15, 1>{}; // bit offset: 15, bit width: 1, Endpoint direction
    constexpr auto LSDEV = BitField<otg_hs_host_t, 17, 1>{}; // bit offset: 17, bit width: 1, Low-speed device
    constexpr auto EPTYP = BitField<otg_hs_host_t, 18, 2>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto MC = BitField<otg_hs_host_t, 20, 2>{}; // bit offset: 20, bit width: 2, Multi Count (MC) / Error Count (EC)
    constexpr auto DAD = BitField<otg_hs_host_t, 22, 7>{}; // bit offset: 22, bit width: 7, Device address
    constexpr auto ODDFRM = BitField<otg_hs_host_t, 29, 1>{}; // bit offset: 29, bit width: 1, Odd frame
    constexpr auto CHDIS = BitField<otg_hs_host_t, 30, 1>{}; // bit offset: 30, bit width: 1, Channel disable
    constexpr auto CHENA = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Channel enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000160u, 0, READWRITE, decltype(MPSIZ), decltype(EPNUM), decltype(EPDIR), decltype(LSDEV), decltype(EPTYP), decltype(MC), decltype(DAD), decltype(ODDFRM), decltype(CHDIS), decltype(CHENA)> OTG_HS_HCCHAR3; // OTG_HS host channel-3 characteristics register

    constexpr auto MPSIZ = BitField<otg_hs_host_t, 0, 11>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto EPNUM = BitField<otg_hs_host_t, 11, 4>{}; // bit offset: 11, bit width: 4, Endpoint number
    constexpr auto EPDIR = BitField<otg_hs_host_t, 15, 1>{}; // bit offset: 15, bit width: 1, Endpoint direction
    constexpr auto LSDEV = BitField<otg_hs_host_t, 17, 1>{}; // bit offset: 17, bit width: 1, Low-speed device
    constexpr auto EPTYP = BitField<otg_hs_host_t, 18, 2>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto MC = BitField<otg_hs_host_t, 20, 2>{}; // bit offset: 20, bit width: 2, Multi Count (MC) / Error Count (EC)
    constexpr auto DAD = BitField<otg_hs_host_t, 22, 7>{}; // bit offset: 22, bit width: 7, Device address
    constexpr auto ODDFRM = BitField<otg_hs_host_t, 29, 1>{}; // bit offset: 29, bit width: 1, Odd frame
    constexpr auto CHDIS = BitField<otg_hs_host_t, 30, 1>{}; // bit offset: 30, bit width: 1, Channel disable
    constexpr auto CHENA = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Channel enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000180u, 0, READWRITE, decltype(MPSIZ), decltype(EPNUM), decltype(EPDIR), decltype(LSDEV), decltype(EPTYP), decltype(MC), decltype(DAD), decltype(ODDFRM), decltype(CHDIS), decltype(CHENA)> OTG_HS_HCCHAR4; // OTG_HS host channel-4 characteristics register

    constexpr auto MPSIZ = BitField<otg_hs_host_t, 0, 11>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto EPNUM = BitField<otg_hs_host_t, 11, 4>{}; // bit offset: 11, bit width: 4, Endpoint number
    constexpr auto EPDIR = BitField<otg_hs_host_t, 15, 1>{}; // bit offset: 15, bit width: 1, Endpoint direction
    constexpr auto LSDEV = BitField<otg_hs_host_t, 17, 1>{}; // bit offset: 17, bit width: 1, Low-speed device
    constexpr auto EPTYP = BitField<otg_hs_host_t, 18, 2>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto MC = BitField<otg_hs_host_t, 20, 2>{}; // bit offset: 20, bit width: 2, Multi Count (MC) / Error Count (EC)
    constexpr auto DAD = BitField<otg_hs_host_t, 22, 7>{}; // bit offset: 22, bit width: 7, Device address
    constexpr auto ODDFRM = BitField<otg_hs_host_t, 29, 1>{}; // bit offset: 29, bit width: 1, Odd frame
    constexpr auto CHDIS = BitField<otg_hs_host_t, 30, 1>{}; // bit offset: 30, bit width: 1, Channel disable
    constexpr auto CHENA = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Channel enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x000001a0u, 0, READWRITE, decltype(MPSIZ), decltype(EPNUM), decltype(EPDIR), decltype(LSDEV), decltype(EPTYP), decltype(MC), decltype(DAD), decltype(ODDFRM), decltype(CHDIS), decltype(CHENA)> OTG_HS_HCCHAR5; // OTG_HS host channel-5 characteristics register

    constexpr auto MPSIZ = BitField<otg_hs_host_t, 0, 11>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto EPNUM = BitField<otg_hs_host_t, 11, 4>{}; // bit offset: 11, bit width: 4, Endpoint number
    constexpr auto EPDIR = BitField<otg_hs_host_t, 15, 1>{}; // bit offset: 15, bit width: 1, Endpoint direction
    constexpr auto LSDEV = BitField<otg_hs_host_t, 17, 1>{}; // bit offset: 17, bit width: 1, Low-speed device
    constexpr auto EPTYP = BitField<otg_hs_host_t, 18, 2>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto MC = BitField<otg_hs_host_t, 20, 2>{}; // bit offset: 20, bit width: 2, Multi Count (MC) / Error Count (EC)
    constexpr auto DAD = BitField<otg_hs_host_t, 22, 7>{}; // bit offset: 22, bit width: 7, Device address
    constexpr auto ODDFRM = BitField<otg_hs_host_t, 29, 1>{}; // bit offset: 29, bit width: 1, Odd frame
    constexpr auto CHDIS = BitField<otg_hs_host_t, 30, 1>{}; // bit offset: 30, bit width: 1, Channel disable
    constexpr auto CHENA = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Channel enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x000001c0u, 0, READWRITE, decltype(MPSIZ), decltype(EPNUM), decltype(EPDIR), decltype(LSDEV), decltype(EPTYP), decltype(MC), decltype(DAD), decltype(ODDFRM), decltype(CHDIS), decltype(CHENA)> OTG_HS_HCCHAR6; // OTG_HS host channel-6 characteristics register

    constexpr auto MPSIZ = BitField<otg_hs_host_t, 0, 11>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto EPNUM = BitField<otg_hs_host_t, 11, 4>{}; // bit offset: 11, bit width: 4, Endpoint number
    constexpr auto EPDIR = BitField<otg_hs_host_t, 15, 1>{}; // bit offset: 15, bit width: 1, Endpoint direction
    constexpr auto LSDEV = BitField<otg_hs_host_t, 17, 1>{}; // bit offset: 17, bit width: 1, Low-speed device
    constexpr auto EPTYP = BitField<otg_hs_host_t, 18, 2>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto MC = BitField<otg_hs_host_t, 20, 2>{}; // bit offset: 20, bit width: 2, Multi Count (MC) / Error Count (EC)
    constexpr auto DAD = BitField<otg_hs_host_t, 22, 7>{}; // bit offset: 22, bit width: 7, Device address
    constexpr auto ODDFRM = BitField<otg_hs_host_t, 29, 1>{}; // bit offset: 29, bit width: 1, Odd frame
    constexpr auto CHDIS = BitField<otg_hs_host_t, 30, 1>{}; // bit offset: 30, bit width: 1, Channel disable
    constexpr auto CHENA = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Channel enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x000001e0u, 0, READWRITE, decltype(MPSIZ), decltype(EPNUM), decltype(EPDIR), decltype(LSDEV), decltype(EPTYP), decltype(MC), decltype(DAD), decltype(ODDFRM), decltype(CHDIS), decltype(CHENA)> OTG_HS_HCCHAR7; // OTG_HS host channel-7 characteristics register

    constexpr auto MPSIZ = BitField<otg_hs_host_t, 0, 11>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto EPNUM = BitField<otg_hs_host_t, 11, 4>{}; // bit offset: 11, bit width: 4, Endpoint number
    constexpr auto EPDIR = BitField<otg_hs_host_t, 15, 1>{}; // bit offset: 15, bit width: 1, Endpoint direction
    constexpr auto LSDEV = BitField<otg_hs_host_t, 17, 1>{}; // bit offset: 17, bit width: 1, Low-speed device
    constexpr auto EPTYP = BitField<otg_hs_host_t, 18, 2>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto MC = BitField<otg_hs_host_t, 20, 2>{}; // bit offset: 20, bit width: 2, Multi Count (MC) / Error Count (EC)
    constexpr auto DAD = BitField<otg_hs_host_t, 22, 7>{}; // bit offset: 22, bit width: 7, Device address
    constexpr auto ODDFRM = BitField<otg_hs_host_t, 29, 1>{}; // bit offset: 29, bit width: 1, Odd frame
    constexpr auto CHDIS = BitField<otg_hs_host_t, 30, 1>{}; // bit offset: 30, bit width: 1, Channel disable
    constexpr auto CHENA = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Channel enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000200u, 0, READWRITE, decltype(MPSIZ), decltype(EPNUM), decltype(EPDIR), decltype(LSDEV), decltype(EPTYP), decltype(MC), decltype(DAD), decltype(ODDFRM), decltype(CHDIS), decltype(CHENA)> OTG_HS_HCCHAR8; // OTG_HS host channel-8 characteristics register

    constexpr auto MPSIZ = BitField<otg_hs_host_t, 0, 11>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto EPNUM = BitField<otg_hs_host_t, 11, 4>{}; // bit offset: 11, bit width: 4, Endpoint number
    constexpr auto EPDIR = BitField<otg_hs_host_t, 15, 1>{}; // bit offset: 15, bit width: 1, Endpoint direction
    constexpr auto LSDEV = BitField<otg_hs_host_t, 17, 1>{}; // bit offset: 17, bit width: 1, Low-speed device
    constexpr auto EPTYP = BitField<otg_hs_host_t, 18, 2>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto MC = BitField<otg_hs_host_t, 20, 2>{}; // bit offset: 20, bit width: 2, Multi Count (MC) / Error Count (EC)
    constexpr auto DAD = BitField<otg_hs_host_t, 22, 7>{}; // bit offset: 22, bit width: 7, Device address
    constexpr auto ODDFRM = BitField<otg_hs_host_t, 29, 1>{}; // bit offset: 29, bit width: 1, Odd frame
    constexpr auto CHDIS = BitField<otg_hs_host_t, 30, 1>{}; // bit offset: 30, bit width: 1, Channel disable
    constexpr auto CHENA = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Channel enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000220u, 0, READWRITE, decltype(MPSIZ), decltype(EPNUM), decltype(EPDIR), decltype(LSDEV), decltype(EPTYP), decltype(MC), decltype(DAD), decltype(ODDFRM), decltype(CHDIS), decltype(CHENA)> OTG_HS_HCCHAR9; // OTG_HS host channel-9 characteristics register

    constexpr auto MPSIZ = BitField<otg_hs_host_t, 0, 11>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto EPNUM = BitField<otg_hs_host_t, 11, 4>{}; // bit offset: 11, bit width: 4, Endpoint number
    constexpr auto EPDIR = BitField<otg_hs_host_t, 15, 1>{}; // bit offset: 15, bit width: 1, Endpoint direction
    constexpr auto LSDEV = BitField<otg_hs_host_t, 17, 1>{}; // bit offset: 17, bit width: 1, Low-speed device
    constexpr auto EPTYP = BitField<otg_hs_host_t, 18, 2>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto MC = BitField<otg_hs_host_t, 20, 2>{}; // bit offset: 20, bit width: 2, Multi Count (MC) / Error Count (EC)
    constexpr auto DAD = BitField<otg_hs_host_t, 22, 7>{}; // bit offset: 22, bit width: 7, Device address
    constexpr auto ODDFRM = BitField<otg_hs_host_t, 29, 1>{}; // bit offset: 29, bit width: 1, Odd frame
    constexpr auto CHDIS = BitField<otg_hs_host_t, 30, 1>{}; // bit offset: 30, bit width: 1, Channel disable
    constexpr auto CHENA = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Channel enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000240u, 0, READWRITE, decltype(MPSIZ), decltype(EPNUM), decltype(EPDIR), decltype(LSDEV), decltype(EPTYP), decltype(MC), decltype(DAD), decltype(ODDFRM), decltype(CHDIS), decltype(CHENA)> OTG_HS_HCCHAR10; // OTG_HS host channel-10 characteristics register

    constexpr auto MPSIZ = BitField<otg_hs_host_t, 0, 11>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto EPNUM = BitField<otg_hs_host_t, 11, 4>{}; // bit offset: 11, bit width: 4, Endpoint number
    constexpr auto EPDIR = BitField<otg_hs_host_t, 15, 1>{}; // bit offset: 15, bit width: 1, Endpoint direction
    constexpr auto LSDEV = BitField<otg_hs_host_t, 17, 1>{}; // bit offset: 17, bit width: 1, Low-speed device
    constexpr auto EPTYP = BitField<otg_hs_host_t, 18, 2>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto MC = BitField<otg_hs_host_t, 20, 2>{}; // bit offset: 20, bit width: 2, Multi Count (MC) / Error Count (EC)
    constexpr auto DAD = BitField<otg_hs_host_t, 22, 7>{}; // bit offset: 22, bit width: 7, Device address
    constexpr auto ODDFRM = BitField<otg_hs_host_t, 29, 1>{}; // bit offset: 29, bit width: 1, Odd frame
    constexpr auto CHDIS = BitField<otg_hs_host_t, 30, 1>{}; // bit offset: 30, bit width: 1, Channel disable
    constexpr auto CHENA = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Channel enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000260u, 0, READWRITE, decltype(MPSIZ), decltype(EPNUM), decltype(EPDIR), decltype(LSDEV), decltype(EPTYP), decltype(MC), decltype(DAD), decltype(ODDFRM), decltype(CHDIS), decltype(CHENA)> OTG_HS_HCCHAR11; // OTG_HS host channel-11 characteristics register

    constexpr auto PRTADDR = BitField<otg_hs_host_t, 0, 7>{}; // bit offset: 0, bit width: 7, Port address
    constexpr auto HUBADDR = BitField<otg_hs_host_t, 7, 7>{}; // bit offset: 7, bit width: 7, Hub address
    constexpr auto XACTPOS = BitField<otg_hs_host_t, 14, 2>{}; // bit offset: 14, bit width: 2, XACTPOS
    constexpr auto COMPLSPLT = BitField<otg_hs_host_t, 16, 1>{}; // bit offset: 16, bit width: 1, Do complete split
    constexpr auto SPLITEN = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Split enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000104u, 0, READWRITE, decltype(PRTADDR), decltype(HUBADDR), decltype(XACTPOS), decltype(COMPLSPLT), decltype(SPLITEN)> OTG_HS_HCSPLT0; // OTG_HS host channel-0 split control register

    constexpr auto PRTADDR = BitField<otg_hs_host_t, 0, 7>{}; // bit offset: 0, bit width: 7, Port address
    constexpr auto HUBADDR = BitField<otg_hs_host_t, 7, 7>{}; // bit offset: 7, bit width: 7, Hub address
    constexpr auto XACTPOS = BitField<otg_hs_host_t, 14, 2>{}; // bit offset: 14, bit width: 2, XACTPOS
    constexpr auto COMPLSPLT = BitField<otg_hs_host_t, 16, 1>{}; // bit offset: 16, bit width: 1, Do complete split
    constexpr auto SPLITEN = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Split enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000124u, 0, READWRITE, decltype(PRTADDR), decltype(HUBADDR), decltype(XACTPOS), decltype(COMPLSPLT), decltype(SPLITEN)> OTG_HS_HCSPLT1; // OTG_HS host channel-1 split control register

    constexpr auto PRTADDR = BitField<otg_hs_host_t, 0, 7>{}; // bit offset: 0, bit width: 7, Port address
    constexpr auto HUBADDR = BitField<otg_hs_host_t, 7, 7>{}; // bit offset: 7, bit width: 7, Hub address
    constexpr auto XACTPOS = BitField<otg_hs_host_t, 14, 2>{}; // bit offset: 14, bit width: 2, XACTPOS
    constexpr auto COMPLSPLT = BitField<otg_hs_host_t, 16, 1>{}; // bit offset: 16, bit width: 1, Do complete split
    constexpr auto SPLITEN = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Split enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000144u, 0, READWRITE, decltype(PRTADDR), decltype(HUBADDR), decltype(XACTPOS), decltype(COMPLSPLT), decltype(SPLITEN)> OTG_HS_HCSPLT2; // OTG_HS host channel-2 split control register

    constexpr auto PRTADDR = BitField<otg_hs_host_t, 0, 7>{}; // bit offset: 0, bit width: 7, Port address
    constexpr auto HUBADDR = BitField<otg_hs_host_t, 7, 7>{}; // bit offset: 7, bit width: 7, Hub address
    constexpr auto XACTPOS = BitField<otg_hs_host_t, 14, 2>{}; // bit offset: 14, bit width: 2, XACTPOS
    constexpr auto COMPLSPLT = BitField<otg_hs_host_t, 16, 1>{}; // bit offset: 16, bit width: 1, Do complete split
    constexpr auto SPLITEN = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Split enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000164u, 0, READWRITE, decltype(PRTADDR), decltype(HUBADDR), decltype(XACTPOS), decltype(COMPLSPLT), decltype(SPLITEN)> OTG_HS_HCSPLT3; // OTG_HS host channel-3 split control register

    constexpr auto PRTADDR = BitField<otg_hs_host_t, 0, 7>{}; // bit offset: 0, bit width: 7, Port address
    constexpr auto HUBADDR = BitField<otg_hs_host_t, 7, 7>{}; // bit offset: 7, bit width: 7, Hub address
    constexpr auto XACTPOS = BitField<otg_hs_host_t, 14, 2>{}; // bit offset: 14, bit width: 2, XACTPOS
    constexpr auto COMPLSPLT = BitField<otg_hs_host_t, 16, 1>{}; // bit offset: 16, bit width: 1, Do complete split
    constexpr auto SPLITEN = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Split enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000184u, 0, READWRITE, decltype(PRTADDR), decltype(HUBADDR), decltype(XACTPOS), decltype(COMPLSPLT), decltype(SPLITEN)> OTG_HS_HCSPLT4; // OTG_HS host channel-4 split control register

    constexpr auto PRTADDR = BitField<otg_hs_host_t, 0, 7>{}; // bit offset: 0, bit width: 7, Port address
    constexpr auto HUBADDR = BitField<otg_hs_host_t, 7, 7>{}; // bit offset: 7, bit width: 7, Hub address
    constexpr auto XACTPOS = BitField<otg_hs_host_t, 14, 2>{}; // bit offset: 14, bit width: 2, XACTPOS
    constexpr auto COMPLSPLT = BitField<otg_hs_host_t, 16, 1>{}; // bit offset: 16, bit width: 1, Do complete split
    constexpr auto SPLITEN = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Split enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x000001a4u, 0, READWRITE, decltype(PRTADDR), decltype(HUBADDR), decltype(XACTPOS), decltype(COMPLSPLT), decltype(SPLITEN)> OTG_HS_HCSPLT5; // OTG_HS host channel-5 split control register

    constexpr auto PRTADDR = BitField<otg_hs_host_t, 0, 7>{}; // bit offset: 0, bit width: 7, Port address
    constexpr auto HUBADDR = BitField<otg_hs_host_t, 7, 7>{}; // bit offset: 7, bit width: 7, Hub address
    constexpr auto XACTPOS = BitField<otg_hs_host_t, 14, 2>{}; // bit offset: 14, bit width: 2, XACTPOS
    constexpr auto COMPLSPLT = BitField<otg_hs_host_t, 16, 1>{}; // bit offset: 16, bit width: 1, Do complete split
    constexpr auto SPLITEN = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Split enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x000001c4u, 0, READWRITE, decltype(PRTADDR), decltype(HUBADDR), decltype(XACTPOS), decltype(COMPLSPLT), decltype(SPLITEN)> OTG_HS_HCSPLT6; // OTG_HS host channel-6 split control register

    constexpr auto PRTADDR = BitField<otg_hs_host_t, 0, 7>{}; // bit offset: 0, bit width: 7, Port address
    constexpr auto HUBADDR = BitField<otg_hs_host_t, 7, 7>{}; // bit offset: 7, bit width: 7, Hub address
    constexpr auto XACTPOS = BitField<otg_hs_host_t, 14, 2>{}; // bit offset: 14, bit width: 2, XACTPOS
    constexpr auto COMPLSPLT = BitField<otg_hs_host_t, 16, 1>{}; // bit offset: 16, bit width: 1, Do complete split
    constexpr auto SPLITEN = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Split enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x000001e4u, 0, READWRITE, decltype(PRTADDR), decltype(HUBADDR), decltype(XACTPOS), decltype(COMPLSPLT), decltype(SPLITEN)> OTG_HS_HCSPLT7; // OTG_HS host channel-7 split control register

    constexpr auto PRTADDR = BitField<otg_hs_host_t, 0, 7>{}; // bit offset: 0, bit width: 7, Port address
    constexpr auto HUBADDR = BitField<otg_hs_host_t, 7, 7>{}; // bit offset: 7, bit width: 7, Hub address
    constexpr auto XACTPOS = BitField<otg_hs_host_t, 14, 2>{}; // bit offset: 14, bit width: 2, XACTPOS
    constexpr auto COMPLSPLT = BitField<otg_hs_host_t, 16, 1>{}; // bit offset: 16, bit width: 1, Do complete split
    constexpr auto SPLITEN = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Split enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000204u, 0, READWRITE, decltype(PRTADDR), decltype(HUBADDR), decltype(XACTPOS), decltype(COMPLSPLT), decltype(SPLITEN)> OTG_HS_HCSPLT8; // OTG_HS host channel-8 split control register

    constexpr auto PRTADDR = BitField<otg_hs_host_t, 0, 7>{}; // bit offset: 0, bit width: 7, Port address
    constexpr auto HUBADDR = BitField<otg_hs_host_t, 7, 7>{}; // bit offset: 7, bit width: 7, Hub address
    constexpr auto XACTPOS = BitField<otg_hs_host_t, 14, 2>{}; // bit offset: 14, bit width: 2, XACTPOS
    constexpr auto COMPLSPLT = BitField<otg_hs_host_t, 16, 1>{}; // bit offset: 16, bit width: 1, Do complete split
    constexpr auto SPLITEN = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Split enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000224u, 0, READWRITE, decltype(PRTADDR), decltype(HUBADDR), decltype(XACTPOS), decltype(COMPLSPLT), decltype(SPLITEN)> OTG_HS_HCSPLT9; // OTG_HS host channel-9 split control register

    constexpr auto PRTADDR = BitField<otg_hs_host_t, 0, 7>{}; // bit offset: 0, bit width: 7, Port address
    constexpr auto HUBADDR = BitField<otg_hs_host_t, 7, 7>{}; // bit offset: 7, bit width: 7, Hub address
    constexpr auto XACTPOS = BitField<otg_hs_host_t, 14, 2>{}; // bit offset: 14, bit width: 2, XACTPOS
    constexpr auto COMPLSPLT = BitField<otg_hs_host_t, 16, 1>{}; // bit offset: 16, bit width: 1, Do complete split
    constexpr auto SPLITEN = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Split enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000244u, 0, READWRITE, decltype(PRTADDR), decltype(HUBADDR), decltype(XACTPOS), decltype(COMPLSPLT), decltype(SPLITEN)> OTG_HS_HCSPLT10; // OTG_HS host channel-10 split control register

    constexpr auto PRTADDR = BitField<otg_hs_host_t, 0, 7>{}; // bit offset: 0, bit width: 7, Port address
    constexpr auto HUBADDR = BitField<otg_hs_host_t, 7, 7>{}; // bit offset: 7, bit width: 7, Hub address
    constexpr auto XACTPOS = BitField<otg_hs_host_t, 14, 2>{}; // bit offset: 14, bit width: 2, XACTPOS
    constexpr auto COMPLSPLT = BitField<otg_hs_host_t, 16, 1>{}; // bit offset: 16, bit width: 1, Do complete split
    constexpr auto SPLITEN = BitField<otg_hs_host_t, 31, 1>{}; // bit offset: 31, bit width: 1, Split enable
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000264u, 0, READWRITE, decltype(PRTADDR), decltype(HUBADDR), decltype(XACTPOS), decltype(COMPLSPLT), decltype(SPLITEN)> OTG_HS_HCSPLT11; // OTG_HS host channel-11 split control register

    constexpr auto XFRC = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed
    constexpr auto CHH = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALL = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt
    constexpr auto NAK = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt
    constexpr auto ACK = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, Response received interrupt
    constexpr auto TXERR = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error
    constexpr auto BBERR = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error
    constexpr auto FRMOR = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun
    constexpr auto DTERR = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000108u, 0, READWRITE, decltype(XFRC), decltype(CHH), decltype(AHBERR), decltype(STALL), decltype(NAK), decltype(ACK), decltype(NYET), decltype(TXERR), decltype(BBERR), decltype(FRMOR), decltype(DTERR)> OTG_HS_HCINT0; // OTG_HS host channel-11 interrupt register

    constexpr auto XFRC = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed
    constexpr auto CHH = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALL = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt
    constexpr auto NAK = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt
    constexpr auto ACK = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, Response received interrupt
    constexpr auto TXERR = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error
    constexpr auto BBERR = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error
    constexpr auto FRMOR = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun
    constexpr auto DTERR = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000128u, 0, READWRITE, decltype(XFRC), decltype(CHH), decltype(AHBERR), decltype(STALL), decltype(NAK), decltype(ACK), decltype(NYET), decltype(TXERR), decltype(BBERR), decltype(FRMOR), decltype(DTERR)> OTG_HS_HCINT1; // OTG_HS host channel-1 interrupt register

    constexpr auto XFRC = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed
    constexpr auto CHH = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALL = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt
    constexpr auto NAK = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt
    constexpr auto ACK = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, Response received interrupt
    constexpr auto TXERR = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error
    constexpr auto BBERR = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error
    constexpr auto FRMOR = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun
    constexpr auto DTERR = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000148u, 0, READWRITE, decltype(XFRC), decltype(CHH), decltype(AHBERR), decltype(STALL), decltype(NAK), decltype(ACK), decltype(NYET), decltype(TXERR), decltype(BBERR), decltype(FRMOR), decltype(DTERR)> OTG_HS_HCINT2; // OTG_HS host channel-2 interrupt register

    constexpr auto XFRC = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed
    constexpr auto CHH = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALL = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt
    constexpr auto NAK = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt
    constexpr auto ACK = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, Response received interrupt
    constexpr auto TXERR = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error
    constexpr auto BBERR = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error
    constexpr auto FRMOR = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun
    constexpr auto DTERR = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000168u, 0, READWRITE, decltype(XFRC), decltype(CHH), decltype(AHBERR), decltype(STALL), decltype(NAK), decltype(ACK), decltype(NYET), decltype(TXERR), decltype(BBERR), decltype(FRMOR), decltype(DTERR)> OTG_HS_HCINT3; // OTG_HS host channel-3 interrupt register

    constexpr auto XFRC = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed
    constexpr auto CHH = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALL = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt
    constexpr auto NAK = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt
    constexpr auto ACK = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, Response received interrupt
    constexpr auto TXERR = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error
    constexpr auto BBERR = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error
    constexpr auto FRMOR = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun
    constexpr auto DTERR = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000188u, 0, READWRITE, decltype(XFRC), decltype(CHH), decltype(AHBERR), decltype(STALL), decltype(NAK), decltype(ACK), decltype(NYET), decltype(TXERR), decltype(BBERR), decltype(FRMOR), decltype(DTERR)> OTG_HS_HCINT4; // OTG_HS host channel-4 interrupt register

    constexpr auto XFRC = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed
    constexpr auto CHH = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALL = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt
    constexpr auto NAK = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt
    constexpr auto ACK = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, Response received interrupt
    constexpr auto TXERR = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error
    constexpr auto BBERR = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error
    constexpr auto FRMOR = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun
    constexpr auto DTERR = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x000001a8u, 0, READWRITE, decltype(XFRC), decltype(CHH), decltype(AHBERR), decltype(STALL), decltype(NAK), decltype(ACK), decltype(NYET), decltype(TXERR), decltype(BBERR), decltype(FRMOR), decltype(DTERR)> OTG_HS_HCINT5; // OTG_HS host channel-5 interrupt register

    constexpr auto XFRC = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed
    constexpr auto CHH = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALL = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt
    constexpr auto NAK = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt
    constexpr auto ACK = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, Response received interrupt
    constexpr auto TXERR = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error
    constexpr auto BBERR = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error
    constexpr auto FRMOR = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun
    constexpr auto DTERR = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x000001c8u, 0, READWRITE, decltype(XFRC), decltype(CHH), decltype(AHBERR), decltype(STALL), decltype(NAK), decltype(ACK), decltype(NYET), decltype(TXERR), decltype(BBERR), decltype(FRMOR), decltype(DTERR)> OTG_HS_HCINT6; // OTG_HS host channel-6 interrupt register

    constexpr auto XFRC = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed
    constexpr auto CHH = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALL = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt
    constexpr auto NAK = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt
    constexpr auto ACK = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, Response received interrupt
    constexpr auto TXERR = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error
    constexpr auto BBERR = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error
    constexpr auto FRMOR = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun
    constexpr auto DTERR = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x000001e8u, 0, READWRITE, decltype(XFRC), decltype(CHH), decltype(AHBERR), decltype(STALL), decltype(NAK), decltype(ACK), decltype(NYET), decltype(TXERR), decltype(BBERR), decltype(FRMOR), decltype(DTERR)> OTG_HS_HCINT7; // OTG_HS host channel-7 interrupt register

    constexpr auto XFRC = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed
    constexpr auto CHH = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALL = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt
    constexpr auto NAK = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt
    constexpr auto ACK = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, Response received interrupt
    constexpr auto TXERR = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error
    constexpr auto BBERR = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error
    constexpr auto FRMOR = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun
    constexpr auto DTERR = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000208u, 0, READWRITE, decltype(XFRC), decltype(CHH), decltype(AHBERR), decltype(STALL), decltype(NAK), decltype(ACK), decltype(NYET), decltype(TXERR), decltype(BBERR), decltype(FRMOR), decltype(DTERR)> OTG_HS_HCINT8; // OTG_HS host channel-8 interrupt register

    constexpr auto XFRC = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed
    constexpr auto CHH = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALL = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt
    constexpr auto NAK = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt
    constexpr auto ACK = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, Response received interrupt
    constexpr auto TXERR = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error
    constexpr auto BBERR = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error
    constexpr auto FRMOR = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun
    constexpr auto DTERR = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000228u, 0, READWRITE, decltype(XFRC), decltype(CHH), decltype(AHBERR), decltype(STALL), decltype(NAK), decltype(ACK), decltype(NYET), decltype(TXERR), decltype(BBERR), decltype(FRMOR), decltype(DTERR)> OTG_HS_HCINT9; // OTG_HS host channel-9 interrupt register

    constexpr auto XFRC = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed
    constexpr auto CHH = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALL = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt
    constexpr auto NAK = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt
    constexpr auto ACK = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, Response received interrupt
    constexpr auto TXERR = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error
    constexpr auto BBERR = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error
    constexpr auto FRMOR = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun
    constexpr auto DTERR = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000248u, 0, READWRITE, decltype(XFRC), decltype(CHH), decltype(AHBERR), decltype(STALL), decltype(NAK), decltype(ACK), decltype(NYET), decltype(TXERR), decltype(BBERR), decltype(FRMOR), decltype(DTERR)> OTG_HS_HCINT10; // OTG_HS host channel-10 interrupt register

    constexpr auto XFRC = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed
    constexpr auto CHH = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALL = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt
    constexpr auto NAK = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt
    constexpr auto ACK = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, Response received interrupt
    constexpr auto TXERR = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error
    constexpr auto BBERR = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error
    constexpr auto FRMOR = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun
    constexpr auto DTERR = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000268u, 0, READWRITE, decltype(XFRC), decltype(CHH), decltype(AHBERR), decltype(STALL), decltype(NAK), decltype(ACK), decltype(NYET), decltype(TXERR), decltype(BBERR), decltype(FRMOR), decltype(DTERR)> OTG_HS_HCINT11; // OTG_HS host channel-11 interrupt register

    constexpr auto XFRCM = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed mask
    constexpr auto CHHM = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted mask
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALLM = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt mask
    constexpr auto NAKM = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt mask
    constexpr auto ACKM = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt mask
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, response received interrupt mask
    constexpr auto TXERRM = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error mask
    constexpr auto BBERRM = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error mask
    constexpr auto FRMORM = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun mask
    constexpr auto DTERRM = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error mask
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x0000010cu, 0, READWRITE, decltype(XFRCM), decltype(CHHM), decltype(AHBERR), decltype(STALLM), decltype(NAKM), decltype(ACKM), decltype(NYET), decltype(TXERRM), decltype(BBERRM), decltype(FRMORM), decltype(DTERRM)> OTG_HS_HCINTMSK0; // OTG_HS host channel-11 interrupt mask register

    constexpr auto XFRCM = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed mask
    constexpr auto CHHM = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted mask
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALLM = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt mask
    constexpr auto NAKM = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt mask
    constexpr auto ACKM = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt mask
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, response received interrupt mask
    constexpr auto TXERRM = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error mask
    constexpr auto BBERRM = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error mask
    constexpr auto FRMORM = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun mask
    constexpr auto DTERRM = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error mask
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x0000012cu, 0, READWRITE, decltype(XFRCM), decltype(CHHM), decltype(AHBERR), decltype(STALLM), decltype(NAKM), decltype(ACKM), decltype(NYET), decltype(TXERRM), decltype(BBERRM), decltype(FRMORM), decltype(DTERRM)> OTG_HS_HCINTMSK1; // OTG_HS host channel-1 interrupt mask register

    constexpr auto XFRCM = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed mask
    constexpr auto CHHM = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted mask
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALLM = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt mask
    constexpr auto NAKM = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt mask
    constexpr auto ACKM = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt mask
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, response received interrupt mask
    constexpr auto TXERRM = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error mask
    constexpr auto BBERRM = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error mask
    constexpr auto FRMORM = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun mask
    constexpr auto DTERRM = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error mask
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x0000014cu, 0, READWRITE, decltype(XFRCM), decltype(CHHM), decltype(AHBERR), decltype(STALLM), decltype(NAKM), decltype(ACKM), decltype(NYET), decltype(TXERRM), decltype(BBERRM), decltype(FRMORM), decltype(DTERRM)> OTG_HS_HCINTMSK2; // OTG_HS host channel-2 interrupt mask register

    constexpr auto XFRCM = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed mask
    constexpr auto CHHM = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted mask
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALLM = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt mask
    constexpr auto NAKM = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt mask
    constexpr auto ACKM = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt mask
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, response received interrupt mask
    constexpr auto TXERRM = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error mask
    constexpr auto BBERRM = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error mask
    constexpr auto FRMORM = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun mask
    constexpr auto DTERRM = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error mask
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x0000016cu, 0, READWRITE, decltype(XFRCM), decltype(CHHM), decltype(AHBERR), decltype(STALLM), decltype(NAKM), decltype(ACKM), decltype(NYET), decltype(TXERRM), decltype(BBERRM), decltype(FRMORM), decltype(DTERRM)> OTG_HS_HCINTMSK3; // OTG_HS host channel-3 interrupt mask register

    constexpr auto XFRCM = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed mask
    constexpr auto CHHM = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted mask
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALLM = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt mask
    constexpr auto NAKM = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt mask
    constexpr auto ACKM = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt mask
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, response received interrupt mask
    constexpr auto TXERRM = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error mask
    constexpr auto BBERRM = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error mask
    constexpr auto FRMORM = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun mask
    constexpr auto DTERRM = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error mask
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x0000018cu, 0, READWRITE, decltype(XFRCM), decltype(CHHM), decltype(AHBERR), decltype(STALLM), decltype(NAKM), decltype(ACKM), decltype(NYET), decltype(TXERRM), decltype(BBERRM), decltype(FRMORM), decltype(DTERRM)> OTG_HS_HCINTMSK4; // OTG_HS host channel-4 interrupt mask register

    constexpr auto XFRCM = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed mask
    constexpr auto CHHM = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted mask
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALLM = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt mask
    constexpr auto NAKM = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt mask
    constexpr auto ACKM = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt mask
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, response received interrupt mask
    constexpr auto TXERRM = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error mask
    constexpr auto BBERRM = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error mask
    constexpr auto FRMORM = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun mask
    constexpr auto DTERRM = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error mask
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x000001acu, 0, READWRITE, decltype(XFRCM), decltype(CHHM), decltype(AHBERR), decltype(STALLM), decltype(NAKM), decltype(ACKM), decltype(NYET), decltype(TXERRM), decltype(BBERRM), decltype(FRMORM), decltype(DTERRM)> OTG_HS_HCINTMSK5; // OTG_HS host channel-5 interrupt mask register

    constexpr auto XFRCM = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed mask
    constexpr auto CHHM = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted mask
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALLM = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt mask
    constexpr auto NAKM = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt mask
    constexpr auto ACKM = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt mask
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, response received interrupt mask
    constexpr auto TXERRM = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error mask
    constexpr auto BBERRM = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error mask
    constexpr auto FRMORM = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun mask
    constexpr auto DTERRM = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error mask
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x000001ccu, 0, READWRITE, decltype(XFRCM), decltype(CHHM), decltype(AHBERR), decltype(STALLM), decltype(NAKM), decltype(ACKM), decltype(NYET), decltype(TXERRM), decltype(BBERRM), decltype(FRMORM), decltype(DTERRM)> OTG_HS_HCINTMSK6; // OTG_HS host channel-6 interrupt mask register

    constexpr auto XFRCM = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed mask
    constexpr auto CHHM = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted mask
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALLM = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt mask
    constexpr auto NAKM = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt mask
    constexpr auto ACKM = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt mask
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, response received interrupt mask
    constexpr auto TXERRM = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error mask
    constexpr auto BBERRM = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error mask
    constexpr auto FRMORM = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun mask
    constexpr auto DTERRM = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error mask
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x000001ecu, 0, READWRITE, decltype(XFRCM), decltype(CHHM), decltype(AHBERR), decltype(STALLM), decltype(NAKM), decltype(ACKM), decltype(NYET), decltype(TXERRM), decltype(BBERRM), decltype(FRMORM), decltype(DTERRM)> OTG_HS_HCINTMSK7; // OTG_HS host channel-7 interrupt mask register

    constexpr auto XFRCM = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed mask
    constexpr auto CHHM = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted mask
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALLM = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt mask
    constexpr auto NAKM = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt mask
    constexpr auto ACKM = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt mask
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, response received interrupt mask
    constexpr auto TXERRM = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error mask
    constexpr auto BBERRM = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error mask
    constexpr auto FRMORM = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun mask
    constexpr auto DTERRM = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error mask
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x0000020cu, 0, READWRITE, decltype(XFRCM), decltype(CHHM), decltype(AHBERR), decltype(STALLM), decltype(NAKM), decltype(ACKM), decltype(NYET), decltype(TXERRM), decltype(BBERRM), decltype(FRMORM), decltype(DTERRM)> OTG_HS_HCINTMSK8; // OTG_HS host channel-8 interrupt mask register

    constexpr auto XFRCM = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed mask
    constexpr auto CHHM = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted mask
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALLM = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt mask
    constexpr auto NAKM = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt mask
    constexpr auto ACKM = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt mask
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, response received interrupt mask
    constexpr auto TXERRM = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error mask
    constexpr auto BBERRM = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error mask
    constexpr auto FRMORM = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun mask
    constexpr auto DTERRM = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error mask
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x0000022cu, 0, READWRITE, decltype(XFRCM), decltype(CHHM), decltype(AHBERR), decltype(STALLM), decltype(NAKM), decltype(ACKM), decltype(NYET), decltype(TXERRM), decltype(BBERRM), decltype(FRMORM), decltype(DTERRM)> OTG_HS_HCINTMSK9; // OTG_HS host channel-9 interrupt mask register

    constexpr auto XFRCM = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed mask
    constexpr auto CHHM = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted mask
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALLM = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt mask
    constexpr auto NAKM = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt mask
    constexpr auto ACKM = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt mask
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, response received interrupt mask
    constexpr auto TXERRM = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error mask
    constexpr auto BBERRM = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error mask
    constexpr auto FRMORM = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun mask
    constexpr auto DTERRM = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error mask
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x0000024cu, 0, READWRITE, decltype(XFRCM), decltype(CHHM), decltype(AHBERR), decltype(STALLM), decltype(NAKM), decltype(ACKM), decltype(NYET), decltype(TXERRM), decltype(BBERRM), decltype(FRMORM), decltype(DTERRM)> OTG_HS_HCINTMSK10; // OTG_HS host channel-10 interrupt mask register

    constexpr auto XFRCM = BitField<otg_hs_host_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed mask
    constexpr auto CHHM = BitField<otg_hs_host_t, 1, 1>{}; // bit offset: 1, bit width: 1, Channel halted mask
    constexpr auto AHBERR = BitField<otg_hs_host_t, 2, 1>{}; // bit offset: 2, bit width: 1, AHB error
    constexpr auto STALLM = BitField<otg_hs_host_t, 3, 1>{}; // bit offset: 3, bit width: 1, STALL response received interrupt mask
    constexpr auto NAKM = BitField<otg_hs_host_t, 4, 1>{}; // bit offset: 4, bit width: 1, NAK response received interrupt mask
    constexpr auto ACKM = BitField<otg_hs_host_t, 5, 1>{}; // bit offset: 5, bit width: 1, ACK response received/transmitted interrupt mask
    constexpr auto NYET = BitField<otg_hs_host_t, 6, 1>{}; // bit offset: 6, bit width: 1, response received interrupt mask
    constexpr auto TXERRM = BitField<otg_hs_host_t, 7, 1>{}; // bit offset: 7, bit width: 1, Transaction error mask
    constexpr auto BBERRM = BitField<otg_hs_host_t, 8, 1>{}; // bit offset: 8, bit width: 1, Babble error mask
    constexpr auto FRMORM = BitField<otg_hs_host_t, 9, 1>{}; // bit offset: 9, bit width: 1, Frame overrun mask
    constexpr auto DTERRM = BitField<otg_hs_host_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data toggle error mask
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x0000026cu, 0, READWRITE, decltype(XFRCM), decltype(CHHM), decltype(AHBERR), decltype(STALLM), decltype(NAKM), decltype(ACKM), decltype(NYET), decltype(TXERRM), decltype(BBERRM), decltype(FRMORM), decltype(DTERRM)> OTG_HS_HCINTMSK11; // OTG_HS host channel-11 interrupt mask register

    constexpr auto XFRSIZ = BitField<otg_hs_host_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_host_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto DPID = BitField<otg_hs_host_t, 29, 2>{}; // bit offset: 29, bit width: 2, Data PID
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000110u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(DPID)> OTG_HS_HCTSIZ0; // OTG_HS host channel-11 transfer size register

    constexpr auto XFRSIZ = BitField<otg_hs_host_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_host_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto DPID = BitField<otg_hs_host_t, 29, 2>{}; // bit offset: 29, bit width: 2, Data PID
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000130u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(DPID)> OTG_HS_HCTSIZ1; // OTG_HS host channel-1 transfer size register

    constexpr auto XFRSIZ = BitField<otg_hs_host_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_host_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto DPID = BitField<otg_hs_host_t, 29, 2>{}; // bit offset: 29, bit width: 2, Data PID
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000150u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(DPID)> OTG_HS_HCTSIZ2; // OTG_HS host channel-2 transfer size register

    constexpr auto XFRSIZ = BitField<otg_hs_host_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_host_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto DPID = BitField<otg_hs_host_t, 29, 2>{}; // bit offset: 29, bit width: 2, Data PID
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000170u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(DPID)> OTG_HS_HCTSIZ3; // OTG_HS host channel-3 transfer size register

    constexpr auto XFRSIZ = BitField<otg_hs_host_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_host_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto DPID = BitField<otg_hs_host_t, 29, 2>{}; // bit offset: 29, bit width: 2, Data PID
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000190u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(DPID)> OTG_HS_HCTSIZ4; // OTG_HS host channel-4 transfer size register

    constexpr auto XFRSIZ = BitField<otg_hs_host_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_host_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto DPID = BitField<otg_hs_host_t, 29, 2>{}; // bit offset: 29, bit width: 2, Data PID
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x000001b0u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(DPID)> OTG_HS_HCTSIZ5; // OTG_HS host channel-5 transfer size register

    constexpr auto XFRSIZ = BitField<otg_hs_host_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_host_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto DPID = BitField<otg_hs_host_t, 29, 2>{}; // bit offset: 29, bit width: 2, Data PID
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x000001d0u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(DPID)> OTG_HS_HCTSIZ6; // OTG_HS host channel-6 transfer size register

    constexpr auto XFRSIZ = BitField<otg_hs_host_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_host_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto DPID = BitField<otg_hs_host_t, 29, 2>{}; // bit offset: 29, bit width: 2, Data PID
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x000001f0u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(DPID)> OTG_HS_HCTSIZ7; // OTG_HS host channel-7 transfer size register

    constexpr auto XFRSIZ = BitField<otg_hs_host_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_host_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto DPID = BitField<otg_hs_host_t, 29, 2>{}; // bit offset: 29, bit width: 2, Data PID
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000210u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(DPID)> OTG_HS_HCTSIZ8; // OTG_HS host channel-8 transfer size register

    constexpr auto XFRSIZ = BitField<otg_hs_host_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_host_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto DPID = BitField<otg_hs_host_t, 29, 2>{}; // bit offset: 29, bit width: 2, Data PID
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000230u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(DPID)> OTG_HS_HCTSIZ9; // OTG_HS host channel-9 transfer size register

    constexpr auto XFRSIZ = BitField<otg_hs_host_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_host_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto DPID = BitField<otg_hs_host_t, 29, 2>{}; // bit offset: 29, bit width: 2, Data PID
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000250u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(DPID)> OTG_HS_HCTSIZ10; // OTG_HS host channel-10 transfer size register

    constexpr auto XFRSIZ = BitField<otg_hs_host_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_host_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto DPID = BitField<otg_hs_host_t, 29, 2>{}; // bit offset: 29, bit width: 2, Data PID
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000270u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(DPID)> OTG_HS_HCTSIZ11; // OTG_HS host channel-11 transfer size register

    constexpr auto DMAADDR = BitField<otg_hs_host_t, 0, 32>{}; // bit offset: 0, bit width: 32, DMA address
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000114u, 0, READWRITE, decltype(DMAADDR)> OTG_HS_HCDMA0; // OTG_HS host channel-0 DMA address register

    constexpr auto DMAADDR = BitField<otg_hs_host_t, 0, 32>{}; // bit offset: 0, bit width: 32, DMA address
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000134u, 0, READWRITE, decltype(DMAADDR)> OTG_HS_HCDMA1; // OTG_HS host channel-1 DMA address register

    constexpr auto DMAADDR = BitField<otg_hs_host_t, 0, 32>{}; // bit offset: 0, bit width: 32, DMA address
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000154u, 0, READWRITE, decltype(DMAADDR)> OTG_HS_HCDMA2; // OTG_HS host channel-2 DMA address register

    constexpr auto DMAADDR = BitField<otg_hs_host_t, 0, 32>{}; // bit offset: 0, bit width: 32, DMA address
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000174u, 0, READWRITE, decltype(DMAADDR)> OTG_HS_HCDMA3; // OTG_HS host channel-3 DMA address register

    constexpr auto DMAADDR = BitField<otg_hs_host_t, 0, 32>{}; // bit offset: 0, bit width: 32, DMA address
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000194u, 0, READWRITE, decltype(DMAADDR)> OTG_HS_HCDMA4; // OTG_HS host channel-4 DMA address register

    constexpr auto DMAADDR = BitField<otg_hs_host_t, 0, 32>{}; // bit offset: 0, bit width: 32, DMA address
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x000001b4u, 0, READWRITE, decltype(DMAADDR)> OTG_HS_HCDMA5; // OTG_HS host channel-5 DMA address register

    constexpr auto DMAADDR = BitField<otg_hs_host_t, 0, 32>{}; // bit offset: 0, bit width: 32, DMA address
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x000001d4u, 0, READWRITE, decltype(DMAADDR)> OTG_HS_HCDMA6; // OTG_HS host channel-6 DMA address register

    constexpr auto DMAADDR = BitField<otg_hs_host_t, 0, 32>{}; // bit offset: 0, bit width: 32, DMA address
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x000001f4u, 0, READWRITE, decltype(DMAADDR)> OTG_HS_HCDMA7; // OTG_HS host channel-7 DMA address register

    constexpr auto DMAADDR = BitField<otg_hs_host_t, 0, 32>{}; // bit offset: 0, bit width: 32, DMA address
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000214u, 0, READWRITE, decltype(DMAADDR)> OTG_HS_HCDMA8; // OTG_HS host channel-8 DMA address register

    constexpr auto DMAADDR = BitField<otg_hs_host_t, 0, 32>{}; // bit offset: 0, bit width: 32, DMA address
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000234u, 0, READWRITE, decltype(DMAADDR)> OTG_HS_HCDMA9; // OTG_HS host channel-9 DMA address register

    constexpr auto DMAADDR = BitField<otg_hs_host_t, 0, 32>{}; // bit offset: 0, bit width: 32, DMA address
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000254u, 0, READWRITE, decltype(DMAADDR)> OTG_HS_HCDMA10; // OTG_HS host channel-10 DMA address register

    constexpr auto DMAADDR = BitField<otg_hs_host_t, 0, 32>{}; // bit offset: 0, bit width: 32, DMA address
    static Register<std::uint32_t, OTG_HS_HOST_BASE_ADDRESS + 0x00000274u, 0, READWRITE, decltype(DMAADDR)> OTG_HS_HCDMA11; // OTG_HS host channel-11 DMA address register

} // namespace OTG_HS_HOST