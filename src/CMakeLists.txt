include_directories(../include)

add_subdirectory(LinearList)
add_subdirectory(Stack)
add_subdirectory(Queue)
add_subdirectory(TestString)

aux_source_directory(. UTILS_SRC_DIR)

add_library(utils ${UTILS_SRC_DIR})

