CMAKE_MINIMUM_REQUIRED (VERSION 2.8)
PROJECT (GDbusCodegenGlibmmProxyTest)
FIND_PACKAGE(PkgConfig)

PKG_CHECK_MODULES (GLIBMM REQUIRED glibmm-2.4)
PKG_CHECK_MODULES (GIOMM  REQUIRED giomm-2.4)

IF (NOT CODEGEN)
    MESSAGE (FATAL_ERROR "CODEGEN not specified. Specify path to codegen using -DCODEGEN=<path to code>")
ENDIF ()

SET (GENERATED_STUB
    ${CMAKE_BINARY_DIR}/generated/many-types_stub.cpp
    ${CMAKE_BINARY_DIR}/generated/many-types_stub.h
)

SET (INTROSPECTION_XML ${CMAKE_SOURCE_DIR}/../common/many-types.xml)

ADD_CUSTOM_COMMAND (OUTPUT ${GENERATED_STUB}
                    COMMAND mkdir -p ${CMAKE_BINARY_DIR}/generated/
                    COMMAND ${CODEGEN} --generate-cpp-code=${CMAKE_BINARY_DIR}/generated/many-types
                                        ${INTROSPECTION_XML}
                    DEPENDS ${INTROSPECTION_XML}
                    COMMENT "Generate the stub for the test program")

SET (SOURCES
    teststubmain.cpp
    ${CMAKE_BINARY_DIR}/generated/many-types_stub.cpp
)

SET (HEADERS
    teststubmain.h
    ../common/tools.h
    ${CMAKE_BINARY_DIR}/generated/many-types_stub.h
)

INCLUDE_DIRECTORIES (
    ../common/
    ${GLIBMM_INCLUDE_DIRS}
    ${GIOMM_INCLUDE_DIRS}
    ${CMAKE_BINARY_DIR}/generated/
    ${CMAKE_BINARY_DIR}/generated/)

ADD_EXECUTABLE (stubtest ${SOURCES} ${HEADERS})

TARGET_LINK_LIBRARIES (stubtest
                        ${GLIBMM_LIBRARIES}
                        ${GIOMM_LIBRARIES}
)
