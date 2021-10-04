#include <CRC.hpp>
#include <DCMI.hpp>
#include <RNG.hpp>

int main()
{
    //std::cout << CRC::DR.read<decltype(CRC::DR_)>() << "\n";
    //std::cout << RNG::SR.read<decltype(RNG::DRDY)>() << "\n";
    //std::cout << RNG::SR() << "\n";
    DCMI::ICR |= DCMI::ERR_ISC | DCMI::FRAME_ISC;
    // std::cout << DCMI::ICR() << "\n";
    DCMI::CR.dump();
    return static_cast<int>(RNG::SR());
}