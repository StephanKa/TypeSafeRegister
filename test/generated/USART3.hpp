#include <Register.hpp>

namespace USART3
{
    struct usart3_t{};

    constexpr std::uint32_t USART3_BASE_ADDRESS = 0x40004800u;

    constexpr auto PE = BitField<usart3_t, 0, 1, "PE", READONLY>{}; // bit offset: 0, bit width: 1, Parity error
    constexpr auto FE = BitField<usart3_t, 1, 1, "FE", READONLY>{}; // bit offset: 1, bit width: 1, Framing error
    constexpr auto NF = BitField<usart3_t, 2, 1, "NF", READONLY>{}; // bit offset: 2, bit width: 1, Noise detected flag
    constexpr auto ORE = BitField<usart3_t, 3, 1, "ORE", READONLY>{}; // bit offset: 3, bit width: 1, Overrun error
    constexpr auto IDLE = BitField<usart3_t, 4, 1, "IDLE", READONLY>{}; // bit offset: 4, bit width: 1, IDLE line detected
    constexpr auto RXNE = BitField<usart3_t, 5, 1, "RXNE", READWRITE>{}; // bit offset: 5, bit width: 1, Read data register not empty
    constexpr auto TC = BitField<usart3_t, 6, 1, "TC", READWRITE>{}; // bit offset: 6, bit width: 1, Transmission complete
    constexpr auto TXE = BitField<usart3_t, 7, 1, "TXE", READONLY>{}; // bit offset: 7, bit width: 1, Transmit data register empty
    constexpr auto LBD = BitField<usart3_t, 8, 1, "LBD", READWRITE>{}; // bit offset: 8, bit width: 1, LIN break detection flag
    constexpr auto CTS = BitField<usart3_t, 9, 1, "CTS", READWRITE>{}; // bit offset: 9, bit width: 1, CTS flag
    static Register<std::uint32_t, USART3_BASE_ADDRESS + 0x00000000u, 192, READWRITE, "SR", decltype(PE), decltype(FE), decltype(NF), decltype(ORE), decltype(IDLE), decltype(RXNE), decltype(TC), decltype(TXE), decltype(LBD), decltype(CTS)> SR; // Status register

    constexpr auto DR_ = BitField<usart3_t, 0, 9, "DR">{}; // bit offset: 0, bit width: 9, Data value
    static Register<std::uint32_t, USART3_BASE_ADDRESS + 0x00000004u, 0, READWRITE, "DR", decltype(DR_)> DR; // Data register

    constexpr auto DIV_Fraction = BitField<usart3_t, 0, 4, "DIV_Fraction">{}; // bit offset: 0, bit width: 4, fraction of USARTDIV
    constexpr auto DIV_Mantissa = BitField<usart3_t, 4, 12, "DIV_Mantissa">{}; // bit offset: 4, bit width: 12, mantissa of USARTDIV
    static Register<std::uint32_t, USART3_BASE_ADDRESS + 0x00000008u, 0, READWRITE, "BRR", decltype(DIV_Fraction), decltype(DIV_Mantissa)> BRR; // Baud rate register

    constexpr auto SBK = BitField<usart3_t, 0, 1, "SBK">{}; // bit offset: 0, bit width: 1, Send break
    constexpr auto RWU = BitField<usart3_t, 1, 1, "RWU">{}; // bit offset: 1, bit width: 1, Receiver wakeup
    constexpr auto RE = BitField<usart3_t, 2, 1, "RE">{}; // bit offset: 2, bit width: 1, Receiver enable
    constexpr auto TE = BitField<usart3_t, 3, 1, "TE">{}; // bit offset: 3, bit width: 1, Transmitter enable
    constexpr auto IDLEIE = BitField<usart3_t, 4, 1, "IDLEIE">{}; // bit offset: 4, bit width: 1, IDLE interrupt enable
    constexpr auto RXNEIE = BitField<usart3_t, 5, 1, "RXNEIE">{}; // bit offset: 5, bit width: 1, RXNE interrupt enable
    constexpr auto TCIE = BitField<usart3_t, 6, 1, "TCIE">{}; // bit offset: 6, bit width: 1, Transmission complete interrupt enable
    constexpr auto TXEIE = BitField<usart3_t, 7, 1, "TXEIE">{}; // bit offset: 7, bit width: 1, TXE interrupt enable
    constexpr auto PEIE = BitField<usart3_t, 8, 1, "PEIE">{}; // bit offset: 8, bit width: 1, PE interrupt enable
    constexpr auto PS = BitField<usart3_t, 9, 1, "PS">{}; // bit offset: 9, bit width: 1, Parity selection
    constexpr auto PCE = BitField<usart3_t, 10, 1, "PCE">{}; // bit offset: 10, bit width: 1, Parity control enable
    constexpr auto WAKE = BitField<usart3_t, 11, 1, "WAKE">{}; // bit offset: 11, bit width: 1, Wakeup method
    constexpr auto M = BitField<usart3_t, 12, 1, "M">{}; // bit offset: 12, bit width: 1, Word length
    constexpr auto UE = BitField<usart3_t, 13, 1, "UE">{}; // bit offset: 13, bit width: 1, USART enable
    constexpr auto OVER8 = BitField<usart3_t, 15, 1, "OVER8">{}; // bit offset: 15, bit width: 1, Oversampling mode
    static Register<std::uint32_t, USART3_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, "CR1", decltype(SBK), decltype(RWU), decltype(RE), decltype(TE), decltype(IDLEIE), decltype(RXNEIE), decltype(TCIE), decltype(TXEIE), decltype(PEIE), decltype(PS), decltype(PCE), decltype(WAKE), decltype(M), decltype(UE), decltype(OVER8)> CR1; // Control register 1

    constexpr auto ADD = BitField<usart3_t, 0, 4, "ADD">{}; // bit offset: 0, bit width: 4, Address of the USART node
    constexpr auto LBDL = BitField<usart3_t, 5, 1, "LBDL">{}; // bit offset: 5, bit width: 1, lin break detection length
    constexpr auto LBDIE = BitField<usart3_t, 6, 1, "LBDIE">{}; // bit offset: 6, bit width: 1, LIN break detection interrupt enable
    constexpr auto LBCL = BitField<usart3_t, 8, 1, "LBCL">{}; // bit offset: 8, bit width: 1, Last bit clock pulse
    constexpr auto CPHA = BitField<usart3_t, 9, 1, "CPHA">{}; // bit offset: 9, bit width: 1, Clock phase
    constexpr auto CPOL = BitField<usart3_t, 10, 1, "CPOL">{}; // bit offset: 10, bit width: 1, Clock polarity
    constexpr auto CLKEN = BitField<usart3_t, 11, 1, "CLKEN">{}; // bit offset: 11, bit width: 1, Clock enable
    constexpr auto STOP = BitField<usart3_t, 12, 2, "STOP">{}; // bit offset: 12, bit width: 2, STOP bits
    constexpr auto LINEN = BitField<usart3_t, 14, 1, "LINEN">{}; // bit offset: 14, bit width: 1, LIN mode enable
    static Register<std::uint32_t, USART3_BASE_ADDRESS + 0x00000010u, 0, READWRITE, "CR2", decltype(ADD), decltype(LBDL), decltype(LBDIE), decltype(LBCL), decltype(CPHA), decltype(CPOL), decltype(CLKEN), decltype(STOP), decltype(LINEN)> CR2; // Control register 2

    constexpr auto EIE = BitField<usart3_t, 0, 1, "EIE">{}; // bit offset: 0, bit width: 1, Error interrupt enable
    constexpr auto IREN = BitField<usart3_t, 1, 1, "IREN">{}; // bit offset: 1, bit width: 1, IrDA mode enable
    constexpr auto IRLP = BitField<usart3_t, 2, 1, "IRLP">{}; // bit offset: 2, bit width: 1, IrDA low-power
    constexpr auto HDSEL = BitField<usart3_t, 3, 1, "HDSEL">{}; // bit offset: 3, bit width: 1, Half-duplex selection
    constexpr auto NACK = BitField<usart3_t, 4, 1, "NACK">{}; // bit offset: 4, bit width: 1, Smartcard NACK enable
    constexpr auto SCEN = BitField<usart3_t, 5, 1, "SCEN">{}; // bit offset: 5, bit width: 1, Smartcard mode enable
    constexpr auto DMAR = BitField<usart3_t, 6, 1, "DMAR">{}; // bit offset: 6, bit width: 1, DMA enable receiver
    constexpr auto DMAT = BitField<usart3_t, 7, 1, "DMAT">{}; // bit offset: 7, bit width: 1, DMA enable transmitter
    constexpr auto RTSE = BitField<usart3_t, 8, 1, "RTSE">{}; // bit offset: 8, bit width: 1, RTS enable
    constexpr auto CTSE = BitField<usart3_t, 9, 1, "CTSE">{}; // bit offset: 9, bit width: 1, CTS enable
    constexpr auto CTSIE = BitField<usart3_t, 10, 1, "CTSIE">{}; // bit offset: 10, bit width: 1, CTS interrupt enable
    constexpr auto ONEBIT = BitField<usart3_t, 11, 1, "ONEBIT">{}; // bit offset: 11, bit width: 1, One sample bit method enable
    static Register<std::uint32_t, USART3_BASE_ADDRESS + 0x00000014u, 0, READWRITE, "CR3", decltype(EIE), decltype(IREN), decltype(IRLP), decltype(HDSEL), decltype(NACK), decltype(SCEN), decltype(DMAR), decltype(DMAT), decltype(RTSE), decltype(CTSE), decltype(CTSIE), decltype(ONEBIT)> CR3; // Control register 3

    constexpr auto PSC = BitField<usart3_t, 0, 8, "PSC">{}; // bit offset: 0, bit width: 8, Prescaler value
    constexpr auto GT = BitField<usart3_t, 8, 8, "GT">{}; // bit offset: 8, bit width: 8, Guard time value
    static Register<std::uint32_t, USART3_BASE_ADDRESS + 0x00000018u, 0, READWRITE, "GTPR", decltype(PSC), decltype(GT)> GTPR; // Guard time and prescaler register

} // namespace USART3