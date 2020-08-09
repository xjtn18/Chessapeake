#pragma once
#include "FlatMatrix.h"
#include "Coord.h"
#include "debug.h"
#include <map>
#include <iterator>
#include <vector>


const std::map<std::string, int> kOrientMap =
	{
		{"white", 1},
		{"black", -1}
	};


class AbstractPiece {
	public:
		bool moved = false; // bool representing if the piece has been moved or not
		char symb; // the symbol used to represent this piece in the shell
		std::string color;
		int dir; // direction in which the pawns of this colored piece are attacking

		virtual std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece>& board, int col, int row, int depth = 1) = 0;
		//virtual ~AbstractPiece(){};

	protected:
		AbstractPiece(std::string init_color, char symbol = '?') : color(init_color), dir(kOrientMap.at(init_color)), symb(symbol) { }

};


class Pawn : public AbstractPiece {
public:
	Pawn(std::string init_color);
	std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece>& board, int col, int row, int depth = 1);

};


class King : public AbstractPiece {
public:
	King(std::string init_color);
	std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece>& board, int col, int row, int depth = 1);
	void checkCastling(FlatMatrix<AbstractPiece>& board, int col, int row, std::vector<Coord>& placements);

};

class Bishop : public AbstractPiece {
public:
	Bishop(std::string init_color);
	std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece>& board, int col, int row, int depth = 1);

};


class Queen : public AbstractPiece {
public:
	Queen(std::string init_color);
	std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece>& board, int col, int row, int depth = 1);

};


class Rook : public AbstractPiece {
public:
	Rook(std::string init_color);
	std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece>& board, int col, int row, int depth = 1);

};


class Knight : public AbstractPiece {
public:
	Knight(std::string init_color);
	std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece>& board, int col, int row, int depth = 1);

};



