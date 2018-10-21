cmake_minimum_required(VERSION 3.10)
project(rvcalc)

add_library(core INTERFACE)

target_compile_features(core INTERFACE cxx_std_14)

target_include_directories(core INTERFACE include)

add_executable(rvcalc src/main.cpp)

target_link_libraries(rvcalc PRIVATE core)

enable_testing()

add_subdirectory(third-party/googletest)

add_executable(tests test/calc_test.cpp test/main_test.cpp test/parser_test.cpp)

target_link_libraries(tests	core gtest)
