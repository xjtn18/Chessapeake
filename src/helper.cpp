#include "inc/helper.h"

void p(std::vector<Coord> v){
	for (auto e : v)
		std::cout << e << " - ";
	std::cout << "\n";
}


void sleep(int sleeptime){
	std::this_thread::sleep_for(std::chrono::seconds(sleeptime));
}


