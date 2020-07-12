#include "includes/Queue.h"

int option(int percents[]){
    register int i=0, choice=rand()%100+1,perc;
    for(perc=percents[0];perc<choice;perc+=percents[i+1],i++);
    return i;
}

int main(int argc, char** argv){
    int arrivals[] = {15,20,25,10,30};
    int service[] = {0,0,0,10,5,10,10,0,15,25,10,15};
    int clerks[] = {0,0,0,0};
    int numOfClerks = sizeof(clerks)/sizeof(int);
    int customers,t,i,numOfMinutes=100,x;
    double maxWait=0.0,currWait=0.0,thereisLine=0.0;

    Queue<int> simulQ;
    std::cout.precision(2);
    for(t=1;t<=numOfMinutes;t++){
        for(i=0;i<numOfClerks;i++){
            if(clerks[i] < 60) clerks[i] = 0;
            else clerks[i] -=60;
        }
        
    }
}