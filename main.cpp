#include <iostream>
#include "timer.h"
#include "TimeUtils.cpp"
#include "ThreadUtils.h"

using namespace std;

#define LOOP_TIME 5
#define DO_WORK_TIME 3
#define GAME_TIME 23
#define LAG_UPDATE_INTERVAL 1

void doWork(int loopCount)
{
    cout << "Do Work! " << loopCount << endl;
    thread_sleep( (DO_WORK_TIME) * 1000);
}

void render(){
    cout << "\t Render" << endl;
}


int main()
{
    bool isWorking = true;
    int loopCount = 0;

    cout << "Program started \n" << endl;

    timer *t = new timer();
    
    while (isWorking)
    {
        t->start();
        doWork(loopCount++);
        t->stop();

        cout <<"loop timer "  << t->getTimePassed() << endl;

        if(t->isOver(LOOP_TIME)){
            thread_sleep( (LOOP_TIME-t->getTimePassed()) * 1000);
        }

        render();
            
        if(loopCount > 5 ){
            isWorking = false;
            cout << "Game exiting..."  << endl;
        }
    }

    t->stop();

    delete t;
    t = NULL;

    return 0;
}