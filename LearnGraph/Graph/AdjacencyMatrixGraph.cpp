#include "AdjacencyMatrixGraph.h"
#include <stack>
#include <string>

void AdjacencyMatrixGraph::_Init_(std::string verlist , _int vertCount /*�������*/ , _int** edgelist , _int edgeCount , bool hasdirect)
{
	m_hasdirect = hasdirect;
	m_vertexCount = vertCount;
	m_vertexs = new _vertex*[m_vertexCount];
	for (auto i = 0; i < m_vertexCount; i++)
	{
		m_vertexs[i] = new _vertex;
		m_vertexs[i]->_elem = verlist.c_str()[i];
		m_vertexs[i]->in_degree = 0;
		m_vertexs[i]->out_degree = 0;
	}
	if (m_hasdirect)                                    //������� �� �򴴽���Ӧ�����Ĺ�ϵ����
	{
		m_edgeCount = edgeCount;
		m_edges = new _edge*[edgeCount];
	}
	else                                              //������� �� �򴴽���Ӧ���������Ĺ�ϵ����
	{
		m_edgeCount = edgeCount * 2;
		m_edges = new _edge*[edgeCount * 2];
	}
	for (auto i = 0; i < (m_hasdirect ? m_edgeCount : (m_edgeCount / 2)); i++)
	{
		m_edges[i] = new _edge;
		m_edges[i]->_f = m_vertexs[edgelist[i][0]];
		m_edges[i]->_s = m_vertexs[edgelist[i][1]];
		//����
		m_edges[i]->_weight = 0;
		++m_edges[i]->_f->out_degree;
		++m_edges[i]->_s->in_degree;
	}
	if (!m_hasdirect)
	{
		for (auto i = m_edgeCount / 2; i < m_edgeCount; i++)
		{
			m_edges[i] = new _edge;
			m_edges[i]->_f = m_vertexs[edgelist[i - m_edgeCount / 2][1]];
			m_edges[i]->_s = m_vertexs[edgelist[i - m_edgeCount / 2][0]];
			++m_edges[i - m_edgeCount / 2]->_f->in_degree;
			++m_edges[i - m_edgeCount / 2]->_s->out_degree;
		}
	}

	//std::cout << m_vertexs[0]->in_degree << " " << m_vertexs[0]->out_degree << std::endl;

	/*for (auto i = 0 ; i < m_edgeCount ; i++)
	{
		std::cout << m_edges[i]->_f->_elem << " -> " << m_edges[i]->_s->_elem << std::endl;
		system("Pause");
	}*/
}

void AdjacencyMatrixGraph::DFS(_vertex* vert , std::string& GetResult , bool*& isVisted) const
{
	if (!vert) return;
	GetResult += vert->_elem;
	isVisted[IndexOf(vert)] = true;
	for (auto i = 0; i < m_edgeCount; i++)
	{
		if (m_edges[i]->_f == vert && !isVisted[IndexOf(m_edges[i]->_s)])
		{
			DFS(m_edges[i]->_s , GetResult , isVisted);
		}
	}
}

Graph::_int AdjacencyMatrixGraph::IndexOf(const _vertex* vert) const
{
	for (auto i = 0; i < m_vertexCount; i++)
	{
		if (vert == m_vertexs[i])
		{
			return i;
		}
	}
	return -1;
}



int AdjacencyMatrixGraph::UCT() const
{

	auto isVisted = new bool[m_vertexCount];
	std::string result = "";
	auto count = 0;
	for (auto i = 0; i < m_vertexCount; i++)
	{
		isVisted[i] = false;
	}
	for (auto i = 0; i < m_vertexCount; ++i)
	{
		if (!isVisted[i])
		{
			++count;
			DFS(m_vertexs[i] , result , isVisted);
		}
	}

	delete[] isVisted;
	return count;
}



std::string AdjacencyMatrixGraph::TPS() const
{
	if (!m_hasdirect) return "";               //����ͼֱ�ӷ���
	std::string result;
	auto s = new std::stack<_vertex*>;
	auto _degree = new _int[m_vertexCount];
	for (auto i = 0; i < m_vertexCount; ++i)
	{
		_degree[i] = m_vertexs[i]->in_degree;
	}


	for (auto i = 0; i < m_vertexCount; ++i)
	{
		if (_degree[i] == 0)
		{
			_degree[i] = -1;
			s->push(m_vertexs[i]);
			while (!s->empty())
			{
				auto tmp = s->top();
				s->pop();
				result += tmp->_elem;
				for (auto j = 0; j < m_edgeCount; ++j)
				{
					if (m_edges[j]->_f == tmp && _degree[IndexOf(m_edges[j]->_s)] != -1)
					{
						--_degree[IndexOf(m_edges[j]->_s)];
						if (_degree[IndexOf(m_edges[j]->_s)] == 0)
						{
							s->push(m_edges[j]->_s);
							_degree[IndexOf(m_edges[j]->_s)] = -1;
						}
					}
				}
			}
		}
	}

	delete[] _degree;
	delete s;

	return result;
}

std::string AdjacencyMatrixGraph::DFS() const
{
	auto isVisted = new bool[m_vertexCount];
	std::string result = "";
	for (auto i = 0; i < m_vertexCount; i++)
	{
		isVisted[i] = false;
	}
	for (auto i = 0; i < m_vertexCount; ++i)
	{
		if (!isVisted[i])
		{
			DFS(m_vertexs[i] , result , isVisted);
		}
	}

	delete[] isVisted;
	return result;
}

std::string AdjacencyMatrixGraph::BFS() const
{
	if (!m_vertexCount) return "";                                      //�п�
	std::string result = "";                             //��������������
	// ReSharper disable once CppNonReclaimedResourceAcquisition
	auto q = new queue();                                                 //new  ����
	auto isVisted = new bool[m_vertexCount];                              //���� isVisted[]����
	for (auto i = 0; i < m_vertexCount; i++)                            //��ʼ������
	{
		isVisted[i] = false;
	}
	for (auto index = 0; index < m_vertexCount; ++index) {
		if (!isVisted[index])
		{
			q->push(m_vertexs[index]);                                                //��ͷ�ڵ����
			isVisted[index] = true;                                                   //��ӵ�ʱ���޸��Ƿ����ֵ
			while (!q->empty())
			{
				auto tmp = q->front();                                            //ȡ������ͷԪ��
				result += tmp->_elem;
				q->pop();
				//isVisted[IndexOf(tmp)] = true;
				for (auto j = 0; j < m_edgeCount; j++)                          //ѭ�����ұ߹�ϵ�������ҵ�ǰ�ڵ�Ĺ�ϵ�ڵ㲢�����
				{
					//std::cout << m_edges[j]->_f->_elem << " => " << m_edges[j]->_s->_elem << std::endl;
					if (m_edges[j]->_f == tmp && !isVisted[IndexOf(m_edges[j]->_s)])
					{
						q->push(m_edges[j]->_s);
						isVisted[IndexOf(m_edges[j]->_s)] = true;
					}
				}
			}
		}
	}
	delete q;
	delete[] isVisted;
	return result;
}

int AdjacencyMatrixGraph::InDegreeOf(const _elem_t data) const
{
	for (auto i = 0; i < m_vertexCount; ++i)
	{
		if (m_vertexs[i]->_elem == data)
		{
			return m_vertexs[i]->in_degree;
		}
	}
	return -1;
}

int AdjacencyMatrixGraph::OutDeGreeOf(const _elem_t data) const
{
	for (auto i = 0; i < m_vertexCount; ++i)
	{
		if (m_vertexs[i]->_elem == data)
		{
			return m_vertexs[i]->out_degree;
		}
	}
	return -1;
}

AdjacencyMatrixGraph::AdjacencyMatrixGraph(std::string verlist , _int vertCount /*�������*/ , _int** edgelist , _int edgeCount , bool hasdirect)             //����ͼ
{
	_Init_(verlist , vertCount , edgelist , edgeCount , hasdirect);        //��ʼ��ͼ
}

AdjacencyMatrixGraph::AdjacencyMatrixGraph()
{
}

AdjacencyMatrixGraph::~AdjacencyMatrixGraph()
{
	for (auto i = 0; i < m_vertexCount; i++)
	{
		delete m_vertexs[i];
	}
	for (auto i = 0; i < m_edgeCount; i++)
	{
		delete m_edges[i];
	}
	delete m_vertexs;
	delete m_edges;
}
