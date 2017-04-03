// Polynomial.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory>

//使用单链表实现
typedef struct
{
	int coefficient;
	int index;
}Data;

typedef struct Lnode
{
	Data data;
	struct Lnode *next;
}LNode;

LNode *InitList();  //初始化一个空链表
void AddListNode(LNode *listHeadNode , int coefficient , int index);    //头插法链表添加节点函数
void ListSortByIndex(LNode *listHeadNode);     //多项式根据指数级排序
void ShowList(LNode *listHeadNode);    //输出多项式
LNode *AddBothList(LNode *listHeadNode1 , LNode *listHeadNode2);   //两个多项式相加
LNode *SubBothList(LNode *listHeadNode1 , LNode *listHeadNode2);   //两个多项式相减
LNode *MulBothList(LNode *listHeadNode1 , LNode *listHeadNode2);  //两个多项式相乘
int Evaluation(LNode *ListHead , int x);    //多项式求值
LNode *Derivation(LNode *listHeadNode);       //对多项式的求导

LNode *InitList()  //初始化一个空链表
{
	auto *listHead = static_cast<LNode *>(malloc(sizeof(LNode)));
	listHead->next = nullptr;
	return listHead;
}

void AddListNode(LNode *listHeadNode, int coefficient , int index)    //头插法链表添加节点函数
{
	auto *temp = listHeadNode;
	while (temp->next)
	{
		if (temp->next->data.index == index)
		{
			temp->next->data.coefficient += coefficient;
			if (temp->next->data.coefficient == 0)
			{
				temp->next = temp->next->next;
			}
			return;
		}
		temp = temp->next;
	}
	auto *newNode = static_cast<LNode *>(malloc(sizeof(LNode)));
	if (newNode)
	{
		newNode->data.coefficient = coefficient;
		newNode->data.index = index;
		newNode->next = listHeadNode->next;
		listHeadNode->next = newNode;
	}
}



void ListSortByIndex(LNode *listHeadNode)     //多项式根据指数级排序
{
	if (!listHeadNode->next) return;
	for (auto *temp = listHeadNode->next; temp->next; temp = temp->next)
	{
		for (auto *ttemp = listHeadNode->next; ttemp->next; ttemp = ttemp->next)
		{
			if (ttemp->next->data.coefficient == 0)
			{
				ttemp->next = ttemp->next->next;
			}
			if (ttemp->next->data.index < ttemp->data.index)
			{
				auto ttempDate = ttemp->next->data;
				ttemp->next->data = ttemp->data;
				ttemp->data = ttempDate;
			}
		}
	}
}


void ShowList(LNode *listHeadNode)    //输出多项式
{
	ListSortByIndex(listHeadNode);
	auto *temp = listHeadNode->next;
	if (!temp)
	{
		printf("0");
		return;
	}
	while (temp->next)
	{
		if (temp->data.index == 0)
		{
			printf("%d", temp->data.coefficient);
		}
		else if (temp->data.index == 1)
		{
			printf("%dX", temp->data.coefficient);
		}
		else
		{
			printf("%dX^%d", temp->data.coefficient, temp->data.index);
		}
		
		if (temp->next->data.coefficient > 0)
		{
			printf("+");
		}
		temp = temp->next;
	}
	if (temp->data.index == 0)
	{
		printf("%d", temp->data.coefficient);
	}
	else if (temp->data.index == 1)
	{
		printf("%dX", temp->data.coefficient);
	}
	else
	{
		printf("%dX^%d", temp->data.coefficient, temp->data.index);
	}
}


LNode *AddBothList(LNode *listHeadNode1, LNode *listHeadNode2)   //两个多项式相加
{
	auto *t2 = listHeadNode2->next , *t1 = listHeadNode1->next, *SumList = InitList();
	while (t1)
	{
		AddListNode(SumList, t1->data.coefficient, t1->data.index);
		t1 = t1->next;
	}
	while (t2)
	{
		AddListNode(SumList, t2->data.coefficient, t2->data.index);
		t2 = t2->next;
	}
	return SumList;
}

LNode *SubBothList(LNode *listHeadNode1, LNode *listHeadNode2)   //两个多项式相减
{
	auto *t2 = listHeadNode2->next, *t1 = listHeadNode1->next , *MulList = InitList();
	while (t1)
	{
		AddListNode(MulList, t1->data.coefficient, t1->data.index);
		t1 = t1->next;
	}
	while (t2)
	{
		AddListNode(MulList, (t2->data.coefficient)*-1 , t2->data.index);
		t2 = t2->next;
	}
	return MulList;
}

LNode *MulBothList(LNode *listHeadNode1, LNode *listHeadNode2)  //两个多项式相乘
{
	auto *MulList = InitList() , *t1 = listHeadNode1 , *t2 = listHeadNode2 ;
	while (t1->next)
	{
		t2 = listHeadNode2;
		while (t2->next)
		{
			AddListNode(MulList, t1->next->data.coefficient * t2->next->data.coefficient,
				t1->next->data.index + t2->next->data.index);
			t2 = t2->next;
		}
		t1 = t1->next;
	}
	return MulList;
}

int Evaluation(LNode *ListHead,int x)    //多项式求值
{
	auto sum = 0;
	auto *t = ListHead->next;
	while (t)
	{
		sum = sum + t->data.coefficient * pow(x, t->data.index);
		t = t->next;
	}
	return sum;
}

LNode *Derivation(LNode *listHeadNode)       //对多项式的求导
{
	ListSortByIndex(listHeadNode);
	// ReSharper disable once CppNonReclaimedResourceAcquisition
	auto *temp = listHeadNode , *tempList = static_cast<LNode *>(malloc(sizeof(LNode)));
	tempList = temp;
	while (temp->next)
	{
		if (temp->next->data.index > 0)
		{
			temp->data.coefficient *= temp->data.index;
			temp->data.index -= 1;
			temp = temp->next;
		}	
		else
		{
			temp->next = temp->next->next;
		}
	}
	if (temp->data.index > 0)
	{
		temp->data.coefficient *= temp->data.index;
		temp->data.index -= 1;
		temp = temp->next;
	}
	else
	{
		temp->next = temp->next->next;
	}
	return tempList;
}

int main()                                           //测试可用性
{
	int count,x,t;
	auto *HeadNode1 = InitList();
	// ReSharper disable once CppDeprecatedEntity
	scanf("%d\n", &count);
	for (auto i = 0 ; i < count; i++)
	{
		int number, poy;
		char temp1, temp2, temp3;
		// ReSharper disable once CppDeprecatedEntity
		scanf("%c%d%c%d%c",&temp1, &number,&temp2, &poy,&temp3);
		AddListNode(HeadNode1, number, poy);
	}
	// ReSharper disable once CppDeprecatedEntity
	scanf("%d",&x);
	printf("%d", Evaluation(HeadNode1, x));
	system("Pause");
    return 0;
}






