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
CMAKE_SOURCE_DIR = "/home/pi/Desktop/LF09/Visual Studio Code Projects/servo"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/pi/Desktop/LF09/Visual Studio Code Projects/servo/build"

# Include any dependencies generated for this target.
include CMakeFiles/servo.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/servo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/servo.dir/flags.make

CMakeFiles/servo.dir/main.cpp.o: CMakeFiles/servo.dir/flags.make
CMakeFiles/servo.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/pi/Desktop/LF09/Visual Studio Code Projects/servo/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/servo.dir/main.cpp.o"
	/usr/bin/arm-linux-gnueabihf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/servo.dir/main.cpp.o -c "/home/pi/Desktop/LF09/Visual Studio Code Projects/servo/main.cpp"

CMakeFiles/servo.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servo.dir/main.cpp.i"
	/usr/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/pi/Desktop/LF09/Visual Studio Code Projects/servo/main.cpp" > CMakeFiles/servo.dir/main.cpp.i

CMakeFiles/servo.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servo.dir/main.cpp.s"
	/usr/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/pi/Desktop/LF09/Visual Studio Code Projects/servo/main.cpp" -o CMakeFiles/servo.dir/main.cpp.s

CMakeFiles/servo.dir/sg90.cpp.o: CMakeFiles/servo.dir/flags.make
CMakeFiles/servo.dir/sg90.cpp.o: ../sg90.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/pi/Desktop/LF09/Visual Studio Code Projects/servo/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/servo.dir/sg90.cpp.o"
	/usr/bin/arm-linux-gnueabihf-g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/servo.dir/sg90.cpp.o -c "/home/pi/Desktop/LF09/Visual Studio Code Projects/servo/sg90.cpp"

CMakeFiles/servo.dir/sg90.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/servo.dir/sg90.cpp.i"
	/usr/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/pi/Desktop/LF09/Visual Studio Code Projects/servo/sg90.cpp" > CMakeFiles/servo.dir/sg90.cpp.i

CMakeFiles/servo.dir/sg90.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/servo.dir/sg90.cpp.s"
	/usr/bin/arm-linux-gnueabihf-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/pi/Desktop/LF09/Visual Studio Code Projects/servo/sg90.cpp" -o CMakeFiles/servo.dir/sg90.cpp.s

# Object files for target servo
servo_OBJECTS = \
"CMakeFiles/servo.dir/main.cpp.o" \
"CMakeFiles/servo.dir/sg90.cpp.o"

# External object files for target servo
servo_EXTERNAL_OBJECTS =

servo: CMakeFiles/servo.dir/main.cpp.o
servo: CMakeFiles/servo.dir/sg90.cpp.o
servo: CMakeFiles/servo.dir/build.make
servo: /usr/lib/libwiringPi.so
servo: CMakeFiles/servo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/pi/Desktop/LF09/Visual Studio Code Projects/servo/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable servo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/servo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/servo.dir/build: servo

.PHONY : CMakeFiles/servo.dir/build

CMakeFiles/servo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/servo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/servo.dir/clean

CMakeFiles/servo.dir/depend:
	cd "/home/pi/Desktop/LF09/Visual Studio Code Projects/servo/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/pi/Desktop/LF09/Visual Studio Code Projects/servo" "/home/pi/Desktop/LF09/Visual Studio Code Projects/servo" "/home/pi/Desktop/LF09/Visual Studio Code Projects/servo/build" "/home/pi/Desktop/LF09/Visual Studio Code Projects/servo/build" "/home/pi/Desktop/LF09/Visual Studio Code Projects/servo/build/CMakeFiles/servo.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/servo.dir/depend

