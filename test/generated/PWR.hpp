#include <Register.hpp>

namespace PWR
{
    struct pwr_t{};

    constexpr std::uint32_t PWR_BASE_ADDRESS = 0x40007000u;

    constexpr auto LPDS = BitField<pwr_t, 0, 1, "LPDS">{}; // bit offset: 0, bit width: 1, Low-power deep sleep
    constexpr auto PDDS = BitField<pwr_t, 1, 1, "PDDS">{}; // bit offset: 1, bit width: 1, Power down deepsleep
    constexpr auto CWUF = BitField<pwr_t, 2, 1, "CWUF">{}; // bit offset: 2, bit width: 1, Clear wakeup flag
    constexpr auto CSBF = BitField<pwr_t, 3, 1, "CSBF">{}; // bit offset: 3, bit width: 1, Clear standby flag
    constexpr auto PVDE = BitField<pwr_t, 4, 1, "PVDE">{}; // bit offset: 4, bit width: 1, Power voltage detector enable
    constexpr auto PLS = BitField<pwr_t, 5, 3, "PLS">{}; // bit offset: 5, bit width: 3, PVD level selection
    constexpr auto DBP = BitField<pwr_t, 8, 1, "DBP">{}; // bit offset: 8, bit width: 1, Disable backup domain write protection
    constexpr auto FPDS = BitField<pwr_t, 9, 1, "FPDS">{}; // bit offset: 9, bit width: 1, Flash power down in Stop mode
    static Register<std::uint32_t, PWR_BASE_ADDRESS + 0x00000000u, 0, READWRITE, "CR", decltype(LPDS), decltype(PDDS), decltype(CWUF), decltype(CSBF), decltype(PVDE), decltype(PLS), decltype(DBP), decltype(FPDS)> CR; // power control register

    constexpr auto WUF = BitField<pwr_t, 0, 1, "WUF", READONLY>{}; // bit offset: 0, bit width: 1, Wakeup flag
    constexpr auto SBF = BitField<pwr_t, 1, 1, "SBF", READONLY>{}; // bit offset: 1, bit width: 1, Standby flag
    constexpr auto PVDO = BitField<pwr_t, 2, 1, "PVDO", READONLY>{}; // bit offset: 2, bit width: 1, PVD output
    constexpr auto BRR = BitField<pwr_t, 3, 1, "BRR", READONLY>{}; // bit offset: 3, bit width: 1, Backup regulator ready
    constexpr auto EWUP = BitField<pwr_t, 8, 1, "EWUP", READWRITE>{}; // bit offset: 8, bit width: 1, Enable WKUP pin
    constexpr auto BRE = BitField<pwr_t, 9, 1, "BRE", READWRITE>{}; // bit offset: 9, bit width: 1, Backup regulator enable
    static Register<std::uint32_t, PWR_BASE_ADDRESS + 0x00000004u, 0, READWRITE, "CSR", decltype(WUF), decltype(SBF), decltype(PVDO), decltype(BRR), decltype(EWUP), decltype(BRE)> CSR; // power control/status register

} // namespace PWR