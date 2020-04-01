#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkList_test.h"

//初始化
void LinkListInit(LinkList* L)
{
	L->head = NULL;
}

//创建一个新节点
Node* CreateNewNode(DataType data)
{
	Node* node = (Node*)malloc(sizeof(Node));

	node->data = data;
	node->next = NULL;

	return node;
}

//头插
void HeadPush(LinkList* L, DataType data)
{
	Node* node = CreateNewNode(data);

	if (L->head == NULL)
	{
		L->head = node;
	}
	else
	{
		node->next = L->head;
		L->head = node;
	}
}

//尾插
void TailPush(LinkList* L, DataType data)
{
	Node* node = CreateNewNode(data);

	if (L->head == NULL)
	{
		L->head = node;
	}
	else
	{
		Node* p = L->head;

		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = node;
	}
}

//在pos之后插入节点
void LinkListInsert(Node* pos, DataType data)
{
	if (pos == NULL)
	{
		return;
	}

	Node* node = CreateNewNode(data);

	node->next = pos->next;
	pos->next = node;
}

//头删
void HeadPop(LinkList* L)
{
	if (L->head != NULL)
	{
		Node* p = L->head;

		L->head = p->next;
		free(p);
	}
}

//尾删
void TailPop(LinkList* L)
{
	if (L->head != NULL)
	{
		Node* tail = L->head;
		Node* p = NULL;

		while (tail->next != NULL)
		{
			p = tail;
			tail = tail->next;
		}

		if (p == NULL)
		{
			L->head = NULL;
		}
		else
		{
			p->next = NULL;
		}
		
		free(tail);
	}
}

//删除pos后的节点
void LinkListDelete(Node* pos)
{
	if (pos == NULL)
	{
		return;
	}

	if (pos->next != NULL)
	{
		Node* p = pos->next;

		pos->next = p->next;
		free(p);
	}
}

//查找
Node* LinkListFind(LinkList* L, DataType data)
{
	if (L->head == NULL)
	{
		return NULL;
	}

	Node* p = L->head;

	while (p != NULL)
	{
		if (p->data == data)
		{
			return p;
		}
		
		p = p->next;
	}

	return NULL;
}

//打印
void LinkListPrint(LinkList* L)
{
	Node* p = L->head;

	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//销毁
void LinkListDestroy(LinkList* L)
{
	Node* p = L->head;
	Node* q = NULL;

	if (p != NULL)
	{
		q = p;
		p = p->next;
		free(q);
	}
}

//删除链表中等于给定值 val 的所有节点
Node* removeElements(LinkList* L, int val)
{
	if (L->head == NULL)
	{
		return NULL;
	}


	Node* p = L->head;
	Node* q = NULL;


	while (p != NULL)
	{
		if (p->data == val)
		{
			struct ListNode* next = p->next;
			if (q == NULL)
			{
				L->head = next;
			}
			else
			{
				q->next = next;
			}
			free(p);
			p = next;
		}
		else
		{
			q = p;
			p = p->next;
		}
	}


	return L->head;
}

//反转一个单链表
Node* reverseList(LinkList* L)
{
	if (L->head == NULL || L->head->next == NULL)
	{
		return L->head;
	}


	Node* p = NULL;
	Node* q = L->head;


	while (q)
	{
		Node* next = q->next;
		next = q->next;
		q->next = p;
		p = q;
		q = next;
	}


	return p;
}

//给定一个带有头结点 head 的非空单链表，返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点
Node* middleNode(LinkList* L)
{
	Node* fast = L->head;
	Node* slow = L->head;


	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}


	return slow;
}

//输入一个链表，输出该链表中倒数第k个结点
Node* FindKthToTail(LinkList* L, unsigned int k)
{
	Node* slow = L->head;
	Node* fast = L->head;

	while (k)
	{
		if (fast == NULL)
		{
			return NULL;
		}
		else
		{
			fast = fast->next;
		}

		k--;
	}

	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}

	return slow;
}