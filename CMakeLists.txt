cmake_minimum_required(VERSION 3.18.0)
project(cmake_test)

find_package(Threads REQUIRED)

set(INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
add_subdirectory(fmt)
add_subdirectory(src)
add_executable(main main.cpp)   
# target_include_directories(main PUBLIC ${INCLUDE_DIR})
target_link_libraries(main PUBLIC hellolib fmt)
# target_link_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)
