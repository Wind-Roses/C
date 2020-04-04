#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

//�ҵ�Ե�ֵ���㣨�����������ཻ����ʼ�ڵ㣩

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode* you = headA;
	struct ListNode* she = headB;

	if (!headA || !headB)
	{
		return NULL;
	}

	while (you != she)         //������Ե���������������
	{
		you = you ? you->next : headB;      //�����ߵ��յ�ʱ����ʼ�����߹���·
		she = she ? she->next : headA;      //�����ߵ��յ�ʱ����ʼ�����߹���·
	}

	//�������ϲ���˴ˣ���Я������ʣ�µ��ó�
	//һ·�ϣ�ʱ�����������Ӱ�ӣ�ʱ�����������Ӱ��
	//�����أ�������������Ҳ������㣬����ˮ�齻�ڣ����ֱ˴�

	return you;
}