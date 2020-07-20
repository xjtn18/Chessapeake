#pragma once
#include "AbstractPiece.h"
#include "constants.h"
#include <string>

class Pawn : public AbstractPiece {
public:
	Pawn(int loc[2]);
	void move();
	void setLocation(int col, int row);

};

class King : public AbstractPiece {
public:
	King(int loc[2]);
	void move();
	void setLocation(int col, int row);

};

class Bishop : public AbstractPiece {
public:
	Bishop(int loc[2]);
	void move();
	void setLocation(int col, int row);

};

class Queen : public AbstractPiece {
public:
	Queen(int loc[2]);
	void move();
	void setLocation(int col, int row);

};

class Rook : public AbstractPiece {
public:
	Rook(int loc[2]);
	void move();
	void setLocation(int col, int row);

};

class Knight : public AbstractPiece {
public:
	Knight(int loc[2]);
	void move();
	void setLocation(int col, int row);

};



