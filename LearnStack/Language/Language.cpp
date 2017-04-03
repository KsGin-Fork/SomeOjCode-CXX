/*
*Created 2016 10 18
*Author:Yangfan
*Email:imqqyangfan@gmail.com
*Github:https://www.Github.com/Amnnny
*/
#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
#include <unordered_map>
#include <sstream>
#include <memory>

using namespace std;
shared_ptr<unordered_map<char , string>> rule_map = make_shared<unordered_map<char , string>>();                  //制定映射表表(如:A->sae B->tAdA)
shared_ptr<stack<char>> m_stack = make_shared<stack<char>>();                                   //建立栈

///为魔王语言翻译添加映射  使用哈希表
void AddRule(char beel_lan , string human_lan)    
{
	if (rule_map->count(beel_lan) > 0)
	{
		cout << beel_lan << "的规则已经制定" << endl;
		return;
	}
	rule_map->insert(unordered_map<char,string>::value_type(beel_lan , human_lan));       //使用insert插入
}

///查找魔王语言映射表，查找映射(找到返回对应字符串，没找到返回原值)
string FindRule(char beel_lan)
{
	if (rule_map->count(beel_lan) == 0)    //如果表中没有这个字符，则将他原样返回
	{
		auto stream = make_shared<stringstream>();
		*stream << static_cast<char>(beel_lan+32);
		return stream->str();
	}
	return rule_map->find(beel_lan)->second;         //如果有，返回他对应的值
}

///(θδ1δ2…δn)→θδnθδn-1…θδ1θ 将字符串按照规则2来转换
string Explanation(string beel)            
{
	string humen = "";
	for (int i = beel.length()-1 ; i > 0; --i)
	{
		humen += beel[0];
		humen += beel[i];
	}
	humen += beel[0];
	return humen;
}
///删除某项映射
void Remove(char beel_lin)             
{
	rule_map->erase(beel_lin);
}

///递归执行规则一
void BeelToHumen(char beel_lan)
{
	auto t_string = FindRule(beel_lan);
	for (size_t j = 0; j < t_string.length(); j++)
	{
		if (t_string[j] >= 'A' && t_string[j] <= 'Z')
		{
			BeelToHumen(t_string[j]);
		}
		else
		{
			m_stack->push(t_string[j]);
		}
	}
}

///翻译魔王语言
void Translate(string beel_buf)
{
	for (size_t i = 0 ; i < beel_buf.length() ; i++)
	{
		if ((beel_buf[i] < 'A' || beel_buf[i] > 'Z' || beel_buf[i] == '(') && beel_buf[i] != ')')   //如果不属于要转换的字符  则入栈
		{
			m_stack->push(beel_buf[i]);
		}
		else if (beel_buf[i] == ')')                     //如果是后半括号则提取括号内部的字符进行规则二转换
		{
			string t_string = "";
			while (m_stack->top() != '(')                         //提取括号内的字符串
			{
				auto stream = make_shared<stringstream>();
				*stream << m_stack->top();
				t_string.insert(0 , stream->str());
				m_stack->pop();
			}
			m_stack->pop();
			t_string = Explanation(t_string);
			for (auto it = t_string.begin() ; it != t_string.end() ; ++it)
			{
				m_stack->push(*it);
			}
		}
		else                          //属于大写A->Z范围的进行规则一转换
		{
			BeelToHumen(beel_buf[i]);
		}
	}
}

///提取栈中的字符组成串输出
void OutPut()
{
	string out_str = "";
	while (!m_stack->empty())
	{
		auto stream = make_shared<stringstream>();
		*stream << m_stack->top();
		out_str.insert(0 ,stream->str());
		m_stack->pop();
	}
	cout << out_str;
}


int main(int argc, char* argv[])
{
	//_CrtSetBreakAlloc(164);
	string beel_buf;
	AddRule('A' , "sae");
	AddRule('B' , "tAdA");
	cout << "Please input a string:";
	cin >> beel_buf;
	Translate(beel_buf);
	OutPut();
	_CrtDumpMemoryLeaks();
	system("Pause");
	return 0;
}
