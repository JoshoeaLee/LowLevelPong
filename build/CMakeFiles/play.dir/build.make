# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/joshualee/Code/C++/Games/LowLevelPong

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/joshualee/Code/C++/Games/LowLevelPong/build

# Include any dependencies generated for this target.
include CMakeFiles/play.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/play.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/play.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/play.dir/flags.make

CMakeFiles/play.dir/main.cpp.o: CMakeFiles/play.dir/flags.make
CMakeFiles/play.dir/main.cpp.o: /Users/joshualee/Code/C++/Games/LowLevelPong/main.cpp
CMakeFiles/play.dir/main.cpp.o: CMakeFiles/play.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/joshualee/Code/C++/Games/LowLevelPong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/play.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/play.dir/main.cpp.o -MF CMakeFiles/play.dir/main.cpp.o.d -o CMakeFiles/play.dir/main.cpp.o -c /Users/joshualee/Code/C++/Games/LowLevelPong/main.cpp

CMakeFiles/play.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/play.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/joshualee/Code/C++/Games/LowLevelPong/main.cpp > CMakeFiles/play.dir/main.cpp.i

CMakeFiles/play.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/play.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/joshualee/Code/C++/Games/LowLevelPong/main.cpp -o CMakeFiles/play.dir/main.cpp.s

# Object files for target play
play_OBJECTS = \
"CMakeFiles/play.dir/main.cpp.o"

# External object files for target play
play_EXTERNAL_OBJECTS =

play: CMakeFiles/play.dir/main.cpp.o
play: CMakeFiles/play.dir/build.make
play: /opt/homebrew/Cellar/sdl2/2.28.2/lib/libSDL2.dylib
play: CMakeFiles/play.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/joshualee/Code/C++/Games/LowLevelPong/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable play"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/play.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/play.dir/build: play
.PHONY : CMakeFiles/play.dir/build

CMakeFiles/play.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/play.dir/cmake_clean.cmake
.PHONY : CMakeFiles/play.dir/clean

CMakeFiles/play.dir/depend:
	cd /Users/joshualee/Code/C++/Games/LowLevelPong/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/joshualee/Code/C++/Games/LowLevelPong /Users/joshualee/Code/C++/Games/LowLevelPong /Users/joshualee/Code/C++/Games/LowLevelPong/build /Users/joshualee/Code/C++/Games/LowLevelPong/build /Users/joshualee/Code/C++/Games/LowLevelPong/build/CMakeFiles/play.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/play.dir/depend
