#include <Register.hpp>

namespace SPI3
{
    struct spi3_t{};

    constexpr std::uint32_t SPI3_BASE_ADDRESS = 0x40003c00u;

    constexpr auto CPHA = BitField<spi3_t, 0, 1, "CPHA">{}; // bit offset: 0, bit width: 1, Clock phase
    constexpr auto CPOL = BitField<spi3_t, 1, 1, "CPOL">{}; // bit offset: 1, bit width: 1, Clock polarity
    constexpr auto MSTR = BitField<spi3_t, 2, 1, "MSTR">{}; // bit offset: 2, bit width: 1, Master selection
    constexpr auto BR = BitField<spi3_t, 3, 3, "BR">{}; // bit offset: 3, bit width: 3, Baud rate control
    constexpr auto SPE = BitField<spi3_t, 6, 1, "SPE">{}; // bit offset: 6, bit width: 1, SPI enable
    constexpr auto LSBFIRST = BitField<spi3_t, 7, 1, "LSBFIRST">{}; // bit offset: 7, bit width: 1, Frame format
    constexpr auto SSI = BitField<spi3_t, 8, 1, "SSI">{}; // bit offset: 8, bit width: 1, Internal slave select
    constexpr auto SSM = BitField<spi3_t, 9, 1, "SSM">{}; // bit offset: 9, bit width: 1, Software slave management
    constexpr auto RXONLY = BitField<spi3_t, 10, 1, "RXONLY">{}; // bit offset: 10, bit width: 1, Receive only
    constexpr auto DFF = BitField<spi3_t, 11, 1, "DFF">{}; // bit offset: 11, bit width: 1, Data frame format
    constexpr auto CRCNEXT = BitField<spi3_t, 12, 1, "CRCNEXT">{}; // bit offset: 12, bit width: 1, CRC transfer next
    constexpr auto CRCEN = BitField<spi3_t, 13, 1, "CRCEN">{}; // bit offset: 13, bit width: 1, Hardware CRC calculation enable
    constexpr auto BIDIOE = BitField<spi3_t, 14, 1, "BIDIOE">{}; // bit offset: 14, bit width: 1, Output enable in bidirectional mode
    constexpr auto BIDIMODE = BitField<spi3_t, 15, 1, "BIDIMODE">{}; // bit offset: 15, bit width: 1, Bidirectional data mode enable
    static Register<std::uint32_t, SPI3_BASE_ADDRESS + 0x00000000u, 0, READWRITE, "CR1", decltype(CPHA), decltype(CPOL), decltype(MSTR), decltype(BR), decltype(SPE), decltype(LSBFIRST), decltype(SSI), decltype(SSM), decltype(RXONLY), decltype(DFF), decltype(CRCNEXT), decltype(CRCEN), decltype(BIDIOE), decltype(BIDIMODE)> CR1; // control register 1

    constexpr auto RXDMAEN = BitField<spi3_t, 0, 1, "RXDMAEN">{}; // bit offset: 0, bit width: 1, Rx buffer DMA enable
    constexpr auto TXDMAEN = BitField<spi3_t, 1, 1, "TXDMAEN">{}; // bit offset: 1, bit width: 1, Tx buffer DMA enable
    constexpr auto SSOE = BitField<spi3_t, 2, 1, "SSOE">{}; // bit offset: 2, bit width: 1, SS output enable
    constexpr auto FRF = BitField<spi3_t, 4, 1, "FRF">{}; // bit offset: 4, bit width: 1, Frame format
    constexpr auto ERRIE = BitField<spi3_t, 5, 1, "ERRIE">{}; // bit offset: 5, bit width: 1, Error interrupt enable
    constexpr auto RXNEIE = BitField<spi3_t, 6, 1, "RXNEIE">{}; // bit offset: 6, bit width: 1, RX buffer not empty interrupt enable
    constexpr auto TXEIE = BitField<spi3_t, 7, 1, "TXEIE">{}; // bit offset: 7, bit width: 1, Tx buffer empty interrupt enable
    static Register<std::uint32_t, SPI3_BASE_ADDRESS + 0x00000004u, 0, READWRITE, "CR2", decltype(RXDMAEN), decltype(TXDMAEN), decltype(SSOE), decltype(FRF), decltype(ERRIE), decltype(RXNEIE), decltype(TXEIE)> CR2; // control register 2

    constexpr auto RXNE = BitField<spi3_t, 0, 1, "RXNE", READONLY>{}; // bit offset: 0, bit width: 1, Receive buffer not empty
    constexpr auto TXE = BitField<spi3_t, 1, 1, "TXE", READONLY>{}; // bit offset: 1, bit width: 1, Transmit buffer empty
    constexpr auto CHSIDE = BitField<spi3_t, 2, 1, "CHSIDE", READONLY>{}; // bit offset: 2, bit width: 1, Channel side
    constexpr auto UDR = BitField<spi3_t, 3, 1, "UDR", READONLY>{}; // bit offset: 3, bit width: 1, Underrun flag
    constexpr auto CRCERR = BitField<spi3_t, 4, 1, "CRCERR", READWRITE>{}; // bit offset: 4, bit width: 1, CRC error flag
    constexpr auto MODF = BitField<spi3_t, 5, 1, "MODF", READONLY>{}; // bit offset: 5, bit width: 1, Mode fault
    constexpr auto OVR = BitField<spi3_t, 6, 1, "OVR", READONLY>{}; // bit offset: 6, bit width: 1, Overrun flag
    constexpr auto BSY = BitField<spi3_t, 7, 1, "BSY", READONLY>{}; // bit offset: 7, bit width: 1, Busy flag
    constexpr auto TIFRFE = BitField<spi3_t, 8, 1, "TIFRFE", READONLY>{}; // bit offset: 8, bit width: 1, TI frame format error
    static Register<std::uint32_t, SPI3_BASE_ADDRESS + 0x00000008u, 2, READWRITE, "SR", decltype(RXNE), decltype(TXE), decltype(CHSIDE), decltype(UDR), decltype(CRCERR), decltype(MODF), decltype(OVR), decltype(BSY), decltype(TIFRFE)> SR; // status register

    constexpr auto DR_ = BitField<spi3_t, 0, 16, "DR">{}; // bit offset: 0, bit width: 16, Data register
    static Register<std::uint32_t, SPI3_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, "DR", decltype(DR_)> DR; // data register

    constexpr auto CRCPOLY = BitField<spi3_t, 0, 16, "CRCPOLY">{}; // bit offset: 0, bit width: 16, CRC polynomial register
    static Register<std::uint32_t, SPI3_BASE_ADDRESS + 0x00000010u, 7, READWRITE, "CRCPR", decltype(CRCPOLY)> CRCPR; // CRC polynomial register

    constexpr auto RxCRC = BitField<spi3_t, 0, 16, "RxCRC">{}; // bit offset: 0, bit width: 16, Rx CRC register
    static Register<std::uint32_t, SPI3_BASE_ADDRESS + 0x00000014u, 0, READONLY, "RXCRCR", decltype(RxCRC)> RXCRCR; // RX CRC register

    constexpr auto TxCRC = BitField<spi3_t, 0, 16, "TxCRC">{}; // bit offset: 0, bit width: 16, Tx CRC register
    static Register<std::uint32_t, SPI3_BASE_ADDRESS + 0x00000018u, 0, READONLY, "TXCRCR", decltype(TxCRC)> TXCRCR; // TX CRC register

    constexpr auto CHLEN = BitField<spi3_t, 0, 1, "CHLEN">{}; // bit offset: 0, bit width: 1, Channel length (number of bits per audio channel)
    constexpr auto DATLEN = BitField<spi3_t, 1, 2, "DATLEN">{}; // bit offset: 1, bit width: 2, Data length to be transferred
    constexpr auto CKPOL = BitField<spi3_t, 3, 1, "CKPOL">{}; // bit offset: 3, bit width: 1, Steady state clock polarity
    constexpr auto I2SSTD = BitField<spi3_t, 4, 2, "I2SSTD">{}; // bit offset: 4, bit width: 2, I2S standard selection
    constexpr auto PCMSYNC = BitField<spi3_t, 7, 1, "PCMSYNC">{}; // bit offset: 7, bit width: 1, PCM frame synchronization
    constexpr auto I2SCFG = BitField<spi3_t, 8, 2, "I2SCFG">{}; // bit offset: 8, bit width: 2, I2S configuration mode
    constexpr auto I2SE = BitField<spi3_t, 10, 1, "I2SE">{}; // bit offset: 10, bit width: 1, I2S Enable
    constexpr auto I2SMOD = BitField<spi3_t, 11, 1, "I2SMOD">{}; // bit offset: 11, bit width: 1, I2S mode selection
    static Register<std::uint32_t, SPI3_BASE_ADDRESS + 0x0000001cu, 0, READWRITE, "I2SCFGR", decltype(CHLEN), decltype(DATLEN), decltype(CKPOL), decltype(I2SSTD), decltype(PCMSYNC), decltype(I2SCFG), decltype(I2SE), decltype(I2SMOD)> I2SCFGR; // I2S configuration register

    constexpr auto I2SDIV = BitField<spi3_t, 0, 8, "I2SDIV">{}; // bit offset: 0, bit width: 8, I2S Linear prescaler
    constexpr auto ODD = BitField<spi3_t, 8, 1, "ODD">{}; // bit offset: 8, bit width: 1, Odd factor for the prescaler
    constexpr auto MCKOE = BitField<spi3_t, 9, 1, "MCKOE">{}; // bit offset: 9, bit width: 1, Master clock output enable
    static Register<std::uint32_t, SPI3_BASE_ADDRESS + 0x00000020u, 10, READWRITE, "I2SPR", decltype(I2SDIV), decltype(ODD), decltype(MCKOE)> I2SPR; // I2S prescaler register

} // namespace SPI3