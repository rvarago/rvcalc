CMAKE_MINIMUM_REQUIRED (VERSION 3.7)
PROJECT(rvcalc)

INCLUDE_DIRECTORIES(src)
INCLUDE_DIRECTORIES(include)
INCLUDE_DIRECTORIES(third-party)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SRC src/*.cpp)

list(REMOVE_ITEM SRC "src/main.cpp")

file(GLOB_RECURSE INCLUDE include/*.hpp)

ADD_LIBRARY(core ${INCLUDE} ${SRC})

ADD_EXECUTABLE(rvcalc src/main.cpp)

TARGET_LINK_LIBRARIES(rvcalc core)

enable_testing()

add_subdirectory(third-party/googletest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

file(GLOB_RECURSE TEST test/*.cpp)

ADD_EXECUTABLE(tests ${TEST})

target_link_libraries(tests
	        pthread
		        gtest
			        gtest_main
				        core)

IF(RELEASE)
	SET(CMAKE_CXX_FLAGS "-Wall -Werror -o2 -std=c++11")
ELSE()
	SET(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")
ENDIF()