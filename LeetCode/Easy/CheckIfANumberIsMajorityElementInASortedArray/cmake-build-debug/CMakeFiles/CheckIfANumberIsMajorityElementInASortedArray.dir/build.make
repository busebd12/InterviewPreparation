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
CMAKE_SOURCE_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CheckIfANumberIsMajorityElementInASortedArray

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CheckIfANumberIsMajorityElementInASortedArray/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/flags.make

CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/main.cpp.o: CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/flags.make
CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CheckIfANumberIsMajorityElementInASortedArray/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/main.cpp.o -c /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CheckIfANumberIsMajorityElementInASortedArray/main.cpp

CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CheckIfANumberIsMajorityElementInASortedArray/main.cpp > CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/main.cpp.i

CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CheckIfANumberIsMajorityElementInASortedArray/main.cpp -o CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/main.cpp.s

# Object files for target CheckIfANumberIsMajorityElementInASortedArray
CheckIfANumberIsMajorityElementInASortedArray_OBJECTS = \
"CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/main.cpp.o"

# External object files for target CheckIfANumberIsMajorityElementInASortedArray
CheckIfANumberIsMajorityElementInASortedArray_EXTERNAL_OBJECTS =

CheckIfANumberIsMajorityElementInASortedArray: CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/main.cpp.o
CheckIfANumberIsMajorityElementInASortedArray: CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/build.make
CheckIfANumberIsMajorityElementInASortedArray: CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CheckIfANumberIsMajorityElementInASortedArray/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CheckIfANumberIsMajorityElementInASortedArray"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/build: CheckIfANumberIsMajorityElementInASortedArray

.PHONY : CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/build

CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/clean

CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/depend:
	cd /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CheckIfANumberIsMajorityElementInASortedArray/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CheckIfANumberIsMajorityElementInASortedArray /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CheckIfANumberIsMajorityElementInASortedArray /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CheckIfANumberIsMajorityElementInASortedArray/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CheckIfANumberIsMajorityElementInASortedArray/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/CheckIfANumberIsMajorityElementInASortedArray/cmake-build-debug/CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CheckIfANumberIsMajorityElementInASortedArray.dir/depend

