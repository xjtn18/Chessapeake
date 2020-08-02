#pragma once
#include "constants.h"
#include "Coord.h"
#include "Pieces.h"
#include "helper.h"
#include <algorithm>

class GameInstance {


public:
	FlatMatrix<AbstractPiece> mainboard;
	int boardWidth = 8;
	int boardHeight = 8;
	std::string toMove = "white";
	bool gameOver = false;
	AbstractPiece* lastMoved = nullptr;
	Coord lastDepartureSquare, lastArrivalSquare;

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
	Coord findPawnInColumn(int col, int row);
	Coord findKing();
	Coord findBishop(int col, int row);

};


