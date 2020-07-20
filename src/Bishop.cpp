#include "inc/Pieces.h"
#include <string>
#include <iterator>

Bishop::Bishop(int loc[2]){
	currentLocation[0] = loc[0];
	currentLocation[1] = loc[2];
	symb='B';
}


void Bishop::move(){
	p("hello");
}


void Bishop::setLocation(int col, int row){
	currentLocation[0] = col;
	currentLocation[1] = row;
}



