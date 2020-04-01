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

//��ʼ��
void LinkListInit(LinkList* L);

//����һ���½ڵ�
Node* CreateNewNode(DataType data);

//ͷ��
void HeadPush(LinkList* L, DataType data);

//β��
void TailPush(LinkList* L, DataType data);

//��pos֮�����ڵ�
void LinkListInsert(Node* pos, DataType data);

//ͷɾ
void HeadPop(LinkList* L);

//βɾ
void TailPop(LinkList* L);

//ɾ��pos��Ľڵ�
void LinkListDelete(Node* pos);

//����
Node* LinkListFind(LinkList* L, DataType data);

//��ӡ
void LinkListPrint(LinkList* L);

//����
void LinkListDestroy(LinkList* L);

//ɾ�������е��ڸ���ֵ val �����нڵ�
Node* removeElements(LinkList* L, int val);

//��תһ��������
Node* reverseList(LinkList* L);

//����һ������ͷ��� head �ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ����м���
Node* middleNode(LinkList* L);

//����һ����������������е�����k�����
Node* FindKthToTail(LinkList* L, unsigned int k);