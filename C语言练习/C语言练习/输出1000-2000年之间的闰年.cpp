#include<stdio.h>

int main() {
	int i = 0, count = 0;

	printf("1000-2000������Ϊ��");
	for (i = 1000; i <= 2000; i++) 
	{
		if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0))
		{
			printf("%d ", i);
			count++;
		}
	}
	printf("\n�������Ϊ��count=%d\n", count);

	return 0;
}