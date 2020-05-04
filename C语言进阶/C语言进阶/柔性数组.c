#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#pragma pack(4)
typedef struct S1
{
	int a;
	int b[0];
}S1;

typedef struct S2
{
	int i;
	int* n;
}S2;

int main()
{
	//s1使用柔性数组
	S1* s1 = (S1*)malloc(sizeof(S1) + sizeof(int) * 10);

	free(s1);

	//s2不适用柔性数组
	S2* s2 = (S2*)malloc(sizeof(S2));
	s2->n = (S2*)malloc(sizeof(int) * 10);

	free(s2->n);
	free(s2);

	system("pause");
	return 0;
}