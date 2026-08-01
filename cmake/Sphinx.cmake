FUNCTION(ENABLE_SPHINX)
    IF(ENABLE_SPHINX)
        FIND_PACKAGE(Doxygen REQUIRED)
                FIND_PACKAGE(Python COMPONENTS Interpreter REQUIRED)
                EXECUTE_PROCESS(
                                COMMAND ${Python_EXECUTABLE} -c "import breathe; import sphinx; import sphinxcontrib.mermaid"
                                RESULT_VARIABLE SPHINX_PYTHON_DEPENDENCIES_RESULT)
                IF (NOT SPHINX_PYTHON_DEPENDENCIES_RESULT EQUAL 0)
                        MESSAGE(FATAL_ERROR "Sphinx documentation requires sphinx, breathe, and sphinxcontrib-mermaid in ${Python_EXECUTABLE}. Install them with '${Python_EXECUTABLE} -m pip install -r ${PROJECT_SOURCE_DIR}/docs/requirements.txt'.")
                ENDIF ()

        SET(SPHINX_BUILD_DIRECTORY "${CMAKE_BINARY_DIR}/docs")
        SET(SPHINX_DOXYGEN_DIRECTORY "${SPHINX_BUILD_DIRECTORY}/doxygen")
        SET(SPHINX_DOXYGEN_XML_DIRECTORY "${SPHINX_DOXYGEN_DIRECTORY}/xml")
        SET(SPHINX_HTML_DIRECTORY "${SPHINX_BUILD_DIRECTORY}/html")
        SET(SPHINX_DOXYFILE "${SPHINX_BUILD_DIRECTORY}/Doxyfile")

        FILE(MAKE_DIRECTORY "${SPHINX_BUILD_DIRECTORY}")
        CONFIGURE_FILE("${PROJECT_SOURCE_DIR}/docs/Doxyfile.in" "${SPHINX_DOXYFILE}" @ONLY)
        FILE(GLOB_RECURSE SPHINX_PUBLIC_HEADERS CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/include/*.h")
        FILE(GLOB_RECURSE SPHINX_SOURCES CONFIGURE_DEPENDS "${PROJECT_SOURCE_DIR}/docs/source/*")

        ADD_CUSTOM_COMMAND(
                OUTPUT "${SPHINX_DOXYGEN_XML_DIRECTORY}/index.xml"
                COMMAND ${DOXYGEN_EXECUTABLE} "${SPHINX_DOXYFILE}"
                DEPENDS "${SPHINX_DOXYFILE}" ${SPHINX_PUBLIC_HEADERS}
                COMMENT "Generating Doxygen XML for Sphinx"
                VERBATIM)
        ADD_CUSTOM_TARGET(doxygen-xml DEPENDS "${SPHINX_DOXYGEN_XML_DIRECTORY}/index.xml")

        ADD_CUSTOM_TARGET(sphinx-docs
                COMMAND ${CMAKE_COMMAND} -E env "TYPESAFE_REGISTER_DOXYGEN_XML_DIR=${SPHINX_DOXYGEN_XML_DIRECTORY}"
                        ${Python_EXECUTABLE} -m sphinx -b html -d "${SPHINX_BUILD_DIRECTORY}/doctrees"
                        "${PROJECT_SOURCE_DIR}/docs/source" "${SPHINX_HTML_DIRECTORY}"
                DEPENDS doxygen-xml ${SPHINX_SOURCES}
                COMMENT "Generating Sphinx HTML documentation"
                VERBATIM)
    ENDIF()
ENDFUNCTION()