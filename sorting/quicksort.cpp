//
// Created by d1r3ct0r on 13/07/2021.
//

#include "sorting.h"
int optimalPartition(std::vector<int> &data, int start, int end){
    int mid = (start + end)/2;
    int pivot = data[mid];
    std::cout<<pivot<<std::endl;
    int ltTracker = start;
    int gtTracker = end;
    while(gtTracker > ltTracker){
        while(pivot<data[gtTracker])gtTracker--;
        while(pivot>data[ltTracker])ltTracker++;
        if(gtTracker> ltTracker)swap(data[gtTracker],data[ltTracker]);
    }
    swap(data[mid],data[gtTracker]);
    return gtTracker;
}
int partition(std::vector<int> &data, int start, int end){
    int pivot = data[start];
    int ltTracker = start;
    int gtTracker = end+1;
    while(gtTracker>=ltTracker){
        do{gtTracker--;}while(pivot<data[gtTracker]);
        do{ltTracker++;}while(pivot>data[ltTracker]);
        if(gtTracker > ltTracker){
            swap(data[ltTracker],data[gtTracker]);
        }

    }
    swap(data[start],data[gtTracker]);
    return gtTracker;
}
void quickSort(std::vector<int>& data, int start, int end){
    for(auto d:data)std::cout<<d<<" ";
    std::cout<<std::endl;
    if(start<end){
        int pivot = optimalPartition(data,start,end);
        quickSort(data,start,pivot-1);
        quickSort(data,pivot+1,end);
    }
}