#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

//字符串长度
int Strlen(const char *str)
{
	int size = 0;

	assert(str != NULL);

	while (*str != '\0')
	{
		str++;
		size++;
	}

	return size;
}

//字符串拷贝
char* Strcpy(char *dest, const char *src)
{
	//参数合法校验
	//法一
	if (dest == NULL || src == NULL)
	{
		return NULL;
	}
	//法二
	//断言，括号里条件必须成立，否则程序崩溃
	//assert(dest != NULL && src != NULL);

	char *result = dest;    //记录最初的dest位置，后面会改变dest的指向
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	//'\0'也要拷贝
	*dest = '\0';

	return result;
}

//字符串拼接
char* Strcat(char *dest, const char *src)
{
	char *result = dest;

	if (dest == NULL || src == NULL)
	{
		return NULL;
	}

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return result;
}

//字符串比较
int Strcmp(const char *str1, const char *str2)
{
	assert(str1 != NULL && str2 != NULL);

	while (*str1 != '\0' && *str2 != '\0')
	{
		if (*str1 > *str2)
		{
			return 1;
		}
		else if (*str1 < *str2)
		{
			return -1;
		}
		else
		{
			str1++;
			str2++;
		}
	}

	if (*str1 > *str2)
	{
		return 1;
	}
	else if (*str1 < *str2)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}

//寻找字符串中的字符串
const char* Strstr(const char *str1, const char *str2)
{
	const char *black = str1;

	assert(str1 != NULL && str2 != NULL);

	if (*str2 == '\0')
	{
		return NULL;
	}

	while (*black != '\0')
	{
		const char *sub = str2;
		const char *red = black;

		while (*red != '\0' && *sub != '\0' && *red == *sub)
		{
			sub++;
			red++;
		}
		if (*sub == '\0')
		{
			return black;
		}
		if (*red == '\0')
		{
			return NULL;
		}
		black++;
	}

	return NULL;
}

int main()
{
	char str[5] = { 0 };
	char str1[20] = "hello world";
	char str2[10] = "world";
	char *p = str;
	int ret = 0;
	char *ret1 = NULL;

	if (p != NULL)
	{
		Strcpy(str, "word");
	}
	printf("%s\n", str);

	Strcat(str1, str2);
	printf("%s\n", str1);

	ret = Strcmp(str1, str2);
	printf("%d\n", ret);

	ret1 = Strstr(str1, str2);
	printf("%s\n", ret1);

	char str[] = "This a simple string";
	char *pch = strtok(str, " ");
	while (pch != NULL)
	{
		printf("%s\n", pch);
		pch = strtok(NULL, " ");
	}

	system("pause");
	return 0;
}