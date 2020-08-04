#pragma once
#include "GameInstance.h"
#include <iostream>
#include <string>
#include <regex>

bool patternMatch(std::string input, std::string piece_str);
void parseMoveRequest(std::string input, GameInstance& game);
void readMoveList(std::string filename, GameInstance& game);

const std::map<std::string, std::string> piecePatterns{
	{"pawn", "[a-h][1-8]"},
	{"king", "K[a-h][1-8]"},
	{"bishop", "B[a-h][1-8]"}, 
	{"queen", "Q[a-h][1-8]"},
	{"rook", "R[a-h][1-8]"},
	{"knight", "N[a-h][1-8]"}
};

template<typename T>
void getCurrentAndDestination(std::string input, GameInstance& game){
	// pulls current coordinate and destination coordinate and edits reference coordinates
	Coord c, d;
	int dcol = coordMap.at(input[1]) - 1;
	int drow = std::atoi(&input[2]) - 1;
	c = game.findPiece<T>(dcol, drow);
	if (!c)
		return;
	d = {dcol, drow};
	game.requestMove(c, d);
}


