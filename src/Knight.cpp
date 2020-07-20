#include "inc/Pieces.h"
#include <string>
#include <iterator>

Knight::Knight(int loc[2]){
	currentLocation[0] = loc[0];
	currentLocation[1] = loc[2];
	symb='N';
}


void Knight::move(){
	p("hello");
}


void Knight::setLocation(int col, int row){
	currentLocation[0] = col;
	currentLocation[1] = row;
}



