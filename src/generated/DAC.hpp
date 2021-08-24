#include <Register.hpp>




namespace DAC
{
    struct dac_t{};

    constexpr std::uint32_t DAC_BASE_ADDRESS = 0x40007400u;

    constexpr auto EN1 = BitField<dac_t, 0, 1>{}; // bit offset: 0, bit width: 1, DAC channel1 enable
    constexpr auto BOFF1 = BitField<dac_t, 1, 1>{}; // bit offset: 1, bit width: 1, DAC channel1 output buffer disable
    constexpr auto TEN1 = BitField<dac_t, 2, 1>{}; // bit offset: 2, bit width: 1, DAC channel1 trigger enable
    constexpr auto TSEL1 = BitField<dac_t, 3, 3>{}; // bit offset: 3, bit width: 3, DAC channel1 trigger selection
    constexpr auto WAVE1 = BitField<dac_t, 6, 2>{}; // bit offset: 6, bit width: 2, DAC channel1 noise/triangle wave generation enable
    constexpr auto MAMP1 = BitField<dac_t, 8, 4>{}; // bit offset: 8, bit width: 4, DAC channel1 mask/amplitude selector
    constexpr auto DMAEN1 = BitField<dac_t, 12, 1>{}; // bit offset: 12, bit width: 1, DAC channel1 DMA enable
    constexpr auto DMAUDRIE1 = BitField<dac_t, 13, 1>{}; // bit offset: 13, bit width: 1, DAC channel1 DMA Underrun Interrupt enable
    constexpr auto EN2 = BitField<dac_t, 16, 1>{}; // bit offset: 16, bit width: 1, DAC channel2 enable
    constexpr auto BOFF2 = BitField<dac_t, 17, 1>{}; // bit offset: 17, bit width: 1, DAC channel2 output buffer disable
    constexpr auto TEN2 = BitField<dac_t, 18, 1>{}; // bit offset: 18, bit width: 1, DAC channel2 trigger enable
    constexpr auto TSEL2 = BitField<dac_t, 19, 3>{}; // bit offset: 19, bit width: 3, DAC channel2 trigger selection
    constexpr auto WAVE2 = BitField<dac_t, 22, 2>{}; // bit offset: 22, bit width: 2, DAC channel2 noise/triangle wave generation enable
    constexpr auto MAMP2 = BitField<dac_t, 24, 4>{}; // bit offset: 24, bit width: 4, DAC channel2 mask/amplitude selector
    constexpr auto DMAEN2 = BitField<dac_t, 28, 1>{}; // bit offset: 28, bit width: 1, DAC channel2 DMA enable
    constexpr auto DMAUDRIE2 = BitField<dac_t, 29, 1>{}; // bit offset: 29, bit width: 1, DAC channel2 DMA underrun interrupt enable
    static Register<std::uint32_t, DAC_BASE_ADDRESS + 0x00000000u, 0, READWRITE, decltype(EN1), decltype(BOFF1), decltype(TEN1), decltype(TSEL1), decltype(WAVE1), decltype(MAMP1), decltype(DMAEN1), decltype(DMAUDRIE1), decltype(EN2), decltype(BOFF2), decltype(TEN2), decltype(TSEL2), decltype(WAVE2), decltype(MAMP2), decltype(DMAEN2), decltype(DMAUDRIE2)> CR; // control register

    constexpr auto SWTRIG1 = BitField<dac_t, 0, 1>{}; // bit offset: 0, bit width: 1, DAC channel1 software trigger
    constexpr auto SWTRIG2 = BitField<dac_t, 1, 1>{}; // bit offset: 1, bit width: 1, DAC channel2 software trigger
    static Register<std::uint32_t, DAC_BASE_ADDRESS + 0x00000004u, 0, WRITEONLY, decltype(SWTRIG1), decltype(SWTRIG2)> SWTRIGR; // software trigger register

    constexpr auto DACC1DHR = BitField<dac_t, 0, 12>{}; // bit offset: 0, bit width: 12, DAC channel1 12-bit right-aligned data
    static Register<std::uint32_t, DAC_BASE_ADDRESS + 0x00000008u, 0, READWRITE, decltype(DACC1DHR)> DHR12R1; // channel1 12-bit right-aligned data holding register

    constexpr auto DACC1DHR = BitField<dac_t, 4, 12>{}; // bit offset: 4, bit width: 12, DAC channel1 12-bit left-aligned data
    static Register<std::uint32_t, DAC_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, decltype(DACC1DHR)> DHR12L1; // channel1 12-bit left aligned data holding register

    constexpr auto DACC1DHR = BitField<dac_t, 0, 8>{}; // bit offset: 0, bit width: 8, DAC channel1 8-bit right-aligned data
    static Register<std::uint32_t, DAC_BASE_ADDRESS + 0x00000010u, 0, READWRITE, decltype(DACC1DHR)> DHR8R1; // channel1 8-bit right aligned data holding register

    constexpr auto DACC2DHR = BitField<dac_t, 0, 12>{}; // bit offset: 0, bit width: 12, DAC channel2 12-bit right-aligned data
    static Register<std::uint32_t, DAC_BASE_ADDRESS + 0x00000014u, 0, READWRITE, decltype(DACC2DHR)> DHR12R2; // channel2 12-bit right aligned data holding register

    constexpr auto DACC2DHR = BitField<dac_t, 4, 12>{}; // bit offset: 4, bit width: 12, DAC channel2 12-bit left-aligned data
    static Register<std::uint32_t, DAC_BASE_ADDRESS + 0x00000018u, 0, READWRITE, decltype(DACC2DHR)> DHR12L2; // channel2 12-bit left aligned data holding register

    constexpr auto DACC2DHR = BitField<dac_t, 0, 8>{}; // bit offset: 0, bit width: 8, DAC channel2 8-bit right-aligned data
    static Register<std::uint32_t, DAC_BASE_ADDRESS + 0x0000001cu, 0, READWRITE, decltype(DACC2DHR)> DHR8R2; // channel2 8-bit right-aligned data holding register

    constexpr auto DACC1DHR = BitField<dac_t, 0, 12>{}; // bit offset: 0, bit width: 12, DAC channel1 12-bit right-aligned data
    constexpr auto DACC2DHR = BitField<dac_t, 16, 12>{}; // bit offset: 16, bit width: 12, DAC channel2 12-bit right-aligned data
    static Register<std::uint32_t, DAC_BASE_ADDRESS + 0x00000020u, 0, READWRITE, decltype(DACC1DHR), decltype(DACC2DHR)> DHR12RD; // Dual DAC 12-bit right-aligned data holding register

    constexpr auto DACC1DHR = BitField<dac_t, 4, 12>{}; // bit offset: 4, bit width: 12, DAC channel1 12-bit left-aligned data
    constexpr auto DACC2DHR = BitField<dac_t, 20, 12>{}; // bit offset: 20, bit width: 12, DAC channel2 12-bit left-aligned data
    static Register<std::uint32_t, DAC_BASE_ADDRESS + 0x00000024u, 0, READWRITE, decltype(DACC1DHR), decltype(DACC2DHR)> DHR12LD; // DUAL DAC 12-bit left aligned data holding register

    constexpr auto DACC1DHR = BitField<dac_t, 0, 8>{}; // bit offset: 0, bit width: 8, DAC channel1 8-bit right-aligned data
    constexpr auto DACC2DHR = BitField<dac_t, 8, 8>{}; // bit offset: 8, bit width: 8, DAC channel2 8-bit right-aligned data
    static Register<std::uint32_t, DAC_BASE_ADDRESS + 0x00000028u, 0, READWRITE, decltype(DACC1DHR), decltype(DACC2DHR)> DHR8RD; // DUAL DAC 8-bit right aligned data holding register

    constexpr auto DACC1DOR = BitField<dac_t, 0, 12>{}; // bit offset: 0, bit width: 12, DAC channel1 data output
    static Register<std::uint32_t, DAC_BASE_ADDRESS + 0x0000002cu, 0, READONLY, decltype(DACC1DOR)> DOR1; // channel1 data output register

    constexpr auto DACC2DOR = BitField<dac_t, 0, 12>{}; // bit offset: 0, bit width: 12, DAC channel2 data output
    static Register<std::uint32_t, DAC_BASE_ADDRESS + 0x00000030u, 0, READONLY, decltype(DACC2DOR)> DOR2; // channel2 data output register

    constexpr auto DMAUDR1 = BitField<dac_t, 13, 1>{}; // bit offset: 13, bit width: 1, DAC channel1 DMA underrun flag
    constexpr auto DMAUDR2 = BitField<dac_t, 29, 1>{}; // bit offset: 29, bit width: 1, DAC channel2 DMA underrun flag
    static Register<std::uint32_t, DAC_BASE_ADDRESS + 0x00000034u, 0, READWRITE, decltype(DMAUDR1), decltype(DMAUDR2)> SR; // status register

} // namespace DAC