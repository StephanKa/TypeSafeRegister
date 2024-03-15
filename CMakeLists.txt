CMAKE_MINIMUM_REQUIRED(VERSION 3.19)

INCLUDE(cmake/Conan.cmake)

IF(NOT DEFINED ${CHIP_MANUFACTURER})
    SET(CHIP_MANUFACTURER STMicro)
ENDIF()

IF(NOT DEFINED ${CHIP_FAMILY})
    SET(CHIP_FAMILY STM32F20x.svd)
ENDIF()

IF(NOT DEFINED CXX_STANDARD)
    SET(CMAKE_CXX_STANDARD 20)
ELSE()
    SET(CMAKE_CXX_STANDARD ${CXX_STANDARD})
ENDIF()
MESSAGE("Using C++ standard ${CMAKE_CXX_STANDARD}")

INCLUDE(cmake/Options.cmake)
INCLUDE(cmake/CodeFormat.cmake)

EXECUTE_PROCESS(
        COMMAND git log -1 --format=%h
        WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
        OUTPUT_VARIABLE GIT_HASH
        OUTPUT_STRIP_TRAILING_WHITESPACE
)

CONFIGURE_FILE("templates/version.hpp.in" "${CMAKE_BINARY_DIR}/generated/include/version.hpp" ESCAPE_QUOTES)

FIND_PACKAGE(Python COMPONENTS Interpreter REQUIRED)

# install PyPI Python package using pip
EXECUTE_PROCESS(COMMAND ${Python_EXECUTABLE} -m pip install --user --upgrade pip setuptools jinja2 conan)
EXECUTE_PROCESS(COMMAND ${Python_EXECUTABLE} -m pip install -U -e "git+https://github.com/posborne/cmsis-svd.git#egg=cmsis-svd&subdirectory=python")

EXECUTE_PROCESS(
        COMMAND git clone --filter=blob:none --no-checkout https://github.com/cmsis-svd/cmsis-svd-data.git
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)

EXECUTE_PROCESS(
        COMMAND git sparse-checkout set --no-cone data/STMicro data/Nordic
        COMMAND git checkout
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/cmsis-svd-data
)

# Set the project name to your project name, my project isn't very descriptive
PROJECT(TypeSafeRegister CXX)
INCLUDE(cmake/StandardProjectSettings.cmake)
INCLUDE(cmake/PreventInSourceBuilds.cmake)

# Link this 'library' to set the c++ standard / compile-time options requested
ADD_LIBRARY(project_options INTERFACE)
TARGET_COMPILE_FEATURES(project_options INTERFACE cxx_std_${CMAKE_CXX_STANDARD})

IF(CMAKE_CXX_COMPILER_ID MATCHES ".*Clang")
    OPTION(ENABLE_BUILD_WITH_TIME_TRACE "Enable -ftime-trace to generate time tracing .json files on clang" OFF)
    IF(ENABLE_BUILD_WITH_TIME_TRACE)
        TARGET_COMPILE_OPTIONS(project_options INTERFACE -ftime-trace)
    ENDIF()
ENDIF()

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
ADD_LIBRARY(project_warnings INTERFACE)

# enable cache system
INCLUDE(cmake/Cache.cmake)

# standard compiler warnings
INCLUDE(cmake/CompilerWarnings.cmake)
SET_PROJECT_WARNINGS(project_warnings)

# sanitizer options if supported by compiler
INCLUDE(cmake/Sanitizers.cmake)
ENABLE_SANITIZERS(project_options)

# enable doxygen
INCLUDE(cmake/Doxygen.cmake)
ENABLE_DOXYGEN()

# allow for static analysis options
INCLUDE(cmake/StaticAnalyzers.cmake)

IF(ENABLE_PCH)
    # This sets a global PCH parameter, each project will build its own PCH, which is a good idea if any #define's change
    #
    # consider breaking this out per project as necessary
    TARGET_PRECOMPILE_HEADERS(
            project_options
            INTERFACE
            <vector>
            <utility>)
ENDIF()

IF(ENABLE_FMT)
    ADD_COMPILE_DEFINITIONS(USE_FMT)
ENDIF()

FIND_PACKAGE(Python REQUIRED)
FIND_PACKAGE(fmt REQUIRED)

ADD_SUBDIRECTORY(examples)

IF(CMAKE_CROSSCOMPILING)
    MESSAGE("Test are not built for GCC ARM toolchain!")
    RETURN()
ENDIF()

FIND_PACKAGE(Catch2 REQUIRED)

IF(ENABLE_TESTING)
    ENABLE_TESTING()
    MESSAGE("Building Tests.")
    ADD_SUBDIRECTORY(test)
ENDIF()
