#include <Register.hpp>




namespace FLASH
{
    struct flash_t{};

    constexpr std::uint32_t FLASH_BASE_ADDRESS = 0x40023c00u;

    constexpr auto LATENCY = BitField<flash_t, 0, 3, READWRITE>{}; // bit offset: 0, bit width: 3, Latency
    constexpr auto PRFTEN = BitField<flash_t, 8, 1, READWRITE>{}; // bit offset: 8, bit width: 1, Prefetch enable
    constexpr auto ICEN = BitField<flash_t, 9, 1, READWRITE>{}; // bit offset: 9, bit width: 1, Instruction cache enable
    constexpr auto DCEN = BitField<flash_t, 10, 1, READWRITE>{}; // bit offset: 10, bit width: 1, Data cache enable
    constexpr auto ICRST = BitField<flash_t, 11, 1, WRITEONLY>{}; // bit offset: 11, bit width: 1, Instruction cache reset
    constexpr auto DCRST = BitField<flash_t, 12, 1, READWRITE>{}; // bit offset: 12, bit width: 1, Data cache reset
    static Register<std::uint32_t, FLASH_BASE_ADDRESS + 0x00000000u, 0, READWRITE, decltype(LATENCY), decltype(PRFTEN), decltype(ICEN), decltype(DCEN), decltype(ICRST), decltype(DCRST)> ACR; // Flash access control register

    constexpr auto KEY = BitField<flash_t, 0, 32>{}; // bit offset: 0, bit width: 32, FPEC key
    static Register<std::uint32_t, FLASH_BASE_ADDRESS + 0x00000004u, 0, WRITEONLY, decltype(KEY)> KEYR; // Flash key register

    constexpr auto OPTKEY = BitField<flash_t, 0, 32>{}; // bit offset: 0, bit width: 32, Option byte key
    static Register<std::uint32_t, FLASH_BASE_ADDRESS + 0x00000008u, 0, WRITEONLY, decltype(OPTKEY)> OPTKEYR; // Flash option key register

    constexpr auto EOP = BitField<flash_t, 0, 1, READWRITE>{}; // bit offset: 0, bit width: 1, End of operation
    constexpr auto OPERR = BitField<flash_t, 1, 1, READWRITE>{}; // bit offset: 1, bit width: 1, Operation error
    constexpr auto WRPERR = BitField<flash_t, 4, 1, READWRITE>{}; // bit offset: 4, bit width: 1, Write protection error
    constexpr auto PGAERR = BitField<flash_t, 5, 1, READWRITE>{}; // bit offset: 5, bit width: 1, Programming alignment error
    constexpr auto PGPERR = BitField<flash_t, 6, 1, READWRITE>{}; // bit offset: 6, bit width: 1, Programming parallelism error
    constexpr auto PGSERR = BitField<flash_t, 7, 1, READWRITE>{}; // bit offset: 7, bit width: 1, Programming sequence error
    constexpr auto BSY = BitField<flash_t, 16, 1, READONLY>{}; // bit offset: 16, bit width: 1, Busy
    static Register<std::uint32_t, FLASH_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, decltype(EOP), decltype(OPERR), decltype(WRPERR), decltype(PGAERR), decltype(PGPERR), decltype(PGSERR), decltype(BSY)> SR; // Status register

    constexpr auto PG = BitField<flash_t, 0, 1>{}; // bit offset: 0, bit width: 1, Programming
    constexpr auto SER = BitField<flash_t, 1, 1>{}; // bit offset: 1, bit width: 1, Sector Erase
    constexpr auto MER = BitField<flash_t, 2, 1>{}; // bit offset: 2, bit width: 1, Mass Erase
    constexpr auto SNB = BitField<flash_t, 3, 4>{}; // bit offset: 3, bit width: 4, Sector number
    constexpr auto PSIZE = BitField<flash_t, 8, 2>{}; // bit offset: 8, bit width: 2, Program size
    constexpr auto STRT = BitField<flash_t, 16, 1>{}; // bit offset: 16, bit width: 1, Start
    constexpr auto EOPIE = BitField<flash_t, 24, 1>{}; // bit offset: 24, bit width: 1, End of operation interrupt enable
    constexpr auto ERRIE = BitField<flash_t, 25, 1>{}; // bit offset: 25, bit width: 1, Error interrupt enable
    constexpr auto LOCK = BitField<flash_t, 31, 1>{}; // bit offset: 31, bit width: 1, Lock
    static Register<std::uint32_t, FLASH_BASE_ADDRESS + 0x00000010u, 2147483648, READWRITE, decltype(PG), decltype(SER), decltype(MER), decltype(SNB), decltype(PSIZE), decltype(STRT), decltype(EOPIE), decltype(ERRIE), decltype(LOCK)> CR; // Control register

    constexpr auto OPTLOCK = BitField<flash_t, 0, 1>{}; // bit offset: 0, bit width: 1, Option lock
    constexpr auto OPTSTRT = BitField<flash_t, 1, 1>{}; // bit offset: 1, bit width: 1, Option start
    constexpr auto BOR_LEV = BitField<flash_t, 2, 2>{}; // bit offset: 2, bit width: 2, BOR reset Level
    constexpr auto WDG_SW = BitField<flash_t, 5, 1>{}; // bit offset: 5, bit width: 1, WDG_SW User option bytes
    constexpr auto nRST_STOP = BitField<flash_t, 6, 1>{}; // bit offset: 6, bit width: 1, nRST_STOP User option bytes
    constexpr auto nRST_STDBY = BitField<flash_t, 7, 1>{}; // bit offset: 7, bit width: 1, nRST_STDBY User option bytes
    constexpr auto RDP = BitField<flash_t, 8, 8>{}; // bit offset: 8, bit width: 8, Read protect
    constexpr auto nWRP = BitField<flash_t, 16, 12>{}; // bit offset: 16, bit width: 12, Not write protect
    static Register<std::uint32_t, FLASH_BASE_ADDRESS + 0x00000014u, 20, READWRITE, decltype(OPTLOCK), decltype(OPTSTRT), decltype(BOR_LEV), decltype(WDG_SW), decltype(nRST_STOP), decltype(nRST_STDBY), decltype(RDP), decltype(nWRP)> OPTCR; // Flash option control register

} // namespace FLASH