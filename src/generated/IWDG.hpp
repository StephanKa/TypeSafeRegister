#include <Register.hpp>




namespace IWDG
{
    struct iwdg_t{};

    constexpr std::uint32_t IWDG_BASE_ADDRESS = 0x40003000u;

    constexpr auto KEY = BitField<iwdg_t, 0, 16>{}; // bit offset: 0, bit width: 16, Key value (write only, read 0000h)
    static Register<std::uint32_t, IWDG_BASE_ADDRESS + 0x00000000u, 0, WRITEONLY, decltype(KEY)> KR; // Key register

    constexpr auto PR_ = BitField<iwdg_t, 0, 3>{}; // bit offset: 0, bit width: 3, Prescaler divider
    static Register<std::uint32_t, IWDG_BASE_ADDRESS + 0x00000004u, 0, READWRITE, decltype(PR_)> PR; // Prescaler register

    constexpr auto RL = BitField<iwdg_t, 0, 12>{}; // bit offset: 0, bit width: 12, Watchdog counter reload value
    static Register<std::uint32_t, IWDG_BASE_ADDRESS + 0x00000008u, 4095, READWRITE, decltype(RL)> RLR; // Reload register

    constexpr auto PVU = BitField<iwdg_t, 0, 1>{}; // bit offset: 0, bit width: 1, Watchdog prescaler value update
    constexpr auto RVU = BitField<iwdg_t, 1, 1>{}; // bit offset: 1, bit width: 1, Watchdog counter reload value update
    static Register<std::uint32_t, IWDG_BASE_ADDRESS + 0x0000000cu, 0, READONLY, decltype(PVU), decltype(RVU)> SR; // Status register

} // namespace IWDG