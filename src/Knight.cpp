#include "../inc/Pieces.h"
#include "../inc/GameInstance.h"


Knight::Knight(std::string init_color) : AbstractPiece(init_color, 'N') { }

std::vector<Coord> Knight::getPlacements(FlatMatrix<AbstractPiece>& board, int col, int row, int depth){
	std::vector<Coord> placements;
	std::vector<Coord> directions = {{1,2}, {1,-2}, {-1,2}, {-1,-2}, {2,-1}, {2,1}, {-2,1}, {-2,-1}};
	AbstractPiece* square;
	int ccol, crow;
	for (auto e : directions){
		ccol = col + e.x;
		crow = row + e.y;
		if (!board.outBounds(ccol, crow)){
			square = board(ccol, crow);
			if (square == nullptr || square->color != this->color){
				placements.push_back({ccol, crow});
			}
		}
	}
			
	if (depth == 2){
		GameInstance::filterSuicide(board, placements, col, row, color);
	}
	return placements;
}



