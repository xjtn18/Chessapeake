#include "../inc/helper.h"
#include "../inc/constants.h"


void sleep(int sleeptime){
	std::this_thread::sleep_for(std::chrono::seconds(sleeptime));
}


