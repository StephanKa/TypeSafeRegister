# Build and Test

## Prerequisites

- CMake 3.23 or newer, Conan 2, Git, and a compiler supported by the selected preset.
- Python packages for the generator:

  ```powershell
  python -m pip install cmsis-svd jinja2 conan
  ```

- CMSIS SVD data. Set `CMSIS_SVD_DATA_DIR` to a checkout containing `data/`, or let CMake acquire it by adding `-DFETCH_CMSIS_SVD_DATA=ON` during configuration.

## Windows with MinGW

The current local Windows-friendly preset uses MSYS2 MinGW GCC and Ninja:

```powershell
cmake --preset win32-gcc-x64-mingw-debug
cmake --build --preset win32-gcc-x64-mingw-debug
ctest --preset win32-gcc-x64-mingw-debug --output-on-failure
```

`win32-gcc-x64-mingw-debug` adds `C:/msys64/mingw64/bin` to `PATH`. Use the matching release preset for release builds.

## Visual Studio

```powershell
cmake --preset windows-2022-debug
cmake --build --preset windows-2022-debug
ctest --preset windows-2022-debug --output-on-failure
```

Available Visual Studio preset families are `windows-2019-*` and `windows-2022-*`.

## Linux

The CI compiler families are GCC 14-16 and Clang 20-22. For example:

```bash
cmake --preset clang-22-debug
cmake --build --preset clang-22-debug
ctest --preset clang-22-debug --output-on-failure
```

## Formatting and Static Analysis

After configuring a build directory, invoke the project targets:

```powershell
cmake --build build/debug/win32-gcc-x64-mingw-debug --target clang-format-check
cmake --build build/debug/win32-gcc-x64-mingw-debug --target clang-format-check-fix
```

On Linux with Clang 22, configure `clang-22-debug-static-analysis` to enable clang-tidy, cppcheck, and include-what-you-use, then build it:

```bash
cmake --preset clang-22-debug-static-analysis -DCXX_STANDARD=17
cmake --build --preset clang-22-debug-static-analysis
```

## Cross Compilation

`gcc-arm-debug` and `gcc-arm-release` use the ARM Cortex-M4 GNU toolchain. These builds intentionally do not build or run host tests.