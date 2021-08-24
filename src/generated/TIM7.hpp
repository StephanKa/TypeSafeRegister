#include <Register.hpp>




namespace TIM7
{
    struct tim7_t{};

    constexpr std::uint32_t TIM7_BASE_ADDRESS = 0x40001400u;

    constexpr auto CEN = BitField<tim7_t, 0, 1>{}; // bit offset: 0, bit width: 1, Counter enable
    constexpr auto UDIS = BitField<tim7_t, 1, 1>{}; // bit offset: 1, bit width: 1, Update disable
    constexpr auto URS = BitField<tim7_t, 2, 1>{}; // bit offset: 2, bit width: 1, Update request source
    constexpr auto OPM = BitField<tim7_t, 3, 1>{}; // bit offset: 3, bit width: 1, One-pulse mode
    constexpr auto ARPE = BitField<tim7_t, 7, 1>{}; // bit offset: 7, bit width: 1, Auto-reload preload enable
    static Register<std::uint32_t, TIM7_BASE_ADDRESS + 0x00000000u, 0, READWRITE, decltype(CEN), decltype(UDIS), decltype(URS), decltype(OPM), decltype(ARPE)> CR1; // control register 1

    constexpr auto MMS = BitField<tim7_t, 4, 3>{}; // bit offset: 4, bit width: 3, Master mode selection
    static Register<std::uint32_t, TIM7_BASE_ADDRESS + 0x00000004u, 0, READWRITE, decltype(MMS)> CR2; // control register 2

    constexpr auto UIE = BitField<tim7_t, 0, 1>{}; // bit offset: 0, bit width: 1, Update interrupt enable
    constexpr auto UDE = BitField<tim7_t, 8, 1>{}; // bit offset: 8, bit width: 1, Update DMA request enable
    static Register<std::uint32_t, TIM7_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, decltype(UIE), decltype(UDE)> DIER; // DMA/Interrupt enable register

    constexpr auto UIF = BitField<tim7_t, 0, 1>{}; // bit offset: 0, bit width: 1, Update interrupt flag
    static Register<std::uint32_t, TIM7_BASE_ADDRESS + 0x00000010u, 0, READWRITE, decltype(UIF)> SR; // status register

    constexpr auto UG = BitField<tim7_t, 0, 1>{}; // bit offset: 0, bit width: 1, Update generation
    static Register<std::uint32_t, TIM7_BASE_ADDRESS + 0x00000014u, 0, WRITEONLY, decltype(UG)> EGR; // event generation register

    constexpr auto CNT_ = BitField<tim7_t, 0, 16>{}; // bit offset: 0, bit width: 16, Low counter value
    static Register<std::uint32_t, TIM7_BASE_ADDRESS + 0x00000024u, 0, READWRITE, decltype(CNT_)> CNT; // counter

    constexpr auto PSC_ = BitField<tim7_t, 0, 16>{}; // bit offset: 0, bit width: 16, Prescaler value
    static Register<std::uint32_t, TIM7_BASE_ADDRESS + 0x00000028u, 0, READWRITE, decltype(PSC_)> PSC; // prescaler

    constexpr auto ARR_ = BitField<tim7_t, 0, 16>{}; // bit offset: 0, bit width: 16, Low Auto-reload value
    static Register<std::uint32_t, TIM7_BASE_ADDRESS + 0x0000002cu, 0, READWRITE, decltype(ARR_)> ARR; // auto-reload register

} // namespace TIM7