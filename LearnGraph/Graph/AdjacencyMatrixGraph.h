#pragma once
#include "Graph.h"
#include <queue>

class AdjacencyMatrixGraph :
	public Graph
{
	typedef std::queue<_vertex*> queue;       //重命名队列
private:
	_vertex** m_vertexs = nullptr;           //顶点集合
	_edge** m_edges = nullptr;               //边集合
	_int m_vertexCount = 0;           //顶点个数
	_int m_edgeCount = 0;             //边个数
	bool m_hasdirect = false;

private:
	void _Init_(std::string verlist /*顶点数据*/ , _int vertCount /*顶点个数*/ , _int** edgelist /*边的集合*/ , _int edgeCount /*边的个数*/ , bool hasdirect /*是否有方向*/);
	void DFS(_vertex* vert , std::string& GetResult  ,bool*& isVisted ) const;
	_int IndexOf(const _vertex* vert) const;
public:
	int UCT() const override;                         //连通分量个数
	std::string TPS() const override;                 //拓扑排序 Topological sorting
	std::string DFS() const override;                 //广度优先遍历 Breadth first traversal
	std::string BFS() const override;                 //深度优先遍历 Depth first traversal
	int InDegreeOf(const _elem_t data) const;         //入度
	int OutDeGreeOf(const _elem_t data) const;        //出度
	AdjacencyMatrixGraph(std::string verlist /*顶点数据*/ , _int vertCount /*顶点个数*/ , _int** edgelist /*边的集合*/ , _int edgeCount /*边的个数*/ , bool hasdirect /*是否有方向*/);
	AdjacencyMatrixGraph();
	~AdjacencyMatrixGraph();
};

