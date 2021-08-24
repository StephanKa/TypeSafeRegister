#include <Register.hpp>




namespace USART1
{
    struct usart1_t{};

    constexpr std::uint32_t USART1_BASE_ADDRESS = 0x40011000u;

    constexpr auto PE = BitField<usart1_t, 0, 1, READONLY>{}; // bit offset: 0, bit width: 1, Parity error
    constexpr auto FE = BitField<usart1_t, 1, 1, READONLY>{}; // bit offset: 1, bit width: 1, Framing error
    constexpr auto NF = BitField<usart1_t, 2, 1, READONLY>{}; // bit offset: 2, bit width: 1, Noise detected flag
    constexpr auto ORE = BitField<usart1_t, 3, 1, READONLY>{}; // bit offset: 3, bit width: 1, Overrun error
    constexpr auto IDLE = BitField<usart1_t, 4, 1, READONLY>{}; // bit offset: 4, bit width: 1, IDLE line detected
    constexpr auto RXNE = BitField<usart1_t, 5, 1, READWRITE>{}; // bit offset: 5, bit width: 1, Read data register not empty
    constexpr auto TC = BitField<usart1_t, 6, 1, READWRITE>{}; // bit offset: 6, bit width: 1, Transmission complete
    constexpr auto TXE = BitField<usart1_t, 7, 1, READONLY>{}; // bit offset: 7, bit width: 1, Transmit data register empty
    constexpr auto LBD = BitField<usart1_t, 8, 1, READWRITE>{}; // bit offset: 8, bit width: 1, LIN break detection flag
    constexpr auto CTS = BitField<usart1_t, 9, 1, READWRITE>{}; // bit offset: 9, bit width: 1, CTS flag
    static Register<std::uint32_t, USART1_BASE_ADDRESS + 0x00000000u, 192, READWRITE, decltype(PE), decltype(FE), decltype(NF), decltype(ORE), decltype(IDLE), decltype(RXNE), decltype(TC), decltype(TXE), decltype(LBD), decltype(CTS)> SR; // Status register

    constexpr auto DR_ = BitField<usart1_t, 0, 9>{}; // bit offset: 0, bit width: 9, Data value
    static Register<std::uint32_t, USART1_BASE_ADDRESS + 0x00000004u, 0, READWRITE, decltype(DR_)> DR; // Data register

    constexpr auto DIV_Fraction = BitField<usart1_t, 0, 4>{}; // bit offset: 0, bit width: 4, fraction of USARTDIV
    constexpr auto DIV_Mantissa = BitField<usart1_t, 4, 12>{}; // bit offset: 4, bit width: 12, mantissa of USARTDIV
    static Register<std::uint32_t, USART1_BASE_ADDRESS + 0x00000008u, 0, READWRITE, decltype(DIV_Fraction), decltype(DIV_Mantissa)> BRR; // Baud rate register

    constexpr auto SBK = BitField<usart1_t, 0, 1>{}; // bit offset: 0, bit width: 1, Send break
    constexpr auto RWU = BitField<usart1_t, 1, 1>{}; // bit offset: 1, bit width: 1, Receiver wakeup
    constexpr auto RE = BitField<usart1_t, 2, 1>{}; // bit offset: 2, bit width: 1, Receiver enable
    constexpr auto TE = BitField<usart1_t, 3, 1>{}; // bit offset: 3, bit width: 1, Transmitter enable
    constexpr auto IDLEIE = BitField<usart1_t, 4, 1>{}; // bit offset: 4, bit width: 1, IDLE interrupt enable
    constexpr auto RXNEIE = BitField<usart1_t, 5, 1>{}; // bit offset: 5, bit width: 1, RXNE interrupt enable
    constexpr auto TCIE = BitField<usart1_t, 6, 1>{}; // bit offset: 6, bit width: 1, Transmission complete interrupt enable
    constexpr auto TXEIE = BitField<usart1_t, 7, 1>{}; // bit offset: 7, bit width: 1, TXE interrupt enable
    constexpr auto PEIE = BitField<usart1_t, 8, 1>{}; // bit offset: 8, bit width: 1, PE interrupt enable
    constexpr auto PS = BitField<usart1_t, 9, 1>{}; // bit offset: 9, bit width: 1, Parity selection
    constexpr auto PCE = BitField<usart1_t, 10, 1>{}; // bit offset: 10, bit width: 1, Parity control enable
    constexpr auto WAKE = BitField<usart1_t, 11, 1>{}; // bit offset: 11, bit width: 1, Wakeup method
    constexpr auto M = BitField<usart1_t, 12, 1>{}; // bit offset: 12, bit width: 1, Word length
    constexpr auto UE = BitField<usart1_t, 13, 1>{}; // bit offset: 13, bit width: 1, USART enable
    constexpr auto OVER8 = BitField<usart1_t, 15, 1>{}; // bit offset: 15, bit width: 1, Oversampling mode
    static Register<std::uint32_t, USART1_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, decltype(SBK), decltype(RWU), decltype(RE), decltype(TE), decltype(IDLEIE), decltype(RXNEIE), decltype(TCIE), decltype(TXEIE), decltype(PEIE), decltype(PS), decltype(PCE), decltype(WAKE), decltype(M), decltype(UE), decltype(OVER8)> CR1; // Control register 1

    constexpr auto ADD = BitField<usart1_t, 0, 4>{}; // bit offset: 0, bit width: 4, Address of the USART node
    constexpr auto LBDL = BitField<usart1_t, 5, 1>{}; // bit offset: 5, bit width: 1, lin break detection length
    constexpr auto LBDIE = BitField<usart1_t, 6, 1>{}; // bit offset: 6, bit width: 1, LIN break detection interrupt enable
    constexpr auto LBCL = BitField<usart1_t, 8, 1>{}; // bit offset: 8, bit width: 1, Last bit clock pulse
    constexpr auto CPHA = BitField<usart1_t, 9, 1>{}; // bit offset: 9, bit width: 1, Clock phase
    constexpr auto CPOL = BitField<usart1_t, 10, 1>{}; // bit offset: 10, bit width: 1, Clock polarity
    constexpr auto CLKEN = BitField<usart1_t, 11, 1>{}; // bit offset: 11, bit width: 1, Clock enable
    constexpr auto STOP = BitField<usart1_t, 12, 2>{}; // bit offset: 12, bit width: 2, STOP bits
    constexpr auto LINEN = BitField<usart1_t, 14, 1>{}; // bit offset: 14, bit width: 1, LIN mode enable
    static Register<std::uint32_t, USART1_BASE_ADDRESS + 0x00000010u, 0, READWRITE, decltype(ADD), decltype(LBDL), decltype(LBDIE), decltype(LBCL), decltype(CPHA), decltype(CPOL), decltype(CLKEN), decltype(STOP), decltype(LINEN)> CR2; // Control register 2

    constexpr auto EIE = BitField<usart1_t, 0, 1>{}; // bit offset: 0, bit width: 1, Error interrupt enable
    constexpr auto IREN = BitField<usart1_t, 1, 1>{}; // bit offset: 1, bit width: 1, IrDA mode enable
    constexpr auto IRLP = BitField<usart1_t, 2, 1>{}; // bit offset: 2, bit width: 1, IrDA low-power
    constexpr auto HDSEL = BitField<usart1_t, 3, 1>{}; // bit offset: 3, bit width: 1, Half-duplex selection
    constexpr auto NACK = BitField<usart1_t, 4, 1>{}; // bit offset: 4, bit width: 1, Smartcard NACK enable
    constexpr auto SCEN = BitField<usart1_t, 5, 1>{}; // bit offset: 5, bit width: 1, Smartcard mode enable
    constexpr auto DMAR = BitField<usart1_t, 6, 1>{}; // bit offset: 6, bit width: 1, DMA enable receiver
    constexpr auto DMAT = BitField<usart1_t, 7, 1>{}; // bit offset: 7, bit width: 1, DMA enable transmitter
    constexpr auto RTSE = BitField<usart1_t, 8, 1>{}; // bit offset: 8, bit width: 1, RTS enable
    constexpr auto CTSE = BitField<usart1_t, 9, 1>{}; // bit offset: 9, bit width: 1, CTS enable
    constexpr auto CTSIE = BitField<usart1_t, 10, 1>{}; // bit offset: 10, bit width: 1, CTS interrupt enable
    constexpr auto ONEBIT = BitField<usart1_t, 11, 1>{}; // bit offset: 11, bit width: 1, One sample bit method enable
    static Register<std::uint32_t, USART1_BASE_ADDRESS + 0x00000014u, 0, READWRITE, decltype(EIE), decltype(IREN), decltype(IRLP), decltype(HDSEL), decltype(NACK), decltype(SCEN), decltype(DMAR), decltype(DMAT), decltype(RTSE), decltype(CTSE), decltype(CTSIE), decltype(ONEBIT)> CR3; // Control register 3

    constexpr auto PSC = BitField<usart1_t, 0, 8>{}; // bit offset: 0, bit width: 8, Prescaler value
    constexpr auto GT = BitField<usart1_t, 8, 8>{}; // bit offset: 8, bit width: 8, Guard time value
    static Register<std::uint32_t, USART1_BASE_ADDRESS + 0x00000018u, 0, READWRITE, decltype(PSC), decltype(GT)> GTPR; // Guard time and prescaler register

} // namespace USART1