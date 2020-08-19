#include "../inc/Pieces.h"
#include "../inc/GameInstance.h"


Pawn::Pawn(std::string init_color) : AbstractPiece(init_color, kSymbolMap.at(init_color).at("pawn")){ }


std::vector<Coord> Pawn::getPlacements(FlatMatrix<AbstractPiece>& board, int col, int row, int depth){
	std::vector<Coord> placements;
	Coord c;

	int prow = row + this->dir;
	int range = row + ((1 + (int)(!this->moved)) * this->dir); //equates to 2 if the pawn has not been moved
	while (prow < board.high && prow >= 0 && board(col, prow) == nullptr && prow != range + this->dir){
		if (board(col, prow) == nullptr){
			c = {col, prow};
			placements.push_back(c);
		}
		prow = prow + this->dir;
	}
	
	//attack placements
	try {
		AbstractPiece* attackSquareLeft = board(col+1,row + this->dir);
		if (attackSquareLeft != nullptr && attackSquareLeft->color != this->color){
			c = {col + 1, row + this->dir};
			placements.push_back(c);
		}
	} catch (const std::out_of_range& oor) {}

	try {
		AbstractPiece* attackSquareRight = board(col-1,row + this->dir);
		if (attackSquareRight != nullptr && attackSquareRight->color != this->color){
			c = {col - 1, row + this->dir};
			placements.push_back(c);
		}
	} catch (const std::out_of_range& oor){}



	if (depth == 2){
		this->CheckEnPassant(board, placements, col, row);
		GameInstance::FilterSuicide(board, placements, col, row, color);
	}

	return placements;
}


void Pawn::CheckEnPassant(FlatMatrix<AbstractPiece>& board, std::vector<Coord>& placements, int col, int row){
	AbstractPiece* neighbor;
	int sides[2] = {1, -1};
	for (int i = 0; i < 2; ++i){
		try {
			neighbor = board(col+sides[i], row);
		} catch (const std::out_of_range& oor){
			continue;
		}
		Pawn* pneighbor = dynamic_cast<Pawn*>(neighbor);
		if (pneighbor && pneighbor->en_passant && pneighbor->color != this->color){
			placements.push_back({col + sides[i], row + this->dir});
		}
	}
}


