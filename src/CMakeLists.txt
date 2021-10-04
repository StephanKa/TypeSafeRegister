# Generic test that uses conan libs
SET(PROJECT_NAME TypeRegisterExample)

IF(NOT DEFINED ${CHIP_FAMILY})
    SET(CHIP_FAMILY STM32F20x.svd)
ENDIF()

CONFIGURE_FILE(generateDefinition.py.in generateDefinition.py @ONLY)
ADD_EXECUTABLE(${PROJECT_NAME} main.cpp)
TARGET_LINK_LIBRARIES(${PROJECT_NAME}
                      PRIVATE project_options
                      project_warnings
                      CONAN_PKG::fmt
                      CONAN_PKG::spdlog)

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME}
                   PRE_BUILD
                   COMMAND python ${CMAKE_CURRENT_BINARY_DIR}/generateDefinition.py ${CMAKE_CURRENT_SOURCE_DIR}
                   DEPENDS ${PROJECT_NAME})

TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE generated include)