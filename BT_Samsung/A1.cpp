/*
* -	Để xác định đồ thị có chu trình Euler hay không, ta cần kiểm tra xem tất cả các đỉnh của đồ thị đều có bận chẵn hay không. 
	Nếu tất cả các đỉnh đều có bậc chẵn, đồ thị đó là chu trình Euler. Ngược lại, nếu có một đỉnh có bậc lẻ thì đồ thị đó không phải là 
	chu trình Euler.
  - Để xác định đồ thị có chu trình Hamilton hay không, ta cần kiểm tra xem có tồn tại một chu trình Hamilton nào đó trong đồ thị hay không. 
 => Đồ thị thứ nhất và thứ ba đều có chu trình Euler vì tất cả các đỉnh đều có bận chẵn. Đồ thị thứ tư không có chu trình Euler vì đỉnh 5 có bậc lẻ. 
	Các đồ thị không có chu trình Euler vì đỉnh 8 có bậc lẻ.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to add an edge
void addEdge(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Function to check whether a graph is Eulerian
bool isEulerian(vector<int> adj[], int V) {
    // Check if all non-zero degree vertices are connected
    int odd = 0;
    for (int i = 0; i < V; i++) {
        if (adj[i].size() & 1)
            odd++;
    }

    // If count of vertices with odd degree is greater than 2, then the graph is not Eulerian
    if (odd > 2)
        return false;

    return true;
}

// Function to check whether a graph has a Hamiltonian cycle
bool isHamiltonian(vector<int> adj[], int V) {
    vector<int> v(V);
    for (int i = 0; i < V; i++)
        v[i] = i;

    do {
        bool valid = true;
        for (int i = 0; i < V; i++) {
            if (find(adj[v[i]].begin(), adj[v[i]].end(), v[(i + 1) % V]) == adj[v[i]].end()) {
                valid = false;
                break;
            }
        }

        if (valid)
            return true;
    } while (next_permutation(v.begin(), v.end()));

    return false;
}

int main() {
    int V = 10;
    vector<vector<int>> adj1(V), adj2(V), adj3(V), adj4(V);

    // Add edges to the graphs
    // Graph 1
    addEdge(adj1.data(), 0, 1);
    addEdge(adj1.data(), 0, 2);
    addEdge(adj1.data(), 0, 3);
    addEdge(adj1.data(), 1, 3);
    addEdge(adj1.data(), 1, 4);
    addEdge(adj1.data(), 2, 5);
    addEdge(adj1.data(), 2, 9);
    addEdge(adj1.data(), 3, 6);
    addEdge(adj1.data(), 4, 7);
    addEdge(adj1.data(), 4, 8);
    addEdge(adj1.data(), 5, 8);
    addEdge(adj1.data(), 5, 9);
    addEdge(adj1.data(), 6, 7);
    addEdge(adj1.data(), 6, 9);
    addEdge(adj1.data(), 7, 8);

    // Graph 2
    addEdge(adj2.data(), 0, 1);
    addEdge(adj2.data(), 0, 2);
    addEdge(adj2.data(), 0, 3);
    addEdge(adj2.data(), 1, 3);
    addEdge(adj2.data(), 0, 3);
    addEdge(adj2.data(), 2, 5);
    addEdge(adj2.data(), 5, 6);
    addEdge(adj2.data(), 3, 6);
    addEdge(adj2.data(), 4, 7);
    addEdge(adj2.data(), 4, 8);
    addEdge(adj2.data(), 5, 8);
    addEdge(adj2.data(), 5, 9);
    addEdge(adj2.data(), 6, 7);
    addEdge(adj2.data(), 6, 9);
    addEdge(adj2.data(), 8, 8);

    // Graph 3
    addEdge(adj3.data(), 0, 1);
    addEdge(adj3.data(), 1, 2);
    addEdge(adj3.data(), 1, 3);
    addEdge(adj3.data(), 0, 3);
    addEdge(adj3.data(), 0, 4);
    addEdge(adj3.data(), 2, 5);
    addEdge(adj3.data(), 2, 9);
    addEdge(adj3.data(), 3, 6);
    addEdge(adj3.data(), 4, 7);
    addEdge(adj3.data(), 4, 8);
    addEdge(adj3.data(), 5, 8);
    addEdge(adj3.data(), 5, 9);
    addEdge(adj3.data(), 6, 7);
    addEdge(adj3.data(), 6, 9);
    addEdge(adj3.data(), 7, 8);

    // Graph 4
    addEdge(adj4.data(), 4, 1);
    addEdge(adj4.data(), 7, 9);
    addEdge(adj4.data(), 6, 2);
    addEdge(adj4.data(), 7, 3);
    addEdge(adj4.data(), 5, 0);
    addEdge(adj4.data(), 0, 2);
    addEdge(adj4.data(), 0, 8);
    addEdge(adj4.data(), 1, 6);
    addEdge(adj4.data(), 3, 9);
    addEdge(adj4.data(), 6, 3);
    addEdge(adj4.data(), 2, 8);
    addEdge(adj4.data(), 1, 5);
    addEdge(adj4.data(), 9, 8);
    addEdge(adj4.data(), 4, 5);
    addEdge(adj4.data(), 4, 7);

    // Check for Eulerian cycle
    cout << "Graph 1 has Eulerian cycle: " << (isEulerian(adj1.data(), V) ? "Yes" : "No") << endl;
    cout << "Graph 2 has Eulerian cycle: " << (isEulerian(adj2.data(), V) ? "Yes" : "No") << endl;
    cout << "Graph 3 has Eulerian cycle: " << (isEulerian(adj3.data(), V) ? "Yes" : "No") << endl;
    cout << "Graph 4 has Eulerian cycle: " << (isEulerian(adj4.data(), V) ? "Yes" : "No") << endl;

    // Check for Hamiltonian cycle
    cout << "Graph 1 has Hamiltonian cycle: " << (isHamiltonian(adj1.data(), V) ? "Yes" : "No") << endl;
    cout << "Graph 2 has Hamiltonian cycle: " << (isHamiltonian(adj2.data(), V) ? "Yes" : "No") << endl;
    cout << "Graph 3 has Hamiltonian cycle: " << (isHamiltonian(adj3.data(), V) ? "Yes" : "No") << endl;
    cout << "Graph 4 has Hamiltonian cycle: " << (isHamiltonian(adj4.data(), V) ? "Yes" : "No") << endl;

    return 0;
}