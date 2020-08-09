#include "../inc/GameInstance.h"


GameInstance::GameInstance(int numCol, int numRow)
 	: boardWidth(numCol), boardHeight(numRow), mainboard(FlatMatrix<AbstractPiece>(numCol, numRow))
{
	setupBoard();
}


GameInstance::~GameInstance(){
}


void GameInstance::setupBoard(){
	//
	// Places all the pieces on to the board (TODO: only works with 8x8 board; need specific functions for select configs)
	//

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
	//
	// Represents a new turn in the game state
	// Currently only swaps the player but may do more in the future
	//
	this->toMove = swapPlayer(this->toMove);
}


std::string GameInstance::swapPlayer(std::string color){
	//
	// Returns opposite player color
	//
	return color == "white" ? "black" : "white";
}




void GameInstance::makeMove(Coord c, Coord d){
	//
	// This function is called after the move has been verified.
	// Alters the mainboard to reflect the move and pushes the previous state to the undo stack
	//
	State state;
	AbstractPiece* mover = mainboard(c.x, c.y);
	AbstractPiece* capture = mainboard(d.x, d.y);
	mainboard(d.x, d.y) = mover;
	mainboard(c.x, c.y) = nullptr; // empty previous residing square
	state.add(mover, capture, c, d);

	handleCastle(mover, capture, c, d, state);
	
	undoStack.push(state); // store state so it can be undone
	redoStack = {}; // clear the redo stack; a move was made in a previous position

	if(GameOver(this->toMove)){
		this->game_winner = this->toMove;
		this->game_over = true;
	}

	mover->moved = true;
	this->tick();
}



bool GameInstance::GameOver(std::string player_color){
	//
	// returns true if the giver player has checkmated their opponent
	//
	std::vector<Coord> all_attacked = GameInstance::allAttackedSquares(mainboard, player_color, 2);
	return all_attacked.empty();
}



void GameInstance::filterSuicide(FlatMatrix<AbstractPiece>& board, std::vector<Coord>& placements, int col, int row, std::string color){
	//
	// Disregard placements that put yourself in check (illegal).
	// Takes reference to placements vector and remove placements that put yourself in check
	//
	Coord d;
	for (int x = 0; x < placements.size(); x++){
		d = placements[x];
		AbstractPiece* mover = board(col, row);
		AbstractPiece* capture = board(d.x, d.y);
		board(d.x, d.y) = mover;
		board(col, row) = nullptr; // empty previous residing square
		Coord k = GameInstance::findKing(board, color);
		std::vector<Coord> all_attacked = GameInstance::allAttackedSquares(board, color, 1);
		if (std::find(all_attacked.begin(), all_attacked.end(), k) != all_attacked.end()){
			placements.erase(placements.begin() + x);
			x--;
		}
		board(d.x, d.y) = capture;
		board(col, row) = mover; // empty previous residing square
	}
}


// NOTE: you dont write 'static' in the cpp definition, only the header; static in .cpp means something DIFFERENT
std::vector<Coord> GameInstance::allAttackedSquares(FlatMatrix<AbstractPiece>& board, std::string defenderColor, int depth){
	//
	// Returns all the squares that are attacked by the defender's oppononent.
	//
	AbstractPiece* square;
	std::vector<Coord> allPlacements, currPlacements;
	for (int x = 0; x < board.wide; x++){
		for (int y = 0; y < board.high; y++){
			square = board(x,y);
			if (square != nullptr && square->color != defenderColor){
				currPlacements = square->getPlacements(board, x, y, depth);
				for (auto e : currPlacements)
					allPlacements.push_back(e);
			}
		}
	}
	return allPlacements;
}


void GameInstance::handleCastle(AbstractPiece* mover, AbstractPiece* capture, Coord c, Coord d, State& state){
	//
	// Checks if the latest move was a castle move and moves the caslted rook accordingly
	//
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
		state.add(castled_rook, nullptr, {rook_position, d.y}, {d.x + 1 - (int)(c.x < d.x) * 2, d.y});
	}
}



void GameInstance::undo(){
	//
	// Reverts to the last state at the top of the undoStack
	//
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
	//
	// Reverts to the last state at the top of the redoStack
	//
	if (this->redoStack.empty()) // nothing to undo
		return;

	State us = this->redoStack.top(); // get the top UndoState

	for (int i = 0; i < us.movers.size(); i++){
		mainboard(us.origins[i].x, us.origins[i].y) = nullptr;
		mainboard(us.landings[i].x, us.landings[i].y) = us.movers[i];
		us.movers[i]->moved = !us.hasMoved[i]; // set the piece's 'moved' boolean to what is was before the move was made
	}

	undoStack.push(us);
	this->redoStack.pop(); // remove the top UndoState
	this->tick(); // might need to make this a 'tick back' function in the future
}



void GameInstance::printBoard(){
	//
	// Displays the board in the terminal
	//
	int idx;
	int h = mainboard.high;
	for (int x = 0; x < mainboard.size; x++){
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

Coord GameInstance::findKing(FlatMatrix<AbstractPiece>& board, std::string color){
	//
	// Finds the King of the given color on the board.
	//
	Coord c;
	AbstractPiece* piece;
	for (int x = 0; x < board.size; x++){
		piece = board[x];
		if (dynamic_cast<King*>(piece) != nullptr && piece->color == color){ // if its the King we want
			c = board.rawIndexTo2D(x);
			break;
		}
	}
	return c;
}



