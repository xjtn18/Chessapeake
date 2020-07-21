#include "inc/constants.h"
#include "inc/GameInstance.h"
#include "inc/Pieces.h"
#include "inc/AbstractPiece.h"

GameInstance::GameInstance(int numCol, int numRow)
 	: boardWidth(numCol), boardHeight(numRow), mainboard(FlatMatrix<AbstractPiece>(numCol, numRow))
{
	setupBoard();
}


void GameInstance::setupBoard(){
	// place Pawns
	for (int x = 0; x < boardWidth; x++){
		int pawnBottom[2]{x, 1};
		int pawnTop[2]{x, 6};
		mainboard(x,1) = new Pawn(pawnBottom);
		mainboard(x,6) = new Pawn(pawnTop);
	}

	// place King
	int kingBottom[2]{0, 1};
	int kingTop[2]{0, 6};
	mainboard(4,0) = new King(kingBottom);
	mainboard(4,7) = new King(kingTop);

	// place Queen
	mainboard(3,0) = new Queen(kingBottom);
	mainboard(3,7) = new Queen(kingTop);
	
	// place Bishops
	mainboard(2,0) = new Bishop(kingBottom);
	mainboard(5,0) = new Bishop(kingTop);
	mainboard(2,7) = new Bishop(kingBottom);
	mainboard(5,7) = new Bishop(kingTop);
	
	// place Rooks
	mainboard(0,0) = new Rook(kingBottom);
	mainboard(7,0) = new Rook(kingTop);
	mainboard(0,7) = new Rook(kingBottom);
	mainboard(7,7) = new Rook(kingTop);
	
	// place Knights
	mainboard(1,0) = new Knight(kingBottom);
	mainboard(6,0) = new Knight(kingTop);
	mainboard(1,7) = new Knight(kingBottom);
	mainboard(6,7) = new Knight(kingTop);
}



void GameInstance::printBoard(){
	// Takes a width and a height
	int rotatedIndex;
	for (int x = 0; x < (mainboard.SIZE); x++){
		// rotate the 1D matrix 90 degrees cc
		rotatedIndex = mainboard.SIZE - ((x % mainboard.high + 1) * mainboard.high) + floor(x / mainboard.high);

		if (mainboard[rotatedIndex] != nullptr){
			std::cout << mainboard[rotatedIndex]->symb << " ";
		} else {
			std::cout << ". ";
		}
		if (x % mainboard.high == mainboard.high-1)
			std::cout << "\n";
	}
}
