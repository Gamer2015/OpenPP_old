# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.1

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Softwareentwicklung\C++\CMake\bin\cmake.exe

# The command to remove a file.
RM = C:\Softwareentwicklung\C++\CMake\bin\cmake.exe -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Stefan\Documents\GitHub\Openpp\Sources\Playground\AI\NeuralNetworks3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Stefan\Documents\GitHub\Openpp\Sources\Playground\AI\NeuralNetworks3-build

# Include any dependencies generated for this target.
include CMakeFiles/PlaygroundAINeuralNetworks3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PlaygroundAINeuralNetworks3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PlaygroundAINeuralNetworks3.dir/flags.make

CMakeFiles/PlaygroundAINeuralNetworks3.dir/main.cpp.obj: CMakeFiles/PlaygroundAINeuralNetworks3.dir/flags.make
CMakeFiles/PlaygroundAINeuralNetworks3.dir/main.cpp.obj: CMakeFiles/PlaygroundAINeuralNetworks3.dir/includes_CXX.rsp
CMakeFiles/PlaygroundAINeuralNetworks3.dir/main.cpp.obj: C:/Users/Stefan/Documents/GitHub/Openpp/Sources/Playground/AI/NeuralNetworks3/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report C:\Users\Stefan\Documents\GitHub\Openpp\Sources\Playground\AI\NeuralNetworks3-build\CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/PlaygroundAINeuralNetworks3.dir/main.cpp.obj"
	C:\Softwareentwicklung\C++\Qt\Tools\mingw48_32\bin\g++.exe   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles\PlaygroundAINeuralNetworks3.dir\main.cpp.obj -c C:\Users\Stefan\Documents\GitHub\Openpp\Sources\Playground\AI\NeuralNetworks3\main.cpp

CMakeFiles/PlaygroundAINeuralNetworks3.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PlaygroundAINeuralNetworks3.dir/main.cpp.i"
	C:\Softwareentwicklung\C++\Qt\Tools\mingw48_32\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -E C:\Users\Stefan\Documents\GitHub\Openpp\Sources\Playground\AI\NeuralNetworks3\main.cpp > CMakeFiles\PlaygroundAINeuralNetworks3.dir\main.cpp.i

CMakeFiles/PlaygroundAINeuralNetworks3.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PlaygroundAINeuralNetworks3.dir/main.cpp.s"
	C:\Softwareentwicklung\C++\Qt\Tools\mingw48_32\bin\g++.exe  $(CXX_DEFINES) $(CXX_FLAGS) -S C:\Users\Stefan\Documents\GitHub\Openpp\Sources\Playground\AI\NeuralNetworks3\main.cpp -o CMakeFiles\PlaygroundAINeuralNetworks3.dir\main.cpp.s

CMakeFiles/PlaygroundAINeuralNetworks3.dir/main.cpp.obj.requires:
.PHONY : CMakeFiles/PlaygroundAINeuralNetworks3.dir/main.cpp.obj.requires

CMakeFiles/PlaygroundAINeuralNetworks3.dir/main.cpp.obj.provides: CMakeFiles/PlaygroundAINeuralNetworks3.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\PlaygroundAINeuralNetworks3.dir\build.make CMakeFiles/PlaygroundAINeuralNetworks3.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/PlaygroundAINeuralNetworks3.dir/main.cpp.obj.provides

CMakeFiles/PlaygroundAINeuralNetworks3.dir/main.cpp.obj.provides.build: CMakeFiles/PlaygroundAINeuralNetworks3.dir/main.cpp.obj

# Object files for target PlaygroundAINeuralNetworks3
PlaygroundAINeuralNetworks3_OBJECTS = \
"CMakeFiles/PlaygroundAINeuralNetworks3.dir/main.cpp.obj"

# External object files for target PlaygroundAINeuralNetworks3
PlaygroundAINeuralNetworks3_EXTERNAL_OBJECTS =

C:/Users/Stefan/Documents/GitHub/Openpp/Sources/Playground/AI/NeuralNetworks3/PlaygroundAINeuralNetworks3.exe: CMakeFiles/PlaygroundAINeuralNetworks3.dir/main.cpp.obj
C:/Users/Stefan/Documents/GitHub/Openpp/Sources/Playground/AI/NeuralNetworks3/PlaygroundAINeuralNetworks3.exe: CMakeFiles/PlaygroundAINeuralNetworks3.dir/build.make
C:/Users/Stefan/Documents/GitHub/Openpp/Sources/Playground/AI/NeuralNetworks3/PlaygroundAINeuralNetworks3.exe: CMakeFiles/PlaygroundAINeuralNetworks3.dir/linklibs.rsp
C:/Users/Stefan/Documents/GitHub/Openpp/Sources/Playground/AI/NeuralNetworks3/PlaygroundAINeuralNetworks3.exe: CMakeFiles/PlaygroundAINeuralNetworks3.dir/objects1.rsp
C:/Users/Stefan/Documents/GitHub/Openpp/Sources/Playground/AI/NeuralNetworks3/PlaygroundAINeuralNetworks3.exe: CMakeFiles/PlaygroundAINeuralNetworks3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable C:\Users\Stefan\Documents\GitHub\Openpp\Sources\Playground\AI\NeuralNetworks3\PlaygroundAINeuralNetworks3.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PlaygroundAINeuralNetworks3.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PlaygroundAINeuralNetworks3.dir/build: C:/Users/Stefan/Documents/GitHub/Openpp/Sources/Playground/AI/NeuralNetworks3/PlaygroundAINeuralNetworks3.exe
.PHONY : CMakeFiles/PlaygroundAINeuralNetworks3.dir/build

CMakeFiles/PlaygroundAINeuralNetworks3.dir/requires: CMakeFiles/PlaygroundAINeuralNetworks3.dir/main.cpp.obj.requires
.PHONY : CMakeFiles/PlaygroundAINeuralNetworks3.dir/requires

CMakeFiles/PlaygroundAINeuralNetworks3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PlaygroundAINeuralNetworks3.dir\cmake_clean.cmake
.PHONY : CMakeFiles/PlaygroundAINeuralNetworks3.dir/clean

CMakeFiles/PlaygroundAINeuralNetworks3.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Stefan\Documents\GitHub\Openpp\Sources\Playground\AI\NeuralNetworks3 C:\Users\Stefan\Documents\GitHub\Openpp\Sources\Playground\AI\NeuralNetworks3 C:\Users\Stefan\Documents\GitHub\Openpp\Sources\Playground\AI\NeuralNetworks3-build C:\Users\Stefan\Documents\GitHub\Openpp\Sources\Playground\AI\NeuralNetworks3-build C:\Users\Stefan\Documents\GitHub\Openpp\Sources\Playground\AI\NeuralNetworks3-build\CMakeFiles\PlaygroundAINeuralNetworks3.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PlaygroundAINeuralNetworks3.dir/depend

