#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char a = -128;
	char b = 128;
	int i = -20;
	unsigned int j = 10;
	char c[1000];
	int k = 0;

	printf("%u\n", a); //char a => int => unsigned int ��λ������λ
	
	printf("%u\n", b); //char b�з����ضϣ��������λ1��Ϊ�˷���λ������b������Ϊ-128

	printf("%d\n", i + j);//int => unsigned int���̵�������ת����i+j��unsigned int=>int

	for (k = 0; k<1000; k++)
	{
		c[k] = -1 - k;
	}
	//strlen()�� '\0'
	//strlen()���Ϊ255����ζ���±�Ϊ255������Ԫ������Ϊ\0
	//kΪ255ʱ -1-k �õ�0
	//c[k] = -1 - k �а� -1-k �õ���int ��ʽת������char�������˽ضϣ�
 	printf("%d\n", strlen(c));

	system("pause");

	return 0;
}