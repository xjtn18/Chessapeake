# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.18.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.18.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Jacob/dev/projects/Chessapeake

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Jacob/dev/projects/Chessapeake/mac-build

# Include any dependencies generated for this target.
include CMakeFiles/out.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/out.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/out.dir/flags.make

CMakeFiles/out.dir/src/Coord.cpp.o: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/src/Coord.cpp.o: ../src/Coord.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Jacob/dev/projects/Chessapeake/mac-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/out.dir/src/Coord.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/out.dir/src/Coord.cpp.o -c /Users/Jacob/dev/projects/Chessapeake/src/Coord.cpp

CMakeFiles/out.dir/src/Coord.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/out.dir/src/Coord.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Jacob/dev/projects/Chessapeake/src/Coord.cpp > CMakeFiles/out.dir/src/Coord.cpp.i

CMakeFiles/out.dir/src/Coord.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/out.dir/src/Coord.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Jacob/dev/projects/Chessapeake/src/Coord.cpp -o CMakeFiles/out.dir/src/Coord.cpp.s

CMakeFiles/out.dir/src/main.cpp.o: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Jacob/dev/projects/Chessapeake/mac-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/out.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/out.dir/src/main.cpp.o -c /Users/Jacob/dev/projects/Chessapeake/src/main.cpp

CMakeFiles/out.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/out.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Jacob/dev/projects/Chessapeake/src/main.cpp > CMakeFiles/out.dir/src/main.cpp.i

CMakeFiles/out.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/out.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Jacob/dev/projects/Chessapeake/src/main.cpp -o CMakeFiles/out.dir/src/main.cpp.s

CMakeFiles/out.dir/src/Pawn.cpp.o: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/src/Pawn.cpp.o: ../src/Pawn.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Jacob/dev/projects/Chessapeake/mac-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/out.dir/src/Pawn.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/out.dir/src/Pawn.cpp.o -c /Users/Jacob/dev/projects/Chessapeake/src/Pawn.cpp

CMakeFiles/out.dir/src/Pawn.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/out.dir/src/Pawn.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Jacob/dev/projects/Chessapeake/src/Pawn.cpp > CMakeFiles/out.dir/src/Pawn.cpp.i

CMakeFiles/out.dir/src/Pawn.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/out.dir/src/Pawn.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Jacob/dev/projects/Chessapeake/src/Pawn.cpp -o CMakeFiles/out.dir/src/Pawn.cpp.s

CMakeFiles/out.dir/src/King.cpp.o: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/src/King.cpp.o: ../src/King.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Jacob/dev/projects/Chessapeake/mac-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/out.dir/src/King.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/out.dir/src/King.cpp.o -c /Users/Jacob/dev/projects/Chessapeake/src/King.cpp

CMakeFiles/out.dir/src/King.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/out.dir/src/King.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Jacob/dev/projects/Chessapeake/src/King.cpp > CMakeFiles/out.dir/src/King.cpp.i

CMakeFiles/out.dir/src/King.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/out.dir/src/King.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Jacob/dev/projects/Chessapeake/src/King.cpp -o CMakeFiles/out.dir/src/King.cpp.s

CMakeFiles/out.dir/src/Queen.cpp.o: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/src/Queen.cpp.o: ../src/Queen.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Jacob/dev/projects/Chessapeake/mac-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/out.dir/src/Queen.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/out.dir/src/Queen.cpp.o -c /Users/Jacob/dev/projects/Chessapeake/src/Queen.cpp

CMakeFiles/out.dir/src/Queen.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/out.dir/src/Queen.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Jacob/dev/projects/Chessapeake/src/Queen.cpp > CMakeFiles/out.dir/src/Queen.cpp.i

CMakeFiles/out.dir/src/Queen.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/out.dir/src/Queen.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Jacob/dev/projects/Chessapeake/src/Queen.cpp -o CMakeFiles/out.dir/src/Queen.cpp.s

CMakeFiles/out.dir/src/Rook.cpp.o: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/src/Rook.cpp.o: ../src/Rook.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Jacob/dev/projects/Chessapeake/mac-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/out.dir/src/Rook.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/out.dir/src/Rook.cpp.o -c /Users/Jacob/dev/projects/Chessapeake/src/Rook.cpp

CMakeFiles/out.dir/src/Rook.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/out.dir/src/Rook.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Jacob/dev/projects/Chessapeake/src/Rook.cpp > CMakeFiles/out.dir/src/Rook.cpp.i

CMakeFiles/out.dir/src/Rook.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/out.dir/src/Rook.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Jacob/dev/projects/Chessapeake/src/Rook.cpp -o CMakeFiles/out.dir/src/Rook.cpp.s

CMakeFiles/out.dir/src/Knight.cpp.o: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/src/Knight.cpp.o: ../src/Knight.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Jacob/dev/projects/Chessapeake/mac-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/out.dir/src/Knight.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/out.dir/src/Knight.cpp.o -c /Users/Jacob/dev/projects/Chessapeake/src/Knight.cpp

CMakeFiles/out.dir/src/Knight.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/out.dir/src/Knight.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Jacob/dev/projects/Chessapeake/src/Knight.cpp > CMakeFiles/out.dir/src/Knight.cpp.i

CMakeFiles/out.dir/src/Knight.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/out.dir/src/Knight.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Jacob/dev/projects/Chessapeake/src/Knight.cpp -o CMakeFiles/out.dir/src/Knight.cpp.s

CMakeFiles/out.dir/src/Bishop.cpp.o: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/src/Bishop.cpp.o: ../src/Bishop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Jacob/dev/projects/Chessapeake/mac-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/out.dir/src/Bishop.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/out.dir/src/Bishop.cpp.o -c /Users/Jacob/dev/projects/Chessapeake/src/Bishop.cpp

CMakeFiles/out.dir/src/Bishop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/out.dir/src/Bishop.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Jacob/dev/projects/Chessapeake/src/Bishop.cpp > CMakeFiles/out.dir/src/Bishop.cpp.i

CMakeFiles/out.dir/src/Bishop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/out.dir/src/Bishop.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Jacob/dev/projects/Chessapeake/src/Bishop.cpp -o CMakeFiles/out.dir/src/Bishop.cpp.s

CMakeFiles/out.dir/src/GameInstance.cpp.o: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/src/GameInstance.cpp.o: ../src/GameInstance.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Jacob/dev/projects/Chessapeake/mac-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/out.dir/src/GameInstance.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/out.dir/src/GameInstance.cpp.o -c /Users/Jacob/dev/projects/Chessapeake/src/GameInstance.cpp

CMakeFiles/out.dir/src/GameInstance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/out.dir/src/GameInstance.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Jacob/dev/projects/Chessapeake/src/GameInstance.cpp > CMakeFiles/out.dir/src/GameInstance.cpp.i

CMakeFiles/out.dir/src/GameInstance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/out.dir/src/GameInstance.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Jacob/dev/projects/Chessapeake/src/GameInstance.cpp -o CMakeFiles/out.dir/src/GameInstance.cpp.s

CMakeFiles/out.dir/src/MoveParser.cpp.o: CMakeFiles/out.dir/flags.make
CMakeFiles/out.dir/src/MoveParser.cpp.o: ../src/MoveParser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Jacob/dev/projects/Chessapeake/mac-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/out.dir/src/MoveParser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/out.dir/src/MoveParser.cpp.o -c /Users/Jacob/dev/projects/Chessapeake/src/MoveParser.cpp

CMakeFiles/out.dir/src/MoveParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/out.dir/src/MoveParser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Jacob/dev/projects/Chessapeake/src/MoveParser.cpp > CMakeFiles/out.dir/src/MoveParser.cpp.i

CMakeFiles/out.dir/src/MoveParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/out.dir/src/MoveParser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Jacob/dev/projects/Chessapeake/src/MoveParser.cpp -o CMakeFiles/out.dir/src/MoveParser.cpp.s

# Object files for target out
out_OBJECTS = \
"CMakeFiles/out.dir/src/Coord.cpp.o" \
"CMakeFiles/out.dir/src/main.cpp.o" \
"CMakeFiles/out.dir/src/Pawn.cpp.o" \
"CMakeFiles/out.dir/src/King.cpp.o" \
"CMakeFiles/out.dir/src/Queen.cpp.o" \
"CMakeFiles/out.dir/src/Rook.cpp.o" \
"CMakeFiles/out.dir/src/Knight.cpp.o" \
"CMakeFiles/out.dir/src/Bishop.cpp.o" \
"CMakeFiles/out.dir/src/GameInstance.cpp.o" \
"CMakeFiles/out.dir/src/MoveParser.cpp.o"

# External object files for target out
out_EXTERNAL_OBJECTS =

out: CMakeFiles/out.dir/src/Coord.cpp.o
out: CMakeFiles/out.dir/src/main.cpp.o
out: CMakeFiles/out.dir/src/Pawn.cpp.o
out: CMakeFiles/out.dir/src/King.cpp.o
out: CMakeFiles/out.dir/src/Queen.cpp.o
out: CMakeFiles/out.dir/src/Rook.cpp.o
out: CMakeFiles/out.dir/src/Knight.cpp.o
out: CMakeFiles/out.dir/src/Bishop.cpp.o
out: CMakeFiles/out.dir/src/GameInstance.cpp.o
out: CMakeFiles/out.dir/src/MoveParser.cpp.o
out: CMakeFiles/out.dir/build.make
out: CMakeFiles/out.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Jacob/dev/projects/Chessapeake/mac-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable out"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/out.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/out.dir/build: out

.PHONY : CMakeFiles/out.dir/build

CMakeFiles/out.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/out.dir/cmake_clean.cmake
.PHONY : CMakeFiles/out.dir/clean

CMakeFiles/out.dir/depend:
	cd /Users/Jacob/dev/projects/Chessapeake/mac-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Jacob/dev/projects/Chessapeake /Users/Jacob/dev/projects/Chessapeake /Users/Jacob/dev/projects/Chessapeake/mac-build /Users/Jacob/dev/projects/Chessapeake/mac-build /Users/Jacob/dev/projects/Chessapeake/mac-build/CMakeFiles/out.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/out.dir/depend

