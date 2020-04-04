#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

//找到缘分的起点（两个单链表相交的起始节点）

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	struct ListNode* you = headA;
	struct ListNode* she = headB;

	if (!headA || !headB)
	{
		return NULL;
	}

	while (you != she)         //若是有缘，你们早晚会相遇
	{
		you = you ? you->next : headB;      //当你走到终点时，开始走她走过的路
		she = she ? she->next : headA;      //当她走到终点时，开始走你走过的路
	}

	//如果你们喜欢彼此，请携手走完剩下的旅程
	//一路上，时而你踩着她的影子，时而她踩着你的影子
	//渐渐地，你变成了她，她也变成了你，你们水乳交融，不分彼此

	return you;
}