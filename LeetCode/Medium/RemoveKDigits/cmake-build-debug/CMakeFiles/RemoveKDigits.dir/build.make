# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_SOURCE_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/RemoveKDigits

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/RemoveKDigits/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RemoveKDigits.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/RemoveKDigits.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RemoveKDigits.dir/flags.make

CMakeFiles/RemoveKDigits.dir/main.cpp.o: CMakeFiles/RemoveKDigits.dir/flags.make
CMakeFiles/RemoveKDigits.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/RemoveKDigits/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RemoveKDigits.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/RemoveKDigits.dir/main.cpp.o -c /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/RemoveKDigits/main.cpp

CMakeFiles/RemoveKDigits.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RemoveKDigits.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/RemoveKDigits/main.cpp > CMakeFiles/RemoveKDigits.dir/main.cpp.i

CMakeFiles/RemoveKDigits.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RemoveKDigits.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/RemoveKDigits/main.cpp -o CMakeFiles/RemoveKDigits.dir/main.cpp.s

# Object files for target RemoveKDigits
RemoveKDigits_OBJECTS = \
"CMakeFiles/RemoveKDigits.dir/main.cpp.o"

# External object files for target RemoveKDigits
RemoveKDigits_EXTERNAL_OBJECTS =

RemoveKDigits: CMakeFiles/RemoveKDigits.dir/main.cpp.o
RemoveKDigits: CMakeFiles/RemoveKDigits.dir/build.make
RemoveKDigits: CMakeFiles/RemoveKDigits.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/RemoveKDigits/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable RemoveKDigits"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RemoveKDigits.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RemoveKDigits.dir/build: RemoveKDigits

.PHONY : CMakeFiles/RemoveKDigits.dir/build

CMakeFiles/RemoveKDigits.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RemoveKDigits.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RemoveKDigits.dir/clean

CMakeFiles/RemoveKDigits.dir/depend:
	cd /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/RemoveKDigits/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/RemoveKDigits /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/RemoveKDigits /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/RemoveKDigits/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/RemoveKDigits/cmake-build-debug /Users/brendanbusey/Desktop/Github/InterviewPreparation/LeetCode/Medium/RemoveKDigits/cmake-build-debug/CMakeFiles/RemoveKDigits.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RemoveKDigits.dir/depend
