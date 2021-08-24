#include <Register.hpp>




namespace OTG_FS_DEVICE
{
    struct otg_fs_device_t{};

    constexpr std::uint32_t OTG_FS_DEVICE_BASE_ADDRESS = 0x50000800u;

    constexpr auto DSPD = BitField<otg_fs_device_t, 0, 2>{}; // bit offset: 0, bit width: 2, Device speed
    constexpr auto NZLSOHSK = BitField<otg_fs_device_t, 2, 1>{}; // bit offset: 2, bit width: 1, Non-zero-length status OUT handshake
    constexpr auto DAD = BitField<otg_fs_device_t, 4, 7>{}; // bit offset: 4, bit width: 7, Device address
    constexpr auto PFIVL = BitField<otg_fs_device_t, 11, 2>{}; // bit offset: 11, bit width: 2, Periodic frame interval
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000000u, 35651584, READWRITE, decltype(DSPD), decltype(NZLSOHSK), decltype(DAD), decltype(PFIVL)> FS_DCFG; // OTG_FS device configuration register (OTG_FS_DCFG)

    constexpr auto RWUSIG = BitField<otg_fs_device_t, 0, 1, READWRITE>{}; // bit offset: 0, bit width: 1, Remote wakeup signaling
    constexpr auto SDIS = BitField<otg_fs_device_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, Soft disconnect
    constexpr auto GINSTS = BitField<otg_fs_device_t, 2, 1, READONLY>{}; // bit offset: 2, bit width: 1, Global IN NAK status
    constexpr auto GONSTS = BitField<otg_fs_device_t, 3, 1, READONLY>{}; // bit offset: 3, bit width: 1, Global OUT NAK status
    constexpr auto TCTL = BitField<otg_fs_device_t, 4, 3, READWRITE>{}; // bit offset: 4, bit width: 3, Test control
    constexpr auto SGINAK = BitField<otg_fs_device_t, 7, 1, READWRITE>{}; // bit offset: 7, bit width: 1, Set global IN NAK
    constexpr auto CGINAK = BitField<otg_fs_device_t, 8, 1, READWRITE>{}; // bit offset: 8, bit width: 1, Clear global IN NAK
    constexpr auto SGONAK = BitField<otg_fs_device_t, 9, 1, READWRITE>{}; // bit offset: 9, bit width: 1, Set global OUT NAK
    constexpr auto CGONAK = BitField<otg_fs_device_t, 10, 1, READWRITE>{}; // bit offset: 10, bit width: 1, Clear global OUT NAK
    constexpr auto POPRGDNE = BitField<otg_fs_device_t, 11, 1, READWRITE>{}; // bit offset: 11, bit width: 1, Power-on programming done
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000004u, 0, READWRITE, decltype(RWUSIG), decltype(SDIS), decltype(GINSTS), decltype(GONSTS), decltype(TCTL), decltype(SGINAK), decltype(CGINAK), decltype(SGONAK), decltype(CGONAK), decltype(POPRGDNE)> FS_DCTL; // OTG_FS device control register (OTG_FS_DCTL)

    constexpr auto SUSPSTS = BitField<otg_fs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, Suspend status
    constexpr auto ENUMSPD = BitField<otg_fs_device_t, 1, 2>{}; // bit offset: 1, bit width: 2, Enumerated speed
    constexpr auto EERR = BitField<otg_fs_device_t, 3, 1>{}; // bit offset: 3, bit width: 1, Erratic error
    constexpr auto FNSOF = BitField<otg_fs_device_t, 8, 14>{}; // bit offset: 8, bit width: 14, Frame number of the received SOF
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000008u, 16, READONLY, decltype(SUSPSTS), decltype(ENUMSPD), decltype(EERR), decltype(FNSOF)> FS_DSTS; // OTG_FS device status register (OTG_FS_DSTS)

    constexpr auto XFRCM = BitField<otg_fs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt mask
    constexpr auto EPDM = BitField<otg_fs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt mask
    constexpr auto TOM = BitField<otg_fs_device_t, 3, 1>{}; // bit offset: 3, bit width: 1, Timeout condition mask (Non-isochronous endpoints)
    constexpr auto ITTXFEMSK = BitField<otg_fs_device_t, 4, 1>{}; // bit offset: 4, bit width: 1, IN token received when TxFIFO empty mask
    constexpr auto INEPNMM = BitField<otg_fs_device_t, 5, 1>{}; // bit offset: 5, bit width: 1, IN token received with EP mismatch mask
    constexpr auto INEPNEM = BitField<otg_fs_device_t, 6, 1>{}; // bit offset: 6, bit width: 1, IN endpoint NAK effective mask
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000010u, 0, READWRITE, decltype(XFRCM), decltype(EPDM), decltype(TOM), decltype(ITTXFEMSK), decltype(INEPNMM), decltype(INEPNEM)> FS_DIEPMSK; // OTG_FS device IN endpoint common interrupt mask register (OTG_FS_DIEPMSK)

    constexpr auto XFRCM = BitField<otg_fs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt mask
    constexpr auto EPDM = BitField<otg_fs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt mask
    constexpr auto STUPM = BitField<otg_fs_device_t, 3, 1>{}; // bit offset: 3, bit width: 1, SETUP phase done mask
    constexpr auto OTEPDM = BitField<otg_fs_device_t, 4, 1>{}; // bit offset: 4, bit width: 1, OUT token received when endpoint disabled mask
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000014u, 0, READWRITE, decltype(XFRCM), decltype(EPDM), decltype(STUPM), decltype(OTEPDM)> FS_DOEPMSK; // OTG_FS device OUT endpoint common interrupt mask register (OTG_FS_DOEPMSK)

    constexpr auto IEPINT = BitField<otg_fs_device_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN endpoint interrupt bits
    constexpr auto OEPINT = BitField<otg_fs_device_t, 16, 16>{}; // bit offset: 16, bit width: 16, OUT endpoint interrupt bits
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000018u, 0, READONLY, decltype(IEPINT), decltype(OEPINT)> FS_DAINT; // OTG_FS device all endpoints interrupt register (OTG_FS_DAINT)

    constexpr auto IEPM = BitField<otg_fs_device_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN EP interrupt mask bits
    constexpr auto OEPINT = BitField<otg_fs_device_t, 16, 16>{}; // bit offset: 16, bit width: 16, OUT endpoint interrupt bits
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x0000001cu, 0, READWRITE, decltype(IEPM), decltype(OEPINT)> FS_DAINTMSK; // OTG_FS all endpoints interrupt mask register (OTG_FS_DAINTMSK)

    constexpr auto VBUSDT = BitField<otg_fs_device_t, 0, 16>{}; // bit offset: 0, bit width: 16, Device VBUS discharge time
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000028u, 6103, READWRITE, decltype(VBUSDT)> DVBUSDIS; // OTG_FS device VBUS discharge time register

    constexpr auto DVBUSP = BitField<otg_fs_device_t, 0, 12>{}; // bit offset: 0, bit width: 12, Device VBUS pulsing time
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x0000002cu, 1464, READWRITE, decltype(DVBUSP)> DVBUSPULSE; // OTG_FS device VBUS pulsing time register

    constexpr auto INEPTXFEM = BitField<otg_fs_device_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN EP Tx FIFO empty interrupt mask bits
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000034u, 0, READWRITE, decltype(INEPTXFEM)> DIEPEMPMSK; // OTG_FS device IN endpoint FIFO empty interrupt mask register

    constexpr auto MPSIZ = BitField<otg_fs_device_t, 0, 2, READWRITE>{}; // bit offset: 0, bit width: 2, Maximum packet size
    constexpr auto USBAEP = BitField<otg_fs_device_t, 15, 1, READONLY>{}; // bit offset: 15, bit width: 1, USB active endpoint
    constexpr auto NAKSTS = BitField<otg_fs_device_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, NAK status
    constexpr auto EPTYP = BitField<otg_fs_device_t, 18, 2, READONLY>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto STALL = BitField<otg_fs_device_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, STALL handshake
    constexpr auto TXFNUM = BitField<otg_fs_device_t, 22, 4, READWRITE>{}; // bit offset: 22, bit width: 4, TxFIFO number
    constexpr auto CNAK = BitField<otg_fs_device_t, 26, 1, WRITEONLY>{}; // bit offset: 26, bit width: 1, Clear NAK
    constexpr auto SNAK = BitField<otg_fs_device_t, 27, 1, WRITEONLY>{}; // bit offset: 27, bit width: 1, Set NAK
    constexpr auto EPDIS = BitField<otg_fs_device_t, 30, 1, READONLY>{}; // bit offset: 30, bit width: 1, Endpoint disable
    constexpr auto EPENA = BitField<otg_fs_device_t, 31, 1, READONLY>{}; // bit offset: 31, bit width: 1, Endpoint enable
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000100u, 0, READWRITE, decltype(MPSIZ), decltype(USBAEP), decltype(NAKSTS), decltype(EPTYP), decltype(STALL), decltype(TXFNUM), decltype(CNAK), decltype(SNAK), decltype(EPDIS), decltype(EPENA)> FS_DIEPCTL0; // OTG_FS device control IN endpoint 0 control register (OTG_FS_DIEPCTL0)

    constexpr auto MPSIZ = BitField<otg_fs_device_t, 0, 11, READWRITE>{}; // bit offset: 0, bit width: 11, MPSIZ
    constexpr auto USBAEP = BitField<otg_fs_device_t, 15, 1, READWRITE>{}; // bit offset: 15, bit width: 1, USBAEP
    constexpr auto EONUM_DPID = BitField<otg_fs_device_t, 16, 1, READONLY>{}; // bit offset: 16, bit width: 1, EONUM/DPID
    constexpr auto NAKSTS = BitField<otg_fs_device_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, NAKSTS
    constexpr auto EPTYP = BitField<otg_fs_device_t, 18, 2, READWRITE>{}; // bit offset: 18, bit width: 2, EPTYP
    constexpr auto Stall = BitField<otg_fs_device_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, Stall
    constexpr auto TXFNUM = BitField<otg_fs_device_t, 22, 4, READWRITE>{}; // bit offset: 22, bit width: 4, TXFNUM
    constexpr auto CNAK = BitField<otg_fs_device_t, 26, 1, WRITEONLY>{}; // bit offset: 26, bit width: 1, CNAK
    constexpr auto SNAK = BitField<otg_fs_device_t, 27, 1, WRITEONLY>{}; // bit offset: 27, bit width: 1, SNAK
    constexpr auto SD0PID_SEVNFRM = BitField<otg_fs_device_t, 28, 1, WRITEONLY>{}; // bit offset: 28, bit width: 1, SD0PID/SEVNFRM
    constexpr auto SODDFRM_SD1PID = BitField<otg_fs_device_t, 29, 1, WRITEONLY>{}; // bit offset: 29, bit width: 1, SODDFRM/SD1PID
    constexpr auto EPDIS = BitField<otg_fs_device_t, 30, 1, READWRITE>{}; // bit offset: 30, bit width: 1, EPDIS
    constexpr auto EPENA = BitField<otg_fs_device_t, 31, 1, READWRITE>{}; // bit offset: 31, bit width: 1, EPENA
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000120u, 0, READWRITE, decltype(MPSIZ), decltype(USBAEP), decltype(EONUM_DPID), decltype(NAKSTS), decltype(EPTYP), decltype(Stall), decltype(TXFNUM), decltype(CNAK), decltype(SNAK), decltype(SD0PID_SEVNFRM), decltype(SODDFRM_SD1PID), decltype(EPDIS), decltype(EPENA)> DIEPCTL1; // OTG device endpoint-1 control register

    constexpr auto MPSIZ = BitField<otg_fs_device_t, 0, 11, READWRITE>{}; // bit offset: 0, bit width: 11, MPSIZ
    constexpr auto USBAEP = BitField<otg_fs_device_t, 15, 1, READWRITE>{}; // bit offset: 15, bit width: 1, USBAEP
    constexpr auto EONUM_DPID = BitField<otg_fs_device_t, 16, 1, READONLY>{}; // bit offset: 16, bit width: 1, EONUM/DPID
    constexpr auto NAKSTS = BitField<otg_fs_device_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, NAKSTS
    constexpr auto EPTYP = BitField<otg_fs_device_t, 18, 2, READWRITE>{}; // bit offset: 18, bit width: 2, EPTYP
    constexpr auto Stall = BitField<otg_fs_device_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, Stall
    constexpr auto TXFNUM = BitField<otg_fs_device_t, 22, 4, READWRITE>{}; // bit offset: 22, bit width: 4, TXFNUM
    constexpr auto CNAK = BitField<otg_fs_device_t, 26, 1, WRITEONLY>{}; // bit offset: 26, bit width: 1, CNAK
    constexpr auto SNAK = BitField<otg_fs_device_t, 27, 1, WRITEONLY>{}; // bit offset: 27, bit width: 1, SNAK
    constexpr auto SD0PID_SEVNFRM = BitField<otg_fs_device_t, 28, 1, WRITEONLY>{}; // bit offset: 28, bit width: 1, SD0PID/SEVNFRM
    constexpr auto SODDFRM = BitField<otg_fs_device_t, 29, 1, WRITEONLY>{}; // bit offset: 29, bit width: 1, SODDFRM
    constexpr auto EPDIS = BitField<otg_fs_device_t, 30, 1, READWRITE>{}; // bit offset: 30, bit width: 1, EPDIS
    constexpr auto EPENA = BitField<otg_fs_device_t, 31, 1, READWRITE>{}; // bit offset: 31, bit width: 1, EPENA
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000140u, 0, READWRITE, decltype(MPSIZ), decltype(USBAEP), decltype(EONUM_DPID), decltype(NAKSTS), decltype(EPTYP), decltype(Stall), decltype(TXFNUM), decltype(CNAK), decltype(SNAK), decltype(SD0PID_SEVNFRM), decltype(SODDFRM), decltype(EPDIS), decltype(EPENA)> DIEPCTL2; // OTG device endpoint-2 control register

    constexpr auto MPSIZ = BitField<otg_fs_device_t, 0, 11, READWRITE>{}; // bit offset: 0, bit width: 11, MPSIZ
    constexpr auto USBAEP = BitField<otg_fs_device_t, 15, 1, READWRITE>{}; // bit offset: 15, bit width: 1, USBAEP
    constexpr auto EONUM_DPID = BitField<otg_fs_device_t, 16, 1, READONLY>{}; // bit offset: 16, bit width: 1, EONUM/DPID
    constexpr auto NAKSTS = BitField<otg_fs_device_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, NAKSTS
    constexpr auto EPTYP = BitField<otg_fs_device_t, 18, 2, READWRITE>{}; // bit offset: 18, bit width: 2, EPTYP
    constexpr auto Stall = BitField<otg_fs_device_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, Stall
    constexpr auto TXFNUM = BitField<otg_fs_device_t, 22, 4, READWRITE>{}; // bit offset: 22, bit width: 4, TXFNUM
    constexpr auto CNAK = BitField<otg_fs_device_t, 26, 1, WRITEONLY>{}; // bit offset: 26, bit width: 1, CNAK
    constexpr auto SNAK = BitField<otg_fs_device_t, 27, 1, WRITEONLY>{}; // bit offset: 27, bit width: 1, SNAK
    constexpr auto SD0PID_SEVNFRM = BitField<otg_fs_device_t, 28, 1, WRITEONLY>{}; // bit offset: 28, bit width: 1, SD0PID/SEVNFRM
    constexpr auto SODDFRM = BitField<otg_fs_device_t, 29, 1, WRITEONLY>{}; // bit offset: 29, bit width: 1, SODDFRM
    constexpr auto EPDIS = BitField<otg_fs_device_t, 30, 1, READWRITE>{}; // bit offset: 30, bit width: 1, EPDIS
    constexpr auto EPENA = BitField<otg_fs_device_t, 31, 1, READWRITE>{}; // bit offset: 31, bit width: 1, EPENA
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000160u, 0, READWRITE, decltype(MPSIZ), decltype(USBAEP), decltype(EONUM_DPID), decltype(NAKSTS), decltype(EPTYP), decltype(Stall), decltype(TXFNUM), decltype(CNAK), decltype(SNAK), decltype(SD0PID_SEVNFRM), decltype(SODDFRM), decltype(EPDIS), decltype(EPENA)> DIEPCTL3; // OTG device endpoint-3 control register

    constexpr auto MPSIZ = BitField<otg_fs_device_t, 0, 2, READONLY>{}; // bit offset: 0, bit width: 2, MPSIZ
    constexpr auto USBAEP = BitField<otg_fs_device_t, 15, 1, READONLY>{}; // bit offset: 15, bit width: 1, USBAEP
    constexpr auto NAKSTS = BitField<otg_fs_device_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, NAKSTS
    constexpr auto EPTYP = BitField<otg_fs_device_t, 18, 2, READONLY>{}; // bit offset: 18, bit width: 2, EPTYP
    constexpr auto SNPM = BitField<otg_fs_device_t, 20, 1, READWRITE>{}; // bit offset: 20, bit width: 1, SNPM
    constexpr auto Stall = BitField<otg_fs_device_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, Stall
    constexpr auto CNAK = BitField<otg_fs_device_t, 26, 1, WRITEONLY>{}; // bit offset: 26, bit width: 1, CNAK
    constexpr auto SNAK = BitField<otg_fs_device_t, 27, 1, WRITEONLY>{}; // bit offset: 27, bit width: 1, SNAK
    constexpr auto EPDIS = BitField<otg_fs_device_t, 30, 1, READONLY>{}; // bit offset: 30, bit width: 1, EPDIS
    constexpr auto EPENA = BitField<otg_fs_device_t, 31, 1, WRITEONLY>{}; // bit offset: 31, bit width: 1, EPENA
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000300u, 32768, READWRITE, decltype(MPSIZ), decltype(USBAEP), decltype(NAKSTS), decltype(EPTYP), decltype(SNPM), decltype(Stall), decltype(CNAK), decltype(SNAK), decltype(EPDIS), decltype(EPENA)> DOEPCTL0; // device endpoint-0 control register

    constexpr auto MPSIZ = BitField<otg_fs_device_t, 0, 11, READWRITE>{}; // bit offset: 0, bit width: 11, MPSIZ
    constexpr auto USBAEP = BitField<otg_fs_device_t, 15, 1, READWRITE>{}; // bit offset: 15, bit width: 1, USBAEP
    constexpr auto EONUM_DPID = BitField<otg_fs_device_t, 16, 1, READONLY>{}; // bit offset: 16, bit width: 1, EONUM/DPID
    constexpr auto NAKSTS = BitField<otg_fs_device_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, NAKSTS
    constexpr auto EPTYP = BitField<otg_fs_device_t, 18, 2, READWRITE>{}; // bit offset: 18, bit width: 2, EPTYP
    constexpr auto SNPM = BitField<otg_fs_device_t, 20, 1, READWRITE>{}; // bit offset: 20, bit width: 1, SNPM
    constexpr auto Stall = BitField<otg_fs_device_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, Stall
    constexpr auto CNAK = BitField<otg_fs_device_t, 26, 1, WRITEONLY>{}; // bit offset: 26, bit width: 1, CNAK
    constexpr auto SNAK = BitField<otg_fs_device_t, 27, 1, WRITEONLY>{}; // bit offset: 27, bit width: 1, SNAK
    constexpr auto SD0PID_SEVNFRM = BitField<otg_fs_device_t, 28, 1, WRITEONLY>{}; // bit offset: 28, bit width: 1, SD0PID/SEVNFRM
    constexpr auto SODDFRM = BitField<otg_fs_device_t, 29, 1, WRITEONLY>{}; // bit offset: 29, bit width: 1, SODDFRM
    constexpr auto EPDIS = BitField<otg_fs_device_t, 30, 1, READWRITE>{}; // bit offset: 30, bit width: 1, EPDIS
    constexpr auto EPENA = BitField<otg_fs_device_t, 31, 1, READWRITE>{}; // bit offset: 31, bit width: 1, EPENA
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000320u, 0, READWRITE, decltype(MPSIZ), decltype(USBAEP), decltype(EONUM_DPID), decltype(NAKSTS), decltype(EPTYP), decltype(SNPM), decltype(Stall), decltype(CNAK), decltype(SNAK), decltype(SD0PID_SEVNFRM), decltype(SODDFRM), decltype(EPDIS), decltype(EPENA)> DOEPCTL1; // device endpoint-1 control register

    constexpr auto MPSIZ = BitField<otg_fs_device_t, 0, 11, READWRITE>{}; // bit offset: 0, bit width: 11, MPSIZ
    constexpr auto USBAEP = BitField<otg_fs_device_t, 15, 1, READWRITE>{}; // bit offset: 15, bit width: 1, USBAEP
    constexpr auto EONUM_DPID = BitField<otg_fs_device_t, 16, 1, READONLY>{}; // bit offset: 16, bit width: 1, EONUM/DPID
    constexpr auto NAKSTS = BitField<otg_fs_device_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, NAKSTS
    constexpr auto EPTYP = BitField<otg_fs_device_t, 18, 2, READWRITE>{}; // bit offset: 18, bit width: 2, EPTYP
    constexpr auto SNPM = BitField<otg_fs_device_t, 20, 1, READWRITE>{}; // bit offset: 20, bit width: 1, SNPM
    constexpr auto Stall = BitField<otg_fs_device_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, Stall
    constexpr auto CNAK = BitField<otg_fs_device_t, 26, 1, WRITEONLY>{}; // bit offset: 26, bit width: 1, CNAK
    constexpr auto SNAK = BitField<otg_fs_device_t, 27, 1, WRITEONLY>{}; // bit offset: 27, bit width: 1, SNAK
    constexpr auto SD0PID_SEVNFRM = BitField<otg_fs_device_t, 28, 1, WRITEONLY>{}; // bit offset: 28, bit width: 1, SD0PID/SEVNFRM
    constexpr auto SODDFRM = BitField<otg_fs_device_t, 29, 1, WRITEONLY>{}; // bit offset: 29, bit width: 1, SODDFRM
    constexpr auto EPDIS = BitField<otg_fs_device_t, 30, 1, READWRITE>{}; // bit offset: 30, bit width: 1, EPDIS
    constexpr auto EPENA = BitField<otg_fs_device_t, 31, 1, READWRITE>{}; // bit offset: 31, bit width: 1, EPENA
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000340u, 0, READWRITE, decltype(MPSIZ), decltype(USBAEP), decltype(EONUM_DPID), decltype(NAKSTS), decltype(EPTYP), decltype(SNPM), decltype(Stall), decltype(CNAK), decltype(SNAK), decltype(SD0PID_SEVNFRM), decltype(SODDFRM), decltype(EPDIS), decltype(EPENA)> DOEPCTL2; // device endpoint-2 control register

    constexpr auto MPSIZ = BitField<otg_fs_device_t, 0, 11, READWRITE>{}; // bit offset: 0, bit width: 11, MPSIZ
    constexpr auto USBAEP = BitField<otg_fs_device_t, 15, 1, READWRITE>{}; // bit offset: 15, bit width: 1, USBAEP
    constexpr auto EONUM_DPID = BitField<otg_fs_device_t, 16, 1, READONLY>{}; // bit offset: 16, bit width: 1, EONUM/DPID
    constexpr auto NAKSTS = BitField<otg_fs_device_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, NAKSTS
    constexpr auto EPTYP = BitField<otg_fs_device_t, 18, 2, READWRITE>{}; // bit offset: 18, bit width: 2, EPTYP
    constexpr auto SNPM = BitField<otg_fs_device_t, 20, 1, READWRITE>{}; // bit offset: 20, bit width: 1, SNPM
    constexpr auto Stall = BitField<otg_fs_device_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, Stall
    constexpr auto CNAK = BitField<otg_fs_device_t, 26, 1, WRITEONLY>{}; // bit offset: 26, bit width: 1, CNAK
    constexpr auto SNAK = BitField<otg_fs_device_t, 27, 1, WRITEONLY>{}; // bit offset: 27, bit width: 1, SNAK
    constexpr auto SD0PID_SEVNFRM = BitField<otg_fs_device_t, 28, 1, WRITEONLY>{}; // bit offset: 28, bit width: 1, SD0PID/SEVNFRM
    constexpr auto SODDFRM = BitField<otg_fs_device_t, 29, 1, WRITEONLY>{}; // bit offset: 29, bit width: 1, SODDFRM
    constexpr auto EPDIS = BitField<otg_fs_device_t, 30, 1, READWRITE>{}; // bit offset: 30, bit width: 1, EPDIS
    constexpr auto EPENA = BitField<otg_fs_device_t, 31, 1, READWRITE>{}; // bit offset: 31, bit width: 1, EPENA
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000360u, 0, READWRITE, decltype(MPSIZ), decltype(USBAEP), decltype(EONUM_DPID), decltype(NAKSTS), decltype(EPTYP), decltype(SNPM), decltype(Stall), decltype(CNAK), decltype(SNAK), decltype(SD0PID_SEVNFRM), decltype(SODDFRM), decltype(EPDIS), decltype(EPENA)> DOEPCTL3; // device endpoint-3 control register

    constexpr auto XFRC = BitField<otg_fs_device_t, 0, 1, READWRITE>{}; // bit offset: 0, bit width: 1, XFRC
    constexpr auto EPDISD = BitField<otg_fs_device_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, EPDISD
    constexpr auto TOC = BitField<otg_fs_device_t, 3, 1, READWRITE>{}; // bit offset: 3, bit width: 1, TOC
    constexpr auto ITTXFE = BitField<otg_fs_device_t, 4, 1, READWRITE>{}; // bit offset: 4, bit width: 1, ITTXFE
    constexpr auto INEPNE = BitField<otg_fs_device_t, 6, 1, READWRITE>{}; // bit offset: 6, bit width: 1, INEPNE
    constexpr auto TXFE = BitField<otg_fs_device_t, 7, 1, READONLY>{}; // bit offset: 7, bit width: 1, TXFE
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000108u, 128, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(TOC), decltype(ITTXFE), decltype(INEPNE), decltype(TXFE)> DIEPINT0; // device endpoint-x interrupt register

    constexpr auto XFRC = BitField<otg_fs_device_t, 0, 1, READWRITE>{}; // bit offset: 0, bit width: 1, XFRC
    constexpr auto EPDISD = BitField<otg_fs_device_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, EPDISD
    constexpr auto TOC = BitField<otg_fs_device_t, 3, 1, READWRITE>{}; // bit offset: 3, bit width: 1, TOC
    constexpr auto ITTXFE = BitField<otg_fs_device_t, 4, 1, READWRITE>{}; // bit offset: 4, bit width: 1, ITTXFE
    constexpr auto INEPNE = BitField<otg_fs_device_t, 6, 1, READWRITE>{}; // bit offset: 6, bit width: 1, INEPNE
    constexpr auto TXFE = BitField<otg_fs_device_t, 7, 1, READONLY>{}; // bit offset: 7, bit width: 1, TXFE
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000128u, 128, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(TOC), decltype(ITTXFE), decltype(INEPNE), decltype(TXFE)> DIEPINT1; // device endpoint-1 interrupt register

    constexpr auto XFRC = BitField<otg_fs_device_t, 0, 1, READWRITE>{}; // bit offset: 0, bit width: 1, XFRC
    constexpr auto EPDISD = BitField<otg_fs_device_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, EPDISD
    constexpr auto TOC = BitField<otg_fs_device_t, 3, 1, READWRITE>{}; // bit offset: 3, bit width: 1, TOC
    constexpr auto ITTXFE = BitField<otg_fs_device_t, 4, 1, READWRITE>{}; // bit offset: 4, bit width: 1, ITTXFE
    constexpr auto INEPNE = BitField<otg_fs_device_t, 6, 1, READWRITE>{}; // bit offset: 6, bit width: 1, INEPNE
    constexpr auto TXFE = BitField<otg_fs_device_t, 7, 1, READONLY>{}; // bit offset: 7, bit width: 1, TXFE
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000148u, 128, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(TOC), decltype(ITTXFE), decltype(INEPNE), decltype(TXFE)> DIEPINT2; // device endpoint-2 interrupt register

    constexpr auto XFRC = BitField<otg_fs_device_t, 0, 1, READWRITE>{}; // bit offset: 0, bit width: 1, XFRC
    constexpr auto EPDISD = BitField<otg_fs_device_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, EPDISD
    constexpr auto TOC = BitField<otg_fs_device_t, 3, 1, READWRITE>{}; // bit offset: 3, bit width: 1, TOC
    constexpr auto ITTXFE = BitField<otg_fs_device_t, 4, 1, READWRITE>{}; // bit offset: 4, bit width: 1, ITTXFE
    constexpr auto INEPNE = BitField<otg_fs_device_t, 6, 1, READWRITE>{}; // bit offset: 6, bit width: 1, INEPNE
    constexpr auto TXFE = BitField<otg_fs_device_t, 7, 1, READONLY>{}; // bit offset: 7, bit width: 1, TXFE
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000168u, 128, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(TOC), decltype(ITTXFE), decltype(INEPNE), decltype(TXFE)> DIEPINT3; // device endpoint-3 interrupt register

    constexpr auto XFRC = BitField<otg_fs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, XFRC
    constexpr auto EPDISD = BitField<otg_fs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, EPDISD
    constexpr auto STUP = BitField<otg_fs_device_t, 3, 1>{}; // bit offset: 3, bit width: 1, STUP
    constexpr auto OTEPDIS = BitField<otg_fs_device_t, 4, 1>{}; // bit offset: 4, bit width: 1, OTEPDIS
    constexpr auto B2BSTUP = BitField<otg_fs_device_t, 6, 1>{}; // bit offset: 6, bit width: 1, B2BSTUP
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000308u, 128, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(STUP), decltype(OTEPDIS), decltype(B2BSTUP)> DOEPINT0; // device endpoint-0 interrupt register

    constexpr auto XFRC = BitField<otg_fs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, XFRC
    constexpr auto EPDISD = BitField<otg_fs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, EPDISD
    constexpr auto STUP = BitField<otg_fs_device_t, 3, 1>{}; // bit offset: 3, bit width: 1, STUP
    constexpr auto OTEPDIS = BitField<otg_fs_device_t, 4, 1>{}; // bit offset: 4, bit width: 1, OTEPDIS
    constexpr auto B2BSTUP = BitField<otg_fs_device_t, 6, 1>{}; // bit offset: 6, bit width: 1, B2BSTUP
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000328u, 128, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(STUP), decltype(OTEPDIS), decltype(B2BSTUP)> DOEPINT1; // device endpoint-1 interrupt register

    constexpr auto XFRC = BitField<otg_fs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, XFRC
    constexpr auto EPDISD = BitField<otg_fs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, EPDISD
    constexpr auto STUP = BitField<otg_fs_device_t, 3, 1>{}; // bit offset: 3, bit width: 1, STUP
    constexpr auto OTEPDIS = BitField<otg_fs_device_t, 4, 1>{}; // bit offset: 4, bit width: 1, OTEPDIS
    constexpr auto B2BSTUP = BitField<otg_fs_device_t, 6, 1>{}; // bit offset: 6, bit width: 1, B2BSTUP
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000348u, 128, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(STUP), decltype(OTEPDIS), decltype(B2BSTUP)> DOEPINT2; // device endpoint-2 interrupt register

    constexpr auto XFRC = BitField<otg_fs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, XFRC
    constexpr auto EPDISD = BitField<otg_fs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, EPDISD
    constexpr auto STUP = BitField<otg_fs_device_t, 3, 1>{}; // bit offset: 3, bit width: 1, STUP
    constexpr auto OTEPDIS = BitField<otg_fs_device_t, 4, 1>{}; // bit offset: 4, bit width: 1, OTEPDIS
    constexpr auto B2BSTUP = BitField<otg_fs_device_t, 6, 1>{}; // bit offset: 6, bit width: 1, B2BSTUP
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000368u, 128, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(STUP), decltype(OTEPDIS), decltype(B2BSTUP)> DOEPINT3; // device endpoint-3 interrupt register

    constexpr auto XFRSIZ = BitField<otg_fs_device_t, 0, 7>{}; // bit offset: 0, bit width: 7, Transfer size
    constexpr auto PKTCNT = BitField<otg_fs_device_t, 19, 2>{}; // bit offset: 19, bit width: 2, Packet count
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000110u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT)> DIEPTSIZ0; // device endpoint-0 transfer size register

    constexpr auto XFRSIZ = BitField<otg_fs_device_t, 0, 7>{}; // bit offset: 0, bit width: 7, Transfer size
    constexpr auto PKTCNT = BitField<otg_fs_device_t, 19, 1>{}; // bit offset: 19, bit width: 1, Packet count
    constexpr auto STUPCNT = BitField<otg_fs_device_t, 29, 2>{}; // bit offset: 29, bit width: 2, SETUP packet count
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000310u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(STUPCNT)> DOEPTSIZ0; // device OUT endpoint-0 transfer size register

    constexpr auto XFRSIZ = BitField<otg_fs_device_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_fs_device_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto MCNT = BitField<otg_fs_device_t, 29, 2>{}; // bit offset: 29, bit width: 2, Multi count
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000130u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(MCNT)> DIEPTSIZ1; // device endpoint-1 transfer size register

    constexpr auto XFRSIZ = BitField<otg_fs_device_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_fs_device_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto MCNT = BitField<otg_fs_device_t, 29, 2>{}; // bit offset: 29, bit width: 2, Multi count
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000150u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(MCNT)> DIEPTSIZ2; // device endpoint-2 transfer size register

    constexpr auto XFRSIZ = BitField<otg_fs_device_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_fs_device_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto MCNT = BitField<otg_fs_device_t, 29, 2>{}; // bit offset: 29, bit width: 2, Multi count
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000170u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(MCNT)> DIEPTSIZ3; // device endpoint-3 transfer size register

    constexpr auto INEPTFSAV = BitField<otg_fs_device_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN endpoint TxFIFO space available
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000118u, 0, READONLY, decltype(INEPTFSAV)> DTXFSTS0; // OTG_FS device IN endpoint transmit FIFO status register

    constexpr auto INEPTFSAV = BitField<otg_fs_device_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN endpoint TxFIFO space available
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000138u, 0, READONLY, decltype(INEPTFSAV)> DTXFSTS1; // OTG_FS device IN endpoint transmit FIFO status register

    constexpr auto INEPTFSAV = BitField<otg_fs_device_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN endpoint TxFIFO space available
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000158u, 0, READONLY, decltype(INEPTFSAV)> DTXFSTS2; // OTG_FS device IN endpoint transmit FIFO status register

    constexpr auto INEPTFSAV = BitField<otg_fs_device_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN endpoint TxFIFO space available
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000178u, 0, READONLY, decltype(INEPTFSAV)> DTXFSTS3; // OTG_FS device IN endpoint transmit FIFO status register

    constexpr auto XFRSIZ = BitField<otg_fs_device_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_fs_device_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto RXDPID_STUPCNT = BitField<otg_fs_device_t, 29, 2>{}; // bit offset: 29, bit width: 2, Received data PID/SETUP packet count
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000330u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(RXDPID_STUPCNT)> DOEPTSIZ1; // device OUT endpoint-1 transfer size register

    constexpr auto XFRSIZ = BitField<otg_fs_device_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_fs_device_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto RXDPID_STUPCNT = BitField<otg_fs_device_t, 29, 2>{}; // bit offset: 29, bit width: 2, Received data PID/SETUP packet count
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000350u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(RXDPID_STUPCNT)> DOEPTSIZ2; // device OUT endpoint-2 transfer size register

    constexpr auto XFRSIZ = BitField<otg_fs_device_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_fs_device_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto RXDPID_STUPCNT = BitField<otg_fs_device_t, 29, 2>{}; // bit offset: 29, bit width: 2, Received data PID/SETUP packet count
    static Register<std::uint32_t, OTG_FS_DEVICE_BASE_ADDRESS + 0x00000370u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(RXDPID_STUPCNT)> DOEPTSIZ3; // device OUT endpoint-3 transfer size register

} // namespace OTG_FS_DEVICE