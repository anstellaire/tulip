cmake_minimum_required(VERSION 2.8)
project(Tulip)

set(CMAKE_CXX_STANDARD 11)

# ------------------------------------------------------------------------------
#   PROJECT SETTINGS
# ------------------------------------------------------------------------------

include_directories("../include/tulip")

add_executable(test_get test_get.cpp)
add_executable(test_index_sequence test_index_sequence.cpp)
add_executable(test_tuple_apply test_tuple_apply.cpp)
