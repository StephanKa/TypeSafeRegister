# Automatically enable catch2 to generate ctest targets
IF(CONAN_CATCH2_ROOT_DEBUG)
    INCLUDE(${CONAN_CATCH2_ROOT_DEBUG}/lib/cmake/Catch2/Catch.cmake)
ELSE()
    INCLUDE(${CONAN_CATCH2_ROOT}/lib/cmake/Catch2/Catch.cmake)
ENDIF()

IF(NOT DEFINED ${CHIP_FAMILY})
    SET(CHIP_FAMILY STM32F20x.svd)
ENDIF()

CONFIGURE_FILE(../src/generateDefinition.py.in generateDefinition.py @ONLY)

ADD_LIBRARY(catch_main STATIC catch_main.cpp)
TARGET_LINK_LIBRARIES(catch_main PUBLIC CONAN_PKG::catch2)
TARGET_LINK_LIBRARIES(catch_main PRIVATE project_options)

ADD_EXECUTABLE(tests tests.cpp)
TARGET_LINK_LIBRARIES(tests PRIVATE project_warnings project_options catch_main CONAN_PKG::fmt)
TARGET_INCLUDE_DIRECTORIES(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../src/include)

ADD_CUSTOM_COMMAND(TARGET tests
                   PRE_BUILD
                   COMMAND python3 ${CMAKE_CURRENT_BINARY_DIR}/generateDefinition.py ${CMAKE_CURRENT_SOURCE_DIR}
                   DEPENDS tests)

# automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
CATCH_DISCOVER_TESTS(
        tests
        TEST_PREFIX
        "unittests."
        REPORTER
        xml
        OUTPUT_DIR
        .
        OUTPUT_PREFIX
        "unittests."
        OUTPUT_SUFFIX
        .xml)
