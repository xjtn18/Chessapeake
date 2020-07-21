#pragma once
#include <map>
#include <iostream>
#include <typeinfo>
#include <math.h>

// workflow helper functions

// this template prints anything (singular value)
template <typename T>
void p(T x){
	std::cout << x << std::endl;
}


// this template prints arrays
template <typename T>
void p(T* x, int len){
	for (int y = 0; y < len; y++){
		std::cout << x[y];
		if (y != len-1){ std::cout << ", ";}
	}
	std::cout << "\n";
}


//chess land helper functions/ class templates

// maps chess board letter notation to integers
const std::map<char, int> coordMap =
	{
		{'a',1},
		{'b',2},
		{'c',3},
		{'d',4},
		{'e',5},
		{'f',6},
		{'g',7},
		{'h',8}
	};


struct Coord {
	int x;
	int y;
};


template <class C>
class FlatMatrix {
public:
	C** mat;
	int high;
	int wide;
	int SIZE;

	FlatMatrix(int numCol, int numRow) : high(numRow), wide(numCol), mat(new C*[numCol * numRow]), SIZE(numCol * numRow){
		for (int x = 0; x < this->SIZE; x++){
			mat[x] = nullptr;
		}
	}

	C*& operator()(int col, int row){
		return mat[col * this->high + row];
	}

	C*& operator[](int ind){
		return mat[ind];
	}
};


