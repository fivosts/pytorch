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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fivosts/Repos/pytorch

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fivosts/Repos/pytorch/build

# Include any dependencies generated for this target.
include sleef/src/libm/CMakeFiles/mkmasked_gnuabi.dir/depend.make

# Include the progress variables for this target.
include sleef/src/libm/CMakeFiles/mkmasked_gnuabi.dir/progress.make

# Include the compile flags for this target's objects.
include sleef/src/libm/CMakeFiles/mkmasked_gnuabi.dir/flags.make

sleef/src/libm/CMakeFiles/mkmasked_gnuabi.dir/mkmasked_gnuabi.c.o: sleef/src/libm/CMakeFiles/mkmasked_gnuabi.dir/flags.make
sleef/src/libm/CMakeFiles/mkmasked_gnuabi.dir/mkmasked_gnuabi.c.o: ../third_party/sleef/src/libm/mkmasked_gnuabi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fivosts/Repos/pytorch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object sleef/src/libm/CMakeFiles/mkmasked_gnuabi.dir/mkmasked_gnuabi.c.o"
	cd /home/fivosts/Repos/pytorch/build/sleef/src/libm && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/mkmasked_gnuabi.dir/mkmasked_gnuabi.c.o   -c /home/fivosts/Repos/pytorch/third_party/sleef/src/libm/mkmasked_gnuabi.c

sleef/src/libm/CMakeFiles/mkmasked_gnuabi.dir/mkmasked_gnuabi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/mkmasked_gnuabi.dir/mkmasked_gnuabi.c.i"
	cd /home/fivosts/Repos/pytorch/build/sleef/src/libm && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fivosts/Repos/pytorch/third_party/sleef/src/libm/mkmasked_gnuabi.c > CMakeFiles/mkmasked_gnuabi.dir/mkmasked_gnuabi.c.i

sleef/src/libm/CMakeFiles/mkmasked_gnuabi.dir/mkmasked_gnuabi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/mkmasked_gnuabi.dir/mkmasked_gnuabi.c.s"
	cd /home/fivosts/Repos/pytorch/build/sleef/src/libm && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fivosts/Repos/pytorch/third_party/sleef/src/libm/mkmasked_gnuabi.c -o CMakeFiles/mkmasked_gnuabi.dir/mkmasked_gnuabi.c.s

# Object files for target mkmasked_gnuabi
mkmasked_gnuabi_OBJECTS = \
"CMakeFiles/mkmasked_gnuabi.dir/mkmasked_gnuabi.c.o"

# External object files for target mkmasked_gnuabi
mkmasked_gnuabi_EXTERNAL_OBJECTS =

sleef/bin/mkmasked_gnuabi: sleef/src/libm/CMakeFiles/mkmasked_gnuabi.dir/mkmasked_gnuabi.c.o
sleef/bin/mkmasked_gnuabi: sleef/src/libm/CMakeFiles/mkmasked_gnuabi.dir/build.make
sleef/bin/mkmasked_gnuabi: sleef/src/libm/CMakeFiles/mkmasked_gnuabi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fivosts/Repos/pytorch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ../../bin/mkmasked_gnuabi"
	cd /home/fivosts/Repos/pytorch/build/sleef/src/libm && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/mkmasked_gnuabi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
sleef/src/libm/CMakeFiles/mkmasked_gnuabi.dir/build: sleef/bin/mkmasked_gnuabi

.PHONY : sleef/src/libm/CMakeFiles/mkmasked_gnuabi.dir/build

sleef/src/libm/CMakeFiles/mkmasked_gnuabi.dir/clean:
	cd /home/fivosts/Repos/pytorch/build/sleef/src/libm && $(CMAKE_COMMAND) -P CMakeFiles/mkmasked_gnuabi.dir/cmake_clean.cmake
.PHONY : sleef/src/libm/CMakeFiles/mkmasked_gnuabi.dir/clean

sleef/src/libm/CMakeFiles/mkmasked_gnuabi.dir/depend:
	cd /home/fivosts/Repos/pytorch/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fivosts/Repos/pytorch /home/fivosts/Repos/pytorch/third_party/sleef/src/libm /home/fivosts/Repos/pytorch/build /home/fivosts/Repos/pytorch/build/sleef/src/libm /home/fivosts/Repos/pytorch/build/sleef/src/libm/CMakeFiles/mkmasked_gnuabi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sleef/src/libm/CMakeFiles/mkmasked_gnuabi.dir/depend

