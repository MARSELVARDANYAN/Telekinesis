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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/marsel/Telekinesis/Task_3 Single_Linked_List"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/marsel/Telekinesis/Task_3 Single_Linked_List/build"

# Include any dependencies generated for this target.
include CMakeFiles/Forward_List.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Forward_List.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Forward_List.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Forward_List.dir/flags.make

CMakeFiles/Forward_List.dir/Src/main.cpp.o: CMakeFiles/Forward_List.dir/flags.make
CMakeFiles/Forward_List.dir/Src/main.cpp.o: /home/marsel/Telekinesis/Task_3\ Single_Linked_List/Src/main.cpp
CMakeFiles/Forward_List.dir/Src/main.cpp.o: CMakeFiles/Forward_List.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/marsel/Telekinesis/Task_3 Single_Linked_List/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Forward_List.dir/Src/main.cpp.o"
	/usr/bin/clang++-16 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Forward_List.dir/Src/main.cpp.o -MF CMakeFiles/Forward_List.dir/Src/main.cpp.o.d -o CMakeFiles/Forward_List.dir/Src/main.cpp.o -c "/home/marsel/Telekinesis/Task_3 Single_Linked_List/Src/main.cpp"

CMakeFiles/Forward_List.dir/Src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Forward_List.dir/Src/main.cpp.i"
	/usr/bin/clang++-16 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/marsel/Telekinesis/Task_3 Single_Linked_List/Src/main.cpp" > CMakeFiles/Forward_List.dir/Src/main.cpp.i

CMakeFiles/Forward_List.dir/Src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Forward_List.dir/Src/main.cpp.s"
	/usr/bin/clang++-16 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/marsel/Telekinesis/Task_3 Single_Linked_List/Src/main.cpp" -o CMakeFiles/Forward_List.dir/Src/main.cpp.s

# Object files for target Forward_List
Forward_List_OBJECTS = \
"CMakeFiles/Forward_List.dir/Src/main.cpp.o"

# External object files for target Forward_List
Forward_List_EXTERNAL_OBJECTS =

Forward_List: CMakeFiles/Forward_List.dir/Src/main.cpp.o
Forward_List: CMakeFiles/Forward_List.dir/build.make
Forward_List: CMakeFiles/Forward_List.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/marsel/Telekinesis/Task_3 Single_Linked_List/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Forward_List"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Forward_List.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Forward_List.dir/build: Forward_List
.PHONY : CMakeFiles/Forward_List.dir/build

CMakeFiles/Forward_List.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Forward_List.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Forward_List.dir/clean

CMakeFiles/Forward_List.dir/depend:
	cd "/home/marsel/Telekinesis/Task_3 Single_Linked_List/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/marsel/Telekinesis/Task_3 Single_Linked_List" "/home/marsel/Telekinesis/Task_3 Single_Linked_List" "/home/marsel/Telekinesis/Task_3 Single_Linked_List/build" "/home/marsel/Telekinesis/Task_3 Single_Linked_List/build" "/home/marsel/Telekinesis/Task_3 Single_Linked_List/build/CMakeFiles/Forward_List.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Forward_List.dir/depend
