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
CMAKE_SOURCE_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/PalindromePermutation

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/PalindromePermutation/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PalindromePermutation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PalindromePermutation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PalindromePermutation.dir/flags.make

CMakeFiles/PalindromePermutation.dir/main.cpp.o: CMakeFiles/PalindromePermutation.dir/flags.make
CMakeFiles/PalindromePermutation.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/PalindromePermutation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PalindromePermutation.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PalindromePermutation.dir/main.cpp.o -c /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/PalindromePermutation/main.cpp

CMakeFiles/PalindromePermutation.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PalindromePermutation.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/PalindromePermutation/main.cpp > CMakeFiles/PalindromePermutation.dir/main.cpp.i

CMakeFiles/PalindromePermutation.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PalindromePermutation.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/PalindromePermutation/main.cpp -o CMakeFiles/PalindromePermutation.dir/main.cpp.s

# Object files for target PalindromePermutation
PalindromePermutation_OBJECTS = \
"CMakeFiles/PalindromePermutation.dir/main.cpp.o"

# External object files for target PalindromePermutation
PalindromePermutation_EXTERNAL_OBJECTS =

PalindromePermutation: CMakeFiles/PalindromePermutation.dir/main.cpp.o
PalindromePermutation: CMakeFiles/PalindromePermutation.dir/build.make
PalindromePermutation: CMakeFiles/PalindromePermutation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/PalindromePermutation/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PalindromePermutation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PalindromePermutation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PalindromePermutation.dir/build: PalindromePermutation

.PHONY : CMakeFiles/PalindromePermutation.dir/build

CMakeFiles/PalindromePermutation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PalindromePermutation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PalindromePermutation.dir/clean

CMakeFiles/PalindromePermutation.dir/depend:
	cd /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/PalindromePermutation/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/PalindromePermutation /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/PalindromePermutation /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/PalindromePermutation/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/PalindromePermutation/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/PalindromePermutation/cmake-build-debug/CMakeFiles/PalindromePermutation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PalindromePermutation.dir/depend

