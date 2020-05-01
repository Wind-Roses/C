#include<stdio.h>
#include <windows.h>

int BinarySearch(int arr[], int key, int sz) {
	int left = 0;
	int right = sz - 1;
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (mid < key)
			left = mid + 1;
		else if (mid > key)
			right = mid - 1;
		else
			return mid;
	}
	return -1;
}
int main() {
	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int key = 7;
	int ret = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	double run_time;
	_LARGE_INTEGER time_start;
	_LARGE_INTEGER time_over;
	double dqFreq;
	LARGE_INTEGER f;
	QueryPerformanceFrequency(&f);
	dqFreq = (double)f.QuadPart;

	system("color 70");

	printf("���������У�");
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n������ֵ��%d", key);

	QueryPerformanceCounter(&time_start);
	ret = BinarySearch(arr, key, sz);
	if (-1 == ret)
		printf("\n�Ҳ���\n");
	else
		printf("\n�ҵ��ˣ��±�Ϊ��%d", ret - 1);
	QueryPerformanceCounter(&time_over);

	run_time = 1000000 * (time_over.QuadPart - time_start.QuadPart) / dqFreq;
	printf("\nrun_time��%fus\n", run_time);

	return 0;
}