# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aditya/Programming/GeekCopy-Practice/Searching

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aditya/Programming/GeekCopy-Practice/Searching

# Include any dependencies generated for this target.
include CMakeFiles/SegregateEvenAndOdd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SegregateEvenAndOdd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SegregateEvenAndOdd.dir/flags.make

CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.o: CMakeFiles/SegregateEvenAndOdd.dir/flags.make
CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.o: SegregateEvenAndOdd.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/aditya/Programming/GeekCopy-Practice/Searching/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.o -c /home/aditya/Programming/GeekCopy-Practice/Searching/SegregateEvenAndOdd.cpp

CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/aditya/Programming/GeekCopy-Practice/Searching/SegregateEvenAndOdd.cpp > CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.i

CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/aditya/Programming/GeekCopy-Practice/Searching/SegregateEvenAndOdd.cpp -o CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.s

CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.o.requires:
.PHONY : CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.o.requires

CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.o.provides: CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.o.requires
	$(MAKE) -f CMakeFiles/SegregateEvenAndOdd.dir/build.make CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.o.provides.build
.PHONY : CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.o.provides

CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.o.provides.build: CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.o

# Object files for target SegregateEvenAndOdd
SegregateEvenAndOdd_OBJECTS = \
"CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.o"

# External object files for target SegregateEvenAndOdd
SegregateEvenAndOdd_EXTERNAL_OBJECTS =

SegregateEvenAndOdd: CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.o
SegregateEvenAndOdd: CMakeFiles/SegregateEvenAndOdd.dir/build.make
SegregateEvenAndOdd: CMakeFiles/SegregateEvenAndOdd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable SegregateEvenAndOdd"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SegregateEvenAndOdd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SegregateEvenAndOdd.dir/build: SegregateEvenAndOdd
.PHONY : CMakeFiles/SegregateEvenAndOdd.dir/build

CMakeFiles/SegregateEvenAndOdd.dir/requires: CMakeFiles/SegregateEvenAndOdd.dir/SegregateEvenAndOdd.cpp.o.requires
.PHONY : CMakeFiles/SegregateEvenAndOdd.dir/requires

CMakeFiles/SegregateEvenAndOdd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SegregateEvenAndOdd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SegregateEvenAndOdd.dir/clean

CMakeFiles/SegregateEvenAndOdd.dir/depend:
	cd /home/aditya/Programming/GeekCopy-Practice/Searching && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aditya/Programming/GeekCopy-Practice/Searching /home/aditya/Programming/GeekCopy-Practice/Searching /home/aditya/Programming/GeekCopy-Practice/Searching /home/aditya/Programming/GeekCopy-Practice/Searching /home/aditya/Programming/GeekCopy-Practice/Searching/CMakeFiles/SegregateEvenAndOdd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SegregateEvenAndOdd.dir/depend

