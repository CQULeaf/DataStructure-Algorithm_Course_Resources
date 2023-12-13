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
