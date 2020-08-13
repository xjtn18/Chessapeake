#pragma once
#include "FlatMatrix.h"
#include "Coord.h"
#include "Pieces.h"
#include "debug.h"
#include <algorithm>
#include <stack>
#include <fstream>


struct State {
	// contains the state of the game at any given moment
	FlatMatrix<AbstractPiece> board;
	std::string toMove;
	bool game_over;
	std::string game_winner;
};



class GameInstance {
	// Stores the model and gamestate of the Chess match

public:
	// state
	State mainstate;
	std::stack<State> undoStack;
	std::stack<State> redoStack;
	
	// methods
	GameInstance(int numCol, int numRow);
	GameInstance(const GameInstance& rhs);
	~GameInstance();
	void setupBoard();
	void printBoard();
	void makeMove(Coord c, Coord d);
	void tick();
	std::string swapPlayer(std::string color);
	void undo();
	void redo();
	void handleCastle(AbstractPiece* mover, Coord c, Coord d);
	void HandleEnPassant(AbstractPiece* mover, Coord c, Coord d);
	bool GameOver(std::string player_color);
	static void filterSuicide(FlatMatrix<AbstractPiece>& board, std::vector<Coord>& placements, std::string color);
	static void filterSuicide(FlatMatrix<AbstractPiece>& board, std::vector<Coord>& placements, int col, int row, std::string color);
	static std::vector<Coord> allAttackedSquares(FlatMatrix<AbstractPiece>& board, std::string defenderColor, int depth = 1);
	static Coord findKing(FlatMatrix<AbstractPiece>& board, std::string color);

};


