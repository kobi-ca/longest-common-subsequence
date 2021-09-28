cmake_minimum_required(VERSION 3.20)
project(longest_common_subsequence)

set(CMAKE_CXX_STANDARD 20)
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS NO_OUTPUT_DIRS)

add_executable(longest_common_subsequence main.cpp)
target_link_libraries(longest_common_subsequence PRIVATE CONAN_PKG::fmt)
