#include "../includes/Graph.hpp"
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
Graph::Graph(unsigned int vertices){
    this->conn = new Vertex* [vertices]();
    this->vertCnt = vertices;
    this->edgeCnt = 0;
    for(int k=0;k<vertices;k++){
        conn[k] = nullptr;
    }
}
void Graph::addEdge(Edge edge){
    Vertex *v = new Vertex();
    v->val = edge.dest;
    v->cost =0;
    v->next = conn[edge.src];
    conn[edge.src] = v;
    edgeCnt++;
}

void Graph::printGraph(){
    for(int k=0;k<this->vertCnt;k++){
        auto c = conn[k];
        std::cout<<k<<" --- ";
        while(c != nullptr){
            std::cout<<c->val<<"->";
            c = c->next;
        }
        std::cout<<std::endl;
    }
}

void Graph::BFSTraversal(Vertex &v){
    if(this->edgeCnt == 0 ){
        std::cout<<"Nothing to traverse"<<std::endl;
        return;
    }
    int curr = v.val;
    std::vector<int> visited;
    visited.push_back(curr);
    std::queue<int> bfs;
    bfs.push(curr);
    auto node = conn[curr];
    while(!bfs.empty()){
        while(node != nullptr){
            if(std::find(visited.begin(),visited.end(),node->val) == visited.end()){
                bfs.push(node->val);
                visited.push_back(node->val);
            }
            node = node->next;
        }
        bfs.pop();
        node = conn[bfs.front()];
    }
    for(auto i:visited)std::cout<<i<<" ";
    std::cout<<std::endl;
}

void Graph::DFSTraversal(Vertex &v){
    std::vector<unsigned int> visited;
    visited.push_back(v.val);
    this->DFS(v,visited);
    for(auto i:visited)std::cout<<i<<" ";
    std::cout<<std::endl;
    return;
}
void Graph::DFS(Vertex v, std::vector<unsigned int> &visited){
    auto c = this->conn[v.val];
    while(c != nullptr){
        if(std::find(visited.begin(),visited.end(),c->val) == visited.end()){
            visited.push_back(c->val);
            DFS(*c,visited);
        }
        c = c->next;
    }
}

Graph::~Graph(){
    Vertex *tmp;
    for(int k=0;k<vertCnt;k++){
        auto c = conn[k];
        while(c != nullptr){
            tmp = c;
            c = c->next;
            delete tmp;
        }
    }
    delete[] conn;
}