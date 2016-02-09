This repository demonstrates how to integrate [Junction](https://github.com/preshing/junction) (and [Turf](https://github.com/preshing/turf)) into a CMake-based project.

Clone this repository, Junction and Turf into adjacent folders, then run CMake on this repository's `CMakeLists.txt`.

    $ git clone https://github.com/preshing/junction-sample.git
    $ git clone https://github.com/preshing/junction.git
    $ git clone https://github.com/preshing/turf.git
    $ cd junction-sample
    $ mkdir build
    $ cd build
    $ cmake <additional options> ..

On Unix-like environments, `cmake` will generate a Makefile by default. On Windows, it will create a Visual Studio solution. To use a specific version of Visual Studio:

    $ cmake -G "Visual Studio 14 2015" ..

To generate an Xcode project on OS X:

    $ cmake -G "Xcode" ..
