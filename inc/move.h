#pragma once
#include "GameInstance.h"
#include "constants.h"
#include "Coord.h"

template<typename T>
void getCurrentAndDestination(std::string input, GameInstance& game){
	// pulls current coordinate and destination coordinate and edits reference coordinates
	Coord c, d;
	int dcol = coordMap.at(input[1]) - 1;
	int drow = std::atoi(&input[2]) - 1;
	c = game.findPiece<T>(dcol, drow);
	if (!c)
		return;
	d = {dcol, drow};
	game.requestMove(c, d);
}


