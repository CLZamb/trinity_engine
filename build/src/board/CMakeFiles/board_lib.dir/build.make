# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.21.3_1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.21.3_1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/cristofher/desktop/practice/c++/ChessProject_v2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/cristofher/desktop/practice/c++/ChessProject_v2/build

# Include any dependencies generated for this target.
include src/board/CMakeFiles/board_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/board/CMakeFiles/board_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include src/board/CMakeFiles/board_lib.dir/progress.make

# Include the compile flags for this target's objects.
include src/board/CMakeFiles/board_lib.dir/flags.make

src/board/CMakeFiles/board_lib.dir/board.cpp.o: src/board/CMakeFiles/board_lib.dir/flags.make
src/board/CMakeFiles/board_lib.dir/board.cpp.o: ../src/board/board.cpp
src/board/CMakeFiles/board_lib.dir/board.cpp.o: src/board/CMakeFiles/board_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/desktop/practice/c++/ChessProject_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/board/CMakeFiles/board_lib.dir/board.cpp.o"
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/board/CMakeFiles/board_lib.dir/board.cpp.o -MF CMakeFiles/board_lib.dir/board.cpp.o.d -o CMakeFiles/board_lib.dir/board.cpp.o -c /Users/cristofher/desktop/practice/c++/ChessProject_v2/src/board/board.cpp

src/board/CMakeFiles/board_lib.dir/board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/board_lib.dir/board.cpp.i"
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/desktop/practice/c++/ChessProject_v2/src/board/board.cpp > CMakeFiles/board_lib.dir/board.cpp.i

src/board/CMakeFiles/board_lib.dir/board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/board_lib.dir/board.cpp.s"
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/desktop/practice/c++/ChessProject_v2/src/board/board.cpp -o CMakeFiles/board_lib.dir/board.cpp.s

src/board/CMakeFiles/board_lib.dir/board_with_info.cpp.o: src/board/CMakeFiles/board_lib.dir/flags.make
src/board/CMakeFiles/board_lib.dir/board_with_info.cpp.o: ../src/board/board_with_info.cpp
src/board/CMakeFiles/board_lib.dir/board_with_info.cpp.o: src/board/CMakeFiles/board_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/desktop/practice/c++/ChessProject_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/board/CMakeFiles/board_lib.dir/board_with_info.cpp.o"
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/board/CMakeFiles/board_lib.dir/board_with_info.cpp.o -MF CMakeFiles/board_lib.dir/board_with_info.cpp.o.d -o CMakeFiles/board_lib.dir/board_with_info.cpp.o -c /Users/cristofher/desktop/practice/c++/ChessProject_v2/src/board/board_with_info.cpp

src/board/CMakeFiles/board_lib.dir/board_with_info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/board_lib.dir/board_with_info.cpp.i"
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/desktop/practice/c++/ChessProject_v2/src/board/board_with_info.cpp > CMakeFiles/board_lib.dir/board_with_info.cpp.i

src/board/CMakeFiles/board_lib.dir/board_with_info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/board_lib.dir/board_with_info.cpp.s"
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/desktop/practice/c++/ChessProject_v2/src/board/board_with_info.cpp -o CMakeFiles/board_lib.dir/board_with_info.cpp.s

src/board/CMakeFiles/board_lib.dir/magic_bitboard.cpp.o: src/board/CMakeFiles/board_lib.dir/flags.make
src/board/CMakeFiles/board_lib.dir/magic_bitboard.cpp.o: ../src/board/magic_bitboard.cpp
src/board/CMakeFiles/board_lib.dir/magic_bitboard.cpp.o: src/board/CMakeFiles/board_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/desktop/practice/c++/ChessProject_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/board/CMakeFiles/board_lib.dir/magic_bitboard.cpp.o"
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/board/CMakeFiles/board_lib.dir/magic_bitboard.cpp.o -MF CMakeFiles/board_lib.dir/magic_bitboard.cpp.o.d -o CMakeFiles/board_lib.dir/magic_bitboard.cpp.o -c /Users/cristofher/desktop/practice/c++/ChessProject_v2/src/board/magic_bitboard.cpp

src/board/CMakeFiles/board_lib.dir/magic_bitboard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/board_lib.dir/magic_bitboard.cpp.i"
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/desktop/practice/c++/ChessProject_v2/src/board/magic_bitboard.cpp > CMakeFiles/board_lib.dir/magic_bitboard.cpp.i

src/board/CMakeFiles/board_lib.dir/magic_bitboard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/board_lib.dir/magic_bitboard.cpp.s"
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/desktop/practice/c++/ChessProject_v2/src/board/magic_bitboard.cpp -o CMakeFiles/board_lib.dir/magic_bitboard.cpp.s

src/board/CMakeFiles/board_lib.dir/move_validation.cpp.o: src/board/CMakeFiles/board_lib.dir/flags.make
src/board/CMakeFiles/board_lib.dir/move_validation.cpp.o: ../src/board/move_validation.cpp
src/board/CMakeFiles/board_lib.dir/move_validation.cpp.o: src/board/CMakeFiles/board_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/desktop/practice/c++/ChessProject_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/board/CMakeFiles/board_lib.dir/move_validation.cpp.o"
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/board/CMakeFiles/board_lib.dir/move_validation.cpp.o -MF CMakeFiles/board_lib.dir/move_validation.cpp.o.d -o CMakeFiles/board_lib.dir/move_validation.cpp.o -c /Users/cristofher/desktop/practice/c++/ChessProject_v2/src/board/move_validation.cpp

src/board/CMakeFiles/board_lib.dir/move_validation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/board_lib.dir/move_validation.cpp.i"
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/desktop/practice/c++/ChessProject_v2/src/board/move_validation.cpp > CMakeFiles/board_lib.dir/move_validation.cpp.i

src/board/CMakeFiles/board_lib.dir/move_validation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/board_lib.dir/move_validation.cpp.s"
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/desktop/practice/c++/ChessProject_v2/src/board/move_validation.cpp -o CMakeFiles/board_lib.dir/move_validation.cpp.s

src/board/CMakeFiles/board_lib.dir/info.cpp.o: src/board/CMakeFiles/board_lib.dir/flags.make
src/board/CMakeFiles/board_lib.dir/info.cpp.o: ../src/board/info.cpp
src/board/CMakeFiles/board_lib.dir/info.cpp.o: src/board/CMakeFiles/board_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/desktop/practice/c++/ChessProject_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object src/board/CMakeFiles/board_lib.dir/info.cpp.o"
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/board/CMakeFiles/board_lib.dir/info.cpp.o -MF CMakeFiles/board_lib.dir/info.cpp.o.d -o CMakeFiles/board_lib.dir/info.cpp.o -c /Users/cristofher/desktop/practice/c++/ChessProject_v2/src/board/info.cpp

src/board/CMakeFiles/board_lib.dir/info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/board_lib.dir/info.cpp.i"
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/desktop/practice/c++/ChessProject_v2/src/board/info.cpp > CMakeFiles/board_lib.dir/info.cpp.i

src/board/CMakeFiles/board_lib.dir/info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/board_lib.dir/info.cpp.s"
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/desktop/practice/c++/ChessProject_v2/src/board/info.cpp -o CMakeFiles/board_lib.dir/info.cpp.s

src/board/CMakeFiles/board_lib.dir/square.cpp.o: src/board/CMakeFiles/board_lib.dir/flags.make
src/board/CMakeFiles/board_lib.dir/square.cpp.o: ../src/board/square.cpp
src/board/CMakeFiles/board_lib.dir/square.cpp.o: src/board/CMakeFiles/board_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/cristofher/desktop/practice/c++/ChessProject_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object src/board/CMakeFiles/board_lib.dir/square.cpp.o"
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/board/CMakeFiles/board_lib.dir/square.cpp.o -MF CMakeFiles/board_lib.dir/square.cpp.o.d -o CMakeFiles/board_lib.dir/square.cpp.o -c /Users/cristofher/desktop/practice/c++/ChessProject_v2/src/board/square.cpp

src/board/CMakeFiles/board_lib.dir/square.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/board_lib.dir/square.cpp.i"
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/cristofher/desktop/practice/c++/ChessProject_v2/src/board/square.cpp > CMakeFiles/board_lib.dir/square.cpp.i

src/board/CMakeFiles/board_lib.dir/square.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/board_lib.dir/square.cpp.s"
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/cristofher/desktop/practice/c++/ChessProject_v2/src/board/square.cpp -o CMakeFiles/board_lib.dir/square.cpp.s

# Object files for target board_lib
board_lib_OBJECTS = \
"CMakeFiles/board_lib.dir/board.cpp.o" \
"CMakeFiles/board_lib.dir/board_with_info.cpp.o" \
"CMakeFiles/board_lib.dir/magic_bitboard.cpp.o" \
"CMakeFiles/board_lib.dir/move_validation.cpp.o" \
"CMakeFiles/board_lib.dir/info.cpp.o" \
"CMakeFiles/board_lib.dir/square.cpp.o"

# External object files for target board_lib
board_lib_EXTERNAL_OBJECTS =

lib/libboard_lib.a: src/board/CMakeFiles/board_lib.dir/board.cpp.o
lib/libboard_lib.a: src/board/CMakeFiles/board_lib.dir/board_with_info.cpp.o
lib/libboard_lib.a: src/board/CMakeFiles/board_lib.dir/magic_bitboard.cpp.o
lib/libboard_lib.a: src/board/CMakeFiles/board_lib.dir/move_validation.cpp.o
lib/libboard_lib.a: src/board/CMakeFiles/board_lib.dir/info.cpp.o
lib/libboard_lib.a: src/board/CMakeFiles/board_lib.dir/square.cpp.o
lib/libboard_lib.a: src/board/CMakeFiles/board_lib.dir/build.make
lib/libboard_lib.a: src/board/CMakeFiles/board_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/cristofher/desktop/practice/c++/ChessProject_v2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library ../../lib/libboard_lib.a"
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && $(CMAKE_COMMAND) -P CMakeFiles/board_lib.dir/cmake_clean_target.cmake
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/board_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/board/CMakeFiles/board_lib.dir/build: lib/libboard_lib.a
.PHONY : src/board/CMakeFiles/board_lib.dir/build

src/board/CMakeFiles/board_lib.dir/clean:
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board && $(CMAKE_COMMAND) -P CMakeFiles/board_lib.dir/cmake_clean.cmake
.PHONY : src/board/CMakeFiles/board_lib.dir/clean

src/board/CMakeFiles/board_lib.dir/depend:
	cd /Users/cristofher/desktop/practice/c++/ChessProject_v2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/cristofher/desktop/practice/c++/ChessProject_v2 /Users/cristofher/desktop/practice/c++/ChessProject_v2/src/board /Users/cristofher/desktop/practice/c++/ChessProject_v2/build /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board /Users/cristofher/desktop/practice/c++/ChessProject_v2/build/src/board/CMakeFiles/board_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/board/CMakeFiles/board_lib.dir/depend

