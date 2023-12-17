#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 这个类表示使用邻接表的有向图
class Graph {
    int V;  // 顶点的数量
    vector<vector<int>> adj; // 邻接表

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w); // 在v的列表中添加w
    }

    void BFS(int s) {
        vector<bool> visited(V, false); // 标记所有顶点为未访问
        queue<int> queue; // 为BFS创建一个队列

        visited[s] = true; // 标记当前节点为已访问并入队
        queue.push(s);

        while (!queue.empty()) {
            s = queue.front();
            cout << s << " ";
            queue.pop();

            for (int adjacent : adj[s]) {
                if (!visited[adjacent]) {
                    visited[adjacent] = true;
                    queue.push(adjacent);
                }
            }
        }
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "下面是从顶点2开始的广度优先遍历(Breadth First Traversal)\n";
    g.BFS(2);

    system("pause");
    return 0;
}