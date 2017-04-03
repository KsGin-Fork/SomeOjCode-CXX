#pragma once
#include <memory>
#include <string>



//孩子兄弟节点法树
template<typename T>
class Tree
{
private:
	struct t_node_
	{
		T _data;
		std::shared_ptr<t_node_> _first_child_;        //此节点的第一个孩子节点
		std::shared_ptr<t_node_> _next__sibling_;      //此节点的下一个兄弟节点
	};
private:
	std::shared_ptr<t_node_> _root_node_;
	int GetNumberOfLeaf(std::shared_ptr<t_node_> root /*根*/) const;
	int GetDepth(shared_ptr<t_node_> root /*根*/) const;
public:
	Tree();
	void Clear();
	bool Empty() const;
	int Depth() const;
	int NumberOfNode() const;
	int NumberOfLeaf() const;
	T* GetAllNodeByPre() const;
	T* GetAllNodeByAft() const;
};

template<typename T>
inline int Tree<T>::GetNumberOfLeaf(std::shared_ptr<t_node_> root /*根*/) const
{
	if (!root || !root.get() || !root->_weight) return 0;
	if (!root || !root->_first_child_.get() || !root->_first_child_->_weight) return 1;
	int count = GetNumberOfLeaf(root->_first_child_);
	for (auto tmp_ = root->_next__sibling_ ; tmp_.get() ; tmp_ = tmp_->_next__sibling_)
	{
		count += GetNumberOfLeaf(tmp_);
	}
	return count;
}

template<typename T>
inline int Tree<T>::GetDepth(shared_ptr<t_node_> root) const
{
	if (!root || !root.get() || !root->_weight) return 0;
	if (!root || !root->_first_child_.get()) return 1;
	int count = GetDepth(root->_first_child_);
	for (auto tmp_ = root->_next__sibling_; tmp_.get(); tmp_ = tmp_->_next__sibling_)
	{
		int tmp = GetDepth(tmp_);
		count = tmp > count ? tmp : count;
	}
	return count+1;
}

//初始化空树
template<typename T>
inline Tree<T>::Tree()
{
	_root_node_ = std::make_shared<t_node_>();
	_root_node_->_weight = 'A';
	_root_node_->_next__sibling_ = nullptr;
	auto tmp = make_shared<t_node_>();
	tmp->_weight = 'B';
	_root_node_->_first_child_ = tmp;
	auto tt = make_shared<t_node_>();
	tt->_weight = 'G';
	tmp->_next__sibling_ = tt;
	tt->_next__sibling_ = nullptr;
	auto ttt = make_shared<t_node_>();
	ttt->_weight = 'G';
	tmp->_next__sibling_ = ttt;
	ttt->_next__sibling_ = nullptr;
	auto tttt = make_shared<t_node_>();
	ttt->_weight = 'G';
	ttt->_first_child_ = tttt;
	auto ttttt = make_shared<t_node_>();
	ttt->_weight = 'G';
	tmp->_next__sibling_ = ttttt;
	tttt->_next__sibling_ = nullptr;
	auto tttttt = make_shared<t_node_>();
	ttt->_weight = 'G';
	tmp->_next__sibling_ = tttttt;
	auto ttttttt = make_shared<t_node_>();
	ttt->_weight = 'G';
	tmp->_next__sibling_ = ttttttt;
	ttttttt->_next__sibling_ = nullptr;
}

template<typename T>
inline void Tree<T>::Clear()
{
}

template<typename T>
inline bool Tree<T>::Empty() const
{
	return false;
}

template<typename T>
inline int Tree<T>::Depth() const
{
	return GetDepth(_root_node_);
}

template<typename T>
inline int Tree<T>::NumberOfNode() const
{
	return 0;
}

template<typename T>
inline int Tree<T>::NumberOfLeaf() const
{
	return GetNumberOfLeaf(_root_node_);
}

template<typename T>
inline T * Tree<T>::GetAllNodeByPre() const
{
	return NULL;
}

template<typename T>
inline T * Tree<T>::GetAllNodeByAft() const
{
	return NULL;
}
