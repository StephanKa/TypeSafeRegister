#include <Register.hpp>

namespace I2C2
{
    struct i2c2_t{};

    constexpr std::uint32_t I2C2_BASE_ADDRESS = 0x40005800u;

    constexpr auto PE = BitField<i2c2_t, 0, 1, "PE">{}; // bit offset: 0, bit width: 1, Peripheral enable
    constexpr auto SMBUS = BitField<i2c2_t, 1, 1, "SMBUS">{}; // bit offset: 1, bit width: 1, SMBus mode
    constexpr auto SMBTYPE = BitField<i2c2_t, 3, 1, "SMBTYPE">{}; // bit offset: 3, bit width: 1, SMBus type
    constexpr auto ENARP = BitField<i2c2_t, 4, 1, "ENARP">{}; // bit offset: 4, bit width: 1, ARP enable
    constexpr auto ENPEC = BitField<i2c2_t, 5, 1, "ENPEC">{}; // bit offset: 5, bit width: 1, PEC enable
    constexpr auto ENGC = BitField<i2c2_t, 6, 1, "ENGC">{}; // bit offset: 6, bit width: 1, General call enable
    constexpr auto NOSTRETCH = BitField<i2c2_t, 7, 1, "NOSTRETCH">{}; // bit offset: 7, bit width: 1, Clock stretching disable (Slave mode)
    constexpr auto START = BitField<i2c2_t, 8, 1, "START">{}; // bit offset: 8, bit width: 1, Start generation
    constexpr auto STOP = BitField<i2c2_t, 9, 1, "STOP">{}; // bit offset: 9, bit width: 1, Stop generation
    constexpr auto ACK = BitField<i2c2_t, 10, 1, "ACK">{}; // bit offset: 10, bit width: 1, Acknowledge enable
    constexpr auto POS = BitField<i2c2_t, 11, 1, "POS">{}; // bit offset: 11, bit width: 1, Acknowledge/PEC Position (for data reception)
    constexpr auto PEC = BitField<i2c2_t, 12, 1, "PEC">{}; // bit offset: 12, bit width: 1, Packet error checking
    constexpr auto ALERT = BitField<i2c2_t, 13, 1, "ALERT">{}; // bit offset: 13, bit width: 1, SMBus alert
    constexpr auto SWRST = BitField<i2c2_t, 15, 1, "SWRST">{}; // bit offset: 15, bit width: 1, Software reset
    static Register<std::uint32_t, I2C2_BASE_ADDRESS + 0x00000000u, 0, READWRITE, "CR1", decltype(PE), decltype(SMBUS), decltype(SMBTYPE), decltype(ENARP), decltype(ENPEC), decltype(ENGC), decltype(NOSTRETCH), decltype(START), decltype(STOP), decltype(ACK), decltype(POS), decltype(PEC), decltype(ALERT), decltype(SWRST)> CR1; // Control register 1

    constexpr auto FREQ = BitField<i2c2_t, 0, 6, "FREQ">{}; // bit offset: 0, bit width: 6, Peripheral clock frequency
    constexpr auto ITERREN = BitField<i2c2_t, 8, 1, "ITERREN">{}; // bit offset: 8, bit width: 1, Error interrupt enable
    constexpr auto ITEVTEN = BitField<i2c2_t, 9, 1, "ITEVTEN">{}; // bit offset: 9, bit width: 1, Event interrupt enable
    constexpr auto ITBUFEN = BitField<i2c2_t, 10, 1, "ITBUFEN">{}; // bit offset: 10, bit width: 1, Buffer interrupt enable
    constexpr auto DMAEN = BitField<i2c2_t, 11, 1, "DMAEN">{}; // bit offset: 11, bit width: 1, DMA requests enable
    constexpr auto LAST = BitField<i2c2_t, 12, 1, "LAST">{}; // bit offset: 12, bit width: 1, DMA last transfer
    static Register<std::uint32_t, I2C2_BASE_ADDRESS + 0x00000004u, 0, READWRITE, "CR2", decltype(FREQ), decltype(ITERREN), decltype(ITEVTEN), decltype(ITBUFEN), decltype(DMAEN), decltype(LAST)> CR2; // Control register 2

    constexpr auto ADD0 = BitField<i2c2_t, 0, 1, "ADD0">{}; // bit offset: 0, bit width: 1, Interface address
    constexpr auto ADD7 = BitField<i2c2_t, 1, 7, "ADD7">{}; // bit offset: 1, bit width: 7, Interface address
    constexpr auto ADD10 = BitField<i2c2_t, 8, 2, "ADD10">{}; // bit offset: 8, bit width: 2, Interface address
    constexpr auto ADDMODE = BitField<i2c2_t, 15, 1, "ADDMODE">{}; // bit offset: 15, bit width: 1, Addressing mode (slave mode)
    static Register<std::uint32_t, I2C2_BASE_ADDRESS + 0x00000008u, 0, READWRITE, "OAR1", decltype(ADD0), decltype(ADD7), decltype(ADD10), decltype(ADDMODE)> OAR1; // Own address register 1

    constexpr auto ENDUAL = BitField<i2c2_t, 0, 1, "ENDUAL">{}; // bit offset: 0, bit width: 1, Dual addressing mode enable
    constexpr auto ADD2 = BitField<i2c2_t, 1, 7, "ADD2">{}; // bit offset: 1, bit width: 7, Interface address
    static Register<std::uint32_t, I2C2_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, "OAR2", decltype(ENDUAL), decltype(ADD2)> OAR2; // Own address register 2

    constexpr auto DR_ = BitField<i2c2_t, 0, 8, "DR">{}; // bit offset: 0, bit width: 8, 8-bit data register
    static Register<std::uint32_t, I2C2_BASE_ADDRESS + 0x00000010u, 0, READWRITE, "DR", decltype(DR_)> DR; // Data register

    constexpr auto SB = BitField<i2c2_t, 0, 1, "SB", READONLY>{}; // bit offset: 0, bit width: 1, Start bit (Master mode)
    constexpr auto ADDR = BitField<i2c2_t, 1, 1, "ADDR", READONLY>{}; // bit offset: 1, bit width: 1, Address sent (master mode)/matched (slave mode)
    constexpr auto BTF = BitField<i2c2_t, 2, 1, "BTF", READONLY>{}; // bit offset: 2, bit width: 1, Byte transfer finished
    constexpr auto ADD10 = BitField<i2c2_t, 3, 1, "ADD10", READONLY>{}; // bit offset: 3, bit width: 1, 10-bit header sent (Master mode)
    constexpr auto STOPF = BitField<i2c2_t, 4, 1, "STOPF", READONLY>{}; // bit offset: 4, bit width: 1, Stop detection (slave mode)
    constexpr auto RxNE = BitField<i2c2_t, 6, 1, "RxNE", READONLY>{}; // bit offset: 6, bit width: 1, Data register not empty (receivers)
    constexpr auto TxE = BitField<i2c2_t, 7, 1, "TxE", READONLY>{}; // bit offset: 7, bit width: 1, Data register empty (transmitters)
    constexpr auto BERR = BitField<i2c2_t, 8, 1, "BERR", READWRITE>{}; // bit offset: 8, bit width: 1, Bus error
    constexpr auto ARLO = BitField<i2c2_t, 9, 1, "ARLO", READWRITE>{}; // bit offset: 9, bit width: 1, Arbitration lost (master mode)
    constexpr auto AF = BitField<i2c2_t, 10, 1, "AF", READWRITE>{}; // bit offset: 10, bit width: 1, Acknowledge failure
    constexpr auto OVR = BitField<i2c2_t, 11, 1, "OVR", READWRITE>{}; // bit offset: 11, bit width: 1, Overrun/Underrun
    constexpr auto PECERR = BitField<i2c2_t, 12, 1, "PECERR", READWRITE>{}; // bit offset: 12, bit width: 1, PEC Error in reception
    constexpr auto TIMEOUT = BitField<i2c2_t, 14, 1, "TIMEOUT", READWRITE>{}; // bit offset: 14, bit width: 1, Timeout or Tlow error
    constexpr auto SMBALERT = BitField<i2c2_t, 15, 1, "SMBALERT", READWRITE>{}; // bit offset: 15, bit width: 1, SMBus alert
    static Register<std::uint32_t, I2C2_BASE_ADDRESS + 0x00000014u, 0, READWRITE, "SR1", decltype(SB), decltype(ADDR), decltype(BTF), decltype(ADD10), decltype(STOPF), decltype(RxNE), decltype(TxE), decltype(BERR), decltype(ARLO), decltype(AF), decltype(OVR), decltype(PECERR), decltype(TIMEOUT), decltype(SMBALERT)> SR1; // Status register 1

    constexpr auto MSL = BitField<i2c2_t, 0, 1, "MSL">{}; // bit offset: 0, bit width: 1, Master/slave
    constexpr auto BUSY = BitField<i2c2_t, 1, 1, "BUSY">{}; // bit offset: 1, bit width: 1, Bus busy
    constexpr auto TRA = BitField<i2c2_t, 2, 1, "TRA">{}; // bit offset: 2, bit width: 1, Transmitter/receiver
    constexpr auto GENCALL = BitField<i2c2_t, 4, 1, "GENCALL">{}; // bit offset: 4, bit width: 1, General call address (Slave mode)
    constexpr auto SMBDEFAULT = BitField<i2c2_t, 5, 1, "SMBDEFAULT">{}; // bit offset: 5, bit width: 1, SMBus device default address (Slave mode)
    constexpr auto SMBHOST = BitField<i2c2_t, 6, 1, "SMBHOST">{}; // bit offset: 6, bit width: 1, SMBus host header (Slave mode)
    constexpr auto DUALF = BitField<i2c2_t, 7, 1, "DUALF">{}; // bit offset: 7, bit width: 1, Dual flag (Slave mode)
    constexpr auto PEC = BitField<i2c2_t, 8, 8, "PEC">{}; // bit offset: 8, bit width: 8, acket error checking register
    static Register<std::uint32_t, I2C2_BASE_ADDRESS + 0x00000018u, 0, READONLY, "SR2", decltype(MSL), decltype(BUSY), decltype(TRA), decltype(GENCALL), decltype(SMBDEFAULT), decltype(SMBHOST), decltype(DUALF), decltype(PEC)> SR2; // Status register 2

    constexpr auto CCR_ = BitField<i2c2_t, 0, 12, "CCR">{}; // bit offset: 0, bit width: 12, Clock control register in Fast/Standard mode (Master mode)
    constexpr auto DUTY = BitField<i2c2_t, 14, 1, "DUTY">{}; // bit offset: 14, bit width: 1, Fast mode duty cycle
    constexpr auto F_S = BitField<i2c2_t, 15, 1, "F_S">{}; // bit offset: 15, bit width: 1, I2C master mode selection
    static Register<std::uint32_t, I2C2_BASE_ADDRESS + 0x0000001cu, 0, READWRITE, "CCR", decltype(CCR_), decltype(DUTY), decltype(F_S)> CCR; // Clock control register

    constexpr auto TRISE_ = BitField<i2c2_t, 0, 6, "TRISE">{}; // bit offset: 0, bit width: 6, Maximum rise time in Fast/Standard mode (Master mode)
    static Register<std::uint32_t, I2C2_BASE_ADDRESS + 0x00000020u, 2, READWRITE, "TRISE", decltype(TRISE_)> TRISE; // TRISE register

} // namespace I2C2