#include <Register.hpp>




namespace TIM2
{
    struct tim2_t{};

    constexpr std::uint32_t TIM2_BASE_ADDRESS = 0x40000000u;

    constexpr auto CEN = BitField<tim2_t, 0, 1>{}; // bit offset: 0, bit width: 1, Counter enable
    constexpr auto UDIS = BitField<tim2_t, 1, 1>{}; // bit offset: 1, bit width: 1, Update disable
    constexpr auto URS = BitField<tim2_t, 2, 1>{}; // bit offset: 2, bit width: 1, Update request source
    constexpr auto OPM = BitField<tim2_t, 3, 1>{}; // bit offset: 3, bit width: 1, One-pulse mode
    constexpr auto DIR = BitField<tim2_t, 4, 1>{}; // bit offset: 4, bit width: 1, Direction
    constexpr auto CMS = BitField<tim2_t, 5, 2>{}; // bit offset: 5, bit width: 2, Center-aligned mode selection
    constexpr auto ARPE = BitField<tim2_t, 7, 1>{}; // bit offset: 7, bit width: 1, Auto-reload preload enable
    constexpr auto CKD = BitField<tim2_t, 8, 2>{}; // bit offset: 8, bit width: 2, Clock division
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x00000000u, 0, READWRITE, decltype(CEN), decltype(UDIS), decltype(URS), decltype(OPM), decltype(DIR), decltype(CMS), decltype(ARPE), decltype(CKD)> CR1; // control register 1

    constexpr auto CCDS = BitField<tim2_t, 3, 1>{}; // bit offset: 3, bit width: 1, Capture/compare DMA selection
    constexpr auto MMS = BitField<tim2_t, 4, 3>{}; // bit offset: 4, bit width: 3, Master mode selection
    constexpr auto TI1S = BitField<tim2_t, 7, 1>{}; // bit offset: 7, bit width: 1, TI1 selection
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x00000004u, 0, READWRITE, decltype(CCDS), decltype(MMS), decltype(TI1S)> CR2; // control register 2

    constexpr auto SMS = BitField<tim2_t, 0, 3>{}; // bit offset: 0, bit width: 3, Slave mode selection
    constexpr auto TS = BitField<tim2_t, 4, 3>{}; // bit offset: 4, bit width: 3, Trigger selection
    constexpr auto MSM = BitField<tim2_t, 7, 1>{}; // bit offset: 7, bit width: 1, Master/Slave mode
    constexpr auto ETF = BitField<tim2_t, 8, 4>{}; // bit offset: 8, bit width: 4, External trigger filter
    constexpr auto ETPS = BitField<tim2_t, 12, 2>{}; // bit offset: 12, bit width: 2, External trigger prescaler
    constexpr auto ECE = BitField<tim2_t, 14, 1>{}; // bit offset: 14, bit width: 1, External clock enable
    constexpr auto ETP = BitField<tim2_t, 15, 1>{}; // bit offset: 15, bit width: 1, External trigger polarity
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x00000008u, 0, READWRITE, decltype(SMS), decltype(TS), decltype(MSM), decltype(ETF), decltype(ETPS), decltype(ECE), decltype(ETP)> SMCR; // slave mode control register

    constexpr auto UIE = BitField<tim2_t, 0, 1>{}; // bit offset: 0, bit width: 1, Update interrupt enable
    constexpr auto CC1IE = BitField<tim2_t, 1, 1>{}; // bit offset: 1, bit width: 1, Capture/Compare 1 interrupt enable
    constexpr auto CC2IE = BitField<tim2_t, 2, 1>{}; // bit offset: 2, bit width: 1, Capture/Compare 2 interrupt enable
    constexpr auto CC3IE = BitField<tim2_t, 3, 1>{}; // bit offset: 3, bit width: 1, Capture/Compare 3 interrupt enable
    constexpr auto CC4IE = BitField<tim2_t, 4, 1>{}; // bit offset: 4, bit width: 1, Capture/Compare 4 interrupt enable
    constexpr auto TIE = BitField<tim2_t, 6, 1>{}; // bit offset: 6, bit width: 1, Trigger interrupt enable
    constexpr auto UDE = BitField<tim2_t, 8, 1>{}; // bit offset: 8, bit width: 1, Update DMA request enable
    constexpr auto CC1DE = BitField<tim2_t, 9, 1>{}; // bit offset: 9, bit width: 1, Capture/Compare 1 DMA request enable
    constexpr auto CC2DE = BitField<tim2_t, 10, 1>{}; // bit offset: 10, bit width: 1, Capture/Compare 2 DMA request enable
    constexpr auto CC3DE = BitField<tim2_t, 11, 1>{}; // bit offset: 11, bit width: 1, Capture/Compare 3 DMA request enable
    constexpr auto CC4DE = BitField<tim2_t, 12, 1>{}; // bit offset: 12, bit width: 1, Capture/Compare 4 DMA request enable
    constexpr auto TDE = BitField<tim2_t, 14, 1>{}; // bit offset: 14, bit width: 1, Trigger DMA request enable
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, decltype(UIE), decltype(CC1IE), decltype(CC2IE), decltype(CC3IE), decltype(CC4IE), decltype(TIE), decltype(UDE), decltype(CC1DE), decltype(CC2DE), decltype(CC3DE), decltype(CC4DE), decltype(TDE)> DIER; // DMA/Interrupt enable register

    constexpr auto UIF = BitField<tim2_t, 0, 1>{}; // bit offset: 0, bit width: 1, Update interrupt flag
    constexpr auto CC1IF = BitField<tim2_t, 1, 1>{}; // bit offset: 1, bit width: 1, Capture/compare 1 interrupt flag
    constexpr auto CC2IF = BitField<tim2_t, 2, 1>{}; // bit offset: 2, bit width: 1, Capture/Compare 2 interrupt flag
    constexpr auto CC3IF = BitField<tim2_t, 3, 1>{}; // bit offset: 3, bit width: 1, Capture/Compare 3 interrupt flag
    constexpr auto CC4IF = BitField<tim2_t, 4, 1>{}; // bit offset: 4, bit width: 1, Capture/Compare 4 interrupt flag
    constexpr auto TIF = BitField<tim2_t, 6, 1>{}; // bit offset: 6, bit width: 1, Trigger interrupt flag
    constexpr auto CC1OF = BitField<tim2_t, 9, 1>{}; // bit offset: 9, bit width: 1, Capture/Compare 1 overcapture flag
    constexpr auto CC2OF = BitField<tim2_t, 10, 1>{}; // bit offset: 10, bit width: 1, Capture/compare 2 overcapture flag
    constexpr auto CC3OF = BitField<tim2_t, 11, 1>{}; // bit offset: 11, bit width: 1, Capture/Compare 3 overcapture flag
    constexpr auto CC4OF = BitField<tim2_t, 12, 1>{}; // bit offset: 12, bit width: 1, Capture/Compare 4 overcapture flag
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x00000010u, 0, READWRITE, decltype(UIF), decltype(CC1IF), decltype(CC2IF), decltype(CC3IF), decltype(CC4IF), decltype(TIF), decltype(CC1OF), decltype(CC2OF), decltype(CC3OF), decltype(CC4OF)> SR; // status register

    constexpr auto UG = BitField<tim2_t, 0, 1>{}; // bit offset: 0, bit width: 1, Update generation
    constexpr auto CC1G = BitField<tim2_t, 1, 1>{}; // bit offset: 1, bit width: 1, Capture/compare 1 generation
    constexpr auto CC2G = BitField<tim2_t, 2, 1>{}; // bit offset: 2, bit width: 1, Capture/compare 2 generation
    constexpr auto CC3G = BitField<tim2_t, 3, 1>{}; // bit offset: 3, bit width: 1, Capture/compare 3 generation
    constexpr auto CC4G = BitField<tim2_t, 4, 1>{}; // bit offset: 4, bit width: 1, Capture/compare 4 generation
    constexpr auto TG = BitField<tim2_t, 6, 1>{}; // bit offset: 6, bit width: 1, Trigger generation
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x00000014u, 0, WRITEONLY, decltype(UG), decltype(CC1G), decltype(CC2G), decltype(CC3G), decltype(CC4G), decltype(TG)> EGR; // event generation register

    constexpr auto CC1S = BitField<tim2_t, 0, 2>{}; // bit offset: 0, bit width: 2, Capture/Compare 1 selection
    constexpr auto OC1FE = BitField<tim2_t, 2, 1>{}; // bit offset: 2, bit width: 1, Output compare 1 fast enable
    constexpr auto OC1PE = BitField<tim2_t, 3, 1>{}; // bit offset: 3, bit width: 1, Output compare 1 preload enable
    constexpr auto OC1M = BitField<tim2_t, 4, 3>{}; // bit offset: 4, bit width: 3, Output compare 1 mode
    constexpr auto OC1CE = BitField<tim2_t, 7, 1>{}; // bit offset: 7, bit width: 1, Output compare 1 clear enable
    constexpr auto CC2S = BitField<tim2_t, 8, 2>{}; // bit offset: 8, bit width: 2, Capture/Compare 2 selection
    constexpr auto OC2FE = BitField<tim2_t, 10, 1>{}; // bit offset: 10, bit width: 1, Output compare 2 fast enable
    constexpr auto OC2PE = BitField<tim2_t, 11, 1>{}; // bit offset: 11, bit width: 1, Output compare 2 preload enable
    constexpr auto OC2M = BitField<tim2_t, 12, 3>{}; // bit offset: 12, bit width: 3, Output compare 2 mode
    constexpr auto OC2CE = BitField<tim2_t, 15, 1>{}; // bit offset: 15, bit width: 1, Output compare 2 clear enable
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x00000018u, 0, READWRITE, decltype(CC1S), decltype(OC1FE), decltype(OC1PE), decltype(OC1M), decltype(OC1CE), decltype(CC2S), decltype(OC2FE), decltype(OC2PE), decltype(OC2M), decltype(OC2CE)> CCMR1_OUTPUT; // capture/compare mode register 1 (output mode)

    constexpr auto CC1S = BitField<tim2_t, 0, 2>{}; // bit offset: 0, bit width: 2, Capture/Compare 1 selection
    constexpr auto IC1PSC = BitField<tim2_t, 2, 2>{}; // bit offset: 2, bit width: 2, Input capture 1 prescaler
    constexpr auto IC1F = BitField<tim2_t, 4, 4>{}; // bit offset: 4, bit width: 4, Input capture 1 filter
    constexpr auto CC2S = BitField<tim2_t, 8, 2>{}; // bit offset: 8, bit width: 2, Capture/compare 2 selection
    constexpr auto IC2PSC = BitField<tim2_t, 10, 2>{}; // bit offset: 10, bit width: 2, Input capture 2 prescaler
    constexpr auto IC2F = BitField<tim2_t, 12, 4>{}; // bit offset: 12, bit width: 4, Input capture 2 filter
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x00000018u, 0, READWRITE, decltype(CC1S), decltype(IC1PSC), decltype(IC1F), decltype(CC2S), decltype(IC2PSC), decltype(IC2F)> CCMR1_INPUT; // capture/compare mode register 1 (input mode)

    constexpr auto CC3S = BitField<tim2_t, 0, 2>{}; // bit offset: 0, bit width: 2, Capture/Compare 3 selection
    constexpr auto OC3FE = BitField<tim2_t, 2, 1>{}; // bit offset: 2, bit width: 1, Output compare 3 fast enable
    constexpr auto OC3PE = BitField<tim2_t, 3, 1>{}; // bit offset: 3, bit width: 1, Output compare 3 preload enable
    constexpr auto OC3M = BitField<tim2_t, 4, 3>{}; // bit offset: 4, bit width: 3, Output compare 3 mode
    constexpr auto OC3CE = BitField<tim2_t, 7, 1>{}; // bit offset: 7, bit width: 1, Output compare 3 clear enable
    constexpr auto CC4S = BitField<tim2_t, 8, 2>{}; // bit offset: 8, bit width: 2, Capture/Compare 4 selection
    constexpr auto OC4FE = BitField<tim2_t, 10, 1>{}; // bit offset: 10, bit width: 1, Output compare 4 fast enable
    constexpr auto OC4PE = BitField<tim2_t, 11, 1>{}; // bit offset: 11, bit width: 1, Output compare 4 preload enable
    constexpr auto OC4M = BitField<tim2_t, 12, 3>{}; // bit offset: 12, bit width: 3, Output compare 4 mode
    constexpr auto OC4CE = BitField<tim2_t, 15, 1>{}; // bit offset: 15, bit width: 1, Output compare 4 clear enable
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x0000001cu, 0, READWRITE, decltype(CC3S), decltype(OC3FE), decltype(OC3PE), decltype(OC3M), decltype(OC3CE), decltype(CC4S), decltype(OC4FE), decltype(OC4PE), decltype(OC4M), decltype(OC4CE)> CCMR2_OUTPUT; // capture/compare mode register 2 (output mode)

    constexpr auto CC3S = BitField<tim2_t, 0, 2>{}; // bit offset: 0, bit width: 2, Capture/Compare 3 selection
    constexpr auto IC3PSC = BitField<tim2_t, 2, 2>{}; // bit offset: 2, bit width: 2, Input capture 3 prescaler
    constexpr auto IC3F = BitField<tim2_t, 4, 4>{}; // bit offset: 4, bit width: 4, Input capture 3 filter
    constexpr auto CC4S = BitField<tim2_t, 8, 2>{}; // bit offset: 8, bit width: 2, Capture/Compare 4 selection
    constexpr auto IC4PSC = BitField<tim2_t, 10, 2>{}; // bit offset: 10, bit width: 2, Input capture 4 prescaler
    constexpr auto IC4F = BitField<tim2_t, 12, 4>{}; // bit offset: 12, bit width: 4, Input capture 4 filter
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x0000001cu, 0, READWRITE, decltype(CC3S), decltype(IC3PSC), decltype(IC3F), decltype(CC4S), decltype(IC4PSC), decltype(IC4F)> CCMR2_INPUT; // capture/compare mode register 2 (input mode)

    constexpr auto CC1E = BitField<tim2_t, 0, 1>{}; // bit offset: 0, bit width: 1, Capture/Compare 1 output enable
    constexpr auto CC1P = BitField<tim2_t, 1, 1>{}; // bit offset: 1, bit width: 1, Capture/Compare 1 output Polarity
    constexpr auto CC1NP = BitField<tim2_t, 3, 1>{}; // bit offset: 3, bit width: 1, Capture/Compare 1 output Polarity
    constexpr auto CC2E = BitField<tim2_t, 4, 1>{}; // bit offset: 4, bit width: 1, Capture/Compare 2 output enable
    constexpr auto CC2P = BitField<tim2_t, 5, 1>{}; // bit offset: 5, bit width: 1, Capture/Compare 2 output Polarity
    constexpr auto CC2NP = BitField<tim2_t, 7, 1>{}; // bit offset: 7, bit width: 1, Capture/Compare 2 output Polarity
    constexpr auto CC3E = BitField<tim2_t, 8, 1>{}; // bit offset: 8, bit width: 1, Capture/Compare 3 output enable
    constexpr auto CC3P = BitField<tim2_t, 9, 1>{}; // bit offset: 9, bit width: 1, Capture/Compare 3 output Polarity
    constexpr auto CC3NP = BitField<tim2_t, 11, 1>{}; // bit offset: 11, bit width: 1, Capture/Compare 3 output Polarity
    constexpr auto CC4E = BitField<tim2_t, 12, 1>{}; // bit offset: 12, bit width: 1, Capture/Compare 4 output enable
    constexpr auto CC4P = BitField<tim2_t, 13, 1>{}; // bit offset: 13, bit width: 1, Capture/Compare 3 output Polarity
    constexpr auto CC4NP = BitField<tim2_t, 15, 1>{}; // bit offset: 15, bit width: 1, Capture/Compare 4 output Polarity
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x00000020u, 0, READWRITE, decltype(CC1E), decltype(CC1P), decltype(CC1NP), decltype(CC2E), decltype(CC2P), decltype(CC2NP), decltype(CC3E), decltype(CC3P), decltype(CC3NP), decltype(CC4E), decltype(CC4P), decltype(CC4NP)> CCER; // capture/compare enable register

    constexpr auto CNT_L = BitField<tim2_t, 0, 16>{}; // bit offset: 0, bit width: 16, Low counter value
    constexpr auto CNT_H = BitField<tim2_t, 16, 16>{}; // bit offset: 16, bit width: 16, High counter value
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x00000024u, 0, READWRITE, decltype(CNT_L), decltype(CNT_H)> CNT; // counter

    constexpr auto PSC_ = BitField<tim2_t, 0, 16>{}; // bit offset: 0, bit width: 16, Prescaler value
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x00000028u, 0, READWRITE, decltype(PSC_)> PSC; // prescaler

    constexpr auto ARR_L = BitField<tim2_t, 0, 16>{}; // bit offset: 0, bit width: 16, Low Auto-reload value
    constexpr auto ARR_H = BitField<tim2_t, 16, 16>{}; // bit offset: 16, bit width: 16, High Auto-reload value
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x0000002cu, 0, READWRITE, decltype(ARR_L), decltype(ARR_H)> ARR; // auto-reload register

    constexpr auto CCR1_L = BitField<tim2_t, 0, 16>{}; // bit offset: 0, bit width: 16, Low Capture/Compare 1 value
    constexpr auto CCR1_H = BitField<tim2_t, 16, 16>{}; // bit offset: 16, bit width: 16, High Capture/Compare 1 value
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x00000034u, 0, READWRITE, decltype(CCR1_L), decltype(CCR1_H)> CCR1; // capture/compare register 1

    constexpr auto CCR2_L = BitField<tim2_t, 0, 16>{}; // bit offset: 0, bit width: 16, Low Capture/Compare 2 value
    constexpr auto CCR2_H = BitField<tim2_t, 16, 16>{}; // bit offset: 16, bit width: 16, High Capture/Compare 2 value
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x00000038u, 0, READWRITE, decltype(CCR2_L), decltype(CCR2_H)> CCR2; // capture/compare register 2

    constexpr auto CCR3_L = BitField<tim2_t, 0, 16>{}; // bit offset: 0, bit width: 16, Low Capture/Compare value
    constexpr auto CCR3_H = BitField<tim2_t, 16, 16>{}; // bit offset: 16, bit width: 16, High Capture/Compare value
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x0000003cu, 0, READWRITE, decltype(CCR3_L), decltype(CCR3_H)> CCR3; // capture/compare register 3

    constexpr auto CCR4_L = BitField<tim2_t, 0, 16>{}; // bit offset: 0, bit width: 16, Low Capture/Compare value
    constexpr auto CCR4_H = BitField<tim2_t, 16, 16>{}; // bit offset: 16, bit width: 16, High Capture/Compare value
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x00000040u, 0, READWRITE, decltype(CCR4_L), decltype(CCR4_H)> CCR4; // capture/compare register 4

    constexpr auto DBA = BitField<tim2_t, 0, 5>{}; // bit offset: 0, bit width: 5, DMA base address
    constexpr auto DBL = BitField<tim2_t, 8, 5>{}; // bit offset: 8, bit width: 5, DMA burst length
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x00000048u, 0, READWRITE, decltype(DBA), decltype(DBL)> DCR; // DMA control register

    constexpr auto DMAB = BitField<tim2_t, 0, 16>{}; // bit offset: 0, bit width: 16, DMA register for burst accesses
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x0000004cu, 0, READWRITE, decltype(DMAB)> DMAR; // DMA address for full transfer

    constexpr auto IT4_RMP = BitField<tim2_t, 6, 2>{}; // bit offset: 6, bit width: 2, Timer Input 4 remap
    static Register<std::uint32_t, TIM2_BASE_ADDRESS + 0x00000050u, 0, READWRITE, decltype(IT4_RMP)> TIM2_OR; // TIM2 option register

} // namespace TIM2