//
// Created by d1r3ct0r on 10/07/2021.
//
#include "sorting.h"

void insertionSort(std::vector<int>& data){
    std::cout<<"INSERTION SORT"<<std::endl;
    for(int forward=1;forward<data.size();forward++){
        for(int i=forward;i>0;i--){
            if(data[i]<data[i-1]){
                swap(data[i],data[i-1]);
            }
        }
    }
}