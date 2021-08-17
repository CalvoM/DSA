#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <vector>
struct Vertex{
    unsigned int val;
    unsigned int cost;
    Vertex *next;
};

struct Edge{
    unsigned int src, dest,weight;
};

class Graph{
public:
    Graph(unsigned int vertices);
    void addEdge(Edge edge);
    void printGraph();
    void BFSTraversal(Vertex &);
    void DFSTraversal(Vertex &);
    ~Graph();
private:
    Vertex **conn;
    unsigned int vertCnt;
    unsigned int edgeCnt;
    void DFS(Vertex v, std::vector<unsigned int> &);
};
#endif