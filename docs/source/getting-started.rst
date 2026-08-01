Getting Started
===============

Prerequisites
-------------

Install CMake 3.23 or newer, Conan 2, Git, a compiler supported by the chosen preset, and the Python dependencies used by the generator:

.. code-block:: powershell

   python -m pip install cmsis-svd jinja2 conan

The generator also needs a CMSIS SVD data checkout. Set ``CMSIS_SVD_DATA_DIR`` to a checkout that contains ``data/``, or use ``-DFETCH_CMSIS_SVD_DATA=ON`` when configuring to let CMake fetch it.

Build and Test
--------------

On Windows with MSYS2 MinGW, configure, build, and test with:

.. code-block:: powershell

   cmake --preset win32-gcc-x64-mingw-debug
   cmake --build --preset win32-gcc-x64-mingw-debug
   ctest --preset win32-gcc-x64-mingw-debug --output-on-failure

For Visual Studio 2022, replace the preset with ``windows-2022-debug``. Linux CI supports GCC 14 through 16 and Clang 20 through 22; for example, use ``clang-22-debug``.

Build This Documentation
------------------------

Install the documentation packages into the Python environment CMake will find:

.. code-block:: powershell

   python -m pip install -r docs/requirements.txt

Configure with Sphinx enabled and then build the documentation target:

.. code-block:: powershell

   cmake --preset win32-gcc-x64-mingw-debug -DENABLE_SPHINX=ON
   cmake --build build/debug/win32-gcc-x64-mingw-debug --target sphinx-docs

The HTML site is written to ``build/debug/win32-gcc-x64-mingw-debug/docs/html/index.html``. Enabling Sphinx requires both ``sphinx-build`` and Doxygen; it is opt-in so ordinary builds do not need either tool.