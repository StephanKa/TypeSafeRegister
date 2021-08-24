#include <Register.hpp>




namespace DBG
{
    struct dbg_t{};

    constexpr std::uint32_t DBG_BASE_ADDRESS = 0xe0042000u;

    constexpr auto DEV_ID = BitField<dbg_t, 0, 12>{}; // bit offset: 0, bit width: 12, DEV_ID
    constexpr auto REV_ID = BitField<dbg_t, 16, 16>{}; // bit offset: 16, bit width: 16, REV_ID
    static Register<std::uint32_t, DBG_BASE_ADDRESS + 0x00000000u, 268461073, READONLY, decltype(DEV_ID), decltype(REV_ID)> DBGMCU_IDCODE; // IDCODE

    constexpr auto DBG_SLEEP = BitField<dbg_t, 0, 1>{}; // bit offset: 0, bit width: 1, DBG_SLEEP
    constexpr auto DBG_STOP = BitField<dbg_t, 1, 1>{}; // bit offset: 1, bit width: 1, DBG_STOP
    constexpr auto DBG_STANDBY = BitField<dbg_t, 2, 1>{}; // bit offset: 2, bit width: 1, DBG_STANDBY
    constexpr auto TRACE_IOEN = BitField<dbg_t, 5, 1>{}; // bit offset: 5, bit width: 1, TRACE_IOEN
    constexpr auto TRACE_MODE = BitField<dbg_t, 6, 2>{}; // bit offset: 6, bit width: 2, TRACE_MODE
    static Register<std::uint32_t, DBG_BASE_ADDRESS + 0x00000004u, 0, READWRITE, decltype(DBG_SLEEP), decltype(DBG_STOP), decltype(DBG_STANDBY), decltype(TRACE_IOEN), decltype(TRACE_MODE)> DBGMCU_CR; // Control Register

    constexpr auto DBG_TIM2_STOP = BitField<dbg_t, 0, 1>{}; // bit offset: 0, bit width: 1, DBG_TIM2_STOP
    constexpr auto DBG_TIM3_STOP = BitField<dbg_t, 1, 1>{}; // bit offset: 1, bit width: 1, DBG_TIM3 _STOP
    constexpr auto DBG_TIM4_STOP = BitField<dbg_t, 2, 1>{}; // bit offset: 2, bit width: 1, DBG_TIM4_STOP
    constexpr auto DBG_TIM5_STOP = BitField<dbg_t, 3, 1>{}; // bit offset: 3, bit width: 1, DBG_TIM5_STOP
    constexpr auto DBG_TIM6_STOP = BitField<dbg_t, 4, 1>{}; // bit offset: 4, bit width: 1, DBG_TIM6_STOP
    constexpr auto DBG_TIM7_STOP = BitField<dbg_t, 5, 1>{}; // bit offset: 5, bit width: 1, DBG_TIM7_STOP
    constexpr auto DBG_TIM12_STOP = BitField<dbg_t, 6, 1>{}; // bit offset: 6, bit width: 1, DBG_TIM12_STOP
    constexpr auto DBG_TIM13_STOP = BitField<dbg_t, 7, 1>{}; // bit offset: 7, bit width: 1, DBG_TIM13_STOP
    constexpr auto DBG_TIM14_STOP = BitField<dbg_t, 8, 1>{}; // bit offset: 8, bit width: 1, DBG_TIM14_STOP
    constexpr auto DBG_WWDG_STOP = BitField<dbg_t, 11, 1>{}; // bit offset: 11, bit width: 1, DBG_WWDG_STOP
    constexpr auto DBG_IWDEG_STOP = BitField<dbg_t, 12, 1>{}; // bit offset: 12, bit width: 1, DBG_IWDEG_STOP
    constexpr auto DBG_J2C1_SMBUS_TIMEOUT = BitField<dbg_t, 21, 1>{}; // bit offset: 21, bit width: 1, DBG_J2C1_SMBUS_TIMEOUT
    constexpr auto DBG_J2C2_SMBUS_TIMEOUT = BitField<dbg_t, 22, 1>{}; // bit offset: 22, bit width: 1, DBG_J2C2_SMBUS_TIMEOUT
    constexpr auto DBG_J2C3SMBUS_TIMEOUT = BitField<dbg_t, 23, 1>{}; // bit offset: 23, bit width: 1, DBG_J2C3SMBUS_TIMEOUT
    constexpr auto DBG_CAN1_STOP = BitField<dbg_t, 25, 1>{}; // bit offset: 25, bit width: 1, DBG_CAN1_STOP
    constexpr auto DBG_CAN2_STOP = BitField<dbg_t, 26, 1>{}; // bit offset: 26, bit width: 1, DBG_CAN2_STOP
    static Register<std::uint32_t, DBG_BASE_ADDRESS + 0x00000008u, 0, READWRITE, decltype(DBG_TIM2_STOP), decltype(DBG_TIM3_STOP), decltype(DBG_TIM4_STOP), decltype(DBG_TIM5_STOP), decltype(DBG_TIM6_STOP), decltype(DBG_TIM7_STOP), decltype(DBG_TIM12_STOP), decltype(DBG_TIM13_STOP), decltype(DBG_TIM14_STOP), decltype(DBG_WWDG_STOP), decltype(DBG_IWDEG_STOP), decltype(DBG_J2C1_SMBUS_TIMEOUT), decltype(DBG_J2C2_SMBUS_TIMEOUT), decltype(DBG_J2C3SMBUS_TIMEOUT), decltype(DBG_CAN1_STOP), decltype(DBG_CAN2_STOP)> DBGMCU_APB1_FZ; // Debug MCU APB1 Freeze registe

    constexpr auto DBG_TIM1_STOP = BitField<dbg_t, 0, 1>{}; // bit offset: 0, bit width: 1, TIM1 counter stopped when core is halted
    constexpr auto DBG_TIM8_STOP = BitField<dbg_t, 1, 1>{}; // bit offset: 1, bit width: 1, TIM8 counter stopped when core is halted
    constexpr auto DBG_TIM9_STOP = BitField<dbg_t, 16, 1>{}; // bit offset: 16, bit width: 1, TIM9 counter stopped when core is halted
    constexpr auto DBG_TIM10_STOP = BitField<dbg_t, 17, 1>{}; // bit offset: 17, bit width: 1, TIM10 counter stopped when core is halted
    constexpr auto DBG_TIM11_STOP = BitField<dbg_t, 18, 1>{}; // bit offset: 18, bit width: 1, TIM11 counter stopped when core is halted
    static Register<std::uint32_t, DBG_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, decltype(DBG_TIM1_STOP), decltype(DBG_TIM8_STOP), decltype(DBG_TIM9_STOP), decltype(DBG_TIM10_STOP), decltype(DBG_TIM11_STOP)> DBGMCU_APB2_FZ; // Debug MCU APB2 Freeze registe

} // namespace DBG