#include <DCMI.hpp>
#include <Register.hpp>
#include <catch2/catch_all.hpp>


TEST_CASE("Test initial DCMI value", "Initial instance DCMI")
{
    REQUIRE(DCMI::DR() == 0u);
}

TEST_CASE("Test set CWSIZE with CAPCNT", "CWSIZE set CAPCNT")
{
    constexpr std::uint32_t VALUE = 42u;
    REQUIRE(DCMI::CWSIZE() == 0u);
    DCMI::CWSIZE.write(DCMI::BitFields::CAPCNT, VALUE);
    REQUIRE(DCMI::CWSIZE() == VALUE);
    DCMI::CWSIZE.reset();
    REQUIRE(DCMI::CWSIZE() == 0u);
}

TEST_CASE("Test set CWSIZE with VLINE", "CWSIZE set VLINE")
{
    constexpr std::uint32_t VALUE = 42u * 2u;
    REQUIRE(DCMI::CWSIZE() == 0u);
    DCMI::CWSIZE.write(DCMI::BitFields::VLINE, VALUE);
    REQUIRE(DCMI::CWSIZE.read<decltype(DCMI::BitFields::VLINE)>() == VALUE);
    REQUIRE(DCMI::CWSIZE() == VALUE << DCMI::BitFields::VLINE.bitOffset);
    DCMI::CWSIZE.reset();
    REQUIRE(DCMI::CWSIZE() == 0u);
}

TEST_CASE("Test getMask()", "Simple mask")
{
    constexpr std::size_t width = 1;
    constexpr std::size_t offset = 0;
    REQUIRE(details::getMask<std::uint32_t>(offset, width) == 1);
}

TEST_CASE("Test getMask() for mask 7", "Simple mask")
{
    constexpr std::size_t width = 3;
    constexpr std::size_t offset = 0;
    REQUIRE(details::getMask<std::uint32_t>(offset, width) == 7);
}
