#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//删除数组中指定元素
int removeElement(int* nums, int numsSize, int val) {
	int count = 0;
	int* arr = (int*)malloc(sizeof(int) * numsSize);


	if (arr == NULL)
		return -1;

	for (int i = 0; i < numsSize; i++)
	{
		if (nums[i] != val)
		{
			arr[count++] = nums[i];
		}
	}


	memcpy(nums, arr, sizeof(int) * count);
	free(arr);


	return count;
}

int removeDuplicates(int* nums, int numsSize) {
	int i = 0;
	int j = 1;
	int count = 0;

	while (j < numsSize)
	{
		nums[count++] = nums[i];

		if (nums[i] != nums[j])
		{
			i++;
			j++;
		}
		else
		{
			while ((nums[i] == nums[j]) && (j < numsSize))
			{
				++j;
			}
			i = j;
			++j;
		}
	}

	if (i < numsSize)
	{
		nums[count++] = nums[i];
	}

	return count;
}

int main()
{
	int num1[10] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	int num2[4] = { 0, 1, 1, 2 };
	int length1 = removeDuplicates(num1, 10);
	int length2 = removeElement(num2, 4, 1);

	printf("%d\n", length1);
	for (int i = 0; i < length1; i++)
	{
		printf("%d ", num1[i]);
	}
	printf("\n");

	printf("%d\n", length2);
	for (int i = 0; i < length2; i++)
	{
		printf("%d ", num2[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}