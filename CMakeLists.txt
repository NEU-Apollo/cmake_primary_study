cmake_minimum_required(VERSION 3.18.0)
project(cmake_test)

find_package(Threads REQUIRED)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(fmt)
add_subdirectory(src)

# GLOB：告诉 CMake 使用通配符模式来查找文件。
# sources：保存找到的文件列表的变量名称。
# CMAKE_CONFIGURE_DEPENDS：让 CMake 监视目录中的文件变化（例如新增或删除文件），并在有变化时重新配置。
# ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp：表示当前源文件目录下的 src 目录内的所有 .cpp 文件。

# GLOB 这个名字来源于操作系统和编程中的 "globbing" 概念。Globbing 指的是使用通配符（如 *, ?, [abc] 等）来匹配文件系统中的多个文件名或路径的技术。这种操作通常用于文件名模式匹配和文件查找。
file(GLOB sources CMAKE_CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

add_executable(main)
target_sources(main PUBLIC main.cpp ${sources})
target_include_directories(main PUBLIC ${INCLUDE_DIR})
target_link_libraries(main PUBLIC fmt Threads::Threads)
# target_link_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)
