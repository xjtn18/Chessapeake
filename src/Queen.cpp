#include "inc/Pieces.h"
#include <string>
#include <iterator>

Queen::Queen(int loc[2]){
	currentLocation[0] = loc[0];
	currentLocation[1] = loc[2];
	symb='Q';
}


void Queen::move(){
	p("hello");
}


void Queen::setLocation(int col, int row){
	currentLocation[0] = col;
	currentLocation[1] = row;
}



