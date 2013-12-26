# SDLpp

## Description

These are my C++ bindings to SDL2. They are intended to encapsulate
common functionality in an RAII fashion so that SDL structs are
destroyed when the container object goes out of scope.

## Dependencies

The library fully utilizes C++11 constructs such as initializer lists,
`unique_ptr`, move semantics, and the like so a modern C++ compiler is
necessary. In addition, the library links against `SDL2`,
`SDL2_image`, and `SDL2_ttf`.

## Building

The project requires Cmake > v2.8.11 although an older Cmake is likely
to work and creates a shared library.

```
mkdir build
cd build
cmake ..
make
```

This will create an `libSDLpp.so` library that your application can
link against. Remember to add the `include` directory as well. In
addition, this will build all the examples in the `examples`
directory.

## Usage

Please refer to individual examples in the `examples` directory for
usage instructions.
