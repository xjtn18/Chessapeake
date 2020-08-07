#include "../inc/MoveParser.h"


bool patternMatch(std::string input, std::string piece_str){
	return std::regex_match(input, std::regex(piecePatterns.at(piece_str)));
}



void parseMoveRequest(std::string input, GameInstance& game){
	Coord c = {-1,-1}, d = {-1,-1};

	try {
		// pawn move
		if (patternMatch(input, "pawn")){
			//int dcol = coordMap.at(input[0]) - 1;
			//int drow = std::atoi(&input[1]) - 1;
			//c = game.findPawn(dcol, drow);
			//if (!c) return; // no such pawn that can make this move; invalid
			//game.requestMove(c,{dcol, drow}, capture_requested);
			//return;
			getCurrentAndDestination<Pawn>(input, game, c, d);
		
		// king move
		} else if (patternMatch(input, "king")){
			//int dcol = coordMap.at(input[1]) - 1;
			//int drow = std::atoi(&input[2]) - 1;
			//c = GameInstance::findKing(game.mainboard, game.toMove);
			//game.requestMove(c,{dcol,drow}, capture_requested);
			//return;
			getCurrentAndDestination<King>(input, game, c, d);

		// bishop move
		} else if (patternMatch(input, "bishop")){
			getCurrentAndDestination<Bishop>(input, game, c, d);

		// knight move
		} else if (patternMatch(input, "knight")){
			getCurrentAndDestination<Knight>(input, game, c, d);

		// rook move
		} else if (patternMatch(input, "rook")){
			getCurrentAndDestination<Rook>(input, game, c, d);

		// queen move
		} else if (patternMatch(input, "queen")){
			getCurrentAndDestination<Queen>(input, game, c, d);
		
		} else if (input == "O-O"){
			

		} else {
			p("Invalid notation", true, 1);
			return;
		}

		game.requestMove(c, d);

	} catch (InvalidMove& ex){
		p("Invalid Move");
	}
	

}


void readMoveList(std::string filename, GameInstance& game){
	std::fstream infile(filename);
	std::string input;
	while (infile >> input){
		parseMoveRequest(input, game);
	}
}



