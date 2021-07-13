//
// Created by d1r3ct0r on 7/9/21.
//
#include <iostream>
#include "sorting.h"
#include <vector>
#include <ctime>
#include <cstdlib>

int main(int argc, char **argv){
    srand((unsigned )time(0));
    std::cout<<"What is the size of data you want"<<std::endl;
    int dataSize=0;
    std::cin>>dataSize;
    std::vector<int> data;
    int item;
    for(int i=0;i<dataSize;i++){
        item = rand()%(dataSize*5);
       data.push_back(item);
    }
    for(auto d:data)std::cout<<d<<" ";
    std::cout<<std::endl;
    quickSort(data,0,dataSize-1);
    for(auto d:data)std::cout<<d<<" ";
    std::cout<<std::endl;
}

