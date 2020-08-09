#include "../inc/MoveParser.h"


bool IsCapture(FlatMatrix<AbstractPiece>& board, Coord d){
	return board(d.x, d.y) != nullptr;
}


Coord FindPawn(FlatMatrix<AbstractPiece>& board, Coord d, int pawn_col, std::string player){
	AbstractPiece* piece;
	Coord c;
	for (int y = 0; y < board.high; y++){
		piece = board(pawn_col, y);
		if (dynamic_cast<Pawn*>(piece) != nullptr && piece->color == player){ // if its the type piece we're looking for
			std::vector<Coord> v = piece->getPlacements(board, pawn_col, y, 2);
			if (std::find(v.begin(), v.end(), d) != v.end()){
				c = {pawn_col, y};
				break;
			}
		}
	}
	return c;
}


bool patternMatch(std::string input, std::string piece_str){
	return std::regex_match(input, std::regex(piecePatterns.at(piece_str)));
}


void parseMoveRequest(std::string input, GameInstance& game){
	Coord c, d;

	try {
		// pawn move
		if (patternMatch(input, "pawn")){
			CheckMove<Pawn>(input, game, c, d);
		
		// king move
		} else if (patternMatch(input, "king")){
			CheckMove<King>(input, game, c, d);

		// bishop move
		} else if (patternMatch(input, "bishop")){
			CheckMove<Bishop>(input, game, c, d);

		// knight move
		} else if (patternMatch(input, "knight")){
			CheckMove<Knight>(input, game, c, d);

		// rook move
		} else if (patternMatch(input, "rook")){
			CheckMove<Rook>(input, game, c, d);

		// queen move
		} else if (patternMatch(input, "queen")){
			CheckMove<Queen>(input, game, c, d);
		
		} else if (input == "O-O"){
			

		} else {
			p("Invalid notation", true, 1);
			return;
		}

		game.makeMove(c, d);

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



