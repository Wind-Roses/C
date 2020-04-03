#define _CRT_SECURE_NO_WARNINGS 1

/*
Fibonacci��������������ģ�
F[0] = 0
F[1] = 1
for each i �� 2: F[i] = F[i-1] + F[i-2]
��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...��
��Fibonacci�����е������ǳ�ΪFibonacci��������һ��N�����������Ϊһ��Fibonacci����
ÿһ������԰ѵ�ǰ����X��ΪX-1����X+1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����
*/

#include<stdio.h>
#include<stdlib.h>

int FindFib(int n)
{
	int fib1 = 0;
	int fib2 = 1;
	int tmp = 0;

	while (fib2 < n)
	{
		tmp = fib1 + fib2;
		fib1 = fib2;
		fib2 = tmp;
	}

	return (n - fib1) > (fib2 - n) ? (fib2 - n) : (n - fib1);
}

int main()
{
	int N = 0;

	printf("����һ����N:");
	scanf("%d", &N);

	int ret = FindFib(N);
	printf("%d\n", ret);

	system("pause");
	return 0;
}