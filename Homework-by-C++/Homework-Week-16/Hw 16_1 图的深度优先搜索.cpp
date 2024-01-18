#include <iostream>
#include <vector>
using namespace std;

#define MaxVexNum 20 // 最大顶点数目

typedef struct {
    int arcs[MaxVexNum][MaxVexNum];
    int vexnum, arcnum;
} AMGraph;

// 深度优先搜索函数
void DFS(AMGraph &G, int v, vector<bool> &visited, vector<int> &result) {
    visited[v] = true;
    result.push_back(v);
    for (int i = 0; i < G.vexnum; ++i) {
        if (G.arcs[v][i] == 1 && !visited[i]) {
            DFS(G, i, visited, result);
        }
    }
}

// 计算连通分量个数的函数
int calculateConnectedComponents(AMGraph &G, vector<int> &result) {
    vector<bool> visited(G.vexnum, false);
    int count = 0;
    for (int i = 0; i < G.vexnum; ++i) {
        if (!visited[i]) {
            DFS(G, i, visited, result);
            count++;
        }
    }
    return count;
}

int main() {
    AMGraph G;
    cin >> G.vexnum >> G.arcnum;
    for (int i = 0; i < G.vexnum; ++i) {
        for (int j = 0; j < G.vexnum; ++j) {
            G.arcs[i][j] = 0; // 初始化邻接矩阵
        }
    }
    
    for (int i = 0; i < G.arcnum; ++i) {
        int a, b;
        cin >> a >> b;
        G.arcs[a][b] = G.arcs[b][a] = 1;
    }

    vector<int> dfsResult;
    int connectedComponents = calculateConnectedComponents(G, dfsResult);
    
    for (int i : dfsResult) {
        cout << i << " ";
    }
    cout << endl;
    
    cout << connectedComponents << endl;
    
    cout << G.arcnum << endl;

    system("pause");
    return 0;
}
