#include "../inc/Pieces.h"
#include "../inc/constants.h"
#include "../inc/GameInstance.h"
#include "../inc/Coord.h"
#include "../inc/move.h"
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
		int dcol = coordMap.at(input[0]) - 1;
		int drow = std::atoi(&input[1]) - 1;
		c = game.findPawn(dcol, drow);
		if (!c) return; // no such pawn that can make this move; invalid
		game.requestMove(c,{dcol, drow});
	
	// pawn capture (wip)
	

	// king move
	} else if (patternMatch(input, "king")){
		int dcol = coordMap.at(input[1]) - 1;
		int drow = std::atoi(&input[2]) - 1;
		c = game.findKing();
		game.requestMove(c,{dcol,drow});

	// bishop move
	} else if (patternMatch(input, "bishop")){
		getCurrentAndDestination<Bishop>(input, game);

	// knight move
	} else if (patternMatch(input, "knight")){
		getCurrentAndDestination<Knight>(input, game);

	// rook move
	} else if (patternMatch(input, "rook")){
		getCurrentAndDestination<Rook>(input, game);

	// queen move
	} else if (patternMatch(input, "queen")){
		getCurrentAndDestination<Queen>(input, game);
	
	} else if (input == "O-O"){
		

	} else {
		p("Improper notation", true, 1);
		return;
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

		if (input == "exit"){
			GAME_EXIT = true; // break the loop

		} else if (input == "u"){ // undo last move
			game.undo();

		} else {
			parseMoveRequestInput(input, game); // check move request
			if (game.gameOver){
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



