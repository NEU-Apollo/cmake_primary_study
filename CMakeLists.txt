cmake_minimum_required(VERSION 3.18.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) #编译器不支持17就会报错
set(CMAKE_CXX_EXTENSIONS OFF) # 防止使用了编译器的一些扩展，只是用C++标准

#放在project之前，Cmake在project函数里对编译器进行一些检测，看他支不支持C++17的特性
project(cmake_test LANGUAGES C CXX VERSION 1.2.3
                    DESCRIPTION "cmake_test_project"
                    HOMEPAGE_URL "https://github.com/...")

message(STATUS "PROJECT_VERSION " ${PROJECT_VERSION})
message(STATUS "PROJECT_VERSION_MAJOR " ${PROJECT_VERSION_MAJOR})
message(STATUS "PROJECT_VERSION_MINOR " ${PROJECT_VERSION_MINOR})
message(STATUS "PROJECT_VERSION_PATCH " ${PROJECT_VERSION_PATCH})
message(STATUS "PROJECT_DESCREPTION " ${PROJECT_DESCRIPTION})
message(STATUS "PROJECT_HOMEPAGE_URL " ${PROJECT_HOMEPAGE_URL})
# 可以嵌套
message(STATUS "cmake_test_version " ${${PROJECT_NAME}_VERSION})




if(NOT CMAKE_BUILD_TYPE) 
    set(CMAKE_BUILD_TYPE Relase)
endif()

find_package(Threads REQUIRED)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(fmt)
add_subdirectory(src)

# GLOB：告诉 CMake 使用通配符模式来查找文件。
# sources：保存找到的文件列表的变量名称。
# CMAKE_CONFIGURE_DEPENDS：让 CMake 监视目录中的文件变化（例如新增或删除文件），并在有变化时重新配置。
# ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp：表示当前源文件目录下的 src 目录内的所有 .cpp 文件。

# GLOB 这个名字来源于操作系统和编程中的 "globbing" 概念。Globbing 指的是使用通配符（如 *, ?, [abc] 等）来匹配文件系统中的多个文件名或路径的技术。这种操作通常用于文件名模式匹配和文件查找。
# file(GLOB sources CMAKE_CONFIGURE_DEPENDS src/*.cpp)
# file(GLOB_RECURSE sources CMAKE_CONFIGURE_DEPENDS src/*.cpp)

#不监视目录中文件变化
aux_source_directory(. sources)
aux_source_directory(src sources)

add_executable(main)
target_sources(main PUBLIC ${sources})
target_include_directories(main PUBLIC ${INCLUDE_DIR})
target_link_libraries(main PUBLIC fmt Threads::Threads)

# target_link_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)


# 输出项目名称，用于确认当前项目的识别名称
message(STATUS "PROJECT_NAME " ${PROJECT_NAME})

# 输出项目源代码目录，用于确认项目源文件所在的位置，建议使用
message(STATUS "PROJECT_SOURCE_DIR " ${PROJECT_SOURCE_DIR})

# 输出项目二进制目录，用于确认项目编译输出文件的位置
message(STATUS "PROJECT_BINARY_DIR " ${PROJECT_BINARY_DIR})

# 输出当前源代码目录，用于确认当前CMakeLists.txt文件所在的目录
message(STATUS "CMAKE_CURRENT_SOURCE_DIR " ${CMAKE_CURRENT_SOURCE_DIR})

# 输出当前二进制目录，用于确认当前CMakeLists.txt文件对应的编译输出目录
message(STATUS "CMAKE_CURRENT_BINARY_DIR " ${CMAKE_CURRENT_BINARY_DIR})

# 输出最外层CMakeLists.txt文件所在的目录，不建议使用，项目就不能作为子模块被别的项目引用了，建议使用PROJECT_SOURCE_DIR
message(STATUS "CMAKE_SOURCE_DIR " ${CMAKE_SOURCE_DIR})

# 输出当前工程名
message(STATUS "PROJECT_NAME " ${PROJECT_NAME})

# 输出根工程名
message(STATUS "CMAKE_PROJECT_NAME " ${CMAKE_PROJECT_NAME})

# BOOL类型，当前项目否是最顶层根项目
message(STATUS "PROJECT_IS_TOP_LEVEL " ${PROJECT_IS_TOP_LEVEL})