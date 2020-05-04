#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

//�ַ�������
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

//�ַ�������
char* Strcpy(char *dest, const char *src)
{
	//�����Ϸ�У��
	//��һ
	if (dest == NULL || src == NULL)
	{
		return NULL;
	}
	//����
	//���ԣ������������������������������
	//assert(dest != NULL && src != NULL);

	char *result = dest;    //��¼�����destλ�ã������ı�dest��ָ��
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	//'\0'ҲҪ����
	*dest = '\0';

	return result;
}

//�ַ���ƴ��
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

//�ַ����Ƚ�
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

//Ѱ���ַ����е��ַ���
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