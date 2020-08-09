#pragma once
#include "Coord.h"
#include <chrono>
#include <thread>
#include <vector>
#include <iostream>

#define PRINT_DEBUG 1 // set this to 0 if you dont want to see any of your debug prints

//declarations
void sleep(int sleeptime);


// this template prints anything (singular value)
template <typename T>
void p(T x, bool nl = true, int sleeptime = 1){
	if (!PRINT_DEBUG)
		return;
	std::cout << x;
	if (nl)
		std::cout << "\n";
	sleep(sleeptime);
}


// this template prints arrays
template <typename T>
void p(T* x, int len){
	for (int y = 0; y < len; y++){
		p(x[y], false);
		if (y != len-1){
			p(", ", false);
		}
	}
	p("");

}

// this template prints vectors
template <typename T>
void p(std::vector<T> v){
	if (v.empty())
		p("VECTOR EMPTY");
		return;
	for (auto e : v)
		p(e, false);
		p(" - ", false);
	p("");
}


template <typename T>
void buffer(T input){
	std::cout << input << std::endl;
	std::string _;
	std::getline(std::cin, _);
}






