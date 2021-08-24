#include <Register.hpp>




namespace UART5
{
    struct uart5_t{};

    constexpr std::uint32_t UART5_BASE_ADDRESS = 0x40005000u;

    constexpr auto PE = BitField<uart5_t, 0, 1, READONLY>{}; // bit offset: 0, bit width: 1, Parity error
    constexpr auto FE = BitField<uart5_t, 1, 1, READONLY>{}; // bit offset: 1, bit width: 1, Framing error
    constexpr auto NF = BitField<uart5_t, 2, 1, READONLY>{}; // bit offset: 2, bit width: 1, Noise detected flag
    constexpr auto ORE = BitField<uart5_t, 3, 1, READONLY>{}; // bit offset: 3, bit width: 1, Overrun error
    constexpr auto IDLE = BitField<uart5_t, 4, 1, READONLY>{}; // bit offset: 4, bit width: 1, IDLE line detected
    constexpr auto RXNE = BitField<uart5_t, 5, 1, READWRITE>{}; // bit offset: 5, bit width: 1, Read data register not empty
    constexpr auto TC = BitField<uart5_t, 6, 1, READWRITE>{}; // bit offset: 6, bit width: 1, Transmission complete
    constexpr auto TXE = BitField<uart5_t, 7, 1, READONLY>{}; // bit offset: 7, bit width: 1, Transmit data register empty
    constexpr auto LBD = BitField<uart5_t, 8, 1, READWRITE>{}; // bit offset: 8, bit width: 1, LIN break detection flag
    static Register<std::uint32_t, UART5_BASE_ADDRESS + 0x00000000u, 192, READWRITE, decltype(PE), decltype(FE), decltype(NF), decltype(ORE), decltype(IDLE), decltype(RXNE), decltype(TC), decltype(TXE), decltype(LBD)> SR; // Status register

    constexpr auto DR_ = BitField<uart5_t, 0, 9>{}; // bit offset: 0, bit width: 9, Data value
    static Register<std::uint32_t, UART5_BASE_ADDRESS + 0x00000004u, 0, READWRITE, decltype(DR_)> DR; // Data register

    constexpr auto DIV_Fraction = BitField<uart5_t, 0, 4>{}; // bit offset: 0, bit width: 4, fraction of USARTDIV
    constexpr auto DIV_Mantissa = BitField<uart5_t, 4, 12>{}; // bit offset: 4, bit width: 12, mantissa of USARTDIV
    static Register<std::uint32_t, UART5_BASE_ADDRESS + 0x00000008u, 0, READWRITE, decltype(DIV_Fraction), decltype(DIV_Mantissa)> BRR; // Baud rate register

    constexpr auto SBK = BitField<uart5_t, 0, 1>{}; // bit offset: 0, bit width: 1, Send break
    constexpr auto RWU = BitField<uart5_t, 1, 1>{}; // bit offset: 1, bit width: 1, Receiver wakeup
    constexpr auto RE = BitField<uart5_t, 2, 1>{}; // bit offset: 2, bit width: 1, Receiver enable
    constexpr auto TE = BitField<uart5_t, 3, 1>{}; // bit offset: 3, bit width: 1, Transmitter enable
    constexpr auto IDLEIE = BitField<uart5_t, 4, 1>{}; // bit offset: 4, bit width: 1, IDLE interrupt enable
    constexpr auto RXNEIE = BitField<uart5_t, 5, 1>{}; // bit offset: 5, bit width: 1, RXNE interrupt enable
    constexpr auto TCIE = BitField<uart5_t, 6, 1>{}; // bit offset: 6, bit width: 1, Transmission complete interrupt enable
    constexpr auto TXEIE = BitField<uart5_t, 7, 1>{}; // bit offset: 7, bit width: 1, TXE interrupt enable
    constexpr auto PEIE = BitField<uart5_t, 8, 1>{}; // bit offset: 8, bit width: 1, PE interrupt enable
    constexpr auto PS = BitField<uart5_t, 9, 1>{}; // bit offset: 9, bit width: 1, Parity selection
    constexpr auto PCE = BitField<uart5_t, 10, 1>{}; // bit offset: 10, bit width: 1, Parity control enable
    constexpr auto WAKE = BitField<uart5_t, 11, 1>{}; // bit offset: 11, bit width: 1, Wakeup method
    constexpr auto M = BitField<uart5_t, 12, 1>{}; // bit offset: 12, bit width: 1, Word length
    constexpr auto UE = BitField<uart5_t, 13, 1>{}; // bit offset: 13, bit width: 1, USART enable
    constexpr auto OVER8 = BitField<uart5_t, 15, 1>{}; // bit offset: 15, bit width: 1, Oversampling mode
    static Register<std::uint32_t, UART5_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, decltype(SBK), decltype(RWU), decltype(RE), decltype(TE), decltype(IDLEIE), decltype(RXNEIE), decltype(TCIE), decltype(TXEIE), decltype(PEIE), decltype(PS), decltype(PCE), decltype(WAKE), decltype(M), decltype(UE), decltype(OVER8)> CR1; // Control register 1

    constexpr auto ADD = BitField<uart5_t, 0, 4>{}; // bit offset: 0, bit width: 4, Address of the USART node
    constexpr auto LBDL = BitField<uart5_t, 5, 1>{}; // bit offset: 5, bit width: 1, lin break detection length
    constexpr auto LBDIE = BitField<uart5_t, 6, 1>{}; // bit offset: 6, bit width: 1, LIN break detection interrupt enable
    constexpr auto STOP = BitField<uart5_t, 12, 2>{}; // bit offset: 12, bit width: 2, STOP bits
    constexpr auto LINEN = BitField<uart5_t, 14, 1>{}; // bit offset: 14, bit width: 1, LIN mode enable
    static Register<std::uint32_t, UART5_BASE_ADDRESS + 0x00000010u, 0, READWRITE, decltype(ADD), decltype(LBDL), decltype(LBDIE), decltype(STOP), decltype(LINEN)> CR2; // Control register 2

    constexpr auto EIE = BitField<uart5_t, 0, 1>{}; // bit offset: 0, bit width: 1, Error interrupt enable
    constexpr auto IREN = BitField<uart5_t, 1, 1>{}; // bit offset: 1, bit width: 1, IrDA mode enable
    constexpr auto IRLP = BitField<uart5_t, 2, 1>{}; // bit offset: 2, bit width: 1, IrDA low-power
    constexpr auto HDSEL = BitField<uart5_t, 3, 1>{}; // bit offset: 3, bit width: 1, Half-duplex selection
    constexpr auto ONEBIT = BitField<uart5_t, 11, 1>{}; // bit offset: 11, bit width: 1, One sample bit method enable
    static Register<std::uint32_t, UART5_BASE_ADDRESS + 0x00000014u, 0, READWRITE, decltype(EIE), decltype(IREN), decltype(IRLP), decltype(HDSEL), decltype(ONEBIT)> CR3; // Control register 3

} // namespace UART5