#pragma once
#include <iostream>

struct Coord {
	int x;
	int y;
	bool operator==(const Coord& lhs);
	operator bool() const;
};

std::ostream& operator<<(std::ostream& os, const Coord& c);


