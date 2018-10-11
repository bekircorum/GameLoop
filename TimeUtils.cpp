#include "boost/date_time/posix_time/posix_time.hpp"
#include <boost/timer.hpp>

namespace pt = boost::posix_time;

class TimeUtils
{

public:
  pt::ptime static getCurrentTime()
  {
      return pt::second_clock::local_time();
    }
};
