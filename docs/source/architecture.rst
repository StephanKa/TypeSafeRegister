How the Repository Works
========================

TypeSafeRegister separates device descriptions, code generation, reusable C++ implementation, and consumers. A CMSIS-SVD file is the source of truth for a microcontroller's peripherals. CMake selects the SVD, configures a Python generator, and makes each consumer build depend on the generated headers. The resulting C++ types use the common headers in ``include/`` to enforce the SVD's access rules at compile time.

Repository Structure
--------------------

``include/`` is the reusable header-only implementation. It defines register, register-array, bit-field, enumerated-field, access-control, metadata, and output types.

``templates/`` contains the Python generator template and the Jinja peripheral-header template. These transform SVD metadata into C++ namespaces, field descriptors, register objects, and metadata tables.

``examples/`` contains STMicro and Nordic programs. ``test/`` contains Catch2 tests that run against simulated generated registers. ``cmake/`` provides dependency setup, toolchains, warnings, formatting, static analysis, Doxygen, and Sphinx integration. ``docs/`` contains this Sphinx documentation source.

.. mermaid::

   flowchart TB
       SVD[CMSIS-SVD data] --> CMake[CMake configuration]
       CMake --> Generator[Configured Python generator]
       Generator --> Template[Jinja peripheral template]
       Template --> Generated[Generated peripheral headers]
       Include[include/ runtime headers] --> Consumers
       Generated --> Consumers[Examples and Catch2 tests]
       Consumers --> Host[Host simulation]
       Consumers --> Target[Cross-compiled firmware]

Generation and Build Flow
-------------------------

During configuration, CMake chooses ``CHIP_MANUFACTURER`` and ``CHIP_FAMILY``, locates CMSIS-SVD data, and verifies the Python modules used by the generator. Each example and the tests configure their own copy of the generator with the corresponding build paths. The generated headers are created before the relevant executable compiles.

.. mermaid::

   sequenceDiagram
       participant Developer
       participant CMake
       participant Python as Python generator
       participant SVD as CMSIS-SVD data
       participant Jinja as Jinja template
       participant CXX as C++ compiler
       Developer->>CMake: Configure preset and device variables
       CMake->>SVD: Locate selected manufacturer and SVD file
       CMake->>Python: Configure generateDefinition.py
       Developer->>CMake: Build test or example target
       CMake->>Python: Run generation dependency
       Python->>SVD: Parse peripherals, registers, fields
       Python->>Jinja: Render each peripheral
       Jinja-->>CMake: generated/<PERIPHERAL>.hpp
       CMake->>CXX: Compile consumer with generated and include/ headers

Runtime Model
-------------

Generated fields carry their bit range, access mode, and SVD side-effect metadata as template arguments. ``Register`` uses those descriptors to constrain its read and write functions. This gives host tests a normal in-memory representation while preserving real volatile loads and stores for cross-compiled hardware builds.

.. mermaid::

   flowchart LR
       Application[Application code] --> Register[Generated Register object]
       Field[Generated field descriptor] --> Register
       Register --> Constraint{Access and side-effect constraints}
       Constraint -->|Host build| Simulation[Reset-value-backed simulation]
       Constraint -->|Cross build| MMIO[Volatile memory-mapped I/O]
       Simulation --> Tests[Catch2 tests]
       MMIO --> Hardware[Peripheral register address]

The same public operation can therefore be tested on the host and used on a target. The behavior is intentionally not identical at the storage layer: host simulation makes tests deterministic, while hardware reads and writes are observable device operations that must follow the peripheral reference manual.

Documentation Flow
------------------

When ``ENABLE_SPHINX=ON`` is configured, the ``sphinx-docs`` target first generates Doxygen XML from ``include/``. Sphinx combines those API comments with the hand-written pages in ``docs/source/``. Breathe renders the C++ API reference, and ``sphinxcontrib-mermaid`` renders the diagrams in this page.

.. mermaid::

   flowchart LR
       Headers[Public headers and Doxygen comments] --> Doxygen[Doxygen XML]
       Pages[docs/source reStructuredText] --> Sphinx[Sphinx]
       Doxygen --> Breathe[Breathe]
       Breathe --> Sphinx
       Mermaid[Mermaid directives] --> Sphinx
       Sphinx --> HTML[docs/html/index.html]