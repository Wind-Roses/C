#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

void* Memcpy(void *dest, const void *src, size_t num)
{
	assert(dest != NULL && src != NULL);
	void *ret = dest;
	char *cdest = dest;
	const char *csrc = src;
	size_t i = 0;

	for (i = 0; i < num; i++)
	{
		*cdest = *csrc;
		cdest++;
		csrc++;
	}

	return ret;
}

void* Memmove(void *dest, const void *src, size_t num)
{
	assert(dest != NULL && src != NULL);
	char *cdest = (char*)dest;
	char *csrc = (char*)src;

	//先判断缓冲区是否重叠
	if (csrc < cdest && cdest < csrc + num)
	{
		//需要从后向前拷贝
		char *pdest = cdest + num - 1;    //指向最后一个字节
		char *psrc = csrc + num - 1;
		for (size_t i = 0; i < num; i++)
		{
			*pdest = *psrc;
			pdest--;
			psrc--;
		}
	}
	else
	{
		Memcpy(dest, src, num);
	}

	return dest;
}

int main()
{
	int arr1[3] = { 1, 2, 3 };
	int arr2[3] = { 0 };

	Memmove(arr2, arr1, 12);
	for (int i = 0; i < 3; i++)
	{
		printf("%d ", arr2[i]);
	}

	system("pause");
	return 0;
}