# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.22.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.22.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/btobab/GitHub/MyDL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/btobab/GitHub/MyDL/build

# Include any dependencies generated for this target.
include src/CMakeFiles/lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/lib.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/lib.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/lib.dir/flags.make

src/CMakeFiles/lib.dir/SeqIter.cpp.o: src/CMakeFiles/lib.dir/flags.make
src/CMakeFiles/lib.dir/SeqIter.cpp.o: ../src/SeqIter.cpp
src/CMakeFiles/lib.dir/SeqIter.cpp.o: src/CMakeFiles/lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/btobab/GitHub/MyDL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/lib.dir/SeqIter.cpp.o"
	cd /Users/btobab/GitHub/MyDL/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/lib.dir/SeqIter.cpp.o -MF CMakeFiles/lib.dir/SeqIter.cpp.o.d -o CMakeFiles/lib.dir/SeqIter.cpp.o -c /Users/btobab/GitHub/MyDL/src/SeqIter.cpp

src/CMakeFiles/lib.dir/SeqIter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/SeqIter.cpp.i"
	cd /Users/btobab/GitHub/MyDL/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/btobab/GitHub/MyDL/src/SeqIter.cpp > CMakeFiles/lib.dir/SeqIter.cpp.i

src/CMakeFiles/lib.dir/SeqIter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/SeqIter.cpp.s"
	cd /Users/btobab/GitHub/MyDL/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/btobab/GitHub/MyDL/src/SeqIter.cpp -o CMakeFiles/lib.dir/SeqIter.cpp.s

src/CMakeFiles/lib.dir/matrix.cpp.o: src/CMakeFiles/lib.dir/flags.make
src/CMakeFiles/lib.dir/matrix.cpp.o: ../src/matrix.cpp
src/CMakeFiles/lib.dir/matrix.cpp.o: src/CMakeFiles/lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/btobab/GitHub/MyDL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/lib.dir/matrix.cpp.o"
	cd /Users/btobab/GitHub/MyDL/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/lib.dir/matrix.cpp.o -MF CMakeFiles/lib.dir/matrix.cpp.o.d -o CMakeFiles/lib.dir/matrix.cpp.o -c /Users/btobab/GitHub/MyDL/src/matrix.cpp

src/CMakeFiles/lib.dir/matrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/matrix.cpp.i"
	cd /Users/btobab/GitHub/MyDL/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/btobab/GitHub/MyDL/src/matrix.cpp > CMakeFiles/lib.dir/matrix.cpp.i

src/CMakeFiles/lib.dir/matrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/matrix.cpp.s"
	cd /Users/btobab/GitHub/MyDL/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/btobab/GitHub/MyDL/src/matrix.cpp -o CMakeFiles/lib.dir/matrix.cpp.s

src/CMakeFiles/lib.dir/matrix_grad.cpp.o: src/CMakeFiles/lib.dir/flags.make
src/CMakeFiles/lib.dir/matrix_grad.cpp.o: ../src/matrix_grad.cpp
src/CMakeFiles/lib.dir/matrix_grad.cpp.o: src/CMakeFiles/lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/btobab/GitHub/MyDL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/lib.dir/matrix_grad.cpp.o"
	cd /Users/btobab/GitHub/MyDL/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/lib.dir/matrix_grad.cpp.o -MF CMakeFiles/lib.dir/matrix_grad.cpp.o.d -o CMakeFiles/lib.dir/matrix_grad.cpp.o -c /Users/btobab/GitHub/MyDL/src/matrix_grad.cpp

src/CMakeFiles/lib.dir/matrix_grad.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/matrix_grad.cpp.i"
	cd /Users/btobab/GitHub/MyDL/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/btobab/GitHub/MyDL/src/matrix_grad.cpp > CMakeFiles/lib.dir/matrix_grad.cpp.i

src/CMakeFiles/lib.dir/matrix_grad.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/matrix_grad.cpp.s"
	cd /Users/btobab/GitHub/MyDL/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/btobab/GitHub/MyDL/src/matrix_grad.cpp -o CMakeFiles/lib.dir/matrix_grad.cpp.s

src/CMakeFiles/lib.dir/new_sequence.cpp.o: src/CMakeFiles/lib.dir/flags.make
src/CMakeFiles/lib.dir/new_sequence.cpp.o: ../src/new_sequence.cpp
src/CMakeFiles/lib.dir/new_sequence.cpp.o: src/CMakeFiles/lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/btobab/GitHub/MyDL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/CMakeFiles/lib.dir/new_sequence.cpp.o"
	cd /Users/btobab/GitHub/MyDL/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/lib.dir/new_sequence.cpp.o -MF CMakeFiles/lib.dir/new_sequence.cpp.o.d -o CMakeFiles/lib.dir/new_sequence.cpp.o -c /Users/btobab/GitHub/MyDL/src/new_sequence.cpp

src/CMakeFiles/lib.dir/new_sequence.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/new_sequence.cpp.i"
	cd /Users/btobab/GitHub/MyDL/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/btobab/GitHub/MyDL/src/new_sequence.cpp > CMakeFiles/lib.dir/new_sequence.cpp.i

src/CMakeFiles/lib.dir/new_sequence.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/new_sequence.cpp.s"
	cd /Users/btobab/GitHub/MyDL/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/btobab/GitHub/MyDL/src/new_sequence.cpp -o CMakeFiles/lib.dir/new_sequence.cpp.s

src/CMakeFiles/lib.dir/numSequence.cpp.o: src/CMakeFiles/lib.dir/flags.make
src/CMakeFiles/lib.dir/numSequence.cpp.o: ../src/numSequence.cpp
src/CMakeFiles/lib.dir/numSequence.cpp.o: src/CMakeFiles/lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/btobab/GitHub/MyDL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/CMakeFiles/lib.dir/numSequence.cpp.o"
	cd /Users/btobab/GitHub/MyDL/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/lib.dir/numSequence.cpp.o -MF CMakeFiles/lib.dir/numSequence.cpp.o.d -o CMakeFiles/lib.dir/numSequence.cpp.o -c /Users/btobab/GitHub/MyDL/src/numSequence.cpp

src/CMakeFiles/lib.dir/numSequence.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/numSequence.cpp.i"
	cd /Users/btobab/GitHub/MyDL/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/btobab/GitHub/MyDL/src/numSequence.cpp > CMakeFiles/lib.dir/numSequence.cpp.i

src/CMakeFiles/lib.dir/numSequence.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/numSequence.cpp.s"
	cd /Users/btobab/GitHub/MyDL/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/btobab/GitHub/MyDL/src/numSequence.cpp -o CMakeFiles/lib.dir/numSequence.cpp.s

src/CMakeFiles/lib.dir/stack.cpp.o: src/CMakeFiles/lib.dir/flags.make
src/CMakeFiles/lib.dir/stack.cpp.o: ../src/stack.cpp
src/CMakeFiles/lib.dir/stack.cpp.o: src/CMakeFiles/lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/btobab/GitHub/MyDL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/CMakeFiles/lib.dir/stack.cpp.o"
	cd /Users/btobab/GitHub/MyDL/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/lib.dir/stack.cpp.o -MF CMakeFiles/lib.dir/stack.cpp.o.d -o CMakeFiles/lib.dir/stack.cpp.o -c /Users/btobab/GitHub/MyDL/src/stack.cpp

src/CMakeFiles/lib.dir/stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib.dir/stack.cpp.i"
	cd /Users/btobab/GitHub/MyDL/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/btobab/GitHub/MyDL/src/stack.cpp > CMakeFiles/lib.dir/stack.cpp.i

src/CMakeFiles/lib.dir/stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib.dir/stack.cpp.s"
	cd /Users/btobab/GitHub/MyDL/build/src && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/btobab/GitHub/MyDL/src/stack.cpp -o CMakeFiles/lib.dir/stack.cpp.s

# Object files for target lib
lib_OBJECTS = \
"CMakeFiles/lib.dir/SeqIter.cpp.o" \
"CMakeFiles/lib.dir/matrix.cpp.o" \
"CMakeFiles/lib.dir/matrix_grad.cpp.o" \
"CMakeFiles/lib.dir/new_sequence.cpp.o" \
"CMakeFiles/lib.dir/numSequence.cpp.o" \
"CMakeFiles/lib.dir/stack.cpp.o"

# External object files for target lib
lib_EXTERNAL_OBJECTS =

src/liblib.a: src/CMakeFiles/lib.dir/SeqIter.cpp.o
src/liblib.a: src/CMakeFiles/lib.dir/matrix.cpp.o
src/liblib.a: src/CMakeFiles/lib.dir/matrix_grad.cpp.o
src/liblib.a: src/CMakeFiles/lib.dir/new_sequence.cpp.o
src/liblib.a: src/CMakeFiles/lib.dir/numSequence.cpp.o
src/liblib.a: src/CMakeFiles/lib.dir/stack.cpp.o
src/liblib.a: src/CMakeFiles/lib.dir/build.make
src/liblib.a: src/CMakeFiles/lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/btobab/GitHub/MyDL/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library liblib.a"
	cd /Users/btobab/GitHub/MyDL/build/src && $(CMAKE_COMMAND) -P CMakeFiles/lib.dir/cmake_clean_target.cmake
	cd /Users/btobab/GitHub/MyDL/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/lib.dir/build: src/liblib.a
.PHONY : src/CMakeFiles/lib.dir/build

src/CMakeFiles/lib.dir/clean:
	cd /Users/btobab/GitHub/MyDL/build/src && $(CMAKE_COMMAND) -P CMakeFiles/lib.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/lib.dir/clean

src/CMakeFiles/lib.dir/depend:
	cd /Users/btobab/GitHub/MyDL/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/btobab/GitHub/MyDL /Users/btobab/GitHub/MyDL/src /Users/btobab/GitHub/MyDL/build /Users/btobab/GitHub/MyDL/build/src /Users/btobab/GitHub/MyDL/build/src/CMakeFiles/lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/lib.dir/depend

