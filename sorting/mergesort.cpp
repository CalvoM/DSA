//
// Created by d1r3ct0r on 10/07/2021.
//
#include "sorting.h"
void merge(std::vector<int>& data,int begin, int mid, int end){
    int b = begin;
    int f = mid+1;
    int firstVal,secondVal=0;
    std::vector<int>temp;
    while(b<=mid && f<=end){
        firstVal = data[b];
        secondVal = data[f];
            if(firstVal<secondVal){
                temp.push_back(firstVal);
                b++;
            }else if(secondVal<firstVal){
                temp.push_back(secondVal);
                f++;
            }
    }
    while(b <=mid){
        temp.push_back(data[b]);
        b++;
    }
    while(f<=end){
        temp.push_back(data[f]);
        f++;
    }
    for(int k=0;k<temp.size();k++){
        data[begin+k] = temp[k];
    }
    std::cout<<std::endl;
}
void mergeSort(std::vector<int>& data,int start, int end){
    if(start>=end){
        return;
    }
    //Divide
    int mid = (end+start)/2;
    mergeSort(data,start,mid);
    mergeSort(data,mid+1,end);
    merge(data,start,mid,end);

}
