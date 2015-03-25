CMAKE_MINIMUM_REQUIRED (VERSION 2.8)
PROJECT (GDbusCodegenGlibmmiProxyTest)
FIND_PACKAGE(PkgConfig)

PKG_CHECK_MODULES (GLIBMM REQUIRED glibmm-2.4)
PKG_CHECK_MODULES (GIOMM  REQUIRED giomm-2.4)

IF (NOT CODEGEN)
    MESSAGE (FATAL_ERROR "CODEGEN not specified. Specify path to codegen using -DCODEGEN=<path to code>")
ENDIF ()


# Generate code for the "many-types" service
SET (INTROSPECTION_XML_PROXY ${CMAKE_SOURCE_DIR}/../common/many-types.xml)

SET (GENERATED_PROXY
    ${CMAKE_BINARY_DIR}/generated/many-types_proxy.cpp
    ${CMAKE_BINARY_DIR}/generated/many-types_proxy.h
    ${CMAKE_BINARY_DIR}/generated/many-types_common.cpp
    ${CMAKE_BINARY_DIR}/generated/many-types_common.h
)

ADD_CUSTOM_COMMAND (OUTPUT ${GENERATED_PROXY}
                    COMMAND mkdir -p ${CMAKE_BINARY_DIR}/generated/
                    COMMAND ${CODEGEN} --generate-cpp-code=${CMAKE_BINARY_DIR}/generated/many-types
                                        ${INTROSPECTION_XML_PROXY}
                    DEPENDS ${INTROSPECTION_XML_PROXY}
                    COMMENT "Generate the proxy for the test program")


# Generate code for the "another-service" service
SET (INTROSPECTION_XML_PROXY_TEST_TWO ${CMAKE_SOURCE_DIR}/../common/another-service.xml)

SET (GENERATED_PROXY_TEST_TWO
    ${CMAKE_BINARY_DIR}/generated/another-service_proxy.cpp
    ${CMAKE_BINARY_DIR}/generated/another-service_proxy.h
    ${CMAKE_BINARY_DIR}/generated/another-service_common.cpp
    ${CMAKE_BINARY_DIR}/generated/another-service_common.h
)

ADD_CUSTOM_COMMAND (OUTPUT ${GENERATED_PROXY_TEST_TWO}
                    COMMAND mkdir -p ${CMAKE_BINARY_DIR}/generated/
                    COMMAND ${CODEGEN} --generate-cpp-code=${CMAKE_BINARY_DIR}/generated/another-service
                                        ${INTROSPECTION_XML_PROXY_TEST_TWO}
                    DEPENDS ${INTROSPECTION_XML_PROXY_TEST_TWO}
                    COMMENT "Generate the proxy for another-service")


SET (SOURCES
    testproxymain.cpp
    ${CMAKE_BINARY_DIR}/generated/many-types_proxy.cpp
    ${CMAKE_BINARY_DIR}/generated/many-types_common.cpp
    ${CMAKE_BINARY_DIR}/generated/another-service_proxy.cpp
    ${CMAKE_BINARY_DIR}/generated/another-service_common.cpp
)

SET (HEADERS
    testproxymain.h
    ../common/tools.h
    ${CMAKE_BINARY_DIR}/generated/many-types_proxy.h
    ${CMAKE_BINARY_DIR}/generated/many-types_common.h
    ${CMAKE_BINARY_DIR}/generated/another-service_proxy.h
    ${CMAKE_BINARY_DIR}/generated/another-service_common.h
)

INCLUDE_DIRECTORIES (
    ../common/
    ${GLIBMM_INCLUDE_DIRS}
    ${GIOMM_INCLUDE_DIRS}
    ${CMAKE_BINARY_DIR}/generated/
    ${CMAKE_BINARY_DIR}/generated/)

ADD_EXECUTABLE (proxytest ${SOURCES} ${HEADERS})

TARGET_LINK_LIBRARIES (proxytest
                        ${GLIBMM_LIBRARIES}
                        ${GIOMM_LIBRARIES}
)
