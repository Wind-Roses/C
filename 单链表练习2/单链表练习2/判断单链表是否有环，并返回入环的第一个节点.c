#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null

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