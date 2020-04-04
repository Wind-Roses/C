#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。

struct ListNode {
	int val;
	struct ListNode *next;
};

bool chkPalindrome(ListNode* A) {
	ListNode* fast, *slow;
	if (A == NULL || A->next == NULL)
	{
		return true;
	}
	fast = slow = A;

	while (fast->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	fast = slow->next;
	ListNode* cur = fast->next;

	while (cur)
	{
		ListNode* next = cur->next;
		cur->next = fast;
		slow->next = cur;
		fast->next = NULL;
		fast = cur;
		cur = next;
	}

	slow = A;
	while (fast)
	{
		if (fast->val != slow->val)
		{
			return false;
		}
		fast = fast->next;
		slow = slow->next;
	}

	return true;
}