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
CMAKE_SOURCE_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Hard/BasicCalculator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Hard/BasicCalculator/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BasicCalculator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BasicCalculator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BasicCalculator.dir/flags.make

CMakeFiles/BasicCalculator.dir/main.cpp.o: CMakeFiles/BasicCalculator.dir/flags.make
CMakeFiles/BasicCalculator.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Hard/BasicCalculator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BasicCalculator.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BasicCalculator.dir/main.cpp.o -c /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Hard/BasicCalculator/main.cpp

CMakeFiles/BasicCalculator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BasicCalculator.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Hard/BasicCalculator/main.cpp > CMakeFiles/BasicCalculator.dir/main.cpp.i

CMakeFiles/BasicCalculator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BasicCalculator.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Hard/BasicCalculator/main.cpp -o CMakeFiles/BasicCalculator.dir/main.cpp.s

# Object files for target BasicCalculator
BasicCalculator_OBJECTS = \
"CMakeFiles/BasicCalculator.dir/main.cpp.o"

# External object files for target BasicCalculator
BasicCalculator_EXTERNAL_OBJECTS =

BasicCalculator: CMakeFiles/BasicCalculator.dir/main.cpp.o
BasicCalculator: CMakeFiles/BasicCalculator.dir/build.make
BasicCalculator: CMakeFiles/BasicCalculator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Hard/BasicCalculator/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BasicCalculator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BasicCalculator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BasicCalculator.dir/build: BasicCalculator

.PHONY : CMakeFiles/BasicCalculator.dir/build

CMakeFiles/BasicCalculator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BasicCalculator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BasicCalculator.dir/clean

CMakeFiles/BasicCalculator.dir/depend:
	cd /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Hard/BasicCalculator/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Hard/BasicCalculator /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Hard/BasicCalculator /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Hard/BasicCalculator/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Hard/BasicCalculator/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Hard/BasicCalculator/cmake-build-debug/CMakeFiles/BasicCalculator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BasicCalculator.dir/depend
