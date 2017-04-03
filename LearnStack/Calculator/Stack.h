#pragma once
#include <memory>

template<typename T> class Stack
{
private:
    typedef struct node
	{
		T data;
		std::shared_ptr<struct node> next;
	}s_node_;
private:
	std::shared_ptr<s_node_> base;
public:
	explicit Stack();
	~Stack();
	void push(T data);
	void pop();
	bool empty();
	T top();
	void Destory();
};

template <typename T>
Stack<T>::Stack()
{
	base = std::make_shared<s_node_>();
	base->next = nullptr;
}

template <typename T>
Stack<T>::~Stack()
{
	base.reset();
}

template <typename T>
void Stack<T>::push(T data)
{
	std::shared_ptr<struct node> t_node = std::make_shared<s_node_>();
	t_node->data = data;
	t_node->next = base->next;
	base->next = t_node;
}

template <typename T>
void Stack<T>::pop()
{
	if (empty()) return;
	std::shared_ptr<struct node> t = base->next;
	base->next = base->next->next;
	t.reset();
}

template <typename T>
bool Stack<T>::empty()
{
	if (!base->next)	return true;
	return false;
}

template <typename T>
T Stack<T>::top()
{
	if (empty()) return false;
	return base->next->data;
}

template<typename T>
inline void Stack<T>::Destory()
{
	base.reset();
}
