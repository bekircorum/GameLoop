#include <iostream>
#include <unistd.h>
#include "timer.h"
#include <boost/thread/thread.hpp>
#include "TimeUtils.cpp"

using namespace std;

#define LOOP_TIME 5
#define GAME_TIME 23
#define LAG_UPDATE_INTERVAL 1

void doWork(int loopCount)
{

    double workTime = 2;
    if(loopCount == 3) {
        workTime = 8;
        cout << "Do HEAVY Work! " << endl;
    } else {
        workTime = 2;
        cout << "Do Work! " << endl;
    }

    boost::this_thread::sleep(boost::posix_time::seconds(workTime));
}

void render(){
    cout << "\t Render" << endl;
}

void sleepMilliSecond(unsigned long miliseconds){
    boost::this_thread::sleep(boost::posix_time::millisec(miliseconds) );
}

int main()
{
    bool isWorking = true;
    int loopCount = 0;

    cout << "Program started : " << TimeUtils::getCurrentTime()  << "\n" << endl;

    timer *t = new timer();
    t->start();

    timer *gameTimer = new timer();
    gameTimer-> start();

    while (isWorking)
    {
        doWork(loopCount);

        if(t->isOver(LOOP_TIME)){
            cout << "Slow loop detected!";
            unsigned long timeIterated = 0;
            pt::time_duration diff = TimeUtils::getCurrentTime() - t->getBegTime();
            unsigned long timeToIterate = diff.total_milliseconds();
            cout << "TimeToIterate="  << timeToIterate << endl;
            while(timeToIterate  >= timeIterated ){
               cout << "Iterate slow loop to cathc up!" << endl;
                
                doWork(loopCount);
                timeIterated = diff.total_milliseconds() + LAG_UPDATE_INTERVAL * 1000; 

                cout << " diff=" << diff.total_milliseconds() << " timeIterated=" << timeIterated << endl;  
            }
        }

        render();
         
        cout << "Loop " << loopCount << " ends."<< endl;
        loopCount++;

        t->reset();

        if(gameTimer-> isOver(GAME_TIME)){
            isWorking = false;
        }
    }

    t->stop();
    gameTimer-> stop();

    delete t,gameTimer;
    t=gameTimer = NULL;

    return 0;
}