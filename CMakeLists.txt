cmake_minimum_required(VERSION 3.7)
project(HRAg)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(HRAg ${SOURCE_FILES})
target_link_libraries(HRAg m)