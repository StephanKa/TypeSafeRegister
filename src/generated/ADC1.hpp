#include <Register.hpp>

namespace ADC1
{
    struct adc1_t{};

    constexpr std::uint32_t ADC1_BASE_ADDRESS = 0x40012000u;

    constexpr auto AWD = BitField<adc1_t, 0, 1, "AWD">{}; // bit offset: 0, bit width: 1, Analog watchdog flag
    constexpr auto EOC = BitField<adc1_t, 1, 1, "EOC">{}; // bit offset: 1, bit width: 1, Regular channel end of conversion
    constexpr auto JEOC = BitField<adc1_t, 2, 1, "JEOC">{}; // bit offset: 2, bit width: 1, Injected channel end of conversion
    constexpr auto JSTRT = BitField<adc1_t, 3, 1, "JSTRT">{}; // bit offset: 3, bit width: 1, Injected channel start flag
    constexpr auto STRT = BitField<adc1_t, 4, 1, "STRT">{}; // bit offset: 4, bit width: 1, Regular channel start flag
    constexpr auto OVR = BitField<adc1_t, 5, 1, "OVR">{}; // bit offset: 5, bit width: 1, Overrun
    static Register<std::uint32_t, ADC1_BASE_ADDRESS + 0x00000000u, 0, READWRITE, "SR", decltype(AWD), decltype(EOC), decltype(JEOC), decltype(JSTRT), decltype(STRT), decltype(OVR)> SR; // status register

    constexpr auto AWDCH = BitField<adc1_t, 0, 5, "AWDCH">{}; // bit offset: 0, bit width: 5, Analog watchdog channel select bits
    constexpr auto EOCIE = BitField<adc1_t, 5, 1, "EOCIE">{}; // bit offset: 5, bit width: 1, Interrupt enable for EOC
    constexpr auto AWDIE = BitField<adc1_t, 6, 1, "AWDIE">{}; // bit offset: 6, bit width: 1, Analog watchdog interrupt enable
    constexpr auto JEOCIE = BitField<adc1_t, 7, 1, "JEOCIE">{}; // bit offset: 7, bit width: 1, Interrupt enable for injected channels
    constexpr auto SCAN = BitField<adc1_t, 8, 1, "SCAN">{}; // bit offset: 8, bit width: 1, Scan mode
    constexpr auto AWDSGL = BitField<adc1_t, 9, 1, "AWDSGL">{}; // bit offset: 9, bit width: 1, Enable the watchdog on a single channel in scan mode
    constexpr auto JAUTO = BitField<adc1_t, 10, 1, "JAUTO">{}; // bit offset: 10, bit width: 1, Automatic injected group conversion
    constexpr auto DISCEN = BitField<adc1_t, 11, 1, "DISCEN">{}; // bit offset: 11, bit width: 1, Discontinuous mode on regular channels
    constexpr auto JDISCEN = BitField<adc1_t, 12, 1, "JDISCEN">{}; // bit offset: 12, bit width: 1, Discontinuous mode on injected channels
    constexpr auto DISCNUM = BitField<adc1_t, 13, 3, "DISCNUM">{}; // bit offset: 13, bit width: 3, Discontinuous mode channel count
    constexpr auto JAWDEN = BitField<adc1_t, 22, 1, "JAWDEN">{}; // bit offset: 22, bit width: 1, Analog watchdog enable on injected channels
    constexpr auto AWDEN = BitField<adc1_t, 23, 1, "AWDEN">{}; // bit offset: 23, bit width: 1, Analog watchdog enable on regular channels
    constexpr auto RES = BitField<adc1_t, 24, 2, "RES">{}; // bit offset: 24, bit width: 2, Resolution
    constexpr auto OVRIE = BitField<adc1_t, 26, 1, "OVRIE">{}; // bit offset: 26, bit width: 1, Overrun interrupt enable
    static Register<std::uint32_t, ADC1_BASE_ADDRESS + 0x00000004u, 0, READWRITE, "CR1", decltype(AWDCH), decltype(EOCIE), decltype(AWDIE), decltype(JEOCIE), decltype(SCAN), decltype(AWDSGL), decltype(JAUTO), decltype(DISCEN), decltype(JDISCEN), decltype(DISCNUM), decltype(JAWDEN), decltype(AWDEN), decltype(RES), decltype(OVRIE)> CR1; // control register 1

    constexpr auto ADON = BitField<adc1_t, 0, 1, "ADON">{}; // bit offset: 0, bit width: 1, A/D Converter ON / OFF
    constexpr auto CONT = BitField<adc1_t, 1, 1, "CONT">{}; // bit offset: 1, bit width: 1, Continuous conversion
    constexpr auto DMA = BitField<adc1_t, 8, 1, "DMA">{}; // bit offset: 8, bit width: 1, Direct memory access mode (for single ADC mode)
    constexpr auto DDS = BitField<adc1_t, 9, 1, "DDS">{}; // bit offset: 9, bit width: 1, DMA disable selection (for single ADC mode)
    constexpr auto EOCS = BitField<adc1_t, 10, 1, "EOCS">{}; // bit offset: 10, bit width: 1, End of conversion selection
    constexpr auto ALIGN = BitField<adc1_t, 11, 1, "ALIGN">{}; // bit offset: 11, bit width: 1, Data alignment
    constexpr auto JEXTSEL = BitField<adc1_t, 16, 4, "JEXTSEL">{}; // bit offset: 16, bit width: 4, External event select for injected group
    constexpr auto JEXTEN = BitField<adc1_t, 20, 2, "JEXTEN">{}; // bit offset: 20, bit width: 2, External trigger enable for injected channels
    constexpr auto JSWSTART = BitField<adc1_t, 22, 1, "JSWSTART">{}; // bit offset: 22, bit width: 1, Start conversion of injected channels
    constexpr auto EXTSEL = BitField<adc1_t, 24, 4, "EXTSEL">{}; // bit offset: 24, bit width: 4, External event select for regular group
    constexpr auto EXTEN = BitField<adc1_t, 28, 2, "EXTEN">{}; // bit offset: 28, bit width: 2, External trigger enable for regular channels
    constexpr auto SWSTART = BitField<adc1_t, 30, 1, "SWSTART">{}; // bit offset: 30, bit width: 1, Start conversion of regular channels
    static Register<std::uint32_t, ADC1_BASE_ADDRESS + 0x00000008u, 0, READWRITE, "CR2", decltype(ADON), decltype(CONT), decltype(DMA), decltype(DDS), decltype(EOCS), decltype(ALIGN), decltype(JEXTSEL), decltype(JEXTEN), decltype(JSWSTART), decltype(EXTSEL), decltype(EXTEN), decltype(SWSTART)> CR2; // control register 2

    constexpr auto SMP10 = BitField<adc1_t, 0, 3, "SMP10">{}; // bit offset: 0, bit width: 3, Channel 10 sampling time selection
    constexpr auto SMP11 = BitField<adc1_t, 3, 3, "SMP11">{}; // bit offset: 3, bit width: 3, Channel 11 sampling time selection
    constexpr auto SMP12 = BitField<adc1_t, 6, 3, "SMP12">{}; // bit offset: 6, bit width: 3, Channel 12 sampling time selection
    constexpr auto SMP13 = BitField<adc1_t, 9, 3, "SMP13">{}; // bit offset: 9, bit width: 3, Channel 13 sampling time selection
    constexpr auto SMP14 = BitField<adc1_t, 12, 3, "SMP14">{}; // bit offset: 12, bit width: 3, Channel 14 sampling time selection
    constexpr auto SMP15 = BitField<adc1_t, 15, 3, "SMP15">{}; // bit offset: 15, bit width: 3, Channel 15 sampling time selection
    constexpr auto SMP16 = BitField<adc1_t, 18, 3, "SMP16">{}; // bit offset: 18, bit width: 3, Channel 16 sampling time selection
    constexpr auto SMP17 = BitField<adc1_t, 21, 3, "SMP17">{}; // bit offset: 21, bit width: 3, Channel 17 sampling time selection
    constexpr auto SMP18 = BitField<adc1_t, 24, 3, "SMP18">{}; // bit offset: 24, bit width: 3, Channel 18 sampling time selection
    static Register<std::uint32_t, ADC1_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, "SMPR1", decltype(SMP10), decltype(SMP11), decltype(SMP12), decltype(SMP13), decltype(SMP14), decltype(SMP15), decltype(SMP16), decltype(SMP17), decltype(SMP18)> SMPR1; // sample time register 1

    constexpr auto SMP0 = BitField<adc1_t, 0, 3, "SMP0">{}; // bit offset: 0, bit width: 3, Channel 0 sampling time selection
    constexpr auto SMP1 = BitField<adc1_t, 3, 3, "SMP1">{}; // bit offset: 3, bit width: 3, Channel 1 sampling time selection
    constexpr auto SMP2 = BitField<adc1_t, 6, 3, "SMP2">{}; // bit offset: 6, bit width: 3, Channel 2 sampling time selection
    constexpr auto SMP3 = BitField<adc1_t, 9, 3, "SMP3">{}; // bit offset: 9, bit width: 3, Channel 3 sampling time selection
    constexpr auto SMP4 = BitField<adc1_t, 12, 3, "SMP4">{}; // bit offset: 12, bit width: 3, Channel 4 sampling time selection
    constexpr auto SMP5 = BitField<adc1_t, 15, 3, "SMP5">{}; // bit offset: 15, bit width: 3, Channel 5 sampling time selection
    constexpr auto SMP6 = BitField<adc1_t, 18, 3, "SMP6">{}; // bit offset: 18, bit width: 3, Channel 6 sampling time selection
    constexpr auto SMP7 = BitField<adc1_t, 21, 3, "SMP7">{}; // bit offset: 21, bit width: 3, Channel 7 sampling time selection
    constexpr auto SMP8 = BitField<adc1_t, 24, 3, "SMP8">{}; // bit offset: 24, bit width: 3, Channel 8 sampling time selection
    constexpr auto SMP9 = BitField<adc1_t, 27, 3, "SMP9">{}; // bit offset: 27, bit width: 3, Channel 9 sampling time selection
    static Register<std::uint32_t, ADC1_BASE_ADDRESS + 0x00000010u, 0, READWRITE, "SMPR2", decltype(SMP0), decltype(SMP1), decltype(SMP2), decltype(SMP3), decltype(SMP4), decltype(SMP5), decltype(SMP6), decltype(SMP7), decltype(SMP8), decltype(SMP9)> SMPR2; // sample time register 2

    constexpr auto JOFFSET1 = BitField<adc1_t, 0, 12, "JOFFSET1">{}; // bit offset: 0, bit width: 12, Data offset for injected channel x
    static Register<std::uint32_t, ADC1_BASE_ADDRESS + 0x00000014u, 0, READWRITE, "JOFR1", decltype(JOFFSET1)> JOFR1; // injected channel data offset register x

    constexpr auto JOFFSET2 = BitField<adc1_t, 0, 12, "JOFFSET2">{}; // bit offset: 0, bit width: 12, Data offset for injected channel x
    static Register<std::uint32_t, ADC1_BASE_ADDRESS + 0x00000018u, 0, READWRITE, "JOFR2", decltype(JOFFSET2)> JOFR2; // injected channel data offset register x

    constexpr auto JOFFSET3 = BitField<adc1_t, 0, 12, "JOFFSET3">{}; // bit offset: 0, bit width: 12, Data offset for injected channel x
    static Register<std::uint32_t, ADC1_BASE_ADDRESS + 0x0000001cu, 0, READWRITE, "JOFR3", decltype(JOFFSET3)> JOFR3; // injected channel data offset register x

    constexpr auto JOFFSET4 = BitField<adc1_t, 0, 12, "JOFFSET4">{}; // bit offset: 0, bit width: 12, Data offset for injected channel x
    static Register<std::uint32_t, ADC1_BASE_ADDRESS + 0x00000020u, 0, READWRITE, "JOFR4", decltype(JOFFSET4)> JOFR4; // injected channel data offset register x

    constexpr auto HT = BitField<adc1_t, 0, 12, "HT">{}; // bit offset: 0, bit width: 12, Analog watchdog higher threshold
    static Register<std::uint32_t, ADC1_BASE_ADDRESS + 0x00000024u, 4095, READWRITE, "HTR", decltype(HT)> HTR; // watchdog higher threshold register

    constexpr auto LT = BitField<adc1_t, 0, 12, "LT">{}; // bit offset: 0, bit width: 12, Analog watchdog lower threshold
    static Register<std::uint32_t, ADC1_BASE_ADDRESS + 0x00000028u, 0, READWRITE, "LTR", decltype(LT)> LTR; // watchdog lower threshold register

    constexpr auto SQ13 = BitField<adc1_t, 0, 5, "SQ13">{}; // bit offset: 0, bit width: 5, 13th conversion in regular sequence
    constexpr auto SQ14 = BitField<adc1_t, 5, 5, "SQ14">{}; // bit offset: 5, bit width: 5, 14th conversion in regular sequence
    constexpr auto SQ15 = BitField<adc1_t, 10, 5, "SQ15">{}; // bit offset: 10, bit width: 5, 15th conversion in regular sequence
    constexpr auto SQ16 = BitField<adc1_t, 15, 5, "SQ16">{}; // bit offset: 15, bit width: 5, 16th conversion in regular sequence
    constexpr auto L = BitField<adc1_t, 20, 4, "L">{}; // bit offset: 20, bit width: 4, Regular channel sequence length
    static Register<std::uint32_t, ADC1_BASE_ADDRESS + 0x0000002cu, 0, READWRITE, "SQR1", decltype(SQ13), decltype(SQ14), decltype(SQ15), decltype(SQ16), decltype(L)> SQR1; // regular sequence register 1

    constexpr auto SQ7 = BitField<adc1_t, 0, 5, "SQ7">{}; // bit offset: 0, bit width: 5, 7th conversion in regular sequence
    constexpr auto SQ8 = BitField<adc1_t, 5, 5, "SQ8">{}; // bit offset: 5, bit width: 5, 8th conversion in regular sequence
    constexpr auto SQ9 = BitField<adc1_t, 10, 5, "SQ9">{}; // bit offset: 10, bit width: 5, 9th conversion in regular sequence
    constexpr auto SQ10 = BitField<adc1_t, 15, 5, "SQ10">{}; // bit offset: 15, bit width: 5, 10th conversion in regular sequence
    constexpr auto SQ11 = BitField<adc1_t, 20, 5, "SQ11">{}; // bit offset: 20, bit width: 5, 11th conversion in regular sequence
    constexpr auto SQ12 = BitField<adc1_t, 25, 5, "SQ12">{}; // bit offset: 25, bit width: 5, 12th conversion in regular sequence
    static Register<std::uint32_t, ADC1_BASE_ADDRESS + 0x00000030u, 0, READWRITE, "SQR2", decltype(SQ7), decltype(SQ8), decltype(SQ9), decltype(SQ10), decltype(SQ11), decltype(SQ12)> SQR2; // regular sequence register 2

    constexpr auto SQ1 = BitField<adc1_t, 0, 5, "SQ1">{}; // bit offset: 0, bit width: 5, 1st conversion in regular sequence
    constexpr auto SQ2 = BitField<adc1_t, 5, 5, "SQ2">{}; // bit offset: 5, bit width: 5, 2nd conversion in regular sequence
    constexpr auto SQ3 = BitField<adc1_t, 10, 5, "SQ3">{}; // bit offset: 10, bit width: 5, 3rd conversion in regular sequence
    constexpr auto SQ4 = BitField<adc1_t, 15, 5, "SQ4">{}; // bit offset: 15, bit width: 5, 4th conversion in regular sequence
    constexpr auto SQ5 = BitField<adc1_t, 20, 5, "SQ5">{}; // bit offset: 20, bit width: 5, 5th conversion in regular sequence
    constexpr auto SQ6 = BitField<adc1_t, 25, 5, "SQ6">{}; // bit offset: 25, bit width: 5, 6th conversion in regular sequence
    static Register<std::uint32_t, ADC1_BASE_ADDRESS + 0x00000034u, 0, READWRITE, "SQR3", decltype(SQ1), decltype(SQ2), decltype(SQ3), decltype(SQ4), decltype(SQ5), decltype(SQ6)> SQR3; // regular sequence register 3

    constexpr auto JSQ1 = BitField<adc1_t, 0, 5, "JSQ1">{}; // bit offset: 0, bit width: 5, 1st conversion in injected sequence
    constexpr auto JSQ2 = BitField<adc1_t, 5, 5, "JSQ2">{}; // bit offset: 5, bit width: 5, 2nd conversion in injected sequence
    constexpr auto JSQ3 = BitField<adc1_t, 10, 5, "JSQ3">{}; // bit offset: 10, bit width: 5, 3rd conversion in injected sequence
    constexpr auto JSQ4 = BitField<adc1_t, 15, 5, "JSQ4">{}; // bit offset: 15, bit width: 5, 4th conversion in injected sequence
    constexpr auto JL = BitField<adc1_t, 20, 2, "JL">{}; // bit offset: 20, bit width: 2, Injected sequence length
    static Register<std::uint32_t, ADC1_BASE_ADDRESS + 0x00000038u, 0, READWRITE, "JSQR", decltype(JSQ1), decltype(JSQ2), decltype(JSQ3), decltype(JSQ4), decltype(JL)> JSQR; // injected sequence register

    constexpr auto JDATA = BitField<adc1_t, 0, 16, "JDATA">{}; // bit offset: 0, bit width: 16, Injected data
    static Register<std::uint32_t, ADC1_BASE_ADDRESS + 0x0000003cu, 0, READONLY, "JDR1", decltype(JDATA)> JDR1; // injected data register x

    constexpr auto JDATA = BitField<adc1_t, 0, 16, "JDATA">{}; // bit offset: 0, bit width: 16, Injected data
    static Register<std::uint32_t, ADC1_BASE_ADDRESS + 0x00000040u, 0, READONLY, "JDR2", decltype(JDATA)> JDR2; // injected data register x

    constexpr auto JDATA = BitField<adc1_t, 0, 16, "JDATA">{}; // bit offset: 0, bit width: 16, Injected data
    static Register<std::uint32_t, ADC1_BASE_ADDRESS + 0x00000044u, 0, READONLY, "JDR3", decltype(JDATA)> JDR3; // injected data register x

    constexpr auto JDATA = BitField<adc1_t, 0, 16, "JDATA">{}; // bit offset: 0, bit width: 16, Injected data
    static Register<std::uint32_t, ADC1_BASE_ADDRESS + 0x00000048u, 0, READONLY, "JDR4", decltype(JDATA)> JDR4; // injected data register x

    constexpr auto DATA = BitField<adc1_t, 0, 16, "DATA">{}; // bit offset: 0, bit width: 16, Regular data
    static Register<std::uint32_t, ADC1_BASE_ADDRESS + 0x0000004cu, 0, READONLY, "DR", decltype(DATA)> DR; // regular data register

} // namespace ADC1