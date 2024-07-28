include_directories(./include)

# 定义测试可执行文件
add_executable(MyTest test.cpp)

# 链接被测试的可执行文件
target_link_libraries(MyTest
    testString
    tree
)