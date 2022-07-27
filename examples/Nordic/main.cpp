#include <TIMER0_S.hpp>
#include <fmt/format.h>

int main()
{
    fmt::print("TIMER0_S::BITMODE():{0}\n", TIMER0_S::BITMODE());
    // dump register map
    TIMER0_S::SHORTS.dump();
    return 0;
}
