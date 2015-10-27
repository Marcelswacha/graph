#include "graph.h"

#include <iostream>
#include <stack>
#include <queue>

Graph::Graph(int V)
{
    this->V = V;
    adjencyList = new std::list<int>[V+1];
}

Graph::~Graph()
{
    delete [] adjencyList;
}

void Graph::addEdge(int v, int w)
{
    if (v <= V && w <= V)
        adjencyList[v].push_back(w);
}

void Graph::printDFS(int s)
{
    bool *visited = new bool[V];
    for (int i=0; i<V; ++i)
        visited[i] = false;

    std::stack<int> stack;

    stack.push(s);
    visited[s]=true;

    while(!stack.empty()) {
        int curr = stack.top();
        visited[curr] = true;
        std::cout << curr << " ";
        stack.pop();

        std::list<int>::iterator it;

        for(it = adjencyList[curr].begin(); it != adjencyList[curr].end(); ++it)
            if (!visited[*it])
                stack.push(*it);
    }

    std::cout << std::endl;
    delete [] visited;
}

void Graph::printBFS(int s)
{
    bool *visited = new bool[V];
    for (int i=0; i<V; ++i)
        visited[i] = false;

    std::queue<int> queue;

    queue.push(s);
    visited[s]=true;

    while(!queue.empty()) {
        int curr = queue.front();
        visited[curr] = true;
        std::cout << curr << " ";
        queue.pop();

        std::list<int>::iterator it;

        for(it = adjencyList[curr].begin(); it != adjencyList[curr].end(); ++it)
            if (!visited[*it])
                queue.push(*it);
    }

    std::cout << std::endl;
    delete [] visited;
}

int main(int argc, char **argv)
{
    Graph g(5);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.printBFS(1);
    g.printDFS(1);
}
