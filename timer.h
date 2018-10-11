#include <iostream>
#include <time.h>	
#include "boost/date_time/posix_time/posix_time.hpp"
#include <boost/timer.hpp>

using namespace std;

namespace pt = boost::posix_time;

class timer {
	public:
		timer();
		void              start();
		void              stop();
		void              reset();
		bool          	  isRunning();
		unsigned long	  getTime();
		bool              isOver(unsigned long seconds);
		pt::ptime 		  getBegTime() const { return beg; }
	private:
		bool              resetted;
		bool              running;
		pt::ptime  beg;
		pt::ptime  end;
};