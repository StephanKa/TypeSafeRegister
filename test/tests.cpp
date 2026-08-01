#include <DCMI.hpp>
#include <Register.h>
#include <RegisterArray.h>
#include <SvdTypes.h>
#include <catch2/catch_all.hpp>
#include <limits>

struct ReadOnlyRegisterTag {
};

using TestField = BitField<ReadOnlyRegisterTag, 0, 1, "TEST">;
using ReadOnlyTestRegister = Register<std::uint32_t, 0, 0, READONLY, "READ_ONLY", TestField>;
using ReadWriteTestRegister = Register<std::uint32_t, 0, 0, READWRITE, "READ_WRITE", TestField>;

enum class TestMode : std::uint32_t
{
    Enabled = 2,
};

using TestEnumField = EnumeratedField<TestMode, 4, 2, "MODE">;
using TestCommandField = BitField<ReadOnlyRegisterTag, 3, 1, "CLEAR", WRITEONLY, std::uint32_t, details::ModifiedWriteValue::OneToClear>;
using TestReadActionField = BitField<ReadOnlyRegisterTag, 0, 1, "READ_CLEAR", READONLY, std::uint32_t, details::ModifiedWriteValue::None, details::ReadAction::Clear>;
using TestEnumRegister = Register<std::uint32_t, 0, 0, READWRITE, "ENUM", TestEnumField>;
using TestCommandRegister = Register<std::uint32_t, 0, 0, READWRITE, "COMMAND", TestCommandField>;
using TestReadActionRegister = Register<std::uint32_t, 0, 0, READONLY, "READ_ACTION", TestReadActionField>;
using TestRegisterArray = RegisterArray<std::uint32_t, 0, 0, READWRITE, "ARRAY", 2, sizeof(std::uint32_t), TestField>;

template<typename RegisterType, typename Field>
concept SupportsFieldWrite = requires(RegisterType &reg, Field field) {
    reg |= field;
    reg &= field;
    reg ^= field;
    reg.write(field, std::uint32_t{ 1 }, OrAssign{});
};

template<typename RegisterType, typename Field>
concept SupportsOrdinaryRead = requires(const RegisterType &reg, Field field) {
    reg.read(field);
};

static_assert(!SupportsFieldWrite<ReadOnlyTestRegister, TestField>);
static_assert(SupportsFieldWrite<ReadWriteTestRegister, TestField>);
static_assert(!SupportsOrdinaryRead<TestReadActionRegister, TestReadActionField>);
static_assert(DCMI::info.registerCount == DCMI::register_info.size());
static_assert(static_cast<std::int32_t>(DCMI::Interrupt::DCMI) == 78);


TEST_CASE("Test initial DCMI value", "Initial instance DCMI")
{
    REQUIRE(DCMI::DR() == 0u);
}

TEST_CASE("Test set CWSIZE with CAPCNT", "CWSIZE set CAPCNT")
{
    constexpr std::uint32_t VALUE = 42u;
    REQUIRE(DCMI::CWSIZE() == 0u);
    DCMI::CWSIZE.replace(DCMI::CWSIZE_Fields::CAPCNT, VALUE);
    REQUIRE(DCMI::CWSIZE() == VALUE);
    DCMI::CWSIZE.reset();
    REQUIRE(DCMI::CWSIZE() == 0u);
}

TEST_CASE("Test set CWSIZE with VLINE", "CWSIZE set VLINE")
{
    constexpr std::uint32_t VALUE = 42u * 2u;
    REQUIRE(DCMI::CWSIZE() == 0u);
    DCMI::CWSIZE.replace(DCMI::CWSIZE_Fields::VLINE, VALUE);
    REQUIRE(DCMI::CWSIZE.read(DCMI::CWSIZE_Fields::VLINE) == VALUE);
    REQUIRE(DCMI::CWSIZE() == VALUE << DCMI::CWSIZE_Fields::VLINE.bitOffset);
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

TEST_CASE("Test getMask() for full-width 64-bit mask", "Wide mask")
{
    REQUIRE(details::getMask<std::uint64_t>(0, 64) == std::numeric_limits<std::uint64_t>::max());
    REQUIRE(details::getMask<std::uint64_t>(60, 4) == 0xf000000000000000ULL);
}
TEST_CASE("Test set ICR with OVR_ISC via ^", "ICR set OVR_ISC")
{
    DCMI::ICR ^= DCMI::ICR_Fields::OVR_ISC;
}

TEST_CASE("Test typed enumerated field write", "Enumerated field")
{
    TestEnumRegister reg;
    reg.set(TestEnumField{}, TestMode::Enabled);
    REQUIRE(reg() == 0x20U);
}

TEST_CASE("Test write-one-to-clear command", "Modified write value")
{
    TestCommandRegister reg;
    reg.clear(TestCommandField{});
    REQUIRE(reg() == 0x8U);
}

TEST_CASE("Test read side-effect API", "Read action")
{
    TestReadActionRegister reg;
    REQUIRE(reg.readAndClear(TestReadActionField{}) == 0U);
}

TEST_CASE("Test typed register array", "Register array")
{
    TestRegisterArray::at<0>().replace(TestField{}, 1U);
    REQUIRE(TestRegisterArray::at<0>()() == 1U);
    REQUIRE(TestRegisterArray::at<1>()() == 0U);
}
