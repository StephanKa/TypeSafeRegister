#include "include/version.hpp"
#include <CRC.hpp>
#include <DCMI.hpp>
#include <RNG.hpp>
#include <fmt/format.h>


int main()
{
    fmt::print("CRC::DR.read():{0}\n", CRC::DR.read(CRC::BitFields::DR));
    fmt::print("RNG::SR.read():{0}\n", RNG::SR.read(RNG::BitFields::DRDY));
    fmt::print("RNG::SR():{0}\n", RNG::SR());
    DCMI::ICR |= DCMI::BitFields::ERR_ISC | DCMI::BitFields::FRAME_ISC;
    // fmt::print("DCMI::ICR():{0}\n", DCMI::ICR()); // compile error because it can't be read
    //  dump register map
    DCMI::CR.dump();
    DCMI::ICR.dump();
    fmt::print(R"(major: {}
minor: {}
patch: {}
Githash: {})",
      SoftwareVersion::Major,
      SoftwareVersion::Minor,
      SoftwareVersion::Patch,
      SoftwareVersion::GitHash);
    return static_cast<int>(RNG::SR());
}
