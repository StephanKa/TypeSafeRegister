#include <Register.hpp>

namespace TIM9
{
    struct tim9_t{};

    constexpr std::uint32_t TIM9_BASE_ADDRESS = 0x40014000u;

    constexpr auto CEN = BitField<tim9_t, 0, 1, "CEN">{}; // bit offset: 0, bit width: 1, Counter enable
    constexpr auto UDIS = BitField<tim9_t, 1, 1, "UDIS">{}; // bit offset: 1, bit width: 1, Update disable
    constexpr auto URS = BitField<tim9_t, 2, 1, "URS">{}; // bit offset: 2, bit width: 1, Update request source
    constexpr auto OPM = BitField<tim9_t, 3, 1, "OPM">{}; // bit offset: 3, bit width: 1, One-pulse mode
    constexpr auto ARPE = BitField<tim9_t, 7, 1, "ARPE">{}; // bit offset: 7, bit width: 1, Auto-reload preload enable
    constexpr auto CKD = BitField<tim9_t, 8, 2, "CKD">{}; // bit offset: 8, bit width: 2, Clock division
    static Register<std::uint32_t, TIM9_BASE_ADDRESS + 0x00000000u, 0, READWRITE, "CR1", decltype(CEN), decltype(UDIS), decltype(URS), decltype(OPM), decltype(ARPE), decltype(CKD)> CR1; // control register 1

    constexpr auto MMS = BitField<tim9_t, 4, 3, "MMS">{}; // bit offset: 4, bit width: 3, Master mode selection
    static Register<std::uint32_t, TIM9_BASE_ADDRESS + 0x00000004u, 0, READWRITE, "CR2", decltype(MMS)> CR2; // control register 2

    constexpr auto SMS = BitField<tim9_t, 0, 3, "SMS">{}; // bit offset: 0, bit width: 3, Slave mode selection
    constexpr auto TS = BitField<tim9_t, 4, 3, "TS">{}; // bit offset: 4, bit width: 3, Trigger selection
    constexpr auto MSM = BitField<tim9_t, 7, 1, "MSM">{}; // bit offset: 7, bit width: 1, Master/Slave mode
    static Register<std::uint32_t, TIM9_BASE_ADDRESS + 0x00000008u, 0, READWRITE, "SMCR", decltype(SMS), decltype(TS), decltype(MSM)> SMCR; // slave mode control register

    constexpr auto UIE = BitField<tim9_t, 0, 1, "UIE">{}; // bit offset: 0, bit width: 1, Update interrupt enable
    constexpr auto CC1IE = BitField<tim9_t, 1, 1, "CC1IE">{}; // bit offset: 1, bit width: 1, Capture/Compare 1 interrupt enable
    constexpr auto CC2IE = BitField<tim9_t, 2, 1, "CC2IE">{}; // bit offset: 2, bit width: 1, Capture/Compare 2 interrupt enable
    constexpr auto TIE = BitField<tim9_t, 6, 1, "TIE">{}; // bit offset: 6, bit width: 1, Trigger interrupt enable
    static Register<std::uint32_t, TIM9_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, "DIER", decltype(UIE), decltype(CC1IE), decltype(CC2IE), decltype(TIE)> DIER; // DMA/Interrupt enable register

    constexpr auto UIF = BitField<tim9_t, 0, 1, "UIF">{}; // bit offset: 0, bit width: 1, Update interrupt flag
    constexpr auto CC1IF = BitField<tim9_t, 1, 1, "CC1IF">{}; // bit offset: 1, bit width: 1, Capture/compare 1 interrupt flag
    constexpr auto CC2IF = BitField<tim9_t, 2, 1, "CC2IF">{}; // bit offset: 2, bit width: 1, Capture/Compare 2 interrupt flag
    constexpr auto TIF = BitField<tim9_t, 6, 1, "TIF">{}; // bit offset: 6, bit width: 1, Trigger interrupt flag
    constexpr auto CC1OF = BitField<tim9_t, 9, 1, "CC1OF">{}; // bit offset: 9, bit width: 1, Capture/Compare 1 overcapture flag
    constexpr auto CC2OF = BitField<tim9_t, 10, 1, "CC2OF">{}; // bit offset: 10, bit width: 1, Capture/compare 2 overcapture flag
    static Register<std::uint32_t, TIM9_BASE_ADDRESS + 0x00000010u, 0, READWRITE, "SR", decltype(UIF), decltype(CC1IF), decltype(CC2IF), decltype(TIF), decltype(CC1OF), decltype(CC2OF)> SR; // status register

    constexpr auto UG = BitField<tim9_t, 0, 1, "UG">{}; // bit offset: 0, bit width: 1, Update generation
    constexpr auto CC1G = BitField<tim9_t, 1, 1, "CC1G">{}; // bit offset: 1, bit width: 1, Capture/compare 1 generation
    constexpr auto CC2G = BitField<tim9_t, 2, 1, "CC2G">{}; // bit offset: 2, bit width: 1, Capture/compare 2 generation
    constexpr auto TG = BitField<tim9_t, 6, 1, "TG">{}; // bit offset: 6, bit width: 1, Trigger generation
    static Register<std::uint32_t, TIM9_BASE_ADDRESS + 0x00000014u, 0, WRITEONLY, "EGR", decltype(UG), decltype(CC1G), decltype(CC2G), decltype(TG)> EGR; // event generation register

    constexpr auto CC1S = BitField<tim9_t, 0, 2, "CC1S">{}; // bit offset: 0, bit width: 2, Capture/Compare 1 selection
    constexpr auto OC1FE = BitField<tim9_t, 2, 1, "OC1FE">{}; // bit offset: 2, bit width: 1, Output Compare 1 fast enable
    constexpr auto OC1PE = BitField<tim9_t, 3, 1, "OC1PE">{}; // bit offset: 3, bit width: 1, Output Compare 1 preload enable
    constexpr auto OC1M = BitField<tim9_t, 4, 3, "OC1M">{}; // bit offset: 4, bit width: 3, Output Compare 1 mode
    constexpr auto CC2S = BitField<tim9_t, 8, 2, "CC2S">{}; // bit offset: 8, bit width: 2, Capture/Compare 2 selection
    constexpr auto OC2FE = BitField<tim9_t, 10, 1, "OC2FE">{}; // bit offset: 10, bit width: 1, Output Compare 2 fast enable
    constexpr auto OC2PE = BitField<tim9_t, 11, 1, "OC2PE">{}; // bit offset: 11, bit width: 1, Output Compare 2 preload enable
    constexpr auto OC2M = BitField<tim9_t, 12, 3, "OC2M">{}; // bit offset: 12, bit width: 3, Output Compare 2 mode
    static Register<std::uint32_t, TIM9_BASE_ADDRESS + 0x00000018u, 0, READWRITE, "CCMR1_OUTPUT", decltype(CC1S), decltype(OC1FE), decltype(OC1PE), decltype(OC1M), decltype(CC2S), decltype(OC2FE), decltype(OC2PE), decltype(OC2M)> CCMR1_OUTPUT; // capture/compare mode register 1 (output mode)

    constexpr auto CC1S = BitField<tim9_t, 0, 2, "CC1S">{}; // bit offset: 0, bit width: 2, Capture/Compare 1 selection
    constexpr auto IC1PSC = BitField<tim9_t, 2, 2, "IC1PSC">{}; // bit offset: 2, bit width: 2, Input capture 1 prescaler
    constexpr auto IC1F = BitField<tim9_t, 4, 3, "IC1F">{}; // bit offset: 4, bit width: 3, Input capture 1 filter
    constexpr auto CC2S = BitField<tim9_t, 8, 2, "CC2S">{}; // bit offset: 8, bit width: 2, Capture/Compare 2 selection
    constexpr auto IC2PSC = BitField<tim9_t, 10, 2, "IC2PSC">{}; // bit offset: 10, bit width: 2, Input capture 2 prescaler
    constexpr auto IC2F = BitField<tim9_t, 12, 3, "IC2F">{}; // bit offset: 12, bit width: 3, Input capture 2 filter
    static Register<std::uint32_t, TIM9_BASE_ADDRESS + 0x00000018u, 0, READWRITE, "CCMR1_INPUT", decltype(CC1S), decltype(IC1PSC), decltype(IC1F), decltype(CC2S), decltype(IC2PSC), decltype(IC2F)> CCMR1_INPUT; // capture/compare mode register 1 (input mode)

    constexpr auto CC1E = BitField<tim9_t, 0, 1, "CC1E">{}; // bit offset: 0, bit width: 1, Capture/Compare 1 output enable
    constexpr auto CC1P = BitField<tim9_t, 1, 1, "CC1P">{}; // bit offset: 1, bit width: 1, Capture/Compare 1 output Polarity
    constexpr auto CC1NP = BitField<tim9_t, 3, 1, "CC1NP">{}; // bit offset: 3, bit width: 1, Capture/Compare 1 output Polarity
    constexpr auto CC2E = BitField<tim9_t, 4, 1, "CC2E">{}; // bit offset: 4, bit width: 1, Capture/Compare 2 output enable
    constexpr auto CC2P = BitField<tim9_t, 5, 1, "CC2P">{}; // bit offset: 5, bit width: 1, Capture/Compare 2 output Polarity
    constexpr auto CC2NP = BitField<tim9_t, 7, 1, "CC2NP">{}; // bit offset: 7, bit width: 1, Capture/Compare 2 output Polarity
    static Register<std::uint32_t, TIM9_BASE_ADDRESS + 0x00000020u, 0, READWRITE, "CCER", decltype(CC1E), decltype(CC1P), decltype(CC1NP), decltype(CC2E), decltype(CC2P), decltype(CC2NP)> CCER; // capture/compare enable register

    constexpr auto CNT_ = BitField<tim9_t, 0, 16, "CNT">{}; // bit offset: 0, bit width: 16, counter value
    static Register<std::uint32_t, TIM9_BASE_ADDRESS + 0x00000024u, 0, READWRITE, "CNT", decltype(CNT_)> CNT; // counter

    constexpr auto PSC_ = BitField<tim9_t, 0, 16, "PSC">{}; // bit offset: 0, bit width: 16, Prescaler value
    static Register<std::uint32_t, TIM9_BASE_ADDRESS + 0x00000028u, 0, READWRITE, "PSC", decltype(PSC_)> PSC; // prescaler

    constexpr auto ARR_ = BitField<tim9_t, 0, 16, "ARR">{}; // bit offset: 0, bit width: 16, Auto-reload value
    static Register<std::uint32_t, TIM9_BASE_ADDRESS + 0x0000002cu, 0, READWRITE, "ARR", decltype(ARR_)> ARR; // auto-reload register

    constexpr auto CCR1_ = BitField<tim9_t, 0, 16, "CCR1">{}; // bit offset: 0, bit width: 16, Capture/Compare 1 value
    static Register<std::uint32_t, TIM9_BASE_ADDRESS + 0x00000034u, 0, READWRITE, "CCR1", decltype(CCR1_)> CCR1; // capture/compare register 1

    constexpr auto CCR2_ = BitField<tim9_t, 0, 16, "CCR2">{}; // bit offset: 0, bit width: 16, Capture/Compare 2 value
    static Register<std::uint32_t, TIM9_BASE_ADDRESS + 0x00000038u, 0, READWRITE, "CCR2", decltype(CCR2_)> CCR2; // capture/compare register 2

} // namespace TIM9