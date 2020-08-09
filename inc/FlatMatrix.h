#pragma once
#include "Coord.h"
#include <math.h>
#include <stdexcept>

template <class C>
class FlatMatrix {
	//
	// Represents a 1-dimensional array with a 2D interface
	//
public:
	C** mat;
	int high; // hieght of the array in 2d
	int wide; // width of the array in 2d
	int size; // raw length of the array

	FlatMatrix(int numCol, int numRow)
		: high(numRow), wide(numCol), mat(new C*[numCol * numRow]), size(numCol * numRow)
	{
		// fill with nullptrs;
		for (int x = 0; x < this->size; x++){
			mat[x] = nullptr;
		}
	}

	FlatMatrix(FlatMatrix& rhs)
		: high(rhs.high), wide(rhs.wide), mat(new C*[rhs.wide * rhs.high]), size(rhs.wide * rhs.high)
	{
		/*
		for (int x = 0; x < this->size; x++){
			mat[x] = nullptr;
			C*
			if (rhs[x] != nullptr){
				*(mat[x]) = *(rhs[x]);
			}
		}
		*/
	}

	C*& operator()(int col, int row){
		// Use THIS to index the matrix, as if it were a normal 2D matrix
		// Same idea applies, first index is the x axis (column) and second index is the y axis (row)
		if (!this->outBounds(col, row))
			return mat[col * this->high + row];
		throw std::out_of_range("Bad board index");
	}

	C*& operator[](int ind){
		// Use this if you have a raw index into the 1D array; will probably rarely be used if ever.
		if (ind >= 0 && ind < this->size)
			return mat[ind];
		throw std::out_of_range("Bad board index");
	}

	bool outBounds(int col, int row){
		return col >= this->wide ||
			col < 0 ||
			row >= this->high ||
			row < 0;
	}

	Coord rawIndexTo2D(int idx){
		return {int(floor(idx / this->high)), idx % this->high};
	}

	~FlatMatrix(){
		//delete[] mat;
		///*
		for (int i = 0; i < this->size; i++){
			delete mat[i]; // delete the heap elements
		}
		delete[] mat; // delete the heap board
		//*/
	}

};


