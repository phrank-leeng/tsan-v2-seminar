cmake_minimum_required(VERSION 3.25)
project(tsan_v2_seminar)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

#[[add_executable(fasttrack_incomplete
        src/fasttrack_incomplete.cpp
        src/fasttrack_incomplete.h)]]

add_executable(vector_clock_limitation
        src/vector_clock_limitation_example.cpp
        src/vector_clock_limitation_example.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread -fPIE -pie -g")