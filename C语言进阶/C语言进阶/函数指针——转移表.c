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

	printf("����������㷽ʽ��\n");
	printf("1.+\n");
	printf("2.-\n");
	printf("3.*\n");
	printf("4./\n");
	scanf("%d", &choice);
	
	//Ȧ���Ӷ�̫��
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

	//��ת�Ʊ�����ָ�����飩����СȦ���Ӷ�
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