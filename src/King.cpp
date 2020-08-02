#include "../inc/Pieces.h"


King::King(std::string init_color) : AbstractPiece(init_color, 'K') { }



std::vector<Coord> King::getPlacements(FlatMatrix<AbstractPiece> board, int col, int row){
	std::vector<Coord> placements;
	Coord c;

	int prow = row + this->dir;

	std::vector<Coord> v = {{-1,-1}, {-1,1}, {1,-1}, {1,1}, {1,0}, {0,1}, {-1,0}, {0,-1}};
	for (auto e : v){
		c = {col + e.x, row + e.y};
		try {
			AbstractPiece* square = board(c.x,c.y);
			if (!board.outBounds(c.x,c.y) && (square == nullptr || square->color != this->color))
				placements.push_back(c);
		} catch (const std::out_of_range& oor){
			continue;
		}
	}
	
	return placements;
}


