cmake_minimum_required(VERSION 3.10)
project(rvcalc)

add_subdirectory(third-party/googletest)

add_subdirectory(core)
add_subdirectory(test)
add_subdirectory(app)