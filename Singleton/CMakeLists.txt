cmake_minimum_required(VERSION 2.8)
project(Singleton)

set(CMAKE_CXX_STANDARD 17)

add_executable(Singleton main.cpp LongevityManager.cpp LongevityManager.h SingletonHandler.hpp SingletonInfoInterface.h SingletonInfoInterface.cpp)