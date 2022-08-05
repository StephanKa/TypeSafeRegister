#include <TIMER0_S.hpp>
#include <fmt/format.h>
#include "include/version.hpp"

int main()
{
    fmt::print("TIMER0_S::BITMODE():{0}\n", TIMER0_S::BITMODE());
    // dump register map
    TIMER0_S::SHORTS.dump();
    fmt::print(R"(major: {}
minor: {}
patch: {}
Githash: {})", SoftwareVersion::Major, SoftwareVersion::Minor, SoftwareVersion::Patch, SoftwareVersion::GitHash);
    return 0;
}
