# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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
CMAKE_COMMAND = /Applications/CMake.app/Contents/bin/cmake

# The command to remove a file.
RM = /Applications/CMake.app/Contents/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/michaelbethke/Documents/Development/Projects/EvolutionaryStringMatching

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/michaelbethke/Documents/Development/Projects/EvolutionaryStringMatching/build

# Include any dependencies generated for this target.
include CMakeFiles/libpugixml.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libpugixml.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libpugixml.dir/flags.make

# Object files for target libpugixml
libpugixml_OBJECTS =

# External object files for target libpugixml
libpugixml_EXTERNAL_OBJECTS =

liblibpugixml.a: CMakeFiles/libpugixml.dir/build.make
liblibpugixml.a: CMakeFiles/libpugixml.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/michaelbethke/Documents/Development/Projects/EvolutionaryStringMatching/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX static library liblibpugixml.a"
	$(CMAKE_COMMAND) -P CMakeFiles/libpugixml.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libpugixml.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libpugixml.dir/build: liblibpugixml.a

.PHONY : CMakeFiles/libpugixml.dir/build

CMakeFiles/libpugixml.dir/requires:

.PHONY : CMakeFiles/libpugixml.dir/requires

CMakeFiles/libpugixml.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libpugixml.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libpugixml.dir/clean

CMakeFiles/libpugixml.dir/depend:
	cd /Users/michaelbethke/Documents/Development/Projects/EvolutionaryStringMatching/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/michaelbethke/Documents/Development/Projects/EvolutionaryStringMatching /Users/michaelbethke/Documents/Development/Projects/EvolutionaryStringMatching /Users/michaelbethke/Documents/Development/Projects/EvolutionaryStringMatching/build /Users/michaelbethke/Documents/Development/Projects/EvolutionaryStringMatching/build /Users/michaelbethke/Documents/Development/Projects/EvolutionaryStringMatching/build/CMakeFiles/libpugixml.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libpugixml.dir/depend

