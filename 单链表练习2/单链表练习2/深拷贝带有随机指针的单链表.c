#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


//����һ������ÿ���ڵ����һ���������ӵ����ָ�룬��ָ�����ָ�������е��κνڵ��սڵ㡣
//Ҫ�󷵻��������� �����

struct Node {
	int val;
	struct Node *next;
	struct Node *random;    //���ָ��ָ��Ľڵ���������Χ�� 0 �� n-1���������ָ���κνڵ㣬��Ϊ  null ��

};


struct Node* copyRandomList(struct Node* head) {
	struct Node* cur = head;
	struct Node* copy, *next, *p;

	if (!head)
	{
		return head;
	}

	//����
	while (cur)
	{
		copy = (struct Node*)malloc(sizeof(struct Node));

		copy->val = cur->val;
		copy->next = cur->next;
		cur->next = copy;

		cur = copy->next;
	}

	//�������ָ��
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

	//����

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