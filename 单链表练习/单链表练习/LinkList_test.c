#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkList_test.h"

//��ʼ��
void LinkListInit(LinkList* L)
{
	L->head = NULL;
}

//����һ���½ڵ�
Node* CreateNewNode(DataType data)
{
	Node* node = (Node*)malloc(sizeof(Node));

	node->data = data;
	node->next = NULL;

	return node;
}

//ͷ��
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

//β��
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

//��pos֮�����ڵ�
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

//ͷɾ
void HeadPop(LinkList* L)
{
	if (L->head != NULL)
	{
		Node* p = L->head;

		L->head = p->next;
		free(p);
	}
}

//βɾ
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

//ɾ��pos��Ľڵ�
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

//����
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

//��ӡ
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

//����
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

//ɾ�������е��ڸ���ֵ val �����нڵ�
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

//��תһ��������
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

//����һ������ͷ��� head �ķǿյ���������������м��㡣����������м��㣬�򷵻صڶ����м���
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

//����һ����������������е�����k�����
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