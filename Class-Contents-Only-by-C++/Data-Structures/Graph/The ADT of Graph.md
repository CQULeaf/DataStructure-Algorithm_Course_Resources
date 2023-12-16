# The ADT of Graph

1. **数据对象**：图的数据对象主要是顶点（Vertex）的集合。每个顶点都是图的一个基本单位。

2. **数据关系**：图中的数据关系由边（Edge）或弧（Arc）定义。边或弧连接两个顶点，代表它们之间的关系。在数学表示中，边或弧可以用顶点对来表示，例如，`(vi, vj)` 或 `<vi, vj>`。这里，`(vi, vj)` 表示无向边，而 `<vi, vj>` 表示有向边。函数 `P(vi, vj)` 定义了边或弧的具体信息或属性。

3. **基本操作**：
   - `InitGraph(graph, kMaxVertex, no_edge_value, directed)`: 初始化一个图。`kMaxVertex` 是最大顶点数，`no_edge_value` 是顶点间无边时的权值，`directed` 表示图是有向的还是无向的。
   - `CreateGraph(graph)`: 构造一个图。
   - `DestroyGraph(graph)`: 释放图占用的所有资源。
   - `NumberOfVex(graph)`: 返回图中顶点的数量。
   - `NumberOfEdge(graph)`: 返回图中边的数量。
   - `ExistEdge(graph, u, v)`: 判断顶点 `u` 到 `v` 之间是否存在边。
   - `GetPosition(graph, v)`: 返回顶点 `v` 在图中的位置。
   - `GetValue(graph, v)`: 返回图中顶点 `v` 的值。
   - `PutValue(graph, v, value)`: 为图中顶点 `v` 赋值 `value`。
   - `FirstAdjVex(graph, v)`: 返回图中顶点 `v` 的第一个邻接顶点。
   - `NextAdjVex(graph, u, v)`: 返回图中 `u` 顶点相对 `v` 顶点的下一个邻接顶点。
   - `InsertVex(graph, v)`: 在图中插入顶点 `v`。
   - `InsertEdge(graph, u, v, weight)`: 在图中顶点 `u` 和 `v` 之间插入一条边，权值为 `weight`。
   - `RemoveVex(graph, v)`: 在图中删除顶点 `v` 及其所有邻接边。
   - `RmoveEdge(graph, u, v)`: 在图中删除顶点 `u` 和 `v` 之间的边。
   - `DFS(graph)`: 对图进行深度优先遍历。
   - `DFS(graph, v, visited)`: 从顶点 `v` 开始进行深度优先遍历，`visited` 记录顶点的访问标记。
   - `BFS(graph)`: 对图进行广度优先遍历。
   - `BFS(graph, v, visited)`: 从顶点 `v` 开始进行广度优先遍历，`visited` 记录顶点的访问标记。

## The Implementation of ADT of Graph with adjMatrix

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int maxVertices;//最大顶点数
    bool directed;//是否为有向图
    vector<vector<int>> adjMatrix;//邻接矩阵

public:
    Graph(int maxVertices, int noEdgeValue = 0, bool directed = false)
        : maxVertices(maxVertices), directed(directed), adjMatrix(maxVertices, vector<int>(maxVertices, noEdgeValue)) {}//初始化

    // 析构函数无需显式定义，vector会自动管理内存

    void insertVertex(int v) {
        // 通常在使用邻接矩阵时，不需要特别处理插入顶点的操作
    }//插入顶点

    void insertEdge(int u, int v, int weight) {
        if (u >= 0 && u < maxVertices && v >= 0 && v < maxVertices) {
            adjMatrix[u][v] = weight;
            if (!directed) {
                adjMatrix[v][u] = weight; // 对于无向图，同时更新对称位置的权值
            }
        }
    }//插入边

    void removeVertex(int v) {
        // 在邻接矩阵表示中，通常不直接删除顶点，因为这需要重构整个矩阵
    }//删除顶点

    void removeEdge(int u, int v) {
        if (u >= 0 && u < maxVertices && v >= 0 && v < maxVertices) {
            adjMatrix[u][v] = noEdgeValue;
            if (!directed) {
                adjMatrix[v][u] = noEdgeValue;// 对于无向图，同时更新对称位置的权值
            }
        }
    }//删除边

    int getPosition(int v) {
        // 返回顶点在图中的位置，因为使用邻接矩阵,故这里直接返回顶点的值
        return v;
    }//返回顶点在图中的位置

    int getValue(int v) {
        // 通常顶点的值就是其位置
        return v;
    }//返回顶点的值

    void putValue(int v, int value) {
        // 在邻接矩阵中，通常不存储额外的顶点值
    }//设置顶点的值

    int numberOfVertices() {
        return maxVertices;
    }//返回顶点数

    int numberOfEdges() {
        int count = 0;
        for (int i = 0; i < maxVertices; i++) {
            for (int j = 0; j < maxVertices; j++) {
                if (adjMatrix[i][j] != noEdgeValue) count++;
            }
        }
        return directed ? count : count / 2;
    }//返回边数

    bool existEdge(int u, int v) {
        return u >= 0 && u < maxVertices && v >= 0 && v < maxVertices && adjMatrix[u][v] != noEdgeValue;
    }//判断边是否存在

};
```

## The Implementation of ADT of Graph with adjList

```cpp
#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
private:
    int maxVertices;
    bool directed;
    vector<list<int>> adjList;

public:
    Graph(int maxVertices, bool directed = false) : maxVertices(maxVertices), directed(directed) {
        adjList.resize(maxVertices);
    }// 图的初始化

    // 析构函数无需显式定义，vector和list会自动管理内存

    void insertVertex(int v) {
        // 在邻接表中，通常不需要显式插入顶点
    }//插入顶点

    void insertEdge(int u, int v) {
        if (u < maxVertices && v < maxVertices) {
            adjList[u].push_back(v);
            if (!directed) {
                adjList[v].push_back(u);
            }
        }
    }//插入边

    void removeVertex(int v) {
        // 由于需要重新构造列表，删除顶点较为复杂
    }//删除顶点

    void removeEdge(int u, int v) {
        adjList[u].remove(v);
        if (!directed) {
            adjList[v].remove(u);
        }
    }//删除边

    int getPosition(int v) {
        return v;
    }//返回顶点在图中的位置

    int numberOfVertices() {
        return maxVertices;
    }//返回顶点数

    int numberOfEdges() {
        int count = 0;
        for (int i = 0; i < maxVertices; i++) {
            count += adjList[i].size();
        }
        return directed ? count : count / 2;
    }//返回边数

    bool existEdge(int u, int v) {
        for (auto& vert : adjList[u]) {
            if (vert == v) return true;
        }
        return false;
    }//判断边是否存在
    
};
```

***仅呈现两种存储方式的基本代码实践，`BFS`与`DFS`等高级操作之后详细说明***
