Code Generation
===============

Pipeline
--------

``templates/generator/generateDefinition.py.in`` is configured by CMake for each consumer: the test executable and both example projects. At build time, it uses ``cmsis_svd`` to parse the selected device SVD and Jinja2 to render ``templates/peripherals/single.jinja2`` once per peripheral.

The output is ``<build-directory>/generated/<PERIPHERAL>.hpp``. It is a build artifact and should not be edited or committed. Change the Python generator or Jinja template when generated output needs to change.

Configuration
-------------

``CHIP_MANUFACTURER`` selects the SVD vendor and defaults to ``STMicro`` at the top level. ``CHIP_FAMILY`` selects the SVD filename and defaults to ``STM32F20x.svd``. The Nordic example supplies ``Nordic`` and ``nrf9160.svd`` when those variables are not already set.

For a different device, provide the variables at configure time:

.. code-block:: bash

   cmake --preset clang-22-debug \
     -DCHIP_MANUFACTURER=STMicro \
     -DCHIP_FAMILY=STM32F20x.svd

The selected file must exist below ``${CMSIS_SVD_DATA_DIR}/data/<manufacturer>/``. During configuration, the project verifies that the active Python interpreter can import both ``cmsis_svd`` and ``jinja2``.

Identifier Handling
-------------------

The generator converts non-C++ identifier characters to underscores, prefixes identifiers that begin with a digit, and disambiguates collisions with numeric suffixes. It validates register widths as 8, 16, 32, or 64 bits and carries SVD access, reset, read-action, and modified-write metadata into the generated types.