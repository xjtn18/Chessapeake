#include "inc/GameInstance.h"
#include "inc/Pieces.h"

GameInstance::GameInstance(int numCol, int numRow)
 	: boardWidth(numCol), boardHeight(numRow), mainboard(FlatMatrix<AbstractPiece>(numCol, numRow))
{
	setupBoard();
}


void GameInstance::setupBoard(){
	// place Pawns
	for (int x = 0; x < boardWidth; x++){
		mainboard(x,1) = new Pawn("white");
		mainboard(x,6) = new Pawn("black");
	}


	// place King
	mainboard(4,0) = new King("white");
	mainboard(4,7) = new King("black");

	// place Queen
	mainboard(3,0) = new Queen("white");
	mainboard(3,7) = new Queen("black");
	
	// place Bishops
	mainboard(2,0) = new Bishop("white");
	mainboard(5,0) = new Bishop("white");
	mainboard(2,7) = new Bishop("black");
	mainboard(5,7) = new Bishop("black");
	
	// place Rooks
	mainboard(0,0) = new Rook("white");
	mainboard(7,0) = new Rook("white");
	mainboard(0,7) = new Rook("black");
	mainboard(7,7) = new Rook("black");
	
	// place Knights
	mainboard(1,0) = new Knight("white");
	mainboard(6,0) = new Knight("white");
	mainboard(1,7) = new Knight("black");
	mainboard(6,7) = new Knight("black");
}


void GameInstance::tick(){
	this->swapToMove();
}


void GameInstance::requestMove(Coord c, Coord d){
	// c being moved piece coordinates, d being destination coordinates
	AbstractPiece* movedPiece = mainboard(c.x, c.y);
	//p(movedPiece->color);
	std::vector<Coord> v = movedPiece->getPlacements(mainboard, c.x, c.y);
	//p(v);
	if (std::find(v.begin(), v.end(), d) != v.end()){
		mainboard(d.x, d.y) = movedPiece;
		mainboard(c.x, c.y) = nullptr; // empty previous residing square
		this->tick();
	} else {
		p("Invalid move");
	}
}


void GameInstance::swapToMove(){
	if (this->toMove == "white"){
		this->toMove = "black";
	} else {
		this->toMove = "white";
	}
}


void GameInstance::printBoard(){
	// Takes a width and a height
	int idx;
	int h = mainboard.high;
	for (int x = 0; x < mainboard.SIZE; x++){
		// get clockwise rotated index
		idx = (x % h + 1) * h - floor(x / h) - 1;

		if (mainboard[idx] != nullptr){
			std::cout << mainboard[idx]->symb << " ";
		} else {
			std::cout << ". ";
		}
		if (x % h == h-1)
			std::cout << "\n";
	}
}



Coord GameInstance::findPawnInColumn(int col, int drow){
	Coord c;
	Coord d = {col, drow};
	AbstractPiece* piece;
	for (int y = 0; y < mainboard.high; y++){
		piece = mainboard(col, y);
		if (dynamic_cast<Pawn*>(piece) != nullptr && piece->color == this->toMove){ // if its a Pawn
			std::vector<Coord> v = piece->getPlacements(mainboard, col, y);
			if (std::find(v.begin(), v.end(), d) != v.end()){
				c = {col, y};
				return c;
			}
		}
	}
	// didnt find pawn that could make this move; invalid
	//BAD_MOVE_FLAG = true;
	p("Invalid move");
	//this->gameOver = true;
	c = {-1,-1}; // dummy bad value
	return c;
}




