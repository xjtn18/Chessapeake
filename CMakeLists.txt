CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
set (CMAKE_CXX_STANDARD 11)

project(ChessLand)


set(incName inc)

add_executable(out
	src/Coord.cpp
	src/main.cpp
	src/Pawn.cpp
	src/King.cpp
	src/Queen.cpp
	src/Rook.cpp
	src/Knight.cpp
	src/Bishop.cpp
	src/GameInstance.cpp
	src/helper.cpp
)

target_include_directories(out PRIVATE $(incName))


