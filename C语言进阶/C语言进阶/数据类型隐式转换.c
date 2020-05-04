#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char a = -128;
	char b = 128;
	int i = -20;
	unsigned int j = 10;
	char c[1000];
	int k = 0;

	printf("%u\n", a); //char a => int => unsigned int 高位补符号位
	
	printf("%u\n", b); //char b中发生截断，导致最高位1成为了符号位，所以b本质上为-128

	printf("%d\n", i + j);//int => unsigned int（短的往长的转），i+j由unsigned int=>int

	for (k = 0; k<1000; k++)
	{
		c[k] = -1 - k;
	}
	//strlen()找 '\0'
	//strlen()结果为255，意味着下标为255的数组元素内容为\0
	//k为255时 -1-k 得到0
	//c[k] = -1 - k 中把 -1-k 得到的int 隐式转换成了char（发生了截断）
 	printf("%d\n", strlen(c));

	system("pause");

	return 0;
}