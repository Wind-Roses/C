#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef int(*Cmp)(int, int);
//Cmp定义了比较规则
//如果是升序：第一个元素<第二个元素，返回1，否则返回0

void bubble_sort(int *arr, Cmp cmp)
{
	int i = 0, j = 0;
	int temp = 0;

	for (i = 0; i < 9; i++)
	{
		for (j = 9; j > i; j--)
		{
			if (cmp(arr[j - 1], arr[j]) == 0)
			{
				temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}
}

//升序
int Greater(int x, int y)
{
	return x < y ? 1 : 0;
}

//降序
int Less(int x, int y)
{
	return x > y ? 1 : 0;
}

int main()
{
	int arr[10] = { 10, 3, 6, 8, 9, 1, 2, 7, 4, 5 };
	int i = 0;

	printf("数组：");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n冒泡排序：");
	bubble_sort(arr, Greater);
	printf("\n");

	system("pause");
	return 0;
}