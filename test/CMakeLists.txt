enable_testing()

add_executable(rvcalc_tests
        src/calc_test.cpp
        src/main_test.cpp
        src/parser_test.cpp
)

target_link_libraries(rvcalc_tests PRIVATE core gtest)
