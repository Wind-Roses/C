#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int test()
{
	printf("ִ��test\n");

	return 100;
}

void test2(int num)
{
	
}

int main()
{
	//ָ�����顢����ָ��
	//int* arr[] = { 0 }; //ָ�����飺Ԫ�ض�Ϊָ��������ȼ��ڶ���ָ�룩
	//int(*arr1)[4] = { 0 }; //����ָ�룺����һ��ָ�룬ָ��һ������Ϊ4��Ԫ�ص����飨int(*)[10]��

	//����ָ��
	//int(*p)() = test; //p�������Ǻ���ָ�룬������int(*)()
	//void(*p2)(int) = test2;

	//����ʹ��typedef����
	typedef int(*Func1)();
	typedef void(*Func2)(int);
	Func1 p = test;
	Func2 p2 = test2;

	//��������
	(*p)();         //����test
	p();            //����test

	//����Linux�о������
	(    *(void(*)())0   )   ();  //�Ȱ�0ǿ��ת����void(*)()���͵ĺ���ָ�룬�ٽ����ã��ٵ��ã���ϵͳ������أ�

	//����
	void(*signal(int, void(*)(int)))(int);  //signal()Ҳ�Ǹ�����ָ��
	typedef void(*Func3)(int);
	Func3 signal(int, Func3);

	//ֻ�к�������û�����ţ����ǵ��ã��ǻ�ȡtest�����ĺ���ָ�룬һ������д���ȼ�
	printf("%p\n", test);
	printf("%p\n", &test);

	
	system("pause");
	return;
}