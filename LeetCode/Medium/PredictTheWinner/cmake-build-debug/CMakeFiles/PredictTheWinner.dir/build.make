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
CMAKE_SOURCE_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/PredictTheWinner

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/PredictTheWinner/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PredictTheWinner.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PredictTheWinner.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PredictTheWinner.dir/flags.make

CMakeFiles/PredictTheWinner.dir/main.cpp.o: CMakeFiles/PredictTheWinner.dir/flags.make
CMakeFiles/PredictTheWinner.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/PredictTheWinner/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PredictTheWinner.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PredictTheWinner.dir/main.cpp.o -c /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/PredictTheWinner/main.cpp

CMakeFiles/PredictTheWinner.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PredictTheWinner.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/PredictTheWinner/main.cpp > CMakeFiles/PredictTheWinner.dir/main.cpp.i

CMakeFiles/PredictTheWinner.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PredictTheWinner.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/PredictTheWinner/main.cpp -o CMakeFiles/PredictTheWinner.dir/main.cpp.s

# Object files for target PredictTheWinner
PredictTheWinner_OBJECTS = \
"CMakeFiles/PredictTheWinner.dir/main.cpp.o"

# External object files for target PredictTheWinner
PredictTheWinner_EXTERNAL_OBJECTS =

PredictTheWinner: CMakeFiles/PredictTheWinner.dir/main.cpp.o
PredictTheWinner: CMakeFiles/PredictTheWinner.dir/build.make
PredictTheWinner: CMakeFiles/PredictTheWinner.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/PredictTheWinner/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PredictTheWinner"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PredictTheWinner.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PredictTheWinner.dir/build: PredictTheWinner

.PHONY : CMakeFiles/PredictTheWinner.dir/build

CMakeFiles/PredictTheWinner.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PredictTheWinner.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PredictTheWinner.dir/clean

CMakeFiles/PredictTheWinner.dir/depend:
	cd /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/PredictTheWinner/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/PredictTheWinner /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/PredictTheWinner /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/PredictTheWinner/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/PredictTheWinner/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/PredictTheWinner/cmake-build-debug/CMakeFiles/PredictTheWinner.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PredictTheWinner.dir/depend

