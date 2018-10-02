

#refer t o https://github.com/open-source-parsers/jsoncpp/wiki/Building

#
```
mkdir -p build/debug
    cd build/debug
    cmake -DCMAKE_BUILD_TYPE=debug -DBUILD_STATIC_LIBS=ON -DBUILD_SHARED_LIBS=OFF -DARCHIVE_INSTALL_DIR=. -G "Unix Makefiles" ../..
make
```

For a good pkg-config file, add:

-DCMAKE_INSTALL_INCLUDEDIR=include/jsoncpp
Running cmake -h will display the list of available generators (passed using the -G option).

By default CMake hides compilation commands. This can be modified by specifying -DCMAKE_VERBOSE_MAKEFILE=true when generating makefiles.

When building the solution file on Visual Studio, it would try to run the tests. In this case, or when running the tests from the command line,
if you build a DLL of jsoncpp, then it must be installed, or at least copied into the output directory holding jsontestrunner_exe.exe