#include <iostream>
#include "includes/IntBST.h"
#define varName(x) #x
int main (int argc,char** argv){
    IntBST tree;
    tree.insert(4);
    for(int i=1;i<=7;i++){
        if(i!=4){
            tree.insert(i);
        }
    }
    tree.preOrderTraversal();
    std::cout<<tree.max()<<std::endl;
    std::cout<<tree.min()<<std::endl;
}