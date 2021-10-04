#include <Register.hpp>

namespace DMA1
{
    struct dma1_t{};

    constexpr std::uint32_t DMA1_BASE_ADDRESS = 0x40026000u;

    constexpr auto FEIF0 = BitField<dma1_t, 0, 1, "FEIF0">{}; // bit offset: 0, bit width: 1, Stream x FIFO error interrupt flag (x=3..0)
    constexpr auto DMEIF0 = BitField<dma1_t, 2, 1, "DMEIF0">{}; // bit offset: 2, bit width: 1, Stream x direct mode error interrupt flag (x=3..0)
    constexpr auto TEIF0 = BitField<dma1_t, 3, 1, "TEIF0">{}; // bit offset: 3, bit width: 1, Stream x transfer error interrupt flag (x=3..0)
    constexpr auto HTIF0 = BitField<dma1_t, 4, 1, "HTIF0">{}; // bit offset: 4, bit width: 1, Stream x half transfer interrupt flag (x=3..0)
    constexpr auto TCIF0 = BitField<dma1_t, 5, 1, "TCIF0">{}; // bit offset: 5, bit width: 1, Stream x transfer complete interrupt flag (x = 3..0)
    constexpr auto FEIF1 = BitField<dma1_t, 6, 1, "FEIF1">{}; // bit offset: 6, bit width: 1, Stream x FIFO error interrupt flag (x=3..0)
    constexpr auto DMEIF1 = BitField<dma1_t, 8, 1, "DMEIF1">{}; // bit offset: 8, bit width: 1, Stream x direct mode error interrupt flag (x=3..0)
    constexpr auto TEIF1 = BitField<dma1_t, 9, 1, "TEIF1">{}; // bit offset: 9, bit width: 1, Stream x transfer error interrupt flag (x=3..0)
    constexpr auto HTIF1 = BitField<dma1_t, 10, 1, "HTIF1">{}; // bit offset: 10, bit width: 1, Stream x half transfer interrupt flag (x=3..0)
    constexpr auto TCIF1 = BitField<dma1_t, 11, 1, "TCIF1">{}; // bit offset: 11, bit width: 1, Stream x transfer complete interrupt flag (x = 3..0)
    constexpr auto FEIF2 = BitField<dma1_t, 16, 1, "FEIF2">{}; // bit offset: 16, bit width: 1, Stream x FIFO error interrupt flag (x=3..0)
    constexpr auto DMEIF2 = BitField<dma1_t, 18, 1, "DMEIF2">{}; // bit offset: 18, bit width: 1, Stream x direct mode error interrupt flag (x=3..0)
    constexpr auto TEIF2 = BitField<dma1_t, 19, 1, "TEIF2">{}; // bit offset: 19, bit width: 1, Stream x transfer error interrupt flag (x=3..0)
    constexpr auto HTIF2 = BitField<dma1_t, 20, 1, "HTIF2">{}; // bit offset: 20, bit width: 1, Stream x half transfer interrupt flag (x=3..0)
    constexpr auto TCIF2 = BitField<dma1_t, 21, 1, "TCIF2">{}; // bit offset: 21, bit width: 1, Stream x transfer complete interrupt flag (x = 3..0)
    constexpr auto FEIF3 = BitField<dma1_t, 22, 1, "FEIF3">{}; // bit offset: 22, bit width: 1, Stream x FIFO error interrupt flag (x=3..0)
    constexpr auto DMEIF3 = BitField<dma1_t, 24, 1, "DMEIF3">{}; // bit offset: 24, bit width: 1, Stream x direct mode error interrupt flag (x=3..0)
    constexpr auto TEIF3 = BitField<dma1_t, 25, 1, "TEIF3">{}; // bit offset: 25, bit width: 1, Stream x transfer error interrupt flag (x=3..0)
    constexpr auto HTIF3 = BitField<dma1_t, 26, 1, "HTIF3">{}; // bit offset: 26, bit width: 1, Stream x half transfer interrupt flag (x=3..0)
    constexpr auto TCIF3 = BitField<dma1_t, 27, 1, "TCIF3">{}; // bit offset: 27, bit width: 1, Stream x transfer complete interrupt flag (x = 3..0)
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000000u, 0, READONLY, "LISR", decltype(FEIF0), decltype(DMEIF0), decltype(TEIF0), decltype(HTIF0), decltype(TCIF0), decltype(FEIF1), decltype(DMEIF1), decltype(TEIF1), decltype(HTIF1), decltype(TCIF1), decltype(FEIF2), decltype(DMEIF2), decltype(TEIF2), decltype(HTIF2), decltype(TCIF2), decltype(FEIF3), decltype(DMEIF3), decltype(TEIF3), decltype(HTIF3), decltype(TCIF3)> LISR; // low interrupt status register

    constexpr auto FEIF4 = BitField<dma1_t, 0, 1, "FEIF4">{}; // bit offset: 0, bit width: 1, Stream x FIFO error interrupt flag (x=7..4)
    constexpr auto DMEIF4 = BitField<dma1_t, 2, 1, "DMEIF4">{}; // bit offset: 2, bit width: 1, Stream x direct mode error interrupt flag (x=7..4)
    constexpr auto TEIF4 = BitField<dma1_t, 3, 1, "TEIF4">{}; // bit offset: 3, bit width: 1, Stream x transfer error interrupt flag (x=7..4)
    constexpr auto HTIF4 = BitField<dma1_t, 4, 1, "HTIF4">{}; // bit offset: 4, bit width: 1, Stream x half transfer interrupt flag (x=7..4)
    constexpr auto TCIF4 = BitField<dma1_t, 5, 1, "TCIF4">{}; // bit offset: 5, bit width: 1, Stream x transfer complete interrupt flag (x=7..4)
    constexpr auto FEIF5 = BitField<dma1_t, 6, 1, "FEIF5">{}; // bit offset: 6, bit width: 1, Stream x FIFO error interrupt flag (x=7..4)
    constexpr auto DMEIF5 = BitField<dma1_t, 8, 1, "DMEIF5">{}; // bit offset: 8, bit width: 1, Stream x direct mode error interrupt flag (x=7..4)
    constexpr auto TEIF5 = BitField<dma1_t, 9, 1, "TEIF5">{}; // bit offset: 9, bit width: 1, Stream x transfer error interrupt flag (x=7..4)
    constexpr auto HTIF5 = BitField<dma1_t, 10, 1, "HTIF5">{}; // bit offset: 10, bit width: 1, Stream x half transfer interrupt flag (x=7..4)
    constexpr auto TCIF5 = BitField<dma1_t, 11, 1, "TCIF5">{}; // bit offset: 11, bit width: 1, Stream x transfer complete interrupt flag (x=7..4)
    constexpr auto FEIF6 = BitField<dma1_t, 16, 1, "FEIF6">{}; // bit offset: 16, bit width: 1, Stream x FIFO error interrupt flag (x=7..4)
    constexpr auto DMEIF6 = BitField<dma1_t, 18, 1, "DMEIF6">{}; // bit offset: 18, bit width: 1, Stream x direct mode error interrupt flag (x=7..4)
    constexpr auto TEIF6 = BitField<dma1_t, 19, 1, "TEIF6">{}; // bit offset: 19, bit width: 1, Stream x transfer error interrupt flag (x=7..4)
    constexpr auto HTIF6 = BitField<dma1_t, 20, 1, "HTIF6">{}; // bit offset: 20, bit width: 1, Stream x half transfer interrupt flag (x=7..4)
    constexpr auto TCIF6 = BitField<dma1_t, 21, 1, "TCIF6">{}; // bit offset: 21, bit width: 1, Stream x transfer complete interrupt flag (x=7..4)
    constexpr auto FEIF7 = BitField<dma1_t, 22, 1, "FEIF7">{}; // bit offset: 22, bit width: 1, Stream x FIFO error interrupt flag (x=7..4)
    constexpr auto DMEIF7 = BitField<dma1_t, 24, 1, "DMEIF7">{}; // bit offset: 24, bit width: 1, Stream x direct mode error interrupt flag (x=7..4)
    constexpr auto TEIF7 = BitField<dma1_t, 25, 1, "TEIF7">{}; // bit offset: 25, bit width: 1, Stream x transfer error interrupt flag (x=7..4)
    constexpr auto HTIF7 = BitField<dma1_t, 26, 1, "HTIF7">{}; // bit offset: 26, bit width: 1, Stream x half transfer interrupt flag (x=7..4)
    constexpr auto TCIF7 = BitField<dma1_t, 27, 1, "TCIF7">{}; // bit offset: 27, bit width: 1, Stream x transfer complete interrupt flag (x=7..4)
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000004u, 0, READONLY, "HISR", decltype(FEIF4), decltype(DMEIF4), decltype(TEIF4), decltype(HTIF4), decltype(TCIF4), decltype(FEIF5), decltype(DMEIF5), decltype(TEIF5), decltype(HTIF5), decltype(TCIF5), decltype(FEIF6), decltype(DMEIF6), decltype(TEIF6), decltype(HTIF6), decltype(TCIF6), decltype(FEIF7), decltype(DMEIF7), decltype(TEIF7), decltype(HTIF7), decltype(TCIF7)> HISR; // high interrupt status register

    constexpr auto CFEIF0 = BitField<dma1_t, 0, 1, "CFEIF0">{}; // bit offset: 0, bit width: 1, Stream x clear FIFO error interrupt flag (x = 3..0)
    constexpr auto CDMEIF0 = BitField<dma1_t, 2, 1, "CDMEIF0">{}; // bit offset: 2, bit width: 1, Stream x clear direct mode error interrupt flag (x = 3..0)
    constexpr auto CTEIF0 = BitField<dma1_t, 3, 1, "CTEIF0">{}; // bit offset: 3, bit width: 1, Stream x clear transfer error interrupt flag (x = 3..0)
    constexpr auto CHTIF0 = BitField<dma1_t, 4, 1, "CHTIF0">{}; // bit offset: 4, bit width: 1, Stream x clear half transfer interrupt flag (x = 3..0)
    constexpr auto CTCIF0 = BitField<dma1_t, 5, 1, "CTCIF0">{}; // bit offset: 5, bit width: 1, Stream x clear transfer complete interrupt flag (x = 3..0)
    constexpr auto CFEIF1 = BitField<dma1_t, 6, 1, "CFEIF1">{}; // bit offset: 6, bit width: 1, Stream x clear FIFO error interrupt flag (x = 3..0)
    constexpr auto CDMEIF1 = BitField<dma1_t, 8, 1, "CDMEIF1">{}; // bit offset: 8, bit width: 1, Stream x clear direct mode error interrupt flag (x = 3..0)
    constexpr auto CTEIF1 = BitField<dma1_t, 9, 1, "CTEIF1">{}; // bit offset: 9, bit width: 1, Stream x clear transfer error interrupt flag (x = 3..0)
    constexpr auto CHTIF1 = BitField<dma1_t, 10, 1, "CHTIF1">{}; // bit offset: 10, bit width: 1, Stream x clear half transfer interrupt flag (x = 3..0)
    constexpr auto CTCIF1 = BitField<dma1_t, 11, 1, "CTCIF1">{}; // bit offset: 11, bit width: 1, Stream x clear transfer complete interrupt flag (x = 3..0)
    constexpr auto CFEIF2 = BitField<dma1_t, 16, 1, "CFEIF2">{}; // bit offset: 16, bit width: 1, Stream x clear FIFO error interrupt flag (x = 3..0)
    constexpr auto CDMEIF2 = BitField<dma1_t, 18, 1, "CDMEIF2">{}; // bit offset: 18, bit width: 1, Stream x clear direct mode error interrupt flag (x = 3..0)
    constexpr auto CTEIF2 = BitField<dma1_t, 19, 1, "CTEIF2">{}; // bit offset: 19, bit width: 1, Stream x clear transfer error interrupt flag (x = 3..0)
    constexpr auto CHTIF2 = BitField<dma1_t, 20, 1, "CHTIF2">{}; // bit offset: 20, bit width: 1, Stream x clear half transfer interrupt flag (x = 3..0)
    constexpr auto CTCIF2 = BitField<dma1_t, 21, 1, "CTCIF2">{}; // bit offset: 21, bit width: 1, Stream x clear transfer complete interrupt flag (x = 3..0)
    constexpr auto CFEIF3 = BitField<dma1_t, 22, 1, "CFEIF3">{}; // bit offset: 22, bit width: 1, Stream x clear FIFO error interrupt flag (x = 3..0)
    constexpr auto CDMEIF3 = BitField<dma1_t, 24, 1, "CDMEIF3">{}; // bit offset: 24, bit width: 1, Stream x clear direct mode error interrupt flag (x = 3..0)
    constexpr auto CTEIF3 = BitField<dma1_t, 25, 1, "CTEIF3">{}; // bit offset: 25, bit width: 1, Stream x clear transfer error interrupt flag (x = 3..0)
    constexpr auto CHTIF3 = BitField<dma1_t, 26, 1, "CHTIF3">{}; // bit offset: 26, bit width: 1, Stream x clear half transfer interrupt flag (x = 3..0)
    constexpr auto CTCIF3 = BitField<dma1_t, 27, 1, "CTCIF3">{}; // bit offset: 27, bit width: 1, Stream x clear transfer complete interrupt flag (x = 3..0)
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000008u, 0, READWRITE, "LIFCR", decltype(CFEIF0), decltype(CDMEIF0), decltype(CTEIF0), decltype(CHTIF0), decltype(CTCIF0), decltype(CFEIF1), decltype(CDMEIF1), decltype(CTEIF1), decltype(CHTIF1), decltype(CTCIF1), decltype(CFEIF2), decltype(CDMEIF2), decltype(CTEIF2), decltype(CHTIF2), decltype(CTCIF2), decltype(CFEIF3), decltype(CDMEIF3), decltype(CTEIF3), decltype(CHTIF3), decltype(CTCIF3)> LIFCR; // low interrupt flag clear register

    constexpr auto CFEIF4 = BitField<dma1_t, 0, 1, "CFEIF4">{}; // bit offset: 0, bit width: 1, Stream x clear FIFO error interrupt flag (x = 7..4)
    constexpr auto CDMEIF4 = BitField<dma1_t, 2, 1, "CDMEIF4">{}; // bit offset: 2, bit width: 1, Stream x clear direct mode error interrupt flag (x = 7..4)
    constexpr auto CTEIF4 = BitField<dma1_t, 3, 1, "CTEIF4">{}; // bit offset: 3, bit width: 1, Stream x clear transfer error interrupt flag (x = 7..4)
    constexpr auto CHTIF4 = BitField<dma1_t, 4, 1, "CHTIF4">{}; // bit offset: 4, bit width: 1, Stream x clear half transfer interrupt flag (x = 7..4)
    constexpr auto CTCIF4 = BitField<dma1_t, 5, 1, "CTCIF4">{}; // bit offset: 5, bit width: 1, Stream x clear transfer complete interrupt flag (x = 7..4)
    constexpr auto CFEIF5 = BitField<dma1_t, 6, 1, "CFEIF5">{}; // bit offset: 6, bit width: 1, Stream x clear FIFO error interrupt flag (x = 7..4)
    constexpr auto CDMEIF5 = BitField<dma1_t, 8, 1, "CDMEIF5">{}; // bit offset: 8, bit width: 1, Stream x clear direct mode error interrupt flag (x = 7..4)
    constexpr auto CTEIF5 = BitField<dma1_t, 9, 1, "CTEIF5">{}; // bit offset: 9, bit width: 1, Stream x clear transfer error interrupt flag (x = 7..4)
    constexpr auto CHTIF5 = BitField<dma1_t, 10, 1, "CHTIF5">{}; // bit offset: 10, bit width: 1, Stream x clear half transfer interrupt flag (x = 7..4)
    constexpr auto CTCIF5 = BitField<dma1_t, 11, 1, "CTCIF5">{}; // bit offset: 11, bit width: 1, Stream x clear transfer complete interrupt flag (x = 7..4)
    constexpr auto CFEIF6 = BitField<dma1_t, 16, 1, "CFEIF6">{}; // bit offset: 16, bit width: 1, Stream x clear FIFO error interrupt flag (x = 7..4)
    constexpr auto CDMEIF6 = BitField<dma1_t, 18, 1, "CDMEIF6">{}; // bit offset: 18, bit width: 1, Stream x clear direct mode error interrupt flag (x = 7..4)
    constexpr auto CTEIF6 = BitField<dma1_t, 19, 1, "CTEIF6">{}; // bit offset: 19, bit width: 1, Stream x clear transfer error interrupt flag (x = 7..4)
    constexpr auto CHTIF6 = BitField<dma1_t, 20, 1, "CHTIF6">{}; // bit offset: 20, bit width: 1, Stream x clear half transfer interrupt flag (x = 7..4)
    constexpr auto CTCIF6 = BitField<dma1_t, 21, 1, "CTCIF6">{}; // bit offset: 21, bit width: 1, Stream x clear transfer complete interrupt flag (x = 7..4)
    constexpr auto CFEIF7 = BitField<dma1_t, 22, 1, "CFEIF7">{}; // bit offset: 22, bit width: 1, Stream x clear FIFO error interrupt flag (x = 7..4)
    constexpr auto CDMEIF7 = BitField<dma1_t, 24, 1, "CDMEIF7">{}; // bit offset: 24, bit width: 1, Stream x clear direct mode error interrupt flag (x = 7..4)
    constexpr auto CTEIF7 = BitField<dma1_t, 25, 1, "CTEIF7">{}; // bit offset: 25, bit width: 1, Stream x clear transfer error interrupt flag (x = 7..4)
    constexpr auto CHTIF7 = BitField<dma1_t, 26, 1, "CHTIF7">{}; // bit offset: 26, bit width: 1, Stream x clear half transfer interrupt flag (x = 7..4)
    constexpr auto CTCIF7 = BitField<dma1_t, 27, 1, "CTCIF7">{}; // bit offset: 27, bit width: 1, Stream x clear transfer complete interrupt flag (x = 7..4)
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, "HIFCR", decltype(CFEIF4), decltype(CDMEIF4), decltype(CTEIF4), decltype(CHTIF4), decltype(CTCIF4), decltype(CFEIF5), decltype(CDMEIF5), decltype(CTEIF5), decltype(CHTIF5), decltype(CTCIF5), decltype(CFEIF6), decltype(CDMEIF6), decltype(CTEIF6), decltype(CHTIF6), decltype(CTCIF6), decltype(CFEIF7), decltype(CDMEIF7), decltype(CTEIF7), decltype(CHTIF7), decltype(CTCIF7)> HIFCR; // high interrupt flag clear register

    constexpr auto EN = BitField<dma1_t, 0, 1, "EN">{}; // bit offset: 0, bit width: 1, Stream enable / flag stream ready when read low
    constexpr auto DMEIE = BitField<dma1_t, 1, 1, "DMEIE">{}; // bit offset: 1, bit width: 1, Direct mode error interrupt enable
    constexpr auto TEIE = BitField<dma1_t, 2, 1, "TEIE">{}; // bit offset: 2, bit width: 1, Transfer error interrupt enable
    constexpr auto HTIE = BitField<dma1_t, 3, 1, "HTIE">{}; // bit offset: 3, bit width: 1, Half transfer interrupt enable
    constexpr auto TCIE = BitField<dma1_t, 4, 1, "TCIE">{}; // bit offset: 4, bit width: 1, Transfer complete interrupt enable
    constexpr auto PFCTRL = BitField<dma1_t, 5, 1, "PFCTRL">{}; // bit offset: 5, bit width: 1, Peripheral flow controller
    constexpr auto DIR = BitField<dma1_t, 6, 2, "DIR">{}; // bit offset: 6, bit width: 2, Data transfer direction
    constexpr auto CIRC = BitField<dma1_t, 8, 1, "CIRC">{}; // bit offset: 8, bit width: 1, Circular mode
    constexpr auto PINC = BitField<dma1_t, 9, 1, "PINC">{}; // bit offset: 9, bit width: 1, Peripheral increment mode
    constexpr auto MINC = BitField<dma1_t, 10, 1, "MINC">{}; // bit offset: 10, bit width: 1, Memory increment mode
    constexpr auto PSIZE = BitField<dma1_t, 11, 2, "PSIZE">{}; // bit offset: 11, bit width: 2, Peripheral data size
    constexpr auto MSIZE = BitField<dma1_t, 13, 2, "MSIZE">{}; // bit offset: 13, bit width: 2, Memory data size
    constexpr auto PINCOS = BitField<dma1_t, 15, 1, "PINCOS">{}; // bit offset: 15, bit width: 1, Peripheral increment offset size
    constexpr auto PL = BitField<dma1_t, 16, 2, "PL">{}; // bit offset: 16, bit width: 2, Priority level
    constexpr auto DBM = BitField<dma1_t, 18, 1, "DBM">{}; // bit offset: 18, bit width: 1, Double buffer mode
    constexpr auto CT = BitField<dma1_t, 19, 1, "CT">{}; // bit offset: 19, bit width: 1, Current target (only in double buffer mode)
    constexpr auto PBURST = BitField<dma1_t, 21, 2, "PBURST">{}; // bit offset: 21, bit width: 2, Peripheral burst transfer configuration
    constexpr auto MBURST = BitField<dma1_t, 23, 2, "MBURST">{}; // bit offset: 23, bit width: 2, Memory burst transfer configuration
    constexpr auto CHSEL = BitField<dma1_t, 25, 3, "CHSEL">{}; // bit offset: 25, bit width: 3, Channel selection
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000010u, 0, READWRITE, "S0CR", decltype(EN), decltype(DMEIE), decltype(TEIE), decltype(HTIE), decltype(TCIE), decltype(PFCTRL), decltype(DIR), decltype(CIRC), decltype(PINC), decltype(MINC), decltype(PSIZE), decltype(MSIZE), decltype(PINCOS), decltype(PL), decltype(DBM), decltype(CT), decltype(PBURST), decltype(MBURST), decltype(CHSEL)> S0CR; // stream x configuration register

    constexpr auto NDT = BitField<dma1_t, 0, 16, "NDT">{}; // bit offset: 0, bit width: 16, Number of data items to transfer
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000014u, 0, READWRITE, "S0NDTR", decltype(NDT)> S0NDTR; // stream x number of data register

    constexpr auto PA = BitField<dma1_t, 0, 32, "PA">{}; // bit offset: 0, bit width: 32, Peripheral address
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000018u, 0, READWRITE, "S0PAR", decltype(PA)> S0PAR; // stream x peripheral address register

    constexpr auto M0A = BitField<dma1_t, 0, 32, "M0A">{}; // bit offset: 0, bit width: 32, Memory 0 address
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x0000001cu, 0, READWRITE, "S0M0AR", decltype(M0A)> S0M0AR; // stream x memory 0 address register

    constexpr auto M1A = BitField<dma1_t, 0, 32, "M1A">{}; // bit offset: 0, bit width: 32, Memory 1 address (used in case of Double buffer mode)
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000020u, 0, READWRITE, "S0M1AR", decltype(M1A)> S0M1AR; // stream x memory 1 address register

    constexpr auto FTH = BitField<dma1_t, 0, 2, "FTH", READWRITE>{}; // bit offset: 0, bit width: 2, FIFO threshold selection
    constexpr auto DMDIS = BitField<dma1_t, 2, 1, "DMDIS", READWRITE>{}; // bit offset: 2, bit width: 1, Direct mode disable
    constexpr auto FS = BitField<dma1_t, 3, 3, "FS", READONLY>{}; // bit offset: 3, bit width: 3, FIFO status
    constexpr auto FEIE = BitField<dma1_t, 7, 1, "FEIE", READWRITE>{}; // bit offset: 7, bit width: 1, FIFO error interrupt enable
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000024u, 33, READWRITE, "S0FCR", decltype(FTH), decltype(DMDIS), decltype(FS), decltype(FEIE)> S0FCR; // stream x FIFO control register

    constexpr auto EN = BitField<dma1_t, 0, 1, "EN">{}; // bit offset: 0, bit width: 1, Stream enable / flag stream ready when read low
    constexpr auto DMEIE = BitField<dma1_t, 1, 1, "DMEIE">{}; // bit offset: 1, bit width: 1, Direct mode error interrupt enable
    constexpr auto TEIE = BitField<dma1_t, 2, 1, "TEIE">{}; // bit offset: 2, bit width: 1, Transfer error interrupt enable
    constexpr auto HTIE = BitField<dma1_t, 3, 1, "HTIE">{}; // bit offset: 3, bit width: 1, Half transfer interrupt enable
    constexpr auto TCIE = BitField<dma1_t, 4, 1, "TCIE">{}; // bit offset: 4, bit width: 1, Transfer complete interrupt enable
    constexpr auto PFCTRL = BitField<dma1_t, 5, 1, "PFCTRL">{}; // bit offset: 5, bit width: 1, Peripheral flow controller
    constexpr auto DIR = BitField<dma1_t, 6, 2, "DIR">{}; // bit offset: 6, bit width: 2, Data transfer direction
    constexpr auto CIRC = BitField<dma1_t, 8, 1, "CIRC">{}; // bit offset: 8, bit width: 1, Circular mode
    constexpr auto PINC = BitField<dma1_t, 9, 1, "PINC">{}; // bit offset: 9, bit width: 1, Peripheral increment mode
    constexpr auto MINC = BitField<dma1_t, 10, 1, "MINC">{}; // bit offset: 10, bit width: 1, Memory increment mode
    constexpr auto PSIZE = BitField<dma1_t, 11, 2, "PSIZE">{}; // bit offset: 11, bit width: 2, Peripheral data size
    constexpr auto MSIZE = BitField<dma1_t, 13, 2, "MSIZE">{}; // bit offset: 13, bit width: 2, Memory data size
    constexpr auto PINCOS = BitField<dma1_t, 15, 1, "PINCOS">{}; // bit offset: 15, bit width: 1, Peripheral increment offset size
    constexpr auto PL = BitField<dma1_t, 16, 2, "PL">{}; // bit offset: 16, bit width: 2, Priority level
    constexpr auto DBM = BitField<dma1_t, 18, 1, "DBM">{}; // bit offset: 18, bit width: 1, Double buffer mode
    constexpr auto CT = BitField<dma1_t, 19, 1, "CT">{}; // bit offset: 19, bit width: 1, Current target (only in double buffer mode)
    constexpr auto PBURST = BitField<dma1_t, 21, 2, "PBURST">{}; // bit offset: 21, bit width: 2, Peripheral burst transfer configuration
    constexpr auto MBURST = BitField<dma1_t, 23, 2, "MBURST">{}; // bit offset: 23, bit width: 2, Memory burst transfer configuration
    constexpr auto CHSEL = BitField<dma1_t, 25, 3, "CHSEL">{}; // bit offset: 25, bit width: 3, Channel selection
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000028u, 0, READWRITE, "S1CR", decltype(EN), decltype(DMEIE), decltype(TEIE), decltype(HTIE), decltype(TCIE), decltype(PFCTRL), decltype(DIR), decltype(CIRC), decltype(PINC), decltype(MINC), decltype(PSIZE), decltype(MSIZE), decltype(PINCOS), decltype(PL), decltype(DBM), decltype(CT), decltype(PBURST), decltype(MBURST), decltype(CHSEL)> S1CR; // stream x configuration register

    constexpr auto NDT = BitField<dma1_t, 0, 16, "NDT">{}; // bit offset: 0, bit width: 16, Number of data items to transfer
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x0000002cu, 0, READWRITE, "S1NDTR", decltype(NDT)> S1NDTR; // stream x number of data register

    constexpr auto PA = BitField<dma1_t, 0, 32, "PA">{}; // bit offset: 0, bit width: 32, Peripheral address
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000030u, 0, READWRITE, "S1PAR", decltype(PA)> S1PAR; // stream x peripheral address register

    constexpr auto M0A = BitField<dma1_t, 0, 32, "M0A">{}; // bit offset: 0, bit width: 32, Memory 0 address
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000034u, 0, READWRITE, "S1M0AR", decltype(M0A)> S1M0AR; // stream x memory 0 address register

    constexpr auto M1A = BitField<dma1_t, 0, 32, "M1A">{}; // bit offset: 0, bit width: 32, Memory 1 address (used in case of Double buffer mode)
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000038u, 0, READWRITE, "S1M1AR", decltype(M1A)> S1M1AR; // stream x memory 1 address register

    constexpr auto FTH = BitField<dma1_t, 0, 2, "FTH", READWRITE>{}; // bit offset: 0, bit width: 2, FIFO threshold selection
    constexpr auto DMDIS = BitField<dma1_t, 2, 1, "DMDIS", READWRITE>{}; // bit offset: 2, bit width: 1, Direct mode disable
    constexpr auto FS = BitField<dma1_t, 3, 3, "FS", READONLY>{}; // bit offset: 3, bit width: 3, FIFO status
    constexpr auto FEIE = BitField<dma1_t, 7, 1, "FEIE", READWRITE>{}; // bit offset: 7, bit width: 1, FIFO error interrupt enable
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x0000003cu, 33, READWRITE, "S1FCR", decltype(FTH), decltype(DMDIS), decltype(FS), decltype(FEIE)> S1FCR; // stream x FIFO control register

    constexpr auto EN = BitField<dma1_t, 0, 1, "EN">{}; // bit offset: 0, bit width: 1, Stream enable / flag stream ready when read low
    constexpr auto DMEIE = BitField<dma1_t, 1, 1, "DMEIE">{}; // bit offset: 1, bit width: 1, Direct mode error interrupt enable
    constexpr auto TEIE = BitField<dma1_t, 2, 1, "TEIE">{}; // bit offset: 2, bit width: 1, Transfer error interrupt enable
    constexpr auto HTIE = BitField<dma1_t, 3, 1, "HTIE">{}; // bit offset: 3, bit width: 1, Half transfer interrupt enable
    constexpr auto TCIE = BitField<dma1_t, 4, 1, "TCIE">{}; // bit offset: 4, bit width: 1, Transfer complete interrupt enable
    constexpr auto PFCTRL = BitField<dma1_t, 5, 1, "PFCTRL">{}; // bit offset: 5, bit width: 1, Peripheral flow controller
    constexpr auto DIR = BitField<dma1_t, 6, 2, "DIR">{}; // bit offset: 6, bit width: 2, Data transfer direction
    constexpr auto CIRC = BitField<dma1_t, 8, 1, "CIRC">{}; // bit offset: 8, bit width: 1, Circular mode
    constexpr auto PINC = BitField<dma1_t, 9, 1, "PINC">{}; // bit offset: 9, bit width: 1, Peripheral increment mode
    constexpr auto MINC = BitField<dma1_t, 10, 1, "MINC">{}; // bit offset: 10, bit width: 1, Memory increment mode
    constexpr auto PSIZE = BitField<dma1_t, 11, 2, "PSIZE">{}; // bit offset: 11, bit width: 2, Peripheral data size
    constexpr auto MSIZE = BitField<dma1_t, 13, 2, "MSIZE">{}; // bit offset: 13, bit width: 2, Memory data size
    constexpr auto PINCOS = BitField<dma1_t, 15, 1, "PINCOS">{}; // bit offset: 15, bit width: 1, Peripheral increment offset size
    constexpr auto PL = BitField<dma1_t, 16, 2, "PL">{}; // bit offset: 16, bit width: 2, Priority level
    constexpr auto DBM = BitField<dma1_t, 18, 1, "DBM">{}; // bit offset: 18, bit width: 1, Double buffer mode
    constexpr auto CT = BitField<dma1_t, 19, 1, "CT">{}; // bit offset: 19, bit width: 1, Current target (only in double buffer mode)
    constexpr auto PBURST = BitField<dma1_t, 21, 2, "PBURST">{}; // bit offset: 21, bit width: 2, Peripheral burst transfer configuration
    constexpr auto MBURST = BitField<dma1_t, 23, 2, "MBURST">{}; // bit offset: 23, bit width: 2, Memory burst transfer configuration
    constexpr auto CHSEL = BitField<dma1_t, 25, 3, "CHSEL">{}; // bit offset: 25, bit width: 3, Channel selection
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000040u, 0, READWRITE, "S2CR", decltype(EN), decltype(DMEIE), decltype(TEIE), decltype(HTIE), decltype(TCIE), decltype(PFCTRL), decltype(DIR), decltype(CIRC), decltype(PINC), decltype(MINC), decltype(PSIZE), decltype(MSIZE), decltype(PINCOS), decltype(PL), decltype(DBM), decltype(CT), decltype(PBURST), decltype(MBURST), decltype(CHSEL)> S2CR; // stream x configuration register

    constexpr auto NDT = BitField<dma1_t, 0, 16, "NDT">{}; // bit offset: 0, bit width: 16, Number of data items to transfer
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000044u, 0, READWRITE, "S2NDTR", decltype(NDT)> S2NDTR; // stream x number of data register

    constexpr auto PA = BitField<dma1_t, 0, 32, "PA">{}; // bit offset: 0, bit width: 32, Peripheral address
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000048u, 0, READWRITE, "S2PAR", decltype(PA)> S2PAR; // stream x peripheral address register

    constexpr auto M0A = BitField<dma1_t, 0, 32, "M0A">{}; // bit offset: 0, bit width: 32, Memory 0 address
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x0000004cu, 0, READWRITE, "S2M0AR", decltype(M0A)> S2M0AR; // stream x memory 0 address register

    constexpr auto M1A = BitField<dma1_t, 0, 32, "M1A">{}; // bit offset: 0, bit width: 32, Memory 1 address (used in case of Double buffer mode)
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000050u, 0, READWRITE, "S2M1AR", decltype(M1A)> S2M1AR; // stream x memory 1 address register

    constexpr auto FTH = BitField<dma1_t, 0, 2, "FTH", READWRITE>{}; // bit offset: 0, bit width: 2, FIFO threshold selection
    constexpr auto DMDIS = BitField<dma1_t, 2, 1, "DMDIS", READWRITE>{}; // bit offset: 2, bit width: 1, Direct mode disable
    constexpr auto FS = BitField<dma1_t, 3, 3, "FS", READONLY>{}; // bit offset: 3, bit width: 3, FIFO status
    constexpr auto FEIE = BitField<dma1_t, 7, 1, "FEIE", READWRITE>{}; // bit offset: 7, bit width: 1, FIFO error interrupt enable
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000054u, 33, READWRITE, "S2FCR", decltype(FTH), decltype(DMDIS), decltype(FS), decltype(FEIE)> S2FCR; // stream x FIFO control register

    constexpr auto EN = BitField<dma1_t, 0, 1, "EN">{}; // bit offset: 0, bit width: 1, Stream enable / flag stream ready when read low
    constexpr auto DMEIE = BitField<dma1_t, 1, 1, "DMEIE">{}; // bit offset: 1, bit width: 1, Direct mode error interrupt enable
    constexpr auto TEIE = BitField<dma1_t, 2, 1, "TEIE">{}; // bit offset: 2, bit width: 1, Transfer error interrupt enable
    constexpr auto HTIE = BitField<dma1_t, 3, 1, "HTIE">{}; // bit offset: 3, bit width: 1, Half transfer interrupt enable
    constexpr auto TCIE = BitField<dma1_t, 4, 1, "TCIE">{}; // bit offset: 4, bit width: 1, Transfer complete interrupt enable
    constexpr auto PFCTRL = BitField<dma1_t, 5, 1, "PFCTRL">{}; // bit offset: 5, bit width: 1, Peripheral flow controller
    constexpr auto DIR = BitField<dma1_t, 6, 2, "DIR">{}; // bit offset: 6, bit width: 2, Data transfer direction
    constexpr auto CIRC = BitField<dma1_t, 8, 1, "CIRC">{}; // bit offset: 8, bit width: 1, Circular mode
    constexpr auto PINC = BitField<dma1_t, 9, 1, "PINC">{}; // bit offset: 9, bit width: 1, Peripheral increment mode
    constexpr auto MINC = BitField<dma1_t, 10, 1, "MINC">{}; // bit offset: 10, bit width: 1, Memory increment mode
    constexpr auto PSIZE = BitField<dma1_t, 11, 2, "PSIZE">{}; // bit offset: 11, bit width: 2, Peripheral data size
    constexpr auto MSIZE = BitField<dma1_t, 13, 2, "MSIZE">{}; // bit offset: 13, bit width: 2, Memory data size
    constexpr auto PINCOS = BitField<dma1_t, 15, 1, "PINCOS">{}; // bit offset: 15, bit width: 1, Peripheral increment offset size
    constexpr auto PL = BitField<dma1_t, 16, 2, "PL">{}; // bit offset: 16, bit width: 2, Priority level
    constexpr auto DBM = BitField<dma1_t, 18, 1, "DBM">{}; // bit offset: 18, bit width: 1, Double buffer mode
    constexpr auto CT = BitField<dma1_t, 19, 1, "CT">{}; // bit offset: 19, bit width: 1, Current target (only in double buffer mode)
    constexpr auto PBURST = BitField<dma1_t, 21, 2, "PBURST">{}; // bit offset: 21, bit width: 2, Peripheral burst transfer configuration
    constexpr auto MBURST = BitField<dma1_t, 23, 2, "MBURST">{}; // bit offset: 23, bit width: 2, Memory burst transfer configuration
    constexpr auto CHSEL = BitField<dma1_t, 25, 3, "CHSEL">{}; // bit offset: 25, bit width: 3, Channel selection
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000058u, 0, READWRITE, "S3CR", decltype(EN), decltype(DMEIE), decltype(TEIE), decltype(HTIE), decltype(TCIE), decltype(PFCTRL), decltype(DIR), decltype(CIRC), decltype(PINC), decltype(MINC), decltype(PSIZE), decltype(MSIZE), decltype(PINCOS), decltype(PL), decltype(DBM), decltype(CT), decltype(PBURST), decltype(MBURST), decltype(CHSEL)> S3CR; // stream x configuration register

    constexpr auto NDT = BitField<dma1_t, 0, 16, "NDT">{}; // bit offset: 0, bit width: 16, Number of data items to transfer
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x0000005cu, 0, READWRITE, "S3NDTR", decltype(NDT)> S3NDTR; // stream x number of data register

    constexpr auto PA = BitField<dma1_t, 0, 32, "PA">{}; // bit offset: 0, bit width: 32, Peripheral address
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000060u, 0, READWRITE, "S3PAR", decltype(PA)> S3PAR; // stream x peripheral address register

    constexpr auto M0A = BitField<dma1_t, 0, 32, "M0A">{}; // bit offset: 0, bit width: 32, Memory 0 address
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000064u, 0, READWRITE, "S3M0AR", decltype(M0A)> S3M0AR; // stream x memory 0 address register

    constexpr auto M1A = BitField<dma1_t, 0, 32, "M1A">{}; // bit offset: 0, bit width: 32, Memory 1 address (used in case of Double buffer mode)
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000068u, 0, READWRITE, "S3M1AR", decltype(M1A)> S3M1AR; // stream x memory 1 address register

    constexpr auto FTH = BitField<dma1_t, 0, 2, "FTH", READWRITE>{}; // bit offset: 0, bit width: 2, FIFO threshold selection
    constexpr auto DMDIS = BitField<dma1_t, 2, 1, "DMDIS", READWRITE>{}; // bit offset: 2, bit width: 1, Direct mode disable
    constexpr auto FS = BitField<dma1_t, 3, 3, "FS", READONLY>{}; // bit offset: 3, bit width: 3, FIFO status
    constexpr auto FEIE = BitField<dma1_t, 7, 1, "FEIE", READWRITE>{}; // bit offset: 7, bit width: 1, FIFO error interrupt enable
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x0000006cu, 33, READWRITE, "S3FCR", decltype(FTH), decltype(DMDIS), decltype(FS), decltype(FEIE)> S3FCR; // stream x FIFO control register

    constexpr auto EN = BitField<dma1_t, 0, 1, "EN">{}; // bit offset: 0, bit width: 1, Stream enable / flag stream ready when read low
    constexpr auto DMEIE = BitField<dma1_t, 1, 1, "DMEIE">{}; // bit offset: 1, bit width: 1, Direct mode error interrupt enable
    constexpr auto TEIE = BitField<dma1_t, 2, 1, "TEIE">{}; // bit offset: 2, bit width: 1, Transfer error interrupt enable
    constexpr auto HTIE = BitField<dma1_t, 3, 1, "HTIE">{}; // bit offset: 3, bit width: 1, Half transfer interrupt enable
    constexpr auto TCIE = BitField<dma1_t, 4, 1, "TCIE">{}; // bit offset: 4, bit width: 1, Transfer complete interrupt enable
    constexpr auto PFCTRL = BitField<dma1_t, 5, 1, "PFCTRL">{}; // bit offset: 5, bit width: 1, Peripheral flow controller
    constexpr auto DIR = BitField<dma1_t, 6, 2, "DIR">{}; // bit offset: 6, bit width: 2, Data transfer direction
    constexpr auto CIRC = BitField<dma1_t, 8, 1, "CIRC">{}; // bit offset: 8, bit width: 1, Circular mode
    constexpr auto PINC = BitField<dma1_t, 9, 1, "PINC">{}; // bit offset: 9, bit width: 1, Peripheral increment mode
    constexpr auto MINC = BitField<dma1_t, 10, 1, "MINC">{}; // bit offset: 10, bit width: 1, Memory increment mode
    constexpr auto PSIZE = BitField<dma1_t, 11, 2, "PSIZE">{}; // bit offset: 11, bit width: 2, Peripheral data size
    constexpr auto MSIZE = BitField<dma1_t, 13, 2, "MSIZE">{}; // bit offset: 13, bit width: 2, Memory data size
    constexpr auto PINCOS = BitField<dma1_t, 15, 1, "PINCOS">{}; // bit offset: 15, bit width: 1, Peripheral increment offset size
    constexpr auto PL = BitField<dma1_t, 16, 2, "PL">{}; // bit offset: 16, bit width: 2, Priority level
    constexpr auto DBM = BitField<dma1_t, 18, 1, "DBM">{}; // bit offset: 18, bit width: 1, Double buffer mode
    constexpr auto CT = BitField<dma1_t, 19, 1, "CT">{}; // bit offset: 19, bit width: 1, Current target (only in double buffer mode)
    constexpr auto PBURST = BitField<dma1_t, 21, 2, "PBURST">{}; // bit offset: 21, bit width: 2, Peripheral burst transfer configuration
    constexpr auto MBURST = BitField<dma1_t, 23, 2, "MBURST">{}; // bit offset: 23, bit width: 2, Memory burst transfer configuration
    constexpr auto CHSEL = BitField<dma1_t, 25, 3, "CHSEL">{}; // bit offset: 25, bit width: 3, Channel selection
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000070u, 0, READWRITE, "S4CR", decltype(EN), decltype(DMEIE), decltype(TEIE), decltype(HTIE), decltype(TCIE), decltype(PFCTRL), decltype(DIR), decltype(CIRC), decltype(PINC), decltype(MINC), decltype(PSIZE), decltype(MSIZE), decltype(PINCOS), decltype(PL), decltype(DBM), decltype(CT), decltype(PBURST), decltype(MBURST), decltype(CHSEL)> S4CR; // stream x configuration register

    constexpr auto NDT = BitField<dma1_t, 0, 16, "NDT">{}; // bit offset: 0, bit width: 16, Number of data items to transfer
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000074u, 0, READWRITE, "S4NDTR", decltype(NDT)> S4NDTR; // stream x number of data register

    constexpr auto PA = BitField<dma1_t, 0, 32, "PA">{}; // bit offset: 0, bit width: 32, Peripheral address
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000078u, 0, READWRITE, "S4PAR", decltype(PA)> S4PAR; // stream x peripheral address register

    constexpr auto M0A = BitField<dma1_t, 0, 32, "M0A">{}; // bit offset: 0, bit width: 32, Memory 0 address
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x0000007cu, 0, READWRITE, "S4M0AR", decltype(M0A)> S4M0AR; // stream x memory 0 address register

    constexpr auto M1A = BitField<dma1_t, 0, 32, "M1A">{}; // bit offset: 0, bit width: 32, Memory 1 address (used in case of Double buffer mode)
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000080u, 0, READWRITE, "S4M1AR", decltype(M1A)> S4M1AR; // stream x memory 1 address register

    constexpr auto FTH = BitField<dma1_t, 0, 2, "FTH", READWRITE>{}; // bit offset: 0, bit width: 2, FIFO threshold selection
    constexpr auto DMDIS = BitField<dma1_t, 2, 1, "DMDIS", READWRITE>{}; // bit offset: 2, bit width: 1, Direct mode disable
    constexpr auto FS = BitField<dma1_t, 3, 3, "FS", READONLY>{}; // bit offset: 3, bit width: 3, FIFO status
    constexpr auto FEIE = BitField<dma1_t, 7, 1, "FEIE", READWRITE>{}; // bit offset: 7, bit width: 1, FIFO error interrupt enable
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000084u, 33, READWRITE, "S4FCR", decltype(FTH), decltype(DMDIS), decltype(FS), decltype(FEIE)> S4FCR; // stream x FIFO control register

    constexpr auto EN = BitField<dma1_t, 0, 1, "EN">{}; // bit offset: 0, bit width: 1, Stream enable / flag stream ready when read low
    constexpr auto DMEIE = BitField<dma1_t, 1, 1, "DMEIE">{}; // bit offset: 1, bit width: 1, Direct mode error interrupt enable
    constexpr auto TEIE = BitField<dma1_t, 2, 1, "TEIE">{}; // bit offset: 2, bit width: 1, Transfer error interrupt enable
    constexpr auto HTIE = BitField<dma1_t, 3, 1, "HTIE">{}; // bit offset: 3, bit width: 1, Half transfer interrupt enable
    constexpr auto TCIE = BitField<dma1_t, 4, 1, "TCIE">{}; // bit offset: 4, bit width: 1, Transfer complete interrupt enable
    constexpr auto PFCTRL = BitField<dma1_t, 5, 1, "PFCTRL">{}; // bit offset: 5, bit width: 1, Peripheral flow controller
    constexpr auto DIR = BitField<dma1_t, 6, 2, "DIR">{}; // bit offset: 6, bit width: 2, Data transfer direction
    constexpr auto CIRC = BitField<dma1_t, 8, 1, "CIRC">{}; // bit offset: 8, bit width: 1, Circular mode
    constexpr auto PINC = BitField<dma1_t, 9, 1, "PINC">{}; // bit offset: 9, bit width: 1, Peripheral increment mode
    constexpr auto MINC = BitField<dma1_t, 10, 1, "MINC">{}; // bit offset: 10, bit width: 1, Memory increment mode
    constexpr auto PSIZE = BitField<dma1_t, 11, 2, "PSIZE">{}; // bit offset: 11, bit width: 2, Peripheral data size
    constexpr auto MSIZE = BitField<dma1_t, 13, 2, "MSIZE">{}; // bit offset: 13, bit width: 2, Memory data size
    constexpr auto PINCOS = BitField<dma1_t, 15, 1, "PINCOS">{}; // bit offset: 15, bit width: 1, Peripheral increment offset size
    constexpr auto PL = BitField<dma1_t, 16, 2, "PL">{}; // bit offset: 16, bit width: 2, Priority level
    constexpr auto DBM = BitField<dma1_t, 18, 1, "DBM">{}; // bit offset: 18, bit width: 1, Double buffer mode
    constexpr auto CT = BitField<dma1_t, 19, 1, "CT">{}; // bit offset: 19, bit width: 1, Current target (only in double buffer mode)
    constexpr auto PBURST = BitField<dma1_t, 21, 2, "PBURST">{}; // bit offset: 21, bit width: 2, Peripheral burst transfer configuration
    constexpr auto MBURST = BitField<dma1_t, 23, 2, "MBURST">{}; // bit offset: 23, bit width: 2, Memory burst transfer configuration
    constexpr auto CHSEL = BitField<dma1_t, 25, 3, "CHSEL">{}; // bit offset: 25, bit width: 3, Channel selection
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000088u, 0, READWRITE, "S5CR", decltype(EN), decltype(DMEIE), decltype(TEIE), decltype(HTIE), decltype(TCIE), decltype(PFCTRL), decltype(DIR), decltype(CIRC), decltype(PINC), decltype(MINC), decltype(PSIZE), decltype(MSIZE), decltype(PINCOS), decltype(PL), decltype(DBM), decltype(CT), decltype(PBURST), decltype(MBURST), decltype(CHSEL)> S5CR; // stream x configuration register

    constexpr auto NDT = BitField<dma1_t, 0, 16, "NDT">{}; // bit offset: 0, bit width: 16, Number of data items to transfer
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x0000008cu, 0, READWRITE, "S5NDTR", decltype(NDT)> S5NDTR; // stream x number of data register

    constexpr auto PA = BitField<dma1_t, 0, 32, "PA">{}; // bit offset: 0, bit width: 32, Peripheral address
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000090u, 0, READWRITE, "S5PAR", decltype(PA)> S5PAR; // stream x peripheral address register

    constexpr auto M0A = BitField<dma1_t, 0, 32, "M0A">{}; // bit offset: 0, bit width: 32, Memory 0 address
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000094u, 0, READWRITE, "S5M0AR", decltype(M0A)> S5M0AR; // stream x memory 0 address register

    constexpr auto M1A = BitField<dma1_t, 0, 32, "M1A">{}; // bit offset: 0, bit width: 32, Memory 1 address (used in case of Double buffer mode)
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x00000098u, 0, READWRITE, "S5M1AR", decltype(M1A)> S5M1AR; // stream x memory 1 address register

    constexpr auto FTH = BitField<dma1_t, 0, 2, "FTH", READWRITE>{}; // bit offset: 0, bit width: 2, FIFO threshold selection
    constexpr auto DMDIS = BitField<dma1_t, 2, 1, "DMDIS", READWRITE>{}; // bit offset: 2, bit width: 1, Direct mode disable
    constexpr auto FS = BitField<dma1_t, 3, 3, "FS", READONLY>{}; // bit offset: 3, bit width: 3, FIFO status
    constexpr auto FEIE = BitField<dma1_t, 7, 1, "FEIE", READWRITE>{}; // bit offset: 7, bit width: 1, FIFO error interrupt enable
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x0000009cu, 33, READWRITE, "S5FCR", decltype(FTH), decltype(DMDIS), decltype(FS), decltype(FEIE)> S5FCR; // stream x FIFO control register

    constexpr auto EN = BitField<dma1_t, 0, 1, "EN">{}; // bit offset: 0, bit width: 1, Stream enable / flag stream ready when read low
    constexpr auto DMEIE = BitField<dma1_t, 1, 1, "DMEIE">{}; // bit offset: 1, bit width: 1, Direct mode error interrupt enable
    constexpr auto TEIE = BitField<dma1_t, 2, 1, "TEIE">{}; // bit offset: 2, bit width: 1, Transfer error interrupt enable
    constexpr auto HTIE = BitField<dma1_t, 3, 1, "HTIE">{}; // bit offset: 3, bit width: 1, Half transfer interrupt enable
    constexpr auto TCIE = BitField<dma1_t, 4, 1, "TCIE">{}; // bit offset: 4, bit width: 1, Transfer complete interrupt enable
    constexpr auto PFCTRL = BitField<dma1_t, 5, 1, "PFCTRL">{}; // bit offset: 5, bit width: 1, Peripheral flow controller
    constexpr auto DIR = BitField<dma1_t, 6, 2, "DIR">{}; // bit offset: 6, bit width: 2, Data transfer direction
    constexpr auto CIRC = BitField<dma1_t, 8, 1, "CIRC">{}; // bit offset: 8, bit width: 1, Circular mode
    constexpr auto PINC = BitField<dma1_t, 9, 1, "PINC">{}; // bit offset: 9, bit width: 1, Peripheral increment mode
    constexpr auto MINC = BitField<dma1_t, 10, 1, "MINC">{}; // bit offset: 10, bit width: 1, Memory increment mode
    constexpr auto PSIZE = BitField<dma1_t, 11, 2, "PSIZE">{}; // bit offset: 11, bit width: 2, Peripheral data size
    constexpr auto MSIZE = BitField<dma1_t, 13, 2, "MSIZE">{}; // bit offset: 13, bit width: 2, Memory data size
    constexpr auto PINCOS = BitField<dma1_t, 15, 1, "PINCOS">{}; // bit offset: 15, bit width: 1, Peripheral increment offset size
    constexpr auto PL = BitField<dma1_t, 16, 2, "PL">{}; // bit offset: 16, bit width: 2, Priority level
    constexpr auto DBM = BitField<dma1_t, 18, 1, "DBM">{}; // bit offset: 18, bit width: 1, Double buffer mode
    constexpr auto CT = BitField<dma1_t, 19, 1, "CT">{}; // bit offset: 19, bit width: 1, Current target (only in double buffer mode)
    constexpr auto PBURST = BitField<dma1_t, 21, 2, "PBURST">{}; // bit offset: 21, bit width: 2, Peripheral burst transfer configuration
    constexpr auto MBURST = BitField<dma1_t, 23, 2, "MBURST">{}; // bit offset: 23, bit width: 2, Memory burst transfer configuration
    constexpr auto CHSEL = BitField<dma1_t, 25, 3, "CHSEL">{}; // bit offset: 25, bit width: 3, Channel selection
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x000000a0u, 0, READWRITE, "S6CR", decltype(EN), decltype(DMEIE), decltype(TEIE), decltype(HTIE), decltype(TCIE), decltype(PFCTRL), decltype(DIR), decltype(CIRC), decltype(PINC), decltype(MINC), decltype(PSIZE), decltype(MSIZE), decltype(PINCOS), decltype(PL), decltype(DBM), decltype(CT), decltype(PBURST), decltype(MBURST), decltype(CHSEL)> S6CR; // stream x configuration register

    constexpr auto NDT = BitField<dma1_t, 0, 16, "NDT">{}; // bit offset: 0, bit width: 16, Number of data items to transfer
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x000000a4u, 0, READWRITE, "S6NDTR", decltype(NDT)> S6NDTR; // stream x number of data register

    constexpr auto PA = BitField<dma1_t, 0, 32, "PA">{}; // bit offset: 0, bit width: 32, Peripheral address
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x000000a8u, 0, READWRITE, "S6PAR", decltype(PA)> S6PAR; // stream x peripheral address register

    constexpr auto M0A = BitField<dma1_t, 0, 32, "M0A">{}; // bit offset: 0, bit width: 32, Memory 0 address
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x000000acu, 0, READWRITE, "S6M0AR", decltype(M0A)> S6M0AR; // stream x memory 0 address register

    constexpr auto M1A = BitField<dma1_t, 0, 32, "M1A">{}; // bit offset: 0, bit width: 32, Memory 1 address (used in case of Double buffer mode)
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x000000b0u, 0, READWRITE, "S6M1AR", decltype(M1A)> S6M1AR; // stream x memory 1 address register

    constexpr auto FTH = BitField<dma1_t, 0, 2, "FTH", READWRITE>{}; // bit offset: 0, bit width: 2, FIFO threshold selection
    constexpr auto DMDIS = BitField<dma1_t, 2, 1, "DMDIS", READWRITE>{}; // bit offset: 2, bit width: 1, Direct mode disable
    constexpr auto FS = BitField<dma1_t, 3, 3, "FS", READONLY>{}; // bit offset: 3, bit width: 3, FIFO status
    constexpr auto FEIE = BitField<dma1_t, 7, 1, "FEIE", READWRITE>{}; // bit offset: 7, bit width: 1, FIFO error interrupt enable
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x000000b4u, 33, READWRITE, "S6FCR", decltype(FTH), decltype(DMDIS), decltype(FS), decltype(FEIE)> S6FCR; // stream x FIFO control register

    constexpr auto EN = BitField<dma1_t, 0, 1, "EN">{}; // bit offset: 0, bit width: 1, Stream enable / flag stream ready when read low
    constexpr auto DMEIE = BitField<dma1_t, 1, 1, "DMEIE">{}; // bit offset: 1, bit width: 1, Direct mode error interrupt enable
    constexpr auto TEIE = BitField<dma1_t, 2, 1, "TEIE">{}; // bit offset: 2, bit width: 1, Transfer error interrupt enable
    constexpr auto HTIE = BitField<dma1_t, 3, 1, "HTIE">{}; // bit offset: 3, bit width: 1, Half transfer interrupt enable
    constexpr auto TCIE = BitField<dma1_t, 4, 1, "TCIE">{}; // bit offset: 4, bit width: 1, Transfer complete interrupt enable
    constexpr auto PFCTRL = BitField<dma1_t, 5, 1, "PFCTRL">{}; // bit offset: 5, bit width: 1, Peripheral flow controller
    constexpr auto DIR = BitField<dma1_t, 6, 2, "DIR">{}; // bit offset: 6, bit width: 2, Data transfer direction
    constexpr auto CIRC = BitField<dma1_t, 8, 1, "CIRC">{}; // bit offset: 8, bit width: 1, Circular mode
    constexpr auto PINC = BitField<dma1_t, 9, 1, "PINC">{}; // bit offset: 9, bit width: 1, Peripheral increment mode
    constexpr auto MINC = BitField<dma1_t, 10, 1, "MINC">{}; // bit offset: 10, bit width: 1, Memory increment mode
    constexpr auto PSIZE = BitField<dma1_t, 11, 2, "PSIZE">{}; // bit offset: 11, bit width: 2, Peripheral data size
    constexpr auto MSIZE = BitField<dma1_t, 13, 2, "MSIZE">{}; // bit offset: 13, bit width: 2, Memory data size
    constexpr auto PINCOS = BitField<dma1_t, 15, 1, "PINCOS">{}; // bit offset: 15, bit width: 1, Peripheral increment offset size
    constexpr auto PL = BitField<dma1_t, 16, 2, "PL">{}; // bit offset: 16, bit width: 2, Priority level
    constexpr auto DBM = BitField<dma1_t, 18, 1, "DBM">{}; // bit offset: 18, bit width: 1, Double buffer mode
    constexpr auto CT = BitField<dma1_t, 19, 1, "CT">{}; // bit offset: 19, bit width: 1, Current target (only in double buffer mode)
    constexpr auto PBURST = BitField<dma1_t, 21, 2, "PBURST">{}; // bit offset: 21, bit width: 2, Peripheral burst transfer configuration
    constexpr auto MBURST = BitField<dma1_t, 23, 2, "MBURST">{}; // bit offset: 23, bit width: 2, Memory burst transfer configuration
    constexpr auto CHSEL = BitField<dma1_t, 25, 3, "CHSEL">{}; // bit offset: 25, bit width: 3, Channel selection
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x000000b8u, 0, READWRITE, "S7CR", decltype(EN), decltype(DMEIE), decltype(TEIE), decltype(HTIE), decltype(TCIE), decltype(PFCTRL), decltype(DIR), decltype(CIRC), decltype(PINC), decltype(MINC), decltype(PSIZE), decltype(MSIZE), decltype(PINCOS), decltype(PL), decltype(DBM), decltype(CT), decltype(PBURST), decltype(MBURST), decltype(CHSEL)> S7CR; // stream x configuration register

    constexpr auto NDT = BitField<dma1_t, 0, 16, "NDT">{}; // bit offset: 0, bit width: 16, Number of data items to transfer
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x000000bcu, 0, READWRITE, "S7NDTR", decltype(NDT)> S7NDTR; // stream x number of data register

    constexpr auto PA = BitField<dma1_t, 0, 32, "PA">{}; // bit offset: 0, bit width: 32, Peripheral address
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x000000c0u, 0, READWRITE, "S7PAR", decltype(PA)> S7PAR; // stream x peripheral address register

    constexpr auto M0A = BitField<dma1_t, 0, 32, "M0A">{}; // bit offset: 0, bit width: 32, Memory 0 address
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x000000c4u, 0, READWRITE, "S7M0AR", decltype(M0A)> S7M0AR; // stream x memory 0 address register

    constexpr auto M1A = BitField<dma1_t, 0, 32, "M1A">{}; // bit offset: 0, bit width: 32, Memory 1 address (used in case of Double buffer mode)
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x000000c8u, 0, READWRITE, "S7M1AR", decltype(M1A)> S7M1AR; // stream x memory 1 address register

    constexpr auto FTH = BitField<dma1_t, 0, 2, "FTH", READWRITE>{}; // bit offset: 0, bit width: 2, FIFO threshold selection
    constexpr auto DMDIS = BitField<dma1_t, 2, 1, "DMDIS", READWRITE>{}; // bit offset: 2, bit width: 1, Direct mode disable
    constexpr auto FS = BitField<dma1_t, 3, 3, "FS", READONLY>{}; // bit offset: 3, bit width: 3, FIFO status
    constexpr auto FEIE = BitField<dma1_t, 7, 1, "FEIE", READWRITE>{}; // bit offset: 7, bit width: 1, FIFO error interrupt enable
    static Register<std::uint32_t, DMA1_BASE_ADDRESS + 0x000000ccu, 33, READWRITE, "S7FCR", decltype(FTH), decltype(DMDIS), decltype(FS), decltype(FEIE)> S7FCR; // stream x FIFO control register

} // namespace DMA1