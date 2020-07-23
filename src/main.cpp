#include "inc/Pieces.h"
#include "inc/constants.h"
#include "inc/GameInstance.h"
#include "inc/Coord.h"
#include <iostream>
#include <string>
#include <regex>
#include <stdlib.h>

#define CLEAROUT system("clear")

// Uncomment this if you are running on windows
// #define CLEAROUT system("CLS")


// this doesnt work
/*
#ifdef __unix
#define CLEAROUT system("clear")
#endif

#ifdef _WIN32
#include <process.h>
#define CLEAROUT system("CLS")
#endif
*/



Coord chessNotationToCoord(std::string notation){
	Coord c;
	c.x = coordMap.at(notation[0]) - 1;
	c.y = std::atoi(&notation[1]) - 1;
	return c;
}


void parseMoveRequestInput(std::string input, GameInstance& game){
	Coord c, d;

	// pawn move
	if (std::regex_match(input, std::regex("[a-h][1-8]"))){
		int col = coordMap.at(input[0]) - 1;
		int drow = std::atoi(&input[1]) - 1;
		c = game.findPawnInColumn(col, drow);
		if (!c) return; // no such pawn that can make this move; invalid
		d = {col, drow};
		game.requestMove(c,d);
	
	
	// pawn capture

	
	} else if (input == "exit"){
		return;

	} else {
		p("Invalid move");
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

		if (input == "exit")
			GAME_EXIT = true; // break the loop

		parseMoveRequestInput(input, game); // check move
		if (game.gameOver){
			CLEAROUT;
			return;
		}
	}
}


int main(){
	GameInstance game = GameInstance(8,8);
	commandLoop(game);
	
	return 0;
}


