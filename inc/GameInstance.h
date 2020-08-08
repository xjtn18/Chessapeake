#pragma once
#include "Coord.h"
#include "Pieces.h"
#include "helper.h"
#include <algorithm>
#include <stack>
#include <fstream>


namespace NotationInputManager{
	bool IsCapture(FlatMatrix<AbstractPiece>& board, Coord d);
	Coord FindPawn(FlatMatrix<AbstractPiece> board, Coord d, int pawn_col, std::string player);

	// templates must always be defined in headers
	template<typename T>
	Coord FindPiece(FlatMatrix<AbstractPiece> board, Coord d, std::string player, bool capture_requested){
		//
		// Finds the piece that can make the requested move.
		// Throws an error if no piece is found that can make such a move.
		//
		bool found = false;
		Coord c;
		AbstractPiece* piece;

		if (NotationInputManager::IsCapture(board, d) != capture_requested){ // check to make sure user specified 'takes' when they should have
			return c;
		}

		for (int x = 0; x < board.wide; x++){
			for (int y = 0; y < board.high; y++){
				piece = board(x, y);
				if (dynamic_cast<T*>(piece) != nullptr && piece->color == player){ // if its the type piece we're looking for
					std::vector<Coord> v = piece->getPlacements(board, x, y, 2);
					if (std::find(v.begin(), v.end(), d) != v.end()){
						c = {x, y};
						if (found){ // if we have already found another similar piece that can make this move
							std::cout << "Ambiguous" << std::endl;
							c = {-1,-1}; // set c to back to bad coordinate
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
	static Coord findKing(FlatMatrix<AbstractPiece> board, std::string color);



};


