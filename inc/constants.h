#pragma once
#include <map>
#include <iostream>
#include <typeinfo>

// workflow helper functions

// this template prints anything (best if singular value)
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
class Matrix {
public:
	C** mat;
	int high;
	int wide;
	int size;

	Matrix(int numCol, int numRow) : high(numRow), wide(numCol), mat(new C*[numCol * numRow]), size(numCol * numRow){
		for (int x = 0; x < this->size; x++){
			mat[x] = nullptr;
		}
	}

	C*& operator()(int col, int row){
		return mat[col * this->high + row];

	}
};



template <typename T>
void printMatrix(int w, int h, T* matrix){
	// Takes a width and a height
	int x;
	for (int y = 0; y < (w * h); y++){
		x = y;
		if (matrix[x] != nullptr){
			std::cout << matrix[x]->symb << " ";
		} else {
			std::cout << ". ";
		}
		if (y % h == h-1)
			std::cout << "\n";
	}
}

