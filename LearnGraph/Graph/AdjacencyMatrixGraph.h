#pragma once
#include "Graph.h"
#include <queue>

class AdjacencyMatrixGraph :
	public Graph
{
	typedef std::queue<_vertex*> queue;       //����������
private:
	_vertex** m_vertexs = nullptr;           //���㼯��
	_edge** m_edges = nullptr;               //�߼���
	_int m_vertexCount = 0;           //�������
	_int m_edgeCount = 0;             //�߸���
	bool m_hasdirect = false;

private:
	void _Init_(std::string verlist /*��������*/ , _int vertCount /*�������*/ , _int** edgelist /*�ߵļ���*/ , _int edgeCount /*�ߵĸ���*/ , bool hasdirect /*�Ƿ��з���*/);
	void DFS(_vertex* vert , std::string& GetResult  ,bool*& isVisted ) const;
	_int IndexOf(const _vertex* vert) const;
public:
	int UCT() const override;                         //��ͨ��������
	std::string TPS() const override;                 //�������� Topological sorting
	std::string DFS() const override;                 //������ȱ��� Breadth first traversal
	std::string BFS() const override;                 //������ȱ��� Depth first traversal
	int InDegreeOf(const _elem_t data) const;         //���
	int OutDeGreeOf(const _elem_t data) const;        //����
	AdjacencyMatrixGraph(std::string verlist /*��������*/ , _int vertCount /*�������*/ , _int** edgelist /*�ߵļ���*/ , _int edgeCount /*�ߵĸ���*/ , bool hasdirect /*�Ƿ��з���*/);
	AdjacencyMatrixGraph();
	~AdjacencyMatrixGraph();
};

