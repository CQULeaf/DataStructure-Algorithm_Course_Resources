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
