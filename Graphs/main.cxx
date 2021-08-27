#include "includes/Graph.hpp"
#include <iostream>
int main(){
    Graph g(6);
    Edge paths[] = {{0,1,5},{0,2,0},{1,3,15},{1,4,20},{2,3,30},{2,4,35},{3,5,20},{4,5,10}};
    for(auto p: paths){
        g.addEdge(p);
    }
}