#define _CRT_SECURE_NO_WARNINGS 1
#include"LinkList_test.h"

int main()
{
	LinkList L;

	LinkListInit(&L);

	for (int i = 1; i <= 10; i++)
	{
		//HeadPush(&L, i);
		TailPush(&L, i);
	}
	LinkListPrint(&L);

	Node* pos = LinkListFind(&L, 3);
	LinkListInsert(pos, 100);
	LinkListPrint(&L);

	LinkListDelete(pos);
	LinkListPrint(&L);

	HeadPop(&L);
	TailPop(&L);
	LinkListPrint(&L);

	LinkListDestroy(&L);

	system("pause");
	return 0;
}