# Agent Guidance

## Repository Purpose

TypeSafeRegister is a C++ library and generator for type-safe access to CMSIS-SVD peripheral registers. Public runtime headers are in `include/`; SVD-driven templates are in `templates/generator/`; generated files belong in the active build directory.

## Engineering Rules

- Target C++23 unless a task explicitly requires compatibility with an older configured `CXX_STANDARD`.
- Preserve the public API and the zero-overhead, type-safe nature of register access.
- Prefer compile-time computation, validation, and dispatch when inputs are known at compile time. Use `constexpr`, `consteval`, templates, concepts, and type-level metadata where they make invalid states unrepresentable without obscuring the API or causing unnecessary compile-time cost.
- Treat volatile register reads and writes as observable hardware operations. Do not add `const` where it changes those semantics.
- Prefer immutable values, `const` local variables, and `const` member functions whenever they accurately express the interface contract.
- Pass non-owning input by `const&` when it is not cheap to copy; pass small scalar and view types by value.
- Keep ownership explicit. Prefer values and standard-library types over raw owning pointers and manual resource management.
- Use the narrowest practical scope, descriptive names, and small single-purpose functions. Avoid speculative abstractions.
- Use the C++ Core Guidelines as the default reference for resource management, interfaces, expressions, and type safety. Apply them in the context of this embedded, header-only library rather than mechanically.
- Add or update focused Catch2 tests in `test/tests.cpp` for behavior changes. Keep generated artifacts out of source control unless a task explicitly requests them.

## Project Layout

- `include/`: public register and bit-field implementation headers.
- `templates/generator/`: Jinja/Python generator templates.
- `test/`: Catch2 tests and test-time generated headers.
- `examples/`: Nordic and STMicro examples.
- `cmake/`: project build, formatting, and analysis configuration.

## Validation

Use the documented commands in `build.md`. For C++ changes, run the matching preset's build and tests. Run `clang-format-check` for formatting-sensitive changes, and use the Clang 22 static-analysis preset when the required tools are available.