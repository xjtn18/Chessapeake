#pragma once
#include "Coord.h"
#include "Pieces.h"
#include "helper.h"
#include <algorithm>
#include <stack>
#include <fstream>


namespace Check{
	bool IsCapture(FlatMatrix<AbstractPiece>& board, Coord d);
};


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
	void requestMove(Coord c, Coord d);
	void makeMove(Coord c, Coord d);
	void tick();
	std::string swapPlayer(std::string color);
	void undo();
	void redo();
	void handleCastle(AbstractPiece* mover, AbstractPiece* capture, Coord c, Coord d, State& state);
	bool GameOver(std::string player_color);
	static void filterSuicide(FlatMatrix<AbstractPiece> board, std::vector<Coord>& placements, std::string color);
	static void filterSuicide(FlatMatrix<AbstractPiece> board, std::vector<Coord>& placements, int col, int row, std::string color);
	static std::vector<Coord> allAttackedSquares(FlatMatrix<AbstractPiece>& board, std::string defenderColor, int depth = 1);
	Coord findPawn(int col, int row);
	static Coord findKing(FlatMatrix<AbstractPiece> board, std::string color);


	// templates must always be defined in headers
	template<typename T>
	Coord findPiece(int dcol, int drow, bool capture_requested, int pawn_col = -1){
		//
		// Finds the piece that can make the requested move.
		// Throws an error if no piece is found that can make such a move.
		//


		bool found = false;
		Coord c = {-1,-1};
		Coord d = {dcol, drow};
		if (Check::IsCapture(mainboard, d) != capture_requested){ // check to make sure user specified 'takes' when they should have
			return c;
		}
		AbstractPiece* piece;

		if (pawn_col != -1){
			for (int y = 0; y < mainboard.high; y++){
				piece = mainboard(pawn_col, y);
				if (piece != nullptr && piece->color == this->toMove){
					std::vector<Coord> v = piece->getPlacements(mainboard, pawn_col, y);
					if (std::find(v.begin(), v.end(), d) != v.end()){
						c = {pawn_col, y};
						break;
					}
				}
			}
			return c;
		}

		for (int x = 0; x < mainboard.wide; x++){
			for (int y = 0; y < mainboard.high; y++){
				piece = mainboard(x, y);
				if (dynamic_cast<T*>(piece) != nullptr && piece->color == this->toMove){ // if its the type piece we're looking for
					std::vector<Coord> v = piece->getPlacements(mainboard, x, y);
					if (std::find(v.begin(), v.end(), d) != v.end()){
						c = {x, y};
						if (found){ // if we have already found another similar piece that can make this move
							std::cout << "Ambiguous" << std::endl;
							c = {-1,-1}; // set c to bad
							return c;
						}
						found = true;
					}
				}
			}
		}
		return c;
	}

};


