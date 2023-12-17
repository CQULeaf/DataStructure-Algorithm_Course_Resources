#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph {
public:
    unordered_map<int, bool> visited;// 用于标记顶点是否已被访问
    unordered_map<int, list<int>> adj;// 邻接表

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void DFS(int v) {
        visited[v] = true;
        cout << v << " ";

        for (int adjacent : adj[v]) {
            if (!visited[adjacent]) {
                DFS(adjacent);
            }
        }
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "下面是从顶点2开始的深度优先遍历(Depth First Traversal)\n";
    g.DFS(2);

    system("pause");
    return 0;
}
