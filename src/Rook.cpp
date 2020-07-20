#include "inc/Pieces.h"
#include <string>
#include <iterator>

Rook::Rook(int loc[2]){
	currentLocation[0] = loc[0];
	currentLocation[1] = loc[2];
	symb='R';
}


void Rook::move(){
	p("hello");
}


void Rook::setLocation(int col, int row){
	currentLocation[0] = col;
	currentLocation[1] = row;
}



