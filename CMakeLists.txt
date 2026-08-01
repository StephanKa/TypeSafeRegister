CMAKE_MINIMUM_REQUIRED(VERSION 3.23)

INCLUDE(cmake/Conan.cmake)

IF(NOT DEFINED CHIP_MANUFACTURER)
    SET(CHIP_MANUFACTURER STMicro)
ENDIF()

IF(NOT DEFINED CHIP_FAMILY)
    SET(CHIP_FAMILY STM32F20x.svd)
ENDIF()

IF(NOT DEFINED CXX_STANDARD)
    SET(CMAKE_CXX_STANDARD 23)
ELSE()
    SET(CMAKE_CXX_STANDARD ${CXX_STANDARD})
ENDIF()
SET(CMAKE_CXX_STANDARD_REQUIRED ON)
SET(CMAKE_CXX_EXTENSIONS OFF)
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
FIND_PACKAGE(Git REQUIRED)

SET(CMSIS_SVD_DATA_DIR "${CMAKE_BINARY_DIR}/cmsis-svd-data" CACHE PATH "Path to a cmsis-svd-data checkout")
OPTION(FETCH_CMSIS_SVD_DATA "Download cmsis-svd-data during CMake configuration" OFF)

EXECUTE_PROCESS(
    COMMAND ${Python_EXECUTABLE} -c "import cmsis_svd; import jinja2"
    RESULT_VARIABLE PYTHON_GENERATOR_DEPENDENCIES_RESULT
)
IF(NOT PYTHON_GENERATOR_DEPENDENCIES_RESULT EQUAL 0)
    MESSAGE(FATAL_ERROR "The generator requires cmsis-svd and jinja2 in ${Python_EXECUTABLE}. Install them with '${Python_EXECUTABLE} -m pip install cmsis-svd jinja2'.")
ENDIF()

IF(NOT EXISTS "${CMSIS_SVD_DATA_DIR}/data")
    IF(NOT FETCH_CMSIS_SVD_DATA)
    MESSAGE(FATAL_ERROR "cmsis-svd-data was not found at ${CMSIS_SVD_DATA_DIR}. Set CMSIS_SVD_DATA_DIR or configure with -DFETCH_CMSIS_SVD_DATA=ON.")
    ENDIF()

    EXECUTE_PROCESS(
        COMMAND ${GIT_EXECUTABLE} clone --depth 1 --filter=blob:none --no-checkout https://github.com/cmsis-svd/cmsis-svd-data.git ${CMSIS_SVD_DATA_DIR}
        RESULT_VARIABLE CMSIS_SVD_CLONE_RESULT
    )
    IF(NOT CMSIS_SVD_CLONE_RESULT EQUAL 0)
    MESSAGE(FATAL_ERROR "Failed to clone cmsis-svd-data.")
    ENDIF()

    EXECUTE_PROCESS(
        COMMAND ${GIT_EXECUTABLE} sparse-checkout set --no-cone data/STMicro data/Nordic
        WORKING_DIRECTORY ${CMSIS_SVD_DATA_DIR}
        RESULT_VARIABLE CMSIS_SVD_SPARSE_CHECKOUT_RESULT
    )
    EXECUTE_PROCESS(
        COMMAND ${GIT_EXECUTABLE} checkout
        WORKING_DIRECTORY ${CMSIS_SVD_DATA_DIR}
        RESULT_VARIABLE CMSIS_SVD_CHECKOUT_RESULT
    )
    IF(NOT CMSIS_SVD_SPARSE_CHECKOUT_RESULT EQUAL 0 OR NOT CMSIS_SVD_CHECKOUT_RESULT EQUAL 0)
    MESSAGE(FATAL_ERROR "Failed to prepare cmsis-svd-data sparse checkout.")
    ENDIF()
ENDIF()

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

SET(TYPESAFE_REGISTER_USE_FMT OFF)
IF(ENABLE_OUTPUT)
    ADD_COMPILE_DEFINITIONS(ENABLE_OUTPUT)
    IF(CMAKE_CXX_STANDARD GREATER_EQUAL 20)
        ADD_COMPILE_DEFINITIONS(TYPESAFE_REGISTER_USE_STD_FORMAT)
    ELSE()
        SET(TYPESAFE_REGISTER_USE_FMT ON)
        FIND_PACKAGE(fmt REQUIRED)
    ENDIF()
ENDIF()

IF(CMAKE_CROSSCOMPILING)
    ADD_COMPILE_DEFINITIONS(TYPESAFE_REGISTER_MMIO)
ENDIF()

IF(ENABLE_AMALGAMATION)
    INCLUDE(cmake/Amalgamation.cmake)
ENDIF()

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
