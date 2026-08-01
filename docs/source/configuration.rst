Configuration Reference
=======================

Build Presets
-------------

``CMakePresets.json`` defines Linux Clang 20-22 and GCC 14-16 debug and release presets, Visual Studio 2019 and 2022 presets, MinGW GCC presets, Clang 22 static analysis, and ARM GNU cross-compile presets. Use a configure preset before its matching build and test preset.

Options
-------

``ENABLE_TESTING`` is enabled by default and builds the Catch2 suite. ``ENABLE_STMICRO_EXAMPLE`` and ``ENABLE_NORDIC_EXAMPLE`` are also enabled by default. ``ENABLE_AMALGAMATION`` generates a consolidated public header and enables its header check.

``ENABLE_DOXYGEN`` builds the legacy ``doxygen-docs`` target. ``ENABLE_SPHINX`` builds the primary documentation workflow: Doxygen XML followed by Sphinx and Breathe. ``ENABLE_OUTPUT`` enables register dump output.

``ENABLE_COVERAGE`` enables supported GCC or Clang coverage configuration. ``ENABLE_SANITIZER_ADDRESS``, ``ENABLE_SANITIZER_LEAK``, ``ENABLE_SANITIZER_UNDEFINED_BEHAVIOR``, ``ENABLE_SANITIZER_THREAD``, and ``ENABLE_SANITIZER_MEMORY`` control sanitizer instrumentation. ``ENABLE_IPO`` enables link-time optimization, and ``ENABLE_PCH`` enables the project precompiled-header option.

Static Analysis and Formatting
------------------------------

The ``clang-22-debug-static-analysis`` preset enables clang-tidy, cppcheck, and include-what-you-use. It is intended for environments where all three tools are installed.

After configuring a build tree, run the formatting targets:

.. code-block:: powershell

   cmake --build build/debug/win32-gcc-x64-mingw-debug --target clang-format-check
   cmake --build build/debug/win32-gcc-x64-mingw-debug --target clang-format-check-fix

``clang-tidy-check`` checks the configured sources, while ``clang-tidy-diff-check`` runs clang-tidy only against the current Git diff.

Cross Compilation
-----------------

``gcc-arm-debug`` and ``gcc-arm-release`` use the ARM Cortex-M4 GNU toolchain. Cross builds define ``TYPESAFE_REGISTER_MMIO``, produce embedded example artifacts such as ELF, binary, and Intel HEX files, and intentionally skip host-side tests.