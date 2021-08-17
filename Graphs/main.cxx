#include "includes/Graph.hpp"
#include <iostream>
int main(){
    Graph g(8);
    Edge paths[] = {{0,1,1},{1,2,1},{2,3,1},{3,0,1},{2,4,1},{4,5,1},{5,6,1},{6,7,1},{6,4,1}};
    for(auto p:paths){
        g.addEdge(p);
    }
    g.printGraph();
    auto start = Vertex{0,1,nullptr};
    g.DFSTraversal(start);
}