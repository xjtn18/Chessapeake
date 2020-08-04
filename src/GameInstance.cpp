#include "../inc/GameInstance.h"


GameInstance::GameInstance(int numCol, int numRow)
 	: boardWidth(numCol), boardHeight(numRow), mainboard(FlatMatrix<AbstractPiece>(numCol, numRow))
{
	setupBoard();
}


GameInstance::GameInstance(const GameInstance& rhs)
	: mainboard(rhs.mainboard)
{ }


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
	this->toMove = swapPlayer(this->toMove);
}




void GameInstance::requestMove(Coord c, Coord d){
	// c being moved piece coordinates, d being destination coordinates
	std::vector<Coord> v = mainboard(c.x,c.y)->getPlacements(mainboard, c.x, c.y);
	if (std::find(v.begin(), v.end(), d) != v.end()){
		this->makeMove(c, d);
	} else {
		p("Invalid Move");
	}
}


void GameInstance::makeMove(Coord c, Coord d){
	State us;
	AbstractPiece* mover = mainboard(c.x, c.y);
	AbstractPiece* capture = mainboard(d.x, d.y);
	mainboard(d.x, d.y) = mover;
	mainboard(c.x, c.y) = nullptr; // empty previous residing square
	us.add(mover, capture, c, d);

	// check if castle move
	int rook_position;
	if (dynamic_cast<King*>(mover) != nullptr && abs(c.x - d.x) == 2){ // if a King was moved two squares, then they castled
		if (c.x < d.x){ // kingside castle
			rook_position = mainboard.wide - 1;
		} else { // queenside castle
			rook_position = 0;
		}
		AbstractPiece* castled_rook = mainboard(rook_position, d.y);
		mainboard(d.x + 1 - (int)(c.x < d.x) * 2, d.y) = mainboard(rook_position, d.y); // move the rook
		mainboard(rook_position, d.y) = nullptr; // empty previous residing corner
		us.add(castled_rook, nullptr, {rook_position, d.y}, {d.x + 1 - (int)(c.x < d.x) * 2, d.y});
	}

	
	// store state for undo stack
	undoStack.push(us);
	redoStack = {}; // clear the redo stack; a move was made in a previous position

	mover->moved = true;
	this->tick();
}


std::string GameInstance::swapPlayer(std::string color){
	if (color == "white"){
		return "black";
	} else {
		return "white";
	}
}


void GameInstance::undo(){
	if (this->undoStack.empty()) // nothing to undo
		return;

	State us = this->undoStack.top(); // get the top UndoState

	for (int i = 0; i < us.movers.size(); i++){
		mainboard(us.origins[i].x, us.origins[i].y) = us.movers[i];
		mainboard(us.landings[i].x, us.landings[i].y) = us.captures[i];
		us.movers[i]->moved = us.hasMoved[i]; // set the piece's 'moved' boolean to what is was before the move was made
	}

	redoStack.push(us);
	this->undoStack.pop(); // remove the top UndoState
	this->tick(); // might need to make this a 'tick back' function in the future
}


void GameInstance::redo(){
	if (this->redoStack.empty()) // nothing to undo
		return;

	State us = this->redoStack.top(); // get the top UndoState

	for (int i = 0; i < us.movers.size(); i++){
		mainboard(us.origins[i].x, us.origins[i].y) = us.captures[i];
		mainboard(us.landings[i].x, us.landings[i].y) = us.movers[i];
		us.movers[i]->moved = !us.hasMoved[i]; // set the piece's 'moved' boolean to what is was before the move was made
	}

	undoStack.push(us);
	this->redoStack.pop(); // remove the top UndoState
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



// NOTE: you dont write 'static' in the cpp definition, only the header; static in .cpp means something DIFFERENT
std::vector<Coord> GameInstance::allAttackedSquares(FlatMatrix<AbstractPiece>& board, std::string defenderColor){
	AbstractPiece* square;
	std::vector<Coord> allPlacements, currPlacements;
	for (int x = 0; x < board.wide; x++){
		for (int y = 0; y < board.high; y++){
			square = board(x,y);
			if (square != nullptr && square->color != defenderColor){
				currPlacements = square->getPlacements(board, x, y, 1);
				for (auto e : currPlacements)
					allPlacements.push_back(e);
			}
		}
	}
	return allPlacements;
}




