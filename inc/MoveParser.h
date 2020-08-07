#pragma once
#include "GameInstance.h"
#include <iostream>
#include <string>
#include <regex>

bool patternMatch(std::string input, std::string piece_str);
void parseMoveRequest(std::string input, GameInstance& game);
void readMoveList(std::string filename, GameInstance& game);


struct InvalidMove : public std::exception
{
	std::string err() const throw (){
		return "Invalid move was requested";
	}
};

const std::map<std::string, std::string> piecePatterns{
	{"pawn", "[a-h](x[a-h])?[1-8]"},
	{"king", "Kx?[a-h][1-8]"},
	{"bishop", "Bx?[a-h][1-8]"},
	{"queen", "Qx?[a-h][1-8]"},
	{"rook", "Rx?[a-h][1-8]"},
	{"knight", "Nx?[a-h][1-8]"}
};


template<typename T>
void getCurrentAndDestination(std::string input, GameInstance& game, Coord& c, Coord& d){
	// pulls current coordinate and destination coordinate and edits reference coordinates
	int dcol, drow, pawn_col = -1;
	dcol = coordMap.at(input[input.length()-2]) - 1;
	drow = std::atoi(&(input[input.length()-1])) - 1;
	bool capture_requested = (input.find('x') != std::string::npos); // true if 'x' was found in the notation
	if (patternMatch(input, "pawn")){
		pawn_col = coordMap.at(input[0]) - 1;
	}
	c = game.findPiece<T>(dcol, drow, capture_requested, pawn_col);
	if (!c)
		throw InvalidMove();
	d = {dcol, drow};
}


