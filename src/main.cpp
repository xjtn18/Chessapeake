#include "../inc/Pieces.h"
#include "../inc/constants.h"
#include "../inc/GameInstance.h"
#include "../inc/Coord.h"
#include <iostream>
#include <string>
#include <regex>
#include <stdlib.h>

// Change to 'CLS' instead of 'clear' this if you are running on windows without cygwin
#define CLEAROUT system("clear") 


// below doesnt work
/*
#ifdef __unix
#define CLEAROUT system("clear")
#endif

#ifdef _WIN32
#include <process.h>
#define CLEAROUT system("CLS")
#endif
*/

const std::map<std::string, std::string> piecePatterns{
	{"pawn", "[a-h][1-8]"},
	{"king", "K[a-h][1-8]"},
	{"bishop", "B[a-h][1-8]"}, 
	{"queen", "Q[a-h][1-8]"},
	{"rook", "R[a-h][1-8]"},
	{"knight", "N[a-h][1-8]"}
};


bool patternMatch(std::string input, std::string piece_str){
	return std::regex_match(input, std::regex(piecePatterns.at(piece_str)));
}


void parseMoveRequestInput(std::string input, GameInstance& game){
	Coord c, d;

	// pawn move
	if (patternMatch(input, "pawn")){
		int col = coordMap.at(input[0]) - 1;
		int drow = std::atoi(&input[1]) - 1;
		c = game.findPawnInColumn(col, drow);
		if (!c) return; // no such pawn that can make this move; invalid
		d = {col, drow};
		game.requestMove(c,d);
	
	
	// pawn capture (wip)
	

	// king move
	} else if (patternMatch(input, "king")){
		int dcol = coordMap.at(input[1]) - 1;
		int drow = std::atoi(&input[2]) - 1;
		c = game.findKing();
		d = {dcol, drow};
		game.requestMove(c,d);

		
	// bishop move
	} else if (patternMatch(input, "bishop")){
		int dcol = coordMap.at(input[1]) - 1;
		int drow = std::atoi(&input[2]) - 1;
		c = game.findBishop(dcol, drow);
		d = {dcol, drow};
		game.requestMove(c,d);

	
	} else {
		p("Invalid notation", true, 1);
	}

}


void commandLoop(GameInstance& game){
	bool GAME_EXIT = false;
	std::string input;

	while (!GAME_EXIT){
		CLEAROUT;
		game.printBoard(); // display chess board
		std::cout << "\n" << game.toMove << " to move :: ";
		std::getline(std::cin, input); // pull move input

		if (input == "ex"){
			GAME_EXIT = true; // break the loop
		} else if (input == "u"){ // undo last move
			game.undo();
		} else {
			parseMoveRequestInput(input, game); // check move
			if (game.gameOver){
				CLEAROUT;
				return;
			}
		}
	}
}


int main(){
	GameInstance game = GameInstance(8,8); // create an 8x8 board
	commandLoop(game);
	
	return 0;
}

