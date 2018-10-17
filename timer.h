#include <iostream>
#include <time.h>	

using namespace std;

class timer {
	public:
		timer();
		void              start();
		void              stop();
		void              reset();
		bool          	  isRunning();
		double			  getTimePassed();
		bool              isOver(unsigned long seconds);
		clock_t 		  getBegTime() const { return beg; }
	private:
		bool              resetted;
		bool              running;
		clock_t  beg;
		clock_t  end;
};