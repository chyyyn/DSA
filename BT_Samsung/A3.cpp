#include <iostream>
#include <vector>

using namespace std;

// Function to add an edge
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u][v]++;
    adj[v][u]++;
}

// Function to count parallel edges
int countParallelEdges(vector<vector<int>>& adj) {
    int count = 0;
    for (int i = 0; i < adj.size(); i++) {
        for (int j = 0; j < adj[i].size(); j++) {
            if (adj[i][j] > 1) {
                count += adj[i][j] / 2;
            }
        }
    }
    return count;
}

int main() {
    int V = 5;
    vector<vector<int>> adj(V, vector<int>(V, 0));

    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 1); // parallel edge
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 0);
    addEdge(adj, 4, 0); // parallel edge

    // Count parallel edges
    int count = countParallelEdges(adj);
    cout << "The graph has " << count << " parallel edges." << endl;

    return 0;
}
