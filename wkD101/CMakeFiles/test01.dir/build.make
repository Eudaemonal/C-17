# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.11.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.11.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/eudaemon/dropbox/project/cpp/wkD101

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/eudaemon/dropbox/project/cpp/wkD101

# Include any dependencies generated for this target.
include CMakeFiles/test01.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test01.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test01.dir/flags.make

CMakeFiles/test01.dir/test01.cpp.o: CMakeFiles/test01.dir/flags.make
CMakeFiles/test01.dir/test01.cpp.o: test01.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/eudaemon/dropbox/project/cpp/wkD101/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test01.dir/test01.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test01.dir/test01.cpp.o -c /Users/eudaemon/dropbox/project/cpp/wkD101/test01.cpp

CMakeFiles/test01.dir/test01.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test01.dir/test01.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/eudaemon/dropbox/project/cpp/wkD101/test01.cpp > CMakeFiles/test01.dir/test01.cpp.i

CMakeFiles/test01.dir/test01.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test01.dir/test01.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/eudaemon/dropbox/project/cpp/wkD101/test01.cpp -o CMakeFiles/test01.dir/test01.cpp.s

# Object files for target test01
test01_OBJECTS = \
"CMakeFiles/test01.dir/test01.cpp.o"

# External object files for target test01
test01_EXTERNAL_OBJECTS =

test01: CMakeFiles/test01.dir/test01.cpp.o
test01: CMakeFiles/test01.dir/build.make
test01: CMakeFiles/test01.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/eudaemon/dropbox/project/cpp/wkD101/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test01"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test01.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test01.dir/build: test01

.PHONY : CMakeFiles/test01.dir/build

CMakeFiles/test01.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test01.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test01.dir/clean

CMakeFiles/test01.dir/depend:
	cd /Users/eudaemon/dropbox/project/cpp/wkD101 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/eudaemon/dropbox/project/cpp/wkD101 /Users/eudaemon/dropbox/project/cpp/wkD101 /Users/eudaemon/dropbox/project/cpp/wkD101 /Users/eudaemon/dropbox/project/cpp/wkD101 /Users/eudaemon/dropbox/project/cpp/wkD101/CMakeFiles/test01.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test01.dir/depend

