# rvcalc
A very basic, but customizable calculator.

**(WIP)**

## CI Status

[![Build Status](https://travis-ci.org/rvarago/rvcalc.svg?branch=master)](https://travis-ci.org/rvarago/rvcalc)

## Usage

**NOTE:** To compile you need a C++ compiler supporting C++ 14 (tested with g++ 7.3.0).

### Compile

```console
mkdir build && cd build
cmake ..
cmake --build . 
```

This will create a build folder where the generated artifacts will be put.

### Run

```console
./rvcalc
```

Or:

```console
./entry.sh app
```

### Test


```console
./rvcalc_tests
```

Or:

```console
./entry.sh test
```
