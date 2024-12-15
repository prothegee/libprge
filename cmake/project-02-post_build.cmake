# clear & copying build binary files
set(LIBPRGE_EXAMPLE_DEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}/example/addons/libprge/bin/${LIBPRGE_OUTPUT}")

file(GLOB LIBPRGE_FILES "${LIBPRGE_EXAMPLE_DEST_DIR}/.*")
foreach(file IN LISTS LIBPRGE_FILES)
    file(REMOVE ${file})
endforeach()

file(MAKE_DIRECTORY ${LIBPRGE_EXAMPLE_DEST_DIR})

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${LIBPRGE_OUTPUT_DIR} ${LIBPRGE_EXAMPLE_DEST_DIR}
    COMMENT "copying dirs & files after build"
)
