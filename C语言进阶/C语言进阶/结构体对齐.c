#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

#pragma pack(4)  //手动修改默认对齐数
#pragma pack()   //还原为默认对齐数
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