#include <CompileTimeMap.h>
#include <DCMI.hpp>
#include <Register.h>
#include <RegisterArray.h>
#include <SvdTypes.h>
#include <catch2/catch_all.hpp>
#include <limits>
#include <string_view>

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
using TestSetCommandField = BitField<ReadOnlyRegisterTag, 4, 1, "SET", WRITEONLY, std::uint32_t, details::ModifiedWriteValue::OneToSet>;
using TestToggleCommandField = BitField<ReadOnlyRegisterTag, 5, 1, "TOGGLE", WRITEONLY, std::uint32_t, details::ModifiedWriteValue::OneToToggle>;
using TestReadActionField = BitField<ReadOnlyRegisterTag, 4, 1, "READ_CLEAR", READONLY, std::uint32_t, details::ModifiedWriteValue::None, details::ReadAction::Clear>;
using TestSingleBitField = BitField<ReadOnlyRegisterTag, 2, 1, "SINGLE">;
using TestMultiBitField = BitField<ReadOnlyRegisterTag, 4, 3, "MULTI">;
using TestEnumRegister = Register<std::uint32_t, 0, 0, READWRITE, "ENUM", TestEnumField>;
using TestCommandRegister = Register<std::uint32_t, 0, 0, READWRITE, "COMMAND", TestCommandField>;
using TestSetCommandRegister = Register<std::uint32_t, 0, 0, READWRITE, "SET_COMMAND", TestSetCommandField>;
using TestToggleCommandRegister = Register<std::uint32_t, 0, 0, READWRITE, "TOGGLE_COMMAND", TestToggleCommandField>;
using TestReadActionRegister = Register<std::uint32_t, 0, 0x10, READONLY, "READ_ACTION", TestReadActionField>;
using TestStateRegister = Register<std::uint32_t, 0, 0xa5, READWRITE, "STATE", TestSingleBitField, TestMultiBitField>;
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
static_assert(TestRegisterArray::size() == 2);

constexpr auto TestMap = CompileTimeMap<int, std::string_view>(Element<int, std::string_view>{ 1, "one" }, Element<int, std::string_view>{ 2, "two" });
static_assert(TestMap.allAreUnique());
static_assert(TestMap.contains(1));
static_assert(!TestMap.contains(3));
static_assert(TestMap.getValues()[1] == "two");


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

    reg = 0xffffffffU;
    reg.set(TestEnumField{}, TestMode::Enabled);
    REQUIRE(reg() == 0xffffffefU);
}

TEST_CASE("Test write-one-to-clear command", "Modified write value")
{
    TestCommandRegister reg;
    reg.clear(TestCommandField{});
    REQUIRE(reg() == 0x8U);
}

TEST_CASE("Test write-one commands", "Modified write value")
{
    TestSetCommandRegister setRegister;
    setRegister.set(TestSetCommandField{});
    REQUIRE(setRegister() == 0x10U);

    TestToggleCommandRegister toggleRegister;
    toggleRegister.toggle(TestToggleCommandField{});
    REQUIRE(toggleRegister() == 0x20U);
}

TEST_CASE("Test read side-effect API", "Read action")
{
    TestReadActionRegister reg;
    REQUIRE(reg.readAndClear(TestReadActionField{}) == 1U);
    REQUIRE(reg() == 0U);
}

TEST_CASE("Test raw register operations and reset", "Register operations")
{
    TestStateRegister reg;
    REQUIRE(reg() == 0xa5U);
    REQUIRE(reg(0x0fU) == 0x05U);

    reg |= 0x10U;
    REQUIRE(reg() == 0xb5U);
    reg &= 0x1fU;
    REQUIRE(reg() == 0x15U);
    reg ^= 0x11U;
    REQUIRE(reg() == 0x04U);

    reg.reset();
    REQUIRE(reg() == 0xa5U);
}

TEST_CASE("Test field operations preserve neighboring bits", "Register field operations")
{
    TestStateRegister reg;
    reg |= TestSingleBitField{};
    REQUIRE(reg() == 0xa5U);
    reg ^= TestSingleBitField{};
    REQUIRE(reg() == 0xa1U);
    reg &= TestSingleBitField{};
    REQUIRE(reg() == 0U);

    reg = 0x8fU;
    reg.replace(TestMultiBitField{}, 0xffU);
    REQUIRE(reg() == 0xffU);
    REQUIRE(reg.read(TestMultiBitField{}) == 0x7U);

    reg = 0x01U;
    reg.write(TestMultiBitField{}, 0x3U, OrAssign{});
    REQUIRE(reg() == 0x31U);
    reg.write(TestMultiBitField{}, 0x2U, AndAssign{});
    REQUIRE(reg() == 0x20U);
    reg.write(TestMultiBitField{}, 0x7U, ExclusiveOrAssign{});
    REQUIRE(reg() == 0x50U);
}

TEST_CASE("Test typed register array", "Register array")
{
    TestRegisterArray::at<0>().replace(TestField{}, 1U);
    REQUIRE(TestRegisterArray::at<0>()() == 1U);
    REQUIRE(TestRegisterArray::at<1>()() == 0U);
}

TEST_CASE("Test compile-time map lookup errors", "Compile-time map")
{
    constexpr auto result = TestMap.getValue(3);
    REQUIRE(!result.has_value());
    REQUIRE(result.error() == details::CompileTimeMapError::KeyNotFound);
}
