#pragma once
#include <chrono>
#include <thread>
#include <vector>
#include "Coord.h"
#include <map>
#include <iostream>
#include <math.h>
#include <stdexcept>

void p(std::vector<Coord> v);
void sleep(int sleeptime);


// ##################
// workflow helper functions
// ##################


#define PRINT_DEBUG 1 // set this to 0 if you dont want to see any of your debug prints


// this template prints anything (singular value)
template <typename T>
void p(T x, bool nl = true, int sleeptime = 1){
	if (!PRINT_DEBUG)
		return;
	std::cout << x;
	if (nl)
		std::cout << "\n";
	sleep(sleeptime);
}


// this template prints arrays
template <typename T>
void p(T* x, int len){
	for (int y = 0; y < len; y++){
		p(x[y], false);
		if (y != len-1){
			p(", ", false);
		}
	}
	p("");

}

// this template prints vectors
template <typename T>
void p(std::vector<T> v){
	if (v.empty())
		p("VECTOR EMPTY");
		return;
	for (auto e : v)
		p(e, false);
		p(" - ", false);
	p("");
}


template <typename T>
void buffer(T input){
	std::cout << input << std::endl;
	std::string _;
	std::getline(std::cin, _);
}


// ##################
//chess land helper functions/ class templates
// ##################


const std::map<std::string, int> whiteBottom =
	{
		{"white", 1},
		{"black", -1}
	};

const std::map<std::string, int> blackBottom =
	{
		{"white", -1},
		{"black", 1}
	};

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




template <class C>
class FlatMatrix {
public:
	C** mat;
	int high;
	int wide;
	int SIZE;

	FlatMatrix(int numCol, int numRow)
		: high(numRow), wide(numCol), mat(new C*[numCol * numRow]), SIZE(numCol * numRow)
	{}


	FlatMatrix(FlatMatrix& rhs)
		: high(rhs.high), wide(rhs.wide), mat(new C*[rhs.wide * rhs.high]), SIZE(rhs.wide * rhs.high)
	{
		for (int x = 0; x < rhs.SIZE; x++){
			//p("stackdumper");
			mat[x] = rhs[x];
		}
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
		if (ind >= 0 && ind < this->SIZE)
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
		// ^^^ program doesnt like this for some reason, probably because its an array of pointers
	}


};
