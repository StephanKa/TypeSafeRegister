#include <Register.hpp>




namespace OTG_HS_PWRCLK
{
    struct otg_hs_pwrclk_t{};

    constexpr std::uint32_t OTG_HS_PWRCLK_BASE_ADDRESS = 0x40040e00u;

    constexpr auto STPPCLK = BitField<otg_hs_pwrclk_t, 0, 1>{}; // bit offset: 0, bit width: 1, Stop PHY clock
    constexpr auto GATEHCLK = BitField<otg_hs_pwrclk_t, 1, 1>{}; // bit offset: 1, bit width: 1, Gate HCLK
    constexpr auto PHYSUSP = BitField<otg_hs_pwrclk_t, 4, 1>{}; // bit offset: 4, bit width: 1, PHY suspended
    static Register<std::uint32_t, OTG_HS_PWRCLK_BASE_ADDRESS + 0x00000000u, 0, READWRITE, decltype(STPPCLK), decltype(GATEHCLK), decltype(PHYSUSP)> OTG_HS_PCGCR; // Power and clock gating control register

} // namespace OTG_HS_PWRCLK