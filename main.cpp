#include <iostream>
#include <unistd.h>
#include "timer.h"
#include <boost/thread/thread.hpp>
#include "TimeUtils.cpp"

using namespace std;

void doWork()
{
    boost::this_thread::sleep(boost::posix_time::seconds(5));
    cout << "\t do work " << endl;
}

int main()
{

    bool isWorking = true;

    cout << "Program started : " << TimeUtils::getCurrentDate() << endl;

    timer *t = new timer();
    t->start();

    while (isWorking)
    {
        doWork();
        t->reset();

        if(t->isOver(100000))
            isWorking = false;
            
        cout << "Iteration " << TimeUtils::getCurrentDate() << endl;
    }

    t->stop();

    return 0;
}
