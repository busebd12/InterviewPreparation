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
CMAKE_SOURCE_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ConvertBSTToGreaterTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ConvertBSTToGreaterTree/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ConvertBSTToGreaterTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ConvertBSTToGreaterTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ConvertBSTToGreaterTree.dir/flags.make

CMakeFiles/ConvertBSTToGreaterTree.dir/main.cpp.o: CMakeFiles/ConvertBSTToGreaterTree.dir/flags.make
CMakeFiles/ConvertBSTToGreaterTree.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ConvertBSTToGreaterTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ConvertBSTToGreaterTree.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ConvertBSTToGreaterTree.dir/main.cpp.o -c /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ConvertBSTToGreaterTree/main.cpp

CMakeFiles/ConvertBSTToGreaterTree.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ConvertBSTToGreaterTree.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ConvertBSTToGreaterTree/main.cpp > CMakeFiles/ConvertBSTToGreaterTree.dir/main.cpp.i

CMakeFiles/ConvertBSTToGreaterTree.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ConvertBSTToGreaterTree.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ConvertBSTToGreaterTree/main.cpp -o CMakeFiles/ConvertBSTToGreaterTree.dir/main.cpp.s

# Object files for target ConvertBSTToGreaterTree
ConvertBSTToGreaterTree_OBJECTS = \
"CMakeFiles/ConvertBSTToGreaterTree.dir/main.cpp.o"

# External object files for target ConvertBSTToGreaterTree
ConvertBSTToGreaterTree_EXTERNAL_OBJECTS =

ConvertBSTToGreaterTree: CMakeFiles/ConvertBSTToGreaterTree.dir/main.cpp.o
ConvertBSTToGreaterTree: CMakeFiles/ConvertBSTToGreaterTree.dir/build.make
ConvertBSTToGreaterTree: CMakeFiles/ConvertBSTToGreaterTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ConvertBSTToGreaterTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ConvertBSTToGreaterTree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ConvertBSTToGreaterTree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ConvertBSTToGreaterTree.dir/build: ConvertBSTToGreaterTree

.PHONY : CMakeFiles/ConvertBSTToGreaterTree.dir/build

CMakeFiles/ConvertBSTToGreaterTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ConvertBSTToGreaterTree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ConvertBSTToGreaterTree.dir/clean

CMakeFiles/ConvertBSTToGreaterTree.dir/depend:
	cd /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ConvertBSTToGreaterTree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ConvertBSTToGreaterTree /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ConvertBSTToGreaterTree /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ConvertBSTToGreaterTree/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ConvertBSTToGreaterTree/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/ConvertBSTToGreaterTree/cmake-build-debug/CMakeFiles/ConvertBSTToGreaterTree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ConvertBSTToGreaterTree.dir/depend
