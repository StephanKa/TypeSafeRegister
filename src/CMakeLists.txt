# Generic test that uses conan libs
SET(PROJECT_NAME TypeRegisterExample)
ADD_EXECUTABLE(${PROJECT_NAME} main.cpp)
TARGET_LINK_LIBRARIES(${PROJECT_NAME}
                      PRIVATE project_options
                      project_warnings
                      CONAN_PKG::fmt
                      CONAN_PKG::spdlog)

ADD_CUSTOM_COMMAND(TARGET ${PROJECT_NAME}
                   PRE_BUILD
                   COMMAND python ${CMAKE_CURRENT_SOURCE_DIR}/generateDefinition.py ${CMAKE_CURRENT_SOURCE_DIR}
                   DEPENDS TypeRegisterExample)

TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE generated include)