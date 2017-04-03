#pragma once
#include <xstring>

class Graph
{
public:
	virtual ~Graph()
	{

	}

protected:
	//////////////////////////////////���������ض���///////////////////////////////
	typedef __int32 _int;
	typedef char32_t _char;
	typedef char _elem_t;
	//////////////////////////////////�ߺͶ������ݽṹ����//////////////////////////
	class _vertex
	{
	public:
		_int out_degree;      //����
		_int in_degree;       //���
		_elem_t _elem;        //����Ԫ��
	};             //���㶨��

	class _edge
	{
	public:
		_vertex *_f;
		_vertex *_s;
		_int _weight;
	};             //�� 
protected:
	virtual std::string DFS() const = 0;
	virtual std::string BFS() const = 0;
	virtual std::string TPS() const = 0;
	virtual int UCT() const = 0;
};

