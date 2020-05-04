#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

int test()
{
	printf("执行test\n");

	return 100;
}

void test2(int num)
{
	
}

int main()
{
	//指针数组、数组指针
	//int* arr[] = { 0 }; //指针数组：元素都为指针变量（等价于二重指针）
	//int(*arr1)[4] = { 0 }; //数组指针：这是一个指针，指向一个长度为4个元素的数组（int(*)[10]）

	//函数指针
	//int(*p)() = test; //p变量就是函数指针，类型是int(*)()
	//void(*p2)(int) = test2;

	//可以使用typedef来简化
	typedef int(*Func1)();
	typedef void(*Func2)(int);
	Func1 p = test;
	Func2 p2 = test2;

	//函数调用
	(*p)();         //调用test
	p();            //调用test

	//早期Linux中经典代码
	(    *(void(*)())0   )   ();  //先把0强制转换成void(*)()类型的函数指针，再解引用，再调用（与系统启动相关）

	//例子
	void(*signal(int, void(*)(int)))(int);  //signal()也是个函数指针
	typedef void(*Func3)(int);
	Func3 signal(int, Func3);

	//只有函数名，没有括号，不是调用，是获取test函数的函数指针，一下两种写法等价
	printf("%p\n", test);
	printf("%p\n", &test);

	
	system("pause");
	return;
}