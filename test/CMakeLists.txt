FIND_PACKAGE(fmt REQUIRED)
FIND_PACKAGE(Catch2 REQUIRED)

INCLUDE(CTest)
INCLUDE(Catch)

SET(PROJECT_NAME Tests)
SET(TEMPLATE_FOLDER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../templates)

CONFIGURE_FILE(../templates/generator/generateDefinition.py.in generateDefinition.py @ONLY)

ADD_EXECUTABLE(${PROJECT_NAME} tests.cpp)
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/generated ../include)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} PRIVATE project_warnings project_options Catch2::Catch2WithMain fmt::fmt-header-only)

ADD_CUSTOM_TARGET(${PROJECT_NAME}_Generation
                  COMMAND python${Python_VERSION_MAJOR} ${CMAKE_CURRENT_BINARY_DIR}/generateDefinition.py)
ADD_DEPENDENCIES(${PROJECT_NAME} ${PROJECT_NAME}_Generation)

# automatically discover tests that are defined in catch based test files you can modify the unittests. Set TEST_PREFIX
# to whatever you want, or use different for different binaries
CATCH_DISCOVER_TESTS(
        ${PROJECT_NAME}
        TEST_PREFIX
        unittests.
        REPORTER
        JUnit
        OUTPUT_DIR
        .
        OUTPUT_PREFIX
        unittests.
        OUTPUT_SUFFIX
        .xml)
