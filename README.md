# TypeSafeRegister

[![C/C++ CMake CI](https://github.com/StephanKa/TypeSafeRegister/actions/workflows/build_cmake.yml/badge.svg)](https://github.com/StephanKa/TypeSafeRegister/actions/workflows/build_cmake.yml)
[![Deploy Documentation](https://github.com/StephanKa/TypeSafeRegister/actions/workflows/deploy-docs.yml/badge.svg)](https://github.com/StephanKa/TypeSafeRegister/actions/workflows/deploy-docs.yml)

TypeSafeRegister generates type-safe C++ register interfaces from CMSIS-SVD peripheral descriptions. Generated register and field types preserve access modes, bit ranges, enumerations, reset values, and SVD-defined read/write side effects. Host builds use reset-value-backed simulation for tests; cross-compiled builds use volatile memory-mapped I/O.

The project targets C++23 and uses concepts, templates, and compile-time metadata to make invalid register operations fail at compile time while preserving zero-overhead hardware access.

Originally based on [Lefticus' cpp_starter_project](https://github.com/lefticus/cpp_starter_project).

## Documentation

The full guide, generated API reference, build instructions, and repository architecture diagrams are published on [GitHub Pages](https://stephanka.github.io/TypeSafeRegister/). The Sphinx source is in [`docs/`](docs/), and the Pages workflow is in [`.github/workflows/deploy-docs.yml`](.github/workflows/deploy-docs.yml).

## Prerequisites

- CMake 3.23 or newer, Conan 2, Git, and a compiler supported by the selected CMake preset.
- Python packages for SVD generation:

  ```powershell
  python -m pip install cmsis-svd jinja2 conan
  ```

- CMSIS SVD data. Set `CMSIS_SVD_DATA_DIR` to a checkout containing `data/`, or allow CMake to retrieve it with `-DFETCH_CMSIS_SVD_DATA=ON`.

## Quick Start

On Linux, use one of the GCC 14-16 or Clang 20-22 presets. For example:

```bash
cmake --preset clang-22-debug
cmake --build --preset clang-22-debug
ctest --preset clang-22-debug --output-on-failure
```

On Windows with MSYS2 MinGW:

```powershell
cmake --preset win32-gcc-x64-mingw-debug
cmake --build --preset win32-gcc-x64-mingw-debug
ctest --preset win32-gcc-x64-mingw-debug --output-on-failure
```

Use `windows-2019-*` or `windows-2022-*` presets for Visual Studio builds. See [`build.md`](build.md) for all supported presets, static analysis, formatting, and cross-compilation commands.

## How It Works

1. CMake selects an SVD vendor through `CHIP_MANUFACTURER` and an SVD file through `CHIP_FAMILY`.
2. The configured Python generator parses that CMSIS-SVD file and renders one header per peripheral from the Jinja template.
3. Examples and Catch2 tests compile those generated headers together with the reusable runtime headers in [`include/`](include/).
4. The generated types encode register access permissions and field metadata in their types, constraining invalid operations at compile time.

For a different device, pass its vendor and SVD filename during configuration:

```bash
cmake --preset clang-22-debug \
  -DCHIP_MANUFACTURER=STMicro \
  -DCHIP_FAMILY=STM32F20x.svd
```

Generated peripheral headers are build artifacts under `<build-directory>/generated/`; change the generator or templates, not generated files.

## Build Documentation

Install the Sphinx dependencies, configure the documentation target, and build it:

```bash
python -m pip install -r docs/requirements.txt
cmake --preset clang-22-debug -DENABLE_SPHINX=ON -DFETCH_CMSIS_SVD_DATA=ON
cmake --build build/debug/clang-22-debug --target sphinx-docs
```

The generated site is at `build/debug/clang-22-debug/docs/html/index.html`. The GitHub Pages workflow rebuilds and deploys it after relevant changes are pushed to `master`.

## Usage

#### STMicro Example
**STMicro**: main.cpp can be found in the example directory.
````c++
#include <CRC.hpp>
#include <DCMI.hpp>
#include <RNG.hpp>
#include <Output.h>

int main()
{
    details::print("CRC::DR.read():{}\n", CRC::DR.read(CRC::DR_Fields::DR));
    details::print("RNG::SR.read():{}\n", RNG::SR.read(RNG::SR_Fields::DRDY));
    details::print("RNG::SR():{}\n", RNG::SR());
    DCMI::ICR |= DCMI::ICR_Fields::ERR_ISC | DCMI::ICR_Fields::FRAME_ISC;
    // dump register map
    DCMI::CR.dump();
    return static_cast<int>(RNG::SR());
}
````

Example output for STM32F20x.svd
````bash
CRC::DR.read():4294967295
RNG::SR.read():0
RNG::SR():0
Register name:      CR
|-----------------------------------------|
|      CAPTURE               R/W          | <-- Bit 0
|-----------------------------------------|
|         CM                 R/W          | <-- Bit 1
|-----------------------------------------|
|        CROP                R/W          | <-- Bit 2
|-----------------------------------------|
|        JPEG                R/W          | <-- Bit 3
|-----------------------------------------|
|        ESS                 R/W          | <-- Bit 4
|-----------------------------------------|
|       PCKPOL               R/W          | <-- Bit 5
|-----------------------------------------|
|       HSPOL                R/W          | <-- Bit 6
|-----------------------------------------|
|       VSPOL                R/W          | <-- Bit 7
|-----------------------------------------|
|        FCRC                R/W          | <-- Bit 8 - 9
|                                         |
|-----------------------------------------|
|        EDM                 R/W          | <-- Bit 10 - 11
|                                         |
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 12
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 13
|-----------------------------------------|
|       ENABLE               R/W          | <-- Bit 14
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 15
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 16
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 17
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 18
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 19
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 20
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 21
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 22
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 23
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 24
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 25
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 26
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 27
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 28
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 29
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 30
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 31
|-----------------------------------------|
````

#### Nordic Example
**Nordic**: main.cpp can be found in the example directory.
````c++
#include <TIMER0_S.hpp>
#include <Output.h>

int main()
{
    details::print("TIMER0_S::BITMODE():{}\n", TIMER0_S::BITMODE());
    // dump register map
    TIMER0_S::SHORTS.dump();
    return 0;
}

````

Example output for nrf9160.svd
````bash
TIMER0_S::BITMODE():0
Register name:    SHORTS
|-----------------------------------------|
|   COMPARE0_CLEAR           R/W          | <-- Bit 0
|-----------------------------------------|
|   COMPARE1_CLEAR           R/W          | <-- Bit 1
|-----------------------------------------|
|   COMPARE2_CLEAR           R/W          | <-- Bit 2
|-----------------------------------------|
|   COMPARE3_CLEAR           R/W          | <-- Bit 3
|-----------------------------------------|
|   COMPARE4_CLEAR           R/W          | <-- Bit 4
|-----------------------------------------|
|   COMPARE5_CLEAR           R/W          | <-- Bit 5
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 6
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 7
|-----------------------------------------|
|   COMPARE0_STOP            R/W          | <-- Bit 8
|-----------------------------------------|
|   COMPARE1_STOP            R/W          | <-- Bit 9
|-----------------------------------------|
|   COMPARE2_STOP            R/W          | <-- Bit 10
|-----------------------------------------|
|   COMPARE3_STOP            R/W          | <-- Bit 11
|-----------------------------------------|
|   COMPARE4_STOP            R/W          | <-- Bit 12
|-----------------------------------------|
|   COMPARE5_STOP            R/W          | <-- Bit 13
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 14
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 15
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 16
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 17
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 18
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 19
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 20
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 21
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 22
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 23
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 24
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 25
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 26
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 27
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 28
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 29
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 30
|-----------------------------------------|
|      Reserved              N/A          | <-- Bit 31
|-----------------------------------------|
````


## Features

- C++23 default build with concepts, `std::expected`, and `std::format` output
- Compile-time register access checks, field ownership checks, and SVD metadata
- `ENABLE_OUTPUT` selects `std::format` for C++20+; only explicit pre-C++20 compatibility builds use `{fmt}`
- `-DENABLE_AMALGAMATION=ON` generates `generated/include/TypeSafeRegister.hpp`, a single header containing all public runtime register types. Build the `TypeSafeRegisterAmalgamation` target to generate it. Device-specific SVD peripheral headers remain generated separately.
- Type-safe access prevents fields from one register being used with another register
- Support for CMSIS-SVD device families, including STMicro and Nordic examples
- Host-side simulation and embedded MMIO generation from the same SVD input
- Optional register-map dumps for development through `ENABLE_OUTPUT`

## Development

Run the matching CTest preset after behavior changes. For C++ changes, run `clang-format-check`; the `clang-22-debug-static-analysis` preset enables clang-tidy, cppcheck, and include-what-you-use when those tools are available.

The project favors clear, const-correct, compile-time-first C++23 code. The [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines) are the default reference, adapted for header-only code and volatile MMIO. See [`agents.md`](agents.md) for repository rules.

## Size Comparison

- [Windows / Linux development](https://godbolt.org/z/PvxxGsMnd)

  This will result in larger files because of the possibility of dumping the registers.

- [MCU development](https://godbolt.org/z/6xazex19K)
````asm
main:                                   # @main
        or      byte ptr [rip + DCMI::ICR (.0)], 21
        mov     rax, qword ptr [rip + RNG::CR (.0)]
        or      rax, 12
        mov     qword ptr [rip + RNG::CR (.0)], rax
        and     eax, 2147483647
        ret
````

## To-Do

- generate tests for all peripherals
- remove duplicate code in CMake
