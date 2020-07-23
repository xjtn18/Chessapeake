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

	GameInstance(int numCol, int numRow);
	void setupBoard();
	void displayBoard();
	void printBoard();
	void requestMove(Coord c, Coord d);
	void tick();
	void swapToMove();
	Coord findPawnInColumn(int col, int row);

};


