# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /home/ilya/JetBrainsTools/apps/CLion/ch-0/203.7148.70/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/ilya/JetBrainsTools/apps/CLion/ch-0/203.7148.70/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ilya/CLionProjects/GameOfLife

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ilya/CLionProjects/GameOfLife/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GameOfLife.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GameOfLife.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GameOfLife.dir/flags.make

CMakeFiles/GameOfLife.dir/main.c.o: CMakeFiles/GameOfLife.dir/flags.make
CMakeFiles/GameOfLife.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/GameOfLife/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/GameOfLife.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/GameOfLife.dir/main.c.o   -c /home/ilya/CLionProjects/GameOfLife/main.c

CMakeFiles/GameOfLife.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GameOfLife.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ilya/CLionProjects/GameOfLife/main.c > CMakeFiles/GameOfLife.dir/main.c.i

CMakeFiles/GameOfLife.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GameOfLife.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ilya/CLionProjects/GameOfLife/main.c -o CMakeFiles/GameOfLife.dir/main.c.s

CMakeFiles/GameOfLife.dir/misc.c.o: CMakeFiles/GameOfLife.dir/flags.make
CMakeFiles/GameOfLife.dir/misc.c.o: ../misc.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/GameOfLife/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/GameOfLife.dir/misc.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/GameOfLife.dir/misc.c.o   -c /home/ilya/CLionProjects/GameOfLife/misc.c

CMakeFiles/GameOfLife.dir/misc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GameOfLife.dir/misc.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ilya/CLionProjects/GameOfLife/misc.c > CMakeFiles/GameOfLife.dir/misc.c.i

CMakeFiles/GameOfLife.dir/misc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GameOfLife.dir/misc.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ilya/CLionProjects/GameOfLife/misc.c -o CMakeFiles/GameOfLife.dir/misc.c.s

CMakeFiles/GameOfLife.dir/singleProcess.c.o: CMakeFiles/GameOfLife.dir/flags.make
CMakeFiles/GameOfLife.dir/singleProcess.c.o: ../singleProcess.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/GameOfLife/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/GameOfLife.dir/singleProcess.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/GameOfLife.dir/singleProcess.c.o   -c /home/ilya/CLionProjects/GameOfLife/singleProcess.c

CMakeFiles/GameOfLife.dir/singleProcess.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GameOfLife.dir/singleProcess.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ilya/CLionProjects/GameOfLife/singleProcess.c > CMakeFiles/GameOfLife.dir/singleProcess.c.i

CMakeFiles/GameOfLife.dir/singleProcess.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GameOfLife.dir/singleProcess.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ilya/CLionProjects/GameOfLife/singleProcess.c -o CMakeFiles/GameOfLife.dir/singleProcess.c.s

CMakeFiles/GameOfLife.dir/multi_process.c.o: CMakeFiles/GameOfLife.dir/flags.make
CMakeFiles/GameOfLife.dir/multi_process.c.o: ../multi_process.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ilya/CLionProjects/GameOfLife/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/GameOfLife.dir/multi_process.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/GameOfLife.dir/multi_process.c.o   -c /home/ilya/CLionProjects/GameOfLife/multi_process.c

CMakeFiles/GameOfLife.dir/multi_process.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/GameOfLife.dir/multi_process.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ilya/CLionProjects/GameOfLife/multi_process.c > CMakeFiles/GameOfLife.dir/multi_process.c.i

CMakeFiles/GameOfLife.dir/multi_process.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/GameOfLife.dir/multi_process.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ilya/CLionProjects/GameOfLife/multi_process.c -o CMakeFiles/GameOfLife.dir/multi_process.c.s

# Object files for target GameOfLife
GameOfLife_OBJECTS = \
"CMakeFiles/GameOfLife.dir/main.c.o" \
"CMakeFiles/GameOfLife.dir/misc.c.o" \
"CMakeFiles/GameOfLife.dir/singleProcess.c.o" \
"CMakeFiles/GameOfLife.dir/multi_process.c.o"

# External object files for target GameOfLife
GameOfLife_EXTERNAL_OBJECTS =

GameOfLife: CMakeFiles/GameOfLife.dir/main.c.o
GameOfLife: CMakeFiles/GameOfLife.dir/misc.c.o
GameOfLife: CMakeFiles/GameOfLife.dir/singleProcess.c.o
GameOfLife: CMakeFiles/GameOfLife.dir/multi_process.c.o
GameOfLife: CMakeFiles/GameOfLife.dir/build.make
GameOfLife: /usr/lib/x86_64-linux-gnu/libmpich.so
GameOfLife: CMakeFiles/GameOfLife.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ilya/CLionProjects/GameOfLife/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable GameOfLife"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GameOfLife.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GameOfLife.dir/build: GameOfLife

.PHONY : CMakeFiles/GameOfLife.dir/build

CMakeFiles/GameOfLife.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GameOfLife.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GameOfLife.dir/clean

CMakeFiles/GameOfLife.dir/depend:
	cd /home/ilya/CLionProjects/GameOfLife/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilya/CLionProjects/GameOfLife /home/ilya/CLionProjects/GameOfLife /home/ilya/CLionProjects/GameOfLife/cmake-build-debug /home/ilya/CLionProjects/GameOfLife/cmake-build-debug /home/ilya/CLionProjects/GameOfLife/cmake-build-debug/CMakeFiles/GameOfLife.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GameOfLife.dir/depend

