cmake_minimum_required(VERSION 3.10)
project(rvcalc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(core INTERFACE)

target_include_directories(core INTERFACE include)

add_executable(rvcalc src/main.cpp)

target_link_libraries(rvcalc PRIVATE core)

enable_testing()

add_subdirectory(third-party/googletest)

add_executable(tests test/calc_test.cpp test/main_test.cpp test/parser_test.cpp)

target_link_libraries(tests	core gtest)

IF(RELEASE)
	set(CMAKE_CXX_FLAGS "-Wall -Werror -o2 -std=c++11")
ELSE()
	set(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")
ENDIF()