# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pepoberes/TP2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pepoberes/TP2/build

# Include any dependencies generated for this target.
include CMakeFiles/drones.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/drones.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/drones.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/drones.dir/flags.make

CMakeFiles/drones.dir/examples/EJ2/main.cpp.o: CMakeFiles/drones.dir/flags.make
CMakeFiles/drones.dir/examples/EJ2/main.cpp.o: /home/pepoberes/TP2/examples/EJ2/main.cpp
CMakeFiles/drones.dir/examples/EJ2/main.cpp.o: CMakeFiles/drones.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/pepoberes/TP2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/drones.dir/examples/EJ2/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/drones.dir/examples/EJ2/main.cpp.o -MF CMakeFiles/drones.dir/examples/EJ2/main.cpp.o.d -o CMakeFiles/drones.dir/examples/EJ2/main.cpp.o -c /home/pepoberes/TP2/examples/EJ2/main.cpp

CMakeFiles/drones.dir/examples/EJ2/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/drones.dir/examples/EJ2/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pepoberes/TP2/examples/EJ2/main.cpp > CMakeFiles/drones.dir/examples/EJ2/main.cpp.i

CMakeFiles/drones.dir/examples/EJ2/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/drones.dir/examples/EJ2/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pepoberes/TP2/examples/EJ2/main.cpp -o CMakeFiles/drones.dir/examples/EJ2/main.cpp.s

CMakeFiles/drones.dir/sources/EJ2/Drone.cpp.o: CMakeFiles/drones.dir/flags.make
CMakeFiles/drones.dir/sources/EJ2/Drone.cpp.o: /home/pepoberes/TP2/sources/EJ2/Drone.cpp
CMakeFiles/drones.dir/sources/EJ2/Drone.cpp.o: CMakeFiles/drones.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/pepoberes/TP2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/drones.dir/sources/EJ2/Drone.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/drones.dir/sources/EJ2/Drone.cpp.o -MF CMakeFiles/drones.dir/sources/EJ2/Drone.cpp.o.d -o CMakeFiles/drones.dir/sources/EJ2/Drone.cpp.o -c /home/pepoberes/TP2/sources/EJ2/Drone.cpp

CMakeFiles/drones.dir/sources/EJ2/Drone.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/drones.dir/sources/EJ2/Drone.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pepoberes/TP2/sources/EJ2/Drone.cpp > CMakeFiles/drones.dir/sources/EJ2/Drone.cpp.i

CMakeFiles/drones.dir/sources/EJ2/Drone.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/drones.dir/sources/EJ2/Drone.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pepoberes/TP2/sources/EJ2/Drone.cpp -o CMakeFiles/drones.dir/sources/EJ2/Drone.cpp.s

# Object files for target drones
drones_OBJECTS = \
"CMakeFiles/drones.dir/examples/EJ2/main.cpp.o" \
"CMakeFiles/drones.dir/sources/EJ2/Drone.cpp.o"

# External object files for target drones
drones_EXTERNAL_OBJECTS =

drones: CMakeFiles/drones.dir/examples/EJ2/main.cpp.o
drones: CMakeFiles/drones.dir/sources/EJ2/Drone.cpp.o
drones: CMakeFiles/drones.dir/build.make
drones: CMakeFiles/drones.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/pepoberes/TP2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable drones"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/drones.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/drones.dir/build: drones
.PHONY : CMakeFiles/drones.dir/build

CMakeFiles/drones.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/drones.dir/cmake_clean.cmake
.PHONY : CMakeFiles/drones.dir/clean

CMakeFiles/drones.dir/depend:
	cd /home/pepoberes/TP2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pepoberes/TP2 /home/pepoberes/TP2 /home/pepoberes/TP2/build /home/pepoberes/TP2/build /home/pepoberes/TP2/build/CMakeFiles/drones.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/drones.dir/depend

