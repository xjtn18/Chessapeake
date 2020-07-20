#include "inc/Pieces.h"
#include <string>
#include <iterator>

Pawn::Pawn(int loc[2]){
	currentLocation[0] = loc[0];
	currentLocation[1] = loc[2];
	symb='P';
}


void Pawn::move(){
	p("hello");
}


void Pawn::setLocation(int col, int row){
	currentLocation[0] = col;
	currentLocation[1] = row;
}



