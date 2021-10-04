#include <Register.hpp>

namespace WWDG
{
    struct wwdg_t{};

    constexpr std::uint32_t WWDG_BASE_ADDRESS = 0x40002c00u;

    constexpr auto T = BitField<wwdg_t, 0, 7, "T">{}; // bit offset: 0, bit width: 7, 7-bit counter (MSB to LSB)
    constexpr auto WDGA = BitField<wwdg_t, 7, 1, "WDGA">{}; // bit offset: 7, bit width: 1, Activation bit
    static Register<std::uint32_t, WWDG_BASE_ADDRESS + 0x00000000u, 127, READWRITE, "CR", decltype(T), decltype(WDGA)> CR; // Control register

    constexpr auto W = BitField<wwdg_t, 0, 7, "W">{}; // bit offset: 0, bit width: 7, 7-bit window value
    constexpr auto WDGTB = BitField<wwdg_t, 7, 2, "WDGTB">{}; // bit offset: 7, bit width: 2, Timer base
    constexpr auto EWI = BitField<wwdg_t, 9, 1, "EWI">{}; // bit offset: 9, bit width: 1, Early wakeup interrupt
    static Register<std::uint32_t, WWDG_BASE_ADDRESS + 0x00000004u, 127, READWRITE, "CFR", decltype(W), decltype(WDGTB), decltype(EWI)> CFR; // Configuration register

    constexpr auto EWIF = BitField<wwdg_t, 0, 1, "EWIF">{}; // bit offset: 0, bit width: 1, Early wakeup interrupt flag
    static Register<std::uint32_t, WWDG_BASE_ADDRESS + 0x00000008u, 0, READWRITE, "SR", decltype(EWIF)> SR; // Status register

} // namespace WWDG