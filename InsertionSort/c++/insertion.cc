#include <iostream>
#include <array>
int main(){
    int arr1[10] = {10,8,7,9,1,2,3,5,4,6};
    int length = std::end(arr1) - std::begin(arr1);
    for(int front=1;front<length;front++){
        int current_item = arr1[front];
        int back = front - 1;
        while(arr1[back]> current_item and back>=0){
            arr1[back+1] = arr1[back];
            back--;
        }
        arr1[back+1] = current_item;
    }
    for (auto c:arr1){
        std::cout<<c<<" ";
    }
}