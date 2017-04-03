// DeleteCurPrevNode.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

typedef  struct ListNode
{
	int elem;
	struct ListNode *next;
}LNode;


void AddNode(LNode *curNode,int myElem)
{
	LNode *newNode = (LNode *)malloc(sizeof(LNode));
	newNode->elem = myElem;
	newNode->next = curNode->next;
	curNode->next = newNode;  
}

void DeleteCurPrevNode(LNode *CurNode)
{
	LNode *temp = CurNode;
	while (temp->next->next != CurNode)
	{
		temp = temp->next;
	}
	temp->next = temp->next->next;
}

void ShowList(LNode *CurNode)
{
	LNode *temp = CurNode;
	while (temp->next != CurNode)
	{
		printf("%d\n", temp->next->elem);
		printf("%d\n", CurNode->elem);
		system("Pause");
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	LNode *curNode = (LNode *)malloc(sizeof(LNode));
	curNode->elem = 0;
	curNode->next = curNode;
	AddNode(curNode, 1);
	DeleteCurPrevNode(curNode);
	ShowList(curNode);
	system("Pause");
    return 0;
}

