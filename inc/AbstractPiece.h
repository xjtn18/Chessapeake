#pragma once

class AbstractPiece {
protected:
	int currentLocation[2];
	//AbstractPiece(int colrow[2]): currentLocation (colrow) {}
public:
	char symb;
	virtual void move() = 0;
	int* getCurrentLocation(){
		return currentLocation;
	}
	void setLocation(int col, int row);

};
