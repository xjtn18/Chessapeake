#pragma once
#include "inc/AbstractPiece.h"
#include "inc/constants.h"

class GameInstance {

	FlatMatrix<AbstractPiece> mainboard;

public:
	int boardWidth = 8;
	int boardHeight = 8;

	GameInstance(int numCol, int numRow);
	void setupBoard();
	void displayBoard();
	void printBoard();

};
