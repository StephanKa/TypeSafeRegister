#include <Register.hpp>

namespace ADC_COMMON
{
    struct adc_common_t{};

    constexpr std::uint32_t ADC_COMMON_BASE_ADDRESS = 0x40012300u;

    constexpr auto AWD1 = BitField<adc_common_t, 0, 1, "AWD1">{}; // bit offset: 0, bit width: 1, Analog watchdog flag of ADC 1
    constexpr auto EOC1 = BitField<adc_common_t, 1, 1, "EOC1">{}; // bit offset: 1, bit width: 1, End of conversion of ADC 1
    constexpr auto JEOC1 = BitField<adc_common_t, 2, 1, "JEOC1">{}; // bit offset: 2, bit width: 1, Injected channel end of conversion of ADC 1
    constexpr auto JSTRT1 = BitField<adc_common_t, 3, 1, "JSTRT1">{}; // bit offset: 3, bit width: 1, Injected channel Start flag of ADC 1
    constexpr auto STRT1 = BitField<adc_common_t, 4, 1, "STRT1">{}; // bit offset: 4, bit width: 1, Regular channel Start flag of ADC 1
    constexpr auto OVR1 = BitField<adc_common_t, 5, 1, "OVR1">{}; // bit offset: 5, bit width: 1, Overrun flag of ADC 1
    constexpr auto AWD2 = BitField<adc_common_t, 8, 1, "AWD2">{}; // bit offset: 8, bit width: 1, Analog watchdog flag of ADC 2
    constexpr auto EOC2 = BitField<adc_common_t, 9, 1, "EOC2">{}; // bit offset: 9, bit width: 1, End of conversion of ADC 2
    constexpr auto JEOC2 = BitField<adc_common_t, 10, 1, "JEOC2">{}; // bit offset: 10, bit width: 1, Injected channel end of conversion of ADC 2
    constexpr auto JSTRT2 = BitField<adc_common_t, 11, 1, "JSTRT2">{}; // bit offset: 11, bit width: 1, Injected channel Start flag of ADC 2
    constexpr auto STRT2 = BitField<adc_common_t, 12, 1, "STRT2">{}; // bit offset: 12, bit width: 1, Regular channel Start flag of ADC 2
    constexpr auto OVR2 = BitField<adc_common_t, 13, 1, "OVR2">{}; // bit offset: 13, bit width: 1, Overrun flag of ADC 2
    constexpr auto AWD3 = BitField<adc_common_t, 16, 1, "AWD3">{}; // bit offset: 16, bit width: 1, Analog watchdog flag of ADC 3
    constexpr auto EOC3 = BitField<adc_common_t, 17, 1, "EOC3">{}; // bit offset: 17, bit width: 1, End of conversion of ADC 3
    constexpr auto JEOC3 = BitField<adc_common_t, 18, 1, "JEOC3">{}; // bit offset: 18, bit width: 1, Injected channel end of conversion of ADC 3
    constexpr auto JSTRT3 = BitField<adc_common_t, 19, 1, "JSTRT3">{}; // bit offset: 19, bit width: 1, Injected channel Start flag of ADC 3
    constexpr auto STRT3 = BitField<adc_common_t, 20, 1, "STRT3">{}; // bit offset: 20, bit width: 1, Regular channel Start flag of ADC 3
    constexpr auto OVR3 = BitField<adc_common_t, 21, 1, "OVR3">{}; // bit offset: 21, bit width: 1, Overrun flag of ADC3
    static Register<std::uint32_t, ADC_COMMON_BASE_ADDRESS + 0x00000000u, 0, READONLY, "CSR", decltype(AWD1), decltype(EOC1), decltype(JEOC1), decltype(JSTRT1), decltype(STRT1), decltype(OVR1), decltype(AWD2), decltype(EOC2), decltype(JEOC2), decltype(JSTRT2), decltype(STRT2), decltype(OVR2), decltype(AWD3), decltype(EOC3), decltype(JEOC3), decltype(JSTRT3), decltype(STRT3), decltype(OVR3)> CSR; // ADC Common status register

    constexpr auto MULT = BitField<adc_common_t, 0, 5, "MULT">{}; // bit offset: 0, bit width: 5, Multi ADC mode selection
    constexpr auto DELAY = BitField<adc_common_t, 8, 4, "DELAY">{}; // bit offset: 8, bit width: 4, Delay between 2 sampling phases
    constexpr auto DDS = BitField<adc_common_t, 13, 1, "DDS">{}; // bit offset: 13, bit width: 1, DMA disable selection for multi-ADC mode
    constexpr auto DMA = BitField<adc_common_t, 14, 2, "DMA">{}; // bit offset: 14, bit width: 2, Direct memory access mode for multi ADC mode
    constexpr auto ADCPRE = BitField<adc_common_t, 16, 2, "ADCPRE">{}; // bit offset: 16, bit width: 2, ADC prescaler
    constexpr auto VBATE = BitField<adc_common_t, 22, 1, "VBATE">{}; // bit offset: 22, bit width: 1, VBAT enable
    constexpr auto TSVREFE = BitField<adc_common_t, 23, 1, "TSVREFE">{}; // bit offset: 23, bit width: 1, Temperature sensor and VREFINT enable
    static Register<std::uint32_t, ADC_COMMON_BASE_ADDRESS + 0x00000004u, 0, READWRITE, "CCR", decltype(MULT), decltype(DELAY), decltype(DDS), decltype(DMA), decltype(ADCPRE), decltype(VBATE), decltype(TSVREFE)> CCR; // ADC common control register

    constexpr auto DATA1 = BitField<adc_common_t, 0, 16, "DATA1">{}; // bit offset: 0, bit width: 16, 1st data item of a pair of regular conversions
    constexpr auto DATA2 = BitField<adc_common_t, 16, 16, "DATA2">{}; // bit offset: 16, bit width: 16, 2nd data item of a pair of regular conversions
    static Register<std::uint32_t, ADC_COMMON_BASE_ADDRESS + 0x00000008u, 0, READONLY, "CDR", decltype(DATA1), decltype(DATA2)> CDR; // ADC common regular data register for dual and triple modes

} // namespace ADC_COMMON