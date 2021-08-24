#include <Register.hpp>




namespace OTG_FS_PWRCLK
{
    struct otg_fs_pwrclk_t{};

    constexpr std::uint32_t OTG_FS_PWRCLK_BASE_ADDRESS = 0x50000e00u;

    constexpr auto STPPCLK = BitField<otg_fs_pwrclk_t, 0, 1>{}; // bit offset: 0, bit width: 1, Stop PHY clock
    constexpr auto GATEHCLK = BitField<otg_fs_pwrclk_t, 1, 1>{}; // bit offset: 1, bit width: 1, Gate HCLK
    constexpr auto PHYSUSP = BitField<otg_fs_pwrclk_t, 4, 1>{}; // bit offset: 4, bit width: 1, PHY Suspended
    static Register<std::uint32_t, OTG_FS_PWRCLK_BASE_ADDRESS + 0x00000000u, 0, READWRITE, decltype(STPPCLK), decltype(GATEHCLK), decltype(PHYSUSP)> FS_PCGCCTL; // OTG_FS power and clock gating control register (OTG_FS_PCGCCTL)

} // namespace OTG_FS_PWRCLK