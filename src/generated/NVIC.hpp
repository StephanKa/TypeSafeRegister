#include <Register.hpp>

namespace NVIC
{
    struct nvic_t{};

    constexpr std::uint32_t NVIC_BASE_ADDRESS = 0xe000e000u;

    constexpr auto INTLINESNUM = BitField<nvic_t, 0, 4, "INTLINESNUM">{}; // bit offset: 0, bit width: 4, Total number of interrupt lines in groups
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000004u, 0, READONLY, "ICTR", decltype(INTLINESNUM)> ICTR; // Interrupt Controller Type Register

    constexpr auto INTID = BitField<nvic_t, 0, 9, "INTID">{}; // bit offset: 0, bit width: 9, interrupt to be triggered
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000f00u, 0, WRITEONLY, "STIR", decltype(INTID)> STIR; // Software Triggered Interrupt Register

    constexpr auto SETENA = BitField<nvic_t, 0, 32, "SETENA">{}; // bit offset: 0, bit width: 32, SETENA
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000100u, 0, READWRITE, "ISER0", decltype(SETENA)> ISER0; // Interrupt Set-Enable Register

    constexpr auto SETENA = BitField<nvic_t, 0, 32, "SETENA">{}; // bit offset: 0, bit width: 32, SETENA
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000104u, 0, READWRITE, "ISER1", decltype(SETENA)> ISER1; // Interrupt Set-Enable Register

    constexpr auto SETENA = BitField<nvic_t, 0, 32, "SETENA">{}; // bit offset: 0, bit width: 32, SETENA
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000108u, 0, READWRITE, "ISER2", decltype(SETENA)> ISER2; // Interrupt Set-Enable Register

    constexpr auto CLRENA = BitField<nvic_t, 0, 32, "CLRENA">{}; // bit offset: 0, bit width: 32, CLRENA
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000180u, 0, READWRITE, "ICER0", decltype(CLRENA)> ICER0; // Interrupt Clear-Enable Register

    constexpr auto CLRENA = BitField<nvic_t, 0, 32, "CLRENA">{}; // bit offset: 0, bit width: 32, CLRENA
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000184u, 0, READWRITE, "ICER1", decltype(CLRENA)> ICER1; // Interrupt Clear-Enable Register

    constexpr auto CLRENA = BitField<nvic_t, 0, 32, "CLRENA">{}; // bit offset: 0, bit width: 32, CLRENA
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000188u, 0, READWRITE, "ICER2", decltype(CLRENA)> ICER2; // Interrupt Clear-Enable Register

    constexpr auto SETPEND = BitField<nvic_t, 0, 32, "SETPEND">{}; // bit offset: 0, bit width: 32, SETPEND
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000200u, 0, READWRITE, "ISPR0", decltype(SETPEND)> ISPR0; // Interrupt Set-Pending Register

    constexpr auto SETPEND = BitField<nvic_t, 0, 32, "SETPEND">{}; // bit offset: 0, bit width: 32, SETPEND
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000204u, 0, READWRITE, "ISPR1", decltype(SETPEND)> ISPR1; // Interrupt Set-Pending Register

    constexpr auto SETPEND = BitField<nvic_t, 0, 32, "SETPEND">{}; // bit offset: 0, bit width: 32, SETPEND
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000208u, 0, READWRITE, "ISPR2", decltype(SETPEND)> ISPR2; // Interrupt Set-Pending Register

    constexpr auto CLRPEND = BitField<nvic_t, 0, 32, "CLRPEND">{}; // bit offset: 0, bit width: 32, CLRPEND
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000280u, 0, READWRITE, "ICPR0", decltype(CLRPEND)> ICPR0; // Interrupt Clear-Pending Register

    constexpr auto CLRPEND = BitField<nvic_t, 0, 32, "CLRPEND">{}; // bit offset: 0, bit width: 32, CLRPEND
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000284u, 0, READWRITE, "ICPR1", decltype(CLRPEND)> ICPR1; // Interrupt Clear-Pending Register

    constexpr auto CLRPEND = BitField<nvic_t, 0, 32, "CLRPEND">{}; // bit offset: 0, bit width: 32, CLRPEND
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000288u, 0, READWRITE, "ICPR2", decltype(CLRPEND)> ICPR2; // Interrupt Clear-Pending Register

    constexpr auto ACTIVE = BitField<nvic_t, 0, 32, "ACTIVE">{}; // bit offset: 0, bit width: 32, ACTIVE
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000300u, 0, READONLY, "IABR0", decltype(ACTIVE)> IABR0; // Interrupt Active Bit Register

    constexpr auto ACTIVE = BitField<nvic_t, 0, 32, "ACTIVE">{}; // bit offset: 0, bit width: 32, ACTIVE
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000304u, 0, READONLY, "IABR1", decltype(ACTIVE)> IABR1; // Interrupt Active Bit Register

    constexpr auto ACTIVE = BitField<nvic_t, 0, 32, "ACTIVE">{}; // bit offset: 0, bit width: 32, ACTIVE
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000308u, 0, READONLY, "IABR2", decltype(ACTIVE)> IABR2; // Interrupt Active Bit Register

    constexpr auto IPR_N0 = BitField<nvic_t, 0, 8, "IPR_N0">{}; // bit offset: 0, bit width: 8, IPR_N0
    constexpr auto IPR_N1 = BitField<nvic_t, 8, 8, "IPR_N1">{}; // bit offset: 8, bit width: 8, IPR_N1
    constexpr auto IPR_N2 = BitField<nvic_t, 16, 8, "IPR_N2">{}; // bit offset: 16, bit width: 8, IPR_N2
    constexpr auto IPR_N3 = BitField<nvic_t, 24, 8, "IPR_N3">{}; // bit offset: 24, bit width: 8, IPR_N3
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000400u, 0, READWRITE, "IPR0", decltype(IPR_N0), decltype(IPR_N1), decltype(IPR_N2), decltype(IPR_N3)> IPR0; // Interrupt Priority Register

    constexpr auto IPR_N0 = BitField<nvic_t, 0, 8, "IPR_N0">{}; // bit offset: 0, bit width: 8, IPR_N0
    constexpr auto IPR_N1 = BitField<nvic_t, 8, 8, "IPR_N1">{}; // bit offset: 8, bit width: 8, IPR_N1
    constexpr auto IPR_N2 = BitField<nvic_t, 16, 8, "IPR_N2">{}; // bit offset: 16, bit width: 8, IPR_N2
    constexpr auto IPR_N3 = BitField<nvic_t, 24, 8, "IPR_N3">{}; // bit offset: 24, bit width: 8, IPR_N3
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000404u, 0, READWRITE, "IPR1", decltype(IPR_N0), decltype(IPR_N1), decltype(IPR_N2), decltype(IPR_N3)> IPR1; // Interrupt Priority Register

    constexpr auto IPR_N0 = BitField<nvic_t, 0, 8, "IPR_N0">{}; // bit offset: 0, bit width: 8, IPR_N0
    constexpr auto IPR_N1 = BitField<nvic_t, 8, 8, "IPR_N1">{}; // bit offset: 8, bit width: 8, IPR_N1
    constexpr auto IPR_N2 = BitField<nvic_t, 16, 8, "IPR_N2">{}; // bit offset: 16, bit width: 8, IPR_N2
    constexpr auto IPR_N3 = BitField<nvic_t, 24, 8, "IPR_N3">{}; // bit offset: 24, bit width: 8, IPR_N3
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000408u, 0, READWRITE, "IPR2", decltype(IPR_N0), decltype(IPR_N1), decltype(IPR_N2), decltype(IPR_N3)> IPR2; // Interrupt Priority Register

    constexpr auto IPR_N0 = BitField<nvic_t, 0, 8, "IPR_N0">{}; // bit offset: 0, bit width: 8, IPR_N0
    constexpr auto IPR_N1 = BitField<nvic_t, 8, 8, "IPR_N1">{}; // bit offset: 8, bit width: 8, IPR_N1
    constexpr auto IPR_N2 = BitField<nvic_t, 16, 8, "IPR_N2">{}; // bit offset: 16, bit width: 8, IPR_N2
    constexpr auto IPR_N3 = BitField<nvic_t, 24, 8, "IPR_N3">{}; // bit offset: 24, bit width: 8, IPR_N3
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x0000040cu, 0, READWRITE, "IPR3", decltype(IPR_N0), decltype(IPR_N1), decltype(IPR_N2), decltype(IPR_N3)> IPR3; // Interrupt Priority Register

    constexpr auto IPR_N0 = BitField<nvic_t, 0, 8, "IPR_N0">{}; // bit offset: 0, bit width: 8, IPR_N0
    constexpr auto IPR_N1 = BitField<nvic_t, 8, 8, "IPR_N1">{}; // bit offset: 8, bit width: 8, IPR_N1
    constexpr auto IPR_N2 = BitField<nvic_t, 16, 8, "IPR_N2">{}; // bit offset: 16, bit width: 8, IPR_N2
    constexpr auto IPR_N3 = BitField<nvic_t, 24, 8, "IPR_N3">{}; // bit offset: 24, bit width: 8, IPR_N3
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000410u, 0, READWRITE, "IPR4", decltype(IPR_N0), decltype(IPR_N1), decltype(IPR_N2), decltype(IPR_N3)> IPR4; // Interrupt Priority Register

    constexpr auto IPR_N0 = BitField<nvic_t, 0, 8, "IPR_N0">{}; // bit offset: 0, bit width: 8, IPR_N0
    constexpr auto IPR_N1 = BitField<nvic_t, 8, 8, "IPR_N1">{}; // bit offset: 8, bit width: 8, IPR_N1
    constexpr auto IPR_N2 = BitField<nvic_t, 16, 8, "IPR_N2">{}; // bit offset: 16, bit width: 8, IPR_N2
    constexpr auto IPR_N3 = BitField<nvic_t, 24, 8, "IPR_N3">{}; // bit offset: 24, bit width: 8, IPR_N3
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000414u, 0, READWRITE, "IPR5", decltype(IPR_N0), decltype(IPR_N1), decltype(IPR_N2), decltype(IPR_N3)> IPR5; // Interrupt Priority Register

    constexpr auto IPR_N0 = BitField<nvic_t, 0, 8, "IPR_N0">{}; // bit offset: 0, bit width: 8, IPR_N0
    constexpr auto IPR_N1 = BitField<nvic_t, 8, 8, "IPR_N1">{}; // bit offset: 8, bit width: 8, IPR_N1
    constexpr auto IPR_N2 = BitField<nvic_t, 16, 8, "IPR_N2">{}; // bit offset: 16, bit width: 8, IPR_N2
    constexpr auto IPR_N3 = BitField<nvic_t, 24, 8, "IPR_N3">{}; // bit offset: 24, bit width: 8, IPR_N3
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000418u, 0, READWRITE, "IPR6", decltype(IPR_N0), decltype(IPR_N1), decltype(IPR_N2), decltype(IPR_N3)> IPR6; // Interrupt Priority Register

    constexpr auto IPR_N0 = BitField<nvic_t, 0, 8, "IPR_N0">{}; // bit offset: 0, bit width: 8, IPR_N0
    constexpr auto IPR_N1 = BitField<nvic_t, 8, 8, "IPR_N1">{}; // bit offset: 8, bit width: 8, IPR_N1
    constexpr auto IPR_N2 = BitField<nvic_t, 16, 8, "IPR_N2">{}; // bit offset: 16, bit width: 8, IPR_N2
    constexpr auto IPR_N3 = BitField<nvic_t, 24, 8, "IPR_N3">{}; // bit offset: 24, bit width: 8, IPR_N3
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x0000041cu, 0, READWRITE, "IPR7", decltype(IPR_N0), decltype(IPR_N1), decltype(IPR_N2), decltype(IPR_N3)> IPR7; // Interrupt Priority Register

    constexpr auto IPR_N0 = BitField<nvic_t, 0, 8, "IPR_N0">{}; // bit offset: 0, bit width: 8, IPR_N0
    constexpr auto IPR_N1 = BitField<nvic_t, 8, 8, "IPR_N1">{}; // bit offset: 8, bit width: 8, IPR_N1
    constexpr auto IPR_N2 = BitField<nvic_t, 16, 8, "IPR_N2">{}; // bit offset: 16, bit width: 8, IPR_N2
    constexpr auto IPR_N3 = BitField<nvic_t, 24, 8, "IPR_N3">{}; // bit offset: 24, bit width: 8, IPR_N3
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000420u, 0, READWRITE, "IPR8", decltype(IPR_N0), decltype(IPR_N1), decltype(IPR_N2), decltype(IPR_N3)> IPR8; // Interrupt Priority Register

    constexpr auto IPR_N0 = BitField<nvic_t, 0, 8, "IPR_N0">{}; // bit offset: 0, bit width: 8, IPR_N0
    constexpr auto IPR_N1 = BitField<nvic_t, 8, 8, "IPR_N1">{}; // bit offset: 8, bit width: 8, IPR_N1
    constexpr auto IPR_N2 = BitField<nvic_t, 16, 8, "IPR_N2">{}; // bit offset: 16, bit width: 8, IPR_N2
    constexpr auto IPR_N3 = BitField<nvic_t, 24, 8, "IPR_N3">{}; // bit offset: 24, bit width: 8, IPR_N3
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000424u, 0, READWRITE, "IPR9", decltype(IPR_N0), decltype(IPR_N1), decltype(IPR_N2), decltype(IPR_N3)> IPR9; // Interrupt Priority Register

    constexpr auto IPR_N0 = BitField<nvic_t, 0, 8, "IPR_N0">{}; // bit offset: 0, bit width: 8, IPR_N0
    constexpr auto IPR_N1 = BitField<nvic_t, 8, 8, "IPR_N1">{}; // bit offset: 8, bit width: 8, IPR_N1
    constexpr auto IPR_N2 = BitField<nvic_t, 16, 8, "IPR_N2">{}; // bit offset: 16, bit width: 8, IPR_N2
    constexpr auto IPR_N3 = BitField<nvic_t, 24, 8, "IPR_N3">{}; // bit offset: 24, bit width: 8, IPR_N3
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000428u, 0, READWRITE, "IPR10", decltype(IPR_N0), decltype(IPR_N1), decltype(IPR_N2), decltype(IPR_N3)> IPR10; // Interrupt Priority Register

    constexpr auto IPR_N0 = BitField<nvic_t, 0, 8, "IPR_N0">{}; // bit offset: 0, bit width: 8, IPR_N0
    constexpr auto IPR_N1 = BitField<nvic_t, 8, 8, "IPR_N1">{}; // bit offset: 8, bit width: 8, IPR_N1
    constexpr auto IPR_N2 = BitField<nvic_t, 16, 8, "IPR_N2">{}; // bit offset: 16, bit width: 8, IPR_N2
    constexpr auto IPR_N3 = BitField<nvic_t, 24, 8, "IPR_N3">{}; // bit offset: 24, bit width: 8, IPR_N3
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x0000042cu, 0, READWRITE, "IPR11", decltype(IPR_N0), decltype(IPR_N1), decltype(IPR_N2), decltype(IPR_N3)> IPR11; // Interrupt Priority Register

    constexpr auto IPR_N0 = BitField<nvic_t, 0, 8, "IPR_N0">{}; // bit offset: 0, bit width: 8, IPR_N0
    constexpr auto IPR_N1 = BitField<nvic_t, 8, 8, "IPR_N1">{}; // bit offset: 8, bit width: 8, IPR_N1
    constexpr auto IPR_N2 = BitField<nvic_t, 16, 8, "IPR_N2">{}; // bit offset: 16, bit width: 8, IPR_N2
    constexpr auto IPR_N3 = BitField<nvic_t, 24, 8, "IPR_N3">{}; // bit offset: 24, bit width: 8, IPR_N3
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000430u, 0, READWRITE, "IPR12", decltype(IPR_N0), decltype(IPR_N1), decltype(IPR_N2), decltype(IPR_N3)> IPR12; // Interrupt Priority Register

    constexpr auto IPR_N0 = BitField<nvic_t, 0, 8, "IPR_N0">{}; // bit offset: 0, bit width: 8, IPR_N0
    constexpr auto IPR_N1 = BitField<nvic_t, 8, 8, "IPR_N1">{}; // bit offset: 8, bit width: 8, IPR_N1
    constexpr auto IPR_N2 = BitField<nvic_t, 16, 8, "IPR_N2">{}; // bit offset: 16, bit width: 8, IPR_N2
    constexpr auto IPR_N3 = BitField<nvic_t, 24, 8, "IPR_N3">{}; // bit offset: 24, bit width: 8, IPR_N3
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000434u, 0, READWRITE, "IPR13", decltype(IPR_N0), decltype(IPR_N1), decltype(IPR_N2), decltype(IPR_N3)> IPR13; // Interrupt Priority Register

    constexpr auto IPR_N0 = BitField<nvic_t, 0, 8, "IPR_N0">{}; // bit offset: 0, bit width: 8, IPR_N0
    constexpr auto IPR_N1 = BitField<nvic_t, 8, 8, "IPR_N1">{}; // bit offset: 8, bit width: 8, IPR_N1
    constexpr auto IPR_N2 = BitField<nvic_t, 16, 8, "IPR_N2">{}; // bit offset: 16, bit width: 8, IPR_N2
    constexpr auto IPR_N3 = BitField<nvic_t, 24, 8, "IPR_N3">{}; // bit offset: 24, bit width: 8, IPR_N3
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000438u, 0, READWRITE, "IPR14", decltype(IPR_N0), decltype(IPR_N1), decltype(IPR_N2), decltype(IPR_N3)> IPR14; // Interrupt Priority Register

    constexpr auto IPR_N0 = BitField<nvic_t, 0, 8, "IPR_N0">{}; // bit offset: 0, bit width: 8, IPR_N0
    constexpr auto IPR_N1 = BitField<nvic_t, 8, 8, "IPR_N1">{}; // bit offset: 8, bit width: 8, IPR_N1
    constexpr auto IPR_N2 = BitField<nvic_t, 16, 8, "IPR_N2">{}; // bit offset: 16, bit width: 8, IPR_N2
    constexpr auto IPR_N3 = BitField<nvic_t, 24, 8, "IPR_N3">{}; // bit offset: 24, bit width: 8, IPR_N3
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x0000043cu, 0, READWRITE, "IPR15", decltype(IPR_N0), decltype(IPR_N1), decltype(IPR_N2), decltype(IPR_N3)> IPR15; // Interrupt Priority Register

    constexpr auto IPR_N0 = BitField<nvic_t, 0, 8, "IPR_N0">{}; // bit offset: 0, bit width: 8, IPR_N0
    constexpr auto IPR_N1 = BitField<nvic_t, 8, 8, "IPR_N1">{}; // bit offset: 8, bit width: 8, IPR_N1
    constexpr auto IPR_N2 = BitField<nvic_t, 16, 8, "IPR_N2">{}; // bit offset: 16, bit width: 8, IPR_N2
    constexpr auto IPR_N3 = BitField<nvic_t, 24, 8, "IPR_N3">{}; // bit offset: 24, bit width: 8, IPR_N3
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000440u, 0, READWRITE, "IPR16", decltype(IPR_N0), decltype(IPR_N1), decltype(IPR_N2), decltype(IPR_N3)> IPR16; // Interrupt Priority Register

    constexpr auto IPR_N0 = BitField<nvic_t, 0, 8, "IPR_N0">{}; // bit offset: 0, bit width: 8, IPR_N0
    constexpr auto IPR_N1 = BitField<nvic_t, 8, 8, "IPR_N1">{}; // bit offset: 8, bit width: 8, IPR_N1
    constexpr auto IPR_N2 = BitField<nvic_t, 16, 8, "IPR_N2">{}; // bit offset: 16, bit width: 8, IPR_N2
    constexpr auto IPR_N3 = BitField<nvic_t, 24, 8, "IPR_N3">{}; // bit offset: 24, bit width: 8, IPR_N3
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000444u, 0, READWRITE, "IPR17", decltype(IPR_N0), decltype(IPR_N1), decltype(IPR_N2), decltype(IPR_N3)> IPR17; // Interrupt Priority Register

    constexpr auto IPR_N0 = BitField<nvic_t, 0, 8, "IPR_N0">{}; // bit offset: 0, bit width: 8, IPR_N0
    constexpr auto IPR_N1 = BitField<nvic_t, 8, 8, "IPR_N1">{}; // bit offset: 8, bit width: 8, IPR_N1
    constexpr auto IPR_N2 = BitField<nvic_t, 16, 8, "IPR_N2">{}; // bit offset: 16, bit width: 8, IPR_N2
    constexpr auto IPR_N3 = BitField<nvic_t, 24, 8, "IPR_N3">{}; // bit offset: 24, bit width: 8, IPR_N3
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x00000448u, 0, READWRITE, "IPR18", decltype(IPR_N0), decltype(IPR_N1), decltype(IPR_N2), decltype(IPR_N3)> IPR18; // Interrupt Priority Register

    constexpr auto IPR_N0 = BitField<nvic_t, 0, 8, "IPR_N0">{}; // bit offset: 0, bit width: 8, IPR_N0
    constexpr auto IPR_N1 = BitField<nvic_t, 8, 8, "IPR_N1">{}; // bit offset: 8, bit width: 8, IPR_N1
    constexpr auto IPR_N2 = BitField<nvic_t, 16, 8, "IPR_N2">{}; // bit offset: 16, bit width: 8, IPR_N2
    constexpr auto IPR_N3 = BitField<nvic_t, 24, 8, "IPR_N3">{}; // bit offset: 24, bit width: 8, IPR_N3
    static Register<std::uint32_t, NVIC_BASE_ADDRESS + 0x0000044cu, 0, READWRITE, "IPR19", decltype(IPR_N0), decltype(IPR_N1), decltype(IPR_N2), decltype(IPR_N3)> IPR19; // Interrupt Priority Register

} // namespace NVIC