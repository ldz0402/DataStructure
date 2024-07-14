include_directories(../../include)

aux_source_directory(. STRING_SRC_DIR)

add_library(testString ${STRING_SRC_DIR})

