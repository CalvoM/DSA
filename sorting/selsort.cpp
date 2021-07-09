//
// Created by d1r3ct0r on 7/9/21.
//
#include "sorting.h"

void selectionSort(std::vector<int>&data){
    int temp;
    for(int finalTracker=0;finalTracker<data.size();finalTracker++){ //C(n^2 + 1)
        for(int preTracker=finalTracker+1;preTracker<data.size();preTracker++){
            if(data[finalTracker]>data[preTracker]){
                swap(data[preTracker],data[finalTracker]);
            }
        }
    }
}

