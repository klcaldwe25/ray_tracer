# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.1/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kylecaldwell/ray_tracer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kylecaldwell/ray_tracer/build

# Include any dependencies generated for this target.
include tst/CMakeFiles/ray_tracer_tst.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tst/CMakeFiles/ray_tracer_tst.dir/compiler_depend.make

# Include the progress variables for this target.
include tst/CMakeFiles/ray_tracer_tst.dir/progress.make

# Include the compile flags for this target's objects.
include tst/CMakeFiles/ray_tracer_tst.dir/flags.make

tst/CMakeFiles/ray_tracer_tst.dir/Canvas-test.cpp.o: tst/CMakeFiles/ray_tracer_tst.dir/flags.make
tst/CMakeFiles/ray_tracer_tst.dir/Canvas-test.cpp.o: /Users/kylecaldwell/ray_tracer/tst/Canvas-test.cpp
tst/CMakeFiles/ray_tracer_tst.dir/Canvas-test.cpp.o: tst/CMakeFiles/ray_tracer_tst.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kylecaldwell/ray_tracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tst/CMakeFiles/ray_tracer_tst.dir/Canvas-test.cpp.o"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tst/CMakeFiles/ray_tracer_tst.dir/Canvas-test.cpp.o -MF CMakeFiles/ray_tracer_tst.dir/Canvas-test.cpp.o.d -o CMakeFiles/ray_tracer_tst.dir/Canvas-test.cpp.o -c /Users/kylecaldwell/ray_tracer/tst/Canvas-test.cpp

tst/CMakeFiles/ray_tracer_tst.dir/Canvas-test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer_tst.dir/Canvas-test.cpp.i"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kylecaldwell/ray_tracer/tst/Canvas-test.cpp > CMakeFiles/ray_tracer_tst.dir/Canvas-test.cpp.i

tst/CMakeFiles/ray_tracer_tst.dir/Canvas-test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer_tst.dir/Canvas-test.cpp.s"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kylecaldwell/ray_tracer/tst/Canvas-test.cpp -o CMakeFiles/ray_tracer_tst.dir/Canvas-test.cpp.s

tst/CMakeFiles/ray_tracer_tst.dir/Color-test.cpp.o: tst/CMakeFiles/ray_tracer_tst.dir/flags.make
tst/CMakeFiles/ray_tracer_tst.dir/Color-test.cpp.o: /Users/kylecaldwell/ray_tracer/tst/Color-test.cpp
tst/CMakeFiles/ray_tracer_tst.dir/Color-test.cpp.o: tst/CMakeFiles/ray_tracer_tst.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kylecaldwell/ray_tracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tst/CMakeFiles/ray_tracer_tst.dir/Color-test.cpp.o"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tst/CMakeFiles/ray_tracer_tst.dir/Color-test.cpp.o -MF CMakeFiles/ray_tracer_tst.dir/Color-test.cpp.o.d -o CMakeFiles/ray_tracer_tst.dir/Color-test.cpp.o -c /Users/kylecaldwell/ray_tracer/tst/Color-test.cpp

tst/CMakeFiles/ray_tracer_tst.dir/Color-test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer_tst.dir/Color-test.cpp.i"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kylecaldwell/ray_tracer/tst/Color-test.cpp > CMakeFiles/ray_tracer_tst.dir/Color-test.cpp.i

tst/CMakeFiles/ray_tracer_tst.dir/Color-test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer_tst.dir/Color-test.cpp.s"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kylecaldwell/ray_tracer/tst/Color-test.cpp -o CMakeFiles/ray_tracer_tst.dir/Color-test.cpp.s

tst/CMakeFiles/ray_tracer_tst.dir/Intersection-test.cpp.o: tst/CMakeFiles/ray_tracer_tst.dir/flags.make
tst/CMakeFiles/ray_tracer_tst.dir/Intersection-test.cpp.o: /Users/kylecaldwell/ray_tracer/tst/Intersection-test.cpp
tst/CMakeFiles/ray_tracer_tst.dir/Intersection-test.cpp.o: tst/CMakeFiles/ray_tracer_tst.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kylecaldwell/ray_tracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tst/CMakeFiles/ray_tracer_tst.dir/Intersection-test.cpp.o"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tst/CMakeFiles/ray_tracer_tst.dir/Intersection-test.cpp.o -MF CMakeFiles/ray_tracer_tst.dir/Intersection-test.cpp.o.d -o CMakeFiles/ray_tracer_tst.dir/Intersection-test.cpp.o -c /Users/kylecaldwell/ray_tracer/tst/Intersection-test.cpp

tst/CMakeFiles/ray_tracer_tst.dir/Intersection-test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer_tst.dir/Intersection-test.cpp.i"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kylecaldwell/ray_tracer/tst/Intersection-test.cpp > CMakeFiles/ray_tracer_tst.dir/Intersection-test.cpp.i

tst/CMakeFiles/ray_tracer_tst.dir/Intersection-test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer_tst.dir/Intersection-test.cpp.s"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kylecaldwell/ray_tracer/tst/Intersection-test.cpp -o CMakeFiles/ray_tracer_tst.dir/Intersection-test.cpp.s

tst/CMakeFiles/ray_tracer_tst.dir/Intersections-test.cpp.o: tst/CMakeFiles/ray_tracer_tst.dir/flags.make
tst/CMakeFiles/ray_tracer_tst.dir/Intersections-test.cpp.o: /Users/kylecaldwell/ray_tracer/tst/Intersections-test.cpp
tst/CMakeFiles/ray_tracer_tst.dir/Intersections-test.cpp.o: tst/CMakeFiles/ray_tracer_tst.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kylecaldwell/ray_tracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object tst/CMakeFiles/ray_tracer_tst.dir/Intersections-test.cpp.o"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tst/CMakeFiles/ray_tracer_tst.dir/Intersections-test.cpp.o -MF CMakeFiles/ray_tracer_tst.dir/Intersections-test.cpp.o.d -o CMakeFiles/ray_tracer_tst.dir/Intersections-test.cpp.o -c /Users/kylecaldwell/ray_tracer/tst/Intersections-test.cpp

tst/CMakeFiles/ray_tracer_tst.dir/Intersections-test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer_tst.dir/Intersections-test.cpp.i"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kylecaldwell/ray_tracer/tst/Intersections-test.cpp > CMakeFiles/ray_tracer_tst.dir/Intersections-test.cpp.i

tst/CMakeFiles/ray_tracer_tst.dir/Intersections-test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer_tst.dir/Intersections-test.cpp.s"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kylecaldwell/ray_tracer/tst/Intersections-test.cpp -o CMakeFiles/ray_tracer_tst.dir/Intersections-test.cpp.s

tst/CMakeFiles/ray_tracer_tst.dir/Matrix-test.cpp.o: tst/CMakeFiles/ray_tracer_tst.dir/flags.make
tst/CMakeFiles/ray_tracer_tst.dir/Matrix-test.cpp.o: /Users/kylecaldwell/ray_tracer/tst/Matrix-test.cpp
tst/CMakeFiles/ray_tracer_tst.dir/Matrix-test.cpp.o: tst/CMakeFiles/ray_tracer_tst.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kylecaldwell/ray_tracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object tst/CMakeFiles/ray_tracer_tst.dir/Matrix-test.cpp.o"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tst/CMakeFiles/ray_tracer_tst.dir/Matrix-test.cpp.o -MF CMakeFiles/ray_tracer_tst.dir/Matrix-test.cpp.o.d -o CMakeFiles/ray_tracer_tst.dir/Matrix-test.cpp.o -c /Users/kylecaldwell/ray_tracer/tst/Matrix-test.cpp

tst/CMakeFiles/ray_tracer_tst.dir/Matrix-test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer_tst.dir/Matrix-test.cpp.i"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kylecaldwell/ray_tracer/tst/Matrix-test.cpp > CMakeFiles/ray_tracer_tst.dir/Matrix-test.cpp.i

tst/CMakeFiles/ray_tracer_tst.dir/Matrix-test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer_tst.dir/Matrix-test.cpp.s"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kylecaldwell/ray_tracer/tst/Matrix-test.cpp -o CMakeFiles/ray_tracer_tst.dir/Matrix-test.cpp.s

tst/CMakeFiles/ray_tracer_tst.dir/Ray-test.cpp.o: tst/CMakeFiles/ray_tracer_tst.dir/flags.make
tst/CMakeFiles/ray_tracer_tst.dir/Ray-test.cpp.o: /Users/kylecaldwell/ray_tracer/tst/Ray-test.cpp
tst/CMakeFiles/ray_tracer_tst.dir/Ray-test.cpp.o: tst/CMakeFiles/ray_tracer_tst.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kylecaldwell/ray_tracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object tst/CMakeFiles/ray_tracer_tst.dir/Ray-test.cpp.o"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tst/CMakeFiles/ray_tracer_tst.dir/Ray-test.cpp.o -MF CMakeFiles/ray_tracer_tst.dir/Ray-test.cpp.o.d -o CMakeFiles/ray_tracer_tst.dir/Ray-test.cpp.o -c /Users/kylecaldwell/ray_tracer/tst/Ray-test.cpp

tst/CMakeFiles/ray_tracer_tst.dir/Ray-test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer_tst.dir/Ray-test.cpp.i"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kylecaldwell/ray_tracer/tst/Ray-test.cpp > CMakeFiles/ray_tracer_tst.dir/Ray-test.cpp.i

tst/CMakeFiles/ray_tracer_tst.dir/Ray-test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer_tst.dir/Ray-test.cpp.s"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kylecaldwell/ray_tracer/tst/Ray-test.cpp -o CMakeFiles/ray_tracer_tst.dir/Ray-test.cpp.s

tst/CMakeFiles/ray_tracer_tst.dir/Shape-test.cpp.o: tst/CMakeFiles/ray_tracer_tst.dir/flags.make
tst/CMakeFiles/ray_tracer_tst.dir/Shape-test.cpp.o: /Users/kylecaldwell/ray_tracer/tst/Shape-test.cpp
tst/CMakeFiles/ray_tracer_tst.dir/Shape-test.cpp.o: tst/CMakeFiles/ray_tracer_tst.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kylecaldwell/ray_tracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object tst/CMakeFiles/ray_tracer_tst.dir/Shape-test.cpp.o"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tst/CMakeFiles/ray_tracer_tst.dir/Shape-test.cpp.o -MF CMakeFiles/ray_tracer_tst.dir/Shape-test.cpp.o.d -o CMakeFiles/ray_tracer_tst.dir/Shape-test.cpp.o -c /Users/kylecaldwell/ray_tracer/tst/Shape-test.cpp

tst/CMakeFiles/ray_tracer_tst.dir/Shape-test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer_tst.dir/Shape-test.cpp.i"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kylecaldwell/ray_tracer/tst/Shape-test.cpp > CMakeFiles/ray_tracer_tst.dir/Shape-test.cpp.i

tst/CMakeFiles/ray_tracer_tst.dir/Shape-test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer_tst.dir/Shape-test.cpp.s"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kylecaldwell/ray_tracer/tst/Shape-test.cpp -o CMakeFiles/ray_tracer_tst.dir/Shape-test.cpp.s

tst/CMakeFiles/ray_tracer_tst.dir/Tuple-test.cpp.o: tst/CMakeFiles/ray_tracer_tst.dir/flags.make
tst/CMakeFiles/ray_tracer_tst.dir/Tuple-test.cpp.o: /Users/kylecaldwell/ray_tracer/tst/Tuple-test.cpp
tst/CMakeFiles/ray_tracer_tst.dir/Tuple-test.cpp.o: tst/CMakeFiles/ray_tracer_tst.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kylecaldwell/ray_tracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object tst/CMakeFiles/ray_tracer_tst.dir/Tuple-test.cpp.o"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tst/CMakeFiles/ray_tracer_tst.dir/Tuple-test.cpp.o -MF CMakeFiles/ray_tracer_tst.dir/Tuple-test.cpp.o.d -o CMakeFiles/ray_tracer_tst.dir/Tuple-test.cpp.o -c /Users/kylecaldwell/ray_tracer/tst/Tuple-test.cpp

tst/CMakeFiles/ray_tracer_tst.dir/Tuple-test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer_tst.dir/Tuple-test.cpp.i"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kylecaldwell/ray_tracer/tst/Tuple-test.cpp > CMakeFiles/ray_tracer_tst.dir/Tuple-test.cpp.i

tst/CMakeFiles/ray_tracer_tst.dir/Tuple-test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer_tst.dir/Tuple-test.cpp.s"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kylecaldwell/ray_tracer/tst/Tuple-test.cpp -o CMakeFiles/ray_tracer_tst.dir/Tuple-test.cpp.s

tst/CMakeFiles/ray_tracer_tst.dir/main.cpp.o: tst/CMakeFiles/ray_tracer_tst.dir/flags.make
tst/CMakeFiles/ray_tracer_tst.dir/main.cpp.o: /Users/kylecaldwell/ray_tracer/tst/main.cpp
tst/CMakeFiles/ray_tracer_tst.dir/main.cpp.o: tst/CMakeFiles/ray_tracer_tst.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kylecaldwell/ray_tracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object tst/CMakeFiles/ray_tracer_tst.dir/main.cpp.o"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT tst/CMakeFiles/ray_tracer_tst.dir/main.cpp.o -MF CMakeFiles/ray_tracer_tst.dir/main.cpp.o.d -o CMakeFiles/ray_tracer_tst.dir/main.cpp.o -c /Users/kylecaldwell/ray_tracer/tst/main.cpp

tst/CMakeFiles/ray_tracer_tst.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ray_tracer_tst.dir/main.cpp.i"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kylecaldwell/ray_tracer/tst/main.cpp > CMakeFiles/ray_tracer_tst.dir/main.cpp.i

tst/CMakeFiles/ray_tracer_tst.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ray_tracer_tst.dir/main.cpp.s"
	cd /Users/kylecaldwell/ray_tracer/build/tst && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kylecaldwell/ray_tracer/tst/main.cpp -o CMakeFiles/ray_tracer_tst.dir/main.cpp.s

# Object files for target ray_tracer_tst
ray_tracer_tst_OBJECTS = \
"CMakeFiles/ray_tracer_tst.dir/Canvas-test.cpp.o" \
"CMakeFiles/ray_tracer_tst.dir/Color-test.cpp.o" \
"CMakeFiles/ray_tracer_tst.dir/Intersection-test.cpp.o" \
"CMakeFiles/ray_tracer_tst.dir/Intersections-test.cpp.o" \
"CMakeFiles/ray_tracer_tst.dir/Matrix-test.cpp.o" \
"CMakeFiles/ray_tracer_tst.dir/Ray-test.cpp.o" \
"CMakeFiles/ray_tracer_tst.dir/Shape-test.cpp.o" \
"CMakeFiles/ray_tracer_tst.dir/Tuple-test.cpp.o" \
"CMakeFiles/ray_tracer_tst.dir/main.cpp.o"

# External object files for target ray_tracer_tst
ray_tracer_tst_EXTERNAL_OBJECTS =

tst/ray_tracer_tst: tst/CMakeFiles/ray_tracer_tst.dir/Canvas-test.cpp.o
tst/ray_tracer_tst: tst/CMakeFiles/ray_tracer_tst.dir/Color-test.cpp.o
tst/ray_tracer_tst: tst/CMakeFiles/ray_tracer_tst.dir/Intersection-test.cpp.o
tst/ray_tracer_tst: tst/CMakeFiles/ray_tracer_tst.dir/Intersections-test.cpp.o
tst/ray_tracer_tst: tst/CMakeFiles/ray_tracer_tst.dir/Matrix-test.cpp.o
tst/ray_tracer_tst: tst/CMakeFiles/ray_tracer_tst.dir/Ray-test.cpp.o
tst/ray_tracer_tst: tst/CMakeFiles/ray_tracer_tst.dir/Shape-test.cpp.o
tst/ray_tracer_tst: tst/CMakeFiles/ray_tracer_tst.dir/Tuple-test.cpp.o
tst/ray_tracer_tst: tst/CMakeFiles/ray_tracer_tst.dir/main.cpp.o
tst/ray_tracer_tst: tst/CMakeFiles/ray_tracer_tst.dir/build.make
tst/ray_tracer_tst: src/libray_tracer_lib.a
tst/ray_tracer_tst: lib/libgtest.a
tst/ray_tracer_tst: tst/CMakeFiles/ray_tracer_tst.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kylecaldwell/ray_tracer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable ray_tracer_tst"
	cd /Users/kylecaldwell/ray_tracer/build/tst && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ray_tracer_tst.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tst/CMakeFiles/ray_tracer_tst.dir/build: tst/ray_tracer_tst
.PHONY : tst/CMakeFiles/ray_tracer_tst.dir/build

tst/CMakeFiles/ray_tracer_tst.dir/clean:
	cd /Users/kylecaldwell/ray_tracer/build/tst && $(CMAKE_COMMAND) -P CMakeFiles/ray_tracer_tst.dir/cmake_clean.cmake
.PHONY : tst/CMakeFiles/ray_tracer_tst.dir/clean

tst/CMakeFiles/ray_tracer_tst.dir/depend:
	cd /Users/kylecaldwell/ray_tracer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kylecaldwell/ray_tracer /Users/kylecaldwell/ray_tracer/tst /Users/kylecaldwell/ray_tracer/build /Users/kylecaldwell/ray_tracer/build/tst /Users/kylecaldwell/ray_tracer/build/tst/CMakeFiles/ray_tracer_tst.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tst/CMakeFiles/ray_tracer_tst.dir/depend

