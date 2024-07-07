include_directories(../../include)

aux_source_directory(. QUEUE_SRC_DIR)

add_library(queue ${QUEUE_SRC_DIR})

