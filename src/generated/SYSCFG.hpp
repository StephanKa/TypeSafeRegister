#include <Register.hpp>




namespace SYSCFG
{
    struct syscfg_t{};

    constexpr std::uint32_t SYSCFG_BASE_ADDRESS = 0x40013800u;

    constexpr auto MEM_MODE = BitField<syscfg_t, 0, 2>{}; // bit offset: 0, bit width: 2, MEM_MODE
    static Register<std::uint32_t, SYSCFG_BASE_ADDRESS + 0x00000000u, 0, READWRITE, decltype(MEM_MODE)> MEMRM; // memory remap register

    constexpr auto MII_RMII_SEL = BitField<syscfg_t, 23, 1>{}; // bit offset: 23, bit width: 1, Ethernet PHY interface selection
    static Register<std::uint32_t, SYSCFG_BASE_ADDRESS + 0x00000004u, 0, READWRITE, decltype(MII_RMII_SEL)> PMC; // peripheral mode configuration register

    constexpr auto EXTI0 = BitField<syscfg_t, 0, 4>{}; // bit offset: 0, bit width: 4, EXTI x configuration (x = 0 to 3)
    constexpr auto EXTI1 = BitField<syscfg_t, 4, 4>{}; // bit offset: 4, bit width: 4, EXTI x configuration (x = 0 to 3)
    constexpr auto EXTI2 = BitField<syscfg_t, 8, 4>{}; // bit offset: 8, bit width: 4, EXTI x configuration (x = 0 to 3)
    constexpr auto EXTI3 = BitField<syscfg_t, 12, 4>{}; // bit offset: 12, bit width: 4, EXTI x configuration (x = 0 to 3)
    static Register<std::uint32_t, SYSCFG_BASE_ADDRESS + 0x00000008u, 0, READWRITE, decltype(EXTI0), decltype(EXTI1), decltype(EXTI2), decltype(EXTI3)> EXTICR1; // external interrupt configuration register 1

    constexpr auto EXTI4 = BitField<syscfg_t, 0, 4>{}; // bit offset: 0, bit width: 4, EXTI x configuration (x = 4 to 7)
    constexpr auto EXTI5 = BitField<syscfg_t, 4, 4>{}; // bit offset: 4, bit width: 4, EXTI x configuration (x = 4 to 7)
    constexpr auto EXTI6 = BitField<syscfg_t, 8, 4>{}; // bit offset: 8, bit width: 4, EXTI x configuration (x = 4 to 7)
    constexpr auto EXTI7 = BitField<syscfg_t, 12, 4>{}; // bit offset: 12, bit width: 4, EXTI x configuration (x = 4 to 7)
    static Register<std::uint32_t, SYSCFG_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, decltype(EXTI4), decltype(EXTI5), decltype(EXTI6), decltype(EXTI7)> EXTICR2; // external interrupt configuration register 2

    constexpr auto EXTI8 = BitField<syscfg_t, 0, 4>{}; // bit offset: 0, bit width: 4, EXTI x configuration (x = 8 to 11)
    constexpr auto EXTI9 = BitField<syscfg_t, 4, 4>{}; // bit offset: 4, bit width: 4, EXTI x configuration (x = 8 to 11)
    constexpr auto EXTI10 = BitField<syscfg_t, 8, 4>{}; // bit offset: 8, bit width: 4, EXTI10
    constexpr auto EXTI11 = BitField<syscfg_t, 12, 4>{}; // bit offset: 12, bit width: 4, EXTI x configuration (x = 8 to 11)
    static Register<std::uint32_t, SYSCFG_BASE_ADDRESS + 0x00000010u, 0, READWRITE, decltype(EXTI8), decltype(EXTI9), decltype(EXTI10), decltype(EXTI11)> EXTICR3; // external interrupt configuration register 3

    constexpr auto EXTI12 = BitField<syscfg_t, 0, 4>{}; // bit offset: 0, bit width: 4, EXTI x configuration (x = 12 to 15)
    constexpr auto EXTI13 = BitField<syscfg_t, 4, 4>{}; // bit offset: 4, bit width: 4, EXTI x configuration (x = 12 to 15)
    constexpr auto EXTI14 = BitField<syscfg_t, 8, 4>{}; // bit offset: 8, bit width: 4, EXTI x configuration (x = 12 to 15)
    constexpr auto EXTI15 = BitField<syscfg_t, 12, 4>{}; // bit offset: 12, bit width: 4, EXTI x configuration (x = 12 to 15)
    static Register<std::uint32_t, SYSCFG_BASE_ADDRESS + 0x00000014u, 0, READWRITE, decltype(EXTI12), decltype(EXTI13), decltype(EXTI14), decltype(EXTI15)> EXTICR4; // external interrupt configuration register 4

    constexpr auto CMP_PD = BitField<syscfg_t, 0, 1, READWRITE>{}; // bit offset: 0, bit width: 1, Compensation cell power-down
    constexpr auto READY = BitField<syscfg_t, 7, 1, READONLY>{}; // bit offset: 7, bit width: 1, READY
    static Register<std::uint32_t, SYSCFG_BASE_ADDRESS + 0x00000020u, 0, READWRITE, decltype(CMP_PD), decltype(READY)> CMPCR; // Compensation cell control register

} // namespace SYSCFG