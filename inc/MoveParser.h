#pragma once
#include "GameInstance.h"
#include <iostream>
#include <string>
#include <regex>

bool PatternMatch(std::string input, std::string piece_str);
void ParseMoveRequest(std::string input, GameInstance& game);
void ReadMoveList(std::string filename, GameInstance& game);
bool IsCapture(FlatMatrix<AbstractPiece>& board, Coord d);
Coord FindPawn(FlatMatrix<AbstractPiece>& board, Coord d, int pawn_col, std::string player);


struct InvalidMove : public std::exception
{
	std::string err() const throw (){
		return "Invalid move was requested";
	}
};


// maps chess board letter notation to integers
const std::map<char, int> coordMap =
	{
		{'a',1},
		{'b',2},
		{'c',3},
		{'d',4},
		{'e',5},
		{'f',6},
		{'g',7},
		{'h',8}
	};


const std::map<std::string, std::string> piecePatterns{
	{"pawn", "[a-h](x[a-h])?[1-8]"},
	{"king", "Kx?[a-h][1-8]"},
	{"bishop", "Bx?[a-h][1-8]"},
	{"queen", "Qx?[a-h][1-8]"},
	{"rook", "Rx?[a-h][1-8]"},
	{"knight", "Nx?[a-h][1-8]"}
};


// templates must always be defined in headers
template<typename T>
Coord FindPiece(FlatMatrix<AbstractPiece>& board, Coord d, std::string player, bool capture_requested){
	//
	// Finds the piece that can make the requested move.
	// Throws an error if no piece is found that can make such a move.
	//
	bool found = false;
	Coord c;
	AbstractPiece* piece;

	if (IsCapture(board, d) != capture_requested){ // check to make sure user specified 'takes' when they should have
		return c;
	}

	for (int x = 0; x < board.wide; x++){
		for (int y = 0; y < board.high; y++){
			piece = board(x, y);
			if (dynamic_cast<T*>(piece) != nullptr && piece->color == player){ // if its the type piece we're looking for
				std::vector<Coord> v = piece->getPlacements(board, x, y, 2);
				if (std::find(v.begin(), v.end(), d) != v.end()){
					c = {x, y};
					if (found){ // if we have already found another similar piece that can make this move
						std::cout << "Ambiguous" << std::endl;
						c = {-1,-1}; // set c to back to bad coordinate
						return c;
					}
					found = true;
				}
			}
		}
	}
	return c;
}


template<typename T>
void CheckMove(std::string input, GameInstance& game, Coord& c, Coord& d){
	// pulls current coordinate and destination coordinate and edits reference coordinates
	int dcol, drow, pawn_col;
	dcol = coordMap.at(input[input.length()-2]) - 1;
	drow = std::atoi(&(input[input.length()-1])) - 1;
	bool capture_requested = (input.find('x') != std::string::npos); // true if 'x' was found in the notation
	if (PatternMatch(input, "pawn")){
		pawn_col = coordMap.at(input[0]) - 1;
		c = FindPawn(game.mainstate.board, {dcol, drow}, pawn_col, game.mainstate.toMove);
	} else {
		c = FindPiece<T>(game.mainstate.board, {dcol, drow}, game.mainstate.toMove, capture_requested);
	}
	if (!c)
		throw InvalidMove();
	d = {dcol, drow};
}


