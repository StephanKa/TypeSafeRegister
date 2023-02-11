SET(PROJECT_NAME Tests)

# Automatically enable catch2 to generate ctest targets
IF(CONAN_CATCH2_ROOT_DEBUG)
    INCLUDE(${CONAN_CATCH2_ROOT_DEBUG}/lib/cmake/Catch2/Catch.cmake)
ELSE()
    INCLUDE(${CONAN_CATCH2_ROOT}/lib/cmake/Catch2/Catch.cmake)
ENDIF()

SET(TEMPLATE_FOLDER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../templates)

CONFIGURE_FILE(../templates/generator/generateDefinition.py.in generateDefinition.py @ONLY)

ADD_LIBRARY(catch_main STATIC catch_main.cpp)
TARGET_LINK_LIBRARIES(catch_main PUBLIC CONAN_PKG::catch2)
TARGET_LINK_LIBRARIES(catch_main PRIVATE project_options)

ADD_EXECUTABLE(${PROJECT_NAME} tests.cpp)
TARGET_LINK_LIBRARIES(${PROJECT_NAME} PRIVATE project_warnings project_options catch_main CONAN_PKG::fmt)
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/generated ../include)

ADD_CUSTOM_TARGET(${PROJECT_NAME}_Generation
                  COMMAND python${Python_VERSION_MAJOR} ${CMAKE_CURRENT_BINARY_DIR}/generateDefinition.py)
ADD_DEPENDENCIES(${PROJECT_NAME} ${PROJECT_NAME}_Generation)
# automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
CATCH_DISCOVER_TESTS(
        ${PROJECT_NAME}
        TEST_PREFIX
        "unittests."
        REPORTER
        JUnit
        OUTPUT_DIR
        .
        OUTPUT_PREFIX
        "unittests."
        OUTPUT_SUFFIX
        .xml)
