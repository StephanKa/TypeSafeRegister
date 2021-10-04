#include <Register.hpp>

namespace TIM8
{
    struct tim8_t{};

    constexpr std::uint32_t TIM8_BASE_ADDRESS = 0x40010400u;

    constexpr auto CEN = BitField<tim8_t, 0, 1, "CEN">{}; // bit offset: 0, bit width: 1, Counter enable
    constexpr auto UDIS = BitField<tim8_t, 1, 1, "UDIS">{}; // bit offset: 1, bit width: 1, Update disable
    constexpr auto URS = BitField<tim8_t, 2, 1, "URS">{}; // bit offset: 2, bit width: 1, Update request source
    constexpr auto OPM = BitField<tim8_t, 3, 1, "OPM">{}; // bit offset: 3, bit width: 1, One-pulse mode
    constexpr auto DIR = BitField<tim8_t, 4, 1, "DIR">{}; // bit offset: 4, bit width: 1, Direction
    constexpr auto CMS = BitField<tim8_t, 5, 2, "CMS">{}; // bit offset: 5, bit width: 2, Center-aligned mode selection
    constexpr auto ARPE = BitField<tim8_t, 7, 1, "ARPE">{}; // bit offset: 7, bit width: 1, Auto-reload preload enable
    constexpr auto CKD = BitField<tim8_t, 8, 2, "CKD">{}; // bit offset: 8, bit width: 2, Clock division
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x00000000u, 0, READWRITE, "CR1", decltype(CEN), decltype(UDIS), decltype(URS), decltype(OPM), decltype(DIR), decltype(CMS), decltype(ARPE), decltype(CKD)> CR1; // control register 1

    constexpr auto CCPC = BitField<tim8_t, 0, 1, "CCPC">{}; // bit offset: 0, bit width: 1, Capture/compare preloaded control
    constexpr auto CCUS = BitField<tim8_t, 2, 1, "CCUS">{}; // bit offset: 2, bit width: 1, Capture/compare control update selection
    constexpr auto CCDS = BitField<tim8_t, 3, 1, "CCDS">{}; // bit offset: 3, bit width: 1, Capture/compare DMA selection
    constexpr auto MMS = BitField<tim8_t, 4, 3, "MMS">{}; // bit offset: 4, bit width: 3, Master mode selection
    constexpr auto TI1S = BitField<tim8_t, 7, 1, "TI1S">{}; // bit offset: 7, bit width: 1, TI1 selection
    constexpr auto OIS1 = BitField<tim8_t, 8, 1, "OIS1">{}; // bit offset: 8, bit width: 1, Output Idle state 1
    constexpr auto OIS1N = BitField<tim8_t, 9, 1, "OIS1N">{}; // bit offset: 9, bit width: 1, Output Idle state 1
    constexpr auto OIS2 = BitField<tim8_t, 10, 1, "OIS2">{}; // bit offset: 10, bit width: 1, Output Idle state 2
    constexpr auto OIS2N = BitField<tim8_t, 11, 1, "OIS2N">{}; // bit offset: 11, bit width: 1, Output Idle state 2
    constexpr auto OIS3 = BitField<tim8_t, 12, 1, "OIS3">{}; // bit offset: 12, bit width: 1, Output Idle state 3
    constexpr auto OIS3N = BitField<tim8_t, 13, 1, "OIS3N">{}; // bit offset: 13, bit width: 1, Output Idle state 3
    constexpr auto OIS4 = BitField<tim8_t, 14, 1, "OIS4">{}; // bit offset: 14, bit width: 1, Output Idle state 4
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x00000004u, 0, READWRITE, "CR2", decltype(CCPC), decltype(CCUS), decltype(CCDS), decltype(MMS), decltype(TI1S), decltype(OIS1), decltype(OIS1N), decltype(OIS2), decltype(OIS2N), decltype(OIS3), decltype(OIS3N), decltype(OIS4)> CR2; // control register 2

    constexpr auto SMS = BitField<tim8_t, 0, 3, "SMS">{}; // bit offset: 0, bit width: 3, Slave mode selection
    constexpr auto TS = BitField<tim8_t, 4, 3, "TS">{}; // bit offset: 4, bit width: 3, Trigger selection
    constexpr auto MSM = BitField<tim8_t, 7, 1, "MSM">{}; // bit offset: 7, bit width: 1, Master/Slave mode
    constexpr auto ETF = BitField<tim8_t, 8, 4, "ETF">{}; // bit offset: 8, bit width: 4, External trigger filter
    constexpr auto ETPS = BitField<tim8_t, 12, 2, "ETPS">{}; // bit offset: 12, bit width: 2, External trigger prescaler
    constexpr auto ECE = BitField<tim8_t, 14, 1, "ECE">{}; // bit offset: 14, bit width: 1, External clock enable
    constexpr auto ETP = BitField<tim8_t, 15, 1, "ETP">{}; // bit offset: 15, bit width: 1, External trigger polarity
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x00000008u, 0, READWRITE, "SMCR", decltype(SMS), decltype(TS), decltype(MSM), decltype(ETF), decltype(ETPS), decltype(ECE), decltype(ETP)> SMCR; // slave mode control register

    constexpr auto UIE = BitField<tim8_t, 0, 1, "UIE">{}; // bit offset: 0, bit width: 1, Update interrupt enable
    constexpr auto CC1IE = BitField<tim8_t, 1, 1, "CC1IE">{}; // bit offset: 1, bit width: 1, Capture/Compare 1 interrupt enable
    constexpr auto CC2IE = BitField<tim8_t, 2, 1, "CC2IE">{}; // bit offset: 2, bit width: 1, Capture/Compare 2 interrupt enable
    constexpr auto CC3IE = BitField<tim8_t, 3, 1, "CC3IE">{}; // bit offset: 3, bit width: 1, Capture/Compare 3 interrupt enable
    constexpr auto CC4IE = BitField<tim8_t, 4, 1, "CC4IE">{}; // bit offset: 4, bit width: 1, Capture/Compare 4 interrupt enable
    constexpr auto COMIE = BitField<tim8_t, 5, 1, "COMIE">{}; // bit offset: 5, bit width: 1, COM interrupt enable
    constexpr auto TIE = BitField<tim8_t, 6, 1, "TIE">{}; // bit offset: 6, bit width: 1, Trigger interrupt enable
    constexpr auto BIE = BitField<tim8_t, 7, 1, "BIE">{}; // bit offset: 7, bit width: 1, Break interrupt enable
    constexpr auto UDE = BitField<tim8_t, 8, 1, "UDE">{}; // bit offset: 8, bit width: 1, Update DMA request enable
    constexpr auto CC1DE = BitField<tim8_t, 9, 1, "CC1DE">{}; // bit offset: 9, bit width: 1, Capture/Compare 1 DMA request enable
    constexpr auto CC2DE = BitField<tim8_t, 10, 1, "CC2DE">{}; // bit offset: 10, bit width: 1, Capture/Compare 2 DMA request enable
    constexpr auto CC3DE = BitField<tim8_t, 11, 1, "CC3DE">{}; // bit offset: 11, bit width: 1, Capture/Compare 3 DMA request enable
    constexpr auto CC4DE = BitField<tim8_t, 12, 1, "CC4DE">{}; // bit offset: 12, bit width: 1, Capture/Compare 4 DMA request enable
    constexpr auto COMDE = BitField<tim8_t, 13, 1, "COMDE">{}; // bit offset: 13, bit width: 1, COM DMA request enable
    constexpr auto TDE = BitField<tim8_t, 14, 1, "TDE">{}; // bit offset: 14, bit width: 1, Trigger DMA request enable
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, "DIER", decltype(UIE), decltype(CC1IE), decltype(CC2IE), decltype(CC3IE), decltype(CC4IE), decltype(COMIE), decltype(TIE), decltype(BIE), decltype(UDE), decltype(CC1DE), decltype(CC2DE), decltype(CC3DE), decltype(CC4DE), decltype(COMDE), decltype(TDE)> DIER; // DMA/Interrupt enable register

    constexpr auto UIF = BitField<tim8_t, 0, 1, "UIF">{}; // bit offset: 0, bit width: 1, Update interrupt flag
    constexpr auto CC1IF = BitField<tim8_t, 1, 1, "CC1IF">{}; // bit offset: 1, bit width: 1, Capture/compare 1 interrupt flag
    constexpr auto CC2IF = BitField<tim8_t, 2, 1, "CC2IF">{}; // bit offset: 2, bit width: 1, Capture/Compare 2 interrupt flag
    constexpr auto CC3IF = BitField<tim8_t, 3, 1, "CC3IF">{}; // bit offset: 3, bit width: 1, Capture/Compare 3 interrupt flag
    constexpr auto CC4IF = BitField<tim8_t, 4, 1, "CC4IF">{}; // bit offset: 4, bit width: 1, Capture/Compare 4 interrupt flag
    constexpr auto COMIF = BitField<tim8_t, 5, 1, "COMIF">{}; // bit offset: 5, bit width: 1, COM interrupt flag
    constexpr auto TIF = BitField<tim8_t, 6, 1, "TIF">{}; // bit offset: 6, bit width: 1, Trigger interrupt flag
    constexpr auto BIF = BitField<tim8_t, 7, 1, "BIF">{}; // bit offset: 7, bit width: 1, Break interrupt flag
    constexpr auto CC1OF = BitField<tim8_t, 9, 1, "CC1OF">{}; // bit offset: 9, bit width: 1, Capture/Compare 1 overcapture flag
    constexpr auto CC2OF = BitField<tim8_t, 10, 1, "CC2OF">{}; // bit offset: 10, bit width: 1, Capture/compare 2 overcapture flag
    constexpr auto CC3OF = BitField<tim8_t, 11, 1, "CC3OF">{}; // bit offset: 11, bit width: 1, Capture/Compare 3 overcapture flag
    constexpr auto CC4OF = BitField<tim8_t, 12, 1, "CC4OF">{}; // bit offset: 12, bit width: 1, Capture/Compare 4 overcapture flag
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x00000010u, 0, READWRITE, "SR", decltype(UIF), decltype(CC1IF), decltype(CC2IF), decltype(CC3IF), decltype(CC4IF), decltype(COMIF), decltype(TIF), decltype(BIF), decltype(CC1OF), decltype(CC2OF), decltype(CC3OF), decltype(CC4OF)> SR; // status register

    constexpr auto UG = BitField<tim8_t, 0, 1, "UG">{}; // bit offset: 0, bit width: 1, Update generation
    constexpr auto CC1G = BitField<tim8_t, 1, 1, "CC1G">{}; // bit offset: 1, bit width: 1, Capture/compare 1 generation
    constexpr auto CC2G = BitField<tim8_t, 2, 1, "CC2G">{}; // bit offset: 2, bit width: 1, Capture/compare 2 generation
    constexpr auto CC3G = BitField<tim8_t, 3, 1, "CC3G">{}; // bit offset: 3, bit width: 1, Capture/compare 3 generation
    constexpr auto CC4G = BitField<tim8_t, 4, 1, "CC4G">{}; // bit offset: 4, bit width: 1, Capture/compare 4 generation
    constexpr auto COMG = BitField<tim8_t, 5, 1, "COMG">{}; // bit offset: 5, bit width: 1, Capture/Compare control update generation
    constexpr auto TG = BitField<tim8_t, 6, 1, "TG">{}; // bit offset: 6, bit width: 1, Trigger generation
    constexpr auto BG = BitField<tim8_t, 7, 1, "BG">{}; // bit offset: 7, bit width: 1, Break generation
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x00000014u, 0, WRITEONLY, "EGR", decltype(UG), decltype(CC1G), decltype(CC2G), decltype(CC3G), decltype(CC4G), decltype(COMG), decltype(TG), decltype(BG)> EGR; // event generation register

    constexpr auto CC1S = BitField<tim8_t, 0, 2, "CC1S">{}; // bit offset: 0, bit width: 2, Capture/Compare 1 selection
    constexpr auto OC1FE = BitField<tim8_t, 2, 1, "OC1FE">{}; // bit offset: 2, bit width: 1, Output Compare 1 fast enable
    constexpr auto OC1PE = BitField<tim8_t, 3, 1, "OC1PE">{}; // bit offset: 3, bit width: 1, Output Compare 1 preload enable
    constexpr auto OC1M = BitField<tim8_t, 4, 3, "OC1M">{}; // bit offset: 4, bit width: 3, Output Compare 1 mode
    constexpr auto OC1CE = BitField<tim8_t, 7, 1, "OC1CE">{}; // bit offset: 7, bit width: 1, Output Compare 1 clear enable
    constexpr auto CC2S = BitField<tim8_t, 8, 2, "CC2S">{}; // bit offset: 8, bit width: 2, Capture/Compare 2 selection
    constexpr auto OC2FE = BitField<tim8_t, 10, 1, "OC2FE">{}; // bit offset: 10, bit width: 1, Output Compare 2 fast enable
    constexpr auto OC2PE = BitField<tim8_t, 11, 1, "OC2PE">{}; // bit offset: 11, bit width: 1, Output Compare 2 preload enable
    constexpr auto OC2M = BitField<tim8_t, 12, 3, "OC2M">{}; // bit offset: 12, bit width: 3, Output Compare 2 mode
    constexpr auto OC2CE = BitField<tim8_t, 15, 1, "OC2CE">{}; // bit offset: 15, bit width: 1, Output Compare 2 clear enable
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x00000018u, 0, READWRITE, "CCMR1_OUTPUT", decltype(CC1S), decltype(OC1FE), decltype(OC1PE), decltype(OC1M), decltype(OC1CE), decltype(CC2S), decltype(OC2FE), decltype(OC2PE), decltype(OC2M), decltype(OC2CE)> CCMR1_OUTPUT; // capture/compare mode register (output mode)

    constexpr auto CC1S = BitField<tim8_t, 0, 2, "CC1S">{}; // bit offset: 0, bit width: 2, Capture/Compare 1 selection
    constexpr auto ICPCS = BitField<tim8_t, 2, 2, "ICPCS">{}; // bit offset: 2, bit width: 2, Input capture 1 prescaler
    constexpr auto IC1F = BitField<tim8_t, 4, 4, "IC1F">{}; // bit offset: 4, bit width: 4, Input capture 1 filter
    constexpr auto CC2S = BitField<tim8_t, 8, 2, "CC2S">{}; // bit offset: 8, bit width: 2, Capture/Compare 2 selection
    constexpr auto IC2PCS = BitField<tim8_t, 10, 2, "IC2PCS">{}; // bit offset: 10, bit width: 2, Input capture 2 prescaler
    constexpr auto IC2F = BitField<tim8_t, 12, 4, "IC2F">{}; // bit offset: 12, bit width: 4, Input capture 2 filter
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x00000018u, 0, READWRITE, "CCMR1_INPUT", decltype(CC1S), decltype(ICPCS), decltype(IC1F), decltype(CC2S), decltype(IC2PCS), decltype(IC2F)> CCMR1_INPUT; // capture/compare mode register 1 (input mode)

    constexpr auto CC3S = BitField<tim8_t, 0, 2, "CC3S">{}; // bit offset: 0, bit width: 2, Capture/Compare 3 selection
    constexpr auto OC3FE = BitField<tim8_t, 2, 1, "OC3FE">{}; // bit offset: 2, bit width: 1, Output compare 3 fast enable
    constexpr auto OC3PE = BitField<tim8_t, 3, 1, "OC3PE">{}; // bit offset: 3, bit width: 1, Output compare 3 preload enable
    constexpr auto OC3M = BitField<tim8_t, 4, 3, "OC3M">{}; // bit offset: 4, bit width: 3, Output compare 3 mode
    constexpr auto OC3CE = BitField<tim8_t, 7, 1, "OC3CE">{}; // bit offset: 7, bit width: 1, Output compare 3 clear enable
    constexpr auto CC4S = BitField<tim8_t, 8, 2, "CC4S">{}; // bit offset: 8, bit width: 2, Capture/Compare 4 selection
    constexpr auto OC4FE = BitField<tim8_t, 10, 1, "OC4FE">{}; // bit offset: 10, bit width: 1, Output compare 4 fast enable
    constexpr auto OC4PE = BitField<tim8_t, 11, 1, "OC4PE">{}; // bit offset: 11, bit width: 1, Output compare 4 preload enable
    constexpr auto OC4M = BitField<tim8_t, 12, 3, "OC4M">{}; // bit offset: 12, bit width: 3, Output compare 4 mode
    constexpr auto OC4CE = BitField<tim8_t, 15, 1, "OC4CE">{}; // bit offset: 15, bit width: 1, Output compare 4 clear enable
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x0000001cu, 0, READWRITE, "CCMR2_OUTPUT", decltype(CC3S), decltype(OC3FE), decltype(OC3PE), decltype(OC3M), decltype(OC3CE), decltype(CC4S), decltype(OC4FE), decltype(OC4PE), decltype(OC4M), decltype(OC4CE)> CCMR2_OUTPUT; // capture/compare mode register (output mode)

    constexpr auto CC3S = BitField<tim8_t, 0, 2, "CC3S">{}; // bit offset: 0, bit width: 2, Capture/compare 3 selection
    constexpr auto IC3PSC = BitField<tim8_t, 2, 2, "IC3PSC">{}; // bit offset: 2, bit width: 2, Input capture 3 prescaler
    constexpr auto IC3F = BitField<tim8_t, 4, 4, "IC3F">{}; // bit offset: 4, bit width: 4, Input capture 3 filter
    constexpr auto CC4S = BitField<tim8_t, 8, 2, "CC4S">{}; // bit offset: 8, bit width: 2, Capture/Compare 4 selection
    constexpr auto IC4PSC = BitField<tim8_t, 10, 2, "IC4PSC">{}; // bit offset: 10, bit width: 2, Input capture 4 prescaler
    constexpr auto IC4F = BitField<tim8_t, 12, 4, "IC4F">{}; // bit offset: 12, bit width: 4, Input capture 4 filter
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x0000001cu, 0, READWRITE, "CCMR2_INPUT", decltype(CC3S), decltype(IC3PSC), decltype(IC3F), decltype(CC4S), decltype(IC4PSC), decltype(IC4F)> CCMR2_INPUT; // capture/compare mode register 2 (input mode)

    constexpr auto CC1E = BitField<tim8_t, 0, 1, "CC1E">{}; // bit offset: 0, bit width: 1, Capture/Compare 1 output enable
    constexpr auto CC1P = BitField<tim8_t, 1, 1, "CC1P">{}; // bit offset: 1, bit width: 1, Capture/Compare 1 output Polarity
    constexpr auto CC1NE = BitField<tim8_t, 2, 1, "CC1NE">{}; // bit offset: 2, bit width: 1, Capture/Compare 1 complementary output enable
    constexpr auto CC1NP = BitField<tim8_t, 3, 1, "CC1NP">{}; // bit offset: 3, bit width: 1, Capture/Compare 1 output Polarity
    constexpr auto CC2E = BitField<tim8_t, 4, 1, "CC2E">{}; // bit offset: 4, bit width: 1, Capture/Compare 2 output enable
    constexpr auto CC2P = BitField<tim8_t, 5, 1, "CC2P">{}; // bit offset: 5, bit width: 1, Capture/Compare 2 output Polarity
    constexpr auto CC2NE = BitField<tim8_t, 6, 1, "CC2NE">{}; // bit offset: 6, bit width: 1, Capture/Compare 2 complementary output enable
    constexpr auto CC2NP = BitField<tim8_t, 7, 1, "CC2NP">{}; // bit offset: 7, bit width: 1, Capture/Compare 2 output Polarity
    constexpr auto CC3E = BitField<tim8_t, 8, 1, "CC3E">{}; // bit offset: 8, bit width: 1, Capture/Compare 3 output enable
    constexpr auto CC3P = BitField<tim8_t, 9, 1, "CC3P">{}; // bit offset: 9, bit width: 1, Capture/Compare 3 output Polarity
    constexpr auto CC3NE = BitField<tim8_t, 10, 1, "CC3NE">{}; // bit offset: 10, bit width: 1, Capture/Compare 3 complementary output enable
    constexpr auto CC3NP = BitField<tim8_t, 11, 1, "CC3NP">{}; // bit offset: 11, bit width: 1, Capture/Compare 3 output Polarity
    constexpr auto CC4E = BitField<tim8_t, 12, 1, "CC4E">{}; // bit offset: 12, bit width: 1, Capture/Compare 4 output enable
    constexpr auto CC4P = BitField<tim8_t, 13, 1, "CC4P">{}; // bit offset: 13, bit width: 1, Capture/Compare 3 output Polarity
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x00000020u, 0, READWRITE, "CCER", decltype(CC1E), decltype(CC1P), decltype(CC1NE), decltype(CC1NP), decltype(CC2E), decltype(CC2P), decltype(CC2NE), decltype(CC2NP), decltype(CC3E), decltype(CC3P), decltype(CC3NE), decltype(CC3NP), decltype(CC4E), decltype(CC4P)> CCER; // capture/compare enable register

    constexpr auto CNT_ = BitField<tim8_t, 0, 16, "CNT">{}; // bit offset: 0, bit width: 16, counter value
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x00000024u, 0, READWRITE, "CNT", decltype(CNT_)> CNT; // counter

    constexpr auto PSC_ = BitField<tim8_t, 0, 16, "PSC">{}; // bit offset: 0, bit width: 16, Prescaler value
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x00000028u, 0, READWRITE, "PSC", decltype(PSC_)> PSC; // prescaler

    constexpr auto ARR_ = BitField<tim8_t, 0, 16, "ARR">{}; // bit offset: 0, bit width: 16, Auto-reload value
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x0000002cu, 0, READWRITE, "ARR", decltype(ARR_)> ARR; // auto-reload register

    constexpr auto CCR1_ = BitField<tim8_t, 0, 16, "CCR1">{}; // bit offset: 0, bit width: 16, Capture/Compare 1 value
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x00000034u, 0, READWRITE, "CCR1", decltype(CCR1_)> CCR1; // capture/compare register 1

    constexpr auto CCR2_ = BitField<tim8_t, 0, 16, "CCR2">{}; // bit offset: 0, bit width: 16, Capture/Compare 2 value
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x00000038u, 0, READWRITE, "CCR2", decltype(CCR2_)> CCR2; // capture/compare register 2

    constexpr auto CCR3_ = BitField<tim8_t, 0, 16, "CCR3">{}; // bit offset: 0, bit width: 16, Capture/Compare value
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x0000003cu, 0, READWRITE, "CCR3", decltype(CCR3_)> CCR3; // capture/compare register 3

    constexpr auto CCR4_ = BitField<tim8_t, 0, 16, "CCR4">{}; // bit offset: 0, bit width: 16, Capture/Compare value
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x00000040u, 0, READWRITE, "CCR4", decltype(CCR4_)> CCR4; // capture/compare register 4

    constexpr auto DBA = BitField<tim8_t, 0, 5, "DBA">{}; // bit offset: 0, bit width: 5, DMA base address
    constexpr auto DBL = BitField<tim8_t, 8, 5, "DBL">{}; // bit offset: 8, bit width: 5, DMA burst length
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x00000048u, 0, READWRITE, "DCR", decltype(DBA), decltype(DBL)> DCR; // DMA control register

    constexpr auto DMAB = BitField<tim8_t, 0, 16, "DMAB">{}; // bit offset: 0, bit width: 16, DMA register for burst accesses
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x0000004cu, 0, READWRITE, "DMAR", decltype(DMAB)> DMAR; // DMA address for full transfer

    constexpr auto REP = BitField<tim8_t, 0, 8, "REP">{}; // bit offset: 0, bit width: 8, Repetition counter value
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x00000030u, 0, READWRITE, "RCR", decltype(REP)> RCR; // repetition counter register

    constexpr auto DTG = BitField<tim8_t, 0, 8, "DTG">{}; // bit offset: 0, bit width: 8, Dead-time generator setup
    constexpr auto LOCK = BitField<tim8_t, 8, 2, "LOCK">{}; // bit offset: 8, bit width: 2, Lock configuration
    constexpr auto OSSI = BitField<tim8_t, 10, 1, "OSSI">{}; // bit offset: 10, bit width: 1, Off-state selection for Idle mode
    constexpr auto OSSR = BitField<tim8_t, 11, 1, "OSSR">{}; // bit offset: 11, bit width: 1, Off-state selection for Run mode
    constexpr auto BKE = BitField<tim8_t, 12, 1, "BKE">{}; // bit offset: 12, bit width: 1, Break enable
    constexpr auto BKP = BitField<tim8_t, 13, 1, "BKP">{}; // bit offset: 13, bit width: 1, Break polarity
    constexpr auto AOE = BitField<tim8_t, 14, 1, "AOE">{}; // bit offset: 14, bit width: 1, Automatic output enable
    constexpr auto MOE = BitField<tim8_t, 15, 1, "MOE">{}; // bit offset: 15, bit width: 1, Main output enable
    static Register<std::uint32_t, TIM8_BASE_ADDRESS + 0x00000044u, 0, READWRITE, "BDTR", decltype(DTG), decltype(LOCK), decltype(OSSI), decltype(OSSR), decltype(BKE), decltype(BKP), decltype(AOE), decltype(MOE)> BDTR; // break and dead-time register

} // namespace TIM8