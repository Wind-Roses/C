#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void Merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int i = 0;
	int j = 0;
	int idx = 0;
	int* arr = (int*)malloc(sizeof(int) * (m + n));

	if (arr == NULL)
		return;

	while (i < m && j < n)
	{
		if (nums1[i] <= nums2[j])
		{
			arr[idx++] = nums1[i];
			i++;
		}
		else
		{
			arr[idx++] = nums2[j];
			j++;
		}
	}

	if (i <= m)
	{
		memcpy(arr + idx, nums1 + i, sizeof(int) * (m - i));
	}
	if (j <= n)
	{
		memcpy(arr + idx, nums2 + j, sizeof(int) * (n - j));
	}

	memcpy(nums1, arr, sizeof(int) * (m + n));
	free(arr);
}

int main()
{
	int nums1[6] = { 1, 2, 3, 0, 0, 0 };
	int nums2[3] = { 2, 5, 6 };

	Merge(nums1, 6, 3, nums2, 3, 3);

	system("pause");
	return 0;
}