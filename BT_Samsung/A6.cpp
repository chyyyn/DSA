#include <iostream>
#include <list>
#include <cstring>
using namespace std;

class Graph {
    int V;
    list<int>* adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void DFS(int v, bool visited[]);
    bool isConnected();
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::DFS(int v, bool visited[]) {
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i, visited);
}

bool Graph::isConnected() {
    bool* visited = new bool[V];
    memset(visited, false, V);
    DFS(0, visited);
    for (int i = 0; i < V; i++)
        if (visited[i] == false)
            return false;
    delete[] visited;
    return true;
}

int main() {
    Graph g1(7);
    g1.addEdge(1, 0);
    g1.addEdge(1, 2);
    g1.addEdge(2, 0);
    g1.addEdge(1, 3);
    g1.addEdge(1, 4);
    g1.addEdge(1, 6);
    g1.addEdge(3, 5);
    g1.addEdge(4, 5);
    g1.isConnected() ? cout << "The graph is edge connected" :
        cout << "The graph is not edge connected";
    return 0;
}
