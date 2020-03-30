#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void ExecuteRotate(int* nums, int left, int right)
{
	int tmp = 0;

	while (left < right)
	{
		tmp = nums[left];
		nums[left] = nums[right];
		nums[right] = tmp;

		left++;
		right--;
	}
}

void Rotate(int* nums, int numsSize, int k) {
	if (k > numsSize)
	{
		k %= numsSize;
	}

	ExecuteRotate(nums, 0, numsSize - 1);
	ExecuteRotate(nums, 0, k - 1);
	ExecuteRotate(nums, k, numsSize - 1);
}

int main()
{
	int nums[7] = { 1, 2, 3, 4, 5, 6, 7 };

	Rotate(nums, 7, 3);

	system("pause");
	return 0;
}