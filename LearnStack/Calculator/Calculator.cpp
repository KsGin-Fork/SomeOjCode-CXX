/*
 *Created 2016 10 14
 *Author:Yangfan
 *Email:imqqyangfan@gmail.com
 *Github:https://www.Github.com/Amnnny
 */

#include "stack.h"            //自实现栈
#include <string>
#include <iostream>
#include <ccomplex>
using namespace std;
Stack<char> operator_stack;      //定义运算符栈
Stack<double> number_stack;      //定义数据栈
char32_t operators[] = { '+' , '-' , '*' , '/' , '(' , ')' };
int32_t list_operators[6][6] =                                 ///符号优先级对照表  1表示优先级大于  
{
		0 , 0 , -1 , -1 , -1 , -1 ,
		0 , 0 , -1 , -1 , -1 , -1 ,
		1 , 1 ,  0 ,  0 , -1 , -1 ,
		1 , 1 ,  0 ,  0 , -1 , -1 ,
		1 , 1 ,  1 ,  1 ,  0 ,  0 ,
		1 , 1 ,  1 ,  1 ,  0 ,  0
};

string Input();
int ParseStr(string &str , string buf_string[]);
double StrToDouble(string str);
int AnalyzingPriority(char operator1 , char operator2);
double Compute(string buf_string[] , int len);
double ComPuteBase(double num1 , char oper , double num2);
void SetNumber();

///输入字符串(无空格)
string Input()
{
	cout << "Please input a Expression:";
 	auto str = make_shared<string>();
	cin >> *str;
	return *str;
}

///解析字符串 转化为string数组 ex:{"32.3" ,"+" ,"4"}
int ParseStr(string& str , string buf_string[])
{
	auto index = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if ((str[i] <= '9' && str[i] >= '0') || str[i] == '.')
		{
			buf_string[index] += str[i];
		}
		else
		{
			if (i > 0)
			{
				index++;
			}
			buf_string[index] = str[i];
			if (str[i + 1] <= '9' && str[i + 1] >= '0')
			{
				index++;
			}
		}
	}
	return index + 1;
}

///根据字符串格式获得double数据
double StrToDouble(string str)
{
	double integer = 0 ,                  //定义整数部分
		decimal = 0;                   //定义小数部分
	int point_index = str.length();       //定义小数点的位置
	for (size_t j = 0; j < str.length(); j++)          //找到小数点的位置
	{
		if (str[j] == '.')
		{
			point_index = j;
			break;
		}
	}
	if (point_index != str.length())                          //计算小数部分
	{
		for (size_t i = point_index + 1; i < str.length(); i++)
		{
			decimal += (str[i] - '0')*pow(10 , point_index - i);
		}
	}
	for (auto i = point_index - 1; i >= 0; i--)                //计算整数部分
	{
		integer += (str[i] - '0')*pow(10 , point_index - i - 1);
	}
	return integer + decimal;
}

///分析操作符优先级
int AnalyzingPriority(char operator1 , char operator2)     //分析操作符优先级
{
	auto j = -1 , k = -1;
	for (auto i = 0; i < 6; i++)
	{
		if (operator1 == operators[i]) j = i;
		if (operator2 == operators[i]) k = i;
	}
	return list_operators[j][k];
}

///提取两个数据栈里的数据和一个操作符数据进行计算，并且将结果压入数据栈
void SetNumber()
{
	auto temp_oper = operator_stack.top();
	operator_stack.pop();
	auto num1 = number_stack.top();
	number_stack.pop();
	auto num2 = number_stack.top();
	number_stack.pop();
	number_stack.push(ComPuteBase(num2 , temp_oper , num1));
}

///对分析好的字符串数组进行计算
double Compute(string buf_string[] , int len)
{
	for (auto i = 0; i < len; i++)
	{
		if (buf_string[i].length() > 1 || buf_string[i][0] <= '9' && buf_string[i][0] >= '0')   //如果是数字  将其转化为数字之后压入栈中
		{
			number_stack.push(StrToDouble(buf_string[i]));
		}
		else   //如果不是
		{
			if (buf_string[i][0] == ')')     //如果当前运算符为')'
			{
				while (operator_stack.top() != '(')
				{
					SetNumber();
				}
				operator_stack.pop();
			}
			else if (operator_stack.empty() || operator_stack.top() == '(' || buf_string[i][0] == '(' || AnalyzingPriority(operator_stack.top() , buf_string[i][0]) == -1)
			{
				operator_stack.push(buf_string[i][0]);         //如果栈为空或者操作符优先级大于栈顶操作符或者在'('之后或者为'('则入栈
			}
			else
			{
				//栈顶运算符优先级大于等于当前运算符
				while (AnalyzingPriority(operator_stack.top() , buf_string[i][0]) != -1)
				{
					SetNumber();
					operator_stack.push(buf_string[i][0]);
					break;
				}
			}
		}
	}
	while (!operator_stack.empty())     //如果栈不为空  
	{
		SetNumber();
	}
	return number_stack.top();
}

///基本计算
double ComPuteBase(double num1 , char oper , double num2)
{
	auto result = 0.0;
	switch (oper)
	{
		case '+':result = num1 + num2; break;
		case '-':result = num1 - num2; break;
		case '*':result = num1 * num2; break;
		case '/':
			if (num2 == 0)
			{
				puts("出现错误!除数为0");
				system("Pause");
				exit(-1);
			}
			result = num1 / num2;
			break;
		default:break;
	}
	return result;
}

int main(int argc , char* argv[])
{
	//_CrtSetBreakAlloc(175);
	// ReSharper disable once CppMsExtAddressOfClassRValue
	auto str = Input();
	auto bufs = new string[100];
	auto len = ParseStr(str , bufs);
	cout << Compute(bufs , len) << endl;
	delete []bufs;
	operator_stack.Destory();
	number_stack.Destory();
	_CrtDumpMemoryLeaks();
	system("Pause");
	return 0;
}
