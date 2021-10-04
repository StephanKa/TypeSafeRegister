#include <Register.hpp>

namespace RNG
{
    struct rng_t{};

    constexpr std::uint32_t RNG_BASE_ADDRESS = 0x50060800u;

    constexpr auto RNGEN = BitField<rng_t, 2, 1, "RNGEN">{}; // bit offset: 2, bit width: 1, Random number generator enable
    constexpr auto IE = BitField<rng_t, 3, 1, "IE">{}; // bit offset: 3, bit width: 1, Interrupt enable
    static Register<std::uint32_t, RNG_BASE_ADDRESS + 0x00000000u, 0, READWRITE, "CR", decltype(RNGEN), decltype(IE)> CR; // control register

    constexpr auto DRDY = BitField<rng_t, 0, 1, "DRDY", READONLY>{}; // bit offset: 0, bit width: 1, Data ready
    constexpr auto CECS = BitField<rng_t, 1, 1, "CECS", READONLY>{}; // bit offset: 1, bit width: 1, Clock error current status
    constexpr auto SECS = BitField<rng_t, 2, 1, "SECS", READONLY>{}; // bit offset: 2, bit width: 1, Seed error current status
    constexpr auto CEIS = BitField<rng_t, 5, 1, "CEIS", READWRITE>{}; // bit offset: 5, bit width: 1, Clock error interrupt status
    constexpr auto SEIS = BitField<rng_t, 6, 1, "SEIS", READWRITE>{}; // bit offset: 6, bit width: 1, Seed error interrupt status
    static Register<std::uint32_t, RNG_BASE_ADDRESS + 0x00000004u, 0, READWRITE, "SR", decltype(DRDY), decltype(CECS), decltype(SECS), decltype(CEIS), decltype(SEIS)> SR; // status register

    constexpr auto RNDATA = BitField<rng_t, 0, 32, "RNDATA">{}; // bit offset: 0, bit width: 32, Random data
    static Register<std::uint32_t, RNG_BASE_ADDRESS + 0x00000008u, 0, READONLY, "DR", decltype(RNDATA)> DR; // data register

} // namespace RNG