Development
===========

Tests
-----

``test/tests.cpp`` uses Catch2 to test simulated registers, field updates, enumerated values, SVD command semantics, side effects, register arrays, and compile-time access constraints. ``test/CMakeLists.txt`` configures a generator instance and makes the test executable depend on generated peripheral headers.

Run the preset-matched CTest command after a change:

.. code-block:: bash

   ctest --preset clang-22-debug --output-on-failure

When changing user-visible behavior, add focused coverage to the Catch2 suite. When changing the amalgamation workflow, configure with ``-DENABLE_AMALGAMATION=ON`` so the dedicated header compilation check is included.

Code Standards
--------------

The project defaults to C++23, requires warnings as errors, and uses explicit compile-time constraints for its hardware access API. Keep public behavior zero-overhead and type-safe. Favor clear names, small functions, values and RAII over raw ownership, immutable locals, and const-qualified interfaces where those accurately express the contract.

Do not add ``const`` in a way that changes a volatile hardware read or write. Do not use ``volatile`` as a synchronization primitive. Preserve the distinction between host simulation and real MMIO.

Repository Layout
-----------------

``include/`` contains public runtime building blocks. ``templates/`` contains the generator and Jinja templates. ``examples/`` holds STMicro and Nordic programs. ``test/`` holds Catch2 coverage and test-time generation. ``cmake/`` contains project configuration modules. ``scripts/`` contains formatting and clang-tidy helpers. ``docs/`` contains the Sphinx source and dependency list.

Contributions
-------------

Do not edit generated headers. Make changes in ``include/``, the generator script, or templates as appropriate, then build and test with a relevant preset. Run the formatting target for C++ changes and use the static analysis preset when its toolchain is available. Keep changes narrow and update this documentation when changing configuration, user-facing API behavior, or generation semantics.