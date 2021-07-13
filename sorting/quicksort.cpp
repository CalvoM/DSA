//
// Created by d1r3ct0r on 13/07/2021.
//

#include "sorting.h"

int partition(std::vector<int> &data, int low, int high){
    int pivot =  data[high];
    int indexToCheck=low;
    int pivotLoc = low-1; //Arbitrary pivot location
    while(indexToCheck < high){
        if(pivot >= data[indexToCheck]){
            pivotLoc++;
            swap(data[pivotLoc],data[indexToCheck]);
        }
        indexToCheck++;
    }
    pivotLoc++;
    swap(data[pivotLoc],data[high]);//In case the lowest is at the end

    return pivotLoc;
}
void quickSort(std::vector<int>& data, int low, int high){
    for(auto d:data)std::cout<<d<<" ";
    std::cout<<std::endl;
    if(low!=high){
        int pivot = partition(data,low,high);
        quickSort(data,low,pivot-1);
        quickSort(data,pivot+1,high);
    }
}