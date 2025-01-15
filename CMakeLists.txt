cmake_minimum_required(VERSION 3.15...3.30)
project(libprge
    VERSION "${LIBPRGE_VERSION_STRING}"
    DESCRIPTION "an addons/extension for godot game engine"
    HOMEPAGE_URL "https://github.com/prothegee/libprge"
    LANGUAGES CXX
)

include(CheckIncludeFileCXX)
include(CMakeDependentOption)
include(GenerateExportHeader)
include(FindPackageHandleStandardArgs)
include(cmake/project-00-lib.cmake)
include(cmake/project-01-config.cmake)
include(cmake/project-02-post_build.cmake)

set(PREFIX        "")
set(IMPORT_PREFIX "")
set(CMAKE_STATIC_LIBRARY_PREFIX "")
set(CMAKE_SHARED_LIBRARY_PREFIX "")

if(LIBPRGE_BUILD_AS_STATIC)
    add_library(${PROJECT_NAME} STATIC 
        src/cpp/libprge/registrar.cc src/cpp/libprge/libprge.hh
        src/cpp/libprge/libprge.cc
    )
    message(NOTICE "-- ${PROJECT_NAME}:\n   build as static library")
else()
    add_library(${PROJECT_NAME} SHARED
        src/cpp/libprge/registrar.cc src/cpp/libprge/libprge.hh
        src/cpp/libprge/libprge.cc
    )
    message(NOTICE "-- ${PROJECT_NAME}:\n   build as shared library")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(LIBPRGE_BUILD_COMPILER_ID 1)
    set(LIBPRGE_COMPILER_IS_GNU   true)
    set(LIBPRGE_COMPILER_IS_MSVC  false)
    set(LIBPRGE_COMPILER_IS_CLANG false)

    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-value
        -Wno-unused-variable
        -Wno-reorder
        -Wno-parentheses
        -Wno-switch
        -Wno-format
        -Wno-invalid-offsetof
        -Wno-multichar
        -Wno-char-subscripts
        -Wno-empty-body
        -Wno-unused-function
    )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    set(LIBPRGE_BUILD_COMPILER_ID 2)
    set(LIBPRGE_COMPILER_IS_GNU   false)
    set(LIBPRGE_COMPILER_IS_MSVC  true)
    set(LIBPRGE_COMPILER_IS_CLANG false)

    target_compile_options(${PROJECT_NAME} PRIVATE
        /W4
    )
elseif(CMAKE_CXX_COMPILER_ID MATCHES "[Cc]lang")
    set(LIBPRGE_BUILD_COMPILER_ID 3)
    set(LIBPRGE_COMPILER_IS_GNU   false)
    set(LIBPRGE_COMPILER_IS_MSVC  false)
    set(LIBPRGE_COMPILER_IS_CLANG true)

    target_compile_options(${PROJECT_NAME} PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-value
        -Wno-unused-variable
        -Wno-reorder
        -Wno-parentheses
        -Wno-switch
        -Wno-format
        -Wno-dynamic-class-memaccess
        -Wno-unused-private-field
        -Wno-invalid-offsetof
        -Wno-multichar
        -Wno-char-subscripts
        -Wno-null-conversion
        -Wno-empty-body
        -Wno-unused-lambda-capture
        -Wno-unused-function
        -Wno-tautological-constant-out-of-range-compare
    )
else()
    set(LIBPRGE_BUILD_COMPILER_ID 0)
    set(LIBPRGE_COMPILER_IS_GNU   false)
    set(LIBPRGE_COMPILER_IS_MSVC  false)
    set(LIBPRGE_COMPILER_IS_CLANG false)

    message(NOTICE "-- ${PROJECT_NAME}:\n   -DCMAKE_CXX_COMPILER_ID is not supported as ${CMAKE_CXX_COMPILER_ID}")
endif()

if(LIBPRGE_IS_DEBUG AND LIBPRGE_USING_PYTHON3)
    set(LIBPRGE_DOC_DATA_SOURCE "${CMAKE_CURRENT_BINARY_DIR}/src/cpp/libprge/documentations.gen.cc")

    file(REMOVE "${LIBPRGE_DOC_DATA_SOURCE}")

    file(GLOB_RECURSE LIBPRGE_DOC_XML
        LIST_DIRECTORIES NO
        CONFIGURE_DEPENDS
        "${CMAKE_CURRENT_SOURCE_DIR}/docs/libprge_docs/xml/*.xml"
    )

    generate_doc_source("${LIBPRGE_DOC_DATA_SOURCE}" "${LIBPRGE_DOC_XML}")

    target_sources(${PROJECT_NAME} PRIVATE "${LIBPRGE_DOC_DATA_SOURCE}")
endif()

# godot-cpp
target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBPRGE_GODOTCPP_TARGETS})

# steamworks-sdk
if(LIBPRGE_USING_STEAMWORKS_SDK)
    # reserved
endif()

generate_export_header(${PROJECT_NAME}
    EXPORT_FILE_NAME
        ${PROJECT_SOURCE_DIR}/src/cpp/libprge/base/export.hh
)

configure_file(
    ${PROJECT_SOURCE_DIR}/src/cpp/libprge/base/config.in.hh
    ${PROJECT_SOURCE_DIR}/src/cpp/libprge/base/config.hh
)

aux_source_directory(src/cpp/libprge LIBPRGE_DIR)
aux_source_directory(src/cpp/libprge/base LIBPRGE_DIR_BASE)
aux_source_directory(src/cpp/libprge/constants LIBPRGE_DIR_CONSTANTS)
aux_source_directory(src/cpp/libprge/functions LIBPRGE_DIR_FUNCTIONS)
aux_source_directory(src/cpp/libprge/interfaces LIBPRGE_DIR_INTERFACES)
aux_source_directory(src/cpp/libprge/nodes LIBPRGE_DIR_NODES)
    aux_source_directory(src/cpp/libprge/nodes/components LIBPRGE_DIR_NODES_COMPONENTS)
aux_source_directory(src/cpp/libprge/objects LIBPRGE_DIR_OBJECTS)
aux_source_directory(src/cpp/libprge/refs LIBPRGE_DIR_REFS)
aux_source_directory(src/cpp/libprge/types LIBPRGE_DIR_TYPES)

target_sources(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${LIBPRGE_DIR}
        ${LIBPRGE_DIR_BASE}
        ${LIBPRGE_DIR_CONSTANTS}
        ${LIBPRGE_DIR_FUNCTIONS}
        # 
        ${LIBPRGE_DIR_INTERFACES}
        ${LIBPRGE_DIR_NODES}
            ${LIBPRGE_DIR_NODES_COMPONENTS}
        ${LIBPRGE_DIR_OBJECTS}
        ${LIBPRGE_DIR_REFS}
        ${LIBPRGE_DIR_TYPES}
)

target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}>/src/cpp
)
