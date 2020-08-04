#pragma once
#include "Coord.h"
#include "Pieces.h"
#include "helper.h"
#include <algorithm>
#include <stack>
#include <fstream>


struct State {
	// stores the state needed to properly undo a move
	std::vector<AbstractPiece*> movers;
	std::vector<AbstractPiece*> captures;
	std::vector<bool> hasMoved;
	std::vector<Coord> origins;
	std::vector<Coord> landings;

	void add(AbstractPiece* mover, AbstractPiece* capture, Coord c, Coord d){
		// add the pieces that moved during this state (needs to be vectors to accomodate for castling)
		movers.push_back(mover);
		captures.push_back(capture);
		hasMoved.push_back(mover->moved);
		origins.push_back(c);
		landings.push_back(d);
	}
};



class GameInstance {

public:
	FlatMatrix<AbstractPiece> mainboard;
	int boardWidth = 8;
	int boardHeight = 8;
	std::string toMove = "white";
	bool gameOver = false;
	std::stack<State> undoStack;
	std::stack<State> redoStack;

	GameInstance(int numCol, int numRow);
	GameInstance(const GameInstance& rhs);
	~GameInstance();
	void setupBoard();
	void printBoard();
	void requestMove(Coord c, Coord d);
	void makeMove(Coord c, Coord d);
	void tick();
	std::string swapPlayer(std::string color);
	void undo();
	void redo();
	static std::vector<Coord> allAttackedSquares(FlatMatrix<AbstractPiece>& board, std::string defenderColor);
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


