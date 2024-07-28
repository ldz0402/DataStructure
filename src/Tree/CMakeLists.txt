include_directories(../../include)

aux_source_directory(. TREE_SRC_DIR)

add_library(tree ${TREE_SRC_DIR})
