#include <list>

class Graph
{
public:
    Graph(int V);
    ~Graph();
    
    void addEdge(int v, int w);
    void printDFS(int s);
    void printBFS(int s);
    
    int getV() const { return V; }
    
private:
    int V;
    std::list<int>* adjencyList;
};