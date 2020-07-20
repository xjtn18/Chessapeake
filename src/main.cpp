#include "inc/Pieces.h"
#include <iostream>
#include <string>
#include "inc/constants.h"
#include "inc/GameInstance.h"


Coord chessNotationToCoord(std::string notate){
	Coord c;
	c.x = coordMap.at(notate[0]) - 1;
	c.y = std::atoi(&notate[1]) - 1;
	return c;
}


int main(){
	GameInstance game = GameInstance(8,8);
	game.displayBoard();
	
	return 0;
}


