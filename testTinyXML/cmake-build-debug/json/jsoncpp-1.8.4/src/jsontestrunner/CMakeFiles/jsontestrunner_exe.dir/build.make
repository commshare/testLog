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

# Include any dependencies generated for this target.
include json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/depend.make

# Include the progress variables for this target.
include json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/progress.make

# Include the compile flags for this target's objects.
include json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/flags.make

json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/main.cpp.o: json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/flags.make
json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/main.cpp.o: ../json/jsoncpp-1.8.4/src/jsontestrunner/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/zhangbin/stream/ttttsdk/testLog/testTinyXML/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/main.cpp.o"
	cd /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/cmake-build-debug/json/jsoncpp-1.8.4/src/jsontestrunner && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/jsontestrunner_exe.dir/main.cpp.o -c /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/json/jsoncpp-1.8.4/src/jsontestrunner/main.cpp

json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/jsontestrunner_exe.dir/main.cpp.i"
	cd /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/cmake-build-debug/json/jsoncpp-1.8.4/src/jsontestrunner && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/json/jsoncpp-1.8.4/src/jsontestrunner/main.cpp > CMakeFiles/jsontestrunner_exe.dir/main.cpp.i

json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/jsontestrunner_exe.dir/main.cpp.s"
	cd /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/cmake-build-debug/json/jsoncpp-1.8.4/src/jsontestrunner && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/json/jsoncpp-1.8.4/src/jsontestrunner/main.cpp -o CMakeFiles/jsontestrunner_exe.dir/main.cpp.s

# Object files for target jsontestrunner_exe
jsontestrunner_exe_OBJECTS = \
"CMakeFiles/jsontestrunner_exe.dir/main.cpp.o"

# External object files for target jsontestrunner_exe
jsontestrunner_exe_EXTERNAL_OBJECTS =

json/jsoncpp-1.8.4/src/jsontestrunner/jsontestrunner_exe: json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/main.cpp.o
json/jsoncpp-1.8.4/src/jsontestrunner/jsontestrunner_exe: json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/build.make
json/jsoncpp-1.8.4/src/jsontestrunner/jsontestrunner_exe: json/jsoncpp-1.8.4/src/lib_json/libjsoncpp.a
json/jsoncpp-1.8.4/src/jsontestrunner/jsontestrunner_exe: json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/zhangbin/stream/ttttsdk/testLog/testTinyXML/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable jsontestrunner_exe"
	cd /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/cmake-build-debug/json/jsoncpp-1.8.4/src/jsontestrunner && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/jsontestrunner_exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/build: json/jsoncpp-1.8.4/src/jsontestrunner/jsontestrunner_exe

.PHONY : json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/build

json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/clean:
	cd /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/cmake-build-debug/json/jsoncpp-1.8.4/src/jsontestrunner && $(CMAKE_COMMAND) -P CMakeFiles/jsontestrunner_exe.dir/cmake_clean.cmake
.PHONY : json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/clean

json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/depend:
	cd /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/zhangbin/stream/ttttsdk/testLog/testTinyXML /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/json/jsoncpp-1.8.4/src/jsontestrunner /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/cmake-build-debug /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/cmake-build-debug/json/jsoncpp-1.8.4/src/jsontestrunner /home/zhangbin/stream/ttttsdk/testLog/testTinyXML/cmake-build-debug/json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : json/jsoncpp-1.8.4/src/jsontestrunner/CMakeFiles/jsontestrunner_exe.dir/depend
