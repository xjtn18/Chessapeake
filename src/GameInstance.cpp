#include "../inc/GameInstance.h"
#include "../inc/Pieces.h"

GameInstance::GameInstance(int numCol, int numRow)
 	: boardWidth(numCol), boardHeight(numRow), mainboard(FlatMatrix<AbstractPiece>(numCol, numRow))
{
	setupBoard();
}

GameInstance::~GameInstance(){
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
	std::vector<Coord> v = mainboard(c.x,c.y)->getPlacements(mainboard, c.x, c.y);
	if (std::find(v.begin(), v.end(), d) != v.end()){
		this->makeMove(c, d);
	} else {
		std::cout << "Invalid move" << std::endl;
	}

}


void GameInstance::makeMove(Coord c, Coord d){
	AbstractPiece* movedPiece = mainboard(c.x, c.y);
	AbstractPiece* captured = mainboard(d.x, d.y);
	mainboard(d.x, d.y) = movedPiece;
	mainboard(c.x, c.y) = nullptr; // empty previous residing square
	undoStack.push({movedPiece, movedPiece->moved, captured, c, d});
	movedPiece->moved = true;
	this->tick();
}


void GameInstance::swapToMove(){
	if (this->toMove == "white"){
		this->toMove = "black";
	} else {
		this->toMove = "white";
	}
}


void GameInstance::undo(){
	if (this->undoStack.empty()) // nothing to undo
		return;
	UndoState us = this->undoStack.top(); // get the top UndoState
	mainboard(us.lastDepartureSquare.x, us.lastDepartureSquare.y) = us.lastMoved;
	us.lastMoved->moved = us.hasMoved; // set the piece's 'moved' boolean to what is was before the move was made
	mainboard(us.lastArrivalSquare.x, us.lastArrivalSquare.y) = us.captured;
	this->undoStack.pop(); // remove the top UndoState
	this->tick(); // might need to make this a 'tick back' function in the future
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


bool GameInstance::outBounds(int col, int row){
	return col >= mainboard.wide ||
		col < 0 ||
		row >= mainboard.high ||
		row < 0;
}



Coord GameInstance::findPawn(int col, int row){
	Coord c = {-1,-1};
	Coord d = {col, row};
	AbstractPiece* piece;
	for (int y = 0; y < mainboard.high; y++){
		piece = mainboard(col, y);
		if (dynamic_cast<Pawn*>(piece) != nullptr && piece->color == this->toMove){ // if its a Pawn
			std::vector<Coord> v = piece->getPlacements(mainboard, col, y);
			if (std::find(v.begin(), v.end(), d) != v.end()){
				c = {col, y};
				break;
			}
		}
	}
	// didnt find pawn that could make this move; invalid
	if (!c)
		p("Invalid Move");
	return c;
}


Coord GameInstance::findKing(){
	Coord c = {-1,-1};
	AbstractPiece* piece;
	for (int x = 0; x < mainboard.SIZE; x++){
		piece = mainboard[x];
		if (dynamic_cast<King*>(piece) != nullptr && piece->color == this->toMove){ // if its the King we want
			c = mainboard.rawIndexTo2D(x);
			break;
		}
	}
	return c;
}






