#define _CRT_SECURE_NO_WARNINGS 1

/*
��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20����
���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void replaceSpace(char *str, int length) {
	int count = 0;

	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ')
		{
			count++;
		}
	}

	for (int i = length - 1; i >= 0; i--)
	{
		if (str[i] != ' ')
		{
			str[i + count * 2] = str[i];
		}
		else
		{
			str[i + count * 2] = '0';
			str[i + count * 2 - 1] = '2';
			str[i + count * 2 - 2] = '%';
			count--;
		}
	}
}

int main()
{
	char str[100] = "We Are Happy";

	replaceSpace(str, 12);

	printf("%s\n", str);

	system("pause");
	return 0;
}