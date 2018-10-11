#include "timer.h"

timer::timer() {
	resetted = true;
	running = false;
}

void timer::start() {
	if(! running) {
		if(resetted)
			beg = pt::microsec_clock::local_time();
		else
			beg -= end - pt::microsec_clock::local_time();
		running = true;
		resetted = false;
	}
}

void timer::stop() {
	if(running) {
		end = pt::microsec_clock::local_time();
		running = false;
	}
}

void timer::reset() {
	bool wereRunning = running;
	if(wereRunning)
		stop();

	beg = 	pt::microsec_clock::local_time();
	
	resetted = true;
	if(wereRunning)
		start();
}

bool timer::isRunning() {
	return running;
}

unsigned long timer::getTime() {
	pt::time_duration diff;
	
	if(running){
		diff = pt::microsec_clock::local_time() -  beg ;
	} else{
		 diff = end - beg;
	}

	return diff.total_microseconds();
}

bool timer::isOver(unsigned long seconds) {
	
	 return seconds * 1000000 >= getTime();
}