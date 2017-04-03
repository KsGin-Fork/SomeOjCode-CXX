#pragma once
#include <memory>
#include <iostream>
#include <sstream>
#include <stack>
#include <queue>
using namespace std;

template<typename T>
class BinaryTree
{
private:
	typedef struct node
	{
		T data;
		shared_ptr<struct node> lChild;
		shared_ptr<struct node> rChild;
	}t_node_;
private:
	shared_ptr<t_node_> root_node_;
	static bool CreatNode(shared_ptr<t_node_> node , string buffer_data , int buf_index);
	static void PrintNode(shared_ptr<t_node_> node , int depth_t_);
	void GetTreeByPre(shared_ptr<t_node_> root , stringstream &ss) const;
	void GetTreeByMid(shared_ptr<t_node_> root , stringstream &ss) const;
	void GetTreeByAft(shared_ptr<t_node_> root , stringstream &ss) const;
	void GetTreeByPreNotRecursive(shared_ptr<t_node_> root , stringstream &ss) const;
	void GetTreeByMidNotRecursive(shared_ptr<t_node_> root , stringstream &ss) const;
	void GetTreeByAftNotRecursive(shared_ptr<t_node_> root , stringstream &ss) const;
	void GetTreeLeafNode(shared_ptr<t_node_> root , stringstream &ss) const;
	void GetTreeByLevel(shared_ptr<t_node_> root , stringstream &ss) const;
	void GetTreeNodeAndNodeLevel(shared_ptr<t_node_> root , stringstream &ss , int level) const;
	void GetTreeNodeByLevel(shared_ptr<t_node_> root , stringstream &ss , int curlevel , const int level) const;
	void GetPathFromRootToLeaf(shared_ptr<t_node_> root , stringstream &ss , stringstream &buf) const;
	void GetPathFromRootToNode(shared_ptr<t_node_> root , const T data , string &ss , bool& flag) const;
	int GetLeafNodeNumberByLevel(shared_ptr<t_node_> root , int curlevel , const int level) const;
	int GetNumOfNode(shared_ptr<t_node_> root) const;
	int GetNumOfLeaf(shared_ptr<t_node_> root) const;
	int GetNumberOfNodeForDegreeIsTwo(shared_ptr<t_node_> root) const;
	int GetDepth(shared_ptr<t_node_> root , int number) const;
	void CreateTreeByPreOrder(shared_ptr<t_node_> root , char nullCh);
	bool BinaryLike(shared_ptr<t_node_> t1_root_ , shared_ptr<t_node_> t2_root_);
	void SwapChildTree(shared_ptr<t_node_> t1_root_);
	void CreatedTreeByPreAndIn(string buf1 , string buf2 , shared_ptr<node> &root);
	void CreatedTreeByInAndAft(string buf1 , string buf2 , shared_ptr<node> &root);
	T GetRecentCommonAncestor(T a , T b , shared_ptr<node> root) const;
public:
	// ReSharper disable once CppDeclarationSpecifierWithoutDeclarators
	const enum Order {
		Preorder = 1 ,
		Inorder = 2 ,
		Aftorder = 3
	};
	explicit BinaryTree();
	explicit BinaryTree(char nullCh);                                      //������չ�������д����ַ���(nullChΪ�п��ַ�)
	explicit BinaryTree(string buf);                                       //�����ַ�����δ���������
	explicit BinaryTree(string buf1 , string buf2 , Order orderF , Order orderS); //���������������������򴴽���
	~BinaryTree();
public:
	string AllTreeNode(Order order) const;                                 //����ö��ֵ�������������(���к�)
	string TreeLeafNode() const;                                           //���Ҷ�ӽڵ�
	string AllTreeNodeNotRecursive(Order order) const;                     //����ö��ֵ�������������(���к�)(�ǵݹ����)
	string TreeByLevel() const;                                            //�Զ�Ԫ����ʽ����ڵ�(�ڵ�����,�ڵ�����)
	string TreeNodeAndNodeLevel() const;                                   //���ָ������εĽ��
	string TreeNodeByLevel(const int level) const;                         //���ָ������ε�Ҷ�ӽ��
	string PathFromRootToLeaf() const;                                     //��ӡ���ڵ㵽����Ҷ�ӽڵ��·��
	int Depth() const;                                                     //����������
	int NumberOfNode() const;                                              //������Ľڵ����
	int NumberOfLeaf() const;                                              //�������Ҷ�ӽ�����
	int NumberOfNodeForDegreeIsTwo() const;                                //������Ķ�Ϊ2�Ľڵ����
	int LeafNodeNumberByLevel(const int level) const;                      //���ָ������ε�Ҷ�ӽ�����
	void PrintTree() const;                                                //����״��̬��ӡ��
	void Clear();                                                          //�����
	void Destory();                                                        //������
	bool Equals(const shared_ptr<BinaryTree> &tree);                       //�ж��������
	void GetRoot(shared_ptr<t_node_> &root);                               //������ĸ��ڵ�
	bool Like(shared_ptr<BinaryTree> tree);                                //�ж���������
	void SwapChildTree();                                                  //�������������������ݹ齻����
	T RecentCommonAncestor(const T a , const T b) const;                   //��a �� b���ڽڵ�������ͬ����
};


//�ַ���ͨ����δ���������
template<typename T>
bool BinaryTree<T>::CreatNode(shared_ptr<t_node_> node , string buffer_data , int buf_index)
{
	if (buffer_data[buf_index - 1] != '#')
	{
		node->data = buffer_data[buf_index - 1];
	}
	node->lChild = nullptr;
	node->rChild = nullptr;
	if ((2 * buf_index) <= static_cast<int>(buffer_data.length()))
	{
		node->lChild = std::make_shared<t_node_>();;
		CreatNode(node->lChild , buffer_data , 2 * buf_index);
	}

	if ((2 * buf_index + 1) <= static_cast<int>(buffer_data.length()))
	{
		node->rChild = std::make_shared<t_node_>();;
		CreatNode(node->rChild , buffer_data , 2 * buf_index + 1);
	}
	return true;
}

//�չ��캯������������
template<typename T>
BinaryTree<T>::BinaryTree()
{
	root_node_ = std::make_shared<t_node_>();
	root_node_->data = ' ';
}
//ʹ��"��չ�����������"������������
template<typename T>
inline BinaryTree<T>::BinaryTree(char nullCh)
{
	root_node_ = std::make_shared<t_node_>();
	CreateTreeByPreOrder(root_node_ , nullCh);
}

//��������
template<typename T>
BinaryTree<T>::~BinaryTree()
{
	root_node_.reset();
}

//����ö�ٲ���������ַ���
template<typename T>
string BinaryTree<T>::AllTreeNode(Order order) const
{
	auto ss = make_shared<stringstream>();
	switch (order)
	{
		case Preorder:GetTreeByPre(root_node_ , *ss); break;
		case Inorder: GetTreeByMid(root_node_ , *ss); break;
		case Aftorder:GetTreeByAft(root_node_ , *ss); break;
		default: break;
	}
	return ss->str();
}

template <typename T>
string BinaryTree<T>::TreeLeafNode() const
{
	auto ss = make_shared<stringstream>();
	GetTreeLeafNode(root_node_ , *ss);
	return ss->str();
}

template <typename T>
string BinaryTree<T>::AllTreeNodeNotRecursive(Order order) const
{
	auto ss = make_shared<stringstream>();
	switch (order)
	{
		case Preorder:GetTreeByPreNotRecursive(root_node_ , *ss); break;
		case Inorder: GetTreeByMidNotRecursive(root_node_ , *ss); break;
		case Aftorder:GetTreeByAftNotRecursive(root_node_ , *ss); break;
		default: break;
	}
	return ss->str();
}

template <typename T>
string BinaryTree<T>::TreeByLevel() const
{
	auto ss = make_shared<stringstream>();
	GetTreeByLevel(root_node_ , *ss);
	return ss->str();
}

template <typename T>
string BinaryTree<T>::TreeNodeAndNodeLevel() const
{
	auto ss = make_shared<stringstream>();
	GetTreeNodeAndNodeLevel(root_node_ , *ss , 1);
	return ss->str();
}

template <typename T>
string BinaryTree<T>::TreeNodeByLevel(const int level) const
{
	auto ss = make_shared<stringstream>();
	GetTreeNodeByLevel(root_node_ , *ss , 1 , level);
	return ss->str();
}

template <typename T>
string BinaryTree<T>::PathFromRootToLeaf() const
{
	auto ss = make_shared<stringstream>();
	auto buf = make_shared<stringstream>();
	GetPathFromRootToLeaf(root_node_ , *ss , *buf);
	return buf->str();
}


//�ó��������߶�
template<typename T>
int BinaryTree<T>::Depth() const
{
	return GetDepth(root_node_ , 0);
}
//�ó����ڵ����
template<typename T>
int BinaryTree<T>::NumberOfNode() const
{
	return GetNumOfNode(root_node_);
}
//�ó���Ҷ�ӽڵ����
template<typename T>
int BinaryTree<T>::NumberOfLeaf() const
{
	return GetNumOfLeaf(root_node_);
}

template <typename T>
int BinaryTree<T>::NumberOfNodeForDegreeIsTwo() const
{
	return GetNumberOfNodeForDegreeIsTwo(root_node_);
}

template <typename T>
int BinaryTree<T>::LeafNodeNumberByLevel(const int level) const
{
	return GetLeafNodeNumberByLevel(root_node_ , 1 , level);
}

//��״��ӡ������
template<typename T>
inline void BinaryTree<T>::PrintTree() const
{
	PrintNode(root_node_ , 0);
}

template<typename T>
inline void BinaryTree<T>::Clear()
{
	root_node_.reset();
	root_node_ = make_shared<t_node_>();
}

template<typename T>
inline void BinaryTree<T>::Destory()
{
	root_node_.reset();
}

template<typename T>
inline bool BinaryTree<T>::Equals(const shared_ptr<BinaryTree<T>> &tree)
{
	if (tree->AllTreeNode(Preorder) != this->AllTreeNode(Preorder)
		|| tree->AllTreeNode(Inorder) != this->AllTreeNode(Inorder))
		return false;
	return true;
}

template<typename T>
inline void BinaryTree<T>::GetRoot(shared_ptr<t_node_> &root)
{
	root = root_node_;
}

template<typename T>
inline bool BinaryTree<T>::Like(shared_ptr<BinaryTree> tree)
{
	auto tptr = make_shared<t_node_>();
	tree->GetRoot(tptr);
	return BinaryLike(this->root_node_ , tptr);
}

template <typename T>
void BinaryTree<T>::SwapChildTree()
{
	SwapChildTree(root_node_);
}

template <typename T>
T BinaryTree<T>::RecentCommonAncestor(const T a ,const T b) const
{
	return GetRecentCommonAncestor(a , b , root_node_);
}

//��״��ӡ������
template<typename T>
void BinaryTree<T>::PrintNode(shared_ptr<t_node_> node , int depth_t_)
{
	if (!node.get() || !node->data) return;
	PrintNode(node->rChild , depth_t_ + 1);
	for (auto i = 0; i < depth_t_; i++)
		std::cout << "     ";
	std::cout << node->data << std::endl;
	PrintNode(node->lChild , depth_t_ + 1);
}

//�õ�ǰ��ڵ��ַ���
template<typename T>
void BinaryTree<T>::GetTreeByPre(shared_ptr<t_node_> root , stringstream &ss) const
{
	if (!root.get() || !root->data) return;
	ss << root->data;
	GetTreeByPre(root->lChild , ss);
	GetTreeByPre(root->rChild , ss);
}

//�õ�����ڵ��ַ���
template<typename T>
void BinaryTree<T>::GetTreeByMid(shared_ptr<t_node_> root , stringstream &ss) const
{
	if (!root.get() || !root->data) return;
	GetTreeByMid(root->lChild , ss);
	ss << root->data;
	GetTreeByMid(root->rChild , ss);
}

//�õ�����ڵ��ַ���
template<typename T>
void BinaryTree<T>::GetTreeByAft(shared_ptr<t_node_> root , stringstream &ss) const
{
	if (!root.get() || !root->data) return;
	GetTreeByAft(root->lChild , ss);
	GetTreeByAft(root->rChild , ss);
	ss << root->data;
}

template <typename T>
void BinaryTree<T>::GetTreeByPreNotRecursive(shared_ptr<t_node_> root , stringstream& ss) const
{
	shared_ptr<stack<shared_ptr<node>>> _stack = make_shared<stack<shared_ptr<node>>>();
	while (root.get() && root->data || !_stack->empty())
	{
		while (root.get() && root->data)
		{
			ss << root->data;
			_stack->push(root);
			root = root->lChild;
		}
		if (!_stack->empty())
		{
			root = _stack->top();
			_stack->pop();
			root = root->rChild;
		}
	}
}

template <typename T>
void BinaryTree<T>::GetTreeByMidNotRecursive(shared_ptr<t_node_> root , stringstream& ss) const
{
	shared_ptr<stack<shared_ptr<node>>> _stack = make_shared<stack<shared_ptr<node>>>();
	while (root.get() && root->data || !_stack->empty())
	{
		while (root.get() && root->data)
		{
			_stack->push(root);
			root = root->lChild;
		}
		if (!_stack->empty())
		{
			root = _stack->top();
			_stack->pop();
			ss << root->data;
			root = root->rChild;
		}
	}
}

template <typename T>
void BinaryTree<T>::GetTreeByAftNotRecursive(shared_ptr<t_node_> root , stringstream& ss) const
{
	shared_ptr<stack<shared_ptr<node>>> _stack = make_shared<stack<shared_ptr<node>>>();
	shared_ptr<node> tmp_node_ = make_shared<node>();
	while (root.get() && root->data || !_stack->empty())
	{
		while (root.get() && root->data)
		{
			_stack->push(root);
			root = root->lChild;
		}
		if (!_stack->empty())
		{
			root = _stack->top();
			if (!(root->rChild.get() && root->rChild->data) || root->rChild == tmp_node_)
			{
				_stack->pop();
				ss << root->data;
				tmp_node_ = root;
				root.reset();
			}
			else
			{
				root = root->rChild;
			}

		}
	}
}

template <typename T>
void BinaryTree<T>::GetTreeLeafNode(shared_ptr<t_node_> root , stringstream& ss) const
{
	if (!root.get() || !root->data) return;
	if (((root->lChild.get() && root->lChild->data) && (root->rChild.get() && root->rChild->data)))
	{
		ss << root->data;
	}
	GetTreeLeafNode(root->lChild , ss);
	GetTreeLeafNode(root->rChild , ss);
}

template <typename T>
void BinaryTree<T>::GetTreeByLevel(shared_ptr<t_node_> root , stringstream& ss) const
{
	// ReSharper disable once CppNonReclaimedResourceAcquisition
	auto _queue = make_shared<queue<shared_ptr<node>>>();
	if (root.get() && root->data) _queue->push(root);
	while (!_queue->empty())
	{
		root = _queue->front();
		_queue->pop();
		ss << root->data;
		if (root->lChild.get() && root->lChild->data)
		{
			_queue->push(root->lChild);
		}
		if (root->rChild.get() && root->rChild->data)
		{
			_queue->push(root->rChild);
		}
	}
}

template <typename T>
void BinaryTree<T>::GetTreeNodeAndNodeLevel(shared_ptr<t_node_> root , stringstream& ss , int level) const
{
	if (!root.get() || !root->data) return;
	ss << "(" << root->data << "," << level << ")";
	GetTreeNodeAndNodeLevel(root->lChild , ss , level + 1);
	GetTreeNodeAndNodeLevel(root->rChild , ss , level + 1);
}

template <typename T>
void BinaryTree<T>::GetTreeNodeByLevel(shared_ptr<t_node_> root , stringstream& ss , int curlevel , const int level) const
{
	if (!root.get() || !root->data) return;
	if (curlevel == level)
	{
		ss << root->data;
	}
	GetTreeNodeByLevel(root->lChild , ss , curlevel + 1 , level);
	GetTreeNodeByLevel(root->rChild , ss , curlevel + 1 , level);
}

//����1
template <typename T>
void BinaryTree<T>::GetPathFromRootToLeaf(shared_ptr<t_node_> root , stringstream& ss , stringstream& buf) const
{
	if (!root.get() || !root->data) return;
	if ((!root->lChild.get() || !root->lChild->data) && (!root->rChild.get() || !root->rChild->data))
	{
		auto str = ss.str().substr(0 , ss.str().length());
		ss.str("");
		ss << str << '\0';
		buf << root->data << ":" << ss.str() << "\r\n";
	}
	else
	{
		ss << root->data;
		GetPathFromRootToLeaf(root->lChild , ss , buf);
		GetPathFromRootToLeaf(root->rChild , ss , buf);
	}
	string str = ss.str().substr(0 , ss.str().length() - 1);
	ss.str("");
	ss << str;
}

template <typename T>
void BinaryTree<T>::GetPathFromRootToNode(shared_ptr<t_node_> root , const T data , string &ss , bool& flag) const
{
	if (!root.get() || !root->data) return;
	if ( root->data == data)
	{
		//ss += root->data;  ���Ȳ���������ڵ�  ������������д���ȡ��ע�ͼ���
		flag = true;
	}
	if (!flag)
	{
		ss += root->data;
	}
	GetPathFromRootToNode(root->lChild , data , ss , flag);
	GetPathFromRootToNode(root->rChild , data , ss , flag);
	if (!flag)
	{
		ss = ss.substr(0 , ss.length() - 1);
	}
}

template <typename T>
int BinaryTree<T>::GetLeafNodeNumberByLevel(shared_ptr<t_node_> root , int curlevel , const int level) const
{
	if (!root.get() || !root->data) return 0;
	if (curlevel == level && (!root->lChild.get() && !root->rChild.get() || !root->lChild->data && !root->rChild->data))
		return 1;
	return GetLeafNodeNumberByLevel(root->lChild , curlevel + 1 , level)
		+ GetLeafNodeNumberByLevel(root->rChild , curlevel + 1 , level);
}

//�ó����ڵ����
template<typename T>
int BinaryTree<T>::GetNumOfNode(shared_ptr<t_node_> root) const
{
	if (!root.get() || !root->data) return 0;
	int lnumber = GetNumOfNode(root->lChild);
	int rnumber = GetNumOfNode(root->rChild);
	return lnumber + rnumber + 1;
}
//�ó���Ҷ�ӽڵ����
template<typename T>
int BinaryTree<T>::GetNumOfLeaf(shared_ptr<t_node_> root) const
{
	if (!root.get() || !root->data)  return 0;
	if (((root->lChild.get() && root->lChild->data) && (root->rChild.get() && root->rChild->data))) return 1;
	return GetNumOfLeaf(root->lChild) + GetNumOfLeaf(root->rChild);
}

template <typename T>
int BinaryTree<T>::GetNumberOfNodeForDegreeIsTwo(shared_ptr<t_node_> root) const
{
	if (!root.get() || !root->data)  return 0;
	int lnumber = GetNumberOfNodeForDegreeIsTwo(root->lChild);
	int rnumber = GetNumberOfNodeForDegreeIsTwo(root->rChild);
	if (((root->lChild.get() && root->lChild->data) && (root->rChild.get() && root->rChild->data)))
		return lnumber + rnumber + 1;
	return lnumber + rnumber;
}

template<typename T>
inline int BinaryTree<T>::GetDepth(shared_ptr<t_node_> root , int number) const
{
	if (!root.get() || !root->data) return number;
	int lnumber = GetDepth(root->lChild , number + 1);
	int rnumber = GetDepth(root->rChild , number + 1);
	return lnumber > rnumber ? lnumber : rnumber;
}

template<typename T>
inline void BinaryTree<T>::CreateTreeByPreOrder(shared_ptr<t_node_> root , char nullCh)
{
	char elem;
	std::cin >> elem;
	if (elem == nullCh) root._Reset();
	else
	{
		root->data = elem;
		root->lChild = make_shared<t_node_>();
		CreateTreeByPreOrder(root->lChild , nullCh);
		root->rChild = make_shared<t_node_>();
		CreateTreeByPreOrder(root->rChild , nullCh);
	}
}

template<typename T>
inline bool BinaryTree<T>::BinaryLike(shared_ptr<t_node_> t1_root_ , shared_ptr<t_node_> t2_root_)
{
	if (!t1_root_.get() && !t2_root_.get()) return true;
	if (!t1_root_.get() && t2_root_.get() || t1_root_.get() && !t2_root_.get()) return false;
	return BinaryLike(t1_root_->lChild , t2_root_->lChild) && BinaryLike(t1_root_->rChild , t2_root_->rChild);
}

template <typename T>
void BinaryTree<T>::SwapChildTree(shared_ptr<t_node_> root)
{
	if (!root.get() || !root->data) return;
	auto tmp = root->rChild;
	root->rChild = root->lChild;
	root->lChild = tmp;
	SwapChildTree(root->lChild);
	SwapChildTree(root->rChild);
}

template <typename T>
void BinaryTree<T>::CreatedTreeByPreAndIn(string buf1 , string buf2 , shared_ptr<node> &root)
{
	if (buf1.length() != buf2.length() || buf1.length() <= 0) return;
	root = make_shared<node>();
	root->data = buf1[0];
	auto i = 0;
	for (; i < buf1.length(); i++)
	{
		if (buf2[i] == buf1[0]) break;
	}
	CreatedTreeByPreAndIn(buf1.substr(1 , buf2.substr(0 , i).length()) , buf2.substr(0 , i) , root->lChild);
	CreatedTreeByPreAndIn(buf1.substr(i + 1) , buf2.substr(i + 1) , root->rChild);
}

template <typename T>
void BinaryTree<T>::CreatedTreeByInAndAft(string buf1 , string buf2 , shared_ptr<node> &root)
{
	if (buf1.length() != buf2.length() || buf1.length() <= 0) return;
	root = make_shared<node>();
	root->data = buf2[buf1.length() - 1];
	auto i = 0;
	for (; i < buf1.length(); i++)
	{
		if (buf1[i] == buf2[buf2.length() - 1]) break;
	}
	CreatedTreeByInAndAft(buf1.substr(0 , i) , buf2.substr(0 , buf1.substr(0 , i).length()) , root->lChild);
	CreatedTreeByInAndAft(buf1.substr(i + 1) , buf2.substr(buf2.length() - buf1.substr(i + 1).length() - 1 , buf1.substr(i + 1).length()) , root->rChild);
}

template <typename T>
T BinaryTree<T>::GetRecentCommonAncestor(T a , T b , shared_ptr<node> root) const
{
	auto ss1 = make_shared<string>();
	auto flag1 = false , flag2 = false;
	GetPathFromRootToNode(root_node_ , a , *ss1 , flag1);
	auto ss2 = make_shared<string>();
	GetPathFromRootToNode(root_node_ , b , *ss2 , flag2);
	for (auto i = 0; i < (ss1->length() > ss2->length() ? ss2->length() : ss1->length()); i++)
	{
		if (ss1->length() > (i + 1 && ss2->length() > i + 1 && (*ss1)[i + 1] == (*ss2)[i + 1]))
		{
			continue;
		}
		return (*ss1)[i];
	}
	return (*ss1)[(ss1->length() > ss2->length() ? ss2->length() : ss1->length()) - 1];
}

//ʹ���ַ�����ʼ����(��α�����ʼ��)  *ע�⣺�˴����ַ�����ǰ���ַ�����ͬ
template<typename T>
BinaryTree<T>::BinaryTree(string buf)
{
	root_node_ = std::make_shared<t_node_>();
	root_node_->lChild = nullptr;
	root_node_->rChild = nullptr;
	CreatNode(root_node_ , buf , 1);
}

template <typename T>
BinaryTree<T>::BinaryTree(string buf1 , string buf2 , Order orderF , Order orderS)
{
	if (orderF == Preorder && orderS == Inorder)
	{
		CreatedTreeByPreAndIn(buf1 , buf2 , root_node_);
	}
	else if (orderF == Inorder && orderS == Aftorder)
	{
		CreatedTreeByInAndAft(buf1 , buf2 , root_node_);
	}
	else
	{
		cout << "����˳����������,��ʹ�� ��+�� ���� ��+��";
	}
}

