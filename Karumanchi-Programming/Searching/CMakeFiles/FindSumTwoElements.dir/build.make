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
CMAKE_SOURCE_DIR = /home/aditya/Desktop/Karumanchi-Programming/Searching

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aditya/Desktop/Karumanchi-Programming/Searching

# Include any dependencies generated for this target.
include CMakeFiles/FindSumTwoElements.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FindSumTwoElements.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FindSumTwoElements.dir/flags.make

CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.o: CMakeFiles/FindSumTwoElements.dir/flags.make
CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.o: FindTwoElementsWithGivenSum.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/aditya/Desktop/Karumanchi-Programming/Searching/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.o -c /home/aditya/Desktop/Karumanchi-Programming/Searching/FindTwoElementsWithGivenSum.cpp

CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/aditya/Desktop/Karumanchi-Programming/Searching/FindTwoElementsWithGivenSum.cpp > CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.i

CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/aditya/Desktop/Karumanchi-Programming/Searching/FindTwoElementsWithGivenSum.cpp -o CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.s

CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.o.requires:
.PHONY : CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.o.requires

CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.o.provides: CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.o.requires
	$(MAKE) -f CMakeFiles/FindSumTwoElements.dir/build.make CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.o.provides.build
.PHONY : CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.o.provides

CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.o.provides.build: CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.o

# Object files for target FindSumTwoElements
FindSumTwoElements_OBJECTS = \
"CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.o"

# External object files for target FindSumTwoElements
FindSumTwoElements_EXTERNAL_OBJECTS =

FindSumTwoElements: CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.o
FindSumTwoElements: CMakeFiles/FindSumTwoElements.dir/build.make
FindSumTwoElements: CMakeFiles/FindSumTwoElements.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable FindSumTwoElements"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FindSumTwoElements.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FindSumTwoElements.dir/build: FindSumTwoElements
.PHONY : CMakeFiles/FindSumTwoElements.dir/build

CMakeFiles/FindSumTwoElements.dir/requires: CMakeFiles/FindSumTwoElements.dir/FindTwoElementsWithGivenSum.cpp.o.requires
.PHONY : CMakeFiles/FindSumTwoElements.dir/requires

CMakeFiles/FindSumTwoElements.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FindSumTwoElements.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FindSumTwoElements.dir/clean

CMakeFiles/FindSumTwoElements.dir/depend:
	cd /home/aditya/Desktop/Karumanchi-Programming/Searching && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aditya/Desktop/Karumanchi-Programming/Searching /home/aditya/Desktop/Karumanchi-Programming/Searching /home/aditya/Desktop/Karumanchi-Programming/Searching /home/aditya/Desktop/Karumanchi-Programming/Searching /home/aditya/Desktop/Karumanchi-Programming/Searching/CMakeFiles/FindSumTwoElements.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FindSumTwoElements.dir/depend

