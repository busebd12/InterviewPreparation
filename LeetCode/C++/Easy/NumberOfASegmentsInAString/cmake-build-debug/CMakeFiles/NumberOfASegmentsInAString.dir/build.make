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
CMAKE_SOURCE_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOfASegmentsInAString

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOfASegmentsInAString/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NumberOfASegmentsInAString.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NumberOfASegmentsInAString.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NumberOfASegmentsInAString.dir/flags.make

CMakeFiles/NumberOfASegmentsInAString.dir/main.cpp.o: CMakeFiles/NumberOfASegmentsInAString.dir/flags.make
CMakeFiles/NumberOfASegmentsInAString.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOfASegmentsInAString/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NumberOfASegmentsInAString.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NumberOfASegmentsInAString.dir/main.cpp.o -c /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOfASegmentsInAString/main.cpp

CMakeFiles/NumberOfASegmentsInAString.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NumberOfASegmentsInAString.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOfASegmentsInAString/main.cpp > CMakeFiles/NumberOfASegmentsInAString.dir/main.cpp.i

CMakeFiles/NumberOfASegmentsInAString.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NumberOfASegmentsInAString.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOfASegmentsInAString/main.cpp -o CMakeFiles/NumberOfASegmentsInAString.dir/main.cpp.s

# Object files for target NumberOfASegmentsInAString
NumberOfASegmentsInAString_OBJECTS = \
"CMakeFiles/NumberOfASegmentsInAString.dir/main.cpp.o"

# External object files for target NumberOfASegmentsInAString
NumberOfASegmentsInAString_EXTERNAL_OBJECTS =

NumberOfASegmentsInAString: CMakeFiles/NumberOfASegmentsInAString.dir/main.cpp.o
NumberOfASegmentsInAString: CMakeFiles/NumberOfASegmentsInAString.dir/build.make
NumberOfASegmentsInAString: CMakeFiles/NumberOfASegmentsInAString.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOfASegmentsInAString/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable NumberOfASegmentsInAString"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NumberOfASegmentsInAString.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NumberOfASegmentsInAString.dir/build: NumberOfASegmentsInAString

.PHONY : CMakeFiles/NumberOfASegmentsInAString.dir/build

CMakeFiles/NumberOfASegmentsInAString.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NumberOfASegmentsInAString.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NumberOfASegmentsInAString.dir/clean

CMakeFiles/NumberOfASegmentsInAString.dir/depend:
	cd /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOfASegmentsInAString/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOfASegmentsInAString /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOfASegmentsInAString /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOfASegmentsInAString/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOfASegmentsInAString/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NumberOfASegmentsInAString/cmake-build-debug/CMakeFiles/NumberOfASegmentsInAString.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NumberOfASegmentsInAString.dir/depend

