#pragma once
#include <memory>


class HuffmanTreeNode
{
public:
	char _data;         //数据
	int _weight;        //权值
	int _parent;        //双亲
	int _panlen;        //路径长
	int _lChild;        //左孩子
	int _rChild;        //右孩子
public:
	explicit HuffmanTreeNode(int _data , int _weight , int _parent , int _pathlen , int _lChild , int _rChild);
	HuffmanTreeNode() = default;
	~HuffmanTreeNode();
};

class HuffmanTree
{
	const int MAX_INT = INT_MAX;
private:
	HuffmanTreeNode** _huffman_tree_;
	int _node_number_ = 0;
private:
	void CreatHuffman(bool*& isCreated , int length) const;
	void _init_(string dataStr , int* weight_list) const;
	int GetTwoNumberAndReturnLength(int* &index_arr , bool*& isCreated) const;
	int IndexOf(const int weight , const bool* isCreated) const;
	int IndexOf(const int weight) const;
	void PrintTree(int root_index , int depth) const;
	void SetWeight(int root_index , int depth) const;
	void GetBinaryCode(int root_index , int parent_index , string &code , const char data , bool& flag) const;
public:
	explicit HuffmanTree(string data);                                                //读取报文,创建huffman树
	explicit HuffmanTree(string dataStr , int* weight_list);                          //创建huffman树
	~HuffmanTree();
	void PrintTree() const;                                                           //树状打印huffman树   
	int WPL() const;                                                                  //求WPL
	int Weight(const char data) const;                                                //求某个数据的权值
	int CodeLen(const char data) const;                                               //求字符的huffman编码长度，若不存在,返回0;
	string Binarycode(const char data) const;                                         //数据 -> huffman编码
	char DataByBinarycode(const string data) const;                                   //huffman -> 数据
	string Coding(string buf) const;                                                  //对string数据进行编码
	string Translate(string code) const;                                              //译码
	double AverageCodeLength() const;                                                 //求平均编码长度
};


//节点类的构造函数
inline HuffmanTreeNode::HuffmanTreeNode(int _data, int _weight , int _parent , int _pathlen , int _lChild , int _rChild)
	:_data(_data) , _weight(_weight) , _parent(_parent) , _panlen(_pathlen) , _lChild(_lChild) , _rChild(_rChild)
{

}

inline HuffmanTreeNode::~HuffmanTreeNode()
{
}

//递归创建哈夫曼树
inline void HuffmanTree::CreatHuffman(bool* &isCreated , int length) const
{
	if (length >= _node_number_)
	{
		return;
	}
	auto num = new int[2];
	num[0] = -1 , num[1] = -1;
	auto curLength = GetTwoNumberAndReturnLength(num , isCreated);
	if (num[0] == -1 || num[1] == -1) { delete[] num; return; }
	_huffman_tree_[curLength]->_weight = _huffman_tree_[num[0]]->_weight + _huffman_tree_[num[1]]->_weight;
	_huffman_tree_[curLength]->_panlen = _huffman_tree_[num[0]]->_weight + _huffman_tree_[num[1]]->_weight;;
	_huffman_tree_[curLength]->_lChild = num[0];
	_huffman_tree_[curLength]->_rChild = num[1];
	_huffman_tree_[num[0]]->_parent = curLength;
	_huffman_tree_[num[1]]->_parent = curLength;
	delete[] num;
	CreatHuffman(isCreated , length + 1);
}

inline void HuffmanTree::_init_(string dataStr, int* weight_list) const
{

	for (auto index = 0; index < dataStr.length(); index++)
	{
		_huffman_tree_[index] = new HuffmanTreeNode(dataStr[index] , weight_list[index] , -1 , -1 , -1 , -1);
	}
	for (auto index = dataStr.length(); index < _node_number_; index++)
	{
		_huffman_tree_[index] = new HuffmanTreeNode(NULL , MAX_INT , -1 , -1 , -1 , -1);
	}
	// ReSharper disable once CppNonReclaimedResourceAcquisition
	auto isCreated = new bool[_node_number_];
	for (auto i = 0; i < _node_number_; i++)
	{
		isCreated[i] = false;
	}
	CreatHuffman(isCreated , 1);
	delete[] isCreated;
	SetWeight(_node_number_ - 1 , 0);
}

inline int HuffmanTree::GetTwoNumberAndReturnLength(int*& index_arr , bool*& isCreated) const
{
	auto number_count = 0;
	for (auto i = 0; i < _node_number_ ; i++)
	{
		if (_huffman_tree_[i]->_weight != MAX_INT)
		{
			++number_count;
		}
		if (_huffman_tree_[i]->_weight && !isCreated[i])
		{
			if (index_arr[0] == -1)
			{
				index_arr[0] = i;
			}
			else
			{
				if (index_arr[1] == -1)
				{
					if (_huffman_tree_[i]->_weight < _huffman_tree_[index_arr[0]]->_weight/*/// missing something here  //*/)
					{
						index_arr[1] = index_arr[0];
						index_arr[0] = i;
					}
					else
					{
						index_arr[1] = i;
					}
				}
				else
				{
					if (_huffman_tree_[i]->_weight < _huffman_tree_[index_arr[0]]->_weight)
					{
						index_arr[1] = index_arr[0];
						index_arr[0] = i;
					}
					else if (_huffman_tree_[i]->_weight <  _huffman_tree_[index_arr[1]]->_weight && i != index_arr[0])
					{
						index_arr[1] = i;
					}
				}
			}
		}
	}
	if (index_arr[0] != -1)
	{
		isCreated[index_arr[0]] = true;
	}
	if (index_arr[1] != -1)
	{
		isCreated[index_arr[1]] = true;
	}
	//for (int j = 0; j < _node_number_; j++)
	//{
	//	cout << j << " : " << _huffman_tree_[j]->_data << " => " << _huffman_tree_[j]->_weight << "  " << isCreated[j] << endl;
	//}
	//system("Pause");
	return number_count;
}


inline int HuffmanTree::IndexOf(const int weight , const bool* isCreated) const
{
	for (auto i = 0; i < _node_number_; i++)
		if (_huffman_tree_[i]->_weight == weight && isCreated[i] == false) 
			return i;
	return -1;
}


inline int HuffmanTree::IndexOf(const int weight) const
{
	for (auto i = 0; i < _node_number_; i++)
		if (_huffman_tree_[i]->_weight == weight)
			return i;
	return -1;
}

inline void HuffmanTree::PrintTree(int root_index, int depth) const
{
	if (root_index >= _node_number_ || root_index < 0) return;
	PrintTree(_huffman_tree_[root_index]->_rChild , depth + 1);
	for (auto i = 0; i < depth; i++) cout << "      ";
	if (root_index < (_node_number_+1)/2)
	{
		cout << _huffman_tree_[root_index]->_weight  << endl;
	}
	else
	{
		cout << "  " << _huffman_tree_[root_index]->_weight << endl;
	}	
	PrintTree(_huffman_tree_[root_index]->_lChild , depth + 1);
}

inline void HuffmanTree::SetWeight(int root_index, int depth) const
{
	if (root_index >= _node_number_ || root_index < 0) return;
	SetWeight(_huffman_tree_[root_index]->_rChild , depth + 1);
	_huffman_tree_[root_index]->_panlen = depth;
	SetWeight(_huffman_tree_[root_index]->_lChild , depth + 1);
}

inline void HuffmanTree::GetBinaryCode(int root_index, int parent_index ,string& code , const char data , bool& flag) const
{
	if (root_index >= _node_number_ || root_index < 0 || flag) return;
	if (_huffman_tree_[root_index]->_data == data)
		flag = true;
	if (parent_index != -1)
	{
		if (_huffman_tree_[parent_index]->_lChild == root_index)
		{
			code += '0';
		}
		else
		{
			code += '1';
		}
	}
	GetBinaryCode(_huffman_tree_[root_index]->_lChild , root_index , code , data , flag);
	GetBinaryCode(_huffman_tree_[root_index]->_rChild , root_index , code , data , flag);
	if (!flag)
	{
			code = code.substr(0 , code.length() - 1);
	}

}

inline HuffmanTree::HuffmanTree(string data)
{
	string buf = " \n.ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";  //设置字符集
	auto list = new int[buf.length()];
	for (auto i = 0 ; i < buf.length(); i++)
	{
		list[i] = 0;
	}
	for (auto i = 0 ; i < data.length() ; i++)
	{
		if (data[i] <= 'Z' && data[i] >= 'A')
		{
			list[data[i] - 'A' + 3]++;
		}
		else if(data[i] <= 'z' && data[i] >= 'a')
		{
			list[data[i] - 68]++;
		}
		else if (data[i] == ' ')
		{
			list[0] ++;
		}
		else if (data[i] == '\n')
		{
			list[1] ++;
		}
		else if (data[i] == '.')
		{
			list[2] ++;
		}
	}
	string newStr;
	auto newList = new int[55];
	for (auto i = 0; i < buf.length(); i++)
	{
		if (list[i] > 0)
		{
			newStr += buf[i];
			newList[newStr.length() - 1] = list[i];
		}
	}
	_node_number_ = 2 * newStr.length() - 1;
	_huffman_tree_ = new HuffmanTreeNode*[_node_number_];
	_init_(newStr , newList);
	delete[] newList;
	delete[] list;
}

//哈夫曼树的构造函数
inline HuffmanTree::HuffmanTree(string dataStr , int* weight_list)
	:_huffman_tree_(new HuffmanTreeNode*[2 * dataStr.length() - 1]),_node_number_(2 * dataStr.length() - 1)
{
	_init_(dataStr , weight_list);
}

//哈夫曼树的析构函数  循环删除所有节点   最后删除树
inline HuffmanTree::~HuffmanTree()
{
	for (auto index = 0; index < _node_number_; index++)
	{
		delete _huffman_tree_[index];
	}
	delete _huffman_tree_;
}

inline void HuffmanTree::PrintTree() const
{
	PrintTree(_node_number_ - 1 , 0);
}

inline int HuffmanTree::WPL() const
{
	auto _WPL = 0;
	for (auto i = 0 ; i < (_node_number_+1)/2 ; i++)
	{
		_WPL += _huffman_tree_[i]->_weight * _huffman_tree_[i]->_panlen;
	}
	return _WPL;
}

inline int HuffmanTree::Weight(char data) const
{
	for (auto i = 0 ; i < (_node_number_+1)/2 ; i++)
	{
		if (_huffman_tree_[i]->_data == data)
		{
			return _huffman_tree_[i]->_weight;
		}
	}
	return MAX_INT;
}

inline int HuffmanTree::CodeLen(const char data) const
{
	for (auto i = 0; i < (_node_number_ + 1) / 2; i++)
	{
		if (_huffman_tree_[i]->_data == data)
		{
			return _huffman_tree_[i]->_panlen;
		}
	}
	return 0;
}

inline string HuffmanTree::Binarycode(char data) const
{
	string code = "";
	auto flag = false;
	GetBinaryCode(_node_number_ - 1 , -1 , code , data , flag);
	if (code == "") return "null";
	return code;
}

inline char HuffmanTree::DataByBinarycode(const string data) const
{

	auto root = _node_number_-1;
	for (auto i = 0 ; i < data.length() ; i++)
	{
		if (root >= _node_number_ || root < 0 || data[i] != '1' && data[i] != '0')
		{
			return '\0';
		}
		if (data[i] == '1')
		{
			
			root = _huffman_tree_[root]->_rChild;
		}
		else
		{
			root = _huffman_tree_[root]->_lChild;
		}
		if (root >= _node_number_ || root < 0 || data[i] != '1' && data[i] != '0')
		{
			return '\0';
		}
	}
	return _huffman_tree_[root]->_data;
}

inline string HuffmanTree::Coding(string buf) const
{
	string code = "";
	for (auto i = 0 ; i < buf.length() ; i++)
	{
		code += Binarycode(buf[i]);
	}
	return code;
}

inline string HuffmanTree::Translate(string code) const
{
	string finalBuf = "";
	string tempBuf = "";
	for (auto i = 0 ; i < code.length() ; i++)
	{
		tempBuf += code[i];
		auto t = DataByBinarycode(tempBuf);
		if (t != '\0')
		{
			tempBuf = "";
			finalBuf += t;
		}
	}
	return finalBuf;
}

inline double HuffmanTree::AverageCodeLength() const
{
	auto len = 0.0;
	auto sum_w = 0.0;
	for (auto i = 0; i < (_node_number_ + 1)/2 ; i++)
	{
		len += _huffman_tree_[i]->_panlen * _huffman_tree_[i]->_weight;
		sum_w += _huffman_tree_[i]->_weight;
	}
	return len / sum_w;
}
