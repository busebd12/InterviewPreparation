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
CMAKE_SOURCE_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CellsWithOddValuesInAMatrix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CellsWithOddValuesInAMatrix/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CellsWithOddValuesInAMatrix.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CellsWithOddValuesInAMatrix.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CellsWithOddValuesInAMatrix.dir/flags.make

CMakeFiles/CellsWithOddValuesInAMatrix.dir/main.cpp.o: CMakeFiles/CellsWithOddValuesInAMatrix.dir/flags.make
CMakeFiles/CellsWithOddValuesInAMatrix.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CellsWithOddValuesInAMatrix/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CellsWithOddValuesInAMatrix.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CellsWithOddValuesInAMatrix.dir/main.cpp.o -c /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CellsWithOddValuesInAMatrix/main.cpp

CMakeFiles/CellsWithOddValuesInAMatrix.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CellsWithOddValuesInAMatrix.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CellsWithOddValuesInAMatrix/main.cpp > CMakeFiles/CellsWithOddValuesInAMatrix.dir/main.cpp.i

CMakeFiles/CellsWithOddValuesInAMatrix.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CellsWithOddValuesInAMatrix.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CellsWithOddValuesInAMatrix/main.cpp -o CMakeFiles/CellsWithOddValuesInAMatrix.dir/main.cpp.s

# Object files for target CellsWithOddValuesInAMatrix
CellsWithOddValuesInAMatrix_OBJECTS = \
"CMakeFiles/CellsWithOddValuesInAMatrix.dir/main.cpp.o"

# External object files for target CellsWithOddValuesInAMatrix
CellsWithOddValuesInAMatrix_EXTERNAL_OBJECTS =

CellsWithOddValuesInAMatrix: CMakeFiles/CellsWithOddValuesInAMatrix.dir/main.cpp.o
CellsWithOddValuesInAMatrix: CMakeFiles/CellsWithOddValuesInAMatrix.dir/build.make
CellsWithOddValuesInAMatrix: CMakeFiles/CellsWithOddValuesInAMatrix.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CellsWithOddValuesInAMatrix/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CellsWithOddValuesInAMatrix"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CellsWithOddValuesInAMatrix.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CellsWithOddValuesInAMatrix.dir/build: CellsWithOddValuesInAMatrix

.PHONY : CMakeFiles/CellsWithOddValuesInAMatrix.dir/build

CMakeFiles/CellsWithOddValuesInAMatrix.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CellsWithOddValuesInAMatrix.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CellsWithOddValuesInAMatrix.dir/clean

CMakeFiles/CellsWithOddValuesInAMatrix.dir/depend:
	cd /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CellsWithOddValuesInAMatrix/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CellsWithOddValuesInAMatrix /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CellsWithOddValuesInAMatrix /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CellsWithOddValuesInAMatrix/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CellsWithOddValuesInAMatrix/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CellsWithOddValuesInAMatrix/cmake-build-debug/CMakeFiles/CellsWithOddValuesInAMatrix.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CellsWithOddValuesInAMatrix.dir/depend
