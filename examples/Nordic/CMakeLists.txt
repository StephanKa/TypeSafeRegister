SET(PROJECT_NAME NordicExample)

IF(NOT DEFINED ${CHIP_MANUFACTURER})
    SET(CHIP_MANUFACTURER Nordic)
ENDIF()

IF(NOT DEFINED ${CHIP_FAMILY})
    SET(CHIP_FAMILY nrf9160.svd)
ENDIF()

SET(TEMPLATE_FOLDER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../../templates)

CONFIGURE_FILE(../../templates/generator/generateDefinition.py.in generateDefinition.py @ONLY)
ADD_EXECUTABLE(${PROJECT_NAME} main.cpp)
TARGET_LINK_LIBRARIES(${PROJECT_NAME}
                      PRIVATE project_options
                      project_warnings
                      CONAN_PKG::fmt
                      CONAN_PKG::spdlog)
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/generated ../../include)

ADD_CUSTOM_TARGET(${PROJECT_NAME}_Generation
                  COMMAND python${Python_VERSION_MAJOR} ${CMAKE_CURRENT_BINARY_DIR}/generateDefinition.py)
ADD_DEPENDENCIES(${PROJECT_NAME} ${PROJECT_NAME}_Generation)