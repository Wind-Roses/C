#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

//�жϴ��С�ˣ���С�˷���1���Ǵ�˷���0
//д��һ
//int CheckSys()
//{
//	int num = 0x11223344;
//	int* p = &num;
//	char* p2 = (char*)p;
//
//	if (*p2 == 0x44)
//	{
//		return 1;
//	}
//
//	return 0;
//}

//д����
int CheckSys()
{
	int num = 1;

	return(*(char*)&num);
}

int main()
{
	int ret = 0;

	ret = CheckSys();
	if (ret == 1)
	{
		printf("��С��\n");
	}
	else
	{
		printf("�Ǵ��\n");
	}

	system("pause");

	return 0;
}