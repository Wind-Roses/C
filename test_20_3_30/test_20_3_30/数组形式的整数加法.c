#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

void Invert(int* arr, int left, int right)
{
	int tmp = 0;

	while (left < right)
	{
		tmp = arr[left];
		arr[left] = arr[right];
		arr[right] = tmp;

		left++;
		right--;
	}
}

int* AddToArrayForm(int* A, int ASize, int K) {
	int knum = 0;
	int k = K;

	//ÄæÖÃA
	Invert(A, 0, ASize - 1);

	while (k)
	{
		k = k / 10;
		knum++;
	}

	//Ïà¼Ó
	int count = 0;
	int tmp = 0;
	int idx = 0;
	int result_size = ASize > knum ? ASize + 1 : knum + 1;
	int* result = (int*)malloc(sizeof(int) * result_size);

	while (idx < result_size - 1)
	{
		if (idx < ASize)
		{
			if (K)
			{
				tmp = K % 10;
				result[idx] = (A[idx] + tmp) % 10 + count;
				count = (A[idx] + tmp) / 10;
				K = K / 10;
			}
			else
			{
				result[idx] = (A[idx] + count) % 10;
				count = (A[idx] + count) / 10;
			}
			
		}
		else
		{
			tmp = K % 10;
			result[idx] = (K + count) % 10;
			count = (tmp + count) / 10;
			K = K / 10;
		}

		idx++;
	}

	if (count == 1)
	{
		result[idx] = count;

		Invert(result, 0, idx);

		return result;
	}
	else
	{
		Invert(result, 0, idx);

		return result + 1;
	}
}

int main()
{
	int A[1] = { 9 };
	int K = 999;
	int* ret = NULL;

	ret = AddToArrayForm(A, 1, 999999999);

	for (int i = 0; i < 11; i++)
	{
		printf("%d ", ret[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}