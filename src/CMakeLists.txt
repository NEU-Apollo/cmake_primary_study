
# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# message(STATUS ${LIBRARY_OUTPUT_PATH})
add_library(hellolib SHARED hello.cpp)
target_include_directories(hellolib PUBLIC ${INCLUDE_DIR})
# message(${INCLUDE_DIR})