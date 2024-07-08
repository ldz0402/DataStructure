include_directories(../../include)

aux_source_directory(. STACK_SRC_DIR)

add_library(stack ${STACK_SRC_DIR})

