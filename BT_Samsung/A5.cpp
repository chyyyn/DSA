/*
* Giả sử G là một đồ thị không có điểm articulation. Điều này có nghĩa là không có đỉnh nào trong G mà khi xóa nó và các cạnh kề sẽ làm đồ thị 
  mất tính liên thông. Bây giờ, giả sử G không phải là đồ thị biconnected. Điều này có nghĩa là có ít nhất một cặp đỉnh mà không được nối với
  nhau bởi hai đường đi không giao nhau. Tuy nhiên, điều này tạo ra một điểm articulation: nếu chúng ta xóa một đỉnh từ một trong hai đường đi,
  đồ thị sẽ mất tính liên thông, điều này tạo ra mâu thuẫn với giả định ban đầu. Vì vậy, nếu G không có điểm articulation, thì nó phải là đồ 
  thị biconnected.

  Ngược lại, giả sử G là một đồ thị biconnected. Điều này có nghĩa là mỗi cặp đỉnh đều được nối với nhau bởi hai đường đi không giao nhau. 
  Nếu chúng ta xóa một đỉnh từ G, thì ít nhất một trong hai đường đi giữa mỗi cặp đỉnh sẽ vẫn còn, do đó G vẫn sẽ liên thông. Do đó, G không 
  có điểm articulation. Vì vậy, nếu G là đồ thị biconnected, thì nó không có điểm articulation.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> adj[100001];
int in[100001], low[100001], vis[100001];
int timer;
bool hasArticulationPoint;

void addEdge(int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int node, int par) {
    vis[node] = 1;
    in[node] = low[node] = timer++;
    int children = 0;

    for (int child : adj[node]) {
        if (child == par) continue;

        if (vis[child]) {
            low[node] = min(low[node], in[child]);
        }
        else {
            dfs(child, node);
            low[node] = min(low[node], low[child]);
            if (low[child] >= in[node] && par != -1) {
                hasArticulationPoint = true;
            }
            children++;
        }
    }

    if (par == -1 && children > 1) {
        hasArticulationPoint = true;
    }
}

int main() {
    int n = 4;

    addEdge(1, 0);
    addEdge(1, 2);
    addEdge(2, 0);
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(1, 6);
    addEdge(3, 5);
    addEdge(4, 5);

    dfs(0, -1);

    if (hasArticulationPoint) {
        cout << "The graph is not biconnected." << endl;
    }
    else {
        cout << "The graph is biconnected." << endl;
    }

    return 0;
}