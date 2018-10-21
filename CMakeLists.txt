cmake_minimum_required(VERSION 3.10)
project(rvcalc)

include_directories(third-party)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(core INTERFACE)

target_include_directories(core INTERFACE include)

add_executable(rvcalc src/main.cpp)

target_link_libraries(rvcalc PRIVATE core)

enable_testing()

add_subdirectory(third-party/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

file(GLOB_RECURSE TEST test/*.cpp)

add_executable(tests ${TEST})

target_link_libraries(tests
	        pthread
		        gtest
			        gtest_main
				        core)

IF(RELEASE)
	set(CMAKE_CXX_FLAGS "-Wall -Werror -o2 -std=c++11")
ELSE()
	set(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")
ENDIF()