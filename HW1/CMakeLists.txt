cmake_minimum_required(VERSION 2.8)
project(HW)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(googletest)
include_directories(googletest-master/googletest/include)

add_executable(HW src/main.cpp src/test.cpp src/TypeList.hpp src/Length.hpp src/Erase.hpp src/EraseUtil.hpp src/IArmyFactory.hpp src/IArmyFactory.cpp src/CFactoryUnit.hpp)
target_link_libraries(HW gtest)