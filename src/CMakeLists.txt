include_directories(../include)

add_subdirectory(LinearList)

aux_source_directory(. UTILS_SRC_DIR)

add_library(utils ${UTILS_SRC_DIR})

