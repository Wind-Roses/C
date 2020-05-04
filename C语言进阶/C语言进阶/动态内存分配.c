#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int size = 0;

	scanf("%d", &size);

	//int num[size] = {}; size为变量，不可以，所以用动态内存
	int* num = (int*)malloc(size * sizeof(int));
	int* num2 = (int*)calloc(size, sizeof(int));   //calloc申请的内存空间全部初始化为0
	int* num3 = (int*)realloc(num, 10 * sizeof(int));  //realloc是在已经申请了内存的情况下进行进一步扩容
	                                                   //如果malloc后面内存空间足够，那么就在malloc后面进行扩容
	                                                   //如果malloc后面内存空间不足，那么久整体拷贝到更大的空间，然后在进行扩容


	//如果申请内存空间过大的话，malloc可能会申请失败，所以要判断返回值是否为空
	if (num == NULL)            //这个必须有
	{
		printf("申请失败\n");
		return 0;
	}

	//malloc申请的内存，必须释放，否则内存泄漏
	//malloc申请的内存，跟随程序结束
	free(num);

	system("pause");
	return 0;
}