#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//����һ�����������һ��ʱ�临�Ӷ�ΪO(n), ����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��

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