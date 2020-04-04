#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<stdlib.h>

//��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
//����һ�������ͷָ�� ListNode* pHead��
//�뷵���������к�������ͷָ�롣ע�⣺�ָ��Ժ󱣳�ԭ��������˳�򲻱䡣

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		ListNode* LHead = (ListNode*)malloc(sizeof(ListNode));
		ListNode* HHead = (ListNode*)malloc(sizeof(ListNode));
		ListNode* L = LHead;
		ListNode* H = HHead;

		while (pHead)
		{
			if (pHead->val < x)
			{
				L->next = pHead;
				L = L->next;
				pHead = pHead->next;
			}
			else
			{
				H->next = pHead;
				H = H->next;
				pHead = pHead->next;
			}
		}
		H->next = NULL;

		H = HHead;
		L->next = HHead->next;
		L = LHead;
		LHead = LHead->next;
		free(L);
		free(H);

		return LHead;
	}
};


