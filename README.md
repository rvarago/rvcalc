# rvcalc
A very basic, but customizable calculator

author: rvarago (varago.rafael@gmail.com)

## Compilation
To compile you need a C++ compiler supporting C++ 14 (tested with 6.3.0)

Compile sources to objects and then to executable:

mkdir build
cd build
cmake ..
make

Then, to run: *./rvcalc*

## Test
The project has unit tests written with Google Test (need gtest):

mkdir build
cd build
cmake ..
make

Then, to run: *./tests*