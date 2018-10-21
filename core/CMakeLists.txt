add_library(core INTERFACE)
target_include_directories(core INTERFACE include)
target_compile_features(core INTERFACE cxx_std_14)

find_package(Boost 1.54.0)

target_link_libraries(core INTERFACE Boost::boost)