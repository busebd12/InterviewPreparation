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
CMAKE_SOURCE_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/SentenceSimilarity

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/SentenceSimilarity/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SentenceSimilarity.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SentenceSimilarity.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SentenceSimilarity.dir/flags.make

CMakeFiles/SentenceSimilarity.dir/main.cpp.o: CMakeFiles/SentenceSimilarity.dir/flags.make
CMakeFiles/SentenceSimilarity.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/SentenceSimilarity/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SentenceSimilarity.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SentenceSimilarity.dir/main.cpp.o -c /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/SentenceSimilarity/main.cpp

CMakeFiles/SentenceSimilarity.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SentenceSimilarity.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/SentenceSimilarity/main.cpp > CMakeFiles/SentenceSimilarity.dir/main.cpp.i

CMakeFiles/SentenceSimilarity.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SentenceSimilarity.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/SentenceSimilarity/main.cpp -o CMakeFiles/SentenceSimilarity.dir/main.cpp.s

# Object files for target SentenceSimilarity
SentenceSimilarity_OBJECTS = \
"CMakeFiles/SentenceSimilarity.dir/main.cpp.o"

# External object files for target SentenceSimilarity
SentenceSimilarity_EXTERNAL_OBJECTS =

SentenceSimilarity: CMakeFiles/SentenceSimilarity.dir/main.cpp.o
SentenceSimilarity: CMakeFiles/SentenceSimilarity.dir/build.make
SentenceSimilarity: CMakeFiles/SentenceSimilarity.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/SentenceSimilarity/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SentenceSimilarity"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SentenceSimilarity.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SentenceSimilarity.dir/build: SentenceSimilarity

.PHONY : CMakeFiles/SentenceSimilarity.dir/build

CMakeFiles/SentenceSimilarity.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SentenceSimilarity.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SentenceSimilarity.dir/clean

CMakeFiles/SentenceSimilarity.dir/depend:
	cd /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/SentenceSimilarity/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/SentenceSimilarity /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/SentenceSimilarity /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/SentenceSimilarity/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/SentenceSimilarity/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Easy/SentenceSimilarity/cmake-build-debug/CMakeFiles/SentenceSimilarity.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SentenceSimilarity.dir/depend

