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
