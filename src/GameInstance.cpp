#include "../inc/GameInstance.h"


GameInstance::GameInstance(int numCol, int numRow)
 	: mainstate({FlatMatrix<AbstractPiece>(numCol, numRow), "white", false, ""})
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
	for (int x = 0; x < mainstate.board.wide; x++){
		mainstate.board(x,1) = new Pawn("white");
		mainstate.board(x,6) = new Pawn("black");
	}


	// place King
	mainstate.board(4,0) = new King("white");
	mainstate.board(4,7) = new King("black");

	// place Queen
	mainstate.board(3,0) = new Queen("white");
	mainstate.board(3,7) = new Queen("black");
	
	// place Bishops
	mainstate.board(2,0) = new Bishop("white");
	mainstate.board(5,0) = new Bishop("white");
	mainstate.board(2,7) = new Bishop("black");
	mainstate.board(5,7) = new Bishop("black");
	
	// place Rooks
	mainstate.board(0,0) = new Rook("white");
	mainstate.board(7,0) = new Rook("white");
	mainstate.board(0,7) = new Rook("black");
	mainstate.board(7,7) = new Rook("black");
	
	// place Knights
	mainstate.board(1,0) = new Knight("white");
	mainstate.board(6,0) = new Knight("white");
	mainstate.board(1,7) = new Knight("black");
	mainstate.board(6,7) = new Knight("black");
}


void GameInstance::tick(){
	//
	// Represents a new turn in the game state
	// Currently only swaps the player but may do more in the future
	//
	mainstate.toMove = swapPlayer(mainstate.toMove);
}




std::string GameInstance::swapPlayer(std::string color){
	// Returns opposite player color
	return color == "white" ? "black" : "white";
}




void GameInstance::makeMove(Coord c, Coord d){
	//
	// This function is called after the move has been verified.
	// Alters the mainstate.board to reflect the move and pushes the previous state to the undo stack
	//
	undoStack.push(mainstate); // stores a copy of the current state on the undo stack
	redoStack = {}; // clear the redo stack; a the line was changed

	AbstractPiece* mover = mainstate.board(c.x, c.y);
	//AbstractPiece* capture = mainstate.board(d.x, d.y);
	mainstate.board.clear(d.x, d.y);
	mainstate.board(d.x, d.y) = mover;
	mainstate.board(c.x, c.y) = nullptr; // empty previous residing square

	HandleEnPassant(mover, c, d);
	handleCastle(mover, c, d);
	

	if(GameOver(mainstate.toMove)){
		mainstate.game_winner = mainstate.toMove;
		mainstate.game_over = true;
	}

	mover->moved = true;
	tick();
}


void GameInstance::HandleEnPassant(AbstractPiece* mover, Coord c, Coord d){
	// clear all en_passants first
	for (int x = 0; x < mainstate.board.size; ++x){
		Pawn* pawn = dynamic_cast<Pawn*>(mainstate.board[x]);
		if (pawn)
			pawn->en_passant = false;
	}

	// add en_passant if valid
	Pawn* pmover = dynamic_cast<Pawn*>(mover);
	if (pmover && abs(d.y - c.y) == 2){
		pmover->en_passant = true;
	}

	// check if an en passant move was made TODO
	
}


void GameInstance::handleCastle(AbstractPiece* mover, Coord c, Coord d){
	//
	// Checks if the latest move was a castle move and moves the caslted rook accordingly
	//
	int rook_position;
	if (dynamic_cast<King*>(mover) != nullptr && abs(c.x - d.x) == 2){ // if a King was moved two squares, then they castled
		if (c.x < d.x){ // kingside castle
			rook_position = mainstate.board.wide - 1;
		} else { // queenside castle
			rook_position = 0;
		}
		AbstractPiece* castled_rook = mainstate.board(rook_position, d.y);
		mainstate.board(d.x + 1 - (int)(c.x < d.x) * 2, d.y) = mainstate.board(rook_position, d.y); // move the rook
		mainstate.board(rook_position, d.y) = nullptr; // empty previous residing corner
	}
}



bool GameInstance::GameOver(std::string player_color){
	//
	// returns true if the giver player has checkmated their opponent
	//
	std::vector<Coord> all_attacked = GameInstance::allAttackedSquares(mainstate.board, player_color, 2);
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



void GameInstance::undo(){
	// Reverts to the last state at the top of the undoStack
	if (undoStack.empty()) // nothing to undo
		return;

	redoStack.push(mainstate);

	State prev_state = undoStack.top(); // get the top UndoState
	mainstate = prev_state;

	undoStack.pop(); // remove the top UndoState
}


void GameInstance::redo(){
	// Reverts to the last state at the top of the redoStack
	if (redoStack.empty()) // nothing to undo
		return;

	undoStack.push(mainstate);

	State later_state = redoStack.top(); // get the top UndoState
	mainstate = later_state;

	redoStack.pop(); // remove the top UndoState
}



void GameInstance::printBoard(){
	std::cout << mainstate.board;
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



