#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include <windows.h>
int main()
{
	int list[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int key = 7;
	double run_time;
	_LARGE_INTEGER time_start;
	_LARGE_INTEGER time_over;
	double dqFreq;
	LARGE_INTEGER f;
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;

	system("color 70");
	
	printf("待查找序列：");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", list[i]);
	}

	printf("\n待查找值为：%d", key);

	QueryPerformanceCounter(&time_start);
	for (int i = 0; i<10; i++)
	{
		if (key == list[i])
		{
			printf("\n找到了，下标为：%d\n", i);
			break;
		}
		if (10 == i)
			printf("is not exsit \n");
	}
	QueryPerformanceCounter(&time_over);
	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	printf("run_time：%fus\n", run_time);
	return 0;
}