FIND_PACKAGE(fmt REQUIRED)

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
                      fmt::fmt-header-only)

IF(CMAKE_CROSSCOMPILING)
    SET_TARGET_PROPERTIES(${PROJECT_NAME} PROPERTIES SUFFIX ".elf")
    TARGET_LINK_OPTIONS(${PROJECT_NAME}
                        PRIVATE
                        -T${CMAKE_CURRENT_SOURCE_DIR}/linkerscript/linkerScript.ld
                        -Wl,-Map=${PROJECT_NAME}.map
    )

    ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME} POST_BUILD
                       COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_BINARY_DIR}/generated ${CMAKE_BINARY_DIR}/install/generated)

    ADD_CUSTOM_TARGET(${PROJECT_NAME}.bin ALL
                      DEPENDS ${PROJECT_NAME}
                      COMMAND ${CMAKE_OBJCOPY} -Obinary ${CMAKE_BINARY_DIR}/src/${PROJECT_NAME}.elf ${CMAKE_BINARY_DIR}/install/${PROJECT_NAME}.bin
                      COMMAND ${CMAKE_OBJCOPY} -Oihex ${CMAKE_BINARY_DIR}/src/${PROJECT_NAME}.elf ${CMAKE_BINARY_DIR}/install/${PROJECT_NAME}.hex
    )
ENDIF()

TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/generated ../../include ${CMAKE_CURRENT_BINARY_DIR}/../../generated)
ADD_CUSTOM_TARGET(${PROJECT_NAME}_Generation
                  COMMAND python${Python_VERSION_MAJOR} ${CMAKE_CURRENT_BINARY_DIR}/generateDefinition.py)
ADD_DEPENDENCIES(${PROJECT_NAME} ${PROJECT_NAME}_Generation)
