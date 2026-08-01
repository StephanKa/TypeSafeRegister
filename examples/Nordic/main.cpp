#include <include/version.hpp>
#ifdef ENABLE_OUTPUT
#include <Output.h>
#endif
#include <TIMER0_S.hpp>

int main()
{
#ifdef ENABLE_OUTPUT
    details::print("TIMER0_S::BITMODE():{}\n", TIMER0_S::BITMODE());
#endif
    // dump register map
    TIMER0_S::SHORTS.dump();
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
    return 0;
}
