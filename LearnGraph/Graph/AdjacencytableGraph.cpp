#include "AdjacencytableGraph.h"
#include <queue>
#include <stack>
#include <iostream>
#include <iterator>
#define MAX 2147483647

int AdjacencyTableGraph::IndexOf(_vertex* vert) const
{
	for (auto i = 0; i < m_vertCount; i++)
	{
		if (vert == m_verts[i])
		{
			return i;
		}
	}
	return -1;
}

void AdjacencyTableGraph::DFS(vert* root , std::string& result  , bool*& iscreated) const
{
	if (!root) return;
	result += root->_elem;
	iscreated[IndexOf(root)] = true;
	if (root->next_node)
	{
		for (auto t = root->next_node; t; t = t->next_node)
		{
			if (!iscreated[t->cur_node_index])
			{
				DFS(m_verts[t->cur_node_index] , result , iscreated);
			}
		}
	}
}

void AdjacencyTableGraph::NLC(vert* root, std::vector<std::string>&results , std::string& result, _int resultCount, bool*& iscreated) const
{
	if (!root) return;
	result += root->_elem;
	iscreated[IndexOf(root)] = true;
	if (root->next_node)
	{
		for (auto t = root->next_node; t; t = t->next_node)
		{
			/*std::cout << m_verts[t->cur_node_index]->_elem << " : " << result << std::endl;*/
			if (m_verts[t->cur_node_index]->_elem == result[0])
			{
				/*std::cout << m_verts[t->cur_node_index]->_elem << " : " << result << m_verts[t->cur_node_index]->_elem << std::endl;*/
				results.push_back(result);
				++resultCount;
			}
			if (!iscreated[t->cur_node_index])
			{
				NLC(m_verts[t->cur_node_index] , results, result ,resultCount, iscreated);
			}
		}
	}
}

template<typename T> void Swap(T &a , T&b) noexcept              //交换
{
	auto t = a;
	a = b;
	b = t;
}

////////////////////这段代码写完之后我已经不想看了/////////////////////
int AdjacencyTableGraph::MST(int* weightForVert , int weightForVertCount) const
{
	if (m_vertCount != weightForVertCount)
	{
		std::cout << "error";
		return 0;
	}

	auto weight = new std::vector<int>;
	auto mSet = new std::vector<std::vector<vert*>*>;
	auto setNumber = 0;
	for (auto i = 0 ; i < m_vertCount ; ++i)
	{
		if (m_verts[i]->next_node)
		{
			for (auto t = m_verts[i]->next_node; t; t = t->next_node)
			{
				auto tv = new std::vector<vert*>();
				tv->push_back(m_verts[i]);
				tv->push_back(m_verts[t->cur_node_index]);
				weight->push_back(t->weight);
				mSet->push_back(tv);
			}
		}		
	}
	
	for (auto i = 0 ; i < weight->size() ; ++i)
	{
		for (auto j = 0 ; j < weight->size() - i - 1 ; ++ j)
		{
			if ((*weight).at(j) >(*weight).at(j+1))
			{
				Swap((*weight).at(j+1) , (*weight).at(j));
				Swap((*mSet).at(j+1) , (*mSet).at(j));
			}
		}
	}

	for (auto i = 1 ; i < weight->size() ; ++i)
	{
		for (auto j = 0 ; j <= setNumber ; ++j)
		{
			if (std::find((*mSet).at(j)->begin() , (*mSet).at(j)->end() , (*(*mSet).at(i))[0]) == (*mSet).at(j)->end() &&
				std::find((*mSet).at(j)->begin() , (*mSet).at(j)->end() , (*(*mSet).at(i))[1]) == (*mSet).at(j)->end())
			{
				++setNumber;
				Swap((*mSet).at(setNumber) , (*mSet).at(i));
				break;
			}
			else if(std::find((*mSet).at(j)->begin() , (*mSet).at(j)->end() , (*(*mSet).at(i))[0]) == (*mSet).at(j)->end() ||
				std::find((*mSet).at(j)->begin() , (*mSet).at(j)->end() , (*(*mSet).at(i))[1]) == (*mSet).at(j)->end())
			{
				(*mSet).at(j)->push_back(std::find((*mSet).at(j)->begin() , (*mSet).at(j)->end() , (*(*mSet).at(i))[0]) == (*mSet).at(j)->end() ? (*(*mSet).at(i))[0] : (*(*mSet).at(i))[1]);
				(*weight).at(j) += (*weight).at(i);
				(*weight).at(i) = MAX;
				break;
			}
		}
	}

	
	for (auto i = 1 ; i < setNumber ; ++i)
	{
		for (auto j = 0 ; j < (*mSet).at(i)->size() ; ++j)
		{
			if (std::find((*mSet).at(0)->begin() , (*mSet).at(0)->end() , (*(*mSet).at(i))[j]) != (*mSet).at(0)->end())
			{
				std::for_each((*mSet).at(i)->cbegin() , (*mSet).at(i)->cend() , [&](vert* obj)
				{
					(*mSet).at(0)->push_back(obj);
				});
				break;
			}
		}
	}
	


	//以下为题目专用代码
	auto maxIndex = 0;
	for (auto i = setNumber + 1; i < weight->size(); ++i)
	{
		if((*weight).at(i) != MAX)
		{
			maxIndex = i;
			break;
		}
	}

	std::cout << maxIndex << std::endl;
	for (auto i = setNumber + 2 ; i < weight->size() ; ++i)
	{
		//std::cout << (*weight)[i] << " " << (*mSet)[i]->size() << std::endl; //" " << weightForVert[IndexOf((*(*mSet)[maxIndex])[0])];
		if ((*weight)[i] != MAX && (*weight)[i] > (*weight)[maxIndex] && (*mSet)[i]->size() == 2 && weightForVert[IndexOf((*(*mSet)[i])[0])] > 0 && weightForVert[IndexOf((*(*mSet)[i])[1])] > 0)
		{
			maxIndex = i;
		}
		/*if ((*weight)[i] != MAX && )
		{
			
		}*/
	}


	(*weight)[0] = (*weight)[0] - (*weight)[maxIndex] + weightForVert[IndexOf((*(*mSet)[maxIndex])[0])] + weightForVert[IndexOf((*(*mSet)[maxIndex])[1])];
	//以上为题目专用代码

	for (auto i = 0 ; i < weight->size() ; ++i)
	{
		std::cout << "[";
		for (auto j = 0 ; j < (*mSet)[i]->size() ; ++j)
		{
			std::cout << " " << (*(*mSet)[i])[j]->_elem;
		}
		std::cout << "]" << " : w[" << i << "] = " << (*weight)[i] << std::endl;
	}

	return (*weight)[0];
}

std::string AdjacencyTableGraph::TPS() const
{
	auto s = new std::stack<vert*>();
	auto degree = new int[m_vertCount];
	for (auto i = 0; i < m_vertCount; ++i)
	{
		degree[i] = m_verts[i]->in_degree;
	}
	//for(auto i = 0 ; i < m_vertCount ; ++i)
	//{
	//	std::cout << degree[i] << " ";
	//}
	std::string result = "";
	for (auto i = 0; i < m_vertCount; ++i)
	{
		if (degree[i] == 0)
		{
			s->push(m_verts[i]);
			degree[i] = -1;
			while (!s->empty())
			{
				auto tmp = s->top();
				s->pop();
				result += tmp->_elem;
				if (tmp->next_node)
				{
					for (auto t = tmp->next_node ; t ; t = t->next_node)
					{
						if (degree[t->cur_node_index] != -1)
						{
							--degree[t->cur_node_index];
							if (degree[t->cur_node_index] == 0)
							{
								s->push(m_verts[t->cur_node_index]);
								degree[t->cur_node_index] = -1;
							}
						}
					}
				}
			}
		}

	}

	delete[] degree;
	delete s;
	return result;
}

std::string AdjacencyTableGraph::BFS() const
{
	std::string result = "";
	auto isVisted = new bool[m_vertCount];
	for (auto i = 0; i < m_vertCount; i++)
	{
		isVisted[i] = false;
	}
	auto q = new std::queue<vert*>();
	for (auto i = 0; i < m_vertCount; i++)
	{
		if (!isVisted[i])
		{
			q->push(m_verts[i]);
			isVisted[i] = true;
			while (!q->empty())
			{
				auto t = q->front();
				q->pop();
				result += t->_elem;
				if (t->next_node)
				{
					for (auto tmp = t->next_node; tmp; tmp = tmp->next_node)
					{
						if (!isVisted[tmp->cur_node_index])
						{
							q->push(m_verts[tmp->cur_node_index]);
							isVisted[tmp->cur_node_index] = true;
						}
					}
				}
			}
		}
	}
	delete[] isVisted;
	delete q;
	return result;
}

std::string AdjacencyTableGraph::DFS() const
{
	std::string result = "";
	auto iscreated = new bool[m_vertCount];
	for (auto i = 0; i < m_vertCount; i++)
	{
		iscreated[i] = false;
	}
	for (auto i = 0; i < m_vertCount; i++)
	{
		if (!iscreated[i])
		{
			DFS(m_verts[i] , result  , iscreated);
		}
	}
	delete[] iscreated;
	return result;
}

int AdjacencyTableGraph::UCT() const
{
	std::string result = "";
	auto iscreated = new bool[m_vertCount];
	auto count = 0;
	for (auto i = 0; i < m_vertCount; i++)
	{
		iscreated[i] = false;
	}
	for (auto i = 0; i < m_vertCount; i++)
	{
		if (!iscreated[i])
		{
			++count;
			DFS(m_verts[i] , result, iscreated);
		}
	}

	delete[] iscreated;
	return count;
}

std::vector<std::string> AdjacencyTableGraph::NLC() const
{
	std::vector<std::string> results;
	std::string result;
	auto resultCount = 0;
	auto iscreated = new bool[m_vertCount];
	for (auto i = 0; i < m_vertCount; i++)
	{
		result = "";
		for (auto j = 0; j < m_vertCount; j++)
		{
			iscreated[j] = false;
		}
		NLC(m_verts[i], results , result , resultCount, iscreated);
	}


	delete[] iscreated;
	return results;
}

int AdjacencyTableGraph::Distance(vert* vertf, vert* vertt, bool*& isVisted , bool& isFound) const
{
	if (isFound) return 0;
	auto max = 0;
	if (vertf->next_node)
	{
		for (auto t = vertf->next_node; t; t = t->next_node)
		{
			if (!isVisted[t->cur_node_index])
			{
				isVisted[t->cur_node_index] = true;
				auto distance = Distance(m_verts[t->cur_node_index] , vertt , isVisted , isFound) + t->weight;
				max = max > distance ? max : distance;
			}
			if (m_verts[t->cur_node_index] == vertt)
			{
				isFound = true;
				return t->weight;				
			}
		}
	}
	return max;
}

//所有点与点之间的最长路径
int AdjacencyTableGraph::MLP() const
{
	auto lengths = new int*[m_vertCount];
	for (auto i = 0; i < m_vertCount; ++i)            //初始化
	{
		lengths[i] = new int[m_vertCount];
		for (auto j = 0; j < m_vertCount; ++j)
		{
			lengths[i][j] = 0;
		}
	}
	auto is_visted = new bool[m_vertCount];
	bool isFound;
	for (auto i = 0 ; i < m_vertCount ; ++i)
	{
		for (auto j = i + 1; j < m_vertCount ; ++j)
		{
			for (auto k = 0 ; k < m_vertCount ; k++)
			{
				is_visted[k] = false;
			}
			isFound = false;
			lengths[i][j] = Distance(m_verts[i] , m_verts[j] , is_visted , isFound);       //递归求两点间的最长关键距离
		}
	}

	auto maxLength = lengths[0][0];
	for (auto i = 0 ; i < m_vertCount ; ++i)
	{
		for (auto j = i + 1 ; j < m_vertCount ; ++j)
		{
			if (maxLength < lengths[i][j])
			{
				maxLength = lengths[i][j];
			}
		}
	}
	return maxLength;
}

int AdjacencyTableGraph::InDegreeOf(const _elem_t data) const
{
	for (auto i = 0; i < m_vertCount; ++i)
	{
		if (m_verts[i]->_elem == data)
		{
			return m_verts[i]->in_degree;
		}
	}
	return -1;
}

int AdjacencyTableGraph::OutDeGreeOf(const _elem_t data) const
{
	for (auto i = 0; i < m_vertCount; ++i)
	{
		if (m_verts[i]->_elem == data)
		{
			return m_verts[i]->out_degree;
		}
	}
	return -1;
}

AdjacencyTableGraph::AdjacencyTableGraph(std::string verts , int vertCount , _int** edges , int edgeCount , bool hasdirect)
	:m_vertCount(vertCount)
{
	auto flag = false;
	m_verts = new vert*[vertCount];
	for (auto i = 0; i < vertCount; i++)
	{
		m_verts[i] = new vert;
		m_verts[i]->_elem = verts.c_str()[i];
		m_verts[i]->next_node = nullptr;
		m_verts[i]->in_degree = 0;
		m_verts[i]->out_degree = 0;
	}


	for (auto i = 0; i < edgeCount; i++)
	{
		//std::cout << edges[i][0] << "=>" << edges[i][1] << std::endl;
		auto tnode = new tableNode;
		tnode->weight = edges[i][2];
		tnode->cur_node_index = edges[i][1];
		tnode->next_node = nullptr;
		auto tmp = m_verts[edges[i][0]]->next_node;

		if (!tmp)
		{
			m_verts[edges[i][0]]->next_node = tnode;
			m_verts[edges[i][0]]->out_degree++;
			m_verts[edges[i][1]]->in_degree++;
		}
		else
		{
			while (tmp->next_node)
			{
				if (tmp->next_node->cur_node_index == edges[i][1])
				{
					flag = true;
					break;
				}
				tmp = tmp->next_node;
			}
			if (flag)
			{
				delete tnode;
			}
			else
			{
				tmp->next_node = tnode;
				m_verts[edges[i][0]]->out_degree++;
				m_verts[edges[i][1]]->in_degree++;
			}
		}

		flag = false;
		if (!hasdirect)
		{
			auto ttnode = new tableNode;
			ttnode->weight = edges[i][2];
			ttnode->cur_node_index = edges[i][0];
			ttnode->next_node = nullptr;
			auto ttmp = m_verts[edges[i][1]]->next_node;

			if (!ttmp)
			{
				m_verts[edges[i][1]]->next_node = ttnode;
				m_verts[edges[i][1]]->out_degree++;
				m_verts[edges[i][0]]->in_degree++;
			}
			else
			{
				while (ttmp->next_node)
				{
					if (ttmp->next_node->cur_node_index == edges[i][0])
					{
						flag = true;
						break;
					}
					ttmp = ttmp->next_node;
				}
				if (flag)
				{
					delete ttnode;
				}
				else
				{
					ttmp->next_node = ttnode;
					m_verts[edges[i][1]]->out_degree++;
					m_verts[edges[i][0]]->in_degree++;
				}
			}


		}
	}
	//////调试
	//for (int i = 0; i < m_vertCount; ++i)
	//{
	//	std::cout << m_verts[i]->out_degree << " " << m_verts[i]->in_degree << std::endl;
	//	auto t = m_verts[i]->next_node;
	//	std::cout << m_verts[i]->_elem;
	//	while (t)
	//	{
	//		std::cout << " -> " << m_verts[t->cur_node_index]->_elem;
	//		t = t->next_node;
	//	}
	//	system("Pause");
	//}
}

AdjacencyTableGraph::AdjacencyTableGraph()
	: m_verts(nullptr) , m_vertCount(0)
{
}

AdjacencyTableGraph::~AdjacencyTableGraph()
{
	for (auto i = 0; i < m_vertCount; i++)
	{
		auto tmp = m_verts[i]->next_node;
		while (tmp)
		{
			auto t = tmp;
			tmp = tmp->next_node;
			delete t;
		}
		delete m_verts[i];
	}
	delete m_verts;
}
