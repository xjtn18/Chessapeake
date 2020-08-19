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


const std::map<std::string, std::map<std::string, char>> kSymbolMap = 
{
	{"white", 
		{
			{"pawn", 'P'},
			{"rook", 'R'},
			{"knight", 'N'},
			{"queen", 'Q'},
			{"king", 'K'},
			{"bishop", 'B'}
		}
	},
	{"black",
		{
			{"pawn", 'p'},
			{"rook", 'r'},
			{"knight", 'n'},
			{"queen", 'q'},
			{"king", 'k'},
			{"bishop", 'b'}
		}
	}
};
			

class AbstractPiece {
	public:
		bool moved = false; // bool representing if the piece has been moved or not
		char symb; // the symbol used to represent this piece in the shell
		std::string color;
		int dir; // direction in which the pawns of this colored piece are attacking

		virtual std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece>& board, int col, int row, int depth = 1) = 0;
		virtual AbstractPiece* clone() const = 0;
		virtual ~AbstractPiece(){}

	protected:
		AbstractPiece(std::string init_color, char symbol = '?') : color(init_color), dir(kOrientMap.at(init_color)), symb(symbol) { }

};


class Pawn : public AbstractPiece {
public:
	bool en_passant = false;
	Pawn(std::string init_color);
	std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece>& board, int col, int row, int depth = 1);
	void CheckEnPassant(FlatMatrix<AbstractPiece>& board, std::vector<Coord>& placements, int col, int row);
	AbstractPiece* clone() const {
		return new Pawn(*this);
	}

};


class King : public AbstractPiece {
public:
	King(std::string init_color);
	std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece>& board, int col, int row, int depth = 1);
	void CheckCastling(FlatMatrix<AbstractPiece>& board, int col, int row, std::vector<Coord>& placements);
	AbstractPiece* clone() const {
		return new King(*this);
	}

};

class Bishop : public AbstractPiece {
public:
	Bishop(std::string init_color);
	std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece>& board, int col, int row, int depth = 1);
	AbstractPiece* clone() const {
		return new Bishop(*this);
	}

};


class Queen : public AbstractPiece {
public:
	Queen(std::string init_color);
	std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece>& board, int col, int row, int depth = 1);
	AbstractPiece* clone() const {
		return new Queen(*this);
	}

};


class Rook : public AbstractPiece {
public:
	Rook(std::string init_color);
	std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece>& board, int col, int row, int depth = 1);
	AbstractPiece* clone() const {
		return new Rook(*this);
	}

};


class Knight : public AbstractPiece {
public:
	Knight(std::string init_color);
	std::vector<Coord> getPlacements(FlatMatrix<AbstractPiece>& board, int col, int row, int depth = 1);
	AbstractPiece* clone() const {
		return new Knight(*this);
	}

};



