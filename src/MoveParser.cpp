#include "../inc/MoveParser.h"


bool patternMatch(std::string input, std::string piece_str){
	return std::regex_match(input, std::regex(piecePatterns.at(piece_str)));
}



void parseMoveRequest(std::string input, GameInstance& game){
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
		c = GameInstance::findKing(game.mainboard, game.toMove);
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


void readMoveList(std::string filename, GameInstance& game){
	std::fstream infile(filename);
	std::string input;
	while (infile >> input){
		parseMoveRequest(input, game);
	}
}



