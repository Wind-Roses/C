#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//����һ��������������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null

struct ListNode {
	int val;
	struct ListNode *next;
};


struct ListNode* hasCycle(struct ListNode *head)
{
	struct ListNode* fast, *slow;

	if (!head)
	{
		return NULL;
	}

	fast = slow = head;

	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
		{
			return slow;
		}
	}

	return NULL;
}

struct ListNode *detectCycle(struct ListNode *head) {
	struct ListNode* p, *q;

	p = head;
	q = hasCycle(head);

	if (q != NULL)
	{
		while (q != p)
		{
			p = p->next;
			q = q->next;
		}

		return p;
	}

	return NULL;
}