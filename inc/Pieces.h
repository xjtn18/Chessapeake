#pragma once
#include <iterator>
#include <vector>
#include "constants.h"
#include "Coord.h"


class AbstractPiece {
	public:
		bool moved = false;
		char symb;
		std::string color;
		int dir;

		virtual std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece> board, int col, int row) = 0;
		virtual ~AbstractPiece(){};

	protected:
		AbstractPiece(std::string init_color, char symbol = '?') : color(init_color), dir(whiteBottom.at(init_color)), symb(symbol) { }

};


class Pawn : public AbstractPiece {
public:
	using AbstractPiece::AbstractPiece;
	Pawn(std::string init_color);
	std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece> board, int col, int row);

};


class King : public AbstractPiece {
public:
	using AbstractPiece::AbstractPiece;
	King(std::string init_color);
	std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece> board, int col, int row);

};

class Bishop : public AbstractPiece {
public:
	Bishop(std::string init_color);
	std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece> board, int col, int row);

};


class Queen : public AbstractPiece {
public:
	using AbstractPiece::AbstractPiece;
	Queen(std::string init_color);
	std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece> board, int col, int row);

};


class Rook : public AbstractPiece {
public:
	using AbstractPiece::AbstractPiece;
	Rook(std::string init_color);
	std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece> board, int col, int row);

};


class Knight : public AbstractPiece {
public:
	using AbstractPiece::AbstractPiece;
	Knight(std::string init_color);
	std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece> board, int col, int row);

};



