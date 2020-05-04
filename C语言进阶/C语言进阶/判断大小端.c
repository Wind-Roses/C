#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//判断大段小端，是小端返回1，是大端返回0
//写法一
//int CheckSys()
//{
//	int num = 0x11223344;
//	int* p = &num;
//	char* p2 = (char*)p;
//
//	if (*p2 == 0x44)
//	{
//		return 1;
//	}
//
//	return 0;
//}

//写法二
int CheckSys()
{
	int num = 1;

	return(*(char*)&num);
}

int main()
{
	int ret = 0;

	ret = CheckSys();
	if (ret == 1)
	{
		printf("是小端\n");
	}
	else
	{
		printf("是大端\n");
	}

	system("pause");

	return 0;
}