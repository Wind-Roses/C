#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main()
{
	//�򿪷�ʽ��"r"���򿪣�"w"д�򿪣����ݱ�д���ļ���ͷ����"a"׷�Ӵ򿪣�����д���ļ�ĩβ��
	//FILE�ǽṹ��
	//��ʧ�ܣ�����NULL
	FILE* fp = fopen("f:/test.txt", "r");
	if (fp == NULL)
	{

		//printf("�ļ���ʧ��! %s\n", strerror(errno));
		perror("���ļ�ʧ�ܣ�");
		system("pause");
		return 0;
	}

	//int c;
	
	//fgetc��һ���ַ���fputcдһ���ַ�
	//fgets��һ��,fputsдһ��
	//stdin��׼���룬stdout��׼���,stderr��׼����
	/*while ((c = fgetc(fp)) != EOF)
	{
		fputc(c, stdout);
	}*/

	//char buf[1024] = { 0 };

	////����ֵΪ NULL ��ʾ������ EOF
	//while (fgets(buf, sizeof(buf) - 1, fp) != NULL)
	//{
	//	fputs(buf, stdout);
	//}

	//fread��ȡn���ֽڣ�fwriteд��n���ֽ�
	char buf[1024] = { 0 };
	//����ֵ�ĺ����ʾʵ�ʶ�ȡ��Ԫ�صĸ���
	int n = fread(buf, 1, sizeof(buf) - 1, fp);
	fwrite(buf, 1, strlen(buf), stdout);

	fclose(fp);

	system("pause");
	return 0;
}