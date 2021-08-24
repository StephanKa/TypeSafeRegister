#include <Register.hpp>




namespace SPI1
{
    struct spi1_t{};

    constexpr std::uint32_t SPI1_BASE_ADDRESS = 0x40013000u;

    constexpr auto CPHA = BitField<spi1_t, 0, 1>{}; // bit offset: 0, bit width: 1, Clock phase
    constexpr auto CPOL = BitField<spi1_t, 1, 1>{}; // bit offset: 1, bit width: 1, Clock polarity
    constexpr auto MSTR = BitField<spi1_t, 2, 1>{}; // bit offset: 2, bit width: 1, Master selection
    constexpr auto BR = BitField<spi1_t, 3, 3>{}; // bit offset: 3, bit width: 3, Baud rate control
    constexpr auto SPE = BitField<spi1_t, 6, 1>{}; // bit offset: 6, bit width: 1, SPI enable
    constexpr auto LSBFIRST = BitField<spi1_t, 7, 1>{}; // bit offset: 7, bit width: 1, Frame format
    constexpr auto SSI = BitField<spi1_t, 8, 1>{}; // bit offset: 8, bit width: 1, Internal slave select
    constexpr auto SSM = BitField<spi1_t, 9, 1>{}; // bit offset: 9, bit width: 1, Software slave management
    constexpr auto RXONLY = BitField<spi1_t, 10, 1>{}; // bit offset: 10, bit width: 1, Receive only
    constexpr auto DFF = BitField<spi1_t, 11, 1>{}; // bit offset: 11, bit width: 1, Data frame format
    constexpr auto CRCNEXT = BitField<spi1_t, 12, 1>{}; // bit offset: 12, bit width: 1, CRC transfer next
    constexpr auto CRCEN = BitField<spi1_t, 13, 1>{}; // bit offset: 13, bit width: 1, Hardware CRC calculation enable
    constexpr auto BIDIOE = BitField<spi1_t, 14, 1>{}; // bit offset: 14, bit width: 1, Output enable in bidirectional mode
    constexpr auto BIDIMODE = BitField<spi1_t, 15, 1>{}; // bit offset: 15, bit width: 1, Bidirectional data mode enable
    static Register<std::uint32_t, SPI1_BASE_ADDRESS + 0x00000000u, 0, READWRITE, decltype(CPHA), decltype(CPOL), decltype(MSTR), decltype(BR), decltype(SPE), decltype(LSBFIRST), decltype(SSI), decltype(SSM), decltype(RXONLY), decltype(DFF), decltype(CRCNEXT), decltype(CRCEN), decltype(BIDIOE), decltype(BIDIMODE)> CR1; // control register 1

    constexpr auto RXDMAEN = BitField<spi1_t, 0, 1>{}; // bit offset: 0, bit width: 1, Rx buffer DMA enable
    constexpr auto TXDMAEN = BitField<spi1_t, 1, 1>{}; // bit offset: 1, bit width: 1, Tx buffer DMA enable
    constexpr auto SSOE = BitField<spi1_t, 2, 1>{}; // bit offset: 2, bit width: 1, SS output enable
    constexpr auto FRF = BitField<spi1_t, 4, 1>{}; // bit offset: 4, bit width: 1, Frame format
    constexpr auto ERRIE = BitField<spi1_t, 5, 1>{}; // bit offset: 5, bit width: 1, Error interrupt enable
    constexpr auto RXNEIE = BitField<spi1_t, 6, 1>{}; // bit offset: 6, bit width: 1, RX buffer not empty interrupt enable
    constexpr auto TXEIE = BitField<spi1_t, 7, 1>{}; // bit offset: 7, bit width: 1, Tx buffer empty interrupt enable
    static Register<std::uint32_t, SPI1_BASE_ADDRESS + 0x00000004u, 0, READWRITE, decltype(RXDMAEN), decltype(TXDMAEN), decltype(SSOE), decltype(FRF), decltype(ERRIE), decltype(RXNEIE), decltype(TXEIE)> CR2; // control register 2

    constexpr auto RXNE = BitField<spi1_t, 0, 1, READONLY>{}; // bit offset: 0, bit width: 1, Receive buffer not empty
    constexpr auto TXE = BitField<spi1_t, 1, 1, READONLY>{}; // bit offset: 1, bit width: 1, Transmit buffer empty
    constexpr auto CHSIDE = BitField<spi1_t, 2, 1, READONLY>{}; // bit offset: 2, bit width: 1, Channel side
    constexpr auto UDR = BitField<spi1_t, 3, 1, READONLY>{}; // bit offset: 3, bit width: 1, Underrun flag
    constexpr auto CRCERR = BitField<spi1_t, 4, 1, READWRITE>{}; // bit offset: 4, bit width: 1, CRC error flag
    constexpr auto MODF = BitField<spi1_t, 5, 1, READONLY>{}; // bit offset: 5, bit width: 1, Mode fault
    constexpr auto OVR = BitField<spi1_t, 6, 1, READONLY>{}; // bit offset: 6, bit width: 1, Overrun flag
    constexpr auto BSY = BitField<spi1_t, 7, 1, READONLY>{}; // bit offset: 7, bit width: 1, Busy flag
    constexpr auto TIFRFE = BitField<spi1_t, 8, 1, READONLY>{}; // bit offset: 8, bit width: 1, TI frame format error
    static Register<std::uint32_t, SPI1_BASE_ADDRESS + 0x00000008u, 2, READWRITE, decltype(RXNE), decltype(TXE), decltype(CHSIDE), decltype(UDR), decltype(CRCERR), decltype(MODF), decltype(OVR), decltype(BSY), decltype(TIFRFE)> SR; // status register

    constexpr auto DR_ = BitField<spi1_t, 0, 16>{}; // bit offset: 0, bit width: 16, Data register
    static Register<std::uint32_t, SPI1_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, decltype(DR_)> DR; // data register

    constexpr auto CRCPOLY = BitField<spi1_t, 0, 16>{}; // bit offset: 0, bit width: 16, CRC polynomial register
    static Register<std::uint32_t, SPI1_BASE_ADDRESS + 0x00000010u, 7, READWRITE, decltype(CRCPOLY)> CRCPR; // CRC polynomial register

    constexpr auto RxCRC = BitField<spi1_t, 0, 16>{}; // bit offset: 0, bit width: 16, Rx CRC register
    static Register<std::uint32_t, SPI1_BASE_ADDRESS + 0x00000014u, 0, READONLY, decltype(RxCRC)> RXCRCR; // RX CRC register

    constexpr auto TxCRC = BitField<spi1_t, 0, 16>{}; // bit offset: 0, bit width: 16, Tx CRC register
    static Register<std::uint32_t, SPI1_BASE_ADDRESS + 0x00000018u, 0, READONLY, decltype(TxCRC)> TXCRCR; // TX CRC register

    constexpr auto CHLEN = BitField<spi1_t, 0, 1>{}; // bit offset: 0, bit width: 1, Channel length (number of bits per audio channel)
    constexpr auto DATLEN = BitField<spi1_t, 1, 2>{}; // bit offset: 1, bit width: 2, Data length to be transferred
    constexpr auto CKPOL = BitField<spi1_t, 3, 1>{}; // bit offset: 3, bit width: 1, Steady state clock polarity
    constexpr auto I2SSTD = BitField<spi1_t, 4, 2>{}; // bit offset: 4, bit width: 2, I2S standard selection
    constexpr auto PCMSYNC = BitField<spi1_t, 7, 1>{}; // bit offset: 7, bit width: 1, PCM frame synchronization
    constexpr auto I2SCFG = BitField<spi1_t, 8, 2>{}; // bit offset: 8, bit width: 2, I2S configuration mode
    constexpr auto I2SE = BitField<spi1_t, 10, 1>{}; // bit offset: 10, bit width: 1, I2S Enable
    constexpr auto I2SMOD = BitField<spi1_t, 11, 1>{}; // bit offset: 11, bit width: 1, I2S mode selection
    static Register<std::uint32_t, SPI1_BASE_ADDRESS + 0x0000001cu, 0, READWRITE, decltype(CHLEN), decltype(DATLEN), decltype(CKPOL), decltype(I2SSTD), decltype(PCMSYNC), decltype(I2SCFG), decltype(I2SE), decltype(I2SMOD)> I2SCFGR; // I2S configuration register

    constexpr auto I2SDIV = BitField<spi1_t, 0, 8>{}; // bit offset: 0, bit width: 8, I2S Linear prescaler
    constexpr auto ODD = BitField<spi1_t, 8, 1>{}; // bit offset: 8, bit width: 1, Odd factor for the prescaler
    constexpr auto MCKOE = BitField<spi1_t, 9, 1>{}; // bit offset: 9, bit width: 1, Master clock output enable
    static Register<std::uint32_t, SPI1_BASE_ADDRESS + 0x00000020u, 10, READWRITE, decltype(I2SDIV), decltype(ODD), decltype(MCKOE)> I2SPR; // I2S prescaler register

} // namespace SPI1