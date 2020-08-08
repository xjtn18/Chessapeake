#pragma once
#include <iostream>

struct Coord {
	int x;
	int y;
	Coord() : x (-1), y (-1) { };
	Coord(std::initializer_list<int> l) : x (*l.begin()), y (*(l.begin()+1)) { };
	bool operator==(const Coord& lhs);
	operator bool() const;
};

std::ostream& operator<<(std::ostream& os, const Coord& c);


