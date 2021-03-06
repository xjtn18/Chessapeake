#include "Pieces.h"
#include "GameInstance.h"



King::King(std::string init_color) : AbstractPiece(init_color, kSymbolMap.at(init_color).at("king")) { }


std::vector<Coord> King::getPlacements(FlatMatrix<AbstractPiece>& board, int col, int row, int depth){
	std::vector<Coord> placements;
	Coord c;

	int prow = row + this->dir;

	std::vector<Coord> v = {{-1,-1}, {-1,1}, {1,-1}, {1,1}, {1,0}, {0,1}, {-1,0}, {0,-1}};
	for (auto e : v){
		c = {col + e.x, row + e.y};
		try {
			AbstractPiece* square = board(c.x,c.y);
			if (square == nullptr || square->color != this->color)
				placements.push_back(c);
		} catch (const std::out_of_range& oor){
			continue;
		}
	}
	
	if (depth == 2){
		this->CheckCastling(board, col, row, placements); // will add castling priviliges if valid
		GameInstance::FilterSuicide(board, placements, col, row, color);
	}
	
	return placements;
}


void King::CheckCastling(FlatMatrix<AbstractPiece>& board, int col, int row, std::vector<Coord>& placements){
	std::vector<Coord> passingSquares;
	std::vector<Coord> allAttacked = GameInstance::AllAttackedSquares(board, this->color, 1);
	Coord c = {col, row}; // current king position
	if (this->moved || std::find(allAttacked.begin(), allAttacked.end(), c) != allAttacked.end()) // if in check or has moved
		return;

	// King side castle
	passingSquares = {{col + 1, row}, {col + 2, row}};
	AbstractPiece* kingsideRook = board(board.wide-1, row); // assuming rook is on the edge
	bool passingSafe = true;
	if (kingsideRook != nullptr && !kingsideRook->moved){
		// check passing squares
		for ( auto ps : passingSquares){
			if (board(ps.x, ps.y) != nullptr || std::find(allAttacked.begin(), allAttacked.end(), ps) != allAttacked.end()){
				passingSafe = false;
				break;
			}
		}
		if (passingSafe)
			placements.push_back({col + 2, row});
	}

	// Queen side castle
	passingSquares = {{col - 1, row}, {col - 2, row}};
	AbstractPiece* queensideRook = board(0, row); // assuming rook is on the edge
	passingSafe = true;
	if (queensideRook != nullptr && !queensideRook->moved){
		// check passing squares
		for ( auto p : passingSquares){
			if (board(p.x, p.y) != nullptr || std::find(allAttacked.begin(), allAttacked.end(), p) != allAttacked.end()){
				passingSafe = false;
				break;
			}
		}
		if (passingSafe)
			placements.push_back({col - 2, row});
	}
}


