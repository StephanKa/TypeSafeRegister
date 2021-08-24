#include <Register.hpp>




namespace OTG_HS_DEVICE
{
    struct otg_hs_device_t{};

    constexpr std::uint32_t OTG_HS_DEVICE_BASE_ADDRESS = 0x40040800u;

    constexpr auto DSPD = BitField<otg_hs_device_t, 0, 2>{}; // bit offset: 0, bit width: 2, Device speed
    constexpr auto NZLSOHSK = BitField<otg_hs_device_t, 2, 1>{}; // bit offset: 2, bit width: 1, Nonzero-length status OUT handshake
    constexpr auto DAD = BitField<otg_hs_device_t, 4, 7>{}; // bit offset: 4, bit width: 7, Device address
    constexpr auto PFIVL = BitField<otg_hs_device_t, 11, 2>{}; // bit offset: 11, bit width: 2, Periodic (micro)frame interval
    constexpr auto PERSCHIVL = BitField<otg_hs_device_t, 24, 2>{}; // bit offset: 24, bit width: 2, Periodic scheduling interval
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000000u, 35651584, READWRITE, decltype(DSPD), decltype(NZLSOHSK), decltype(DAD), decltype(PFIVL), decltype(PERSCHIVL)> OTG_HS_DCFG; // OTG_HS device configuration register

    constexpr auto RWUSIG = BitField<otg_hs_device_t, 0, 1, READWRITE>{}; // bit offset: 0, bit width: 1, Remote wakeup signaling
    constexpr auto SDIS = BitField<otg_hs_device_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, Soft disconnect
    constexpr auto GINSTS = BitField<otg_hs_device_t, 2, 1, READONLY>{}; // bit offset: 2, bit width: 1, Global IN NAK status
    constexpr auto GONSTS = BitField<otg_hs_device_t, 3, 1, READONLY>{}; // bit offset: 3, bit width: 1, Global OUT NAK status
    constexpr auto TCTL = BitField<otg_hs_device_t, 4, 3, READWRITE>{}; // bit offset: 4, bit width: 3, Test control
    constexpr auto SGINAK = BitField<otg_hs_device_t, 7, 1, WRITEONLY>{}; // bit offset: 7, bit width: 1, Set global IN NAK
    constexpr auto CGINAK = BitField<otg_hs_device_t, 8, 1, WRITEONLY>{}; // bit offset: 8, bit width: 1, Clear global IN NAK
    constexpr auto SGONAK = BitField<otg_hs_device_t, 9, 1, WRITEONLY>{}; // bit offset: 9, bit width: 1, Set global OUT NAK
    constexpr auto CGONAK = BitField<otg_hs_device_t, 10, 1, WRITEONLY>{}; // bit offset: 10, bit width: 1, Clear global OUT NAK
    constexpr auto POPRGDNE = BitField<otg_hs_device_t, 11, 1, READWRITE>{}; // bit offset: 11, bit width: 1, Power-on programming done
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000004u, 0, READWRITE, decltype(RWUSIG), decltype(SDIS), decltype(GINSTS), decltype(GONSTS), decltype(TCTL), decltype(SGINAK), decltype(CGINAK), decltype(SGONAK), decltype(CGONAK), decltype(POPRGDNE)> OTG_HS_DCTL; // OTG_HS device control register

    constexpr auto SUSPSTS = BitField<otg_hs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, Suspend status
    constexpr auto ENUMSPD = BitField<otg_hs_device_t, 1, 2>{}; // bit offset: 1, bit width: 2, Enumerated speed
    constexpr auto EERR = BitField<otg_hs_device_t, 3, 1>{}; // bit offset: 3, bit width: 1, Erratic error
    constexpr auto FNSOF = BitField<otg_hs_device_t, 8, 14>{}; // bit offset: 8, bit width: 14, Frame number of the received SOF
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000008u, 16, READONLY, decltype(SUSPSTS), decltype(ENUMSPD), decltype(EERR), decltype(FNSOF)> OTG_HS_DSTS; // OTG_HS device status register

    constexpr auto XFRCM = BitField<otg_hs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt mask
    constexpr auto EPDM = BitField<otg_hs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt mask
    constexpr auto TOM = BitField<otg_hs_device_t, 3, 1>{}; // bit offset: 3, bit width: 1, Timeout condition mask (nonisochronous endpoints)
    constexpr auto ITTXFEMSK = BitField<otg_hs_device_t, 4, 1>{}; // bit offset: 4, bit width: 1, IN token received when TxFIFO empty mask
    constexpr auto INEPNMM = BitField<otg_hs_device_t, 5, 1>{}; // bit offset: 5, bit width: 1, IN token received with EP mismatch mask
    constexpr auto INEPNEM = BitField<otg_hs_device_t, 6, 1>{}; // bit offset: 6, bit width: 1, IN endpoint NAK effective mask
    constexpr auto TXFURM = BitField<otg_hs_device_t, 8, 1>{}; // bit offset: 8, bit width: 1, FIFO underrun mask
    constexpr auto BIM = BitField<otg_hs_device_t, 9, 1>{}; // bit offset: 9, bit width: 1, BNA interrupt mask
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000010u, 0, READWRITE, decltype(XFRCM), decltype(EPDM), decltype(TOM), decltype(ITTXFEMSK), decltype(INEPNMM), decltype(INEPNEM), decltype(TXFURM), decltype(BIM)> OTG_HS_DIEPMSK; // OTG_HS device IN endpoint common interrupt mask register

    constexpr auto XFRCM = BitField<otg_hs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt mask
    constexpr auto EPDM = BitField<otg_hs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt mask
    constexpr auto STUPM = BitField<otg_hs_device_t, 3, 1>{}; // bit offset: 3, bit width: 1, SETUP phase done mask
    constexpr auto OTEPDM = BitField<otg_hs_device_t, 4, 1>{}; // bit offset: 4, bit width: 1, OUT token received when endpoint disabled mask
    constexpr auto B2BSTUP = BitField<otg_hs_device_t, 6, 1>{}; // bit offset: 6, bit width: 1, Back-to-back SETUP packets received mask
    constexpr auto OPEM = BitField<otg_hs_device_t, 8, 1>{}; // bit offset: 8, bit width: 1, OUT packet error mask
    constexpr auto BOIM = BitField<otg_hs_device_t, 9, 1>{}; // bit offset: 9, bit width: 1, BNA interrupt mask
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000014u, 0, READWRITE, decltype(XFRCM), decltype(EPDM), decltype(STUPM), decltype(OTEPDM), decltype(B2BSTUP), decltype(OPEM), decltype(BOIM)> OTG_HS_DOEPMSK; // OTG_HS device OUT endpoint common interrupt mask register

    constexpr auto IEPINT = BitField<otg_hs_device_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN endpoint interrupt bits
    constexpr auto OEPINT = BitField<otg_hs_device_t, 16, 16>{}; // bit offset: 16, bit width: 16, OUT endpoint interrupt bits
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000018u, 0, READONLY, decltype(IEPINT), decltype(OEPINT)> OTG_HS_DAINT; // OTG_HS device all endpoints interrupt register

    constexpr auto IEPM = BitField<otg_hs_device_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN EP interrupt mask bits
    constexpr auto OEPM = BitField<otg_hs_device_t, 16, 16>{}; // bit offset: 16, bit width: 16, OUT EP interrupt mask bits
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x0000001cu, 0, READWRITE, decltype(IEPM), decltype(OEPM)> OTG_HS_DAINTMSK; // OTG_HS all endpoints interrupt mask register

    constexpr auto VBUSDT = BitField<otg_hs_device_t, 0, 16>{}; // bit offset: 0, bit width: 16, Device VBUS discharge time
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000028u, 6103, READWRITE, decltype(VBUSDT)> OTG_HS_DVBUSDIS; // OTG_HS device VBUS discharge time register

    constexpr auto DVBUSP = BitField<otg_hs_device_t, 0, 12>{}; // bit offset: 0, bit width: 12, Device VBUS pulsing time
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x0000002cu, 1464, READWRITE, decltype(DVBUSP)> OTG_HS_DVBUSPULSE; // OTG_HS device VBUS pulsing time register

    constexpr auto NONISOTHREN = BitField<otg_hs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, Nonisochronous IN endpoints threshold enable
    constexpr auto ISOTHREN = BitField<otg_hs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, ISO IN endpoint threshold enable
    constexpr auto TXTHRLEN = BitField<otg_hs_device_t, 2, 9>{}; // bit offset: 2, bit width: 9, Transmit threshold length
    constexpr auto RXTHREN = BitField<otg_hs_device_t, 16, 1>{}; // bit offset: 16, bit width: 1, Receive threshold enable
    constexpr auto RXTHRLEN = BitField<otg_hs_device_t, 17, 9>{}; // bit offset: 17, bit width: 9, Receive threshold length
    constexpr auto ARPEN = BitField<otg_hs_device_t, 27, 1>{}; // bit offset: 27, bit width: 1, Arbiter parking enable
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000030u, 0, READWRITE, decltype(NONISOTHREN), decltype(ISOTHREN), decltype(TXTHRLEN), decltype(RXTHREN), decltype(RXTHRLEN), decltype(ARPEN)> OTG_HS_DTHRCTL; // OTG_HS Device threshold control register

    constexpr auto INEPTXFEM = BitField<otg_hs_device_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN EP Tx FIFO empty interrupt mask bits
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000034u, 0, READWRITE, decltype(INEPTXFEM)> OTG_HS_DIEPEMPMSK; // OTG_HS device IN endpoint FIFO empty interrupt mask register

    constexpr auto IEP1INT = BitField<otg_hs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, IN endpoint 1interrupt bit
    constexpr auto OEP1INT = BitField<otg_hs_device_t, 17, 1>{}; // bit offset: 17, bit width: 1, OUT endpoint 1 interrupt bit
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000038u, 0, READWRITE, decltype(IEP1INT), decltype(OEP1INT)> OTG_HS_DEACHINT; // OTG_HS device each endpoint interrupt register

    constexpr auto IEP1INTM = BitField<otg_hs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, IN Endpoint 1 interrupt mask bit
    constexpr auto OEP1INTM = BitField<otg_hs_device_t, 17, 1>{}; // bit offset: 17, bit width: 1, OUT Endpoint 1 interrupt mask bit
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x0000003cu, 0, READWRITE, decltype(IEP1INTM), decltype(OEP1INTM)> OTG_HS_DEACHINTMSK; // OTG_HS device each endpoint interrupt register mask

    constexpr auto XFRCM = BitField<otg_hs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt mask
    constexpr auto EPDM = BitField<otg_hs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt mask
    constexpr auto TOM = BitField<otg_hs_device_t, 3, 1>{}; // bit offset: 3, bit width: 1, Timeout condition mask (nonisochronous endpoints)
    constexpr auto ITTXFEMSK = BitField<otg_hs_device_t, 4, 1>{}; // bit offset: 4, bit width: 1, IN token received when TxFIFO empty mask
    constexpr auto INEPNMM = BitField<otg_hs_device_t, 5, 1>{}; // bit offset: 5, bit width: 1, IN token received with EP mismatch mask
    constexpr auto INEPNEM = BitField<otg_hs_device_t, 6, 1>{}; // bit offset: 6, bit width: 1, IN endpoint NAK effective mask
    constexpr auto TXFURM = BitField<otg_hs_device_t, 8, 1>{}; // bit offset: 8, bit width: 1, FIFO underrun mask
    constexpr auto BIM = BitField<otg_hs_device_t, 9, 1>{}; // bit offset: 9, bit width: 1, BNA interrupt mask
    constexpr auto NAKM = BitField<otg_hs_device_t, 13, 1>{}; // bit offset: 13, bit width: 1, NAK interrupt mask
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000040u, 0, READWRITE, decltype(XFRCM), decltype(EPDM), decltype(TOM), decltype(ITTXFEMSK), decltype(INEPNMM), decltype(INEPNEM), decltype(TXFURM), decltype(BIM), decltype(NAKM)> OTG_HS_DIEPEACHMSK1; // OTG_HS device each in endpoint-1 interrupt register

    constexpr auto XFRCM = BitField<otg_hs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt mask
    constexpr auto EPDM = BitField<otg_hs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt mask
    constexpr auto TOM = BitField<otg_hs_device_t, 3, 1>{}; // bit offset: 3, bit width: 1, Timeout condition mask
    constexpr auto ITTXFEMSK = BitField<otg_hs_device_t, 4, 1>{}; // bit offset: 4, bit width: 1, IN token received when TxFIFO empty mask
    constexpr auto INEPNMM = BitField<otg_hs_device_t, 5, 1>{}; // bit offset: 5, bit width: 1, IN token received with EP mismatch mask
    constexpr auto INEPNEM = BitField<otg_hs_device_t, 6, 1>{}; // bit offset: 6, bit width: 1, IN endpoint NAK effective mask
    constexpr auto TXFURM = BitField<otg_hs_device_t, 8, 1>{}; // bit offset: 8, bit width: 1, OUT packet error mask
    constexpr auto BIM = BitField<otg_hs_device_t, 9, 1>{}; // bit offset: 9, bit width: 1, BNA interrupt mask
    constexpr auto BERRM = BitField<otg_hs_device_t, 12, 1>{}; // bit offset: 12, bit width: 1, Bubble error interrupt mask
    constexpr auto NAKM = BitField<otg_hs_device_t, 13, 1>{}; // bit offset: 13, bit width: 1, NAK interrupt mask
    constexpr auto NYETM = BitField<otg_hs_device_t, 14, 1>{}; // bit offset: 14, bit width: 1, NYET interrupt mask
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000080u, 0, READWRITE, decltype(XFRCM), decltype(EPDM), decltype(TOM), decltype(ITTXFEMSK), decltype(INEPNMM), decltype(INEPNEM), decltype(TXFURM), decltype(BIM), decltype(BERRM), decltype(NAKM), decltype(NYETM)> OTG_HS_DOEPEACHMSK1; // OTG_HS device each OUT endpoint-1 interrupt register

    constexpr auto MPSIZ = BitField<otg_hs_device_t, 0, 11, READWRITE>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto USBAEP = BitField<otg_hs_device_t, 15, 1, READWRITE>{}; // bit offset: 15, bit width: 1, USB active endpoint
    constexpr auto EONUM_DPID = BitField<otg_hs_device_t, 16, 1, READONLY>{}; // bit offset: 16, bit width: 1, Even/odd frame
    constexpr auto NAKSTS = BitField<otg_hs_device_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, NAK status
    constexpr auto EPTYP = BitField<otg_hs_device_t, 18, 2, READWRITE>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto Stall = BitField<otg_hs_device_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, STALL handshake
    constexpr auto TXFNUM = BitField<otg_hs_device_t, 22, 4, READWRITE>{}; // bit offset: 22, bit width: 4, TxFIFO number
    constexpr auto CNAK = BitField<otg_hs_device_t, 26, 1, WRITEONLY>{}; // bit offset: 26, bit width: 1, Clear NAK
    constexpr auto SNAK = BitField<otg_hs_device_t, 27, 1, WRITEONLY>{}; // bit offset: 27, bit width: 1, Set NAK
    constexpr auto SD0PID_SEVNFRM = BitField<otg_hs_device_t, 28, 1, WRITEONLY>{}; // bit offset: 28, bit width: 1, Set DATA0 PID
    constexpr auto SODDFRM = BitField<otg_hs_device_t, 29, 1, WRITEONLY>{}; // bit offset: 29, bit width: 1, Set odd frame
    constexpr auto EPDIS = BitField<otg_hs_device_t, 30, 1, READWRITE>{}; // bit offset: 30, bit width: 1, Endpoint disable
    constexpr auto EPENA = BitField<otg_hs_device_t, 31, 1, READWRITE>{}; // bit offset: 31, bit width: 1, Endpoint enable
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000100u, 0, READWRITE, decltype(MPSIZ), decltype(USBAEP), decltype(EONUM_DPID), decltype(NAKSTS), decltype(EPTYP), decltype(Stall), decltype(TXFNUM), decltype(CNAK), decltype(SNAK), decltype(SD0PID_SEVNFRM), decltype(SODDFRM), decltype(EPDIS), decltype(EPENA)> OTG_HS_DIEPCTL0; // OTG device endpoint-0 control register

    constexpr auto MPSIZ = BitField<otg_hs_device_t, 0, 11, READWRITE>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto USBAEP = BitField<otg_hs_device_t, 15, 1, READWRITE>{}; // bit offset: 15, bit width: 1, USB active endpoint
    constexpr auto EONUM_DPID = BitField<otg_hs_device_t, 16, 1, READONLY>{}; // bit offset: 16, bit width: 1, Even/odd frame
    constexpr auto NAKSTS = BitField<otg_hs_device_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, NAK status
    constexpr auto EPTYP = BitField<otg_hs_device_t, 18, 2, READWRITE>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto Stall = BitField<otg_hs_device_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, STALL handshake
    constexpr auto TXFNUM = BitField<otg_hs_device_t, 22, 4, READWRITE>{}; // bit offset: 22, bit width: 4, TxFIFO number
    constexpr auto CNAK = BitField<otg_hs_device_t, 26, 1, WRITEONLY>{}; // bit offset: 26, bit width: 1, Clear NAK
    constexpr auto SNAK = BitField<otg_hs_device_t, 27, 1, WRITEONLY>{}; // bit offset: 27, bit width: 1, Set NAK
    constexpr auto SD0PID_SEVNFRM = BitField<otg_hs_device_t, 28, 1, WRITEONLY>{}; // bit offset: 28, bit width: 1, Set DATA0 PID
    constexpr auto SODDFRM = BitField<otg_hs_device_t, 29, 1, WRITEONLY>{}; // bit offset: 29, bit width: 1, Set odd frame
    constexpr auto EPDIS = BitField<otg_hs_device_t, 30, 1, READWRITE>{}; // bit offset: 30, bit width: 1, Endpoint disable
    constexpr auto EPENA = BitField<otg_hs_device_t, 31, 1, READWRITE>{}; // bit offset: 31, bit width: 1, Endpoint enable
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000120u, 0, READWRITE, decltype(MPSIZ), decltype(USBAEP), decltype(EONUM_DPID), decltype(NAKSTS), decltype(EPTYP), decltype(Stall), decltype(TXFNUM), decltype(CNAK), decltype(SNAK), decltype(SD0PID_SEVNFRM), decltype(SODDFRM), decltype(EPDIS), decltype(EPENA)> OTG_HS_DIEPCTL1; // OTG device endpoint-1 control register

    constexpr auto MPSIZ = BitField<otg_hs_device_t, 0, 11, READWRITE>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto USBAEP = BitField<otg_hs_device_t, 15, 1, READWRITE>{}; // bit offset: 15, bit width: 1, USB active endpoint
    constexpr auto EONUM_DPID = BitField<otg_hs_device_t, 16, 1, READONLY>{}; // bit offset: 16, bit width: 1, Even/odd frame
    constexpr auto NAKSTS = BitField<otg_hs_device_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, NAK status
    constexpr auto EPTYP = BitField<otg_hs_device_t, 18, 2, READWRITE>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto Stall = BitField<otg_hs_device_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, STALL handshake
    constexpr auto TXFNUM = BitField<otg_hs_device_t, 22, 4, READWRITE>{}; // bit offset: 22, bit width: 4, TxFIFO number
    constexpr auto CNAK = BitField<otg_hs_device_t, 26, 1, WRITEONLY>{}; // bit offset: 26, bit width: 1, Clear NAK
    constexpr auto SNAK = BitField<otg_hs_device_t, 27, 1, WRITEONLY>{}; // bit offset: 27, bit width: 1, Set NAK
    constexpr auto SD0PID_SEVNFRM = BitField<otg_hs_device_t, 28, 1, WRITEONLY>{}; // bit offset: 28, bit width: 1, Set DATA0 PID
    constexpr auto SODDFRM = BitField<otg_hs_device_t, 29, 1, WRITEONLY>{}; // bit offset: 29, bit width: 1, Set odd frame
    constexpr auto EPDIS = BitField<otg_hs_device_t, 30, 1, READWRITE>{}; // bit offset: 30, bit width: 1, Endpoint disable
    constexpr auto EPENA = BitField<otg_hs_device_t, 31, 1, READWRITE>{}; // bit offset: 31, bit width: 1, Endpoint enable
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000140u, 0, READWRITE, decltype(MPSIZ), decltype(USBAEP), decltype(EONUM_DPID), decltype(NAKSTS), decltype(EPTYP), decltype(Stall), decltype(TXFNUM), decltype(CNAK), decltype(SNAK), decltype(SD0PID_SEVNFRM), decltype(SODDFRM), decltype(EPDIS), decltype(EPENA)> OTG_HS_DIEPCTL2; // OTG device endpoint-2 control register

    constexpr auto MPSIZ = BitField<otg_hs_device_t, 0, 11, READWRITE>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto USBAEP = BitField<otg_hs_device_t, 15, 1, READWRITE>{}; // bit offset: 15, bit width: 1, USB active endpoint
    constexpr auto EONUM_DPID = BitField<otg_hs_device_t, 16, 1, READONLY>{}; // bit offset: 16, bit width: 1, Even/odd frame
    constexpr auto NAKSTS = BitField<otg_hs_device_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, NAK status
    constexpr auto EPTYP = BitField<otg_hs_device_t, 18, 2, READWRITE>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto Stall = BitField<otg_hs_device_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, STALL handshake
    constexpr auto TXFNUM = BitField<otg_hs_device_t, 22, 4, READWRITE>{}; // bit offset: 22, bit width: 4, TxFIFO number
    constexpr auto CNAK = BitField<otg_hs_device_t, 26, 1, WRITEONLY>{}; // bit offset: 26, bit width: 1, Clear NAK
    constexpr auto SNAK = BitField<otg_hs_device_t, 27, 1, WRITEONLY>{}; // bit offset: 27, bit width: 1, Set NAK
    constexpr auto SD0PID_SEVNFRM = BitField<otg_hs_device_t, 28, 1, WRITEONLY>{}; // bit offset: 28, bit width: 1, Set DATA0 PID
    constexpr auto SODDFRM = BitField<otg_hs_device_t, 29, 1, WRITEONLY>{}; // bit offset: 29, bit width: 1, Set odd frame
    constexpr auto EPDIS = BitField<otg_hs_device_t, 30, 1, READWRITE>{}; // bit offset: 30, bit width: 1, Endpoint disable
    constexpr auto EPENA = BitField<otg_hs_device_t, 31, 1, READWRITE>{}; // bit offset: 31, bit width: 1, Endpoint enable
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000160u, 0, READWRITE, decltype(MPSIZ), decltype(USBAEP), decltype(EONUM_DPID), decltype(NAKSTS), decltype(EPTYP), decltype(Stall), decltype(TXFNUM), decltype(CNAK), decltype(SNAK), decltype(SD0PID_SEVNFRM), decltype(SODDFRM), decltype(EPDIS), decltype(EPENA)> OTG_HS_DIEPCTL3; // OTG device endpoint-3 control register

    constexpr auto MPSIZ = BitField<otg_hs_device_t, 0, 11, READWRITE>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto USBAEP = BitField<otg_hs_device_t, 15, 1, READWRITE>{}; // bit offset: 15, bit width: 1, USB active endpoint
    constexpr auto EONUM_DPID = BitField<otg_hs_device_t, 16, 1, READONLY>{}; // bit offset: 16, bit width: 1, Even/odd frame
    constexpr auto NAKSTS = BitField<otg_hs_device_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, NAK status
    constexpr auto EPTYP = BitField<otg_hs_device_t, 18, 2, READWRITE>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto Stall = BitField<otg_hs_device_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, STALL handshake
    constexpr auto TXFNUM = BitField<otg_hs_device_t, 22, 4, READWRITE>{}; // bit offset: 22, bit width: 4, TxFIFO number
    constexpr auto CNAK = BitField<otg_hs_device_t, 26, 1, WRITEONLY>{}; // bit offset: 26, bit width: 1, Clear NAK
    constexpr auto SNAK = BitField<otg_hs_device_t, 27, 1, WRITEONLY>{}; // bit offset: 27, bit width: 1, Set NAK
    constexpr auto SD0PID_SEVNFRM = BitField<otg_hs_device_t, 28, 1, WRITEONLY>{}; // bit offset: 28, bit width: 1, Set DATA0 PID
    constexpr auto SODDFRM = BitField<otg_hs_device_t, 29, 1, WRITEONLY>{}; // bit offset: 29, bit width: 1, Set odd frame
    constexpr auto EPDIS = BitField<otg_hs_device_t, 30, 1, READWRITE>{}; // bit offset: 30, bit width: 1, Endpoint disable
    constexpr auto EPENA = BitField<otg_hs_device_t, 31, 1, READWRITE>{}; // bit offset: 31, bit width: 1, Endpoint enable
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000180u, 0, READWRITE, decltype(MPSIZ), decltype(USBAEP), decltype(EONUM_DPID), decltype(NAKSTS), decltype(EPTYP), decltype(Stall), decltype(TXFNUM), decltype(CNAK), decltype(SNAK), decltype(SD0PID_SEVNFRM), decltype(SODDFRM), decltype(EPDIS), decltype(EPENA)> OTG_HS_DIEPCTL4; // OTG device endpoint-4 control register

    constexpr auto MPSIZ = BitField<otg_hs_device_t, 0, 11, READWRITE>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto USBAEP = BitField<otg_hs_device_t, 15, 1, READWRITE>{}; // bit offset: 15, bit width: 1, USB active endpoint
    constexpr auto EONUM_DPID = BitField<otg_hs_device_t, 16, 1, READONLY>{}; // bit offset: 16, bit width: 1, Even/odd frame
    constexpr auto NAKSTS = BitField<otg_hs_device_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, NAK status
    constexpr auto EPTYP = BitField<otg_hs_device_t, 18, 2, READWRITE>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto Stall = BitField<otg_hs_device_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, STALL handshake
    constexpr auto TXFNUM = BitField<otg_hs_device_t, 22, 4, READWRITE>{}; // bit offset: 22, bit width: 4, TxFIFO number
    constexpr auto CNAK = BitField<otg_hs_device_t, 26, 1, WRITEONLY>{}; // bit offset: 26, bit width: 1, Clear NAK
    constexpr auto SNAK = BitField<otg_hs_device_t, 27, 1, WRITEONLY>{}; // bit offset: 27, bit width: 1, Set NAK
    constexpr auto SD0PID_SEVNFRM = BitField<otg_hs_device_t, 28, 1, WRITEONLY>{}; // bit offset: 28, bit width: 1, Set DATA0 PID
    constexpr auto SODDFRM = BitField<otg_hs_device_t, 29, 1, WRITEONLY>{}; // bit offset: 29, bit width: 1, Set odd frame
    constexpr auto EPDIS = BitField<otg_hs_device_t, 30, 1, READWRITE>{}; // bit offset: 30, bit width: 1, Endpoint disable
    constexpr auto EPENA = BitField<otg_hs_device_t, 31, 1, READWRITE>{}; // bit offset: 31, bit width: 1, Endpoint enable
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x000001a0u, 0, READWRITE, decltype(MPSIZ), decltype(USBAEP), decltype(EONUM_DPID), decltype(NAKSTS), decltype(EPTYP), decltype(Stall), decltype(TXFNUM), decltype(CNAK), decltype(SNAK), decltype(SD0PID_SEVNFRM), decltype(SODDFRM), decltype(EPDIS), decltype(EPENA)> OTG_HS_DIEPCTL5; // OTG device endpoint-5 control register

    constexpr auto MPSIZ = BitField<otg_hs_device_t, 0, 11, READWRITE>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto USBAEP = BitField<otg_hs_device_t, 15, 1, READWRITE>{}; // bit offset: 15, bit width: 1, USB active endpoint
    constexpr auto EONUM_DPID = BitField<otg_hs_device_t, 16, 1, READONLY>{}; // bit offset: 16, bit width: 1, Even/odd frame
    constexpr auto NAKSTS = BitField<otg_hs_device_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, NAK status
    constexpr auto EPTYP = BitField<otg_hs_device_t, 18, 2, READWRITE>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto Stall = BitField<otg_hs_device_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, STALL handshake
    constexpr auto TXFNUM = BitField<otg_hs_device_t, 22, 4, READWRITE>{}; // bit offset: 22, bit width: 4, TxFIFO number
    constexpr auto CNAK = BitField<otg_hs_device_t, 26, 1, WRITEONLY>{}; // bit offset: 26, bit width: 1, Clear NAK
    constexpr auto SNAK = BitField<otg_hs_device_t, 27, 1, WRITEONLY>{}; // bit offset: 27, bit width: 1, Set NAK
    constexpr auto SD0PID_SEVNFRM = BitField<otg_hs_device_t, 28, 1, WRITEONLY>{}; // bit offset: 28, bit width: 1, Set DATA0 PID
    constexpr auto SODDFRM = BitField<otg_hs_device_t, 29, 1, WRITEONLY>{}; // bit offset: 29, bit width: 1, Set odd frame
    constexpr auto EPDIS = BitField<otg_hs_device_t, 30, 1, READWRITE>{}; // bit offset: 30, bit width: 1, Endpoint disable
    constexpr auto EPENA = BitField<otg_hs_device_t, 31, 1, READWRITE>{}; // bit offset: 31, bit width: 1, Endpoint enable
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x000001c0u, 0, READWRITE, decltype(MPSIZ), decltype(USBAEP), decltype(EONUM_DPID), decltype(NAKSTS), decltype(EPTYP), decltype(Stall), decltype(TXFNUM), decltype(CNAK), decltype(SNAK), decltype(SD0PID_SEVNFRM), decltype(SODDFRM), decltype(EPDIS), decltype(EPENA)> OTG_HS_DIEPCTL6; // OTG device endpoint-6 control register

    constexpr auto MPSIZ = BitField<otg_hs_device_t, 0, 11, READWRITE>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto USBAEP = BitField<otg_hs_device_t, 15, 1, READWRITE>{}; // bit offset: 15, bit width: 1, USB active endpoint
    constexpr auto EONUM_DPID = BitField<otg_hs_device_t, 16, 1, READONLY>{}; // bit offset: 16, bit width: 1, Even/odd frame
    constexpr auto NAKSTS = BitField<otg_hs_device_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, NAK status
    constexpr auto EPTYP = BitField<otg_hs_device_t, 18, 2, READWRITE>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto Stall = BitField<otg_hs_device_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, STALL handshake
    constexpr auto TXFNUM = BitField<otg_hs_device_t, 22, 4, READWRITE>{}; // bit offset: 22, bit width: 4, TxFIFO number
    constexpr auto CNAK = BitField<otg_hs_device_t, 26, 1, WRITEONLY>{}; // bit offset: 26, bit width: 1, Clear NAK
    constexpr auto SNAK = BitField<otg_hs_device_t, 27, 1, WRITEONLY>{}; // bit offset: 27, bit width: 1, Set NAK
    constexpr auto SD0PID_SEVNFRM = BitField<otg_hs_device_t, 28, 1, WRITEONLY>{}; // bit offset: 28, bit width: 1, Set DATA0 PID
    constexpr auto SODDFRM = BitField<otg_hs_device_t, 29, 1, WRITEONLY>{}; // bit offset: 29, bit width: 1, Set odd frame
    constexpr auto EPDIS = BitField<otg_hs_device_t, 30, 1, READWRITE>{}; // bit offset: 30, bit width: 1, Endpoint disable
    constexpr auto EPENA = BitField<otg_hs_device_t, 31, 1, READWRITE>{}; // bit offset: 31, bit width: 1, Endpoint enable
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x000001e0u, 0, READWRITE, decltype(MPSIZ), decltype(USBAEP), decltype(EONUM_DPID), decltype(NAKSTS), decltype(EPTYP), decltype(Stall), decltype(TXFNUM), decltype(CNAK), decltype(SNAK), decltype(SD0PID_SEVNFRM), decltype(SODDFRM), decltype(EPDIS), decltype(EPENA)> OTG_HS_DIEPCTL7; // OTG device endpoint-7 control register

    constexpr auto XFRC = BitField<otg_hs_device_t, 0, 1, READWRITE>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt
    constexpr auto EPDISD = BitField<otg_hs_device_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt
    constexpr auto TOC = BitField<otg_hs_device_t, 3, 1, READWRITE>{}; // bit offset: 3, bit width: 1, Timeout condition
    constexpr auto ITTXFE = BitField<otg_hs_device_t, 4, 1, READWRITE>{}; // bit offset: 4, bit width: 1, IN token received when TxFIFO is empty
    constexpr auto INEPNE = BitField<otg_hs_device_t, 6, 1, READWRITE>{}; // bit offset: 6, bit width: 1, IN endpoint NAK effective
    constexpr auto TXFE = BitField<otg_hs_device_t, 7, 1, READONLY>{}; // bit offset: 7, bit width: 1, Transmit FIFO empty
    constexpr auto TXFIFOUDRN = BitField<otg_hs_device_t, 8, 1, READWRITE>{}; // bit offset: 8, bit width: 1, Transmit Fifo Underrun
    constexpr auto BNA = BitField<otg_hs_device_t, 9, 1, READWRITE>{}; // bit offset: 9, bit width: 1, Buffer not available interrupt
    constexpr auto PKTDRPSTS = BitField<otg_hs_device_t, 11, 1, READWRITE>{}; // bit offset: 11, bit width: 1, Packet dropped status
    constexpr auto BERR = BitField<otg_hs_device_t, 12, 1, READWRITE>{}; // bit offset: 12, bit width: 1, Babble error interrupt
    constexpr auto NAK = BitField<otg_hs_device_t, 13, 1, READWRITE>{}; // bit offset: 13, bit width: 1, NAK interrupt
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000108u, 128, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(TOC), decltype(ITTXFE), decltype(INEPNE), decltype(TXFE), decltype(TXFIFOUDRN), decltype(BNA), decltype(PKTDRPSTS), decltype(BERR), decltype(NAK)> OTG_HS_DIEPINT0; // OTG device endpoint-0 interrupt register

    constexpr auto XFRC = BitField<otg_hs_device_t, 0, 1, READWRITE>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt
    constexpr auto EPDISD = BitField<otg_hs_device_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt
    constexpr auto TOC = BitField<otg_hs_device_t, 3, 1, READWRITE>{}; // bit offset: 3, bit width: 1, Timeout condition
    constexpr auto ITTXFE = BitField<otg_hs_device_t, 4, 1, READWRITE>{}; // bit offset: 4, bit width: 1, IN token received when TxFIFO is empty
    constexpr auto INEPNE = BitField<otg_hs_device_t, 6, 1, READWRITE>{}; // bit offset: 6, bit width: 1, IN endpoint NAK effective
    constexpr auto TXFE = BitField<otg_hs_device_t, 7, 1, READONLY>{}; // bit offset: 7, bit width: 1, Transmit FIFO empty
    constexpr auto TXFIFOUDRN = BitField<otg_hs_device_t, 8, 1, READWRITE>{}; // bit offset: 8, bit width: 1, Transmit Fifo Underrun
    constexpr auto BNA = BitField<otg_hs_device_t, 9, 1, READWRITE>{}; // bit offset: 9, bit width: 1, Buffer not available interrupt
    constexpr auto PKTDRPSTS = BitField<otg_hs_device_t, 11, 1, READWRITE>{}; // bit offset: 11, bit width: 1, Packet dropped status
    constexpr auto BERR = BitField<otg_hs_device_t, 12, 1, READWRITE>{}; // bit offset: 12, bit width: 1, Babble error interrupt
    constexpr auto NAK = BitField<otg_hs_device_t, 13, 1, READWRITE>{}; // bit offset: 13, bit width: 1, NAK interrupt
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000128u, 0, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(TOC), decltype(ITTXFE), decltype(INEPNE), decltype(TXFE), decltype(TXFIFOUDRN), decltype(BNA), decltype(PKTDRPSTS), decltype(BERR), decltype(NAK)> OTG_HS_DIEPINT1; // OTG device endpoint-1 interrupt register

    constexpr auto XFRC = BitField<otg_hs_device_t, 0, 1, READWRITE>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt
    constexpr auto EPDISD = BitField<otg_hs_device_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt
    constexpr auto TOC = BitField<otg_hs_device_t, 3, 1, READWRITE>{}; // bit offset: 3, bit width: 1, Timeout condition
    constexpr auto ITTXFE = BitField<otg_hs_device_t, 4, 1, READWRITE>{}; // bit offset: 4, bit width: 1, IN token received when TxFIFO is empty
    constexpr auto INEPNE = BitField<otg_hs_device_t, 6, 1, READWRITE>{}; // bit offset: 6, bit width: 1, IN endpoint NAK effective
    constexpr auto TXFE = BitField<otg_hs_device_t, 7, 1, READONLY>{}; // bit offset: 7, bit width: 1, Transmit FIFO empty
    constexpr auto TXFIFOUDRN = BitField<otg_hs_device_t, 8, 1, READWRITE>{}; // bit offset: 8, bit width: 1, Transmit Fifo Underrun
    constexpr auto BNA = BitField<otg_hs_device_t, 9, 1, READWRITE>{}; // bit offset: 9, bit width: 1, Buffer not available interrupt
    constexpr auto PKTDRPSTS = BitField<otg_hs_device_t, 11, 1, READWRITE>{}; // bit offset: 11, bit width: 1, Packet dropped status
    constexpr auto BERR = BitField<otg_hs_device_t, 12, 1, READWRITE>{}; // bit offset: 12, bit width: 1, Babble error interrupt
    constexpr auto NAK = BitField<otg_hs_device_t, 13, 1, READWRITE>{}; // bit offset: 13, bit width: 1, NAK interrupt
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000148u, 0, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(TOC), decltype(ITTXFE), decltype(INEPNE), decltype(TXFE), decltype(TXFIFOUDRN), decltype(BNA), decltype(PKTDRPSTS), decltype(BERR), decltype(NAK)> OTG_HS_DIEPINT2; // OTG device endpoint-2 interrupt register

    constexpr auto XFRC = BitField<otg_hs_device_t, 0, 1, READWRITE>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt
    constexpr auto EPDISD = BitField<otg_hs_device_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt
    constexpr auto TOC = BitField<otg_hs_device_t, 3, 1, READWRITE>{}; // bit offset: 3, bit width: 1, Timeout condition
    constexpr auto ITTXFE = BitField<otg_hs_device_t, 4, 1, READWRITE>{}; // bit offset: 4, bit width: 1, IN token received when TxFIFO is empty
    constexpr auto INEPNE = BitField<otg_hs_device_t, 6, 1, READWRITE>{}; // bit offset: 6, bit width: 1, IN endpoint NAK effective
    constexpr auto TXFE = BitField<otg_hs_device_t, 7, 1, READONLY>{}; // bit offset: 7, bit width: 1, Transmit FIFO empty
    constexpr auto TXFIFOUDRN = BitField<otg_hs_device_t, 8, 1, READWRITE>{}; // bit offset: 8, bit width: 1, Transmit Fifo Underrun
    constexpr auto BNA = BitField<otg_hs_device_t, 9, 1, READWRITE>{}; // bit offset: 9, bit width: 1, Buffer not available interrupt
    constexpr auto PKTDRPSTS = BitField<otg_hs_device_t, 11, 1, READWRITE>{}; // bit offset: 11, bit width: 1, Packet dropped status
    constexpr auto BERR = BitField<otg_hs_device_t, 12, 1, READWRITE>{}; // bit offset: 12, bit width: 1, Babble error interrupt
    constexpr auto NAK = BitField<otg_hs_device_t, 13, 1, READWRITE>{}; // bit offset: 13, bit width: 1, NAK interrupt
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000168u, 0, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(TOC), decltype(ITTXFE), decltype(INEPNE), decltype(TXFE), decltype(TXFIFOUDRN), decltype(BNA), decltype(PKTDRPSTS), decltype(BERR), decltype(NAK)> OTG_HS_DIEPINT3; // OTG device endpoint-3 interrupt register

    constexpr auto XFRC = BitField<otg_hs_device_t, 0, 1, READWRITE>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt
    constexpr auto EPDISD = BitField<otg_hs_device_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt
    constexpr auto TOC = BitField<otg_hs_device_t, 3, 1, READWRITE>{}; // bit offset: 3, bit width: 1, Timeout condition
    constexpr auto ITTXFE = BitField<otg_hs_device_t, 4, 1, READWRITE>{}; // bit offset: 4, bit width: 1, IN token received when TxFIFO is empty
    constexpr auto INEPNE = BitField<otg_hs_device_t, 6, 1, READWRITE>{}; // bit offset: 6, bit width: 1, IN endpoint NAK effective
    constexpr auto TXFE = BitField<otg_hs_device_t, 7, 1, READONLY>{}; // bit offset: 7, bit width: 1, Transmit FIFO empty
    constexpr auto TXFIFOUDRN = BitField<otg_hs_device_t, 8, 1, READWRITE>{}; // bit offset: 8, bit width: 1, Transmit Fifo Underrun
    constexpr auto BNA = BitField<otg_hs_device_t, 9, 1, READWRITE>{}; // bit offset: 9, bit width: 1, Buffer not available interrupt
    constexpr auto PKTDRPSTS = BitField<otg_hs_device_t, 11, 1, READWRITE>{}; // bit offset: 11, bit width: 1, Packet dropped status
    constexpr auto BERR = BitField<otg_hs_device_t, 12, 1, READWRITE>{}; // bit offset: 12, bit width: 1, Babble error interrupt
    constexpr auto NAK = BitField<otg_hs_device_t, 13, 1, READWRITE>{}; // bit offset: 13, bit width: 1, NAK interrupt
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000188u, 0, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(TOC), decltype(ITTXFE), decltype(INEPNE), decltype(TXFE), decltype(TXFIFOUDRN), decltype(BNA), decltype(PKTDRPSTS), decltype(BERR), decltype(NAK)> OTG_HS_DIEPINT4; // OTG device endpoint-4 interrupt register

    constexpr auto XFRC = BitField<otg_hs_device_t, 0, 1, READWRITE>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt
    constexpr auto EPDISD = BitField<otg_hs_device_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt
    constexpr auto TOC = BitField<otg_hs_device_t, 3, 1, READWRITE>{}; // bit offset: 3, bit width: 1, Timeout condition
    constexpr auto ITTXFE = BitField<otg_hs_device_t, 4, 1, READWRITE>{}; // bit offset: 4, bit width: 1, IN token received when TxFIFO is empty
    constexpr auto INEPNE = BitField<otg_hs_device_t, 6, 1, READWRITE>{}; // bit offset: 6, bit width: 1, IN endpoint NAK effective
    constexpr auto TXFE = BitField<otg_hs_device_t, 7, 1, READONLY>{}; // bit offset: 7, bit width: 1, Transmit FIFO empty
    constexpr auto TXFIFOUDRN = BitField<otg_hs_device_t, 8, 1, READWRITE>{}; // bit offset: 8, bit width: 1, Transmit Fifo Underrun
    constexpr auto BNA = BitField<otg_hs_device_t, 9, 1, READWRITE>{}; // bit offset: 9, bit width: 1, Buffer not available interrupt
    constexpr auto PKTDRPSTS = BitField<otg_hs_device_t, 11, 1, READWRITE>{}; // bit offset: 11, bit width: 1, Packet dropped status
    constexpr auto BERR = BitField<otg_hs_device_t, 12, 1, READWRITE>{}; // bit offset: 12, bit width: 1, Babble error interrupt
    constexpr auto NAK = BitField<otg_hs_device_t, 13, 1, READWRITE>{}; // bit offset: 13, bit width: 1, NAK interrupt
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x000001a8u, 0, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(TOC), decltype(ITTXFE), decltype(INEPNE), decltype(TXFE), decltype(TXFIFOUDRN), decltype(BNA), decltype(PKTDRPSTS), decltype(BERR), decltype(NAK)> OTG_HS_DIEPINT5; // OTG device endpoint-5 interrupt register

    constexpr auto XFRC = BitField<otg_hs_device_t, 0, 1, READWRITE>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt
    constexpr auto EPDISD = BitField<otg_hs_device_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt
    constexpr auto TOC = BitField<otg_hs_device_t, 3, 1, READWRITE>{}; // bit offset: 3, bit width: 1, Timeout condition
    constexpr auto ITTXFE = BitField<otg_hs_device_t, 4, 1, READWRITE>{}; // bit offset: 4, bit width: 1, IN token received when TxFIFO is empty
    constexpr auto INEPNE = BitField<otg_hs_device_t, 6, 1, READWRITE>{}; // bit offset: 6, bit width: 1, IN endpoint NAK effective
    constexpr auto TXFE = BitField<otg_hs_device_t, 7, 1, READONLY>{}; // bit offset: 7, bit width: 1, Transmit FIFO empty
    constexpr auto TXFIFOUDRN = BitField<otg_hs_device_t, 8, 1, READWRITE>{}; // bit offset: 8, bit width: 1, Transmit Fifo Underrun
    constexpr auto BNA = BitField<otg_hs_device_t, 9, 1, READWRITE>{}; // bit offset: 9, bit width: 1, Buffer not available interrupt
    constexpr auto PKTDRPSTS = BitField<otg_hs_device_t, 11, 1, READWRITE>{}; // bit offset: 11, bit width: 1, Packet dropped status
    constexpr auto BERR = BitField<otg_hs_device_t, 12, 1, READWRITE>{}; // bit offset: 12, bit width: 1, Babble error interrupt
    constexpr auto NAK = BitField<otg_hs_device_t, 13, 1, READWRITE>{}; // bit offset: 13, bit width: 1, NAK interrupt
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x000001c8u, 0, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(TOC), decltype(ITTXFE), decltype(INEPNE), decltype(TXFE), decltype(TXFIFOUDRN), decltype(BNA), decltype(PKTDRPSTS), decltype(BERR), decltype(NAK)> OTG_HS_DIEPINT6; // OTG device endpoint-6 interrupt register

    constexpr auto XFRC = BitField<otg_hs_device_t, 0, 1, READWRITE>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt
    constexpr auto EPDISD = BitField<otg_hs_device_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt
    constexpr auto TOC = BitField<otg_hs_device_t, 3, 1, READWRITE>{}; // bit offset: 3, bit width: 1, Timeout condition
    constexpr auto ITTXFE = BitField<otg_hs_device_t, 4, 1, READWRITE>{}; // bit offset: 4, bit width: 1, IN token received when TxFIFO is empty
    constexpr auto INEPNE = BitField<otg_hs_device_t, 6, 1, READWRITE>{}; // bit offset: 6, bit width: 1, IN endpoint NAK effective
    constexpr auto TXFE = BitField<otg_hs_device_t, 7, 1, READONLY>{}; // bit offset: 7, bit width: 1, Transmit FIFO empty
    constexpr auto TXFIFOUDRN = BitField<otg_hs_device_t, 8, 1, READWRITE>{}; // bit offset: 8, bit width: 1, Transmit Fifo Underrun
    constexpr auto BNA = BitField<otg_hs_device_t, 9, 1, READWRITE>{}; // bit offset: 9, bit width: 1, Buffer not available interrupt
    constexpr auto PKTDRPSTS = BitField<otg_hs_device_t, 11, 1, READWRITE>{}; // bit offset: 11, bit width: 1, Packet dropped status
    constexpr auto BERR = BitField<otg_hs_device_t, 12, 1, READWRITE>{}; // bit offset: 12, bit width: 1, Babble error interrupt
    constexpr auto NAK = BitField<otg_hs_device_t, 13, 1, READWRITE>{}; // bit offset: 13, bit width: 1, NAK interrupt
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x000001e8u, 0, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(TOC), decltype(ITTXFE), decltype(INEPNE), decltype(TXFE), decltype(TXFIFOUDRN), decltype(BNA), decltype(PKTDRPSTS), decltype(BERR), decltype(NAK)> OTG_HS_DIEPINT7; // OTG device endpoint-7 interrupt register

    constexpr auto XFRSIZ = BitField<otg_hs_device_t, 0, 7>{}; // bit offset: 0, bit width: 7, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_device_t, 19, 2>{}; // bit offset: 19, bit width: 2, Packet count
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000110u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT)> OTG_HS_DIEPTSIZ0; // OTG_HS device IN endpoint 0 transfer size register

    constexpr auto DMAADDR = BitField<otg_hs_device_t, 0, 32>{}; // bit offset: 0, bit width: 32, DMA address
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000114u, 0, READWRITE, decltype(DMAADDR)> OTG_HS_DIEPDMA1; // OTG_HS device endpoint-1 DMA address register

    constexpr auto DMAADDR = BitField<otg_hs_device_t, 0, 32>{}; // bit offset: 0, bit width: 32, DMA address
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000134u, 0, READWRITE, decltype(DMAADDR)> OTG_HS_DIEPDMA2; // OTG_HS device endpoint-2 DMA address register

    constexpr auto DMAADDR = BitField<otg_hs_device_t, 0, 32>{}; // bit offset: 0, bit width: 32, DMA address
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000154u, 0, READWRITE, decltype(DMAADDR)> OTG_HS_DIEPDMA3; // OTG_HS device endpoint-3 DMA address register

    constexpr auto DMAADDR = BitField<otg_hs_device_t, 0, 32>{}; // bit offset: 0, bit width: 32, DMA address
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000174u, 0, READWRITE, decltype(DMAADDR)> OTG_HS_DIEPDMA4; // OTG_HS device endpoint-4 DMA address register

    constexpr auto DMAADDR = BitField<otg_hs_device_t, 0, 32>{}; // bit offset: 0, bit width: 32, DMA address
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000194u, 0, READWRITE, decltype(DMAADDR)> OTG_HS_DIEPDMA5; // OTG_HS device endpoint-5 DMA address register

    constexpr auto INEPTFSAV = BitField<otg_hs_device_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN endpoint TxFIFO space avail
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000118u, 0, READONLY, decltype(INEPTFSAV)> OTG_HS_DTXFSTS0; // OTG_HS device IN endpoint transmit FIFO status register

    constexpr auto INEPTFSAV = BitField<otg_hs_device_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN endpoint TxFIFO space avail
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000138u, 0, READONLY, decltype(INEPTFSAV)> OTG_HS_DTXFSTS1; // OTG_HS device IN endpoint transmit FIFO status register

    constexpr auto INEPTFSAV = BitField<otg_hs_device_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN endpoint TxFIFO space avail
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000158u, 0, READONLY, decltype(INEPTFSAV)> OTG_HS_DTXFSTS2; // OTG_HS device IN endpoint transmit FIFO status register

    constexpr auto INEPTFSAV = BitField<otg_hs_device_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN endpoint TxFIFO space avail
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000178u, 0, READONLY, decltype(INEPTFSAV)> OTG_HS_DTXFSTS3; // OTG_HS device IN endpoint transmit FIFO status register

    constexpr auto INEPTFSAV = BitField<otg_hs_device_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN endpoint TxFIFO space avail
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000198u, 0, READONLY, decltype(INEPTFSAV)> OTG_HS_DTXFSTS4; // OTG_HS device IN endpoint transmit FIFO status register

    constexpr auto INEPTFSAV = BitField<otg_hs_device_t, 0, 16>{}; // bit offset: 0, bit width: 16, IN endpoint TxFIFO space avail
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x000001b8u, 0, READONLY, decltype(INEPTFSAV)> OTG_HS_DTXFSTS5; // OTG_HS device IN endpoint transmit FIFO status register

    constexpr auto XFRSIZ = BitField<otg_hs_device_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_device_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto MCNT = BitField<otg_hs_device_t, 29, 2>{}; // bit offset: 29, bit width: 2, Multi count
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000130u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(MCNT)> OTG_HS_DIEPTSIZ1; // OTG_HS device endpoint transfer size register

    constexpr auto XFRSIZ = BitField<otg_hs_device_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_device_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto MCNT = BitField<otg_hs_device_t, 29, 2>{}; // bit offset: 29, bit width: 2, Multi count
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000150u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(MCNT)> OTG_HS_DIEPTSIZ2; // OTG_HS device endpoint transfer size register

    constexpr auto XFRSIZ = BitField<otg_hs_device_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_device_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto MCNT = BitField<otg_hs_device_t, 29, 2>{}; // bit offset: 29, bit width: 2, Multi count
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000170u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(MCNT)> OTG_HS_DIEPTSIZ3; // OTG_HS device endpoint transfer size register

    constexpr auto XFRSIZ = BitField<otg_hs_device_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_device_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto MCNT = BitField<otg_hs_device_t, 29, 2>{}; // bit offset: 29, bit width: 2, Multi count
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000190u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(MCNT)> OTG_HS_DIEPTSIZ4; // OTG_HS device endpoint transfer size register

    constexpr auto XFRSIZ = BitField<otg_hs_device_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_device_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto MCNT = BitField<otg_hs_device_t, 29, 2>{}; // bit offset: 29, bit width: 2, Multi count
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x000001b0u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(MCNT)> OTG_HS_DIEPTSIZ5; // OTG_HS device endpoint transfer size register

    constexpr auto MPSIZ = BitField<otg_hs_device_t, 0, 2, READONLY>{}; // bit offset: 0, bit width: 2, Maximum packet size
    constexpr auto USBAEP = BitField<otg_hs_device_t, 15, 1, READONLY>{}; // bit offset: 15, bit width: 1, USB active endpoint
    constexpr auto NAKSTS = BitField<otg_hs_device_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, NAK status
    constexpr auto EPTYP = BitField<otg_hs_device_t, 18, 2, READONLY>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto SNPM = BitField<otg_hs_device_t, 20, 1, READWRITE>{}; // bit offset: 20, bit width: 1, Snoop mode
    constexpr auto Stall = BitField<otg_hs_device_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, STALL handshake
    constexpr auto CNAK = BitField<otg_hs_device_t, 26, 1, WRITEONLY>{}; // bit offset: 26, bit width: 1, Clear NAK
    constexpr auto SNAK = BitField<otg_hs_device_t, 27, 1, WRITEONLY>{}; // bit offset: 27, bit width: 1, Set NAK
    constexpr auto EPDIS = BitField<otg_hs_device_t, 30, 1, READONLY>{}; // bit offset: 30, bit width: 1, Endpoint disable
    constexpr auto EPENA = BitField<otg_hs_device_t, 31, 1, WRITEONLY>{}; // bit offset: 31, bit width: 1, Endpoint enable
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000300u, 32768, READWRITE, decltype(MPSIZ), decltype(USBAEP), decltype(NAKSTS), decltype(EPTYP), decltype(SNPM), decltype(Stall), decltype(CNAK), decltype(SNAK), decltype(EPDIS), decltype(EPENA)> OTG_HS_DOEPCTL0; // OTG_HS device control OUT endpoint 0 control register

    constexpr auto MPSIZ = BitField<otg_hs_device_t, 0, 11, READWRITE>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto USBAEP = BitField<otg_hs_device_t, 15, 1, READWRITE>{}; // bit offset: 15, bit width: 1, USB active endpoint
    constexpr auto EONUM_DPID = BitField<otg_hs_device_t, 16, 1, READONLY>{}; // bit offset: 16, bit width: 1, Even odd frame/Endpoint data PID
    constexpr auto NAKSTS = BitField<otg_hs_device_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, NAK status
    constexpr auto EPTYP = BitField<otg_hs_device_t, 18, 2, READWRITE>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto SNPM = BitField<otg_hs_device_t, 20, 1, READWRITE>{}; // bit offset: 20, bit width: 1, Snoop mode
    constexpr auto Stall = BitField<otg_hs_device_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, STALL handshake
    constexpr auto CNAK = BitField<otg_hs_device_t, 26, 1, WRITEONLY>{}; // bit offset: 26, bit width: 1, Clear NAK
    constexpr auto SNAK = BitField<otg_hs_device_t, 27, 1, WRITEONLY>{}; // bit offset: 27, bit width: 1, Set NAK
    constexpr auto SD0PID_SEVNFRM = BitField<otg_hs_device_t, 28, 1, WRITEONLY>{}; // bit offset: 28, bit width: 1, Set DATA0 PID/Set even frame
    constexpr auto SODDFRM = BitField<otg_hs_device_t, 29, 1, WRITEONLY>{}; // bit offset: 29, bit width: 1, Set odd frame
    constexpr auto EPDIS = BitField<otg_hs_device_t, 30, 1, READWRITE>{}; // bit offset: 30, bit width: 1, Endpoint disable
    constexpr auto EPENA = BitField<otg_hs_device_t, 31, 1, READWRITE>{}; // bit offset: 31, bit width: 1, Endpoint enable
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000320u, 0, READWRITE, decltype(MPSIZ), decltype(USBAEP), decltype(EONUM_DPID), decltype(NAKSTS), decltype(EPTYP), decltype(SNPM), decltype(Stall), decltype(CNAK), decltype(SNAK), decltype(SD0PID_SEVNFRM), decltype(SODDFRM), decltype(EPDIS), decltype(EPENA)> OTG_HS_DOEPCTL1; // OTG device endpoint-1 control register

    constexpr auto MPSIZ = BitField<otg_hs_device_t, 0, 11, READWRITE>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto USBAEP = BitField<otg_hs_device_t, 15, 1, READWRITE>{}; // bit offset: 15, bit width: 1, USB active endpoint
    constexpr auto EONUM_DPID = BitField<otg_hs_device_t, 16, 1, READONLY>{}; // bit offset: 16, bit width: 1, Even odd frame/Endpoint data PID
    constexpr auto NAKSTS = BitField<otg_hs_device_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, NAK status
    constexpr auto EPTYP = BitField<otg_hs_device_t, 18, 2, READWRITE>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto SNPM = BitField<otg_hs_device_t, 20, 1, READWRITE>{}; // bit offset: 20, bit width: 1, Snoop mode
    constexpr auto Stall = BitField<otg_hs_device_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, STALL handshake
    constexpr auto CNAK = BitField<otg_hs_device_t, 26, 1, WRITEONLY>{}; // bit offset: 26, bit width: 1, Clear NAK
    constexpr auto SNAK = BitField<otg_hs_device_t, 27, 1, WRITEONLY>{}; // bit offset: 27, bit width: 1, Set NAK
    constexpr auto SD0PID_SEVNFRM = BitField<otg_hs_device_t, 28, 1, WRITEONLY>{}; // bit offset: 28, bit width: 1, Set DATA0 PID/Set even frame
    constexpr auto SODDFRM = BitField<otg_hs_device_t, 29, 1, WRITEONLY>{}; // bit offset: 29, bit width: 1, Set odd frame
    constexpr auto EPDIS = BitField<otg_hs_device_t, 30, 1, READWRITE>{}; // bit offset: 30, bit width: 1, Endpoint disable
    constexpr auto EPENA = BitField<otg_hs_device_t, 31, 1, READWRITE>{}; // bit offset: 31, bit width: 1, Endpoint enable
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000340u, 0, READWRITE, decltype(MPSIZ), decltype(USBAEP), decltype(EONUM_DPID), decltype(NAKSTS), decltype(EPTYP), decltype(SNPM), decltype(Stall), decltype(CNAK), decltype(SNAK), decltype(SD0PID_SEVNFRM), decltype(SODDFRM), decltype(EPDIS), decltype(EPENA)> OTG_HS_DOEPCTL2; // OTG device endpoint-2 control register

    constexpr auto MPSIZ = BitField<otg_hs_device_t, 0, 11, READWRITE>{}; // bit offset: 0, bit width: 11, Maximum packet size
    constexpr auto USBAEP = BitField<otg_hs_device_t, 15, 1, READWRITE>{}; // bit offset: 15, bit width: 1, USB active endpoint
    constexpr auto EONUM_DPID = BitField<otg_hs_device_t, 16, 1, READONLY>{}; // bit offset: 16, bit width: 1, Even odd frame/Endpoint data PID
    constexpr auto NAKSTS = BitField<otg_hs_device_t, 17, 1, READONLY>{}; // bit offset: 17, bit width: 1, NAK status
    constexpr auto EPTYP = BitField<otg_hs_device_t, 18, 2, READWRITE>{}; // bit offset: 18, bit width: 2, Endpoint type
    constexpr auto SNPM = BitField<otg_hs_device_t, 20, 1, READWRITE>{}; // bit offset: 20, bit width: 1, Snoop mode
    constexpr auto Stall = BitField<otg_hs_device_t, 21, 1, READWRITE>{}; // bit offset: 21, bit width: 1, STALL handshake
    constexpr auto CNAK = BitField<otg_hs_device_t, 26, 1, WRITEONLY>{}; // bit offset: 26, bit width: 1, Clear NAK
    constexpr auto SNAK = BitField<otg_hs_device_t, 27, 1, WRITEONLY>{}; // bit offset: 27, bit width: 1, Set NAK
    constexpr auto SD0PID_SEVNFRM = BitField<otg_hs_device_t, 28, 1, WRITEONLY>{}; // bit offset: 28, bit width: 1, Set DATA0 PID/Set even frame
    constexpr auto SODDFRM = BitField<otg_hs_device_t, 29, 1, WRITEONLY>{}; // bit offset: 29, bit width: 1, Set odd frame
    constexpr auto EPDIS = BitField<otg_hs_device_t, 30, 1, READWRITE>{}; // bit offset: 30, bit width: 1, Endpoint disable
    constexpr auto EPENA = BitField<otg_hs_device_t, 31, 1, READWRITE>{}; // bit offset: 31, bit width: 1, Endpoint enable
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000360u, 0, READWRITE, decltype(MPSIZ), decltype(USBAEP), decltype(EONUM_DPID), decltype(NAKSTS), decltype(EPTYP), decltype(SNPM), decltype(Stall), decltype(CNAK), decltype(SNAK), decltype(SD0PID_SEVNFRM), decltype(SODDFRM), decltype(EPDIS), decltype(EPENA)> OTG_HS_DOEPCTL3; // OTG device endpoint-3 control register

    constexpr auto XFRC = BitField<otg_hs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt
    constexpr auto EPDISD = BitField<otg_hs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt
    constexpr auto STUP = BitField<otg_hs_device_t, 3, 1>{}; // bit offset: 3, bit width: 1, SETUP phase done
    constexpr auto OTEPDIS = BitField<otg_hs_device_t, 4, 1>{}; // bit offset: 4, bit width: 1, OUT token received when endpoint disabled
    constexpr auto B2BSTUP = BitField<otg_hs_device_t, 6, 1>{}; // bit offset: 6, bit width: 1, Back-to-back SETUP packets received
    constexpr auto NYET = BitField<otg_hs_device_t, 14, 1>{}; // bit offset: 14, bit width: 1, NYET interrupt
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000308u, 128, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(STUP), decltype(OTEPDIS), decltype(B2BSTUP), decltype(NYET)> OTG_HS_DOEPINT0; // OTG_HS device endpoint-0 interrupt register

    constexpr auto XFRC = BitField<otg_hs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt
    constexpr auto EPDISD = BitField<otg_hs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt
    constexpr auto STUP = BitField<otg_hs_device_t, 3, 1>{}; // bit offset: 3, bit width: 1, SETUP phase done
    constexpr auto OTEPDIS = BitField<otg_hs_device_t, 4, 1>{}; // bit offset: 4, bit width: 1, OUT token received when endpoint disabled
    constexpr auto B2BSTUP = BitField<otg_hs_device_t, 6, 1>{}; // bit offset: 6, bit width: 1, Back-to-back SETUP packets received
    constexpr auto NYET = BitField<otg_hs_device_t, 14, 1>{}; // bit offset: 14, bit width: 1, NYET interrupt
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000328u, 0, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(STUP), decltype(OTEPDIS), decltype(B2BSTUP), decltype(NYET)> OTG_HS_DOEPINT1; // OTG_HS device endpoint-1 interrupt register

    constexpr auto XFRC = BitField<otg_hs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt
    constexpr auto EPDISD = BitField<otg_hs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt
    constexpr auto STUP = BitField<otg_hs_device_t, 3, 1>{}; // bit offset: 3, bit width: 1, SETUP phase done
    constexpr auto OTEPDIS = BitField<otg_hs_device_t, 4, 1>{}; // bit offset: 4, bit width: 1, OUT token received when endpoint disabled
    constexpr auto B2BSTUP = BitField<otg_hs_device_t, 6, 1>{}; // bit offset: 6, bit width: 1, Back-to-back SETUP packets received
    constexpr auto NYET = BitField<otg_hs_device_t, 14, 1>{}; // bit offset: 14, bit width: 1, NYET interrupt
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000348u, 0, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(STUP), decltype(OTEPDIS), decltype(B2BSTUP), decltype(NYET)> OTG_HS_DOEPINT2; // OTG_HS device endpoint-2 interrupt register

    constexpr auto XFRC = BitField<otg_hs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt
    constexpr auto EPDISD = BitField<otg_hs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt
    constexpr auto STUP = BitField<otg_hs_device_t, 3, 1>{}; // bit offset: 3, bit width: 1, SETUP phase done
    constexpr auto OTEPDIS = BitField<otg_hs_device_t, 4, 1>{}; // bit offset: 4, bit width: 1, OUT token received when endpoint disabled
    constexpr auto B2BSTUP = BitField<otg_hs_device_t, 6, 1>{}; // bit offset: 6, bit width: 1, Back-to-back SETUP packets received
    constexpr auto NYET = BitField<otg_hs_device_t, 14, 1>{}; // bit offset: 14, bit width: 1, NYET interrupt
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000368u, 0, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(STUP), decltype(OTEPDIS), decltype(B2BSTUP), decltype(NYET)> OTG_HS_DOEPINT3; // OTG_HS device endpoint-3 interrupt register

    constexpr auto XFRC = BitField<otg_hs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt
    constexpr auto EPDISD = BitField<otg_hs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt
    constexpr auto STUP = BitField<otg_hs_device_t, 3, 1>{}; // bit offset: 3, bit width: 1, SETUP phase done
    constexpr auto OTEPDIS = BitField<otg_hs_device_t, 4, 1>{}; // bit offset: 4, bit width: 1, OUT token received when endpoint disabled
    constexpr auto B2BSTUP = BitField<otg_hs_device_t, 6, 1>{}; // bit offset: 6, bit width: 1, Back-to-back SETUP packets received
    constexpr auto NYET = BitField<otg_hs_device_t, 14, 1>{}; // bit offset: 14, bit width: 1, NYET interrupt
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000388u, 0, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(STUP), decltype(OTEPDIS), decltype(B2BSTUP), decltype(NYET)> OTG_HS_DOEPINT4; // OTG_HS device endpoint-4 interrupt register

    constexpr auto XFRC = BitField<otg_hs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt
    constexpr auto EPDISD = BitField<otg_hs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt
    constexpr auto STUP = BitField<otg_hs_device_t, 3, 1>{}; // bit offset: 3, bit width: 1, SETUP phase done
    constexpr auto OTEPDIS = BitField<otg_hs_device_t, 4, 1>{}; // bit offset: 4, bit width: 1, OUT token received when endpoint disabled
    constexpr auto B2BSTUP = BitField<otg_hs_device_t, 6, 1>{}; // bit offset: 6, bit width: 1, Back-to-back SETUP packets received
    constexpr auto NYET = BitField<otg_hs_device_t, 14, 1>{}; // bit offset: 14, bit width: 1, NYET interrupt
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x000003a8u, 0, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(STUP), decltype(OTEPDIS), decltype(B2BSTUP), decltype(NYET)> OTG_HS_DOEPINT5; // OTG_HS device endpoint-5 interrupt register

    constexpr auto XFRC = BitField<otg_hs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt
    constexpr auto EPDISD = BitField<otg_hs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt
    constexpr auto STUP = BitField<otg_hs_device_t, 3, 1>{}; // bit offset: 3, bit width: 1, SETUP phase done
    constexpr auto OTEPDIS = BitField<otg_hs_device_t, 4, 1>{}; // bit offset: 4, bit width: 1, OUT token received when endpoint disabled
    constexpr auto B2BSTUP = BitField<otg_hs_device_t, 6, 1>{}; // bit offset: 6, bit width: 1, Back-to-back SETUP packets received
    constexpr auto NYET = BitField<otg_hs_device_t, 14, 1>{}; // bit offset: 14, bit width: 1, NYET interrupt
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x000003c8u, 0, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(STUP), decltype(OTEPDIS), decltype(B2BSTUP), decltype(NYET)> OTG_HS_DOEPINT6; // OTG_HS device endpoint-6 interrupt register

    constexpr auto XFRC = BitField<otg_hs_device_t, 0, 1>{}; // bit offset: 0, bit width: 1, Transfer completed interrupt
    constexpr auto EPDISD = BitField<otg_hs_device_t, 1, 1>{}; // bit offset: 1, bit width: 1, Endpoint disabled interrupt
    constexpr auto STUP = BitField<otg_hs_device_t, 3, 1>{}; // bit offset: 3, bit width: 1, SETUP phase done
    constexpr auto OTEPDIS = BitField<otg_hs_device_t, 4, 1>{}; // bit offset: 4, bit width: 1, OUT token received when endpoint disabled
    constexpr auto B2BSTUP = BitField<otg_hs_device_t, 6, 1>{}; // bit offset: 6, bit width: 1, Back-to-back SETUP packets received
    constexpr auto NYET = BitField<otg_hs_device_t, 14, 1>{}; // bit offset: 14, bit width: 1, NYET interrupt
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x000003e8u, 0, READWRITE, decltype(XFRC), decltype(EPDISD), decltype(STUP), decltype(OTEPDIS), decltype(B2BSTUP), decltype(NYET)> OTG_HS_DOEPINT7; // OTG_HS device endpoint-7 interrupt register

    constexpr auto XFRSIZ = BitField<otg_hs_device_t, 0, 7>{}; // bit offset: 0, bit width: 7, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_device_t, 19, 1>{}; // bit offset: 19, bit width: 1, Packet count
    constexpr auto STUPCNT = BitField<otg_hs_device_t, 29, 2>{}; // bit offset: 29, bit width: 2, SETUP packet count
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000310u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(STUPCNT)> OTG_HS_DOEPTSIZ0; // OTG_HS device endpoint-1 transfer size register

    constexpr auto XFRSIZ = BitField<otg_hs_device_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_device_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto RXDPID_STUPCNT = BitField<otg_hs_device_t, 29, 2>{}; // bit offset: 29, bit width: 2, Received data PID/SETUP packet count
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000330u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(RXDPID_STUPCNT)> OTG_HS_DOEPTSIZ1; // OTG_HS device endpoint-2 transfer size register

    constexpr auto XFRSIZ = BitField<otg_hs_device_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_device_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto RXDPID_STUPCNT = BitField<otg_hs_device_t, 29, 2>{}; // bit offset: 29, bit width: 2, Received data PID/SETUP packet count
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000350u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(RXDPID_STUPCNT)> OTG_HS_DOEPTSIZ2; // OTG_HS device endpoint-3 transfer size register

    constexpr auto XFRSIZ = BitField<otg_hs_device_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_device_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto RXDPID_STUPCNT = BitField<otg_hs_device_t, 29, 2>{}; // bit offset: 29, bit width: 2, Received data PID/SETUP packet count
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000370u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(RXDPID_STUPCNT)> OTG_HS_DOEPTSIZ3; // OTG_HS device endpoint-4 transfer size register

    constexpr auto XFRSIZ = BitField<otg_hs_device_t, 0, 19>{}; // bit offset: 0, bit width: 19, Transfer size
    constexpr auto PKTCNT = BitField<otg_hs_device_t, 19, 10>{}; // bit offset: 19, bit width: 10, Packet count
    constexpr auto RXDPID_STUPCNT = BitField<otg_hs_device_t, 29, 2>{}; // bit offset: 29, bit width: 2, Received data PID/SETUP packet count
    static Register<std::uint32_t, OTG_HS_DEVICE_BASE_ADDRESS + 0x00000390u, 0, READWRITE, decltype(XFRSIZ), decltype(PKTCNT), decltype(RXDPID_STUPCNT)> OTG_HS_DOEPTSIZ4; // OTG_HS device endpoint-5 transfer size register

} // namespace OTG_HS_DEVICE