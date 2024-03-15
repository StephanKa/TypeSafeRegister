# Typesafe Register Usage

This project is based on [Lefticus - cpp_starter_project](https://github.com/lefticus/cpp_starter_project)

![example workflow](https://github.com/StephanKa/TypeSafeRegister/actions/workflows/build_cmake.yml/badge.svg)

## Prerequisites

- install [cmsis_svd](https://github.com/posborne/cmsis-svd/tree/master/python) with ``python3 -m pip install -U -e 'git+https://github.com/posborne/cmsis-svd.git#egg=cmsis-svd&subdirectory=python'``


## General

This project will generate typesafe Register access which will be generated through a jinja template and generates header for each peripheral defined in the **_.svd_** files. 
It also allows the compile time check what access rights it has. 

### Setup 
Setup CMake variable for chip family including the file extension **_.svd_** that you will use.
For a list of files have a look at the data folder at [cmsis_svd data](https://github.com/posborne/cmsis-svd/tree/master/data)

### Usage

#### STMicro Example
**STMicro**: main.cpp can be found in the example directory.
````c++
#include <CRC.hpp>
#include <DCMI.hpp>
#include <RNG.hpp>
#include <fmt/format.h>

int main()
{
    fmt::print("CRC::DR.read():{0}\n", CRC::DR.read<decltype(CRC::BitFields::DR)>());
    fmt::print("RNG::SR.read():{0}\n", RNG::SR.read<decltype(RNG::BitFields::DRDY)>());
    fmt::print("RNG::SR():{0}\n", RNG::SR());
    DCMI::ICR |= DCMI::BitFields::ERR_ISC | DCMI::BitFields::FRAME_ISC;
    //fmt::print("DCMI::ICR():{0}\n", DCMI::ICR()); // compile error because it can't be read
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
#include <fmt/format.h>

int main()
{
    fmt::print("TIMER0_S::BITMODE():{0}\n", TIMER0_S::BITMODE());
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

- C++20 features like concepts
- Typesafe access of registers
- Register defines can't be mixed up, e.g one define for another register
- Supports many chip families, see **cmsis-svd**
- Code generation will create files for development machines and embedded devices, easier write of unit tests
- Dump generated register values , see example output above

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
