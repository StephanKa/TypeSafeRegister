Core Concepts
=============

Generated Types
---------------

Each SVD peripheral becomes a header in the active build directory's ``generated/`` folder. A peripheral type exposes its registers as static objects, and each register owns generated field descriptor types. The generated metadata also records peripheral base addresses, register descriptions, interrupts, and address blocks.

The core public headers in ``include/`` provide ``Register``, ``RegisterArray``, ``BitField``, ``EnumeratedField``, access markers, and compile-time metadata. Generated headers include these building blocks rather than duplicating their implementation.

Access Safety
-------------

The SVD access mode is encoded in each register and field type. ``READONLY`` objects permit reads but not writes; ``WRITEONLY`` objects permit writes but not reads; and ``READWRITE`` objects permit both. Attempts to use an unavailable operation fail through constrained C++ interfaces during compilation.

For ordinary fields, use ``read(field)`` to retrieve an unshifted value and ``replace(field, value)`` to update only that field. Single-bit fields can be combined with ``|=``, ``&=``, and ``^=``. ``write(field, value, OrAssign{})`` and related operation tags apply a selected read-modify-write operation for multi-bit fields. Enumerated fields use ``set(field, Enum::Value)``.

SVD Side Effects
----------------

SVD ``modifiedWriteValues`` and ``readAction`` metadata are preserved by generated descriptors. Command-style fields expose ``clear()``, ``set()``, or ``toggle()`` for write-one operations. A field that clears on read must be accessed with ``readAndClear(field)`` rather than the ordinary ``read(field)`` interface.

Host Simulation and Hardware
----------------------------

For normal host builds, registers store a simulated value initialized from their SVD reset value, allowing unit tests to exercise register behavior. Cross compilation defines ``TYPESAFE_REGISTER_MMIO``; registers then read and write their fixed hardware address through volatile memory-mapped I/O.

Hardware accesses are observable operations. Do not remove, duplicate, cache, or reorder register reads and writes without understanding the device reference manual. ``volatile`` preserves the access operation; it does not provide thread synchronization or atomicity.

Output
------

Set ``ENABLE_OUTPUT=ON`` to enable register-map dumps and formatted output. C++20 and newer builds use ``std::format``; explicit pre-C++20 compatibility configurations use ``{fmt}`` instead.