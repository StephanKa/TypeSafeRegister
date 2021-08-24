#include <Register.hpp>




namespace RTC
{
    struct rtc_t{};

    constexpr std::uint32_t RTC_BASE_ADDRESS = 0x40002800u;

    constexpr auto SU = BitField<rtc_t, 0, 4>{}; // bit offset: 0, bit width: 4, Second units in BCD format
    constexpr auto ST = BitField<rtc_t, 4, 3>{}; // bit offset: 4, bit width: 3, Second tens in BCD format
    constexpr auto MNU = BitField<rtc_t, 8, 4>{}; // bit offset: 8, bit width: 4, Minute units in BCD format
    constexpr auto MNT = BitField<rtc_t, 12, 3>{}; // bit offset: 12, bit width: 3, Minute tens in BCD format
    constexpr auto HU = BitField<rtc_t, 16, 4>{}; // bit offset: 16, bit width: 4, Hour units in BCD format
    constexpr auto HT = BitField<rtc_t, 20, 2>{}; // bit offset: 20, bit width: 2, Hour tens in BCD format
    constexpr auto PM = BitField<rtc_t, 22, 1>{}; // bit offset: 22, bit width: 1, AM/PM notation
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000000u, 0, READWRITE, decltype(SU), decltype(ST), decltype(MNU), decltype(MNT), decltype(HU), decltype(HT), decltype(PM)> TR; // time register

    constexpr auto DU = BitField<rtc_t, 0, 4>{}; // bit offset: 0, bit width: 4, Date units in BCD format
    constexpr auto DT = BitField<rtc_t, 4, 2>{}; // bit offset: 4, bit width: 2, Date tens in BCD format
    constexpr auto MU = BitField<rtc_t, 8, 4>{}; // bit offset: 8, bit width: 4, Month units in BCD format
    constexpr auto MT = BitField<rtc_t, 12, 1>{}; // bit offset: 12, bit width: 1, Month tens in BCD format
    constexpr auto WDU = BitField<rtc_t, 13, 3>{}; // bit offset: 13, bit width: 3, Week day units
    constexpr auto YU = BitField<rtc_t, 16, 4>{}; // bit offset: 16, bit width: 4, Year units in BCD format
    constexpr auto YT = BitField<rtc_t, 20, 4>{}; // bit offset: 20, bit width: 4, Year tens in BCD format
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000004u, 8449, READWRITE, decltype(DU), decltype(DT), decltype(MU), decltype(MT), decltype(WDU), decltype(YU), decltype(YT)> DR; // date register

    constexpr auto WCKSEL = BitField<rtc_t, 0, 3>{}; // bit offset: 0, bit width: 3, Wakeup clock selection
    constexpr auto TSEDGE = BitField<rtc_t, 3, 1>{}; // bit offset: 3, bit width: 1, Time-stamp event active edge
    constexpr auto REFCKON = BitField<rtc_t, 4, 1>{}; // bit offset: 4, bit width: 1, Reference clock detection enable (50 or 60 Hz)
    constexpr auto FMT = BitField<rtc_t, 6, 1>{}; // bit offset: 6, bit width: 1, Hour format
    constexpr auto DCE = BitField<rtc_t, 7, 1>{}; // bit offset: 7, bit width: 1, Coarse digital calibration enable
    constexpr auto ALRAE = BitField<rtc_t, 8, 1>{}; // bit offset: 8, bit width: 1, Alarm A enable
    constexpr auto ALRBE = BitField<rtc_t, 9, 1>{}; // bit offset: 9, bit width: 1, Alarm B enable
    constexpr auto WUTE = BitField<rtc_t, 10, 1>{}; // bit offset: 10, bit width: 1, Wakeup timer enable
    constexpr auto TSE = BitField<rtc_t, 11, 1>{}; // bit offset: 11, bit width: 1, Time stamp enable
    constexpr auto ALRAIE = BitField<rtc_t, 12, 1>{}; // bit offset: 12, bit width: 1, Alarm A interrupt enable
    constexpr auto ALRBIE = BitField<rtc_t, 13, 1>{}; // bit offset: 13, bit width: 1, Alarm B interrupt enable
    constexpr auto WUTIE = BitField<rtc_t, 14, 1>{}; // bit offset: 14, bit width: 1, Wakeup timer interrupt enable
    constexpr auto TSIE = BitField<rtc_t, 15, 1>{}; // bit offset: 15, bit width: 1, Time-stamp interrupt enable
    constexpr auto ADD1H = BitField<rtc_t, 16, 1>{}; // bit offset: 16, bit width: 1, Add 1 hour (summer time change)
    constexpr auto SUB1H = BitField<rtc_t, 17, 1>{}; // bit offset: 17, bit width: 1, Subtract 1 hour (winter time change)
    constexpr auto BKP = BitField<rtc_t, 18, 1>{}; // bit offset: 18, bit width: 1, Backup
    constexpr auto POL = BitField<rtc_t, 20, 1>{}; // bit offset: 20, bit width: 1, Output polarity
    constexpr auto OSEL = BitField<rtc_t, 21, 2>{}; // bit offset: 21, bit width: 2, Output selection
    constexpr auto COE = BitField<rtc_t, 23, 1>{}; // bit offset: 23, bit width: 1, Calibration output enable
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000008u, 0, READWRITE, decltype(WCKSEL), decltype(TSEDGE), decltype(REFCKON), decltype(FMT), decltype(DCE), decltype(ALRAE), decltype(ALRBE), decltype(WUTE), decltype(TSE), decltype(ALRAIE), decltype(ALRBIE), decltype(WUTIE), decltype(TSIE), decltype(ADD1H), decltype(SUB1H), decltype(BKP), decltype(POL), decltype(OSEL), decltype(COE)> CR; // control register

    constexpr auto ALRAWF = BitField<rtc_t, 0, 1, READONLY>{}; // bit offset: 0, bit width: 1, Alarm A write flag
    constexpr auto ALRBWF = BitField<rtc_t, 1, 1, READONLY>{}; // bit offset: 1, bit width: 1, Alarm B write flag
    constexpr auto WUTWF = BitField<rtc_t, 2, 1, READONLY>{}; // bit offset: 2, bit width: 1, Wakeup timer write flag
    constexpr auto INITS = BitField<rtc_t, 4, 1, READONLY>{}; // bit offset: 4, bit width: 1, Initialization status flag
    constexpr auto RSF = BitField<rtc_t, 5, 1, READWRITE>{}; // bit offset: 5, bit width: 1, Registers synchronization flag
    constexpr auto INITF = BitField<rtc_t, 6, 1, READONLY>{}; // bit offset: 6, bit width: 1, Initialization flag
    constexpr auto INIT = BitField<rtc_t, 7, 1, READWRITE>{}; // bit offset: 7, bit width: 1, Initialization mode
    constexpr auto ALRAF = BitField<rtc_t, 8, 1, READWRITE>{}; // bit offset: 8, bit width: 1, Alarm A flag
    constexpr auto ALRBF = BitField<rtc_t, 9, 1, READWRITE>{}; // bit offset: 9, bit width: 1, Alarm B flag
    constexpr auto WUTF = BitField<rtc_t, 10, 1, READWRITE>{}; // bit offset: 10, bit width: 1, Wakeup timer flag
    constexpr auto TSF = BitField<rtc_t, 11, 1, READWRITE>{}; // bit offset: 11, bit width: 1, Time-stamp flag
    constexpr auto TSOVF = BitField<rtc_t, 12, 1, READWRITE>{}; // bit offset: 12, bit width: 1, Time-stamp overflow flag
    constexpr auto TAMP1F = BitField<rtc_t, 13, 1, READWRITE>{}; // bit offset: 13, bit width: 1, Tamper detection flag
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x0000000cu, 7, READWRITE, decltype(ALRAWF), decltype(ALRBWF), decltype(WUTWF), decltype(INITS), decltype(RSF), decltype(INITF), decltype(INIT), decltype(ALRAF), decltype(ALRBF), decltype(WUTF), decltype(TSF), decltype(TSOVF), decltype(TAMP1F)> ISR; // initialization and status register

    constexpr auto PREDIV_S = BitField<rtc_t, 0, 13>{}; // bit offset: 0, bit width: 13, Synchronous prescaler factor
    constexpr auto PREDIV_A = BitField<rtc_t, 16, 7>{}; // bit offset: 16, bit width: 7, Asynchronous prescaler factor
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000010u, 8323327, READWRITE, decltype(PREDIV_S), decltype(PREDIV_A)> PRER; // prescaler register

    constexpr auto WUT = BitField<rtc_t, 0, 16>{}; // bit offset: 0, bit width: 16, Wakeup auto-reload value bits
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000014u, 65535, READWRITE, decltype(WUT)> WUTR; // wakeup timer register

    constexpr auto DC = BitField<rtc_t, 0, 5>{}; // bit offset: 0, bit width: 5, Digital calibration
    constexpr auto DCS = BitField<rtc_t, 7, 1>{}; // bit offset: 7, bit width: 1, Digital calibration sign
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000018u, 0, READWRITE, decltype(DC), decltype(DCS)> CALIBR; // calibration register

    constexpr auto SU = BitField<rtc_t, 0, 4>{}; // bit offset: 0, bit width: 4, Second units in BCD format
    constexpr auto ST = BitField<rtc_t, 4, 3>{}; // bit offset: 4, bit width: 3, Second tens in BCD format
    constexpr auto MSK1 = BitField<rtc_t, 7, 1>{}; // bit offset: 7, bit width: 1, Alarm A seconds mask
    constexpr auto MNU = BitField<rtc_t, 8, 4>{}; // bit offset: 8, bit width: 4, Minute units in BCD format
    constexpr auto MNT = BitField<rtc_t, 12, 3>{}; // bit offset: 12, bit width: 3, Minute tens in BCD format
    constexpr auto MSK2 = BitField<rtc_t, 15, 1>{}; // bit offset: 15, bit width: 1, Alarm A minutes mask
    constexpr auto HU = BitField<rtc_t, 16, 4>{}; // bit offset: 16, bit width: 4, Hour units in BCD format
    constexpr auto HT = BitField<rtc_t, 20, 2>{}; // bit offset: 20, bit width: 2, Hour tens in BCD format
    constexpr auto PM = BitField<rtc_t, 22, 1>{}; // bit offset: 22, bit width: 1, AM/PM notation
    constexpr auto MSK3 = BitField<rtc_t, 23, 1>{}; // bit offset: 23, bit width: 1, Alarm A hours mask
    constexpr auto DU = BitField<rtc_t, 24, 4>{}; // bit offset: 24, bit width: 4, Date units or day in BCD format
    constexpr auto DT = BitField<rtc_t, 28, 2>{}; // bit offset: 28, bit width: 2, Date tens in BCD format
    constexpr auto WDSEL = BitField<rtc_t, 30, 1>{}; // bit offset: 30, bit width: 1, Week day selection
    constexpr auto MSK4 = BitField<rtc_t, 31, 1>{}; // bit offset: 31, bit width: 1, Alarm A date mask
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x0000001cu, 0, READWRITE, decltype(SU), decltype(ST), decltype(MSK1), decltype(MNU), decltype(MNT), decltype(MSK2), decltype(HU), decltype(HT), decltype(PM), decltype(MSK3), decltype(DU), decltype(DT), decltype(WDSEL), decltype(MSK4)> ALRMAR; // alarm A register

    constexpr auto SU = BitField<rtc_t, 0, 4>{}; // bit offset: 0, bit width: 4, Second units in BCD format
    constexpr auto ST = BitField<rtc_t, 4, 3>{}; // bit offset: 4, bit width: 3, Second tens in BCD format
    constexpr auto MSK1 = BitField<rtc_t, 7, 1>{}; // bit offset: 7, bit width: 1, Alarm B seconds mask
    constexpr auto MNU = BitField<rtc_t, 8, 4>{}; // bit offset: 8, bit width: 4, Minute units in BCD format
    constexpr auto MNT = BitField<rtc_t, 12, 3>{}; // bit offset: 12, bit width: 3, Minute tens in BCD format
    constexpr auto MSK2 = BitField<rtc_t, 15, 1>{}; // bit offset: 15, bit width: 1, Alarm B minutes mask
    constexpr auto HU = BitField<rtc_t, 16, 4>{}; // bit offset: 16, bit width: 4, Hour units in BCD format
    constexpr auto HT = BitField<rtc_t, 20, 2>{}; // bit offset: 20, bit width: 2, Hour tens in BCD format
    constexpr auto PM = BitField<rtc_t, 22, 1>{}; // bit offset: 22, bit width: 1, AM/PM notation
    constexpr auto MSK3 = BitField<rtc_t, 23, 1>{}; // bit offset: 23, bit width: 1, Alarm B hours mask
    constexpr auto DU = BitField<rtc_t, 24, 4>{}; // bit offset: 24, bit width: 4, Date units or day in BCD format
    constexpr auto DT = BitField<rtc_t, 28, 2>{}; // bit offset: 28, bit width: 2, Date tens in BCD format
    constexpr auto WDSEL = BitField<rtc_t, 30, 1>{}; // bit offset: 30, bit width: 1, Week day selection
    constexpr auto MSK4 = BitField<rtc_t, 31, 1>{}; // bit offset: 31, bit width: 1, Alarm B date mask
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000020u, 0, READWRITE, decltype(SU), decltype(ST), decltype(MSK1), decltype(MNU), decltype(MNT), decltype(MSK2), decltype(HU), decltype(HT), decltype(PM), decltype(MSK3), decltype(DU), decltype(DT), decltype(WDSEL), decltype(MSK4)> ALRMBR; // alarm B register

    constexpr auto KEY = BitField<rtc_t, 0, 8>{}; // bit offset: 0, bit width: 8, Write protection key
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000024u, 0, WRITEONLY, decltype(KEY)> WPR; // write protection register

    constexpr auto SU = BitField<rtc_t, 0, 4>{}; // bit offset: 0, bit width: 4, Second units in BCD format
    constexpr auto ST = BitField<rtc_t, 4, 3>{}; // bit offset: 4, bit width: 3, Second tens in BCD format
    constexpr auto MNU = BitField<rtc_t, 8, 4>{}; // bit offset: 8, bit width: 4, Minute units in BCD format
    constexpr auto MNT = BitField<rtc_t, 12, 3>{}; // bit offset: 12, bit width: 3, Minute tens in BCD format
    constexpr auto HU = BitField<rtc_t, 16, 4>{}; // bit offset: 16, bit width: 4, Hour units in BCD format
    constexpr auto HT = BitField<rtc_t, 20, 2>{}; // bit offset: 20, bit width: 2, Hour tens in BCD format
    constexpr auto PM = BitField<rtc_t, 22, 1>{}; // bit offset: 22, bit width: 1, AM/PM notation
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000030u, 0, READONLY, decltype(SU), decltype(ST), decltype(MNU), decltype(MNT), decltype(HU), decltype(HT), decltype(PM)> TSTR; // time stamp time register

    constexpr auto DU = BitField<rtc_t, 0, 4>{}; // bit offset: 0, bit width: 4, Date units in BCD format
    constexpr auto DT = BitField<rtc_t, 4, 2>{}; // bit offset: 4, bit width: 2, Date tens in BCD format
    constexpr auto MU = BitField<rtc_t, 8, 4>{}; // bit offset: 8, bit width: 4, Month units in BCD format
    constexpr auto MT = BitField<rtc_t, 12, 1>{}; // bit offset: 12, bit width: 1, Month tens in BCD format
    constexpr auto WDU = BitField<rtc_t, 13, 3>{}; // bit offset: 13, bit width: 3, Week day units
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000034u, 0, READONLY, decltype(DU), decltype(DT), decltype(MU), decltype(MT), decltype(WDU)> TSDR; // time stamp date register

    constexpr auto TAMP1E = BitField<rtc_t, 0, 1>{}; // bit offset: 0, bit width: 1, Tamper 1 detection enable
    constexpr auto TAMP1TRG = BitField<rtc_t, 1, 1>{}; // bit offset: 1, bit width: 1, Active level for tamper 1
    constexpr auto TAMPIE = BitField<rtc_t, 2, 1>{}; // bit offset: 2, bit width: 1, Tamper interrupt enable
    constexpr auto TAMP1INSEL = BitField<rtc_t, 16, 1>{}; // bit offset: 16, bit width: 1, TAMPER1 mapping
    constexpr auto TSINSEL = BitField<rtc_t, 17, 1>{}; // bit offset: 17, bit width: 1, TIMESTAMP mapping
    constexpr auto ALARMOUTTYPE = BitField<rtc_t, 18, 1>{}; // bit offset: 18, bit width: 1, AFO_ALARM output type
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000040u, 0, READWRITE, decltype(TAMP1E), decltype(TAMP1TRG), decltype(TAMPIE), decltype(TAMP1INSEL), decltype(TSINSEL), decltype(ALARMOUTTYPE)> TAFCR; // tamper and alternate function configuration register

    constexpr auto BKP = BitField<rtc_t, 0, 32>{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000050u, 0, READWRITE, decltype(BKP)> BKP0R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32>{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000054u, 0, READWRITE, decltype(BKP)> BKP1R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32>{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000058u, 0, READWRITE, decltype(BKP)> BKP2R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32>{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x0000005cu, 0, READWRITE, decltype(BKP)> BKP3R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32>{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000060u, 0, READWRITE, decltype(BKP)> BKP4R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32>{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000064u, 0, READWRITE, decltype(BKP)> BKP5R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32>{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000068u, 0, READWRITE, decltype(BKP)> BKP6R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32>{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x0000006cu, 0, READWRITE, decltype(BKP)> BKP7R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32>{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000070u, 0, READWRITE, decltype(BKP)> BKP8R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32>{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000074u, 0, READWRITE, decltype(BKP)> BKP9R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32>{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000078u, 0, READWRITE, decltype(BKP)> BKP10R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32>{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x0000007cu, 0, READWRITE, decltype(BKP)> BKP11R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32>{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000080u, 0, READWRITE, decltype(BKP)> BKP12R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32>{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000084u, 0, READWRITE, decltype(BKP)> BKP13R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32>{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000088u, 0, READWRITE, decltype(BKP)> BKP14R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32>{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x0000008cu, 0, READWRITE, decltype(BKP)> BKP15R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32>{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000090u, 0, READWRITE, decltype(BKP)> BKP16R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32>{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000094u, 0, READWRITE, decltype(BKP)> BKP17R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32>{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000098u, 0, READWRITE, decltype(BKP)> BKP18R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32>{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x0000009cu, 0, READWRITE, decltype(BKP)> BKP19R; // backup register

} // namespace RTC