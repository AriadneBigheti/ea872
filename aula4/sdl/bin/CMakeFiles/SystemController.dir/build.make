# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/ariadne/Documentos/ea872/Ariadne/ea872/aula4/sdl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ariadne/Documentos/ea872/Ariadne/ea872/aula4/sdl/bin

# Include any dependencies generated for this target.
include CMakeFiles/SystemController.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SystemController.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SystemController.dir/flags.make

CMakeFiles/SystemController.dir/src/SystemController.cpp.o: CMakeFiles/SystemController.dir/flags.make
CMakeFiles/SystemController.dir/src/SystemController.cpp.o: ../src/SystemController.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ariadne/Documentos/ea872/Ariadne/ea872/aula4/sdl/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SystemController.dir/src/SystemController.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SystemController.dir/src/SystemController.cpp.o -c /home/ariadne/Documentos/ea872/Ariadne/ea872/aula4/sdl/src/SystemController.cpp

CMakeFiles/SystemController.dir/src/SystemController.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SystemController.dir/src/SystemController.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ariadne/Documentos/ea872/Ariadne/ea872/aula4/sdl/src/SystemController.cpp > CMakeFiles/SystemController.dir/src/SystemController.cpp.i

CMakeFiles/SystemController.dir/src/SystemController.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SystemController.dir/src/SystemController.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ariadne/Documentos/ea872/Ariadne/ea872/aula4/sdl/src/SystemController.cpp -o CMakeFiles/SystemController.dir/src/SystemController.cpp.s

# Object files for target SystemController
SystemController_OBJECTS = \
"CMakeFiles/SystemController.dir/src/SystemController.cpp.o"

# External object files for target SystemController
SystemController_EXTERNAL_OBJECTS =

libSystemController.a: CMakeFiles/SystemController.dir/src/SystemController.cpp.o
libSystemController.a: CMakeFiles/SystemController.dir/build.make
libSystemController.a: CMakeFiles/SystemController.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ariadne/Documentos/ea872/Ariadne/ea872/aula4/sdl/bin/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libSystemController.a"
	$(CMAKE_COMMAND) -P CMakeFiles/SystemController.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SystemController.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SystemController.dir/build: libSystemController.a

.PHONY : CMakeFiles/SystemController.dir/build

CMakeFiles/SystemController.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SystemController.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SystemController.dir/clean

CMakeFiles/SystemController.dir/depend:
	cd /home/ariadne/Documentos/ea872/Ariadne/ea872/aula4/sdl/bin && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ariadne/Documentos/ea872/Ariadne/ea872/aula4/sdl /home/ariadne/Documentos/ea872/Ariadne/ea872/aula4/sdl /home/ariadne/Documentos/ea872/Ariadne/ea872/aula4/sdl/bin /home/ariadne/Documentos/ea872/Ariadne/ea872/aula4/sdl/bin /home/ariadne/Documentos/ea872/Ariadne/ea872/aula4/sdl/bin/CMakeFiles/SystemController.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SystemController.dir/depend

