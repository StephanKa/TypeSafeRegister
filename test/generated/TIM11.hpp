#include <Register.hpp>

namespace TIM11
{
    struct tim11_t{};

    constexpr std::uint32_t TIM11_BASE_ADDRESS = 0x40014800u;

    constexpr auto CEN = BitField<tim11_t, 0, 1, "CEN">{}; // bit offset: 0, bit width: 1, Counter enable
    constexpr auto UDIS = BitField<tim11_t, 1, 1, "UDIS">{}; // bit offset: 1, bit width: 1, Update disable
    constexpr auto URS = BitField<tim11_t, 2, 1, "URS">{}; // bit offset: 2, bit width: 1, Update request source
    constexpr auto ARPE = BitField<tim11_t, 7, 1, "ARPE">{}; // bit offset: 7, bit width: 1, Auto-reload preload enable
    constexpr auto CKD = BitField<tim11_t, 8, 2, "CKD">{}; // bit offset: 8, bit width: 2, Clock division
    static Register<std::uint32_t, TIM11_BASE_ADDRESS + 0x00000000u, 0, READWRITE, "CR1", decltype(CEN), decltype(UDIS), decltype(URS), decltype(ARPE), decltype(CKD)> CR1; // control register 1

    constexpr auto UIE = BitField<tim11_t, 0, 1, "UIE">{}; // bit offset: 0, bit width: 1, Update interrupt enable
    constexpr auto CC1IE = BitField<tim11_t, 1, 1, "CC1IE">{}; // bit offset: 1, bit width: 1, Capture/Compare 1 interrupt enable
    static Register<std::uint32_t, TIM11_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, "DIER", decltype(UIE), decltype(CC1IE)> DIER; // DMA/Interrupt enable register

    constexpr auto UIF = BitField<tim11_t, 0, 1, "UIF">{}; // bit offset: 0, bit width: 1, Update interrupt flag
    constexpr auto CC1IF = BitField<tim11_t, 1, 1, "CC1IF">{}; // bit offset: 1, bit width: 1, Capture/compare 1 interrupt flag
    constexpr auto CC1OF = BitField<tim11_t, 9, 1, "CC1OF">{}; // bit offset: 9, bit width: 1, Capture/Compare 1 overcapture flag
    static Register<std::uint32_t, TIM11_BASE_ADDRESS + 0x00000010u, 0, READWRITE, "SR", decltype(UIF), decltype(CC1IF), decltype(CC1OF)> SR; // status register

    constexpr auto UG = BitField<tim11_t, 0, 1, "UG">{}; // bit offset: 0, bit width: 1, Update generation
    constexpr auto CC1G = BitField<tim11_t, 1, 1, "CC1G">{}; // bit offset: 1, bit width: 1, Capture/compare 1 generation
    static Register<std::uint32_t, TIM11_BASE_ADDRESS + 0x00000014u, 0, WRITEONLY, "EGR", decltype(UG), decltype(CC1G)> EGR; // event generation register

    constexpr auto CC1S = BitField<tim11_t, 0, 2, "CC1S">{}; // bit offset: 0, bit width: 2, Capture/Compare 1 selection
    constexpr auto OC1FE = BitField<tim11_t, 2, 1, "OC1FE">{}; // bit offset: 2, bit width: 1, Output compare 1 fast enable
    constexpr auto OC1PE = BitField<tim11_t, 3, 1, "OC1PE">{}; // bit offset: 3, bit width: 1, Output Compare 1 preload enable
    constexpr auto OC1M = BitField<tim11_t, 4, 3, "OC1M">{}; // bit offset: 4, bit width: 3, Output Compare 1 mode
    static Register<std::uint32_t, TIM11_BASE_ADDRESS + 0x00000018u, 0, READWRITE, "CCMR1_OUTPUT", decltype(CC1S), decltype(OC1FE), decltype(OC1PE), decltype(OC1M)> CCMR1_OUTPUT; // capture/compare mode register (output mode)

    constexpr auto CC1S = BitField<tim11_t, 0, 2, "CC1S">{}; // bit offset: 0, bit width: 2, Capture/Compare 1 selection
    constexpr auto IC1PSC = BitField<tim11_t, 2, 2, "IC1PSC">{}; // bit offset: 2, bit width: 2, Input capture 1 prescaler
    constexpr auto IC1F = BitField<tim11_t, 4, 4, "IC1F">{}; // bit offset: 4, bit width: 4, Input capture 1 filter
    static Register<std::uint32_t, TIM11_BASE_ADDRESS + 0x00000018u, 0, READWRITE, "CCMR1_INPUT", decltype(CC1S), decltype(IC1PSC), decltype(IC1F)> CCMR1_INPUT; // capture/compare mode register (inputmode)

    constexpr auto CC1E = BitField<tim11_t, 0, 1, "CC1E">{}; // bit offset: 0, bit width: 1, Capture/Compare 1 output enable
    constexpr auto CC1P = BitField<tim11_t, 1, 1, "CC1P">{}; // bit offset: 1, bit width: 1, Capture/Compare 1 output Polarity
    constexpr auto CC1NP = BitField<tim11_t, 3, 1, "CC1NP">{}; // bit offset: 3, bit width: 1, Capture/Compare 1 output Polarity
    static Register<std::uint32_t, TIM11_BASE_ADDRESS + 0x00000020u, 0, READWRITE, "CCER", decltype(CC1E), decltype(CC1P), decltype(CC1NP)> CCER; // capture/compare enable register

    constexpr auto CNT_ = BitField<tim11_t, 0, 16, "CNT">{}; // bit offset: 0, bit width: 16, counter value
    static Register<std::uint32_t, TIM11_BASE_ADDRESS + 0x00000024u, 0, READWRITE, "CNT", decltype(CNT_)> CNT; // counter

    constexpr auto PSC_ = BitField<tim11_t, 0, 16, "PSC">{}; // bit offset: 0, bit width: 16, Prescaler value
    static Register<std::uint32_t, TIM11_BASE_ADDRESS + 0x00000028u, 0, READWRITE, "PSC", decltype(PSC_)> PSC; // prescaler

    constexpr auto ARR_ = BitField<tim11_t, 0, 16, "ARR">{}; // bit offset: 0, bit width: 16, Auto-reload value
    static Register<std::uint32_t, TIM11_BASE_ADDRESS + 0x0000002cu, 0, READWRITE, "ARR", decltype(ARR_)> ARR; // auto-reload register

    constexpr auto CCR1_ = BitField<tim11_t, 0, 16, "CCR1">{}; // bit offset: 0, bit width: 16, Capture/Compare 1 value
    static Register<std::uint32_t, TIM11_BASE_ADDRESS + 0x00000034u, 0, READWRITE, "CCR1", decltype(CCR1_)> CCR1; // capture/compare register 1

    constexpr auto RMP = BitField<tim11_t, 0, 2, "RMP">{}; // bit offset: 0, bit width: 2, Input 1 remapping capability
    static Register<std::uint32_t, TIM11_BASE_ADDRESS + 0x00000050u, 0, READWRITE, "OR", decltype(RMP)> OR; // option register

} // namespace TIM11