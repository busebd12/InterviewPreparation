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
CMAKE_SOURCE_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ReshapeTheMatrix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ReshapeTheMatrix/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ReshapeTheMatrix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ReshapeTheMatrix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ReshapeTheMatrix.dir/flags.make

CMakeFiles/ReshapeTheMatrix.dir/main.cpp.o: CMakeFiles/ReshapeTheMatrix.dir/flags.make
CMakeFiles/ReshapeTheMatrix.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ReshapeTheMatrix/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ReshapeTheMatrix.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReshapeTheMatrix.dir/main.cpp.o -c /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ReshapeTheMatrix/main.cpp

CMakeFiles/ReshapeTheMatrix.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReshapeTheMatrix.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ReshapeTheMatrix/main.cpp > CMakeFiles/ReshapeTheMatrix.dir/main.cpp.i

CMakeFiles/ReshapeTheMatrix.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReshapeTheMatrix.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ReshapeTheMatrix/main.cpp -o CMakeFiles/ReshapeTheMatrix.dir/main.cpp.s

# Object files for target ReshapeTheMatrix
ReshapeTheMatrix_OBJECTS = \
"CMakeFiles/ReshapeTheMatrix.dir/main.cpp.o"

# External object files for target ReshapeTheMatrix
ReshapeTheMatrix_EXTERNAL_OBJECTS =

ReshapeTheMatrix: CMakeFiles/ReshapeTheMatrix.dir/main.cpp.o
ReshapeTheMatrix: CMakeFiles/ReshapeTheMatrix.dir/build.make
ReshapeTheMatrix: CMakeFiles/ReshapeTheMatrix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ReshapeTheMatrix/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ReshapeTheMatrix"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ReshapeTheMatrix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ReshapeTheMatrix.dir/build: ReshapeTheMatrix

.PHONY : CMakeFiles/ReshapeTheMatrix.dir/build

CMakeFiles/ReshapeTheMatrix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ReshapeTheMatrix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ReshapeTheMatrix.dir/clean

CMakeFiles/ReshapeTheMatrix.dir/depend:
	cd /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ReshapeTheMatrix/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ReshapeTheMatrix /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ReshapeTheMatrix /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ReshapeTheMatrix/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ReshapeTheMatrix/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ReshapeTheMatrix/cmake-build-debug/CMakeFiles/ReshapeTheMatrix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ReshapeTheMatrix.dir/depend
