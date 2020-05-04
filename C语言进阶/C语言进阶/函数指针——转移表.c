#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

int main()
{
	int choice = 0;
	int ret = 0;

	printf("输入你的运算方式：\n");
	printf("1.+\n");
	printf("2.-\n");
	printf("3.*\n");
	printf("4./\n");
	scanf("%d", &choice);
	
	//圈复杂度太高
	/*if (choice == 1)
	{
		Add(10, 20);
	}
	else if (choice == 2)
	{
		Sub(10, 20);
	}
	else if (choice == 3)
	{
		Mul(10, 20);
	}
	else if (choice == 4)
	{
		Div(10, 20);
	}*/

	//用转移表（函数指针数组）来减小圈复杂度
	typedef int(*Func)(int, int);
	Func table[] = {
		Add,
		Sub,
		Mul,
		Div
	};
	ret = table[choice - 1](10, 20);

	printf("%d\n", ret);

	system("pause");
	return 0;
}