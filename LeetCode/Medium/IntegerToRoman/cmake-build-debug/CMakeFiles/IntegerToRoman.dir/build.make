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
CMAKE_SOURCE_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/IntegerToRoman

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/IntegerToRoman/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/IntegerToRoman.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/IntegerToRoman.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IntegerToRoman.dir/flags.make

CMakeFiles/IntegerToRoman.dir/main.cpp.o: CMakeFiles/IntegerToRoman.dir/flags.make
CMakeFiles/IntegerToRoman.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/IntegerToRoman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/IntegerToRoman.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/IntegerToRoman.dir/main.cpp.o -c /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/IntegerToRoman/main.cpp

CMakeFiles/IntegerToRoman.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/IntegerToRoman.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/IntegerToRoman/main.cpp > CMakeFiles/IntegerToRoman.dir/main.cpp.i

CMakeFiles/IntegerToRoman.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/IntegerToRoman.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/IntegerToRoman/main.cpp -o CMakeFiles/IntegerToRoman.dir/main.cpp.s

# Object files for target IntegerToRoman
IntegerToRoman_OBJECTS = \
"CMakeFiles/IntegerToRoman.dir/main.cpp.o"

# External object files for target IntegerToRoman
IntegerToRoman_EXTERNAL_OBJECTS =

IntegerToRoman: CMakeFiles/IntegerToRoman.dir/main.cpp.o
IntegerToRoman: CMakeFiles/IntegerToRoman.dir/build.make
IntegerToRoman: CMakeFiles/IntegerToRoman.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/IntegerToRoman/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable IntegerToRoman"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/IntegerToRoman.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IntegerToRoman.dir/build: IntegerToRoman

.PHONY : CMakeFiles/IntegerToRoman.dir/build

CMakeFiles/IntegerToRoman.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/IntegerToRoman.dir/cmake_clean.cmake
.PHONY : CMakeFiles/IntegerToRoman.dir/clean

CMakeFiles/IntegerToRoman.dir/depend:
	cd /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/IntegerToRoman/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/IntegerToRoman /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/IntegerToRoman /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/IntegerToRoman/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/IntegerToRoman/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/IntegerToRoman/cmake-build-debug/CMakeFiles/IntegerToRoman.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/IntegerToRoman.dir/depend

