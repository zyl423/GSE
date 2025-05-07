cmake_minimum_required(VERSION 3.10)
project(HelloWorldApp)

# 设置C++标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 定义Unicode版本的Windows API
add_definitions(-DUNICODE -D_UNICODE)

# 添加可执行文件
add_executable(HelloWorldApp WIN32 main.cpp)

# Windows特定链接设置
if(WIN32)
    target_link_libraries(HelloWorldApp gdi32)
endif() 