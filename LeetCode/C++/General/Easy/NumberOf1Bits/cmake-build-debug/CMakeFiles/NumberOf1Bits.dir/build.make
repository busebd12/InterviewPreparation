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
CMAKE_SOURCE_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOf1Bits

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOf1Bits/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NumberOf1Bits.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NumberOf1Bits.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NumberOf1Bits.dir/flags.make

CMakeFiles/NumberOf1Bits.dir/main.cpp.o: CMakeFiles/NumberOf1Bits.dir/flags.make
CMakeFiles/NumberOf1Bits.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOf1Bits/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NumberOf1Bits.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NumberOf1Bits.dir/main.cpp.o -c /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOf1Bits/main.cpp

CMakeFiles/NumberOf1Bits.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NumberOf1Bits.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOf1Bits/main.cpp > CMakeFiles/NumberOf1Bits.dir/main.cpp.i

CMakeFiles/NumberOf1Bits.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NumberOf1Bits.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOf1Bits/main.cpp -o CMakeFiles/NumberOf1Bits.dir/main.cpp.s

# Object files for target NumberOf1Bits
NumberOf1Bits_OBJECTS = \
"CMakeFiles/NumberOf1Bits.dir/main.cpp.o"

# External object files for target NumberOf1Bits
NumberOf1Bits_EXTERNAL_OBJECTS =

NumberOf1Bits: CMakeFiles/NumberOf1Bits.dir/main.cpp.o
NumberOf1Bits: CMakeFiles/NumberOf1Bits.dir/build.make
NumberOf1Bits: CMakeFiles/NumberOf1Bits.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOf1Bits/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable NumberOf1Bits"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NumberOf1Bits.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NumberOf1Bits.dir/build: NumberOf1Bits

.PHONY : CMakeFiles/NumberOf1Bits.dir/build

CMakeFiles/NumberOf1Bits.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NumberOf1Bits.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NumberOf1Bits.dir/clean

CMakeFiles/NumberOf1Bits.dir/depend:
	cd /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOf1Bits/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOf1Bits /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOf1Bits /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOf1Bits/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOf1Bits/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOf1Bits/cmake-build-debug/CMakeFiles/NumberOf1Bits.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NumberOf1Bits.dir/depend
