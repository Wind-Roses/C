#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int size = 0;

	scanf("%d", &size);

	//int num[size] = {}; sizeΪ�����������ԣ������ö�̬�ڴ�
	int* num = (int*)malloc(size * sizeof(int));
	int* num2 = (int*)calloc(size, sizeof(int));   //calloc������ڴ�ռ�ȫ����ʼ��Ϊ0
	int* num3 = (int*)realloc(num, 10 * sizeof(int));  //realloc�����Ѿ��������ڴ������½��н�һ������
	                                                   //���malloc�����ڴ�ռ��㹻����ô����malloc�����������
	                                                   //���malloc�����ڴ�ռ䲻�㣬��ô�����忽��������Ŀռ䣬Ȼ���ڽ�������


	//��������ڴ�ռ����Ļ���malloc���ܻ�����ʧ�ܣ�����Ҫ�жϷ���ֵ�Ƿ�Ϊ��
	if (num == NULL)            //���������
	{
		printf("����ʧ��\n");
		return 0;
	}

	//malloc������ڴ棬�����ͷţ������ڴ�й©
	//malloc������ڴ棬����������
	free(num);

	system("pause");
	return 0;
}