# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NestedListWeightSum

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NestedListWeightSum/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NestedListWeightSum.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NestedListWeightSum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NestedListWeightSum.dir/flags.make

CMakeFiles/NestedListWeightSum.dir/main.cpp.o: CMakeFiles/NestedListWeightSum.dir/flags.make
CMakeFiles/NestedListWeightSum.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NestedListWeightSum/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NestedListWeightSum.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NestedListWeightSum.dir/main.cpp.o -c /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NestedListWeightSum/main.cpp

CMakeFiles/NestedListWeightSum.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NestedListWeightSum.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NestedListWeightSum/main.cpp > CMakeFiles/NestedListWeightSum.dir/main.cpp.i

CMakeFiles/NestedListWeightSum.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NestedListWeightSum.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NestedListWeightSum/main.cpp -o CMakeFiles/NestedListWeightSum.dir/main.cpp.s

# Object files for target NestedListWeightSum
NestedListWeightSum_OBJECTS = \
"CMakeFiles/NestedListWeightSum.dir/main.cpp.o"

# External object files for target NestedListWeightSum
NestedListWeightSum_EXTERNAL_OBJECTS =

NestedListWeightSum: CMakeFiles/NestedListWeightSum.dir/main.cpp.o
NestedListWeightSum: CMakeFiles/NestedListWeightSum.dir/build.make
NestedListWeightSum: CMakeFiles/NestedListWeightSum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NestedListWeightSum/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable NestedListWeightSum"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NestedListWeightSum.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NestedListWeightSum.dir/build: NestedListWeightSum

.PHONY : CMakeFiles/NestedListWeightSum.dir/build

CMakeFiles/NestedListWeightSum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NestedListWeightSum.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NestedListWeightSum.dir/clean

CMakeFiles/NestedListWeightSum.dir/depend:
	cd /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NestedListWeightSum/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NestedListWeightSum /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NestedListWeightSum /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NestedListWeightSum/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NestedListWeightSum/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NestedListWeightSum/cmake-build-debug/CMakeFiles/NestedListWeightSum.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NestedListWeightSum.dir/depend

