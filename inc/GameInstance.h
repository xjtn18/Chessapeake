#pragma once
#include "FlatMatrix.h"
#include "Coord.h"
#include "Pieces.h"
#include "debug.h"
#include <algorithm>
#include <stack>
#include <fstream>



struct State {
	// stores the all of the state information needed to properly undo/redo a move
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
	// Stores the model and gamestate of the Chess match

public:
	FlatMatrix<AbstractPiece> mainboard;
	int boardWidth = 8;
	int boardHeight = 8;
	std::string toMove = "white";
	bool game_over = false;
	std::string game_winner = "";
	std::stack<State> undoStack;
	std::stack<State> redoStack;

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
	void handleCastle(AbstractPiece* mover, AbstractPiece* capture, Coord c, Coord d, State& state);
	bool GameOver(std::string player_color);
	static void filterSuicide(FlatMatrix<AbstractPiece>& board, std::vector<Coord>& placements, std::string color);
	static void filterSuicide(FlatMatrix<AbstractPiece>& board, std::vector<Coord>& placements, int col, int row, std::string color);
	static std::vector<Coord> allAttackedSquares(FlatMatrix<AbstractPiece>& board, std::string defenderColor, int depth = 1);
	static Coord findKing(FlatMatrix<AbstractPiece>& board, std::string color);



};


