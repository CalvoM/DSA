//
// Created by d1r3ct0r on 7/9/21.
//
#include <iostream>
#include "sorting.h"
#include <vector>

int main(int argc, char **argv){
    std::cout<<"What is the size of data you want"<<std::endl;
    int dataSize=0;
    std::cin>>dataSize;
    std::vector<int> data;
    int item;
    for(int i=0;i<dataSize;i++){
        item = rand()%2000;
       data.push_back(item);
    }
    selectionSort(data);
}

