//
// Created by d1r3ct0r on 7/9/21.
//
#include "sorting.h"

void bubbleSort(std::vector<int>& data){
    for(int final=data.size()-1;final>=0;final--){
        for(int i=0;i<=final-1;i++){
            if(data[i]>data[i+1]) {
                swap(data[i], data[i + 1]);
            }
        }
    }
}