#include <Register.hpp>




namespace EXTI
{
    struct exti_t{};

    constexpr std::uint32_t EXTI_BASE_ADDRESS = 0x40013c00u;

    constexpr auto MR0 = BitField<exti_t, 0, 1>{}; // bit offset: 0, bit width: 1, Interrupt Mask on line 0
    constexpr auto MR1 = BitField<exti_t, 1, 1>{}; // bit offset: 1, bit width: 1, Interrupt Mask on line 1
    constexpr auto MR2 = BitField<exti_t, 2, 1>{}; // bit offset: 2, bit width: 1, Interrupt Mask on line 2
    constexpr auto MR3 = BitField<exti_t, 3, 1>{}; // bit offset: 3, bit width: 1, Interrupt Mask on line 3
    constexpr auto MR4 = BitField<exti_t, 4, 1>{}; // bit offset: 4, bit width: 1, Interrupt Mask on line 4
    constexpr auto MR5 = BitField<exti_t, 5, 1>{}; // bit offset: 5, bit width: 1, Interrupt Mask on line 5
    constexpr auto MR6 = BitField<exti_t, 6, 1>{}; // bit offset: 6, bit width: 1, Interrupt Mask on line 6
    constexpr auto MR7 = BitField<exti_t, 7, 1>{}; // bit offset: 7, bit width: 1, Interrupt Mask on line 7
    constexpr auto MR8 = BitField<exti_t, 8, 1>{}; // bit offset: 8, bit width: 1, Interrupt Mask on line 8
    constexpr auto MR9 = BitField<exti_t, 9, 1>{}; // bit offset: 9, bit width: 1, Interrupt Mask on line 9
    constexpr auto MR10 = BitField<exti_t, 10, 1>{}; // bit offset: 10, bit width: 1, Interrupt Mask on line 10
    constexpr auto MR11 = BitField<exti_t, 11, 1>{}; // bit offset: 11, bit width: 1, Interrupt Mask on line 11
    constexpr auto MR12 = BitField<exti_t, 12, 1>{}; // bit offset: 12, bit width: 1, Interrupt Mask on line 12
    constexpr auto MR13 = BitField<exti_t, 13, 1>{}; // bit offset: 13, bit width: 1, Interrupt Mask on line 13
    constexpr auto MR14 = BitField<exti_t, 14, 1>{}; // bit offset: 14, bit width: 1, Interrupt Mask on line 14
    constexpr auto MR15 = BitField<exti_t, 15, 1>{}; // bit offset: 15, bit width: 1, Interrupt Mask on line 15
    constexpr auto MR16 = BitField<exti_t, 16, 1>{}; // bit offset: 16, bit width: 1, Interrupt Mask on line 16
    constexpr auto MR17 = BitField<exti_t, 17, 1>{}; // bit offset: 17, bit width: 1, Interrupt Mask on line 17
    constexpr auto MR18 = BitField<exti_t, 18, 1>{}; // bit offset: 18, bit width: 1, Interrupt Mask on line 18
    constexpr auto MR19 = BitField<exti_t, 19, 1>{}; // bit offset: 19, bit width: 1, Interrupt Mask on line 19
    constexpr auto MR20 = BitField<exti_t, 20, 1>{}; // bit offset: 20, bit width: 1, Interrupt Mask on line 20
    constexpr auto MR21 = BitField<exti_t, 21, 1>{}; // bit offset: 21, bit width: 1, Interrupt Mask on line 21
    constexpr auto MR22 = BitField<exti_t, 22, 1>{}; // bit offset: 22, bit width: 1, Interrupt Mask on line 22
    static Register<std::uint32_t, EXTI_BASE_ADDRESS + 0x00000000u, 0, READWRITE, decltype(MR0), decltype(MR1), decltype(MR2), decltype(MR3), decltype(MR4), decltype(MR5), decltype(MR6), decltype(MR7), decltype(MR8), decltype(MR9), decltype(MR10), decltype(MR11), decltype(MR12), decltype(MR13), decltype(MR14), decltype(MR15), decltype(MR16), decltype(MR17), decltype(MR18), decltype(MR19), decltype(MR20), decltype(MR21), decltype(MR22)> IMR; // Interrupt mask register (EXTI_IMR)

    constexpr auto MR0 = BitField<exti_t, 0, 1>{}; // bit offset: 0, bit width: 1, Event Mask on line 0
    constexpr auto MR1 = BitField<exti_t, 1, 1>{}; // bit offset: 1, bit width: 1, Event Mask on line 1
    constexpr auto MR2 = BitField<exti_t, 2, 1>{}; // bit offset: 2, bit width: 1, Event Mask on line 2
    constexpr auto MR3 = BitField<exti_t, 3, 1>{}; // bit offset: 3, bit width: 1, Event Mask on line 3
    constexpr auto MR4 = BitField<exti_t, 4, 1>{}; // bit offset: 4, bit width: 1, Event Mask on line 4
    constexpr auto MR5 = BitField<exti_t, 5, 1>{}; // bit offset: 5, bit width: 1, Event Mask on line 5
    constexpr auto MR6 = BitField<exti_t, 6, 1>{}; // bit offset: 6, bit width: 1, Event Mask on line 6
    constexpr auto MR7 = BitField<exti_t, 7, 1>{}; // bit offset: 7, bit width: 1, Event Mask on line 7
    constexpr auto MR8 = BitField<exti_t, 8, 1>{}; // bit offset: 8, bit width: 1, Event Mask on line 8
    constexpr auto MR9 = BitField<exti_t, 9, 1>{}; // bit offset: 9, bit width: 1, Event Mask on line 9
    constexpr auto MR10 = BitField<exti_t, 10, 1>{}; // bit offset: 10, bit width: 1, Event Mask on line 10
    constexpr auto MR11 = BitField<exti_t, 11, 1>{}; // bit offset: 11, bit width: 1, Event Mask on line 11
    constexpr auto MR12 = BitField<exti_t, 12, 1>{}; // bit offset: 12, bit width: 1, Event Mask on line 12
    constexpr auto MR13 = BitField<exti_t, 13, 1>{}; // bit offset: 13, bit width: 1, Event Mask on line 13
    constexpr auto MR14 = BitField<exti_t, 14, 1>{}; // bit offset: 14, bit width: 1, Event Mask on line 14
    constexpr auto MR15 = BitField<exti_t, 15, 1>{}; // bit offset: 15, bit width: 1, Event Mask on line 15
    constexpr auto MR16 = BitField<exti_t, 16, 1>{}; // bit offset: 16, bit width: 1, Event Mask on line 16
    constexpr auto MR17 = BitField<exti_t, 17, 1>{}; // bit offset: 17, bit width: 1, Event Mask on line 17
    constexpr auto MR18 = BitField<exti_t, 18, 1>{}; // bit offset: 18, bit width: 1, Event Mask on line 18
    constexpr auto MR19 = BitField<exti_t, 19, 1>{}; // bit offset: 19, bit width: 1, Event Mask on line 19
    constexpr auto MR20 = BitField<exti_t, 20, 1>{}; // bit offset: 20, bit width: 1, Event Mask on line 20
    constexpr auto MR21 = BitField<exti_t, 21, 1>{}; // bit offset: 21, bit width: 1, Event Mask on line 21
    constexpr auto MR22 = BitField<exti_t, 22, 1>{}; // bit offset: 22, bit width: 1, Event Mask on line 22
    static Register<std::uint32_t, EXTI_BASE_ADDRESS + 0x00000004u, 0, READWRITE, decltype(MR0), decltype(MR1), decltype(MR2), decltype(MR3), decltype(MR4), decltype(MR5), decltype(MR6), decltype(MR7), decltype(MR8), decltype(MR9), decltype(MR10), decltype(MR11), decltype(MR12), decltype(MR13), decltype(MR14), decltype(MR15), decltype(MR16), decltype(MR17), decltype(MR18), decltype(MR19), decltype(MR20), decltype(MR21), decltype(MR22)> EMR; // Event mask register (EXTI_EMR)

    constexpr auto TR0 = BitField<exti_t, 0, 1>{}; // bit offset: 0, bit width: 1, Rising trigger event configuration of line 0
    constexpr auto TR1 = BitField<exti_t, 1, 1>{}; // bit offset: 1, bit width: 1, Rising trigger event configuration of line 1
    constexpr auto TR2 = BitField<exti_t, 2, 1>{}; // bit offset: 2, bit width: 1, Rising trigger event configuration of line 2
    constexpr auto TR3 = BitField<exti_t, 3, 1>{}; // bit offset: 3, bit width: 1, Rising trigger event configuration of line 3
    constexpr auto TR4 = BitField<exti_t, 4, 1>{}; // bit offset: 4, bit width: 1, Rising trigger event configuration of line 4
    constexpr auto TR5 = BitField<exti_t, 5, 1>{}; // bit offset: 5, bit width: 1, Rising trigger event configuration of line 5
    constexpr auto TR6 = BitField<exti_t, 6, 1>{}; // bit offset: 6, bit width: 1, Rising trigger event configuration of line 6
    constexpr auto TR7 = BitField<exti_t, 7, 1>{}; // bit offset: 7, bit width: 1, Rising trigger event configuration of line 7
    constexpr auto TR8 = BitField<exti_t, 8, 1>{}; // bit offset: 8, bit width: 1, Rising trigger event configuration of line 8
    constexpr auto TR9 = BitField<exti_t, 9, 1>{}; // bit offset: 9, bit width: 1, Rising trigger event configuration of line 9
    constexpr auto TR10 = BitField<exti_t, 10, 1>{}; // bit offset: 10, bit width: 1, Rising trigger event configuration of line 10
    constexpr auto TR11 = BitField<exti_t, 11, 1>{}; // bit offset: 11, bit width: 1, Rising trigger event configuration of line 11
    constexpr auto TR12 = BitField<exti_t, 12, 1>{}; // bit offset: 12, bit width: 1, Rising trigger event configuration of line 12
    constexpr auto TR13 = BitField<exti_t, 13, 1>{}; // bit offset: 13, bit width: 1, Rising trigger event configuration of line 13
    constexpr auto TR14 = BitField<exti_t, 14, 1>{}; // bit offset: 14, bit width: 1, Rising trigger event configuration of line 14
    constexpr auto TR15 = BitField<exti_t, 15, 1>{}; // bit offset: 15, bit width: 1, Rising trigger event configuration of line 15
    constexpr auto TR16 = BitField<exti_t, 16, 1>{}; // bit offset: 16, bit width: 1, Rising trigger event configuration of line 16
    constexpr auto TR17 = BitField<exti_t, 17, 1>{}; // bit offset: 17, bit width: 1, Rising trigger event configuration of line 17
    constexpr auto TR18 = BitField<exti_t, 18, 1>{}; // bit offset: 18, bit width: 1, Rising trigger event configuration of line 18
    constexpr auto TR19 = BitField<exti_t, 19, 1>{}; // bit offset: 19, bit width: 1, Rising trigger event configuration of line 19
    constexpr auto TR20 = BitField<exti_t, 20, 1>{}; // bit offset: 20, bit width: 1, Rising trigger event configuration of line 20
    constexpr auto TR21 = BitField<exti_t, 21, 1>{}; // bit offset: 21, bit width: 1, Rising trigger event configuration of line 21
    constexpr auto TR22 = BitField<exti_t, 22, 1>{}; // bit offset: 22, bit width: 1, Rising trigger event configuration of line 22
    static Register<std::uint32_t, EXTI_BASE_ADDRESS + 0x00000008u, 0, READWRITE, decltype(TR0), decltype(TR1), decltype(TR2), decltype(TR3), decltype(TR4), decltype(TR5), decltype(TR6), decltype(TR7), decltype(TR8), decltype(TR9), decltype(TR10), decltype(TR11), decltype(TR12), decltype(TR13), decltype(TR14), decltype(TR15), decltype(TR16), decltype(TR17), decltype(TR18), decltype(TR19), decltype(TR20), decltype(TR21), decltype(TR22)> RTSR; // Rising Trigger selection register (EXTI_RTSR)

    constexpr auto TR0 = BitField<exti_t, 0, 1>{}; // bit offset: 0, bit width: 1, Falling trigger event configuration of line 0
    constexpr auto TR1 = BitField<exti_t, 1, 1>{}; // bit offset: 1, bit width: 1, Falling trigger event configuration of line 1
    constexpr auto TR2 = BitField<exti_t, 2, 1>{}; // bit offset: 2, bit width: 1, Falling trigger event configuration of line 2
    constexpr auto TR3 = BitField<exti_t, 3, 1>{}; // bit offset: 3, bit width: 1, Falling trigger event configuration of line 3
    constexpr auto TR4 = BitField<exti_t, 4, 1>{}; // bit offset: 4, bit width: 1, Falling trigger event configuration of line 4
    constexpr auto TR5 = BitField<exti_t, 5, 1>{}; // bit offset: 5, bit width: 1, Falling trigger event configuration of line 5
    constexpr auto TR6 = BitField<exti_t, 6, 1>{}; // bit offset: 6, bit width: 1, Falling trigger event configuration of line 6
    constexpr auto TR7 = BitField<exti_t, 7, 1>{}; // bit offset: 7, bit width: 1, Falling trigger event configuration of line 7
    constexpr auto TR8 = BitField<exti_t, 8, 1>{}; // bit offset: 8, bit width: 1, Falling trigger event configuration of line 8
    constexpr auto TR9 = BitField<exti_t, 9, 1>{}; // bit offset: 9, bit width: 1, Falling trigger event configuration of line 9
    constexpr auto TR10 = BitField<exti_t, 10, 1>{}; // bit offset: 10, bit width: 1, Falling trigger event configuration of line 10
    constexpr auto TR11 = BitField<exti_t, 11, 1>{}; // bit offset: 11, bit width: 1, Falling trigger event configuration of line 11
    constexpr auto TR12 = BitField<exti_t, 12, 1>{}; // bit offset: 12, bit width: 1, Falling trigger event configuration of line 12
    constexpr auto TR13 = BitField<exti_t, 13, 1>{}; // bit offset: 13, bit width: 1, Falling trigger event configuration of line 13
    constexpr auto TR14 = BitField<exti_t, 14, 1>{}; // bit offset: 14, bit width: 1, Falling trigger event configuration of line 14
    constexpr auto TR15 = BitField<exti_t, 15, 1>{}; // bit offset: 15, bit width: 1, Falling trigger event configuration of line 15
    constexpr auto TR16 = BitField<exti_t, 16, 1>{}; // bit offset: 16, bit width: 1, Falling trigger event configuration of line 16
    constexpr auto TR17 = BitField<exti_t, 17, 1>{}; // bit offset: 17, bit width: 1, Falling trigger event configuration of line 17
    constexpr auto TR18 = BitField<exti_t, 18, 1>{}; // bit offset: 18, bit width: 1, Falling trigger event configuration of line 18
    constexpr auto TR19 = BitField<exti_t, 19, 1>{}; // bit offset: 19, bit width: 1, Falling trigger event configuration of line 19
    constexpr auto TR20 = BitField<exti_t, 20, 1>{}; // bit offset: 20, bit width: 1, Falling trigger event configuration of line 20
    constexpr auto TR21 = BitField<exti_t, 21, 1>{}; // bit offset: 21, bit width: 1, Falling trigger event configuration of line 21
    constexpr auto TR22 = BitField<exti_t, 22, 1>{}; // bit offset: 22, bit width: 1, Falling trigger event configuration of line 22
    static Register<std::uint32_t, EXTI_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, decltype(TR0), decltype(TR1), decltype(TR2), decltype(TR3), decltype(TR4), decltype(TR5), decltype(TR6), decltype(TR7), decltype(TR8), decltype(TR9), decltype(TR10), decltype(TR11), decltype(TR12), decltype(TR13), decltype(TR14), decltype(TR15), decltype(TR16), decltype(TR17), decltype(TR18), decltype(TR19), decltype(TR20), decltype(TR21), decltype(TR22)> FTSR; // Falling Trigger selection register (EXTI_FTSR)

    constexpr auto SWIER0 = BitField<exti_t, 0, 1>{}; // bit offset: 0, bit width: 1, Software Interrupt on line 0
    constexpr auto SWIER1 = BitField<exti_t, 1, 1>{}; // bit offset: 1, bit width: 1, Software Interrupt on line 1
    constexpr auto SWIER2 = BitField<exti_t, 2, 1>{}; // bit offset: 2, bit width: 1, Software Interrupt on line 2
    constexpr auto SWIER3 = BitField<exti_t, 3, 1>{}; // bit offset: 3, bit width: 1, Software Interrupt on line 3
    constexpr auto SWIER4 = BitField<exti_t, 4, 1>{}; // bit offset: 4, bit width: 1, Software Interrupt on line 4
    constexpr auto SWIER5 = BitField<exti_t, 5, 1>{}; // bit offset: 5, bit width: 1, Software Interrupt on line 5
    constexpr auto SWIER6 = BitField<exti_t, 6, 1>{}; // bit offset: 6, bit width: 1, Software Interrupt on line 6
    constexpr auto SWIER7 = BitField<exti_t, 7, 1>{}; // bit offset: 7, bit width: 1, Software Interrupt on line 7
    constexpr auto SWIER8 = BitField<exti_t, 8, 1>{}; // bit offset: 8, bit width: 1, Software Interrupt on line 8
    constexpr auto SWIER9 = BitField<exti_t, 9, 1>{}; // bit offset: 9, bit width: 1, Software Interrupt on line 9
    constexpr auto SWIER10 = BitField<exti_t, 10, 1>{}; // bit offset: 10, bit width: 1, Software Interrupt on line 10
    constexpr auto SWIER11 = BitField<exti_t, 11, 1>{}; // bit offset: 11, bit width: 1, Software Interrupt on line 11
    constexpr auto SWIER12 = BitField<exti_t, 12, 1>{}; // bit offset: 12, bit width: 1, Software Interrupt on line 12
    constexpr auto SWIER13 = BitField<exti_t, 13, 1>{}; // bit offset: 13, bit width: 1, Software Interrupt on line 13
    constexpr auto SWIER14 = BitField<exti_t, 14, 1>{}; // bit offset: 14, bit width: 1, Software Interrupt on line 14
    constexpr auto SWIER15 = BitField<exti_t, 15, 1>{}; // bit offset: 15, bit width: 1, Software Interrupt on line 15
    constexpr auto SWIER16 = BitField<exti_t, 16, 1>{}; // bit offset: 16, bit width: 1, Software Interrupt on line 16
    constexpr auto SWIER17 = BitField<exti_t, 17, 1>{}; // bit offset: 17, bit width: 1, Software Interrupt on line 17
    constexpr auto SWIER18 = BitField<exti_t, 18, 1>{}; // bit offset: 18, bit width: 1, Software Interrupt on line 18
    constexpr auto SWIER19 = BitField<exti_t, 19, 1>{}; // bit offset: 19, bit width: 1, Software Interrupt on line 19
    constexpr auto SWIER20 = BitField<exti_t, 20, 1>{}; // bit offset: 20, bit width: 1, Software Interrupt on line 20
    constexpr auto SWIER21 = BitField<exti_t, 21, 1>{}; // bit offset: 21, bit width: 1, Software Interrupt on line 21
    constexpr auto SWIER22 = BitField<exti_t, 22, 1>{}; // bit offset: 22, bit width: 1, Software Interrupt on line 22
    static Register<std::uint32_t, EXTI_BASE_ADDRESS + 0x00000010u, 0, READWRITE, decltype(SWIER0), decltype(SWIER1), decltype(SWIER2), decltype(SWIER3), decltype(SWIER4), decltype(SWIER5), decltype(SWIER6), decltype(SWIER7), decltype(SWIER8), decltype(SWIER9), decltype(SWIER10), decltype(SWIER11), decltype(SWIER12), decltype(SWIER13), decltype(SWIER14), decltype(SWIER15), decltype(SWIER16), decltype(SWIER17), decltype(SWIER18), decltype(SWIER19), decltype(SWIER20), decltype(SWIER21), decltype(SWIER22)> SWIER; // Software interrupt event register (EXTI_SWIER)

    constexpr auto PR0 = BitField<exti_t, 0, 1>{}; // bit offset: 0, bit width: 1, Pending bit 0
    constexpr auto PR1 = BitField<exti_t, 1, 1>{}; // bit offset: 1, bit width: 1, Pending bit 1
    constexpr auto PR2 = BitField<exti_t, 2, 1>{}; // bit offset: 2, bit width: 1, Pending bit 2
    constexpr auto PR3 = BitField<exti_t, 3, 1>{}; // bit offset: 3, bit width: 1, Pending bit 3
    constexpr auto PR4 = BitField<exti_t, 4, 1>{}; // bit offset: 4, bit width: 1, Pending bit 4
    constexpr auto PR5 = BitField<exti_t, 5, 1>{}; // bit offset: 5, bit width: 1, Pending bit 5
    constexpr auto PR6 = BitField<exti_t, 6, 1>{}; // bit offset: 6, bit width: 1, Pending bit 6
    constexpr auto PR7 = BitField<exti_t, 7, 1>{}; // bit offset: 7, bit width: 1, Pending bit 7
    constexpr auto PR8 = BitField<exti_t, 8, 1>{}; // bit offset: 8, bit width: 1, Pending bit 8
    constexpr auto PR9 = BitField<exti_t, 9, 1>{}; // bit offset: 9, bit width: 1, Pending bit 9
    constexpr auto PR10 = BitField<exti_t, 10, 1>{}; // bit offset: 10, bit width: 1, Pending bit 10
    constexpr auto PR11 = BitField<exti_t, 11, 1>{}; // bit offset: 11, bit width: 1, Pending bit 11
    constexpr auto PR12 = BitField<exti_t, 12, 1>{}; // bit offset: 12, bit width: 1, Pending bit 12
    constexpr auto PR13 = BitField<exti_t, 13, 1>{}; // bit offset: 13, bit width: 1, Pending bit 13
    constexpr auto PR14 = BitField<exti_t, 14, 1>{}; // bit offset: 14, bit width: 1, Pending bit 14
    constexpr auto PR15 = BitField<exti_t, 15, 1>{}; // bit offset: 15, bit width: 1, Pending bit 15
    constexpr auto PR16 = BitField<exti_t, 16, 1>{}; // bit offset: 16, bit width: 1, Pending bit 16
    constexpr auto PR17 = BitField<exti_t, 17, 1>{}; // bit offset: 17, bit width: 1, Pending bit 17
    constexpr auto PR18 = BitField<exti_t, 18, 1>{}; // bit offset: 18, bit width: 1, Pending bit 18
    constexpr auto PR19 = BitField<exti_t, 19, 1>{}; // bit offset: 19, bit width: 1, Pending bit 19
    constexpr auto PR20 = BitField<exti_t, 20, 1>{}; // bit offset: 20, bit width: 1, Pending bit 20
    constexpr auto PR21 = BitField<exti_t, 21, 1>{}; // bit offset: 21, bit width: 1, Pending bit 21
    constexpr auto PR22 = BitField<exti_t, 22, 1>{}; // bit offset: 22, bit width: 1, Pending bit 22
    static Register<std::uint32_t, EXTI_BASE_ADDRESS + 0x00000014u, 0, READWRITE, decltype(PR0), decltype(PR1), decltype(PR2), decltype(PR3), decltype(PR4), decltype(PR5), decltype(PR6), decltype(PR7), decltype(PR8), decltype(PR9), decltype(PR10), decltype(PR11), decltype(PR12), decltype(PR13), decltype(PR14), decltype(PR15), decltype(PR16), decltype(PR17), decltype(PR18), decltype(PR19), decltype(PR20), decltype(PR21), decltype(PR22)> PR; // Pending register (EXTI_PR)

} // namespace EXTI