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
CMAKE_SOURCE_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NimGame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NimGame/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/NimGame.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NimGame.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NimGame.dir/flags.make

CMakeFiles/NimGame.dir/main.cpp.o: CMakeFiles/NimGame.dir/flags.make
CMakeFiles/NimGame.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NimGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NimGame.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NimGame.dir/main.cpp.o -c /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NimGame/main.cpp

CMakeFiles/NimGame.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NimGame.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NimGame/main.cpp > CMakeFiles/NimGame.dir/main.cpp.i

CMakeFiles/NimGame.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NimGame.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NimGame/main.cpp -o CMakeFiles/NimGame.dir/main.cpp.s

# Object files for target NimGame
NimGame_OBJECTS = \
"CMakeFiles/NimGame.dir/main.cpp.o"

# External object files for target NimGame
NimGame_EXTERNAL_OBJECTS =

NimGame: CMakeFiles/NimGame.dir/main.cpp.o
NimGame: CMakeFiles/NimGame.dir/build.make
NimGame: CMakeFiles/NimGame.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NimGame/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable NimGame"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NimGame.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NimGame.dir/build: NimGame

.PHONY : CMakeFiles/NimGame.dir/build

CMakeFiles/NimGame.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NimGame.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NimGame.dir/clean

CMakeFiles/NimGame.dir/depend:
	cd /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NimGame/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NimGame /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NimGame /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NimGame/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NimGame/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/NimGame/cmake-build-debug/CMakeFiles/NimGame.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NimGame.dir/depend

