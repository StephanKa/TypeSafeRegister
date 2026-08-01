TypeSafeRegister
================

TypeSafeRegister generates C++ types from CMSIS-SVD files so peripheral register access is checked at compile time. Generated register and field types preserve access permissions, bit ranges, enumerations, and SVD-defined read or write side effects. The project targets C++23 and supports host-side register simulation as well as memory-mapped I/O on cross-compiled targets.

.. toctree::
   :maxdepth: 2
   :caption: Contents

   getting-started
   architecture
   concepts
   generation
   configuration
   examples
   development
   api