#include <Register.hpp>




namespace FSMC
{
    struct fsmc_t{};

    constexpr std::uint32_t FSMC_BASE_ADDRESS = 0xa0000000u;

    constexpr auto MBKEN = BitField<fsmc_t, 0, 1>{}; // bit offset: 0, bit width: 1, MBKEN
    constexpr auto MUXEN = BitField<fsmc_t, 1, 1>{}; // bit offset: 1, bit width: 1, MUXEN
    constexpr auto MTYP = BitField<fsmc_t, 2, 2>{}; // bit offset: 2, bit width: 2, MTYP
    constexpr auto MWID = BitField<fsmc_t, 4, 2>{}; // bit offset: 4, bit width: 2, MWID
    constexpr auto FACCEN = BitField<fsmc_t, 6, 1>{}; // bit offset: 6, bit width: 1, FACCEN
    constexpr auto BURSTEN = BitField<fsmc_t, 8, 1>{}; // bit offset: 8, bit width: 1, BURSTEN
    constexpr auto WAITPOL = BitField<fsmc_t, 9, 1>{}; // bit offset: 9, bit width: 1, WAITPOL
    constexpr auto WAITCFG = BitField<fsmc_t, 11, 1>{}; // bit offset: 11, bit width: 1, WAITCFG
    constexpr auto WREN = BitField<fsmc_t, 12, 1>{}; // bit offset: 12, bit width: 1, WREN
    constexpr auto WAITEN = BitField<fsmc_t, 13, 1>{}; // bit offset: 13, bit width: 1, WAITEN
    constexpr auto EXTMOD = BitField<fsmc_t, 14, 1>{}; // bit offset: 14, bit width: 1, EXTMOD
    constexpr auto ASYNCWAIT = BitField<fsmc_t, 15, 1>{}; // bit offset: 15, bit width: 1, ASYNCWAIT
    constexpr auto CBURSTRW = BitField<fsmc_t, 19, 1>{}; // bit offset: 19, bit width: 1, CBURSTRW
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x00000000u, 12496, READWRITE, decltype(MBKEN), decltype(MUXEN), decltype(MTYP), decltype(MWID), decltype(FACCEN), decltype(BURSTEN), decltype(WAITPOL), decltype(WAITCFG), decltype(WREN), decltype(WAITEN), decltype(EXTMOD), decltype(ASYNCWAIT), decltype(CBURSTRW)> BCR1; // SRAM/NOR-Flash chip-select control register 1

    constexpr auto ADDSET = BitField<fsmc_t, 0, 4>{}; // bit offset: 0, bit width: 4, ADDSET
    constexpr auto ADDHLD = BitField<fsmc_t, 4, 4>{}; // bit offset: 4, bit width: 4, ADDHLD
    constexpr auto DATAST = BitField<fsmc_t, 8, 8>{}; // bit offset: 8, bit width: 8, DATAST
    constexpr auto BUSTURN = BitField<fsmc_t, 16, 4>{}; // bit offset: 16, bit width: 4, BUSTURN
    constexpr auto CLKDIV = BitField<fsmc_t, 20, 4>{}; // bit offset: 20, bit width: 4, CLKDIV
    constexpr auto DATLAT = BitField<fsmc_t, 24, 4>{}; // bit offset: 24, bit width: 4, DATLAT
    constexpr auto ACCMOD = BitField<fsmc_t, 28, 2>{}; // bit offset: 28, bit width: 2, ACCMOD
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x00000004u, 4294967295, READWRITE, decltype(ADDSET), decltype(ADDHLD), decltype(DATAST), decltype(BUSTURN), decltype(CLKDIV), decltype(DATLAT), decltype(ACCMOD)> BTR1; // SRAM/NOR-Flash chip-select timing register 1

    constexpr auto MBKEN = BitField<fsmc_t, 0, 1>{}; // bit offset: 0, bit width: 1, MBKEN
    constexpr auto MUXEN = BitField<fsmc_t, 1, 1>{}; // bit offset: 1, bit width: 1, MUXEN
    constexpr auto MTYP = BitField<fsmc_t, 2, 2>{}; // bit offset: 2, bit width: 2, MTYP
    constexpr auto MWID = BitField<fsmc_t, 4, 2>{}; // bit offset: 4, bit width: 2, MWID
    constexpr auto FACCEN = BitField<fsmc_t, 6, 1>{}; // bit offset: 6, bit width: 1, FACCEN
    constexpr auto BURSTEN = BitField<fsmc_t, 8, 1>{}; // bit offset: 8, bit width: 1, BURSTEN
    constexpr auto WAITPOL = BitField<fsmc_t, 9, 1>{}; // bit offset: 9, bit width: 1, WAITPOL
    constexpr auto WRAPMOD = BitField<fsmc_t, 10, 1>{}; // bit offset: 10, bit width: 1, WRAPMOD
    constexpr auto WAITCFG = BitField<fsmc_t, 11, 1>{}; // bit offset: 11, bit width: 1, WAITCFG
    constexpr auto WREN = BitField<fsmc_t, 12, 1>{}; // bit offset: 12, bit width: 1, WREN
    constexpr auto WAITEN = BitField<fsmc_t, 13, 1>{}; // bit offset: 13, bit width: 1, WAITEN
    constexpr auto EXTMOD = BitField<fsmc_t, 14, 1>{}; // bit offset: 14, bit width: 1, EXTMOD
    constexpr auto ASYNCWAIT = BitField<fsmc_t, 15, 1>{}; // bit offset: 15, bit width: 1, ASYNCWAIT
    constexpr auto CBURSTRW = BitField<fsmc_t, 19, 1>{}; // bit offset: 19, bit width: 1, CBURSTRW
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x00000008u, 12496, READWRITE, decltype(MBKEN), decltype(MUXEN), decltype(MTYP), decltype(MWID), decltype(FACCEN), decltype(BURSTEN), decltype(WAITPOL), decltype(WRAPMOD), decltype(WAITCFG), decltype(WREN), decltype(WAITEN), decltype(EXTMOD), decltype(ASYNCWAIT), decltype(CBURSTRW)> BCR2; // SRAM/NOR-Flash chip-select control register 2

    constexpr auto ADDSET = BitField<fsmc_t, 0, 4>{}; // bit offset: 0, bit width: 4, ADDSET
    constexpr auto ADDHLD = BitField<fsmc_t, 4, 4>{}; // bit offset: 4, bit width: 4, ADDHLD
    constexpr auto DATAST = BitField<fsmc_t, 8, 8>{}; // bit offset: 8, bit width: 8, DATAST
    constexpr auto BUSTURN = BitField<fsmc_t, 16, 4>{}; // bit offset: 16, bit width: 4, BUSTURN
    constexpr auto CLKDIV = BitField<fsmc_t, 20, 4>{}; // bit offset: 20, bit width: 4, CLKDIV
    constexpr auto DATLAT = BitField<fsmc_t, 24, 4>{}; // bit offset: 24, bit width: 4, DATLAT
    constexpr auto ACCMOD = BitField<fsmc_t, 28, 2>{}; // bit offset: 28, bit width: 2, ACCMOD
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x0000000cu, 4294967295, READWRITE, decltype(ADDSET), decltype(ADDHLD), decltype(DATAST), decltype(BUSTURN), decltype(CLKDIV), decltype(DATLAT), decltype(ACCMOD)> BTR2; // SRAM/NOR-Flash chip-select timing register 2

    constexpr auto MBKEN = BitField<fsmc_t, 0, 1>{}; // bit offset: 0, bit width: 1, MBKEN
    constexpr auto MUXEN = BitField<fsmc_t, 1, 1>{}; // bit offset: 1, bit width: 1, MUXEN
    constexpr auto MTYP = BitField<fsmc_t, 2, 2>{}; // bit offset: 2, bit width: 2, MTYP
    constexpr auto MWID = BitField<fsmc_t, 4, 2>{}; // bit offset: 4, bit width: 2, MWID
    constexpr auto FACCEN = BitField<fsmc_t, 6, 1>{}; // bit offset: 6, bit width: 1, FACCEN
    constexpr auto BURSTEN = BitField<fsmc_t, 8, 1>{}; // bit offset: 8, bit width: 1, BURSTEN
    constexpr auto WAITPOL = BitField<fsmc_t, 9, 1>{}; // bit offset: 9, bit width: 1, WAITPOL
    constexpr auto WRAPMOD = BitField<fsmc_t, 10, 1>{}; // bit offset: 10, bit width: 1, WRAPMOD
    constexpr auto WAITCFG = BitField<fsmc_t, 11, 1>{}; // bit offset: 11, bit width: 1, WAITCFG
    constexpr auto WREN = BitField<fsmc_t, 12, 1>{}; // bit offset: 12, bit width: 1, WREN
    constexpr auto WAITEN = BitField<fsmc_t, 13, 1>{}; // bit offset: 13, bit width: 1, WAITEN
    constexpr auto EXTMOD = BitField<fsmc_t, 14, 1>{}; // bit offset: 14, bit width: 1, EXTMOD
    constexpr auto ASYNCWAIT = BitField<fsmc_t, 15, 1>{}; // bit offset: 15, bit width: 1, ASYNCWAIT
    constexpr auto CBURSTRW = BitField<fsmc_t, 19, 1>{}; // bit offset: 19, bit width: 1, CBURSTRW
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x00000010u, 12496, READWRITE, decltype(MBKEN), decltype(MUXEN), decltype(MTYP), decltype(MWID), decltype(FACCEN), decltype(BURSTEN), decltype(WAITPOL), decltype(WRAPMOD), decltype(WAITCFG), decltype(WREN), decltype(WAITEN), decltype(EXTMOD), decltype(ASYNCWAIT), decltype(CBURSTRW)> BCR3; // SRAM/NOR-Flash chip-select control register 3

    constexpr auto ADDSET = BitField<fsmc_t, 0, 4>{}; // bit offset: 0, bit width: 4, ADDSET
    constexpr auto ADDHLD = BitField<fsmc_t, 4, 4>{}; // bit offset: 4, bit width: 4, ADDHLD
    constexpr auto DATAST = BitField<fsmc_t, 8, 8>{}; // bit offset: 8, bit width: 8, DATAST
    constexpr auto BUSTURN = BitField<fsmc_t, 16, 4>{}; // bit offset: 16, bit width: 4, BUSTURN
    constexpr auto CLKDIV = BitField<fsmc_t, 20, 4>{}; // bit offset: 20, bit width: 4, CLKDIV
    constexpr auto DATLAT = BitField<fsmc_t, 24, 4>{}; // bit offset: 24, bit width: 4, DATLAT
    constexpr auto ACCMOD = BitField<fsmc_t, 28, 2>{}; // bit offset: 28, bit width: 2, ACCMOD
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x00000014u, 4294967295, READWRITE, decltype(ADDSET), decltype(ADDHLD), decltype(DATAST), decltype(BUSTURN), decltype(CLKDIV), decltype(DATLAT), decltype(ACCMOD)> BTR3; // SRAM/NOR-Flash chip-select timing register 3

    constexpr auto MBKEN = BitField<fsmc_t, 0, 1>{}; // bit offset: 0, bit width: 1, MBKEN
    constexpr auto MUXEN = BitField<fsmc_t, 1, 1>{}; // bit offset: 1, bit width: 1, MUXEN
    constexpr auto MTYP = BitField<fsmc_t, 2, 2>{}; // bit offset: 2, bit width: 2, MTYP
    constexpr auto MWID = BitField<fsmc_t, 4, 2>{}; // bit offset: 4, bit width: 2, MWID
    constexpr auto FACCEN = BitField<fsmc_t, 6, 1>{}; // bit offset: 6, bit width: 1, FACCEN
    constexpr auto BURSTEN = BitField<fsmc_t, 8, 1>{}; // bit offset: 8, bit width: 1, BURSTEN
    constexpr auto WAITPOL = BitField<fsmc_t, 9, 1>{}; // bit offset: 9, bit width: 1, WAITPOL
    constexpr auto WRAPMOD = BitField<fsmc_t, 10, 1>{}; // bit offset: 10, bit width: 1, WRAPMOD
    constexpr auto WAITCFG = BitField<fsmc_t, 11, 1>{}; // bit offset: 11, bit width: 1, WAITCFG
    constexpr auto WREN = BitField<fsmc_t, 12, 1>{}; // bit offset: 12, bit width: 1, WREN
    constexpr auto WAITEN = BitField<fsmc_t, 13, 1>{}; // bit offset: 13, bit width: 1, WAITEN
    constexpr auto EXTMOD = BitField<fsmc_t, 14, 1>{}; // bit offset: 14, bit width: 1, EXTMOD
    constexpr auto ASYNCWAIT = BitField<fsmc_t, 15, 1>{}; // bit offset: 15, bit width: 1, ASYNCWAIT
    constexpr auto CBURSTRW = BitField<fsmc_t, 19, 1>{}; // bit offset: 19, bit width: 1, CBURSTRW
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x00000018u, 12496, READWRITE, decltype(MBKEN), decltype(MUXEN), decltype(MTYP), decltype(MWID), decltype(FACCEN), decltype(BURSTEN), decltype(WAITPOL), decltype(WRAPMOD), decltype(WAITCFG), decltype(WREN), decltype(WAITEN), decltype(EXTMOD), decltype(ASYNCWAIT), decltype(CBURSTRW)> BCR4; // SRAM/NOR-Flash chip-select control register 4

    constexpr auto ADDSET = BitField<fsmc_t, 0, 4>{}; // bit offset: 0, bit width: 4, ADDSET
    constexpr auto ADDHLD = BitField<fsmc_t, 4, 4>{}; // bit offset: 4, bit width: 4, ADDHLD
    constexpr auto DATAST = BitField<fsmc_t, 8, 8>{}; // bit offset: 8, bit width: 8, DATAST
    constexpr auto BUSTURN = BitField<fsmc_t, 16, 4>{}; // bit offset: 16, bit width: 4, BUSTURN
    constexpr auto CLKDIV = BitField<fsmc_t, 20, 4>{}; // bit offset: 20, bit width: 4, CLKDIV
    constexpr auto DATLAT = BitField<fsmc_t, 24, 4>{}; // bit offset: 24, bit width: 4, DATLAT
    constexpr auto ACCMOD = BitField<fsmc_t, 28, 2>{}; // bit offset: 28, bit width: 2, ACCMOD
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x0000001cu, 4294967295, READWRITE, decltype(ADDSET), decltype(ADDHLD), decltype(DATAST), decltype(BUSTURN), decltype(CLKDIV), decltype(DATLAT), decltype(ACCMOD)> BTR4; // SRAM/NOR-Flash chip-select timing register 4

    constexpr auto PWAITEN = BitField<fsmc_t, 1, 1>{}; // bit offset: 1, bit width: 1, PWAITEN
    constexpr auto PBKEN = BitField<fsmc_t, 2, 1>{}; // bit offset: 2, bit width: 1, PBKEN
    constexpr auto PTYP = BitField<fsmc_t, 3, 1>{}; // bit offset: 3, bit width: 1, PTYP
    constexpr auto PWID = BitField<fsmc_t, 4, 2>{}; // bit offset: 4, bit width: 2, PWID
    constexpr auto ECCEN = BitField<fsmc_t, 6, 1>{}; // bit offset: 6, bit width: 1, ECCEN
    constexpr auto TCLR = BitField<fsmc_t, 9, 4>{}; // bit offset: 9, bit width: 4, TCLR
    constexpr auto TAR = BitField<fsmc_t, 13, 4>{}; // bit offset: 13, bit width: 4, TAR
    constexpr auto ECCPS = BitField<fsmc_t, 17, 3>{}; // bit offset: 17, bit width: 3, ECCPS
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x00000060u, 24, READWRITE, decltype(PWAITEN), decltype(PBKEN), decltype(PTYP), decltype(PWID), decltype(ECCEN), decltype(TCLR), decltype(TAR), decltype(ECCPS)> PCR2; // PC Card/NAND Flash control register 2

    constexpr auto IRS = BitField<fsmc_t, 0, 1, READWRITE>{}; // bit offset: 0, bit width: 1, IRS
    constexpr auto ILS = BitField<fsmc_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, ILS
    constexpr auto IFS = BitField<fsmc_t, 2, 1, READWRITE>{}; // bit offset: 2, bit width: 1, IFS
    constexpr auto IREN = BitField<fsmc_t, 3, 1, READWRITE>{}; // bit offset: 3, bit width: 1, IREN
    constexpr auto ILEN = BitField<fsmc_t, 4, 1, READWRITE>{}; // bit offset: 4, bit width: 1, ILEN
    constexpr auto IFEN = BitField<fsmc_t, 5, 1, READWRITE>{}; // bit offset: 5, bit width: 1, IFEN
    constexpr auto FEMPT = BitField<fsmc_t, 6, 1, READONLY>{}; // bit offset: 6, bit width: 1, FEMPT
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x00000064u, 64, READWRITE, decltype(IRS), decltype(ILS), decltype(IFS), decltype(IREN), decltype(ILEN), decltype(IFEN), decltype(FEMPT)> SR2; // FIFO status and interrupt register 2

    constexpr auto MEMSETx = BitField<fsmc_t, 0, 8>{}; // bit offset: 0, bit width: 8, MEMSETx
    constexpr auto MEMWAITx = BitField<fsmc_t, 8, 8>{}; // bit offset: 8, bit width: 8, MEMWAITx
    constexpr auto MEMHOLDx = BitField<fsmc_t, 16, 8>{}; // bit offset: 16, bit width: 8, MEMHOLDx
    constexpr auto MEMHIZx = BitField<fsmc_t, 24, 8>{}; // bit offset: 24, bit width: 8, MEMHIZx
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x00000068u, 4244438268, READWRITE, decltype(MEMSETx), decltype(MEMWAITx), decltype(MEMHOLDx), decltype(MEMHIZx)> PMEM2; // Common memory space timing register 2

    constexpr auto ATTSETx = BitField<fsmc_t, 0, 8>{}; // bit offset: 0, bit width: 8, Attribute memory x setup time
    constexpr auto ATTWAITx = BitField<fsmc_t, 8, 8>{}; // bit offset: 8, bit width: 8, Attribute memory x wait time
    constexpr auto ATTHOLDx = BitField<fsmc_t, 16, 8>{}; // bit offset: 16, bit width: 8, Attribute memory x hold time
    constexpr auto ATTHIZx = BitField<fsmc_t, 24, 8>{}; // bit offset: 24, bit width: 8, Attribute memory x databus HiZ time
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x0000006cu, 4244438268, READWRITE, decltype(ATTSETx), decltype(ATTWAITx), decltype(ATTHOLDx), decltype(ATTHIZx)> PATT2; // Attribute memory space timing register 2

    constexpr auto ECCx = BitField<fsmc_t, 0, 32>{}; // bit offset: 0, bit width: 32, ECC result
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x00000074u, 0, READONLY, decltype(ECCx)> ECCR2; // ECC result register 2

    constexpr auto PWAITEN = BitField<fsmc_t, 1, 1>{}; // bit offset: 1, bit width: 1, PWAITEN
    constexpr auto PBKEN = BitField<fsmc_t, 2, 1>{}; // bit offset: 2, bit width: 1, PBKEN
    constexpr auto PTYP = BitField<fsmc_t, 3, 1>{}; // bit offset: 3, bit width: 1, PTYP
    constexpr auto PWID = BitField<fsmc_t, 4, 2>{}; // bit offset: 4, bit width: 2, PWID
    constexpr auto ECCEN = BitField<fsmc_t, 6, 1>{}; // bit offset: 6, bit width: 1, ECCEN
    constexpr auto TCLR = BitField<fsmc_t, 9, 4>{}; // bit offset: 9, bit width: 4, TCLR
    constexpr auto TAR = BitField<fsmc_t, 13, 4>{}; // bit offset: 13, bit width: 4, TAR
    constexpr auto ECCPS = BitField<fsmc_t, 17, 3>{}; // bit offset: 17, bit width: 3, ECCPS
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x00000080u, 24, READWRITE, decltype(PWAITEN), decltype(PBKEN), decltype(PTYP), decltype(PWID), decltype(ECCEN), decltype(TCLR), decltype(TAR), decltype(ECCPS)> PCR3; // PC Card/NAND Flash control register 3

    constexpr auto IRS = BitField<fsmc_t, 0, 1, READWRITE>{}; // bit offset: 0, bit width: 1, IRS
    constexpr auto ILS = BitField<fsmc_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, ILS
    constexpr auto IFS = BitField<fsmc_t, 2, 1, READWRITE>{}; // bit offset: 2, bit width: 1, IFS
    constexpr auto IREN = BitField<fsmc_t, 3, 1, READWRITE>{}; // bit offset: 3, bit width: 1, IREN
    constexpr auto ILEN = BitField<fsmc_t, 4, 1, READWRITE>{}; // bit offset: 4, bit width: 1, ILEN
    constexpr auto IFEN = BitField<fsmc_t, 5, 1, READWRITE>{}; // bit offset: 5, bit width: 1, IFEN
    constexpr auto FEMPT = BitField<fsmc_t, 6, 1, READONLY>{}; // bit offset: 6, bit width: 1, FEMPT
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x00000084u, 64, READWRITE, decltype(IRS), decltype(ILS), decltype(IFS), decltype(IREN), decltype(ILEN), decltype(IFEN), decltype(FEMPT)> SR3; // FIFO status and interrupt register 3

    constexpr auto MEMSETx = BitField<fsmc_t, 0, 8>{}; // bit offset: 0, bit width: 8, MEMSETx
    constexpr auto MEMWAITx = BitField<fsmc_t, 8, 8>{}; // bit offset: 8, bit width: 8, MEMWAITx
    constexpr auto MEMHOLDx = BitField<fsmc_t, 16, 8>{}; // bit offset: 16, bit width: 8, MEMHOLDx
    constexpr auto MEMHIZx = BitField<fsmc_t, 24, 8>{}; // bit offset: 24, bit width: 8, MEMHIZx
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x00000088u, 4244438268, READWRITE, decltype(MEMSETx), decltype(MEMWAITx), decltype(MEMHOLDx), decltype(MEMHIZx)> PMEM3; // Common memory space timing register 3

    constexpr auto ATTSETx = BitField<fsmc_t, 0, 8>{}; // bit offset: 0, bit width: 8, ATTSETx
    constexpr auto ATTWAITx = BitField<fsmc_t, 8, 8>{}; // bit offset: 8, bit width: 8, ATTWAITx
    constexpr auto ATTHOLDx = BitField<fsmc_t, 16, 8>{}; // bit offset: 16, bit width: 8, ATTHOLDx
    constexpr auto ATTHIZx = BitField<fsmc_t, 24, 8>{}; // bit offset: 24, bit width: 8, ATTHIZx
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x0000008cu, 4244438268, READWRITE, decltype(ATTSETx), decltype(ATTWAITx), decltype(ATTHOLDx), decltype(ATTHIZx)> PATT3; // Attribute memory space timing register 3

    constexpr auto ECCx = BitField<fsmc_t, 0, 32>{}; // bit offset: 0, bit width: 32, ECCx
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x00000094u, 0, READONLY, decltype(ECCx)> ECCR3; // ECC result register 3

    constexpr auto PWAITEN = BitField<fsmc_t, 1, 1>{}; // bit offset: 1, bit width: 1, PWAITEN
    constexpr auto PBKEN = BitField<fsmc_t, 2, 1>{}; // bit offset: 2, bit width: 1, PBKEN
    constexpr auto PTYP = BitField<fsmc_t, 3, 1>{}; // bit offset: 3, bit width: 1, PTYP
    constexpr auto PWID = BitField<fsmc_t, 4, 2>{}; // bit offset: 4, bit width: 2, PWID
    constexpr auto ECCEN = BitField<fsmc_t, 6, 1>{}; // bit offset: 6, bit width: 1, ECCEN
    constexpr auto TCLR = BitField<fsmc_t, 9, 4>{}; // bit offset: 9, bit width: 4, TCLR
    constexpr auto TAR = BitField<fsmc_t, 13, 4>{}; // bit offset: 13, bit width: 4, TAR
    constexpr auto ECCPS = BitField<fsmc_t, 17, 3>{}; // bit offset: 17, bit width: 3, ECCPS
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x000000a0u, 24, READWRITE, decltype(PWAITEN), decltype(PBKEN), decltype(PTYP), decltype(PWID), decltype(ECCEN), decltype(TCLR), decltype(TAR), decltype(ECCPS)> PCR4; // PC Card/NAND Flash control register 4

    constexpr auto IRS = BitField<fsmc_t, 0, 1, READWRITE>{}; // bit offset: 0, bit width: 1, IRS
    constexpr auto ILS = BitField<fsmc_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, ILS
    constexpr auto IFS = BitField<fsmc_t, 2, 1, READWRITE>{}; // bit offset: 2, bit width: 1, IFS
    constexpr auto IREN = BitField<fsmc_t, 3, 1, READWRITE>{}; // bit offset: 3, bit width: 1, IREN
    constexpr auto ILEN = BitField<fsmc_t, 4, 1, READWRITE>{}; // bit offset: 4, bit width: 1, ILEN
    constexpr auto IFEN = BitField<fsmc_t, 5, 1, READWRITE>{}; // bit offset: 5, bit width: 1, IFEN
    constexpr auto FEMPT = BitField<fsmc_t, 6, 1, READONLY>{}; // bit offset: 6, bit width: 1, FEMPT
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x000000a4u, 64, READWRITE, decltype(IRS), decltype(ILS), decltype(IFS), decltype(IREN), decltype(ILEN), decltype(IFEN), decltype(FEMPT)> SR4; // FIFO status and interrupt register 4

    constexpr auto MEMSETx = BitField<fsmc_t, 0, 8>{}; // bit offset: 0, bit width: 8, MEMSETx
    constexpr auto MEMWAITx = BitField<fsmc_t, 8, 8>{}; // bit offset: 8, bit width: 8, MEMWAITx
    constexpr auto MEMHOLDx = BitField<fsmc_t, 16, 8>{}; // bit offset: 16, bit width: 8, MEMHOLDx
    constexpr auto MEMHIZx = BitField<fsmc_t, 24, 8>{}; // bit offset: 24, bit width: 8, MEMHIZx
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x000000a8u, 4244438268, READWRITE, decltype(MEMSETx), decltype(MEMWAITx), decltype(MEMHOLDx), decltype(MEMHIZx)> PMEM4; // Common memory space timing register 4

    constexpr auto ATTSETx = BitField<fsmc_t, 0, 8>{}; // bit offset: 0, bit width: 8, ATTSETx
    constexpr auto ATTWAITx = BitField<fsmc_t, 8, 8>{}; // bit offset: 8, bit width: 8, ATTWAITx
    constexpr auto ATTHOLDx = BitField<fsmc_t, 16, 8>{}; // bit offset: 16, bit width: 8, ATTHOLDx
    constexpr auto ATTHIZx = BitField<fsmc_t, 24, 8>{}; // bit offset: 24, bit width: 8, ATTHIZx
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x000000acu, 4244438268, READWRITE, decltype(ATTSETx), decltype(ATTWAITx), decltype(ATTHOLDx), decltype(ATTHIZx)> PATT4; // Attribute memory space timing register 4

    constexpr auto IOSETx = BitField<fsmc_t, 0, 8>{}; // bit offset: 0, bit width: 8, IOSETx
    constexpr auto IOWAITx = BitField<fsmc_t, 8, 8>{}; // bit offset: 8, bit width: 8, IOWAITx
    constexpr auto IOHOLDx = BitField<fsmc_t, 16, 8>{}; // bit offset: 16, bit width: 8, IOHOLDx
    constexpr auto IOHIZx = BitField<fsmc_t, 24, 8>{}; // bit offset: 24, bit width: 8, IOHIZx
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x000000b0u, 4244438268, READWRITE, decltype(IOSETx), decltype(IOWAITx), decltype(IOHOLDx), decltype(IOHIZx)> PIO4; // I/O space timing register 4

    constexpr auto ADDSET = BitField<fsmc_t, 0, 4>{}; // bit offset: 0, bit width: 4, ADDSET
    constexpr auto ADDHLD = BitField<fsmc_t, 4, 4>{}; // bit offset: 4, bit width: 4, ADDHLD
    constexpr auto DATAST = BitField<fsmc_t, 8, 8>{}; // bit offset: 8, bit width: 8, DATAST
    constexpr auto CLKDIV = BitField<fsmc_t, 20, 4>{}; // bit offset: 20, bit width: 4, CLKDIV
    constexpr auto DATLAT = BitField<fsmc_t, 24, 4>{}; // bit offset: 24, bit width: 4, DATLAT
    constexpr auto ACCMOD = BitField<fsmc_t, 28, 2>{}; // bit offset: 28, bit width: 2, ACCMOD
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x00000104u, 268435455, READWRITE, decltype(ADDSET), decltype(ADDHLD), decltype(DATAST), decltype(CLKDIV), decltype(DATLAT), decltype(ACCMOD)> BWTR1; // SRAM/NOR-Flash write timing registers 1

    constexpr auto ADDSET = BitField<fsmc_t, 0, 4>{}; // bit offset: 0, bit width: 4, ADDSET
    constexpr auto ADDHLD = BitField<fsmc_t, 4, 4>{}; // bit offset: 4, bit width: 4, ADDHLD
    constexpr auto DATAST = BitField<fsmc_t, 8, 8>{}; // bit offset: 8, bit width: 8, DATAST
    constexpr auto CLKDIV = BitField<fsmc_t, 20, 4>{}; // bit offset: 20, bit width: 4, CLKDIV
    constexpr auto DATLAT = BitField<fsmc_t, 24, 4>{}; // bit offset: 24, bit width: 4, DATLAT
    constexpr auto ACCMOD = BitField<fsmc_t, 28, 2>{}; // bit offset: 28, bit width: 2, ACCMOD
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x0000010cu, 268435455, READWRITE, decltype(ADDSET), decltype(ADDHLD), decltype(DATAST), decltype(CLKDIV), decltype(DATLAT), decltype(ACCMOD)> BWTR2; // SRAM/NOR-Flash write timing registers 2

    constexpr auto ADDSET = BitField<fsmc_t, 0, 4>{}; // bit offset: 0, bit width: 4, ADDSET
    constexpr auto ADDHLD = BitField<fsmc_t, 4, 4>{}; // bit offset: 4, bit width: 4, ADDHLD
    constexpr auto DATAST = BitField<fsmc_t, 8, 8>{}; // bit offset: 8, bit width: 8, DATAST
    constexpr auto CLKDIV = BitField<fsmc_t, 20, 4>{}; // bit offset: 20, bit width: 4, CLKDIV
    constexpr auto DATLAT = BitField<fsmc_t, 24, 4>{}; // bit offset: 24, bit width: 4, DATLAT
    constexpr auto ACCMOD = BitField<fsmc_t, 28, 2>{}; // bit offset: 28, bit width: 2, ACCMOD
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x00000114u, 268435455, READWRITE, decltype(ADDSET), decltype(ADDHLD), decltype(DATAST), decltype(CLKDIV), decltype(DATLAT), decltype(ACCMOD)> BWTR3; // SRAM/NOR-Flash write timing registers 3

    constexpr auto ADDSET = BitField<fsmc_t, 0, 4>{}; // bit offset: 0, bit width: 4, ADDSET
    constexpr auto ADDHLD = BitField<fsmc_t, 4, 4>{}; // bit offset: 4, bit width: 4, ADDHLD
    constexpr auto DATAST = BitField<fsmc_t, 8, 8>{}; // bit offset: 8, bit width: 8, DATAST
    constexpr auto CLKDIV = BitField<fsmc_t, 20, 4>{}; // bit offset: 20, bit width: 4, CLKDIV
    constexpr auto DATLAT = BitField<fsmc_t, 24, 4>{}; // bit offset: 24, bit width: 4, DATLAT
    constexpr auto ACCMOD = BitField<fsmc_t, 28, 2>{}; // bit offset: 28, bit width: 2, ACCMOD
    static Register<std::uint32_t, FSMC_BASE_ADDRESS + 0x0000011cu, 268435455, READWRITE, decltype(ADDSET), decltype(ADDHLD), decltype(DATAST), decltype(CLKDIV), decltype(DATLAT), decltype(ACCMOD)> BWTR4; // SRAM/NOR-Flash write timing registers 4

} // namespace FSMC