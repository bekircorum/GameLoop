#include <time.h>

class TimeUtils
{

public:
  clock_t static getCurrentTime()
  {
      return clock();
    }
};
