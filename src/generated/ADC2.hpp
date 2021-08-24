#include <Register.hpp>




namespace ADC2
{
    struct adc2_t{};

    constexpr std::uint32_t ADC2_BASE_ADDRESS = 0x40012100u;

    constexpr auto AWD = BitField<adc2_t, 0, 1>{}; // bit offset: 0, bit width: 1, Analog watchdog flag
    constexpr auto EOC = BitField<adc2_t, 1, 1>{}; // bit offset: 1, bit width: 1, Regular channel end of conversion
    constexpr auto JEOC = BitField<adc2_t, 2, 1>{}; // bit offset: 2, bit width: 1, Injected channel end of conversion
    constexpr auto JSTRT = BitField<adc2_t, 3, 1>{}; // bit offset: 3, bit width: 1, Injected channel start flag
    constexpr auto STRT = BitField<adc2_t, 4, 1>{}; // bit offset: 4, bit width: 1, Regular channel start flag
    constexpr auto OVR = BitField<adc2_t, 5, 1>{}; // bit offset: 5, bit width: 1, Overrun
    static Register<std::uint32_t, ADC2_BASE_ADDRESS + 0x00000000u, 0, READWRITE, decltype(AWD), decltype(EOC), decltype(JEOC), decltype(JSTRT), decltype(STRT), decltype(OVR)> SR; // status register

    constexpr auto AWDCH = BitField<adc2_t, 0, 5>{}; // bit offset: 0, bit width: 5, Analog watchdog channel select bits
    constexpr auto EOCIE = BitField<adc2_t, 5, 1>{}; // bit offset: 5, bit width: 1, Interrupt enable for EOC
    constexpr auto AWDIE = BitField<adc2_t, 6, 1>{}; // bit offset: 6, bit width: 1, Analog watchdog interrupt enable
    constexpr auto JEOCIE = BitField<adc2_t, 7, 1>{}; // bit offset: 7, bit width: 1, Interrupt enable for injected channels
    constexpr auto SCAN = BitField<adc2_t, 8, 1>{}; // bit offset: 8, bit width: 1, Scan mode
    constexpr auto AWDSGL = BitField<adc2_t, 9, 1>{}; // bit offset: 9, bit width: 1, Enable the watchdog on a single channel in scan mode
    constexpr auto JAUTO = BitField<adc2_t, 10, 1>{}; // bit offset: 10, bit width: 1, Automatic injected group conversion
    constexpr auto DISCEN = BitField<adc2_t, 11, 1>{}; // bit offset: 11, bit width: 1, Discontinuous mode on regular channels
    constexpr auto JDISCEN = BitField<adc2_t, 12, 1>{}; // bit offset: 12, bit width: 1, Discontinuous mode on injected channels
    constexpr auto DISCNUM = BitField<adc2_t, 13, 3>{}; // bit offset: 13, bit width: 3, Discontinuous mode channel count
    constexpr auto JAWDEN = BitField<adc2_t, 22, 1>{}; // bit offset: 22, bit width: 1, Analog watchdog enable on injected channels
    constexpr auto AWDEN = BitField<adc2_t, 23, 1>{}; // bit offset: 23, bit width: 1, Analog watchdog enable on regular channels
    constexpr auto RES = BitField<adc2_t, 24, 2>{}; // bit offset: 24, bit width: 2, Resolution
    constexpr auto OVRIE = BitField<adc2_t, 26, 1>{}; // bit offset: 26, bit width: 1, Overrun interrupt enable
    static Register<std::uint32_t, ADC2_BASE_ADDRESS + 0x00000004u, 0, READWRITE, decltype(AWDCH), decltype(EOCIE), decltype(AWDIE), decltype(JEOCIE), decltype(SCAN), decltype(AWDSGL), decltype(JAUTO), decltype(DISCEN), decltype(JDISCEN), decltype(DISCNUM), decltype(JAWDEN), decltype(AWDEN), decltype(RES), decltype(OVRIE)> CR1; // control register 1

    constexpr auto ADON = BitField<adc2_t, 0, 1>{}; // bit offset: 0, bit width: 1, A/D Converter ON / OFF
    constexpr auto CONT = BitField<adc2_t, 1, 1>{}; // bit offset: 1, bit width: 1, Continuous conversion
    constexpr auto DMA = BitField<adc2_t, 8, 1>{}; // bit offset: 8, bit width: 1, Direct memory access mode (for single ADC mode)
    constexpr auto DDS = BitField<adc2_t, 9, 1>{}; // bit offset: 9, bit width: 1, DMA disable selection (for single ADC mode)
    constexpr auto EOCS = BitField<adc2_t, 10, 1>{}; // bit offset: 10, bit width: 1, End of conversion selection
    constexpr auto ALIGN = BitField<adc2_t, 11, 1>{}; // bit offset: 11, bit width: 1, Data alignment
    constexpr auto JEXTSEL = BitField<adc2_t, 16, 4>{}; // bit offset: 16, bit width: 4, External event select for injected group
    constexpr auto JEXTEN = BitField<adc2_t, 20, 2>{}; // bit offset: 20, bit width: 2, External trigger enable for injected channels
    constexpr auto JSWSTART = BitField<adc2_t, 22, 1>{}; // bit offset: 22, bit width: 1, Start conversion of injected channels
    constexpr auto EXTSEL = BitField<adc2_t, 24, 4>{}; // bit offset: 24, bit width: 4, External event select for regular group
    constexpr auto EXTEN = BitField<adc2_t, 28, 2>{}; // bit offset: 28, bit width: 2, External trigger enable for regular channels
    constexpr auto SWSTART = BitField<adc2_t, 30, 1>{}; // bit offset: 30, bit width: 1, Start conversion of regular channels
    static Register<std::uint32_t, ADC2_BASE_ADDRESS + 0x00000008u, 0, READWRITE, decltype(ADON), decltype(CONT), decltype(DMA), decltype(DDS), decltype(EOCS), decltype(ALIGN), decltype(JEXTSEL), decltype(JEXTEN), decltype(JSWSTART), decltype(EXTSEL), decltype(EXTEN), decltype(SWSTART)> CR2; // control register 2

    constexpr auto SMP10 = BitField<adc2_t, 0, 3>{}; // bit offset: 0, bit width: 3, Channel 10 sampling time selection
    constexpr auto SMP11 = BitField<adc2_t, 3, 3>{}; // bit offset: 3, bit width: 3, Channel 11 sampling time selection
    constexpr auto SMP12 = BitField<adc2_t, 6, 3>{}; // bit offset: 6, bit width: 3, Channel 12 sampling time selection
    constexpr auto SMP13 = BitField<adc2_t, 9, 3>{}; // bit offset: 9, bit width: 3, Channel 13 sampling time selection
    constexpr auto SMP14 = BitField<adc2_t, 12, 3>{}; // bit offset: 12, bit width: 3, Channel 14 sampling time selection
    constexpr auto SMP15 = BitField<adc2_t, 15, 3>{}; // bit offset: 15, bit width: 3, Channel 15 sampling time selection
    constexpr auto SMP16 = BitField<adc2_t, 18, 3>{}; // bit offset: 18, bit width: 3, Channel 16 sampling time selection
    constexpr auto SMP17 = BitField<adc2_t, 21, 3>{}; // bit offset: 21, bit width: 3, Channel 17 sampling time selection
    constexpr auto SMP18 = BitField<adc2_t, 24, 3>{}; // bit offset: 24, bit width: 3, Channel 18 sampling time selection
    static Register<std::uint32_t, ADC2_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, decltype(SMP10), decltype(SMP11), decltype(SMP12), decltype(SMP13), decltype(SMP14), decltype(SMP15), decltype(SMP16), decltype(SMP17), decltype(SMP18)> SMPR1; // sample time register 1

    constexpr auto SMP0 = BitField<adc2_t, 0, 3>{}; // bit offset: 0, bit width: 3, Channel 0 sampling time selection
    constexpr auto SMP1 = BitField<adc2_t, 3, 3>{}; // bit offset: 3, bit width: 3, Channel 1 sampling time selection
    constexpr auto SMP2 = BitField<adc2_t, 6, 3>{}; // bit offset: 6, bit width: 3, Channel 2 sampling time selection
    constexpr auto SMP3 = BitField<adc2_t, 9, 3>{}; // bit offset: 9, bit width: 3, Channel 3 sampling time selection
    constexpr auto SMP4 = BitField<adc2_t, 12, 3>{}; // bit offset: 12, bit width: 3, Channel 4 sampling time selection
    constexpr auto SMP5 = BitField<adc2_t, 15, 3>{}; // bit offset: 15, bit width: 3, Channel 5 sampling time selection
    constexpr auto SMP6 = BitField<adc2_t, 18, 3>{}; // bit offset: 18, bit width: 3, Channel 6 sampling time selection
    constexpr auto SMP7 = BitField<adc2_t, 21, 3>{}; // bit offset: 21, bit width: 3, Channel 7 sampling time selection
    constexpr auto SMP8 = BitField<adc2_t, 24, 3>{}; // bit offset: 24, bit width: 3, Channel 8 sampling time selection
    constexpr auto SMP9 = BitField<adc2_t, 27, 3>{}; // bit offset: 27, bit width: 3, Channel 9 sampling time selection
    static Register<std::uint32_t, ADC2_BASE_ADDRESS + 0x00000010u, 0, READWRITE, decltype(SMP0), decltype(SMP1), decltype(SMP2), decltype(SMP3), decltype(SMP4), decltype(SMP5), decltype(SMP6), decltype(SMP7), decltype(SMP8), decltype(SMP9)> SMPR2; // sample time register 2

    constexpr auto JOFFSET1 = BitField<adc2_t, 0, 12>{}; // bit offset: 0, bit width: 12, Data offset for injected channel x
    static Register<std::uint32_t, ADC2_BASE_ADDRESS + 0x00000014u, 0, READWRITE, decltype(JOFFSET1)> JOFR1; // injected channel data offset register x

    constexpr auto JOFFSET2 = BitField<adc2_t, 0, 12>{}; // bit offset: 0, bit width: 12, Data offset for injected channel x
    static Register<std::uint32_t, ADC2_BASE_ADDRESS + 0x00000018u, 0, READWRITE, decltype(JOFFSET2)> JOFR2; // injected channel data offset register x

    constexpr auto JOFFSET3 = BitField<adc2_t, 0, 12>{}; // bit offset: 0, bit width: 12, Data offset for injected channel x
    static Register<std::uint32_t, ADC2_BASE_ADDRESS + 0x0000001cu, 0, READWRITE, decltype(JOFFSET3)> JOFR3; // injected channel data offset register x

    constexpr auto JOFFSET4 = BitField<adc2_t, 0, 12>{}; // bit offset: 0, bit width: 12, Data offset for injected channel x
    static Register<std::uint32_t, ADC2_BASE_ADDRESS + 0x00000020u, 0, READWRITE, decltype(JOFFSET4)> JOFR4; // injected channel data offset register x

    constexpr auto HT = BitField<adc2_t, 0, 12>{}; // bit offset: 0, bit width: 12, Analog watchdog higher threshold
    static Register<std::uint32_t, ADC2_BASE_ADDRESS + 0x00000024u, 4095, READWRITE, decltype(HT)> HTR; // watchdog higher threshold register

    constexpr auto LT = BitField<adc2_t, 0, 12>{}; // bit offset: 0, bit width: 12, Analog watchdog lower threshold
    static Register<std::uint32_t, ADC2_BASE_ADDRESS + 0x00000028u, 0, READWRITE, decltype(LT)> LTR; // watchdog lower threshold register

    constexpr auto SQ13 = BitField<adc2_t, 0, 5>{}; // bit offset: 0, bit width: 5, 13th conversion in regular sequence
    constexpr auto SQ14 = BitField<adc2_t, 5, 5>{}; // bit offset: 5, bit width: 5, 14th conversion in regular sequence
    constexpr auto SQ15 = BitField<adc2_t, 10, 5>{}; // bit offset: 10, bit width: 5, 15th conversion in regular sequence
    constexpr auto SQ16 = BitField<adc2_t, 15, 5>{}; // bit offset: 15, bit width: 5, 16th conversion in regular sequence
    constexpr auto L = BitField<adc2_t, 20, 4>{}; // bit offset: 20, bit width: 4, Regular channel sequence length
    static Register<std::uint32_t, ADC2_BASE_ADDRESS + 0x0000002cu, 0, READWRITE, decltype(SQ13), decltype(SQ14), decltype(SQ15), decltype(SQ16), decltype(L)> SQR1; // regular sequence register 1

    constexpr auto SQ7 = BitField<adc2_t, 0, 5>{}; // bit offset: 0, bit width: 5, 7th conversion in regular sequence
    constexpr auto SQ8 = BitField<adc2_t, 5, 5>{}; // bit offset: 5, bit width: 5, 8th conversion in regular sequence
    constexpr auto SQ9 = BitField<adc2_t, 10, 5>{}; // bit offset: 10, bit width: 5, 9th conversion in regular sequence
    constexpr auto SQ10 = BitField<adc2_t, 15, 5>{}; // bit offset: 15, bit width: 5, 10th conversion in regular sequence
    constexpr auto SQ11 = BitField<adc2_t, 20, 5>{}; // bit offset: 20, bit width: 5, 11th conversion in regular sequence
    constexpr auto SQ12 = BitField<adc2_t, 25, 5>{}; // bit offset: 25, bit width: 5, 12th conversion in regular sequence
    static Register<std::uint32_t, ADC2_BASE_ADDRESS + 0x00000030u, 0, READWRITE, decltype(SQ7), decltype(SQ8), decltype(SQ9), decltype(SQ10), decltype(SQ11), decltype(SQ12)> SQR2; // regular sequence register 2

    constexpr auto SQ1 = BitField<adc2_t, 0, 5>{}; // bit offset: 0, bit width: 5, 1st conversion in regular sequence
    constexpr auto SQ2 = BitField<adc2_t, 5, 5>{}; // bit offset: 5, bit width: 5, 2nd conversion in regular sequence
    constexpr auto SQ3 = BitField<adc2_t, 10, 5>{}; // bit offset: 10, bit width: 5, 3rd conversion in regular sequence
    constexpr auto SQ4 = BitField<adc2_t, 15, 5>{}; // bit offset: 15, bit width: 5, 4th conversion in regular sequence
    constexpr auto SQ5 = BitField<adc2_t, 20, 5>{}; // bit offset: 20, bit width: 5, 5th conversion in regular sequence
    constexpr auto SQ6 = BitField<adc2_t, 25, 5>{}; // bit offset: 25, bit width: 5, 6th conversion in regular sequence
    static Register<std::uint32_t, ADC2_BASE_ADDRESS + 0x00000034u, 0, READWRITE, decltype(SQ1), decltype(SQ2), decltype(SQ3), decltype(SQ4), decltype(SQ5), decltype(SQ6)> SQR3; // regular sequence register 3

    constexpr auto JSQ1 = BitField<adc2_t, 0, 5>{}; // bit offset: 0, bit width: 5, 1st conversion in injected sequence
    constexpr auto JSQ2 = BitField<adc2_t, 5, 5>{}; // bit offset: 5, bit width: 5, 2nd conversion in injected sequence
    constexpr auto JSQ3 = BitField<adc2_t, 10, 5>{}; // bit offset: 10, bit width: 5, 3rd conversion in injected sequence
    constexpr auto JSQ4 = BitField<adc2_t, 15, 5>{}; // bit offset: 15, bit width: 5, 4th conversion in injected sequence
    constexpr auto JL = BitField<adc2_t, 20, 2>{}; // bit offset: 20, bit width: 2, Injected sequence length
    static Register<std::uint32_t, ADC2_BASE_ADDRESS + 0x00000038u, 0, READWRITE, decltype(JSQ1), decltype(JSQ2), decltype(JSQ3), decltype(JSQ4), decltype(JL)> JSQR; // injected sequence register

    constexpr auto JDATA = BitField<adc2_t, 0, 16>{}; // bit offset: 0, bit width: 16, Injected data
    static Register<std::uint32_t, ADC2_BASE_ADDRESS + 0x0000003cu, 0, READONLY, decltype(JDATA)> JDR1; // injected data register x

    constexpr auto JDATA = BitField<adc2_t, 0, 16>{}; // bit offset: 0, bit width: 16, Injected data
    static Register<std::uint32_t, ADC2_BASE_ADDRESS + 0x00000040u, 0, READONLY, decltype(JDATA)> JDR2; // injected data register x

    constexpr auto JDATA = BitField<adc2_t, 0, 16>{}; // bit offset: 0, bit width: 16, Injected data
    static Register<std::uint32_t, ADC2_BASE_ADDRESS + 0x00000044u, 0, READONLY, decltype(JDATA)> JDR3; // injected data register x

    constexpr auto JDATA = BitField<adc2_t, 0, 16>{}; // bit offset: 0, bit width: 16, Injected data
    static Register<std::uint32_t, ADC2_BASE_ADDRESS + 0x00000048u, 0, READONLY, decltype(JDATA)> JDR4; // injected data register x

    constexpr auto DATA = BitField<adc2_t, 0, 16>{}; // bit offset: 0, bit width: 16, Regular data
    static Register<std::uint32_t, ADC2_BASE_ADDRESS + 0x0000004cu, 0, READONLY, decltype(DATA)> DR; // regular data register

} // namespace ADC2