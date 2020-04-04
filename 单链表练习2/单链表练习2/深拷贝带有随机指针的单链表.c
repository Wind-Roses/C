#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


//给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
//要求返回这个链表的 深拷贝。

struct Node {
	int val;
	struct Node *next;
	struct Node *random;    //随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。

};


struct Node* copyRandomList(struct Node* head) {
	struct Node* cur = head;
	struct Node* copy, *next, *p;

	if (!head)
	{
		return head;
	}

	//拷贝
	while (cur)
	{
		copy = (struct Node*)malloc(sizeof(struct Node));

		copy->val = cur->val;
		copy->next = cur->next;
		cur->next = copy;

		cur = copy->next;
	}

	//拷贝随机指针
	cur = head;
	while (cur)
	{
		copy = cur->next;

		if (cur->random)
		{
			copy->random = cur->random->next;
		}
		else
		{
			copy->random = NULL;
		}
		cur = copy->next;
	}

	//拆链

	cur = head;
	p = cur->next;

	while (cur)
	{
		copy = cur->next;
		next = copy->next;
		cur->next = next;

		if (next)
		{
			copy->next = next->next;
		}
		cur = next;
	}

	return p;
}