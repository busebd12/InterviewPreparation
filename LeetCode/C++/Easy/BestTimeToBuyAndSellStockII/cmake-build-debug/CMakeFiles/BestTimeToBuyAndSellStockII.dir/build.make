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
CMAKE_SOURCE_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/BestTimeToBuyAndSellStockII

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/BestTimeToBuyAndSellStockII/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BestTimeToBuyAndSellStockII.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BestTimeToBuyAndSellStockII.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BestTimeToBuyAndSellStockII.dir/flags.make

CMakeFiles/BestTimeToBuyAndSellStockII.dir/main.cpp.o: CMakeFiles/BestTimeToBuyAndSellStockII.dir/flags.make
CMakeFiles/BestTimeToBuyAndSellStockII.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/BestTimeToBuyAndSellStockII/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BestTimeToBuyAndSellStockII.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BestTimeToBuyAndSellStockII.dir/main.cpp.o -c /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/BestTimeToBuyAndSellStockII/main.cpp

CMakeFiles/BestTimeToBuyAndSellStockII.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BestTimeToBuyAndSellStockII.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/BestTimeToBuyAndSellStockII/main.cpp > CMakeFiles/BestTimeToBuyAndSellStockII.dir/main.cpp.i

CMakeFiles/BestTimeToBuyAndSellStockII.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BestTimeToBuyAndSellStockII.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/BestTimeToBuyAndSellStockII/main.cpp -o CMakeFiles/BestTimeToBuyAndSellStockII.dir/main.cpp.s

# Object files for target BestTimeToBuyAndSellStockII
BestTimeToBuyAndSellStockII_OBJECTS = \
"CMakeFiles/BestTimeToBuyAndSellStockII.dir/main.cpp.o"

# External object files for target BestTimeToBuyAndSellStockII
BestTimeToBuyAndSellStockII_EXTERNAL_OBJECTS =

BestTimeToBuyAndSellStockII: CMakeFiles/BestTimeToBuyAndSellStockII.dir/main.cpp.o
BestTimeToBuyAndSellStockII: CMakeFiles/BestTimeToBuyAndSellStockII.dir/build.make
BestTimeToBuyAndSellStockII: CMakeFiles/BestTimeToBuyAndSellStockII.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/BestTimeToBuyAndSellStockII/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BestTimeToBuyAndSellStockII"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BestTimeToBuyAndSellStockII.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BestTimeToBuyAndSellStockII.dir/build: BestTimeToBuyAndSellStockII

.PHONY : CMakeFiles/BestTimeToBuyAndSellStockII.dir/build

CMakeFiles/BestTimeToBuyAndSellStockII.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BestTimeToBuyAndSellStockII.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BestTimeToBuyAndSellStockII.dir/clean

CMakeFiles/BestTimeToBuyAndSellStockII.dir/depend:
	cd /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/BestTimeToBuyAndSellStockII/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/BestTimeToBuyAndSellStockII /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/BestTimeToBuyAndSellStockII /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/BestTimeToBuyAndSellStockII/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/BestTimeToBuyAndSellStockII/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/BestTimeToBuyAndSellStockII/cmake-build-debug/CMakeFiles/BestTimeToBuyAndSellStockII.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BestTimeToBuyAndSellStockII.dir/depend

