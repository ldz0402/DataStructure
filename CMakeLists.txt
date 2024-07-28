cmake_minimum_required(VERSION 3.0)

project(DataStructure VERSION 1.0.0)

message(STATUS Build Type:  ${CMAKE_BUILD_TYPE})

include_directories(./include)

add_subdirectory(./src)
add_subdirectory(./test)

aux_source_directory(. SRC_DIR)

add_executable(DataStructure ${SRC_DIR})

target_link_libraries(DataStructure
    utils
    linearlist
    stack
    queue
    testString
    tree
)
