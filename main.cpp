#include <iostream>
#include <unistd.h>
#include "timer.h"
#include <boost/thread/thread.hpp>
#include "TimeUtils.cpp"

using namespace std;

#define EXPIRE_TIME 10

void doWork()
{
    boost::this_thread::sleep(boost::posix_time::seconds(2));
    cout << "Do Work! " << endl;
}

void render(){
    cout << "\t Render" << endl;
}

int main()
{

    bool isWorking = true;
    int loopCount = 0;

    cout << "Program started : " << TimeUtils::getCurrentTime()  << "\n" << endl;

    timer *t = new timer();
    t->start();

    while (isWorking)
    {
        doWork();
        render();
         
        cout << "Loop " << loopCount << " ends."<< endl;
        loopCount++;

        if(!t->isOver(EXPIRE_TIME)){
             cout << "Timer expired! Program exiting.. " << TimeUtils::getCurrentTime() << endl;
             isWorking = false;
         }
    }

    t->stop();

    return 0;
}
