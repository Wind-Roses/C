#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main() {
	int a = 3, b = 5, temp = 0;
	//scanf("%d%d", &a, &b);
	/*temp = a;
	a = b;
	b = temp;*/
	
	//����ʹ���м����
	/*a = a + b;
	b = a - b;
	a = a - b;*/

	//��򡪡���������λ���
	//��ͬΪ0������Ϊ1
	//011���� a=3 
	//101���� b=5
	//110���� a=6
	//011���� b=3
	//101���� a=5
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("%d %d\n", a, b);
	system("pause");
	return 0;
}