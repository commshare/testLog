# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Produce verbose output by default.
VERBOSE = 1

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/zhangbin/clion/clion-2018.1.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/zhangbin/clion/clion-2018.1.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/zhangbin/stream/ttttsdk/testLog/testTinyXML

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/cmake-build-debug

# Utility rule file for jsoncpp_readerwriter_tests.

# Include the progress variables for this target.
include json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests.dir/progress.make

json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests: json/jsoncpp-1.8.4/src/jsontestrunner/jsontestrunner_exe
json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests: json/jsoncpp-1.8.4/src/test_lib_json/jsoncpp_test
	cd /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/cmake-build-debug/json/jsoncpp-1.8.4/src/jsontestrunner && /usr/bin/python2 -B /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/json/jsoncpp-1.8.4/src/jsontestrunner/../../test/runjsontests.py /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/cmake-build-debug/json/jsoncpp-1.8.4/src/jsontestrunner/jsontestrunner_exe /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/json/jsoncpp-1.8.4/src/jsontestrunner/../../test/data

jsoncpp_readerwriter_tests: json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests
jsoncpp_readerwriter_tests: json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests.dir/build.make

.PHONY : jsoncpp_readerwriter_tests

# Rule to build all files generated by this target.
json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests.dir/build: jsoncpp_readerwriter_tests

.PHONY : json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests.dir/build

json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests.dir/clean:
	cd /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/cmake-build-debug/json/jsoncpp-1.8.4/src/jsontestrunner && $(CMAKE_COMMAND) -P CMakeFiles/jsoncpp_readerwriter_tests.dir/cmake_clean.cmake
.PHONY : json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests.dir/clean

json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests.dir/depend:
	cd /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhangbin/stream/ttttsdk/testLog/testTinyXML /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/json/jsoncpp-1.8.4/src/jsontestrunner /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/cmake-build-debug /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/cmake-build-debug/json/jsoncpp-1.8.4/src/jsontestrunner /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/cmake-build-debug/json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsoncpp_readerwriter_tests.dir/depend

