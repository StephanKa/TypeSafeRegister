#include <Register.hpp>

namespace RCC
{
    struct rcc_t{};

    constexpr std::uint32_t RCC_BASE_ADDRESS = 0x40023800u;

    constexpr auto HSION = BitField<rcc_t, 0, 1, "HSION", READWRITE>{}; // bit offset: 0, bit width: 1, Internal high-speed clock enable
    constexpr auto HSIRDY = BitField<rcc_t, 1, 1, "HSIRDY", READONLY>{}; // bit offset: 1, bit width: 1, Internal high-speed clock ready flag
    constexpr auto HSITRIM = BitField<rcc_t, 3, 5, "HSITRIM", READWRITE>{}; // bit offset: 3, bit width: 5, Internal high-speed clock trimming
    constexpr auto HSICAL = BitField<rcc_t, 8, 8, "HSICAL", READONLY>{}; // bit offset: 8, bit width: 8, Internal high-speed clock calibration
    constexpr auto HSEON = BitField<rcc_t, 16, 1, "HSEON", READWRITE>{}; // bit offset: 16, bit width: 1, HSE clock enable
    constexpr auto HSERDY = BitField<rcc_t, 17, 1, "HSERDY", READONLY>{}; // bit offset: 17, bit width: 1, HSE clock ready flag
    constexpr auto HSEBYP = BitField<rcc_t, 18, 1, "HSEBYP", READWRITE>{}; // bit offset: 18, bit width: 1, HSE clock bypass
    constexpr auto CSSON = BitField<rcc_t, 19, 1, "CSSON", READWRITE>{}; // bit offset: 19, bit width: 1, Clock security system enable
    constexpr auto PLLON = BitField<rcc_t, 24, 1, "PLLON", READWRITE>{}; // bit offset: 24, bit width: 1, Main PLL (PLL) enable
    constexpr auto PLLRDY = BitField<rcc_t, 25, 1, "PLLRDY", READONLY>{}; // bit offset: 25, bit width: 1, Main PLL (PLL) clock ready flag
    constexpr auto PLLI2SON = BitField<rcc_t, 26, 1, "PLLI2SON", READWRITE>{}; // bit offset: 26, bit width: 1, PLLI2S enable
    constexpr auto PLLI2SRDY = BitField<rcc_t, 27, 1, "PLLI2SRDY", READONLY>{}; // bit offset: 27, bit width: 1, PLLI2S clock ready flag
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000000u, 131, READWRITE, "CR", decltype(HSION), decltype(HSIRDY), decltype(HSITRIM), decltype(HSICAL), decltype(HSEON), decltype(HSERDY), decltype(HSEBYP), decltype(CSSON), decltype(PLLON), decltype(PLLRDY), decltype(PLLI2SON), decltype(PLLI2SRDY)> CR; // clock control register

    constexpr auto PLLM0 = BitField<rcc_t, 0, 1, "PLLM0">{}; // bit offset: 0, bit width: 1, Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
    constexpr auto PLLM1 = BitField<rcc_t, 1, 1, "PLLM1">{}; // bit offset: 1, bit width: 1, Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
    constexpr auto PLLM2 = BitField<rcc_t, 2, 1, "PLLM2">{}; // bit offset: 2, bit width: 1, Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
    constexpr auto PLLM3 = BitField<rcc_t, 3, 1, "PLLM3">{}; // bit offset: 3, bit width: 1, Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
    constexpr auto PLLM4 = BitField<rcc_t, 4, 1, "PLLM4">{}; // bit offset: 4, bit width: 1, Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
    constexpr auto PLLM5 = BitField<rcc_t, 5, 1, "PLLM5">{}; // bit offset: 5, bit width: 1, Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
    constexpr auto PLLN0 = BitField<rcc_t, 6, 1, "PLLN0">{}; // bit offset: 6, bit width: 1, Main PLL (PLL) multiplication factor for VCO
    constexpr auto PLLN1 = BitField<rcc_t, 7, 1, "PLLN1">{}; // bit offset: 7, bit width: 1, Main PLL (PLL) multiplication factor for VCO
    constexpr auto PLLN2 = BitField<rcc_t, 8, 1, "PLLN2">{}; // bit offset: 8, bit width: 1, Main PLL (PLL) multiplication factor for VCO
    constexpr auto PLLN3 = BitField<rcc_t, 9, 1, "PLLN3">{}; // bit offset: 9, bit width: 1, Main PLL (PLL) multiplication factor for VCO
    constexpr auto PLLN4 = BitField<rcc_t, 10, 1, "PLLN4">{}; // bit offset: 10, bit width: 1, Main PLL (PLL) multiplication factor for VCO
    constexpr auto PLLN5 = BitField<rcc_t, 11, 1, "PLLN5">{}; // bit offset: 11, bit width: 1, Main PLL (PLL) multiplication factor for VCO
    constexpr auto PLLN6 = BitField<rcc_t, 12, 1, "PLLN6">{}; // bit offset: 12, bit width: 1, Main PLL (PLL) multiplication factor for VCO
    constexpr auto PLLN7 = BitField<rcc_t, 13, 1, "PLLN7">{}; // bit offset: 13, bit width: 1, Main PLL (PLL) multiplication factor for VCO
    constexpr auto PLLN8 = BitField<rcc_t, 14, 1, "PLLN8">{}; // bit offset: 14, bit width: 1, Main PLL (PLL) multiplication factor for VCO
    constexpr auto PLLP0 = BitField<rcc_t, 16, 1, "PLLP0">{}; // bit offset: 16, bit width: 1, Main PLL (PLL) division factor for main system clock
    constexpr auto PLLP1 = BitField<rcc_t, 17, 1, "PLLP1">{}; // bit offset: 17, bit width: 1, Main PLL (PLL) division factor for main system clock
    constexpr auto PLLSRC = BitField<rcc_t, 22, 1, "PLLSRC">{}; // bit offset: 22, bit width: 1, Main PLL(PLL) and audio PLL (PLLI2S) entry clock source
    constexpr auto PLLQ0 = BitField<rcc_t, 24, 1, "PLLQ0">{}; // bit offset: 24, bit width: 1, Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks
    constexpr auto PLLQ1 = BitField<rcc_t, 25, 1, "PLLQ1">{}; // bit offset: 25, bit width: 1, Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks
    constexpr auto PLLQ2 = BitField<rcc_t, 26, 1, "PLLQ2">{}; // bit offset: 26, bit width: 1, Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks
    constexpr auto PLLQ3 = BitField<rcc_t, 27, 1, "PLLQ3">{}; // bit offset: 27, bit width: 1, Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000004u, 603992080, READWRITE, "PLLCFGR", decltype(PLLM0), decltype(PLLM1), decltype(PLLM2), decltype(PLLM3), decltype(PLLM4), decltype(PLLM5), decltype(PLLN0), decltype(PLLN1), decltype(PLLN2), decltype(PLLN3), decltype(PLLN4), decltype(PLLN5), decltype(PLLN6), decltype(PLLN7), decltype(PLLN8), decltype(PLLP0), decltype(PLLP1), decltype(PLLSRC), decltype(PLLQ0), decltype(PLLQ1), decltype(PLLQ2), decltype(PLLQ3)> PLLCFGR; // PLL configuration register

    constexpr auto SW0 = BitField<rcc_t, 0, 1, "SW0", READWRITE>{}; // bit offset: 0, bit width: 1, System clock switch
    constexpr auto SW1 = BitField<rcc_t, 1, 1, "SW1", READWRITE>{}; // bit offset: 1, bit width: 1, System clock switch
    constexpr auto SWS0 = BitField<rcc_t, 2, 1, "SWS0", READONLY>{}; // bit offset: 2, bit width: 1, System clock switch status
    constexpr auto SWS1 = BitField<rcc_t, 3, 1, "SWS1", READONLY>{}; // bit offset: 3, bit width: 1, System clock switch status
    constexpr auto HPRE0 = BitField<rcc_t, 4, 1, "HPRE0", READWRITE>{}; // bit offset: 4, bit width: 1, AHB prescaler
    constexpr auto HPRE1 = BitField<rcc_t, 5, 1, "HPRE1", READWRITE>{}; // bit offset: 5, bit width: 1, AHB prescaler
    constexpr auto HPRE2 = BitField<rcc_t, 6, 1, "HPRE2", READWRITE>{}; // bit offset: 6, bit width: 1, AHB prescaler
    constexpr auto HPRE3 = BitField<rcc_t, 7, 1, "HPRE3", READWRITE>{}; // bit offset: 7, bit width: 1, AHB prescaler
    constexpr auto PPRE10 = BitField<rcc_t, 10, 1, "PPRE10", READWRITE>{}; // bit offset: 10, bit width: 1, APB Low speed prescaler (APB1)
    constexpr auto PPRE11 = BitField<rcc_t, 11, 1, "PPRE11", READWRITE>{}; // bit offset: 11, bit width: 1, APB Low speed prescaler (APB1)
    constexpr auto PPRE12 = BitField<rcc_t, 12, 1, "PPRE12", READWRITE>{}; // bit offset: 12, bit width: 1, APB Low speed prescaler (APB1)
    constexpr auto PPRE20 = BitField<rcc_t, 13, 1, "PPRE20", READWRITE>{}; // bit offset: 13, bit width: 1, APB high-speed prescaler (APB2)
    constexpr auto PPRE21 = BitField<rcc_t, 14, 1, "PPRE21", READWRITE>{}; // bit offset: 14, bit width: 1, APB high-speed prescaler (APB2)
    constexpr auto PPRE22 = BitField<rcc_t, 15, 1, "PPRE22", READWRITE>{}; // bit offset: 15, bit width: 1, APB high-speed prescaler (APB2)
    constexpr auto RTCPRE0 = BitField<rcc_t, 16, 1, "RTCPRE0", READWRITE>{}; // bit offset: 16, bit width: 1, HSE division factor for RTC clock
    constexpr auto RTCPRE1 = BitField<rcc_t, 17, 1, "RTCPRE1", READWRITE>{}; // bit offset: 17, bit width: 1, HSE division factor for RTC clock
    constexpr auto RTCPRE2 = BitField<rcc_t, 18, 1, "RTCPRE2", READWRITE>{}; // bit offset: 18, bit width: 1, HSE division factor for RTC clock
    constexpr auto RTCPRE3 = BitField<rcc_t, 19, 1, "RTCPRE3", READWRITE>{}; // bit offset: 19, bit width: 1, HSE division factor for RTC clock
    constexpr auto RTCPRE4 = BitField<rcc_t, 20, 1, "RTCPRE4", READWRITE>{}; // bit offset: 20, bit width: 1, HSE division factor for RTC clock
    constexpr auto MCO10 = BitField<rcc_t, 21, 1, "MCO10", READWRITE>{}; // bit offset: 21, bit width: 1, Microcontroller clock output 1
    constexpr auto MCO11 = BitField<rcc_t, 22, 1, "MCO11", READWRITE>{}; // bit offset: 22, bit width: 1, Microcontroller clock output 1
    constexpr auto I2SSRC = BitField<rcc_t, 23, 1, "I2SSRC", READWRITE>{}; // bit offset: 23, bit width: 1, I2S clock selection
    constexpr auto MCO1PRE0 = BitField<rcc_t, 24, 1, "MCO1PRE0", READWRITE>{}; // bit offset: 24, bit width: 1, MCO1 prescaler
    constexpr auto MCO1PRE1 = BitField<rcc_t, 25, 1, "MCO1PRE1", READWRITE>{}; // bit offset: 25, bit width: 1, MCO1 prescaler
    constexpr auto MCO1PRE2 = BitField<rcc_t, 26, 1, "MCO1PRE2", READWRITE>{}; // bit offset: 26, bit width: 1, MCO1 prescaler
    constexpr auto MCO2PRE0 = BitField<rcc_t, 27, 1, "MCO2PRE0", READWRITE>{}; // bit offset: 27, bit width: 1, MCO2 prescaler
    constexpr auto MCO2PRE1 = BitField<rcc_t, 28, 1, "MCO2PRE1", READWRITE>{}; // bit offset: 28, bit width: 1, MCO2 prescaler
    constexpr auto MCO2PRE2 = BitField<rcc_t, 29, 1, "MCO2PRE2", READWRITE>{}; // bit offset: 29, bit width: 1, MCO2 prescaler
    constexpr auto MCO20 = BitField<rcc_t, 30, 1, "MCO20", READWRITE>{}; // bit offset: 30, bit width: 1, Microcontroller clock output 2
    constexpr auto MCO21 = BitField<rcc_t, 31, 1, "MCO21", READWRITE>{}; // bit offset: 31, bit width: 1, Microcontroller clock output 2
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000008u, 0, READWRITE, "CFGR", decltype(SW0), decltype(SW1), decltype(SWS0), decltype(SWS1), decltype(HPRE0), decltype(HPRE1), decltype(HPRE2), decltype(HPRE3), decltype(PPRE10), decltype(PPRE11), decltype(PPRE12), decltype(PPRE20), decltype(PPRE21), decltype(PPRE22), decltype(RTCPRE0), decltype(RTCPRE1), decltype(RTCPRE2), decltype(RTCPRE3), decltype(RTCPRE4), decltype(MCO10), decltype(MCO11), decltype(I2SSRC), decltype(MCO1PRE0), decltype(MCO1PRE1), decltype(MCO1PRE2), decltype(MCO2PRE0), decltype(MCO2PRE1), decltype(MCO2PRE2), decltype(MCO20), decltype(MCO21)> CFGR; // clock configuration register

    constexpr auto LSIRDYF = BitField<rcc_t, 0, 1, "LSIRDYF", READONLY>{}; // bit offset: 0, bit width: 1, LSI ready interrupt flag
    constexpr auto LSERDYF = BitField<rcc_t, 1, 1, "LSERDYF", READONLY>{}; // bit offset: 1, bit width: 1, LSE ready interrupt flag
    constexpr auto HSIRDYF = BitField<rcc_t, 2, 1, "HSIRDYF", READONLY>{}; // bit offset: 2, bit width: 1, HSI ready interrupt flag
    constexpr auto HSERDYF = BitField<rcc_t, 3, 1, "HSERDYF", READONLY>{}; // bit offset: 3, bit width: 1, HSE ready interrupt flag
    constexpr auto PLLRDYF = BitField<rcc_t, 4, 1, "PLLRDYF", READONLY>{}; // bit offset: 4, bit width: 1, Main PLL (PLL) ready interrupt flag
    constexpr auto PLLI2SRDYF = BitField<rcc_t, 5, 1, "PLLI2SRDYF", READONLY>{}; // bit offset: 5, bit width: 1, PLLI2S ready interrupt flag
    constexpr auto CSSF = BitField<rcc_t, 7, 1, "CSSF", READONLY>{}; // bit offset: 7, bit width: 1, Clock security system interrupt flag
    constexpr auto LSIRDYIE = BitField<rcc_t, 8, 1, "LSIRDYIE", READWRITE>{}; // bit offset: 8, bit width: 1, LSI ready interrupt enable
    constexpr auto LSERDYIE = BitField<rcc_t, 9, 1, "LSERDYIE", READWRITE>{}; // bit offset: 9, bit width: 1, LSE ready interrupt enable
    constexpr auto HSIRDYIE = BitField<rcc_t, 10, 1, "HSIRDYIE", READWRITE>{}; // bit offset: 10, bit width: 1, HSI ready interrupt enable
    constexpr auto HSERDYIE = BitField<rcc_t, 11, 1, "HSERDYIE", READWRITE>{}; // bit offset: 11, bit width: 1, HSE ready interrupt enable
    constexpr auto PLLRDYIE = BitField<rcc_t, 12, 1, "PLLRDYIE", READWRITE>{}; // bit offset: 12, bit width: 1, Main PLL (PLL) ready interrupt enable
    constexpr auto PLLI2SRDYIE = BitField<rcc_t, 13, 1, "PLLI2SRDYIE", READWRITE>{}; // bit offset: 13, bit width: 1, PLLI2S ready interrupt enable
    constexpr auto LSIRDYC = BitField<rcc_t, 16, 1, "LSIRDYC", WRITEONLY>{}; // bit offset: 16, bit width: 1, LSI ready interrupt clear
    constexpr auto LSERDYC = BitField<rcc_t, 17, 1, "LSERDYC", WRITEONLY>{}; // bit offset: 17, bit width: 1, LSE ready interrupt clear
    constexpr auto HSIRDYC = BitField<rcc_t, 18, 1, "HSIRDYC", WRITEONLY>{}; // bit offset: 18, bit width: 1, HSI ready interrupt clear
    constexpr auto HSERDYC = BitField<rcc_t, 19, 1, "HSERDYC", WRITEONLY>{}; // bit offset: 19, bit width: 1, HSE ready interrupt clear
    constexpr auto PLLRDYC = BitField<rcc_t, 20, 1, "PLLRDYC", WRITEONLY>{}; // bit offset: 20, bit width: 1, Main PLL(PLL) ready interrupt clear
    constexpr auto PLLI2SRDYC = BitField<rcc_t, 21, 1, "PLLI2SRDYC", WRITEONLY>{}; // bit offset: 21, bit width: 1, PLLI2S ready interrupt clear
    constexpr auto CSSC = BitField<rcc_t, 23, 1, "CSSC", WRITEONLY>{}; // bit offset: 23, bit width: 1, Clock security system interrupt clear
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, "CIR", decltype(LSIRDYF), decltype(LSERDYF), decltype(HSIRDYF), decltype(HSERDYF), decltype(PLLRDYF), decltype(PLLI2SRDYF), decltype(CSSF), decltype(LSIRDYIE), decltype(LSERDYIE), decltype(HSIRDYIE), decltype(HSERDYIE), decltype(PLLRDYIE), decltype(PLLI2SRDYIE), decltype(LSIRDYC), decltype(LSERDYC), decltype(HSIRDYC), decltype(HSERDYC), decltype(PLLRDYC), decltype(PLLI2SRDYC), decltype(CSSC)> CIR; // clock interrupt register

    constexpr auto GPIOARST = BitField<rcc_t, 0, 1, "GPIOARST">{}; // bit offset: 0, bit width: 1, IO port A reset
    constexpr auto GPIOBRST = BitField<rcc_t, 1, 1, "GPIOBRST">{}; // bit offset: 1, bit width: 1, IO port B reset
    constexpr auto GPIOCRST = BitField<rcc_t, 2, 1, "GPIOCRST">{}; // bit offset: 2, bit width: 1, IO port C reset
    constexpr auto GPIODRST = BitField<rcc_t, 3, 1, "GPIODRST">{}; // bit offset: 3, bit width: 1, IO port D reset
    constexpr auto GPIOERST = BitField<rcc_t, 4, 1, "GPIOERST">{}; // bit offset: 4, bit width: 1, IO port E reset
    constexpr auto GPIOFRST = BitField<rcc_t, 5, 1, "GPIOFRST">{}; // bit offset: 5, bit width: 1, IO port F reset
    constexpr auto GPIOGRST = BitField<rcc_t, 6, 1, "GPIOGRST">{}; // bit offset: 6, bit width: 1, IO port G reset
    constexpr auto GPIOHRST = BitField<rcc_t, 7, 1, "GPIOHRST">{}; // bit offset: 7, bit width: 1, IO port H reset
    constexpr auto GPIOIRST = BitField<rcc_t, 8, 1, "GPIOIRST">{}; // bit offset: 8, bit width: 1, IO port I reset
    constexpr auto CRCRST = BitField<rcc_t, 12, 1, "CRCRST">{}; // bit offset: 12, bit width: 1, CRC reset
    constexpr auto DMA1RST = BitField<rcc_t, 21, 1, "DMA1RST">{}; // bit offset: 21, bit width: 1, DMA2 reset
    constexpr auto DMA2RST = BitField<rcc_t, 22, 1, "DMA2RST">{}; // bit offset: 22, bit width: 1, DMA2 reset
    constexpr auto ETHMACRST = BitField<rcc_t, 25, 1, "ETHMACRST">{}; // bit offset: 25, bit width: 1, Ethernet MAC reset
    constexpr auto OTGHSRST = BitField<rcc_t, 29, 1, "OTGHSRST">{}; // bit offset: 29, bit width: 1, USB OTG HS module reset
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000010u, 0, READWRITE, "AHB1RSTR", decltype(GPIOARST), decltype(GPIOBRST), decltype(GPIOCRST), decltype(GPIODRST), decltype(GPIOERST), decltype(GPIOFRST), decltype(GPIOGRST), decltype(GPIOHRST), decltype(GPIOIRST), decltype(CRCRST), decltype(DMA1RST), decltype(DMA2RST), decltype(ETHMACRST), decltype(OTGHSRST)> AHB1RSTR; // AHB1 peripheral reset register

    constexpr auto DCMIRST = BitField<rcc_t, 0, 1, "DCMIRST">{}; // bit offset: 0, bit width: 1, Camera interface reset
    constexpr auto RNGRST = BitField<rcc_t, 6, 1, "RNGRST">{}; // bit offset: 6, bit width: 1, Random number generator module reset
    constexpr auto OTGFSRST = BitField<rcc_t, 7, 1, "OTGFSRST">{}; // bit offset: 7, bit width: 1, USB OTG FS module reset
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000014u, 0, READWRITE, "AHB2RSTR", decltype(DCMIRST), decltype(RNGRST), decltype(OTGFSRST)> AHB2RSTR; // AHB2 peripheral reset register

    constexpr auto FSMCRST = BitField<rcc_t, 0, 1, "FSMCRST">{}; // bit offset: 0, bit width: 1, Flexible static memory controller module reset
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000018u, 0, READWRITE, "AHB3RSTR", decltype(FSMCRST)> AHB3RSTR; // AHB3 peripheral reset register

    constexpr auto TIM2RST = BitField<rcc_t, 0, 1, "TIM2RST">{}; // bit offset: 0, bit width: 1, TIM2 reset
    constexpr auto TIM3RST = BitField<rcc_t, 1, 1, "TIM3RST">{}; // bit offset: 1, bit width: 1, TIM3 reset
    constexpr auto TIM4RST = BitField<rcc_t, 2, 1, "TIM4RST">{}; // bit offset: 2, bit width: 1, TIM4 reset
    constexpr auto TIM5RST = BitField<rcc_t, 3, 1, "TIM5RST">{}; // bit offset: 3, bit width: 1, TIM5 reset
    constexpr auto TIM6RST = BitField<rcc_t, 4, 1, "TIM6RST">{}; // bit offset: 4, bit width: 1, TIM6 reset
    constexpr auto TIM7RST = BitField<rcc_t, 5, 1, "TIM7RST">{}; // bit offset: 5, bit width: 1, TIM7 reset
    constexpr auto TIM12RST = BitField<rcc_t, 6, 1, "TIM12RST">{}; // bit offset: 6, bit width: 1, TIM12 reset
    constexpr auto TIM13RST = BitField<rcc_t, 7, 1, "TIM13RST">{}; // bit offset: 7, bit width: 1, TIM13 reset
    constexpr auto TIM14RST = BitField<rcc_t, 8, 1, "TIM14RST">{}; // bit offset: 8, bit width: 1, TIM14 reset
    constexpr auto WWDGRST = BitField<rcc_t, 11, 1, "WWDGRST">{}; // bit offset: 11, bit width: 1, Window watchdog reset
    constexpr auto SPI2RST = BitField<rcc_t, 14, 1, "SPI2RST">{}; // bit offset: 14, bit width: 1, SPI 2 reset
    constexpr auto SPI3RST = BitField<rcc_t, 15, 1, "SPI3RST">{}; // bit offset: 15, bit width: 1, SPI 3 reset
    constexpr auto UART2RST = BitField<rcc_t, 17, 1, "UART2RST">{}; // bit offset: 17, bit width: 1, USART 2 reset
    constexpr auto UART3RST = BitField<rcc_t, 18, 1, "UART3RST">{}; // bit offset: 18, bit width: 1, USART 3 reset
    constexpr auto UART4RST = BitField<rcc_t, 19, 1, "UART4RST">{}; // bit offset: 19, bit width: 1, USART 4 reset
    constexpr auto UART5RST = BitField<rcc_t, 20, 1, "UART5RST">{}; // bit offset: 20, bit width: 1, USART 5 reset
    constexpr auto I2C1RST = BitField<rcc_t, 21, 1, "I2C1RST">{}; // bit offset: 21, bit width: 1, I2C 1 reset
    constexpr auto I2C2RST = BitField<rcc_t, 22, 1, "I2C2RST">{}; // bit offset: 22, bit width: 1, I2C 2 reset
    constexpr auto I2C3RST = BitField<rcc_t, 23, 1, "I2C3RST">{}; // bit offset: 23, bit width: 1, I2C3 reset
    constexpr auto CAN1RST = BitField<rcc_t, 25, 1, "CAN1RST">{}; // bit offset: 25, bit width: 1, CAN1 reset
    constexpr auto CAN2RST = BitField<rcc_t, 26, 1, "CAN2RST">{}; // bit offset: 26, bit width: 1, CAN2 reset
    constexpr auto PWRRST = BitField<rcc_t, 28, 1, "PWRRST">{}; // bit offset: 28, bit width: 1, Power interface reset
    constexpr auto DACRST = BitField<rcc_t, 29, 1, "DACRST">{}; // bit offset: 29, bit width: 1, DAC reset
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000020u, 0, READWRITE, "APB1RSTR", decltype(TIM2RST), decltype(TIM3RST), decltype(TIM4RST), decltype(TIM5RST), decltype(TIM6RST), decltype(TIM7RST), decltype(TIM12RST), decltype(TIM13RST), decltype(TIM14RST), decltype(WWDGRST), decltype(SPI2RST), decltype(SPI3RST), decltype(UART2RST), decltype(UART3RST), decltype(UART4RST), decltype(UART5RST), decltype(I2C1RST), decltype(I2C2RST), decltype(I2C3RST), decltype(CAN1RST), decltype(CAN2RST), decltype(PWRRST), decltype(DACRST)> APB1RSTR; // APB1 peripheral reset register

    constexpr auto TIM1RST = BitField<rcc_t, 0, 1, "TIM1RST">{}; // bit offset: 0, bit width: 1, TIM1 reset
    constexpr auto TIM8RST = BitField<rcc_t, 1, 1, "TIM8RST">{}; // bit offset: 1, bit width: 1, TIM8 reset
    constexpr auto USART1RST = BitField<rcc_t, 4, 1, "USART1RST">{}; // bit offset: 4, bit width: 1, USART1 reset
    constexpr auto USART6RST = BitField<rcc_t, 5, 1, "USART6RST">{}; // bit offset: 5, bit width: 1, USART6 reset
    constexpr auto ADCRST = BitField<rcc_t, 8, 1, "ADCRST">{}; // bit offset: 8, bit width: 1, ADC interface reset (common to all ADCs)
    constexpr auto SDIORST = BitField<rcc_t, 11, 1, "SDIORST">{}; // bit offset: 11, bit width: 1, SDIO reset
    constexpr auto SPI1RST = BitField<rcc_t, 12, 1, "SPI1RST">{}; // bit offset: 12, bit width: 1, SPI 1 reset
    constexpr auto SYSCFGRST = BitField<rcc_t, 14, 1, "SYSCFGRST">{}; // bit offset: 14, bit width: 1, System configuration controller reset
    constexpr auto TIM9RST = BitField<rcc_t, 16, 1, "TIM9RST">{}; // bit offset: 16, bit width: 1, TIM9 reset
    constexpr auto TIM10RST = BitField<rcc_t, 17, 1, "TIM10RST">{}; // bit offset: 17, bit width: 1, TIM10 reset
    constexpr auto TIM11RST = BitField<rcc_t, 18, 1, "TIM11RST">{}; // bit offset: 18, bit width: 1, TIM11 reset
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000024u, 0, READWRITE, "APB2RSTR", decltype(TIM1RST), decltype(TIM8RST), decltype(USART1RST), decltype(USART6RST), decltype(ADCRST), decltype(SDIORST), decltype(SPI1RST), decltype(SYSCFGRST), decltype(TIM9RST), decltype(TIM10RST), decltype(TIM11RST)> APB2RSTR; // APB2 peripheral reset register

    constexpr auto GPIOAEN = BitField<rcc_t, 0, 1, "GPIOAEN">{}; // bit offset: 0, bit width: 1, IO port A clock enable
    constexpr auto GPIOBEN = BitField<rcc_t, 1, 1, "GPIOBEN">{}; // bit offset: 1, bit width: 1, IO port B clock enable
    constexpr auto GPIOCEN = BitField<rcc_t, 2, 1, "GPIOCEN">{}; // bit offset: 2, bit width: 1, IO port C clock enable
    constexpr auto GPIODEN = BitField<rcc_t, 3, 1, "GPIODEN">{}; // bit offset: 3, bit width: 1, IO port D clock enable
    constexpr auto GPIOEEN = BitField<rcc_t, 4, 1, "GPIOEEN">{}; // bit offset: 4, bit width: 1, IO port E clock enable
    constexpr auto GPIOFEN = BitField<rcc_t, 5, 1, "GPIOFEN">{}; // bit offset: 5, bit width: 1, IO port F clock enable
    constexpr auto GPIOGEN = BitField<rcc_t, 6, 1, "GPIOGEN">{}; // bit offset: 6, bit width: 1, IO port G clock enable
    constexpr auto GPIOHEN = BitField<rcc_t, 7, 1, "GPIOHEN">{}; // bit offset: 7, bit width: 1, IO port H clock enable
    constexpr auto GPIOIEN = BitField<rcc_t, 8, 1, "GPIOIEN">{}; // bit offset: 8, bit width: 1, IO port I clock enable
    constexpr auto CRCEN = BitField<rcc_t, 12, 1, "CRCEN">{}; // bit offset: 12, bit width: 1, CRC clock enable
    constexpr auto BKPSRAMEN = BitField<rcc_t, 18, 1, "BKPSRAMEN">{}; // bit offset: 18, bit width: 1, Backup SRAM interface clock enable
    constexpr auto DMA1EN = BitField<rcc_t, 21, 1, "DMA1EN">{}; // bit offset: 21, bit width: 1, DMA1 clock enable
    constexpr auto DMA2EN = BitField<rcc_t, 22, 1, "DMA2EN">{}; // bit offset: 22, bit width: 1, DMA2 clock enable
    constexpr auto ETHMACEN = BitField<rcc_t, 25, 1, "ETHMACEN">{}; // bit offset: 25, bit width: 1, Ethernet MAC clock enable
    constexpr auto ETHMACTXEN = BitField<rcc_t, 26, 1, "ETHMACTXEN">{}; // bit offset: 26, bit width: 1, Ethernet Transmission clock enable
    constexpr auto ETHMACRXEN = BitField<rcc_t, 27, 1, "ETHMACRXEN">{}; // bit offset: 27, bit width: 1, Ethernet Reception clock enable
    constexpr auto ETHMACPTPEN = BitField<rcc_t, 28, 1, "ETHMACPTPEN">{}; // bit offset: 28, bit width: 1, Ethernet PTP clock enable
    constexpr auto OTGHSEN = BitField<rcc_t, 29, 1, "OTGHSEN">{}; // bit offset: 29, bit width: 1, USB OTG HS clock enable
    constexpr auto OTGHSULPIEN = BitField<rcc_t, 30, 1, "OTGHSULPIEN">{}; // bit offset: 30, bit width: 1, USB OTG HSULPI clock enable
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000030u, 0, READWRITE, "AHB1ENR", decltype(GPIOAEN), decltype(GPIOBEN), decltype(GPIOCEN), decltype(GPIODEN), decltype(GPIOEEN), decltype(GPIOFEN), decltype(GPIOGEN), decltype(GPIOHEN), decltype(GPIOIEN), decltype(CRCEN), decltype(BKPSRAMEN), decltype(DMA1EN), decltype(DMA2EN), decltype(ETHMACEN), decltype(ETHMACTXEN), decltype(ETHMACRXEN), decltype(ETHMACPTPEN), decltype(OTGHSEN), decltype(OTGHSULPIEN)> AHB1ENR; // AHB1 peripheral clock register

    constexpr auto DCMIEN = BitField<rcc_t, 0, 1, "DCMIEN">{}; // bit offset: 0, bit width: 1, Camera interface enable
    constexpr auto RNGEN = BitField<rcc_t, 6, 1, "RNGEN">{}; // bit offset: 6, bit width: 1, Random number generator clock enable
    constexpr auto OTGFSEN = BitField<rcc_t, 7, 1, "OTGFSEN">{}; // bit offset: 7, bit width: 1, USB OTG FS clock enable
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000034u, 0, READWRITE, "AHB2ENR", decltype(DCMIEN), decltype(RNGEN), decltype(OTGFSEN)> AHB2ENR; // AHB2 peripheral clock enable register

    constexpr auto FSMCEN = BitField<rcc_t, 0, 1, "FSMCEN">{}; // bit offset: 0, bit width: 1, Flexible static memory controller module clock enable
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000038u, 0, READWRITE, "AHB3ENR", decltype(FSMCEN)> AHB3ENR; // AHB3 peripheral clock enable register

    constexpr auto TIM2EN = BitField<rcc_t, 0, 1, "TIM2EN">{}; // bit offset: 0, bit width: 1, TIM2 clock enable
    constexpr auto TIM3EN = BitField<rcc_t, 1, 1, "TIM3EN">{}; // bit offset: 1, bit width: 1, TIM3 clock enable
    constexpr auto TIM4EN = BitField<rcc_t, 2, 1, "TIM4EN">{}; // bit offset: 2, bit width: 1, TIM4 clock enable
    constexpr auto TIM5EN = BitField<rcc_t, 3, 1, "TIM5EN">{}; // bit offset: 3, bit width: 1, TIM5 clock enable
    constexpr auto TIM6EN = BitField<rcc_t, 4, 1, "TIM6EN">{}; // bit offset: 4, bit width: 1, TIM6 clock enable
    constexpr auto TIM7EN = BitField<rcc_t, 5, 1, "TIM7EN">{}; // bit offset: 5, bit width: 1, TIM7 clock enable
    constexpr auto TIM12EN = BitField<rcc_t, 6, 1, "TIM12EN">{}; // bit offset: 6, bit width: 1, TIM12 clock enable
    constexpr auto TIM13EN = BitField<rcc_t, 7, 1, "TIM13EN">{}; // bit offset: 7, bit width: 1, TIM13 clock enable
    constexpr auto TIM14EN = BitField<rcc_t, 8, 1, "TIM14EN">{}; // bit offset: 8, bit width: 1, TIM14 clock enable
    constexpr auto WWDGEN = BitField<rcc_t, 11, 1, "WWDGEN">{}; // bit offset: 11, bit width: 1, Window watchdog clock enable
    constexpr auto SPI2EN = BitField<rcc_t, 14, 1, "SPI2EN">{}; // bit offset: 14, bit width: 1, SPI2 clock enable
    constexpr auto SPI3EN = BitField<rcc_t, 15, 1, "SPI3EN">{}; // bit offset: 15, bit width: 1, SPI3 clock enable
    constexpr auto USART2EN = BitField<rcc_t, 17, 1, "USART2EN">{}; // bit offset: 17, bit width: 1, USART 2 clock enable
    constexpr auto USART3EN = BitField<rcc_t, 18, 1, "USART3EN">{}; // bit offset: 18, bit width: 1, USART3 clock enable
    constexpr auto UART4EN = BitField<rcc_t, 19, 1, "UART4EN">{}; // bit offset: 19, bit width: 1, UART4 clock enable
    constexpr auto UART5EN = BitField<rcc_t, 20, 1, "UART5EN">{}; // bit offset: 20, bit width: 1, UART5 clock enable
    constexpr auto I2C1EN = BitField<rcc_t, 21, 1, "I2C1EN">{}; // bit offset: 21, bit width: 1, I2C1 clock enable
    constexpr auto I2C2EN = BitField<rcc_t, 22, 1, "I2C2EN">{}; // bit offset: 22, bit width: 1, I2C2 clock enable
    constexpr auto I2C3EN = BitField<rcc_t, 23, 1, "I2C3EN">{}; // bit offset: 23, bit width: 1, I2C3 clock enable
    constexpr auto CAN1EN = BitField<rcc_t, 25, 1, "CAN1EN">{}; // bit offset: 25, bit width: 1, CAN 1 clock enable
    constexpr auto CAN2EN = BitField<rcc_t, 26, 1, "CAN2EN">{}; // bit offset: 26, bit width: 1, CAN 2 clock enable
    constexpr auto PWREN = BitField<rcc_t, 28, 1, "PWREN">{}; // bit offset: 28, bit width: 1, Power interface clock enable
    constexpr auto DACEN = BitField<rcc_t, 29, 1, "DACEN">{}; // bit offset: 29, bit width: 1, DAC interface clock enable
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000040u, 0, READWRITE, "APB1ENR", decltype(TIM2EN), decltype(TIM3EN), decltype(TIM4EN), decltype(TIM5EN), decltype(TIM6EN), decltype(TIM7EN), decltype(TIM12EN), decltype(TIM13EN), decltype(TIM14EN), decltype(WWDGEN), decltype(SPI2EN), decltype(SPI3EN), decltype(USART2EN), decltype(USART3EN), decltype(UART4EN), decltype(UART5EN), decltype(I2C1EN), decltype(I2C2EN), decltype(I2C3EN), decltype(CAN1EN), decltype(CAN2EN), decltype(PWREN), decltype(DACEN)> APB1ENR; // APB1 peripheral clock enable register

    constexpr auto TIM1EN = BitField<rcc_t, 0, 1, "TIM1EN">{}; // bit offset: 0, bit width: 1, TIM1 clock enable
    constexpr auto TIM8EN = BitField<rcc_t, 1, 1, "TIM8EN">{}; // bit offset: 1, bit width: 1, TIM8 clock enable
    constexpr auto USART1EN = BitField<rcc_t, 4, 1, "USART1EN">{}; // bit offset: 4, bit width: 1, USART1 clock enable
    constexpr auto USART6EN = BitField<rcc_t, 5, 1, "USART6EN">{}; // bit offset: 5, bit width: 1, USART6 clock enable
    constexpr auto ADC1EN = BitField<rcc_t, 8, 1, "ADC1EN">{}; // bit offset: 8, bit width: 1, ADC1 clock enable
    constexpr auto ADC2EN = BitField<rcc_t, 9, 1, "ADC2EN">{}; // bit offset: 9, bit width: 1, ADC2 clock enable
    constexpr auto ADC3EN = BitField<rcc_t, 10, 1, "ADC3EN">{}; // bit offset: 10, bit width: 1, ADC3 clock enable
    constexpr auto SDIOEN = BitField<rcc_t, 11, 1, "SDIOEN">{}; // bit offset: 11, bit width: 1, SDIO clock enable
    constexpr auto SPI1EN = BitField<rcc_t, 12, 1, "SPI1EN">{}; // bit offset: 12, bit width: 1, SPI1 clock enable
    constexpr auto SYSCFGEN = BitField<rcc_t, 14, 1, "SYSCFGEN">{}; // bit offset: 14, bit width: 1, System configuration controller clock enable
    constexpr auto TIM9EN = BitField<rcc_t, 16, 1, "TIM9EN">{}; // bit offset: 16, bit width: 1, TIM9 clock enable
    constexpr auto TIM10EN = BitField<rcc_t, 17, 1, "TIM10EN">{}; // bit offset: 17, bit width: 1, TIM10 clock enable
    constexpr auto TIM11EN = BitField<rcc_t, 18, 1, "TIM11EN">{}; // bit offset: 18, bit width: 1, TIM11 clock enable
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000044u, 0, READWRITE, "APB2ENR", decltype(TIM1EN), decltype(TIM8EN), decltype(USART1EN), decltype(USART6EN), decltype(ADC1EN), decltype(ADC2EN), decltype(ADC3EN), decltype(SDIOEN), decltype(SPI1EN), decltype(SYSCFGEN), decltype(TIM9EN), decltype(TIM10EN), decltype(TIM11EN)> APB2ENR; // APB2 peripheral clock enable register

    constexpr auto GPIOALPEN = BitField<rcc_t, 0, 1, "GPIOALPEN">{}; // bit offset: 0, bit width: 1, IO port A clock enable during sleep mode
    constexpr auto GPIOBLPEN = BitField<rcc_t, 1, 1, "GPIOBLPEN">{}; // bit offset: 1, bit width: 1, IO port B clock enable during Sleep mode
    constexpr auto GPIOCLPEN = BitField<rcc_t, 2, 1, "GPIOCLPEN">{}; // bit offset: 2, bit width: 1, IO port C clock enable during Sleep mode
    constexpr auto GPIODLPEN = BitField<rcc_t, 3, 1, "GPIODLPEN">{}; // bit offset: 3, bit width: 1, IO port D clock enable during Sleep mode
    constexpr auto GPIOELPEN = BitField<rcc_t, 4, 1, "GPIOELPEN">{}; // bit offset: 4, bit width: 1, IO port E clock enable during Sleep mode
    constexpr auto GPIOFLPEN = BitField<rcc_t, 5, 1, "GPIOFLPEN">{}; // bit offset: 5, bit width: 1, IO port F clock enable during Sleep mode
    constexpr auto GPIOGLPEN = BitField<rcc_t, 6, 1, "GPIOGLPEN">{}; // bit offset: 6, bit width: 1, IO port G clock enable during Sleep mode
    constexpr auto GPIOHLPEN = BitField<rcc_t, 7, 1, "GPIOHLPEN">{}; // bit offset: 7, bit width: 1, IO port H clock enable during Sleep mode
    constexpr auto GPIOILPEN = BitField<rcc_t, 8, 1, "GPIOILPEN">{}; // bit offset: 8, bit width: 1, IO port I clock enable during Sleep mode
    constexpr auto CRCLPEN = BitField<rcc_t, 12, 1, "CRCLPEN">{}; // bit offset: 12, bit width: 1, CRC clock enable during Sleep mode
    constexpr auto FLITFLPEN = BitField<rcc_t, 15, 1, "FLITFLPEN">{}; // bit offset: 15, bit width: 1, Flash interface clock enable during Sleep mode
    constexpr auto SRAM1LPEN = BitField<rcc_t, 16, 1, "SRAM1LPEN">{}; // bit offset: 16, bit width: 1, SRAM 1interface clock enable during Sleep mode
    constexpr auto SRAM2LPEN = BitField<rcc_t, 17, 1, "SRAM2LPEN">{}; // bit offset: 17, bit width: 1, SRAM 2 interface clock enable during Sleep mode
    constexpr auto BKPSRAMLPEN = BitField<rcc_t, 18, 1, "BKPSRAMLPEN">{}; // bit offset: 18, bit width: 1, Backup SRAM interface clock enable during Sleep mode
    constexpr auto DMA1LPEN = BitField<rcc_t, 21, 1, "DMA1LPEN">{}; // bit offset: 21, bit width: 1, DMA1 clock enable during Sleep mode
    constexpr auto DMA2LPEN = BitField<rcc_t, 22, 1, "DMA2LPEN">{}; // bit offset: 22, bit width: 1, DMA2 clock enable during Sleep mode
    constexpr auto ETHMACLPEN = BitField<rcc_t, 25, 1, "ETHMACLPEN">{}; // bit offset: 25, bit width: 1, Ethernet MAC clock enable during Sleep mode
    constexpr auto ETHMACTXLPEN = BitField<rcc_t, 26, 1, "ETHMACTXLPEN">{}; // bit offset: 26, bit width: 1, Ethernet transmission clock enable during Sleep mode
    constexpr auto ETHMACRXLPEN = BitField<rcc_t, 27, 1, "ETHMACRXLPEN">{}; // bit offset: 27, bit width: 1, Ethernet reception clock enable during Sleep mode
    constexpr auto ETHMACPTPLPEN = BitField<rcc_t, 28, 1, "ETHMACPTPLPEN">{}; // bit offset: 28, bit width: 1, Ethernet PTP clock enable during Sleep mode
    constexpr auto OTGHSLPEN = BitField<rcc_t, 29, 1, "OTGHSLPEN">{}; // bit offset: 29, bit width: 1, USB OTG HS clock enable during Sleep mode
    constexpr auto OTGHSULPILPEN = BitField<rcc_t, 30, 1, "OTGHSULPILPEN">{}; // bit offset: 30, bit width: 1, USB OTG HS ULPI clock enable during Sleep mode
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000050u, 2120716799, READWRITE, "AHB1LPENR", decltype(GPIOALPEN), decltype(GPIOBLPEN), decltype(GPIOCLPEN), decltype(GPIODLPEN), decltype(GPIOELPEN), decltype(GPIOFLPEN), decltype(GPIOGLPEN), decltype(GPIOHLPEN), decltype(GPIOILPEN), decltype(CRCLPEN), decltype(FLITFLPEN), decltype(SRAM1LPEN), decltype(SRAM2LPEN), decltype(BKPSRAMLPEN), decltype(DMA1LPEN), decltype(DMA2LPEN), decltype(ETHMACLPEN), decltype(ETHMACTXLPEN), decltype(ETHMACRXLPEN), decltype(ETHMACPTPLPEN), decltype(OTGHSLPEN), decltype(OTGHSULPILPEN)> AHB1LPENR; // AHB1 peripheral clock enable in low power mode register

    constexpr auto DCMILPEN = BitField<rcc_t, 0, 1, "DCMILPEN">{}; // bit offset: 0, bit width: 1, Camera interface enable during Sleep mode
    constexpr auto RNGLPEN = BitField<rcc_t, 6, 1, "RNGLPEN">{}; // bit offset: 6, bit width: 1, Random number generator clock enable during Sleep mode
    constexpr auto OTGFSLPEN = BitField<rcc_t, 7, 1, "OTGFSLPEN">{}; // bit offset: 7, bit width: 1, USB OTG FS clock enable during Sleep mode
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000054u, 241, READWRITE, "AHB2LPENR", decltype(DCMILPEN), decltype(RNGLPEN), decltype(OTGFSLPEN)> AHB2LPENR; // AHB2 peripheral clock enable in low power mode register

    constexpr auto FSMCLPEN = BitField<rcc_t, 0, 1, "FSMCLPEN">{}; // bit offset: 0, bit width: 1, Flexible static memory controller module clock enable during Sleep mode
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000058u, 1, READWRITE, "AHB3LPENR", decltype(FSMCLPEN)> AHB3LPENR; // AHB3 peripheral clock enable in low power mode register

    constexpr auto TIM2LPEN = BitField<rcc_t, 0, 1, "TIM2LPEN">{}; // bit offset: 0, bit width: 1, TIM2 clock enable during Sleep mode
    constexpr auto TIM3LPEN = BitField<rcc_t, 1, 1, "TIM3LPEN">{}; // bit offset: 1, bit width: 1, TIM3 clock enable during Sleep mode
    constexpr auto TIM4LPEN = BitField<rcc_t, 2, 1, "TIM4LPEN">{}; // bit offset: 2, bit width: 1, TIM4 clock enable during Sleep mode
    constexpr auto TIM5LPEN = BitField<rcc_t, 3, 1, "TIM5LPEN">{}; // bit offset: 3, bit width: 1, TIM5 clock enable during Sleep mode
    constexpr auto TIM6LPEN = BitField<rcc_t, 4, 1, "TIM6LPEN">{}; // bit offset: 4, bit width: 1, TIM6 clock enable during Sleep mode
    constexpr auto TIM7LPEN = BitField<rcc_t, 5, 1, "TIM7LPEN">{}; // bit offset: 5, bit width: 1, TIM7 clock enable during Sleep mode
    constexpr auto TIM12LPEN = BitField<rcc_t, 6, 1, "TIM12LPEN">{}; // bit offset: 6, bit width: 1, TIM12 clock enable during Sleep mode
    constexpr auto TIM13LPEN = BitField<rcc_t, 7, 1, "TIM13LPEN">{}; // bit offset: 7, bit width: 1, TIM13 clock enable during Sleep mode
    constexpr auto TIM14LPEN = BitField<rcc_t, 8, 1, "TIM14LPEN">{}; // bit offset: 8, bit width: 1, TIM14 clock enable during Sleep mode
    constexpr auto WWDGLPEN = BitField<rcc_t, 11, 1, "WWDGLPEN">{}; // bit offset: 11, bit width: 1, Window watchdog clock enable during Sleep mode
    constexpr auto SPI2LPEN = BitField<rcc_t, 14, 1, "SPI2LPEN">{}; // bit offset: 14, bit width: 1, SPI2 clock enable during Sleep mode
    constexpr auto SPI3LPEN = BitField<rcc_t, 15, 1, "SPI3LPEN">{}; // bit offset: 15, bit width: 1, SPI3 clock enable during Sleep mode
    constexpr auto USART2LPEN = BitField<rcc_t, 17, 1, "USART2LPEN">{}; // bit offset: 17, bit width: 1, USART2 clock enable during Sleep mode
    constexpr auto USART3LPEN = BitField<rcc_t, 18, 1, "USART3LPEN">{}; // bit offset: 18, bit width: 1, USART3 clock enable during Sleep mode
    constexpr auto UART4LPEN = BitField<rcc_t, 19, 1, "UART4LPEN">{}; // bit offset: 19, bit width: 1, UART4 clock enable during Sleep mode
    constexpr auto UART5LPEN = BitField<rcc_t, 20, 1, "UART5LPEN">{}; // bit offset: 20, bit width: 1, UART5 clock enable during Sleep mode
    constexpr auto I2C1LPEN = BitField<rcc_t, 21, 1, "I2C1LPEN">{}; // bit offset: 21, bit width: 1, I2C1 clock enable during Sleep mode
    constexpr auto I2C2LPEN = BitField<rcc_t, 22, 1, "I2C2LPEN">{}; // bit offset: 22, bit width: 1, I2C2 clock enable during Sleep mode
    constexpr auto I2C3LPEN = BitField<rcc_t, 23, 1, "I2C3LPEN">{}; // bit offset: 23, bit width: 1, I2C3 clock enable during Sleep mode
    constexpr auto CAN1LPEN = BitField<rcc_t, 25, 1, "CAN1LPEN">{}; // bit offset: 25, bit width: 1, CAN 1 clock enable during Sleep mode
    constexpr auto CAN2LPEN = BitField<rcc_t, 26, 1, "CAN2LPEN">{}; // bit offset: 26, bit width: 1, CAN 2 clock enable during Sleep mode
    constexpr auto PWRLPEN = BitField<rcc_t, 28, 1, "PWRLPEN">{}; // bit offset: 28, bit width: 1, Power interface clock enable during Sleep mode
    constexpr auto DACLPEN = BitField<rcc_t, 29, 1, "DACLPEN">{}; // bit offset: 29, bit width: 1, DAC interface clock enable during Sleep mode
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000060u, 922667519, READWRITE, "APB1LPENR", decltype(TIM2LPEN), decltype(TIM3LPEN), decltype(TIM4LPEN), decltype(TIM5LPEN), decltype(TIM6LPEN), decltype(TIM7LPEN), decltype(TIM12LPEN), decltype(TIM13LPEN), decltype(TIM14LPEN), decltype(WWDGLPEN), decltype(SPI2LPEN), decltype(SPI3LPEN), decltype(USART2LPEN), decltype(USART3LPEN), decltype(UART4LPEN), decltype(UART5LPEN), decltype(I2C1LPEN), decltype(I2C2LPEN), decltype(I2C3LPEN), decltype(CAN1LPEN), decltype(CAN2LPEN), decltype(PWRLPEN), decltype(DACLPEN)> APB1LPENR; // APB1 peripheral clock enable in low power mode register

    constexpr auto TIM1LPEN = BitField<rcc_t, 0, 1, "TIM1LPEN">{}; // bit offset: 0, bit width: 1, TIM1 clock enable during Sleep mode
    constexpr auto TIM8LPEN = BitField<rcc_t, 1, 1, "TIM8LPEN">{}; // bit offset: 1, bit width: 1, TIM8 clock enable during Sleep mode
    constexpr auto USART1LPEN = BitField<rcc_t, 4, 1, "USART1LPEN">{}; // bit offset: 4, bit width: 1, USART1 clock enable during Sleep mode
    constexpr auto USART6LPEN = BitField<rcc_t, 5, 1, "USART6LPEN">{}; // bit offset: 5, bit width: 1, USART6 clock enable during Sleep mode
    constexpr auto ADC1LPEN = BitField<rcc_t, 8, 1, "ADC1LPEN">{}; // bit offset: 8, bit width: 1, ADC1 clock enable during Sleep mode
    constexpr auto ADC2LPEN = BitField<rcc_t, 9, 1, "ADC2LPEN">{}; // bit offset: 9, bit width: 1, ADC2 clock enable during Sleep mode
    constexpr auto ADC3LPEN = BitField<rcc_t, 10, 1, "ADC3LPEN">{}; // bit offset: 10, bit width: 1, ADC 3 clock enable during Sleep mode
    constexpr auto SDIOLPEN = BitField<rcc_t, 11, 1, "SDIOLPEN">{}; // bit offset: 11, bit width: 1, SDIO clock enable during Sleep mode
    constexpr auto SPI1LPEN = BitField<rcc_t, 12, 1, "SPI1LPEN">{}; // bit offset: 12, bit width: 1, SPI 1 clock enable during Sleep mode
    constexpr auto SYSCFGLPEN = BitField<rcc_t, 14, 1, "SYSCFGLPEN">{}; // bit offset: 14, bit width: 1, System configuration controller clock enable during Sleep mode
    constexpr auto TIM9LPEN = BitField<rcc_t, 16, 1, "TIM9LPEN">{}; // bit offset: 16, bit width: 1, TIM9 clock enable during sleep mode
    constexpr auto TIM10LPEN = BitField<rcc_t, 17, 1, "TIM10LPEN">{}; // bit offset: 17, bit width: 1, TIM10 clock enable during Sleep mode
    constexpr auto TIM11LPEN = BitField<rcc_t, 18, 1, "TIM11LPEN">{}; // bit offset: 18, bit width: 1, TIM11 clock enable during Sleep mode
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000064u, 483123, READWRITE, "APB2LPENR", decltype(TIM1LPEN), decltype(TIM8LPEN), decltype(USART1LPEN), decltype(USART6LPEN), decltype(ADC1LPEN), decltype(ADC2LPEN), decltype(ADC3LPEN), decltype(SDIOLPEN), decltype(SPI1LPEN), decltype(SYSCFGLPEN), decltype(TIM9LPEN), decltype(TIM10LPEN), decltype(TIM11LPEN)> APB2LPENR; // APB2 peripheral clock enabled in low power mode register

    constexpr auto LSEON = BitField<rcc_t, 0, 1, "LSEON", READWRITE>{}; // bit offset: 0, bit width: 1, External low-speed oscillator enable
    constexpr auto LSERDY = BitField<rcc_t, 1, 1, "LSERDY", READONLY>{}; // bit offset: 1, bit width: 1, External low-speed oscillator ready
    constexpr auto LSEBYP = BitField<rcc_t, 2, 1, "LSEBYP", READWRITE>{}; // bit offset: 2, bit width: 1, External low-speed oscillator bypass
    constexpr auto RTCSEL0 = BitField<rcc_t, 8, 1, "RTCSEL0", READWRITE>{}; // bit offset: 8, bit width: 1, RTC clock source selection
    constexpr auto RTCSEL1 = BitField<rcc_t, 9, 1, "RTCSEL1", READWRITE>{}; // bit offset: 9, bit width: 1, RTC clock source selection
    constexpr auto RTCEN = BitField<rcc_t, 15, 1, "RTCEN", READWRITE>{}; // bit offset: 15, bit width: 1, RTC clock enable
    constexpr auto BDRST = BitField<rcc_t, 16, 1, "BDRST", READWRITE>{}; // bit offset: 16, bit width: 1, Backup domain software reset
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000070u, 0, READWRITE, "BDCR", decltype(LSEON), decltype(LSERDY), decltype(LSEBYP), decltype(RTCSEL0), decltype(RTCSEL1), decltype(RTCEN), decltype(BDRST)> BDCR; // Backup domain control register

    constexpr auto LSION = BitField<rcc_t, 0, 1, "LSION", READWRITE>{}; // bit offset: 0, bit width: 1, Internal low-speed oscillator enable
    constexpr auto LSIRDY = BitField<rcc_t, 1, 1, "LSIRDY", READONLY>{}; // bit offset: 1, bit width: 1, Internal low-speed oscillator ready
    constexpr auto RMVF = BitField<rcc_t, 24, 1, "RMVF", READWRITE>{}; // bit offset: 24, bit width: 1, Remove reset flag
    constexpr auto BORRSTF = BitField<rcc_t, 25, 1, "BORRSTF", READWRITE>{}; // bit offset: 25, bit width: 1, BOR reset flag
    constexpr auto PINRSTF = BitField<rcc_t, 26, 1, "PINRSTF", READWRITE>{}; // bit offset: 26, bit width: 1, PIN reset flag
    constexpr auto PORRSTF = BitField<rcc_t, 27, 1, "PORRSTF", READWRITE>{}; // bit offset: 27, bit width: 1, POR/PDR reset flag
    constexpr auto SFTRSTF = BitField<rcc_t, 28, 1, "SFTRSTF", READWRITE>{}; // bit offset: 28, bit width: 1, Software reset flag
    constexpr auto WDGRSTF = BitField<rcc_t, 29, 1, "WDGRSTF", READWRITE>{}; // bit offset: 29, bit width: 1, Independent watchdog reset flag
    constexpr auto WWDGRSTF = BitField<rcc_t, 30, 1, "WWDGRSTF", READWRITE>{}; // bit offset: 30, bit width: 1, Window watchdog reset flag
    constexpr auto LPWRRSTF = BitField<rcc_t, 31, 1, "LPWRRSTF", READWRITE>{}; // bit offset: 31, bit width: 1, Low-power reset flag
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000074u, 234881024, READWRITE, "CSR", decltype(LSION), decltype(LSIRDY), decltype(RMVF), decltype(BORRSTF), decltype(PINRSTF), decltype(PORRSTF), decltype(SFTRSTF), decltype(WDGRSTF), decltype(WWDGRSTF), decltype(LPWRRSTF)> CSR; // clock control & status register

    constexpr auto MODPER = BitField<rcc_t, 0, 13, "MODPER">{}; // bit offset: 0, bit width: 13, Modulation period
    constexpr auto INCSTEP = BitField<rcc_t, 13, 15, "INCSTEP">{}; // bit offset: 13, bit width: 15, Incrementation step
    constexpr auto SPREADSEL = BitField<rcc_t, 30, 1, "SPREADSEL">{}; // bit offset: 30, bit width: 1, Spread Select
    constexpr auto SSCGEN = BitField<rcc_t, 31, 1, "SSCGEN">{}; // bit offset: 31, bit width: 1, Spread spectrum modulation enable
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000080u, 0, READWRITE, "SSCGR", decltype(MODPER), decltype(INCSTEP), decltype(SPREADSEL), decltype(SSCGEN)> SSCGR; // spread spectrum clock generation register

    constexpr auto PLLI2SN0 = BitField<rcc_t, 6, 1, "PLLI2SN0">{}; // bit offset: 6, bit width: 1, PLLI2S multiplication factor for VCO
    constexpr auto PLLI2SN1 = BitField<rcc_t, 7, 1, "PLLI2SN1">{}; // bit offset: 7, bit width: 1, PLLI2S multiplication factor for VCO
    constexpr auto PLLI2SN2 = BitField<rcc_t, 8, 1, "PLLI2SN2">{}; // bit offset: 8, bit width: 1, PLLI2S multiplication factor for VCO
    constexpr auto PLLI2SN3 = BitField<rcc_t, 9, 1, "PLLI2SN3">{}; // bit offset: 9, bit width: 1, PLLI2S multiplication factor for VCO
    constexpr auto PLLI2SN4 = BitField<rcc_t, 10, 1, "PLLI2SN4">{}; // bit offset: 10, bit width: 1, PLLI2S multiplication factor for VCO
    constexpr auto PLLI2SN5 = BitField<rcc_t, 11, 1, "PLLI2SN5">{}; // bit offset: 11, bit width: 1, PLLI2S multiplication factor for VCO
    constexpr auto PLLI2SN6 = BitField<rcc_t, 12, 1, "PLLI2SN6">{}; // bit offset: 12, bit width: 1, PLLI2S multiplication factor for VCO
    constexpr auto PLLI2SN7 = BitField<rcc_t, 13, 1, "PLLI2SN7">{}; // bit offset: 13, bit width: 1, PLLI2S multiplication factor for VCO
    constexpr auto PLLI2SN8 = BitField<rcc_t, 14, 1, "PLLI2SN8">{}; // bit offset: 14, bit width: 1, PLLI2S multiplication factor for VCO
    constexpr auto PLLI2SR0 = BitField<rcc_t, 28, 1, "PLLI2SR0">{}; // bit offset: 28, bit width: 1, PLLI2S division factor for I2S clocks
    constexpr auto PLLI2SR1 = BitField<rcc_t, 29, 1, "PLLI2SR1">{}; // bit offset: 29, bit width: 1, PLLI2S division factor for I2S clocks
    constexpr auto PLLI2SR2 = BitField<rcc_t, 30, 1, "PLLI2SR2">{}; // bit offset: 30, bit width: 1, PLLI2S division factor for I2S clocks
    static Register<std::uint32_t, RCC_BASE_ADDRESS + 0x00000084u, 536883200, READWRITE, "PLLI2SCFGR", decltype(PLLI2SN0), decltype(PLLI2SN1), decltype(PLLI2SN2), decltype(PLLI2SN3), decltype(PLLI2SN4), decltype(PLLI2SN5), decltype(PLLI2SN6), decltype(PLLI2SN7), decltype(PLLI2SN8), decltype(PLLI2SR0), decltype(PLLI2SR1), decltype(PLLI2SR2)> PLLI2SCFGR; // PLLI2S configuration register

} // namespace RCC