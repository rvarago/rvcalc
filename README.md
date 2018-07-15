# rvcalc
A very basic, but customizable calculator

author: rvarago (varago.rafael@gmail.com)

## Compilation
To compile you need a C++ compiler supporting C++ 14 (tested with 6.3.0)

Compile sources to objects and then to executable:

```console
mkdir build && cd build
cmake ..
make
./rvcalc
```
Or:

```console
./entry.sh
```
## Test
The project has unit tests written with Google Test:

```console
mkdir build && cd build
cmake ..
make
./tests
```

Or:

```console
./entry.sh test
```
