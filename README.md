# Typesafe Register Usage

This project is based on [Lefticus - cpp_starter_project](https://github.com/lefticus/cpp_starter_project)

![example workflow](https://github.com/StephanKa/TypeSafeRegister/actions/workflows/build_cmake.yml/badge.svg)

## Prerequisites

- [cmsis_svd](https://github.com/posborne/cmsis-svd/tree/master/python)

## General

This project will generate typesafe Register access which will be generated through a jinja template and generates header for each peripheral defined in the **_.svd_** files. 
It also allows the compile time check what access rights it has. 

### Setup 
Setup CMake variable for chip family including the file extension **_.svd_** that you will use.
For a list of files have a look at the data folder at [cmsis_svd data](https://github.com/posborne/cmsis-svd/tree/master/data)

### Usage

Example main.cpp can be found in the source directory.
````c++
#include <CRC.hpp>
#include <DCMI.hpp>
#include <RNG.hpp>
#include <fmt/format.h>

int main()
{
    fmt::print("CRC::DR.read():{0}\n", CRC::DR.read<decltype(CRC::DR_)>());
    fmt::print("RNG::SR.read():{0}\n", RNG::SR.read<decltype(RNG::DRDY)>());
    fmt::print("RNG::SR():{0}\n", RNG::SR());
    DCMI::ICR |= DCMI::ERR_ISC | DCMI::FRAME_ISC;
    // fmt::print("DCMI::ICR():{0}\n", DCMI::ICR()); // compile error because it can't be read
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
Register      CR
| --------------------|
| CAPTURE     R/W     | <-- Bit 0
| --------------------|
|    CM       R/W     | <-- Bit 1
| --------------------|
|   CROP      R/W     | <-- Bit 2
| --------------------|
|   JPEG      R/W     | <-- Bit 3
| --------------------|
|   ESS       R/W     | <-- Bit 4
| --------------------|
|  PCKPOL     R/W     | <-- Bit 5
| --------------------|
|  HSPOL      R/W     | <-- Bit 6
| --------------------|
|  VSPOL      R/W     | <-- Bit 7
| --------------------|
|   FCRC      R/W     | <-- Bit 8 - 9
|                     |
| --------------------|
|   EDM       R/W     | <-- Bit 10 - 11
|                     |
| --------------------|
| Reserved    N/A     | <-- Bit 12
| --------------------|
| Reserved    N/A     | <-- Bit 13
| --------------------|
|  ENABLE     R/W     | <-- Bit 14
| --------------------|
| Reserved    N/A     | <-- Bit 15
| --------------------|
| Reserved    N/A     | <-- Bit 16
| --------------------|
| Reserved    N/A     | <-- Bit 17
| --------------------|
| Reserved    N/A     | <-- Bit 18
| --------------------|
| Reserved    N/A     | <-- Bit 19
| --------------------|
| Reserved    N/A     | <-- Bit 20
| --------------------|
| Reserved    N/A     | <-- Bit 21
| --------------------|
| Reserved    N/A     | <-- Bit 22
| --------------------|
| Reserved    N/A     | <-- Bit 23
| --------------------|
| Reserved    N/A     | <-- Bit 24
| --------------------|
| Reserved    N/A     | <-- Bit 25
| --------------------|
| Reserved    N/A     | <-- Bit 26
| --------------------|
| Reserved    N/A     | <-- Bit 27
| --------------------|
| Reserved    N/A     | <-- Bit 28
| --------------------|
| Reserved    N/A     | <-- Bit 29
| --------------------|
| Reserved    N/A     | <-- Bit 30
| --------------------|
| Reserved    N/A     | <-- Bit 31
| --------------------|

````


## Features

- C++20 features like concepts
- Typesafe access of registers
- Register defines can't be mixed up, e.g one define for another register
- Supports many chip families, see **cmsis-svd**
- Code generation will create files for development machines and embedded devices, easier write of unit tests
- Dump generated register values , see example output above

## Size Comparison

- [Windows / Linux development](https://godbolt.org/z/rK8vcG4n6)

  This will result in larger files because of the possibility of dumping the registers.

- [MCU development](https://godbolt.org/z/bqPhda5fE) 
````asm
main:  # @main
        mov     rax, qword ptr [rip + DCMI::ICR+8]
        or      dword ptr [rax], 21
        mov     rcx, qword ptr [rip + RNG::CR+8]
        mov     eax, dword ptr [rcx]
        or      eax, 12
        mov     dword ptr [rcx], eax
        and     eax, 2147483647
        ret
DCMI::ICR:
        .long   0                               # 0x0
        .zero   4
        .quad   DCMI::ICR

RNG::CR:
        .long   0                               # 0x0
        .zero   4
        .quad   RNG::CR
````

## To-Do

- add support for enumerated values
  - get list of all enumerated values and reduce generated output
- rework jinja
- add Register support for enum class
