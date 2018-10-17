#include "timer.h"

timer::timer() {
	resetted = true;
	running = false;
}

void timer::start() {
	if(! running) {
		if(resetted)
			beg = clock();
		else
			beg -= end - clock();
		running = true;
		resetted = false;
	}
}

void timer::stop() {
	if(running) {
		end = clock();
		running = false;
	}
}

void timer::reset() {
	bool wereRunning = running;
	if(wereRunning)
		stop();

	beg = clock();
	
	resetted = true;
	if(wereRunning)
		start();
}

bool timer::isRunning() {
	return running;
}

double timer::getTimePassed() {
	clock_t diff;
	
	if(running){
		diff = clock() -  beg ;
	} else{
		 diff = end - beg;
	}

	return diff / (double) CLOCKS_PER_SEC;
}

bool timer::isOver(unsigned long seconds) {
	 return seconds <= getTimePassed();
}