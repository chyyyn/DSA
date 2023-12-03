/*
* Giả sử đồ thị G là đồ thị hai màu. Điều này có nghĩa là chúng ta có thể tô mỗi đỉnh của G với một trong hai màu sao cho không có hai 
  đỉnh kề nhau có cùng màu. Bây giờ, giả sử G có một chu trình độ dài lẻ. Khi đi qua chu trình này, chúng ta sẽ thay đổi màu sau mỗi bước.
  Do đó, sau một số lẻ các bước, chúng ta sẽ quay lại đỉnh ban đầu với màu khác so với màu ban đầu, điều này tạo ra mâu thuẫn với giả định 
  rằng G là đồ thị hai màu. Vì vậy, nếu G là đồ thị hai màu, thì nó không thể chứa chu trình độ dài lẻ.

  Ngược lại, giả sử G là đồ thị không chứa chu trình độ dài lẻ. Chúng ta có thể tô G với hai màu bằng cách chọn một đỉnh bất kỳ, 
  tô nó với màu 1, sau đó tô tất cả các đỉnh kề với nó với màu 2, và tiếp tục quá trình này cho đến khi tất cả các đỉnh đều được tô. 
  Nếu G chứa một chu trình độ dài lẻ, thì chúng ta sẽ gặp phải tình huống tương tự như trong phần chứng minh đầu tiên, nhưng vì G 
  không chứa chu trình độ dài lẻ, quá trình tô màu sẽ không gặp vấn đề. Vì vậy, nếu G không chứa chu trình độ dài lẻ, thì nó phải là 
  đồ thị hai màu.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to add an edge
void addEdge(vector<vector<int>>& adj, int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Function to check whether a graph is bipartite
bool isBipartite(vector<vector<int>>& adj, int V) {
    vector<int> color(V, -1);
    for (int i = 0; i < V; i++) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 1;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if (color[v] == color[u])
                        return false;
                }
            }
        }
    }
    return true;
}

int main() {
    int V = 4;
    vector<vector<int>> adj(V);

    // Add edges to the graph
    addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 0);

    // Check if the graph is bipartite
    cout << "The graph is " << (isBipartite(adj, V) ? "" : "not ") << "bipartite." << endl;

    return 0;
}
