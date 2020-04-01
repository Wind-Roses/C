#pragma once
#include<stdio.h>
#include<stdlib.h>

typedef int DataType;
typedef struct Node
{
	DataType data;
	struct Node* next;
}Node;
typedef struct LinkList
{
	Node* head;
}LinkList;

//初始化
void LinkListInit(LinkList* L);

//创建一个新节点
Node* CreateNewNode(DataType data);

//头插
void HeadPush(LinkList* L, DataType data);

//尾插
void TailPush(LinkList* L, DataType data);

//在pos之后插入节点
void LinkListInsert(Node* pos, DataType data);

//头删
void HeadPop(LinkList* L);

//尾删
void TailPop(LinkList* L);

//删除pos后的节点
void LinkListDelete(Node* pos);

//查找
Node* LinkListFind(LinkList* L, DataType data);

//打印
void LinkListPrint(LinkList* L);

//销毁
void LinkListDestroy(LinkList* L);

//删除链表中等于给定值 val 的所有节点
Node* removeElements(LinkList* L, int val);

//反转一个单链表
Node* reverseList(LinkList* L);

//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点
Node* middleNode(LinkList* L);

//输入一个链表，输出该链表中倒数第k个结点
Node* FindKthToTail(LinkList* L, unsigned int k);