#define _CRT_SECURE_NO_WARNINGS 1
#define E 1e-4

#include<stdio.h>
#include<stdlib.h>

int main()
{
	float i = 19.0;
	float j = i / 7.0;

	if (j * 7.0 - i < E && j * 7.0 - i > -E)
	{
		printf("相等\n");
	}
	else
	{
		printf("不等\n");
	}

	system("pause");

	return 0;
}