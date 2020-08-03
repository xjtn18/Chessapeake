#pragma once
#include "constants.h"
#include "Coord.h"
#include "Pieces.h"
#include "helper.h"
#include <algorithm>
#include <stack>


struct UndoState {
	// stores that state needed to properly undo a move
	AbstractPiece* lastMoved = nullptr;
	bool hasMoved;
	AbstractPiece* captured = nullptr;
	Coord lastDepartureSquare;
	Coord lastArrivalSquare;
};



class GameInstance {

public:
	FlatMatrix<AbstractPiece> mainboard;
	int boardWidth = 8;
	int boardHeight = 8;
	std::string toMove = "white";
	bool gameOver = false;
	std::stack<UndoState> undoStack;

	GameInstance(int numCol, int numRow);
	~GameInstance();
	void setupBoard();
	void printBoard();
	void requestMove(Coord c, Coord d);
	void makeMove(Coord c, Coord d);
	void tick();
	void swapToMove();
	bool outBounds(int col, int row);
	void undo();
	Coord findPawn(int col, int row);
	Coord findKing();

	// templates must always be defined in headers
	template<typename T>
	Coord findPiece(int col, int row){
		Coord c = {-1,-1};
		Coord d = {col, row};
		AbstractPiece* piece;
		for (int x = 0; x < mainboard.wide; x++){
			for (int y = 0; y < mainboard.high; y++){
				piece = mainboard(x, y);
				if (dynamic_cast<T*>(piece) != nullptr && piece->color == this->toMove){ // if its the type piece we're looking for
					std::vector<Coord> v = piece->getPlacements(mainboard, x, y);
					if (std::find(v.begin(), v.end(), d) != v.end()){
						c = {x, y};
						break;
					}
				}
			}
		}
		if (!c)
			p("Invalid Move");
		return c;
	}

};


