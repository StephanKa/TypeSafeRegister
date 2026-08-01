Examples
========

STMicro
-------

The STMicro example generates peripheral headers for the configured STM32 device. Its ``main.cpp`` demonstrates a field read, a combined write to a register, and a register map dump:

.. code-block:: cpp

   details::print("CRC::DR.read():{}\\n", CRC::DR.read(CRC::DR_Fields::DR));
   DCMI::ICR |= DCMI::ICR_Fields::ERR_ISC | DCMI::ICR_Fields::FRAME_ISC;
   DCMI::CR.dump();

Nordic
------

The Nordic example follows the same generated-header pattern for the nRF9160 SVD by default. It reads the ``TIMER0_S`` bit mode and dumps the ``SHORTS`` register map.

Both examples run their own configured generator as a dependency before compilation. For ARM builds, their post-build steps copy generated headers and produce installable binary artifacts.

Usage Rules
-----------

Use a generated field descriptor from the same register: the library statically rejects cross-register fields. Pass field values unshifted to ``replace`` and ``write``. Prefer named commands such as ``clear`` for SVD write-one-to-clear fields over manually writing masks. Treat the output from ``dump`` as a development aid; it is available only when ``ENABLE_OUTPUT`` is enabled.