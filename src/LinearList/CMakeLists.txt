include_directories(../../include)

aux_source_directory(. LINEAR_LIST_SRC_DIR)

add_library(linearlist ${LINEAR_LIST_SRC_DIR})

