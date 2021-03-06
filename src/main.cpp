#include "Pieces.h"
#include "Coord.h"
#include "MoveParser.h"
#include <stdlib.h>

// Change to 'CLS' instead of 'clear' this if you are running on windows without cygwin
#define kRefresh true
#define CLEAR_SHELL_COMMAND "clear"

void ClearShell(){
	if (kRefresh){
		system(CLEAR_SHELL_COMMAND);
	}
}

void PrintHelp(){
	ClearShell();
	std::cout << "Commands: \n\
u - undo \n\
r - redo \n\
exit - end program \n"
		<< std::endl;
	std::string _;
	std::getline(std::cin, _);
}


void commandLoop(GameInstance& game){
	bool GAME_EXIT = false;
	std::string input;

	while (!GAME_EXIT){
		ClearShell();
		game.PrintBoard(); // display chess board
		std::cout << "\n" << game.mainstate.toMove << " to move :: ";
		std::getline(std::cin, input); // pull move input

		if (input == "exit"){
			GAME_EXIT = true; // break the loop

		} else if (input == "u"){ // undo last move
			game.Undo();
		
		} else if (input == "r"){
			game.Redo();

		} else if (input == "f"){
			game.FlipBoardOrientation();

		} else if (input == "help"){
			PrintHelp();

		} else {
			ParseMoveRequest(input, game); // check move request
			// dangerous in scenario that game_over was set but game_winner was not
			if (game.mainstate.game_over){
				ClearShell();
				game.PrintBoard();
				std::cout << "\n" << game.mainstate.game_winner << " wins." << std::endl; // TODO: store how the player won as well (time/checkmate)
				buffer("");
				return;
			}
		}
	}
}


int main(){
	GameInstance game = GameInstance(8,8); // create an 8x8 board
	std::string filename = "../init_moves.txt";
	//readMoveList(filename, game); // set board position by making all moves listed in txt file
	commandLoop(game);
	
	return 0;
}



