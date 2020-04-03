#define _CRT_SECURE_NO_WARNINGS 1

/*
Fibonacci数列是这样定义的：
F[0] = 0
F[1] = 1
for each i ≥ 2: F[i] = F[i-1] + F[i-2]
因此，Fibonacci数列就形如：0, 1, 1, 2, 3, 5, 8, 13, ...，
在Fibonacci数列中的数我们称为Fibonacci数。给你一个N，你想让其变为一个Fibonacci数，
每一步你可以把当前数字X变为X-1或者X+1，现在给你一个数N求最少需要多少步可以变为Fibonacci数。
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

	printf("输入一个数N:");
	scanf("%d", &N);

	int ret = FindFib(N);
	printf("%d\n", ret);

	system("pause");
	return 0;
}