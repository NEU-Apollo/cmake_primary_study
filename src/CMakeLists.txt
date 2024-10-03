
# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# message(STATUS ${LIBRARY_OUTPUT_PATH})
# add_library(hellolib SHARED hello.cpp)
# target_include_directories(hellolib PUBLIC ${INCLUDE_DIR})
# message(${INCLUDE_DIR})

add_library(hellolib OBJECT hello.cpp)
add_library(worldlib OBJECT world.cpp)
target_include_directories(hellolib PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_include_directories(worldlib PUBLIC ${PROJECT_SOURCE_DIR}/include)
target_link_directories(hellolib PUBLIC ${PROJECT_SOURCE_DIR}/fmt)
target_link_directories(worldlib PUBLIC ${PROJECT_SOURCE_DIR}/fmt)
target_link_libraries(hellolib PUBLIC fmt)
target_link_libraries(worldlib PUBLIC fmt)
message(STATUS ${PROJECT_SOURCE_DIR}/include)
message(STATUS ${CMAKE_BINARY_DIR})

set(SON_VAR "sonvar" PARENT_SCOPE)