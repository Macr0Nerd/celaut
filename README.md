# CelAut

## Info
CelAut is a simple project so that I can easily play around with a wide array of cellular automatons. I built a basic 
framework to work off of, which is in `include/celaut/celaut.hpp`. This is simply a template class with common 
functions that are useful across many cellular automatons. The most important function, however, is the update method. 
This is the actual implementation of the automaton. The way it works is that the template class will take a struct. 
This will be the data in each cell in a two-dimensional vector.

It's easiest to implement these in header files under `include/automatons` and create a `run()` or `play()` method 
to easily just include the header and run the method. You can change which automaton is being used by editing 
`app/main.cpp`, including the right header from `include/automatons`, and then running the `play()` function from the 
right namespace. Then just recompile and run!

## Automatons
Currently I have implemented:
 * Conway's Game of Life (`include/automatons/conway.hpp`)

## Requirements
 * C++20 capable compiler (gcc, clang, msvc)
 * CMake 3.10 or above

## Building
 1. Clone git repo

 2. In the cloned git repo, run

    ```shell
    mkdir build
    cd build
    cmake ..
    make
    ```
 
 3. Run with

    ```shell
    ./celaut
    ```

## License
Copyright (c) 2020 [Gabriele Alessandro Ron](https://macr0nerd.github.io)

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.