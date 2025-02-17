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
include sleef/src/libm/CMakeFiles/dispavx_obj.dir/depend.make

# Include the progress variables for this target.
include sleef/src/libm/CMakeFiles/dispavx_obj.dir/progress.make

# Include the compile flags for this target's objects.
include sleef/src/libm/CMakeFiles/dispavx_obj.dir/flags.make

sleef/src/libm/dispavx.c: sleef/bin/mkdisp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/fivosts/Repos/pytorch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating dispavx.c"
	cd /home/fivosts/Repos/pytorch/build/sleef/src/libm && /usr/bin/cmake -E copy /home/fivosts/Repos/pytorch/third_party/sleef/src/libm/dispavx.c.org /home/fivosts/Repos/pytorch/build/sleef/src/libm/dispavx.c
	cd /home/fivosts/Repos/pytorch/build/sleef/src/libm && ../../bin/mkdisp 4 8 __m256d __m256 __m128i avx fma4 avx2 >> /home/fivosts/Repos/pytorch/build/sleef/src/libm/dispavx.c

sleef/src/libm/CMakeFiles/dispavx_obj.dir/dispavx.c.o: sleef/src/libm/CMakeFiles/dispavx_obj.dir/flags.make
sleef/src/libm/CMakeFiles/dispavx_obj.dir/dispavx.c.o: sleef/src/libm/dispavx.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fivosts/Repos/pytorch/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object sleef/src/libm/CMakeFiles/dispavx_obj.dir/dispavx.c.o"
	cd /home/fivosts/Repos/pytorch/build/sleef/src/libm && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dispavx_obj.dir/dispavx.c.o   -c /home/fivosts/Repos/pytorch/build/sleef/src/libm/dispavx.c

sleef/src/libm/CMakeFiles/dispavx_obj.dir/dispavx.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dispavx_obj.dir/dispavx.c.i"
	cd /home/fivosts/Repos/pytorch/build/sleef/src/libm && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fivosts/Repos/pytorch/build/sleef/src/libm/dispavx.c > CMakeFiles/dispavx_obj.dir/dispavx.c.i

sleef/src/libm/CMakeFiles/dispavx_obj.dir/dispavx.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dispavx_obj.dir/dispavx.c.s"
	cd /home/fivosts/Repos/pytorch/build/sleef/src/libm && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fivosts/Repos/pytorch/build/sleef/src/libm/dispavx.c -o CMakeFiles/dispavx_obj.dir/dispavx.c.s

dispavx_obj: sleef/src/libm/CMakeFiles/dispavx_obj.dir/dispavx.c.o
dispavx_obj: sleef/src/libm/CMakeFiles/dispavx_obj.dir/build.make

.PHONY : dispavx_obj

# Rule to build all files generated by this target.
sleef/src/libm/CMakeFiles/dispavx_obj.dir/build: dispavx_obj

.PHONY : sleef/src/libm/CMakeFiles/dispavx_obj.dir/build

sleef/src/libm/CMakeFiles/dispavx_obj.dir/clean:
	cd /home/fivosts/Repos/pytorch/build/sleef/src/libm && $(CMAKE_COMMAND) -P CMakeFiles/dispavx_obj.dir/cmake_clean.cmake
.PHONY : sleef/src/libm/CMakeFiles/dispavx_obj.dir/clean

sleef/src/libm/CMakeFiles/dispavx_obj.dir/depend: sleef/src/libm/dispavx.c
	cd /home/fivosts/Repos/pytorch/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fivosts/Repos/pytorch /home/fivosts/Repos/pytorch/third_party/sleef/src/libm /home/fivosts/Repos/pytorch/build /home/fivosts/Repos/pytorch/build/sleef/src/libm /home/fivosts/Repos/pytorch/build/sleef/src/libm/CMakeFiles/dispavx_obj.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : sleef/src/libm/CMakeFiles/dispavx_obj.dir/depend

