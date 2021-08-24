#include <Register.hpp>




namespace DCMI
{
    struct dcmi_t{};

    constexpr std::uint32_t DCMI_BASE_ADDRESS = 0x50050000u;

    constexpr auto CAPTURE = BitField<dcmi_t, 0, 1>{}; // bit offset: 0, bit width: 1, Capture enable
    constexpr auto CM = BitField<dcmi_t, 1, 1>{}; // bit offset: 1, bit width: 1, Capture mode
    constexpr auto CROP = BitField<dcmi_t, 2, 1>{}; // bit offset: 2, bit width: 1, Crop feature
    constexpr auto JPEG = BitField<dcmi_t, 3, 1>{}; // bit offset: 3, bit width: 1, JPEG format
    constexpr auto ESS = BitField<dcmi_t, 4, 1>{}; // bit offset: 4, bit width: 1, Embedded synchronization select
    constexpr auto PCKPOL = BitField<dcmi_t, 5, 1>{}; // bit offset: 5, bit width: 1, Pixel clock polarity
    constexpr auto HSPOL = BitField<dcmi_t, 6, 1>{}; // bit offset: 6, bit width: 1, Horizontal synchronization polarity
    constexpr auto VSPOL = BitField<dcmi_t, 7, 1>{}; // bit offset: 7, bit width: 1, Vertical synchronization polarity
    constexpr auto FCRC = BitField<dcmi_t, 8, 2>{}; // bit offset: 8, bit width: 2, Frame capture rate control
    constexpr auto EDM = BitField<dcmi_t, 10, 2>{}; // bit offset: 10, bit width: 2, Extended data mode
    constexpr auto ENABLE = BitField<dcmi_t, 14, 1>{}; // bit offset: 14, bit width: 1, DCMI enable
    static Register<std::uint32_t, DCMI_BASE_ADDRESS + 0x00000000u, 0, READWRITE, decltype(CAPTURE), decltype(CM), decltype(CROP), decltype(JPEG), decltype(ESS), decltype(PCKPOL), decltype(HSPOL), decltype(VSPOL), decltype(FCRC), decltype(EDM), decltype(ENABLE)> CR; // control register 1

    constexpr auto HSYNC = BitField<dcmi_t, 0, 1>{}; // bit offset: 0, bit width: 1, HSYNC
    constexpr auto VSYNC = BitField<dcmi_t, 1, 1>{}; // bit offset: 1, bit width: 1, VSYNC
    constexpr auto FNE = BitField<dcmi_t, 2, 1>{}; // bit offset: 2, bit width: 1, FIFO not empty
    static Register<std::uint32_t, DCMI_BASE_ADDRESS + 0x00000004u, 0, READONLY, decltype(HSYNC), decltype(VSYNC), decltype(FNE)> SR; // status register

    constexpr auto FRAME_RIS = BitField<dcmi_t, 0, 1>{}; // bit offset: 0, bit width: 1, Capture complete raw interrupt status
    constexpr auto OVR_RIS = BitField<dcmi_t, 1, 1>{}; // bit offset: 1, bit width: 1, Overrun raw interrupt status
    constexpr auto ERR_RIS = BitField<dcmi_t, 2, 1>{}; // bit offset: 2, bit width: 1, Synchronization error raw interrupt status
    constexpr auto VSYNC_RIS = BitField<dcmi_t, 3, 1>{}; // bit offset: 3, bit width: 1, VSYNC raw interrupt status
    constexpr auto LINE_RIS = BitField<dcmi_t, 4, 1>{}; // bit offset: 4, bit width: 1, Line raw interrupt status
    static Register<std::uint32_t, DCMI_BASE_ADDRESS + 0x00000008u, 0, READONLY, decltype(FRAME_RIS), decltype(OVR_RIS), decltype(ERR_RIS), decltype(VSYNC_RIS), decltype(LINE_RIS)> RIS; // raw interrupt status register

    constexpr auto FRAME_IE = BitField<dcmi_t, 0, 1>{}; // bit offset: 0, bit width: 1, Capture complete interrupt enable
    constexpr auto OVR_IE = BitField<dcmi_t, 1, 1>{}; // bit offset: 1, bit width: 1, Overrun interrupt enable
    constexpr auto ERR_IE = BitField<dcmi_t, 2, 1>{}; // bit offset: 2, bit width: 1, Synchronization error interrupt enable
    constexpr auto VSYNC_IE = BitField<dcmi_t, 3, 1>{}; // bit offset: 3, bit width: 1, VSYNC interrupt enable
    constexpr auto LINE_IE = BitField<dcmi_t, 4, 1>{}; // bit offset: 4, bit width: 1, Line interrupt enable
    static Register<std::uint32_t, DCMI_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, decltype(FRAME_IE), decltype(OVR_IE), decltype(ERR_IE), decltype(VSYNC_IE), decltype(LINE_IE)> IER; // interrupt enable register

    constexpr auto FRAME_MIS = BitField<dcmi_t, 0, 1>{}; // bit offset: 0, bit width: 1, Capture complete masked interrupt status
    constexpr auto OVR_MIS = BitField<dcmi_t, 1, 1>{}; // bit offset: 1, bit width: 1, Overrun masked interrupt status
    constexpr auto ERR_MIS = BitField<dcmi_t, 2, 1>{}; // bit offset: 2, bit width: 1, Synchronization error masked interrupt status
    constexpr auto VSYNC_MIS = BitField<dcmi_t, 3, 1>{}; // bit offset: 3, bit width: 1, VSYNC masked interrupt status
    constexpr auto LINE_MIS = BitField<dcmi_t, 4, 1>{}; // bit offset: 4, bit width: 1, Line masked interrupt status
    static Register<std::uint32_t, DCMI_BASE_ADDRESS + 0x00000010u, 0, READONLY, decltype(FRAME_MIS), decltype(OVR_MIS), decltype(ERR_MIS), decltype(VSYNC_MIS), decltype(LINE_MIS)> MIS; // masked interrupt status register

    constexpr auto FRAME_ISC = BitField<dcmi_t, 0, 1>{}; // bit offset: 0, bit width: 1, Capture complete interrupt status clear
    constexpr auto OVR_ISC = BitField<dcmi_t, 1, 1>{}; // bit offset: 1, bit width: 1, Overrun interrupt status clear
    constexpr auto ERR_ISC = BitField<dcmi_t, 2, 1>{}; // bit offset: 2, bit width: 1, Synchronization error interrupt status clear
    constexpr auto VSYNC_ISC = BitField<dcmi_t, 3, 1>{}; // bit offset: 3, bit width: 1, Vertical synch interrupt status clear
    constexpr auto LINE_ISC = BitField<dcmi_t, 4, 1>{}; // bit offset: 4, bit width: 1, line interrupt status clear
    static Register<std::uint32_t, DCMI_BASE_ADDRESS + 0x00000014u, 0, WRITEONLY, decltype(FRAME_ISC), decltype(OVR_ISC), decltype(ERR_ISC), decltype(VSYNC_ISC), decltype(LINE_ISC)> ICR; // interrupt clear register

    constexpr auto FSC = BitField<dcmi_t, 0, 8>{}; // bit offset: 0, bit width: 8, Frame start delimiter code
    constexpr auto LSC = BitField<dcmi_t, 8, 8>{}; // bit offset: 8, bit width: 8, Line start delimiter code
    constexpr auto LEC = BitField<dcmi_t, 16, 8>{}; // bit offset: 16, bit width: 8, Line end delimiter code
    constexpr auto FEC = BitField<dcmi_t, 24, 8>{}; // bit offset: 24, bit width: 8, Frame end delimiter code
    static Register<std::uint32_t, DCMI_BASE_ADDRESS + 0x00000018u, 0, READWRITE, decltype(FSC), decltype(LSC), decltype(LEC), decltype(FEC)> ESCR; // embedded synchronization code register

    constexpr auto FSU = BitField<dcmi_t, 0, 8>{}; // bit offset: 0, bit width: 8, Frame start delimiter unmask
    constexpr auto LSU = BitField<dcmi_t, 8, 8>{}; // bit offset: 8, bit width: 8, Line start delimiter unmask
    constexpr auto LEU = BitField<dcmi_t, 16, 8>{}; // bit offset: 16, bit width: 8, Line end delimiter unmask
    constexpr auto FEU = BitField<dcmi_t, 24, 8>{}; // bit offset: 24, bit width: 8, Frame end delimiter unmask
    static Register<std::uint32_t, DCMI_BASE_ADDRESS + 0x0000001cu, 0, READWRITE, decltype(FSU), decltype(LSU), decltype(LEU), decltype(FEU)> ESUR; // embedded synchronization unmask register

    constexpr auto HOFFCNT = BitField<dcmi_t, 0, 14>{}; // bit offset: 0, bit width: 14, Horizontal offset count
    constexpr auto VST = BitField<dcmi_t, 16, 13>{}; // bit offset: 16, bit width: 13, Vertical start line count
    static Register<std::uint32_t, DCMI_BASE_ADDRESS + 0x00000020u, 0, READWRITE, decltype(HOFFCNT), decltype(VST)> CWSTRT; // crop window start

    constexpr auto CAPCNT = BitField<dcmi_t, 0, 14>{}; // bit offset: 0, bit width: 14, Capture count
    constexpr auto VLINE = BitField<dcmi_t, 16, 14>{}; // bit offset: 16, bit width: 14, Vertical line count
    static Register<std::uint32_t, DCMI_BASE_ADDRESS + 0x00000024u, 0, READWRITE, decltype(CAPCNT), decltype(VLINE)> CWSIZE; // crop window size

    constexpr auto Byte0 = BitField<dcmi_t, 0, 8>{}; // bit offset: 0, bit width: 8, Data byte 0
    constexpr auto Byte1 = BitField<dcmi_t, 8, 8>{}; // bit offset: 8, bit width: 8, Data byte 1
    constexpr auto Byte2 = BitField<dcmi_t, 16, 8>{}; // bit offset: 16, bit width: 8, Data byte 2
    constexpr auto Byte3 = BitField<dcmi_t, 24, 8>{}; // bit offset: 24, bit width: 8, Data byte 3
    static Register<std::uint32_t, DCMI_BASE_ADDRESS + 0x00000028u, 0, READONLY, decltype(Byte0), decltype(Byte1), decltype(Byte2), decltype(Byte3)> DR; // data register

} // namespace DCMI