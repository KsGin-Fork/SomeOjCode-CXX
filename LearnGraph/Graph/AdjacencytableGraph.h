#pragma once
#include "Graph.h"
#include <string>
#include <vector>

class AdjacencyTableGraph :
	public Graph
{

private:

	struct tableNode
	{
		_int weight;
		_int cur_node_index;
		tableNode* next_node;
	};

	struct vert : _vertex
	{
		tableNode* next_node;
	};

private:

	vert **m_verts;                 //顶点集合
	_int m_vertCount;              //顶点数量

private:
	int IndexOf(_vertex* vert) const;
	void DFS(vert* root , std::string& result ,  bool*& iscreated) const;
	void NLC(vert* root , std::vector<std::string>& results , std::string& result , _int resultCount , bool*& isVisted) const;
public:
	std::string TPS() const override;                   //拓扑排序 Topological sorting
	std::string BFS() const override;                   //广度优先遍历 Breadth first traversal
	std::string DFS() const override;                   //深度优先遍历 Depth first traversal
	int UCT() const override;                           //求联通分量个数
	int MST(int* weightForVert , int weightForVertCount) const;                                         //最小生成树
	std::vector<std::string> NLC() const;
	int Distance(vert* vertf , vert* vertt , bool*& isVisted , bool& isFound) const;	//网络寻路路径(出自ACM题)
	int MLP() const;                                    //点与点之间的最长路径
	int InDegreeOf(const _elem_t data) const;           //入度
	int OutDeGreeOf(const _elem_t data) const;          //出度
	explicit AdjacencyTableGraph(std::string verts , int vertCount , _int** edges , int edgeCount , bool hasdirect);
	AdjacencyTableGraph();
	~AdjacencyTableGraph();
};

