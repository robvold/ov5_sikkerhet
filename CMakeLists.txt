cmake_minimum_required(VERSION 3.1)

project(ov5)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Wextra")


add_library(utility INTERFACE)
target_include_directories(utility INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(main main.c)
target_link_libraries(main utility)

enable_testing()
add_subdirectory(tests)