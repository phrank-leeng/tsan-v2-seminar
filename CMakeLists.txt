cmake_minimum_required(VERSION 3.25)
project(tsan_v2_seminar)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

#[[add_executable(fasttrack_incomplete
        src/fasttrack_incomplete.cpp
        src/fasttrack_incomplete.h)]]

add_executable(tsan_v2_seminar
        src/main.cpp
        src/main.h
        src/shadow_word_limitation.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=thread -fPIE -pie -g")