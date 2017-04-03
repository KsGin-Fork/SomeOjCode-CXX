#pragma once
#include <xstring>

class Graph
{
public:
	virtual ~Graph()
	{

	}

protected:
	//////////////////////////////////数据类型重定义///////////////////////////////
	typedef __int32 _int;
	typedef char32_t _char;
	typedef char _elem_t;
	//////////////////////////////////边和顶点数据结构定义//////////////////////////
	class _vertex
	{
	public:
		_int out_degree;      //出度
		_int in_degree;       //入度
		_elem_t _elem;        //数据元素
	};             //顶点定义

	class _edge
	{
	public:
		_vertex *_f;
		_vertex *_s;
		_int _weight;
	};             //边 
protected:
	virtual std::string DFS() const = 0;
	virtual std::string BFS() const = 0;
	virtual std::string TPS() const = 0;
	virtual int UCT() const = 0;
};

