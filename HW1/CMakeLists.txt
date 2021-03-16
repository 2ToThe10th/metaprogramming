cmake_minimum_required(VERSION 3.17)
project(TypeListErase)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest)
include_directories(googletest-master/googletest/include)

add_executable(TypeListErase src/main.cpp src/test.cpp src/TypeList.hpp src/Length.hpp src/Erase.hpp src/EraseUtil.hpp)
target_link_libraries(TypeListErase gtest)