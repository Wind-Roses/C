#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

#pragma pack(4)  //�ֶ��޸�Ĭ�϶�����
#pragma pack()   //��ԭΪĬ�϶�����
struct Test
{
	int a;
	int b;
	char c;
};

int main()
{
	struct Test s;

	printf("%d\n", sizeof(s));

	system("pause");
	return 0;
}