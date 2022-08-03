#include <CRC.hpp>
#include <DCMI.hpp>
#include <RNG.hpp>
#include <fmt/format.h>

int main()
{
    fmt::print("CRC::DR.read():{0}\n", CRC::DR.read<decltype(CRC::BitFields::DR)>());
    fmt::print("RNG::SR.read():{0}\n", RNG::SR.read<decltype(RNG::BitFields::DRDY)>());
    fmt::print("RNG::SR():{0}\n", RNG::SR());
    DCMI::ICR |= DCMI::BitFields::ERR_ISC | DCMI::BitFields::FRAME_ISC;
    //fmt::print("DCMI::ICR():{0}\n", DCMI::ICR()); // compile error because it can't be read
    // dump register map
    DCMI::CR.dump();
    return static_cast<int>(RNG::SR());
}