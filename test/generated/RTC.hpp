#include <Register.hpp>

namespace RTC
{
    struct rtc_t{};

    constexpr std::uint32_t RTC_BASE_ADDRESS = 0x40002800u;

    constexpr auto SU = BitField<rtc_t, 0, 4, "SU">{}; // bit offset: 0, bit width: 4, Second units in BCD format
    constexpr auto ST = BitField<rtc_t, 4, 3, "ST">{}; // bit offset: 4, bit width: 3, Second tens in BCD format
    constexpr auto MNU = BitField<rtc_t, 8, 4, "MNU">{}; // bit offset: 8, bit width: 4, Minute units in BCD format
    constexpr auto MNT = BitField<rtc_t, 12, 3, "MNT">{}; // bit offset: 12, bit width: 3, Minute tens in BCD format
    constexpr auto HU = BitField<rtc_t, 16, 4, "HU">{}; // bit offset: 16, bit width: 4, Hour units in BCD format
    constexpr auto HT = BitField<rtc_t, 20, 2, "HT">{}; // bit offset: 20, bit width: 2, Hour tens in BCD format
    constexpr auto PM = BitField<rtc_t, 22, 1, "PM">{}; // bit offset: 22, bit width: 1, AM/PM notation
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000000u, 0, READWRITE, "TR", decltype(SU), decltype(ST), decltype(MNU), decltype(MNT), decltype(HU), decltype(HT), decltype(PM)> TR; // time register

    constexpr auto DU = BitField<rtc_t, 0, 4, "DU">{}; // bit offset: 0, bit width: 4, Date units in BCD format
    constexpr auto DT = BitField<rtc_t, 4, 2, "DT">{}; // bit offset: 4, bit width: 2, Date tens in BCD format
    constexpr auto MU = BitField<rtc_t, 8, 4, "MU">{}; // bit offset: 8, bit width: 4, Month units in BCD format
    constexpr auto MT = BitField<rtc_t, 12, 1, "MT">{}; // bit offset: 12, bit width: 1, Month tens in BCD format
    constexpr auto WDU = BitField<rtc_t, 13, 3, "WDU">{}; // bit offset: 13, bit width: 3, Week day units
    constexpr auto YU = BitField<rtc_t, 16, 4, "YU">{}; // bit offset: 16, bit width: 4, Year units in BCD format
    constexpr auto YT = BitField<rtc_t, 20, 4, "YT">{}; // bit offset: 20, bit width: 4, Year tens in BCD format
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000004u, 8449, READWRITE, "DR", decltype(DU), decltype(DT), decltype(MU), decltype(MT), decltype(WDU), decltype(YU), decltype(YT)> DR; // date register

    constexpr auto WCKSEL = BitField<rtc_t, 0, 3, "WCKSEL">{}; // bit offset: 0, bit width: 3, Wakeup clock selection
    constexpr auto TSEDGE = BitField<rtc_t, 3, 1, "TSEDGE">{}; // bit offset: 3, bit width: 1, Time-stamp event active edge
    constexpr auto REFCKON = BitField<rtc_t, 4, 1, "REFCKON">{}; // bit offset: 4, bit width: 1, Reference clock detection enable (50 or 60 Hz)
    constexpr auto FMT = BitField<rtc_t, 6, 1, "FMT">{}; // bit offset: 6, bit width: 1, Hour format
    constexpr auto DCE = BitField<rtc_t, 7, 1, "DCE">{}; // bit offset: 7, bit width: 1, Coarse digital calibration enable
    constexpr auto ALRAE = BitField<rtc_t, 8, 1, "ALRAE">{}; // bit offset: 8, bit width: 1, Alarm A enable
    constexpr auto ALRBE = BitField<rtc_t, 9, 1, "ALRBE">{}; // bit offset: 9, bit width: 1, Alarm B enable
    constexpr auto WUTE = BitField<rtc_t, 10, 1, "WUTE">{}; // bit offset: 10, bit width: 1, Wakeup timer enable
    constexpr auto TSE = BitField<rtc_t, 11, 1, "TSE">{}; // bit offset: 11, bit width: 1, Time stamp enable
    constexpr auto ALRAIE = BitField<rtc_t, 12, 1, "ALRAIE">{}; // bit offset: 12, bit width: 1, Alarm A interrupt enable
    constexpr auto ALRBIE = BitField<rtc_t, 13, 1, "ALRBIE">{}; // bit offset: 13, bit width: 1, Alarm B interrupt enable
    constexpr auto WUTIE = BitField<rtc_t, 14, 1, "WUTIE">{}; // bit offset: 14, bit width: 1, Wakeup timer interrupt enable
    constexpr auto TSIE = BitField<rtc_t, 15, 1, "TSIE">{}; // bit offset: 15, bit width: 1, Time-stamp interrupt enable
    constexpr auto ADD1H = BitField<rtc_t, 16, 1, "ADD1H">{}; // bit offset: 16, bit width: 1, Add 1 hour (summer time change)
    constexpr auto SUB1H = BitField<rtc_t, 17, 1, "SUB1H">{}; // bit offset: 17, bit width: 1, Subtract 1 hour (winter time change)
    constexpr auto BKP = BitField<rtc_t, 18, 1, "BKP">{}; // bit offset: 18, bit width: 1, Backup
    constexpr auto POL = BitField<rtc_t, 20, 1, "POL">{}; // bit offset: 20, bit width: 1, Output polarity
    constexpr auto OSEL = BitField<rtc_t, 21, 2, "OSEL">{}; // bit offset: 21, bit width: 2, Output selection
    constexpr auto COE = BitField<rtc_t, 23, 1, "COE">{}; // bit offset: 23, bit width: 1, Calibration output enable
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000008u, 0, READWRITE, "CR", decltype(WCKSEL), decltype(TSEDGE), decltype(REFCKON), decltype(FMT), decltype(DCE), decltype(ALRAE), decltype(ALRBE), decltype(WUTE), decltype(TSE), decltype(ALRAIE), decltype(ALRBIE), decltype(WUTIE), decltype(TSIE), decltype(ADD1H), decltype(SUB1H), decltype(BKP), decltype(POL), decltype(OSEL), decltype(COE)> CR; // control register

    constexpr auto ALRAWF = BitField<rtc_t, 0, 1, "ALRAWF", READONLY>{}; // bit offset: 0, bit width: 1, Alarm A write flag
    constexpr auto ALRBWF = BitField<rtc_t, 1, 1, "ALRBWF", READONLY>{}; // bit offset: 1, bit width: 1, Alarm B write flag
    constexpr auto WUTWF = BitField<rtc_t, 2, 1, "WUTWF", READONLY>{}; // bit offset: 2, bit width: 1, Wakeup timer write flag
    constexpr auto INITS = BitField<rtc_t, 4, 1, "INITS", READONLY>{}; // bit offset: 4, bit width: 1, Initialization status flag
    constexpr auto RSF = BitField<rtc_t, 5, 1, "RSF", READWRITE>{}; // bit offset: 5, bit width: 1, Registers synchronization flag
    constexpr auto INITF = BitField<rtc_t, 6, 1, "INITF", READONLY>{}; // bit offset: 6, bit width: 1, Initialization flag
    constexpr auto INIT = BitField<rtc_t, 7, 1, "INIT", READWRITE>{}; // bit offset: 7, bit width: 1, Initialization mode
    constexpr auto ALRAF = BitField<rtc_t, 8, 1, "ALRAF", READWRITE>{}; // bit offset: 8, bit width: 1, Alarm A flag
    constexpr auto ALRBF = BitField<rtc_t, 9, 1, "ALRBF", READWRITE>{}; // bit offset: 9, bit width: 1, Alarm B flag
    constexpr auto WUTF = BitField<rtc_t, 10, 1, "WUTF", READWRITE>{}; // bit offset: 10, bit width: 1, Wakeup timer flag
    constexpr auto TSF = BitField<rtc_t, 11, 1, "TSF", READWRITE>{}; // bit offset: 11, bit width: 1, Time-stamp flag
    constexpr auto TSOVF = BitField<rtc_t, 12, 1, "TSOVF", READWRITE>{}; // bit offset: 12, bit width: 1, Time-stamp overflow flag
    constexpr auto TAMP1F = BitField<rtc_t, 13, 1, "TAMP1F", READWRITE>{}; // bit offset: 13, bit width: 1, Tamper detection flag
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x0000000cu, 7, READWRITE, "ISR", decltype(ALRAWF), decltype(ALRBWF), decltype(WUTWF), decltype(INITS), decltype(RSF), decltype(INITF), decltype(INIT), decltype(ALRAF), decltype(ALRBF), decltype(WUTF), decltype(TSF), decltype(TSOVF), decltype(TAMP1F)> ISR; // initialization and status register

    constexpr auto PREDIV_S = BitField<rtc_t, 0, 13, "PREDIV_S">{}; // bit offset: 0, bit width: 13, Synchronous prescaler factor
    constexpr auto PREDIV_A = BitField<rtc_t, 16, 7, "PREDIV_A">{}; // bit offset: 16, bit width: 7, Asynchronous prescaler factor
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000010u, 8323327, READWRITE, "PRER", decltype(PREDIV_S), decltype(PREDIV_A)> PRER; // prescaler register

    constexpr auto WUT = BitField<rtc_t, 0, 16, "WUT">{}; // bit offset: 0, bit width: 16, Wakeup auto-reload value bits
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000014u, 65535, READWRITE, "WUTR", decltype(WUT)> WUTR; // wakeup timer register

    constexpr auto DC = BitField<rtc_t, 0, 5, "DC">{}; // bit offset: 0, bit width: 5, Digital calibration
    constexpr auto DCS = BitField<rtc_t, 7, 1, "DCS">{}; // bit offset: 7, bit width: 1, Digital calibration sign
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000018u, 0, READWRITE, "CALIBR", decltype(DC), decltype(DCS)> CALIBR; // calibration register

    constexpr auto SU = BitField<rtc_t, 0, 4, "SU">{}; // bit offset: 0, bit width: 4, Second units in BCD format
    constexpr auto ST = BitField<rtc_t, 4, 3, "ST">{}; // bit offset: 4, bit width: 3, Second tens in BCD format
    constexpr auto MSK1 = BitField<rtc_t, 7, 1, "MSK1">{}; // bit offset: 7, bit width: 1, Alarm A seconds mask
    constexpr auto MNU = BitField<rtc_t, 8, 4, "MNU">{}; // bit offset: 8, bit width: 4, Minute units in BCD format
    constexpr auto MNT = BitField<rtc_t, 12, 3, "MNT">{}; // bit offset: 12, bit width: 3, Minute tens in BCD format
    constexpr auto MSK2 = BitField<rtc_t, 15, 1, "MSK2">{}; // bit offset: 15, bit width: 1, Alarm A minutes mask
    constexpr auto HU = BitField<rtc_t, 16, 4, "HU">{}; // bit offset: 16, bit width: 4, Hour units in BCD format
    constexpr auto HT = BitField<rtc_t, 20, 2, "HT">{}; // bit offset: 20, bit width: 2, Hour tens in BCD format
    constexpr auto PM = BitField<rtc_t, 22, 1, "PM">{}; // bit offset: 22, bit width: 1, AM/PM notation
    constexpr auto MSK3 = BitField<rtc_t, 23, 1, "MSK3">{}; // bit offset: 23, bit width: 1, Alarm A hours mask
    constexpr auto DU = BitField<rtc_t, 24, 4, "DU">{}; // bit offset: 24, bit width: 4, Date units or day in BCD format
    constexpr auto DT = BitField<rtc_t, 28, 2, "DT">{}; // bit offset: 28, bit width: 2, Date tens in BCD format
    constexpr auto WDSEL = BitField<rtc_t, 30, 1, "WDSEL">{}; // bit offset: 30, bit width: 1, Week day selection
    constexpr auto MSK4 = BitField<rtc_t, 31, 1, "MSK4">{}; // bit offset: 31, bit width: 1, Alarm A date mask
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x0000001cu, 0, READWRITE, "ALRMAR", decltype(SU), decltype(ST), decltype(MSK1), decltype(MNU), decltype(MNT), decltype(MSK2), decltype(HU), decltype(HT), decltype(PM), decltype(MSK3), decltype(DU), decltype(DT), decltype(WDSEL), decltype(MSK4)> ALRMAR; // alarm A register

    constexpr auto SU = BitField<rtc_t, 0, 4, "SU">{}; // bit offset: 0, bit width: 4, Second units in BCD format
    constexpr auto ST = BitField<rtc_t, 4, 3, "ST">{}; // bit offset: 4, bit width: 3, Second tens in BCD format
    constexpr auto MSK1 = BitField<rtc_t, 7, 1, "MSK1">{}; // bit offset: 7, bit width: 1, Alarm B seconds mask
    constexpr auto MNU = BitField<rtc_t, 8, 4, "MNU">{}; // bit offset: 8, bit width: 4, Minute units in BCD format
    constexpr auto MNT = BitField<rtc_t, 12, 3, "MNT">{}; // bit offset: 12, bit width: 3, Minute tens in BCD format
    constexpr auto MSK2 = BitField<rtc_t, 15, 1, "MSK2">{}; // bit offset: 15, bit width: 1, Alarm B minutes mask
    constexpr auto HU = BitField<rtc_t, 16, 4, "HU">{}; // bit offset: 16, bit width: 4, Hour units in BCD format
    constexpr auto HT = BitField<rtc_t, 20, 2, "HT">{}; // bit offset: 20, bit width: 2, Hour tens in BCD format
    constexpr auto PM = BitField<rtc_t, 22, 1, "PM">{}; // bit offset: 22, bit width: 1, AM/PM notation
    constexpr auto MSK3 = BitField<rtc_t, 23, 1, "MSK3">{}; // bit offset: 23, bit width: 1, Alarm B hours mask
    constexpr auto DU = BitField<rtc_t, 24, 4, "DU">{}; // bit offset: 24, bit width: 4, Date units or day in BCD format
    constexpr auto DT = BitField<rtc_t, 28, 2, "DT">{}; // bit offset: 28, bit width: 2, Date tens in BCD format
    constexpr auto WDSEL = BitField<rtc_t, 30, 1, "WDSEL">{}; // bit offset: 30, bit width: 1, Week day selection
    constexpr auto MSK4 = BitField<rtc_t, 31, 1, "MSK4">{}; // bit offset: 31, bit width: 1, Alarm B date mask
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000020u, 0, READWRITE, "ALRMBR", decltype(SU), decltype(ST), decltype(MSK1), decltype(MNU), decltype(MNT), decltype(MSK2), decltype(HU), decltype(HT), decltype(PM), decltype(MSK3), decltype(DU), decltype(DT), decltype(WDSEL), decltype(MSK4)> ALRMBR; // alarm B register

    constexpr auto KEY = BitField<rtc_t, 0, 8, "KEY">{}; // bit offset: 0, bit width: 8, Write protection key
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000024u, 0, WRITEONLY, "WPR", decltype(KEY)> WPR; // write protection register

    constexpr auto SU = BitField<rtc_t, 0, 4, "SU">{}; // bit offset: 0, bit width: 4, Second units in BCD format
    constexpr auto ST = BitField<rtc_t, 4, 3, "ST">{}; // bit offset: 4, bit width: 3, Second tens in BCD format
    constexpr auto MNU = BitField<rtc_t, 8, 4, "MNU">{}; // bit offset: 8, bit width: 4, Minute units in BCD format
    constexpr auto MNT = BitField<rtc_t, 12, 3, "MNT">{}; // bit offset: 12, bit width: 3, Minute tens in BCD format
    constexpr auto HU = BitField<rtc_t, 16, 4, "HU">{}; // bit offset: 16, bit width: 4, Hour units in BCD format
    constexpr auto HT = BitField<rtc_t, 20, 2, "HT">{}; // bit offset: 20, bit width: 2, Hour tens in BCD format
    constexpr auto PM = BitField<rtc_t, 22, 1, "PM">{}; // bit offset: 22, bit width: 1, AM/PM notation
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000030u, 0, READONLY, "TSTR", decltype(SU), decltype(ST), decltype(MNU), decltype(MNT), decltype(HU), decltype(HT), decltype(PM)> TSTR; // time stamp time register

    constexpr auto DU = BitField<rtc_t, 0, 4, "DU">{}; // bit offset: 0, bit width: 4, Date units in BCD format
    constexpr auto DT = BitField<rtc_t, 4, 2, "DT">{}; // bit offset: 4, bit width: 2, Date tens in BCD format
    constexpr auto MU = BitField<rtc_t, 8, 4, "MU">{}; // bit offset: 8, bit width: 4, Month units in BCD format
    constexpr auto MT = BitField<rtc_t, 12, 1, "MT">{}; // bit offset: 12, bit width: 1, Month tens in BCD format
    constexpr auto WDU = BitField<rtc_t, 13, 3, "WDU">{}; // bit offset: 13, bit width: 3, Week day units
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000034u, 0, READONLY, "TSDR", decltype(DU), decltype(DT), decltype(MU), decltype(MT), decltype(WDU)> TSDR; // time stamp date register

    constexpr auto TAMP1E = BitField<rtc_t, 0, 1, "TAMP1E">{}; // bit offset: 0, bit width: 1, Tamper 1 detection enable
    constexpr auto TAMP1TRG = BitField<rtc_t, 1, 1, "TAMP1TRG">{}; // bit offset: 1, bit width: 1, Active level for tamper 1
    constexpr auto TAMPIE = BitField<rtc_t, 2, 1, "TAMPIE">{}; // bit offset: 2, bit width: 1, Tamper interrupt enable
    constexpr auto TAMP1INSEL = BitField<rtc_t, 16, 1, "TAMP1INSEL">{}; // bit offset: 16, bit width: 1, TAMPER1 mapping
    constexpr auto TSINSEL = BitField<rtc_t, 17, 1, "TSINSEL">{}; // bit offset: 17, bit width: 1, TIMESTAMP mapping
    constexpr auto ALARMOUTTYPE = BitField<rtc_t, 18, 1, "ALARMOUTTYPE">{}; // bit offset: 18, bit width: 1, AFO_ALARM output type
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000040u, 0, READWRITE, "TAFCR", decltype(TAMP1E), decltype(TAMP1TRG), decltype(TAMPIE), decltype(TAMP1INSEL), decltype(TSINSEL), decltype(ALARMOUTTYPE)> TAFCR; // tamper and alternate function configuration register

    constexpr auto BKP = BitField<rtc_t, 0, 32, "BKP">{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000050u, 0, READWRITE, "BKP0R", decltype(BKP)> BKP0R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32, "BKP">{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000054u, 0, READWRITE, "BKP1R", decltype(BKP)> BKP1R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32, "BKP">{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000058u, 0, READWRITE, "BKP2R", decltype(BKP)> BKP2R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32, "BKP">{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x0000005cu, 0, READWRITE, "BKP3R", decltype(BKP)> BKP3R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32, "BKP">{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000060u, 0, READWRITE, "BKP4R", decltype(BKP)> BKP4R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32, "BKP">{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000064u, 0, READWRITE, "BKP5R", decltype(BKP)> BKP5R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32, "BKP">{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000068u, 0, READWRITE, "BKP6R", decltype(BKP)> BKP6R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32, "BKP">{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x0000006cu, 0, READWRITE, "BKP7R", decltype(BKP)> BKP7R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32, "BKP">{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000070u, 0, READWRITE, "BKP8R", decltype(BKP)> BKP8R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32, "BKP">{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000074u, 0, READWRITE, "BKP9R", decltype(BKP)> BKP9R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32, "BKP">{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000078u, 0, READWRITE, "BKP10R", decltype(BKP)> BKP10R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32, "BKP">{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x0000007cu, 0, READWRITE, "BKP11R", decltype(BKP)> BKP11R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32, "BKP">{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000080u, 0, READWRITE, "BKP12R", decltype(BKP)> BKP12R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32, "BKP">{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000084u, 0, READWRITE, "BKP13R", decltype(BKP)> BKP13R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32, "BKP">{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000088u, 0, READWRITE, "BKP14R", decltype(BKP)> BKP14R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32, "BKP">{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x0000008cu, 0, READWRITE, "BKP15R", decltype(BKP)> BKP15R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32, "BKP">{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000090u, 0, READWRITE, "BKP16R", decltype(BKP)> BKP16R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32, "BKP">{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000094u, 0, READWRITE, "BKP17R", decltype(BKP)> BKP17R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32, "BKP">{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x00000098u, 0, READWRITE, "BKP18R", decltype(BKP)> BKP18R; // backup register

    constexpr auto BKP = BitField<rtc_t, 0, 32, "BKP">{}; // bit offset: 0, bit width: 32, BKP
    static Register<std::uint32_t, RTC_BASE_ADDRESS + 0x0000009cu, 0, READWRITE, "BKP19R", decltype(BKP)> BKP19R; // backup register

} // namespace RTC