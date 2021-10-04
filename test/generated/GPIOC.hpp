#include <Register.hpp>

namespace GPIOC
{
    struct gpioc_t{};

    constexpr std::uint32_t GPIOC_BASE_ADDRESS = 0x40020800u;

    constexpr auto MODER0 = BitField<gpioc_t, 0, 2, "MODER0">{}; // bit offset: 0, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto MODER1 = BitField<gpioc_t, 2, 2, "MODER1">{}; // bit offset: 2, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto MODER2 = BitField<gpioc_t, 4, 2, "MODER2">{}; // bit offset: 4, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto MODER3 = BitField<gpioc_t, 6, 2, "MODER3">{}; // bit offset: 6, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto MODER4 = BitField<gpioc_t, 8, 2, "MODER4">{}; // bit offset: 8, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto MODER5 = BitField<gpioc_t, 10, 2, "MODER5">{}; // bit offset: 10, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto MODER6 = BitField<gpioc_t, 12, 2, "MODER6">{}; // bit offset: 12, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto MODER7 = BitField<gpioc_t, 14, 2, "MODER7">{}; // bit offset: 14, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto MODER8 = BitField<gpioc_t, 16, 2, "MODER8">{}; // bit offset: 16, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto MODER9 = BitField<gpioc_t, 18, 2, "MODER9">{}; // bit offset: 18, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto MODER10 = BitField<gpioc_t, 20, 2, "MODER10">{}; // bit offset: 20, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto MODER11 = BitField<gpioc_t, 22, 2, "MODER11">{}; // bit offset: 22, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto MODER12 = BitField<gpioc_t, 24, 2, "MODER12">{}; // bit offset: 24, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto MODER13 = BitField<gpioc_t, 26, 2, "MODER13">{}; // bit offset: 26, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto MODER14 = BitField<gpioc_t, 28, 2, "MODER14">{}; // bit offset: 28, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto MODER15 = BitField<gpioc_t, 30, 2, "MODER15">{}; // bit offset: 30, bit width: 2, Port x configuration bits (y = 0..15)
    static Register<std::uint32_t, GPIOC_BASE_ADDRESS + 0x00000000u, 0, READWRITE, "MODER", decltype(MODER0), decltype(MODER1), decltype(MODER2), decltype(MODER3), decltype(MODER4), decltype(MODER5), decltype(MODER6), decltype(MODER7), decltype(MODER8), decltype(MODER9), decltype(MODER10), decltype(MODER11), decltype(MODER12), decltype(MODER13), decltype(MODER14), decltype(MODER15)> MODER; // GPIO port mode register

    constexpr auto OT0 = BitField<gpioc_t, 0, 1, "OT0">{}; // bit offset: 0, bit width: 1, Port x configuration bit 0
    constexpr auto OT1 = BitField<gpioc_t, 1, 1, "OT1">{}; // bit offset: 1, bit width: 1, Port x configuration bit 1
    constexpr auto OT2 = BitField<gpioc_t, 2, 1, "OT2">{}; // bit offset: 2, bit width: 1, Port x configuration bit 2
    constexpr auto OT3 = BitField<gpioc_t, 3, 1, "OT3">{}; // bit offset: 3, bit width: 1, Port x configuration bit 3
    constexpr auto OT4 = BitField<gpioc_t, 4, 1, "OT4">{}; // bit offset: 4, bit width: 1, Port x configuration bit 4
    constexpr auto OT5 = BitField<gpioc_t, 5, 1, "OT5">{}; // bit offset: 5, bit width: 1, Port x configuration bit 5
    constexpr auto OT6 = BitField<gpioc_t, 6, 1, "OT6">{}; // bit offset: 6, bit width: 1, Port x configuration bit 6
    constexpr auto OT7 = BitField<gpioc_t, 7, 1, "OT7">{}; // bit offset: 7, bit width: 1, Port x configuration bit 7
    constexpr auto OT8 = BitField<gpioc_t, 8, 1, "OT8">{}; // bit offset: 8, bit width: 1, Port x configuration bit 8
    constexpr auto OT9 = BitField<gpioc_t, 9, 1, "OT9">{}; // bit offset: 9, bit width: 1, Port x configuration bit 9
    constexpr auto OT10 = BitField<gpioc_t, 10, 1, "OT10">{}; // bit offset: 10, bit width: 1, Port x configuration bit 10
    constexpr auto OT11 = BitField<gpioc_t, 11, 1, "OT11">{}; // bit offset: 11, bit width: 1, Port x configuration bit 11
    constexpr auto OT12 = BitField<gpioc_t, 12, 1, "OT12">{}; // bit offset: 12, bit width: 1, Port x configuration bit 12
    constexpr auto OT13 = BitField<gpioc_t, 13, 1, "OT13">{}; // bit offset: 13, bit width: 1, Port x configuration bit 13
    constexpr auto OT14 = BitField<gpioc_t, 14, 1, "OT14">{}; // bit offset: 14, bit width: 1, Port x configuration bit 14
    constexpr auto OT15 = BitField<gpioc_t, 15, 1, "OT15">{}; // bit offset: 15, bit width: 1, Port x configuration bit 15
    static Register<std::uint32_t, GPIOC_BASE_ADDRESS + 0x00000004u, 0, READWRITE, "OTYPER", decltype(OT0), decltype(OT1), decltype(OT2), decltype(OT3), decltype(OT4), decltype(OT5), decltype(OT6), decltype(OT7), decltype(OT8), decltype(OT9), decltype(OT10), decltype(OT11), decltype(OT12), decltype(OT13), decltype(OT14), decltype(OT15)> OTYPER; // GPIO port output type register

    constexpr auto OSPEEDR0 = BitField<gpioc_t, 0, 2, "OSPEEDR0">{}; // bit offset: 0, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto OSPEEDR1 = BitField<gpioc_t, 2, 2, "OSPEEDR1">{}; // bit offset: 2, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto OSPEEDR2 = BitField<gpioc_t, 4, 2, "OSPEEDR2">{}; // bit offset: 4, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto OSPEEDR3 = BitField<gpioc_t, 6, 2, "OSPEEDR3">{}; // bit offset: 6, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto OSPEEDR4 = BitField<gpioc_t, 8, 2, "OSPEEDR4">{}; // bit offset: 8, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto OSPEEDR5 = BitField<gpioc_t, 10, 2, "OSPEEDR5">{}; // bit offset: 10, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto OSPEEDR6 = BitField<gpioc_t, 12, 2, "OSPEEDR6">{}; // bit offset: 12, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto OSPEEDR7 = BitField<gpioc_t, 14, 2, "OSPEEDR7">{}; // bit offset: 14, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto OSPEEDR8 = BitField<gpioc_t, 16, 2, "OSPEEDR8">{}; // bit offset: 16, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto OSPEEDR9 = BitField<gpioc_t, 18, 2, "OSPEEDR9">{}; // bit offset: 18, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto OSPEEDR10 = BitField<gpioc_t, 20, 2, "OSPEEDR10">{}; // bit offset: 20, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto OSPEEDR11 = BitField<gpioc_t, 22, 2, "OSPEEDR11">{}; // bit offset: 22, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto OSPEEDR12 = BitField<gpioc_t, 24, 2, "OSPEEDR12">{}; // bit offset: 24, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto OSPEEDR13 = BitField<gpioc_t, 26, 2, "OSPEEDR13">{}; // bit offset: 26, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto OSPEEDR14 = BitField<gpioc_t, 28, 2, "OSPEEDR14">{}; // bit offset: 28, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto OSPEEDR15 = BitField<gpioc_t, 30, 2, "OSPEEDR15">{}; // bit offset: 30, bit width: 2, Port x configuration bits (y = 0..15)
    static Register<std::uint32_t, GPIOC_BASE_ADDRESS + 0x00000008u, 0, READWRITE, "OSPEEDR", decltype(OSPEEDR0), decltype(OSPEEDR1), decltype(OSPEEDR2), decltype(OSPEEDR3), decltype(OSPEEDR4), decltype(OSPEEDR5), decltype(OSPEEDR6), decltype(OSPEEDR7), decltype(OSPEEDR8), decltype(OSPEEDR9), decltype(OSPEEDR10), decltype(OSPEEDR11), decltype(OSPEEDR12), decltype(OSPEEDR13), decltype(OSPEEDR14), decltype(OSPEEDR15)> OSPEEDR; // GPIO port output speed register

    constexpr auto PUPDR0 = BitField<gpioc_t, 0, 2, "PUPDR0">{}; // bit offset: 0, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto PUPDR1 = BitField<gpioc_t, 2, 2, "PUPDR1">{}; // bit offset: 2, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto PUPDR2 = BitField<gpioc_t, 4, 2, "PUPDR2">{}; // bit offset: 4, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto PUPDR3 = BitField<gpioc_t, 6, 2, "PUPDR3">{}; // bit offset: 6, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto PUPDR4 = BitField<gpioc_t, 8, 2, "PUPDR4">{}; // bit offset: 8, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto PUPDR5 = BitField<gpioc_t, 10, 2, "PUPDR5">{}; // bit offset: 10, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto PUPDR6 = BitField<gpioc_t, 12, 2, "PUPDR6">{}; // bit offset: 12, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto PUPDR7 = BitField<gpioc_t, 14, 2, "PUPDR7">{}; // bit offset: 14, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto PUPDR8 = BitField<gpioc_t, 16, 2, "PUPDR8">{}; // bit offset: 16, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto PUPDR9 = BitField<gpioc_t, 18, 2, "PUPDR9">{}; // bit offset: 18, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto PUPDR10 = BitField<gpioc_t, 20, 2, "PUPDR10">{}; // bit offset: 20, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto PUPDR11 = BitField<gpioc_t, 22, 2, "PUPDR11">{}; // bit offset: 22, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto PUPDR12 = BitField<gpioc_t, 24, 2, "PUPDR12">{}; // bit offset: 24, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto PUPDR13 = BitField<gpioc_t, 26, 2, "PUPDR13">{}; // bit offset: 26, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto PUPDR14 = BitField<gpioc_t, 28, 2, "PUPDR14">{}; // bit offset: 28, bit width: 2, Port x configuration bits (y = 0..15)
    constexpr auto PUPDR15 = BitField<gpioc_t, 30, 2, "PUPDR15">{}; // bit offset: 30, bit width: 2, Port x configuration bits (y = 0..15)
    static Register<std::uint32_t, GPIOC_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, "PUPDR", decltype(PUPDR0), decltype(PUPDR1), decltype(PUPDR2), decltype(PUPDR3), decltype(PUPDR4), decltype(PUPDR5), decltype(PUPDR6), decltype(PUPDR7), decltype(PUPDR8), decltype(PUPDR9), decltype(PUPDR10), decltype(PUPDR11), decltype(PUPDR12), decltype(PUPDR13), decltype(PUPDR14), decltype(PUPDR15)> PUPDR; // GPIO port pull-up/pull-down register

    constexpr auto IDR0 = BitField<gpioc_t, 0, 1, "IDR0">{}; // bit offset: 0, bit width: 1, Port input data (y = 0..15)
    constexpr auto IDR1 = BitField<gpioc_t, 1, 1, "IDR1">{}; // bit offset: 1, bit width: 1, Port input data (y = 0..15)
    constexpr auto IDR2 = BitField<gpioc_t, 2, 1, "IDR2">{}; // bit offset: 2, bit width: 1, Port input data (y = 0..15)
    constexpr auto IDR3 = BitField<gpioc_t, 3, 1, "IDR3">{}; // bit offset: 3, bit width: 1, Port input data (y = 0..15)
    constexpr auto IDR4 = BitField<gpioc_t, 4, 1, "IDR4">{}; // bit offset: 4, bit width: 1, Port input data (y = 0..15)
    constexpr auto IDR5 = BitField<gpioc_t, 5, 1, "IDR5">{}; // bit offset: 5, bit width: 1, Port input data (y = 0..15)
    constexpr auto IDR6 = BitField<gpioc_t, 6, 1, "IDR6">{}; // bit offset: 6, bit width: 1, Port input data (y = 0..15)
    constexpr auto IDR7 = BitField<gpioc_t, 7, 1, "IDR7">{}; // bit offset: 7, bit width: 1, Port input data (y = 0..15)
    constexpr auto IDR8 = BitField<gpioc_t, 8, 1, "IDR8">{}; // bit offset: 8, bit width: 1, Port input data (y = 0..15)
    constexpr auto IDR9 = BitField<gpioc_t, 9, 1, "IDR9">{}; // bit offset: 9, bit width: 1, Port input data (y = 0..15)
    constexpr auto IDR10 = BitField<gpioc_t, 10, 1, "IDR10">{}; // bit offset: 10, bit width: 1, Port input data (y = 0..15)
    constexpr auto IDR11 = BitField<gpioc_t, 11, 1, "IDR11">{}; // bit offset: 11, bit width: 1, Port input data (y = 0..15)
    constexpr auto IDR12 = BitField<gpioc_t, 12, 1, "IDR12">{}; // bit offset: 12, bit width: 1, Port input data (y = 0..15)
    constexpr auto IDR13 = BitField<gpioc_t, 13, 1, "IDR13">{}; // bit offset: 13, bit width: 1, Port input data (y = 0..15)
    constexpr auto IDR14 = BitField<gpioc_t, 14, 1, "IDR14">{}; // bit offset: 14, bit width: 1, Port input data (y = 0..15)
    constexpr auto IDR15 = BitField<gpioc_t, 15, 1, "IDR15">{}; // bit offset: 15, bit width: 1, Port input data (y = 0..15)
    static Register<std::uint32_t, GPIOC_BASE_ADDRESS + 0x00000010u, 0, READONLY, "IDR", decltype(IDR0), decltype(IDR1), decltype(IDR2), decltype(IDR3), decltype(IDR4), decltype(IDR5), decltype(IDR6), decltype(IDR7), decltype(IDR8), decltype(IDR9), decltype(IDR10), decltype(IDR11), decltype(IDR12), decltype(IDR13), decltype(IDR14), decltype(IDR15)> IDR; // GPIO port input data register

    constexpr auto ODR0 = BitField<gpioc_t, 0, 1, "ODR0">{}; // bit offset: 0, bit width: 1, Port output data (y = 0..15)
    constexpr auto ODR1 = BitField<gpioc_t, 1, 1, "ODR1">{}; // bit offset: 1, bit width: 1, Port output data (y = 0..15)
    constexpr auto ODR2 = BitField<gpioc_t, 2, 1, "ODR2">{}; // bit offset: 2, bit width: 1, Port output data (y = 0..15)
    constexpr auto ODR3 = BitField<gpioc_t, 3, 1, "ODR3">{}; // bit offset: 3, bit width: 1, Port output data (y = 0..15)
    constexpr auto ODR4 = BitField<gpioc_t, 4, 1, "ODR4">{}; // bit offset: 4, bit width: 1, Port output data (y = 0..15)
    constexpr auto ODR5 = BitField<gpioc_t, 5, 1, "ODR5">{}; // bit offset: 5, bit width: 1, Port output data (y = 0..15)
    constexpr auto ODR6 = BitField<gpioc_t, 6, 1, "ODR6">{}; // bit offset: 6, bit width: 1, Port output data (y = 0..15)
    constexpr auto ODR7 = BitField<gpioc_t, 7, 1, "ODR7">{}; // bit offset: 7, bit width: 1, Port output data (y = 0..15)
    constexpr auto ODR8 = BitField<gpioc_t, 8, 1, "ODR8">{}; // bit offset: 8, bit width: 1, Port output data (y = 0..15)
    constexpr auto ODR9 = BitField<gpioc_t, 9, 1, "ODR9">{}; // bit offset: 9, bit width: 1, Port output data (y = 0..15)
    constexpr auto ODR10 = BitField<gpioc_t, 10, 1, "ODR10">{}; // bit offset: 10, bit width: 1, Port output data (y = 0..15)
    constexpr auto ODR11 = BitField<gpioc_t, 11, 1, "ODR11">{}; // bit offset: 11, bit width: 1, Port output data (y = 0..15)
    constexpr auto ODR12 = BitField<gpioc_t, 12, 1, "ODR12">{}; // bit offset: 12, bit width: 1, Port output data (y = 0..15)
    constexpr auto ODR13 = BitField<gpioc_t, 13, 1, "ODR13">{}; // bit offset: 13, bit width: 1, Port output data (y = 0..15)
    constexpr auto ODR14 = BitField<gpioc_t, 14, 1, "ODR14">{}; // bit offset: 14, bit width: 1, Port output data (y = 0..15)
    constexpr auto ODR15 = BitField<gpioc_t, 15, 1, "ODR15">{}; // bit offset: 15, bit width: 1, Port output data (y = 0..15)
    static Register<std::uint32_t, GPIOC_BASE_ADDRESS + 0x00000014u, 0, READWRITE, "ODR", decltype(ODR0), decltype(ODR1), decltype(ODR2), decltype(ODR3), decltype(ODR4), decltype(ODR5), decltype(ODR6), decltype(ODR7), decltype(ODR8), decltype(ODR9), decltype(ODR10), decltype(ODR11), decltype(ODR12), decltype(ODR13), decltype(ODR14), decltype(ODR15)> ODR; // GPIO port output data register

    constexpr auto BS0 = BitField<gpioc_t, 0, 1, "BS0">{}; // bit offset: 0, bit width: 1, Port x set bit y (y= 0..15)
    constexpr auto BS1 = BitField<gpioc_t, 1, 1, "BS1">{}; // bit offset: 1, bit width: 1, Port x set bit y (y= 0..15)
    constexpr auto BS2 = BitField<gpioc_t, 2, 1, "BS2">{}; // bit offset: 2, bit width: 1, Port x set bit y (y= 0..15)
    constexpr auto BS3 = BitField<gpioc_t, 3, 1, "BS3">{}; // bit offset: 3, bit width: 1, Port x set bit y (y= 0..15)
    constexpr auto BS4 = BitField<gpioc_t, 4, 1, "BS4">{}; // bit offset: 4, bit width: 1, Port x set bit y (y= 0..15)
    constexpr auto BS5 = BitField<gpioc_t, 5, 1, "BS5">{}; // bit offset: 5, bit width: 1, Port x set bit y (y= 0..15)
    constexpr auto BS6 = BitField<gpioc_t, 6, 1, "BS6">{}; // bit offset: 6, bit width: 1, Port x set bit y (y= 0..15)
    constexpr auto BS7 = BitField<gpioc_t, 7, 1, "BS7">{}; // bit offset: 7, bit width: 1, Port x set bit y (y= 0..15)
    constexpr auto BS8 = BitField<gpioc_t, 8, 1, "BS8">{}; // bit offset: 8, bit width: 1, Port x set bit y (y= 0..15)
    constexpr auto BS9 = BitField<gpioc_t, 9, 1, "BS9">{}; // bit offset: 9, bit width: 1, Port x set bit y (y= 0..15)
    constexpr auto BS10 = BitField<gpioc_t, 10, 1, "BS10">{}; // bit offset: 10, bit width: 1, Port x set bit y (y= 0..15)
    constexpr auto BS11 = BitField<gpioc_t, 11, 1, "BS11">{}; // bit offset: 11, bit width: 1, Port x set bit y (y= 0..15)
    constexpr auto BS12 = BitField<gpioc_t, 12, 1, "BS12">{}; // bit offset: 12, bit width: 1, Port x set bit y (y= 0..15)
    constexpr auto BS13 = BitField<gpioc_t, 13, 1, "BS13">{}; // bit offset: 13, bit width: 1, Port x set bit y (y= 0..15)
    constexpr auto BS14 = BitField<gpioc_t, 14, 1, "BS14">{}; // bit offset: 14, bit width: 1, Port x set bit y (y= 0..15)
    constexpr auto BS15 = BitField<gpioc_t, 15, 1, "BS15">{}; // bit offset: 15, bit width: 1, Port x set bit y (y= 0..15)
    constexpr auto BR0 = BitField<gpioc_t, 16, 1, "BR0">{}; // bit offset: 16, bit width: 1, Port x set bit y (y= 0..15)
    constexpr auto BR1 = BitField<gpioc_t, 17, 1, "BR1">{}; // bit offset: 17, bit width: 1, Port x reset bit y (y = 0..15)
    constexpr auto BR2 = BitField<gpioc_t, 18, 1, "BR2">{}; // bit offset: 18, bit width: 1, Port x reset bit y (y = 0..15)
    constexpr auto BR3 = BitField<gpioc_t, 19, 1, "BR3">{}; // bit offset: 19, bit width: 1, Port x reset bit y (y = 0..15)
    constexpr auto BR4 = BitField<gpioc_t, 20, 1, "BR4">{}; // bit offset: 20, bit width: 1, Port x reset bit y (y = 0..15)
    constexpr auto BR5 = BitField<gpioc_t, 21, 1, "BR5">{}; // bit offset: 21, bit width: 1, Port x reset bit y (y = 0..15)
    constexpr auto BR6 = BitField<gpioc_t, 22, 1, "BR6">{}; // bit offset: 22, bit width: 1, Port x reset bit y (y = 0..15)
    constexpr auto BR7 = BitField<gpioc_t, 23, 1, "BR7">{}; // bit offset: 23, bit width: 1, Port x reset bit y (y = 0..15)
    constexpr auto BR8 = BitField<gpioc_t, 24, 1, "BR8">{}; // bit offset: 24, bit width: 1, Port x reset bit y (y = 0..15)
    constexpr auto BR9 = BitField<gpioc_t, 25, 1, "BR9">{}; // bit offset: 25, bit width: 1, Port x reset bit y (y = 0..15)
    constexpr auto BR10 = BitField<gpioc_t, 26, 1, "BR10">{}; // bit offset: 26, bit width: 1, Port x reset bit y (y = 0..15)
    constexpr auto BR11 = BitField<gpioc_t, 27, 1, "BR11">{}; // bit offset: 27, bit width: 1, Port x reset bit y (y = 0..15)
    constexpr auto BR12 = BitField<gpioc_t, 28, 1, "BR12">{}; // bit offset: 28, bit width: 1, Port x reset bit y (y = 0..15)
    constexpr auto BR13 = BitField<gpioc_t, 29, 1, "BR13">{}; // bit offset: 29, bit width: 1, Port x reset bit y (y = 0..15)
    constexpr auto BR14 = BitField<gpioc_t, 30, 1, "BR14">{}; // bit offset: 30, bit width: 1, Port x reset bit y (y = 0..15)
    constexpr auto BR15 = BitField<gpioc_t, 31, 1, "BR15">{}; // bit offset: 31, bit width: 1, Port x reset bit y (y = 0..15)
    static Register<std::uint32_t, GPIOC_BASE_ADDRESS + 0x00000018u, 0, WRITEONLY, "BSRR", decltype(BS0), decltype(BS1), decltype(BS2), decltype(BS3), decltype(BS4), decltype(BS5), decltype(BS6), decltype(BS7), decltype(BS8), decltype(BS9), decltype(BS10), decltype(BS11), decltype(BS12), decltype(BS13), decltype(BS14), decltype(BS15), decltype(BR0), decltype(BR1), decltype(BR2), decltype(BR3), decltype(BR4), decltype(BR5), decltype(BR6), decltype(BR7), decltype(BR8), decltype(BR9), decltype(BR10), decltype(BR11), decltype(BR12), decltype(BR13), decltype(BR14), decltype(BR15)> BSRR; // GPIO port bit set/reset register

    constexpr auto LCK0 = BitField<gpioc_t, 0, 1, "LCK0">{}; // bit offset: 0, bit width: 1, Port x lock bit y (y= 0..15)
    constexpr auto LCK1 = BitField<gpioc_t, 1, 1, "LCK1">{}; // bit offset: 1, bit width: 1, Port x lock bit y (y= 0..15)
    constexpr auto LCK2 = BitField<gpioc_t, 2, 1, "LCK2">{}; // bit offset: 2, bit width: 1, Port x lock bit y (y= 0..15)
    constexpr auto LCK3 = BitField<gpioc_t, 3, 1, "LCK3">{}; // bit offset: 3, bit width: 1, Port x lock bit y (y= 0..15)
    constexpr auto LCK4 = BitField<gpioc_t, 4, 1, "LCK4">{}; // bit offset: 4, bit width: 1, Port x lock bit y (y= 0..15)
    constexpr auto LCK5 = BitField<gpioc_t, 5, 1, "LCK5">{}; // bit offset: 5, bit width: 1, Port x lock bit y (y= 0..15)
    constexpr auto LCK6 = BitField<gpioc_t, 6, 1, "LCK6">{}; // bit offset: 6, bit width: 1, Port x lock bit y (y= 0..15)
    constexpr auto LCK7 = BitField<gpioc_t, 7, 1, "LCK7">{}; // bit offset: 7, bit width: 1, Port x lock bit y (y= 0..15)
    constexpr auto LCK8 = BitField<gpioc_t, 8, 1, "LCK8">{}; // bit offset: 8, bit width: 1, Port x lock bit y (y= 0..15)
    constexpr auto LCK9 = BitField<gpioc_t, 9, 1, "LCK9">{}; // bit offset: 9, bit width: 1, Port x lock bit y (y= 0..15)
    constexpr auto LCK10 = BitField<gpioc_t, 10, 1, "LCK10">{}; // bit offset: 10, bit width: 1, Port x lock bit y (y= 0..15)
    constexpr auto LCK11 = BitField<gpioc_t, 11, 1, "LCK11">{}; // bit offset: 11, bit width: 1, Port x lock bit y (y= 0..15)
    constexpr auto LCK12 = BitField<gpioc_t, 12, 1, "LCK12">{}; // bit offset: 12, bit width: 1, Port x lock bit y (y= 0..15)
    constexpr auto LCK13 = BitField<gpioc_t, 13, 1, "LCK13">{}; // bit offset: 13, bit width: 1, Port x lock bit y (y= 0..15)
    constexpr auto LCK14 = BitField<gpioc_t, 14, 1, "LCK14">{}; // bit offset: 14, bit width: 1, Port x lock bit y (y= 0..15)
    constexpr auto LCK15 = BitField<gpioc_t, 15, 1, "LCK15">{}; // bit offset: 15, bit width: 1, Port x lock bit y (y= 0..15)
    constexpr auto LCKK = BitField<gpioc_t, 16, 1, "LCKK">{}; // bit offset: 16, bit width: 1, Port x lock bit y (y= 0..15)
    static Register<std::uint32_t, GPIOC_BASE_ADDRESS + 0x0000001cu, 0, READWRITE, "LCKR", decltype(LCK0), decltype(LCK1), decltype(LCK2), decltype(LCK3), decltype(LCK4), decltype(LCK5), decltype(LCK6), decltype(LCK7), decltype(LCK8), decltype(LCK9), decltype(LCK10), decltype(LCK11), decltype(LCK12), decltype(LCK13), decltype(LCK14), decltype(LCK15), decltype(LCKK)> LCKR; // GPIO port configuration lock register

    constexpr auto AFRL0 = BitField<gpioc_t, 0, 4, "AFRL0">{}; // bit offset: 0, bit width: 4, Alternate function selection for port x bit y (y = 0..7)
    constexpr auto AFRL1 = BitField<gpioc_t, 4, 4, "AFRL1">{}; // bit offset: 4, bit width: 4, Alternate function selection for port x bit y (y = 0..7)
    constexpr auto AFRL2 = BitField<gpioc_t, 8, 4, "AFRL2">{}; // bit offset: 8, bit width: 4, Alternate function selection for port x bit y (y = 0..7)
    constexpr auto AFRL3 = BitField<gpioc_t, 12, 4, "AFRL3">{}; // bit offset: 12, bit width: 4, Alternate function selection for port x bit y (y = 0..7)
    constexpr auto AFRL4 = BitField<gpioc_t, 16, 4, "AFRL4">{}; // bit offset: 16, bit width: 4, Alternate function selection for port x bit y (y = 0..7)
    constexpr auto AFRL5 = BitField<gpioc_t, 20, 4, "AFRL5">{}; // bit offset: 20, bit width: 4, Alternate function selection for port x bit y (y = 0..7)
    constexpr auto AFRL6 = BitField<gpioc_t, 24, 4, "AFRL6">{}; // bit offset: 24, bit width: 4, Alternate function selection for port x bit y (y = 0..7)
    constexpr auto AFRL7 = BitField<gpioc_t, 28, 4, "AFRL7">{}; // bit offset: 28, bit width: 4, Alternate function selection for port x bit y (y = 0..7)
    static Register<std::uint32_t, GPIOC_BASE_ADDRESS + 0x00000020u, 0, READWRITE, "AFRL", decltype(AFRL0), decltype(AFRL1), decltype(AFRL2), decltype(AFRL3), decltype(AFRL4), decltype(AFRL5), decltype(AFRL6), decltype(AFRL7)> AFRL; // GPIO alternate function low register

    constexpr auto AFRH8 = BitField<gpioc_t, 0, 4, "AFRH8">{}; // bit offset: 0, bit width: 4, Alternate function selection for port x bit y (y = 8..15)
    constexpr auto AFRH9 = BitField<gpioc_t, 4, 4, "AFRH9">{}; // bit offset: 4, bit width: 4, Alternate function selection for port x bit y (y = 8..15)
    constexpr auto AFRH10 = BitField<gpioc_t, 8, 4, "AFRH10">{}; // bit offset: 8, bit width: 4, Alternate function selection for port x bit y (y = 8..15)
    constexpr auto AFRH11 = BitField<gpioc_t, 12, 4, "AFRH11">{}; // bit offset: 12, bit width: 4, Alternate function selection for port x bit y (y = 8..15)
    constexpr auto AFRH12 = BitField<gpioc_t, 16, 4, "AFRH12">{}; // bit offset: 16, bit width: 4, Alternate function selection for port x bit y (y = 8..15)
    constexpr auto AFRH13 = BitField<gpioc_t, 20, 4, "AFRH13">{}; // bit offset: 20, bit width: 4, Alternate function selection for port x bit y (y = 8..15)
    constexpr auto AFRH14 = BitField<gpioc_t, 24, 4, "AFRH14">{}; // bit offset: 24, bit width: 4, Alternate function selection for port x bit y (y = 8..15)
    constexpr auto AFRH15 = BitField<gpioc_t, 28, 4, "AFRH15">{}; // bit offset: 28, bit width: 4, Alternate function selection for port x bit y (y = 8..15)
    static Register<std::uint32_t, GPIOC_BASE_ADDRESS + 0x00000024u, 0, READWRITE, "AFRH", decltype(AFRH8), decltype(AFRH9), decltype(AFRH10), decltype(AFRH11), decltype(AFRH12), decltype(AFRH13), decltype(AFRH14), decltype(AFRH15)> AFRH; // GPIO alternate function high register

} // namespace GPIOC