#include <Register.hpp>




namespace SDIO
{
    struct sdio_t{};

    constexpr std::uint32_t SDIO_BASE_ADDRESS = 0x40012c00u;

    constexpr auto PWRCTRL = BitField<sdio_t, 0, 2>{}; // bit offset: 0, bit width: 2, PWRCTRL
    static Register<std::uint32_t, SDIO_BASE_ADDRESS + 0x00000000u, 0, READWRITE, decltype(PWRCTRL)> POWER; // power control register

    constexpr auto CLKDIV = BitField<sdio_t, 0, 8>{}; // bit offset: 0, bit width: 8, Clock divide factor
    constexpr auto CLKEN = BitField<sdio_t, 8, 1>{}; // bit offset: 8, bit width: 1, Clock enable bit
    constexpr auto PWRSAV = BitField<sdio_t, 9, 1>{}; // bit offset: 9, bit width: 1, Power saving configuration bit
    constexpr auto BYPASS = BitField<sdio_t, 10, 1>{}; // bit offset: 10, bit width: 1, Clock divider bypass enable bit
    constexpr auto WIDBUS = BitField<sdio_t, 11, 2>{}; // bit offset: 11, bit width: 2, Wide bus mode enable bit
    constexpr auto NEGEDGE = BitField<sdio_t, 13, 1>{}; // bit offset: 13, bit width: 1, SDIO_CK dephasing selection bit
    constexpr auto HWFC_EN = BitField<sdio_t, 14, 1>{}; // bit offset: 14, bit width: 1, HW Flow Control enable
    static Register<std::uint32_t, SDIO_BASE_ADDRESS + 0x00000004u, 0, READWRITE, decltype(CLKDIV), decltype(CLKEN), decltype(PWRSAV), decltype(BYPASS), decltype(WIDBUS), decltype(NEGEDGE), decltype(HWFC_EN)> CLKCR; // SDI clock control register

    constexpr auto CMDARG = BitField<sdio_t, 0, 32>{}; // bit offset: 0, bit width: 32, Command argument
    static Register<std::uint32_t, SDIO_BASE_ADDRESS + 0x00000008u, 0, READWRITE, decltype(CMDARG)> ARG; // argument register

    constexpr auto CMDINDEX = BitField<sdio_t, 0, 6>{}; // bit offset: 0, bit width: 6, Command index
    constexpr auto WAITRESP = BitField<sdio_t, 6, 2>{}; // bit offset: 6, bit width: 2, Wait for response bits
    constexpr auto WAITINT = BitField<sdio_t, 8, 1>{}; // bit offset: 8, bit width: 1, CPSM waits for interrupt request
    constexpr auto WAITPEND = BitField<sdio_t, 9, 1>{}; // bit offset: 9, bit width: 1, CPSM Waits for ends of data transfer (CmdPend internal signal).
    constexpr auto CPSMEN = BitField<sdio_t, 10, 1>{}; // bit offset: 10, bit width: 1, Command path state machine (CPSM) Enable bit
    constexpr auto SDIOSuspend = BitField<sdio_t, 11, 1>{}; // bit offset: 11, bit width: 1, SD I/O suspend command
    constexpr auto ENCMDcompl = BitField<sdio_t, 12, 1>{}; // bit offset: 12, bit width: 1, Enable CMD completion
    constexpr auto nIEN = BitField<sdio_t, 13, 1>{}; // bit offset: 13, bit width: 1, not Interrupt Enable
    constexpr auto CE_ATACMD = BitField<sdio_t, 14, 1>{}; // bit offset: 14, bit width: 1, CE-ATA command
    static Register<std::uint32_t, SDIO_BASE_ADDRESS + 0x0000000cu, 0, READWRITE, decltype(CMDINDEX), decltype(WAITRESP), decltype(WAITINT), decltype(WAITPEND), decltype(CPSMEN), decltype(SDIOSuspend), decltype(ENCMDcompl), decltype(nIEN), decltype(CE_ATACMD)> CMD; // command register

    constexpr auto RESPCMD_ = BitField<sdio_t, 0, 6>{}; // bit offset: 0, bit width: 6, Response command index
    static Register<std::uint32_t, SDIO_BASE_ADDRESS + 0x00000010u, 0, READONLY, decltype(RESPCMD_)> RESPCMD; // command response register

    constexpr auto CARDSTATUS1 = BitField<sdio_t, 0, 32>{}; // bit offset: 0, bit width: 32, see Table 132.
    static Register<std::uint32_t, SDIO_BASE_ADDRESS + 0x00000014u, 0, READONLY, decltype(CARDSTATUS1)> RESP1; // response 1..4 register

    constexpr auto CARDSTATUS2 = BitField<sdio_t, 0, 32>{}; // bit offset: 0, bit width: 32, see Table 132.
    static Register<std::uint32_t, SDIO_BASE_ADDRESS + 0x00000018u, 0, READONLY, decltype(CARDSTATUS2)> RESP2; // response 1..4 register

    constexpr auto CARDSTATUS3 = BitField<sdio_t, 0, 32>{}; // bit offset: 0, bit width: 32, see Table 132.
    static Register<std::uint32_t, SDIO_BASE_ADDRESS + 0x0000001cu, 0, READONLY, decltype(CARDSTATUS3)> RESP3; // response 1..4 register

    constexpr auto CARDSTATUS4 = BitField<sdio_t, 0, 32>{}; // bit offset: 0, bit width: 32, see Table 132.
    static Register<std::uint32_t, SDIO_BASE_ADDRESS + 0x00000020u, 0, READONLY, decltype(CARDSTATUS4)> RESP4; // response 1..4 register

    constexpr auto DATATIME = BitField<sdio_t, 0, 32>{}; // bit offset: 0, bit width: 32, Data timeout period
    static Register<std::uint32_t, SDIO_BASE_ADDRESS + 0x00000024u, 0, READWRITE, decltype(DATATIME)> DTIMER; // data timer register

    constexpr auto DATALENGTH = BitField<sdio_t, 0, 25>{}; // bit offset: 0, bit width: 25, Data length value
    static Register<std::uint32_t, SDIO_BASE_ADDRESS + 0x00000028u, 0, READWRITE, decltype(DATALENGTH)> DLEN; // data length register

    constexpr auto DTEN = BitField<sdio_t, 0, 1>{}; // bit offset: 0, bit width: 1, DTEN
    constexpr auto DTDIR = BitField<sdio_t, 1, 1>{}; // bit offset: 1, bit width: 1, Data transfer direction selection
    constexpr auto DTMODE = BitField<sdio_t, 2, 1>{}; // bit offset: 2, bit width: 1, Data transfer mode selection 1: Stream or SDIO multibyte data transfer.
    constexpr auto DMAEN = BitField<sdio_t, 3, 1>{}; // bit offset: 3, bit width: 1, DMA enable bit
    constexpr auto DBLOCKSIZE = BitField<sdio_t, 4, 4>{}; // bit offset: 4, bit width: 4, Data block size
    constexpr auto RWSTART = BitField<sdio_t, 8, 1>{}; // bit offset: 8, bit width: 1, Read wait start
    constexpr auto RWSTOP = BitField<sdio_t, 9, 1>{}; // bit offset: 9, bit width: 1, Read wait stop
    constexpr auto RWMOD = BitField<sdio_t, 10, 1>{}; // bit offset: 10, bit width: 1, Read wait mode
    constexpr auto SDIOEN = BitField<sdio_t, 11, 1>{}; // bit offset: 11, bit width: 1, SD I/O enable functions
    static Register<std::uint32_t, SDIO_BASE_ADDRESS + 0x0000002cu, 0, READWRITE, decltype(DTEN), decltype(DTDIR), decltype(DTMODE), decltype(DMAEN), decltype(DBLOCKSIZE), decltype(RWSTART), decltype(RWSTOP), decltype(RWMOD), decltype(SDIOEN)> DCTRL; // data control register

    constexpr auto DATACOUNT = BitField<sdio_t, 0, 25>{}; // bit offset: 0, bit width: 25, Data count value
    static Register<std::uint32_t, SDIO_BASE_ADDRESS + 0x00000030u, 0, READONLY, decltype(DATACOUNT)> DCOUNT; // data counter register

    constexpr auto CCRCFAIL = BitField<sdio_t, 0, 1>{}; // bit offset: 0, bit width: 1, Command response received (CRC check failed)
    constexpr auto DCRCFAIL = BitField<sdio_t, 1, 1>{}; // bit offset: 1, bit width: 1, Data block sent/received (CRC check failed)
    constexpr auto CTIMEOUT = BitField<sdio_t, 2, 1>{}; // bit offset: 2, bit width: 1, Command response timeout
    constexpr auto DTIMEOUT = BitField<sdio_t, 3, 1>{}; // bit offset: 3, bit width: 1, Data timeout
    constexpr auto TXUNDERR = BitField<sdio_t, 4, 1>{}; // bit offset: 4, bit width: 1, Transmit FIFO underrun error
    constexpr auto RXOVERR = BitField<sdio_t, 5, 1>{}; // bit offset: 5, bit width: 1, Received FIFO overrun error
    constexpr auto CMDREND = BitField<sdio_t, 6, 1>{}; // bit offset: 6, bit width: 1, Command response received (CRC check passed)
    constexpr auto CMDSENT = BitField<sdio_t, 7, 1>{}; // bit offset: 7, bit width: 1, Command sent (no response required)
    constexpr auto DATAEND = BitField<sdio_t, 8, 1>{}; // bit offset: 8, bit width: 1, Data end (data counter, SDIDCOUNT, is zero)
    constexpr auto STBITERR = BitField<sdio_t, 9, 1>{}; // bit offset: 9, bit width: 1, Start bit not detected on all data signals in wide bus mode
    constexpr auto DBCKEND = BitField<sdio_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data block sent/received (CRC check passed)
    constexpr auto CMDACT = BitField<sdio_t, 11, 1>{}; // bit offset: 11, bit width: 1, Command transfer in progress
    constexpr auto TXACT = BitField<sdio_t, 12, 1>{}; // bit offset: 12, bit width: 1, Data transmit in progress
    constexpr auto RXACT = BitField<sdio_t, 13, 1>{}; // bit offset: 13, bit width: 1, Data receive in progress
    constexpr auto TXFIFOHE = BitField<sdio_t, 14, 1>{}; // bit offset: 14, bit width: 1, Transmit FIFO half empty: at least 8 words can be written into the FIFO
    constexpr auto RXFIFOHF = BitField<sdio_t, 15, 1>{}; // bit offset: 15, bit width: 1, Receive FIFO half full: there are at least 8 words in the FIFO
    constexpr auto TXFIFOF = BitField<sdio_t, 16, 1>{}; // bit offset: 16, bit width: 1, Transmit FIFO full
    constexpr auto RXFIFOF = BitField<sdio_t, 17, 1>{}; // bit offset: 17, bit width: 1, Receive FIFO full
    constexpr auto TXFIFOE = BitField<sdio_t, 18, 1>{}; // bit offset: 18, bit width: 1, Transmit FIFO empty
    constexpr auto RXFIFOE = BitField<sdio_t, 19, 1>{}; // bit offset: 19, bit width: 1, Receive FIFO empty
    constexpr auto TXDAVL = BitField<sdio_t, 20, 1>{}; // bit offset: 20, bit width: 1, Data available in transmit FIFO
    constexpr auto RXDAVL = BitField<sdio_t, 21, 1>{}; // bit offset: 21, bit width: 1, Data available in receive FIFO
    constexpr auto SDIOIT = BitField<sdio_t, 22, 1>{}; // bit offset: 22, bit width: 1, SDIO interrupt received
    constexpr auto CEATAEND = BitField<sdio_t, 23, 1>{}; // bit offset: 23, bit width: 1, CE-ATA command completion signal received for CMD61
    static Register<std::uint32_t, SDIO_BASE_ADDRESS + 0x00000034u, 0, READONLY, decltype(CCRCFAIL), decltype(DCRCFAIL), decltype(CTIMEOUT), decltype(DTIMEOUT), decltype(TXUNDERR), decltype(RXOVERR), decltype(CMDREND), decltype(CMDSENT), decltype(DATAEND), decltype(STBITERR), decltype(DBCKEND), decltype(CMDACT), decltype(TXACT), decltype(RXACT), decltype(TXFIFOHE), decltype(RXFIFOHF), decltype(TXFIFOF), decltype(RXFIFOF), decltype(TXFIFOE), decltype(RXFIFOE), decltype(TXDAVL), decltype(RXDAVL), decltype(SDIOIT), decltype(CEATAEND)> STA; // status register

    constexpr auto CCRCFAILC = BitField<sdio_t, 0, 1>{}; // bit offset: 0, bit width: 1, CCRCFAIL flag clear bit
    constexpr auto DCRCFAILC = BitField<sdio_t, 1, 1>{}; // bit offset: 1, bit width: 1, DCRCFAIL flag clear bit
    constexpr auto CTIMEOUTC = BitField<sdio_t, 2, 1>{}; // bit offset: 2, bit width: 1, CTIMEOUT flag clear bit
    constexpr auto DTIMEOUTC = BitField<sdio_t, 3, 1>{}; // bit offset: 3, bit width: 1, DTIMEOUT flag clear bit
    constexpr auto TXUNDERRC = BitField<sdio_t, 4, 1>{}; // bit offset: 4, bit width: 1, TXUNDERR flag clear bit
    constexpr auto RXOVERRC = BitField<sdio_t, 5, 1>{}; // bit offset: 5, bit width: 1, RXOVERR flag clear bit
    constexpr auto CMDRENDC = BitField<sdio_t, 6, 1>{}; // bit offset: 6, bit width: 1, CMDREND flag clear bit
    constexpr auto CMDSENTC = BitField<sdio_t, 7, 1>{}; // bit offset: 7, bit width: 1, CMDSENT flag clear bit
    constexpr auto DATAENDC = BitField<sdio_t, 8, 1>{}; // bit offset: 8, bit width: 1, DATAEND flag clear bit
    constexpr auto STBITERRC = BitField<sdio_t, 9, 1>{}; // bit offset: 9, bit width: 1, STBITERR flag clear bit
    constexpr auto DBCKENDC = BitField<sdio_t, 10, 1>{}; // bit offset: 10, bit width: 1, DBCKEND flag clear bit
    constexpr auto SDIOITC = BitField<sdio_t, 22, 1>{}; // bit offset: 22, bit width: 1, SDIOIT flag clear bit
    constexpr auto CEATAENDC = BitField<sdio_t, 23, 1>{}; // bit offset: 23, bit width: 1, CEATAEND flag clear bit
    static Register<std::uint32_t, SDIO_BASE_ADDRESS + 0x00000038u, 0, READWRITE, decltype(CCRCFAILC), decltype(DCRCFAILC), decltype(CTIMEOUTC), decltype(DTIMEOUTC), decltype(TXUNDERRC), decltype(RXOVERRC), decltype(CMDRENDC), decltype(CMDSENTC), decltype(DATAENDC), decltype(STBITERRC), decltype(DBCKENDC), decltype(SDIOITC), decltype(CEATAENDC)> ICR; // interrupt clear register

    constexpr auto CCRCFAILIE = BitField<sdio_t, 0, 1>{}; // bit offset: 0, bit width: 1, Command CRC fail interrupt enable
    constexpr auto DCRCFAILIE = BitField<sdio_t, 1, 1>{}; // bit offset: 1, bit width: 1, Data CRC fail interrupt enable
    constexpr auto CTIMEOUTIE = BitField<sdio_t, 2, 1>{}; // bit offset: 2, bit width: 1, Command timeout interrupt enable
    constexpr auto DTIMEOUTIE = BitField<sdio_t, 3, 1>{}; // bit offset: 3, bit width: 1, Data timeout interrupt enable
    constexpr auto TXUNDERRIE = BitField<sdio_t, 4, 1>{}; // bit offset: 4, bit width: 1, Tx FIFO underrun error interrupt enable
    constexpr auto RXOVERRIE = BitField<sdio_t, 5, 1>{}; // bit offset: 5, bit width: 1, Rx FIFO overrun error interrupt enable
    constexpr auto CMDRENDIE = BitField<sdio_t, 6, 1>{}; // bit offset: 6, bit width: 1, Command response received interrupt enable
    constexpr auto CMDSENTIE = BitField<sdio_t, 7, 1>{}; // bit offset: 7, bit width: 1, Command sent interrupt enable
    constexpr auto DATAENDIE = BitField<sdio_t, 8, 1>{}; // bit offset: 8, bit width: 1, Data end interrupt enable
    constexpr auto STBITERRIE = BitField<sdio_t, 9, 1>{}; // bit offset: 9, bit width: 1, Start bit error interrupt enable
    constexpr auto DBCKENDIE = BitField<sdio_t, 10, 1>{}; // bit offset: 10, bit width: 1, Data block end interrupt enable
    constexpr auto CMDACTIE = BitField<sdio_t, 11, 1>{}; // bit offset: 11, bit width: 1, Command acting interrupt enable
    constexpr auto TXACTIE = BitField<sdio_t, 12, 1>{}; // bit offset: 12, bit width: 1, Data transmit acting interrupt enable
    constexpr auto RXACTIE = BitField<sdio_t, 13, 1>{}; // bit offset: 13, bit width: 1, Data receive acting interrupt enable
    constexpr auto TXFIFOHEIE = BitField<sdio_t, 14, 1>{}; // bit offset: 14, bit width: 1, Tx FIFO half empty interrupt enable
    constexpr auto RXFIFOHFIE = BitField<sdio_t, 15, 1>{}; // bit offset: 15, bit width: 1, Rx FIFO half full interrupt enable
    constexpr auto TXFIFOFIE = BitField<sdio_t, 16, 1>{}; // bit offset: 16, bit width: 1, Tx FIFO full interrupt enable
    constexpr auto RXFIFOFIE = BitField<sdio_t, 17, 1>{}; // bit offset: 17, bit width: 1, Rx FIFO full interrupt enable
    constexpr auto TXFIFOEIE = BitField<sdio_t, 18, 1>{}; // bit offset: 18, bit width: 1, Tx FIFO empty interrupt enable
    constexpr auto RXFIFOEIE = BitField<sdio_t, 19, 1>{}; // bit offset: 19, bit width: 1, Rx FIFO empty interrupt enable
    constexpr auto TXDAVLIE = BitField<sdio_t, 20, 1>{}; // bit offset: 20, bit width: 1, Data available in Tx FIFO interrupt enable
    constexpr auto RXDAVLIE = BitField<sdio_t, 21, 1>{}; // bit offset: 21, bit width: 1, Data available in Rx FIFO interrupt enable
    constexpr auto SDIOITIE = BitField<sdio_t, 22, 1>{}; // bit offset: 22, bit width: 1, SDIO mode interrupt received interrupt enable
    constexpr auto CEATAENDIE = BitField<sdio_t, 23, 1>{}; // bit offset: 23, bit width: 1, CE-ATA command completion signal received interrupt enable
    static Register<std::uint32_t, SDIO_BASE_ADDRESS + 0x0000003cu, 0, READWRITE, decltype(CCRCFAILIE), decltype(DCRCFAILIE), decltype(CTIMEOUTIE), decltype(DTIMEOUTIE), decltype(TXUNDERRIE), decltype(RXOVERRIE), decltype(CMDRENDIE), decltype(CMDSENTIE), decltype(DATAENDIE), decltype(STBITERRIE), decltype(DBCKENDIE), decltype(CMDACTIE), decltype(TXACTIE), decltype(RXACTIE), decltype(TXFIFOHEIE), decltype(RXFIFOHFIE), decltype(TXFIFOFIE), decltype(RXFIFOFIE), decltype(TXFIFOEIE), decltype(RXFIFOEIE), decltype(TXDAVLIE), decltype(RXDAVLIE), decltype(SDIOITIE), decltype(CEATAENDIE)> MASK; // mask register

    constexpr auto FIFOCOUNT = BitField<sdio_t, 0, 24>{}; // bit offset: 0, bit width: 24, Remaining number of words to be written to or read from the FIFO.
    static Register<std::uint32_t, SDIO_BASE_ADDRESS + 0x00000048u, 0, READONLY, decltype(FIFOCOUNT)> FIFOCNT; // FIFO counter register

    constexpr auto FIFOData = BitField<sdio_t, 0, 32>{}; // bit offset: 0, bit width: 32, Receive and transmit FIFO data
    static Register<std::uint32_t, SDIO_BASE_ADDRESS + 0x00000080u, 0, READWRITE, decltype(FIFOData)> FIFO; // data FIFO register

} // namespace SDIO