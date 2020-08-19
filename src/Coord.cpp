#include "Coord.h"

bool Coord::operator==(const Coord& lhs){
	return this->x == lhs.x && this->y == lhs.y;
}


std::ostream& operator<<(std::ostream& os, const Coord& c){
	os << "(" << c.x << ", " << c.y << ")";
	return os;
}

Coord::operator bool() const{
	return this->x != -1 && this->y != -1;
}


