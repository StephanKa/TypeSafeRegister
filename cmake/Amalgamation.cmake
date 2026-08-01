SET(TYPESAFE_REGISTER_PUBLIC_HEADERS
    AssignmentOperations.h
    BitName.h
    BitType.h
    BitInfo.h
    CompileTimeMap.h
    details.h
    SvdTypes.h
    BitField.h
    EnumeratedField.h
    Output.h
    Register.h
    RegisterArray.h)

SET(TYPESAFE_REGISTER_AMALGAMATED_HEADER "${CMAKE_BINARY_DIR}/generated/include/TypeSafeRegister.hpp")
SET(TYPESAFE_REGISTER_PUBLIC_HEADER_PATHS)
FOREACH(header IN LISTS TYPESAFE_REGISTER_PUBLIC_HEADERS)
    LIST(APPEND TYPESAFE_REGISTER_PUBLIC_HEADER_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/include/${header}")
ENDFOREACH()

ADD_CUSTOM_COMMAND(
    OUTPUT "${TYPESAFE_REGISTER_AMALGAMATED_HEADER}"
    COMMAND ${Python_EXECUTABLE} "${CMAKE_CURRENT_SOURCE_DIR}/scripts/amalgamate_headers.py"
            --include-dir "${CMAKE_CURRENT_SOURCE_DIR}/include"
            --output "${TYPESAFE_REGISTER_AMALGAMATED_HEADER}"
    DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/scripts/amalgamate_headers.py" ${TYPESAFE_REGISTER_PUBLIC_HEADER_PATHS}
    COMMENT "Generating TypeSafeRegister amalgamated header"
    VERBATIM)

ADD_CUSTOM_TARGET(TypeSafeRegisterAmalgamation ALL DEPENDS "${TYPESAFE_REGISTER_AMALGAMATED_HEADER}")