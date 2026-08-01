#include <include/version.hpp>
#include <CRC.hpp>
#include <DCMI.hpp>
#ifdef ENABLE_OUTPUT
#include <Output.h>
#endif
#include <RNG.hpp>


int main()
{
#ifdef ENABLE_OUTPUT
    details::print("CRC::DR.read():{}\n", CRC::DR.read(CRC::DR_Fields::DR));
    details::print("RNG::SR.read():{}\n", RNG::SR.read(RNG::SR_Fields::DRDY));
    details::print("RNG::SR():{}\n", RNG::SR());
#endif
    DCMI::ICR |= DCMI::ICR_Fields::ERR_ISC | DCMI::ICR_Fields::FRAME_ISC;
    //  dump register map
    DCMI::CR.dump();
    DCMI::ICR.dump();
#ifdef ENABLE_OUTPUT
    details::print(R"(major: {}
minor: {}
patch: {}
Githash: {})",
      SoftwareVersion::Major,
      SoftwareVersion::Minor,
      SoftwareVersion::Patch,
      SoftwareVersion::GitHash);
#endif
    return static_cast<int>(RNG::SR());
}
