#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void Mune() {
	printf("*******************************\n");
	printf("************ 1. play **********\n");
	printf("************ 0. exit **********\n");
	printf("*******************************\n");
}

void Game() {
	int red = 0;
	int num = 0;
	red = rand() % 100 + 1;        //����1-100�������
	while (1) {
		printf("������֣�");
		scanf("%d", &num);
		if (num == red) {
			printf("�ɹ����У�\n");
			break;
		}
		else if (num > red)
			printf("�������ֹ���\n");
		else if (num < red)
			printf("�������ֹ�С\n");
	}
}
int main() {
	int input = 0;
	srand((unsigned int)time(NULL));       //ʹ��rand()����ǰ��Ҫ���ô˺���
	do {
		Mune();
		printf("�����룺");
		scanf("%d", &input);
		switch (input) {
		case 1:
			Game();
			break;
		case 0:
			break;
		default:
			printf("����������������\n");
		}
	} while (input);

	return 0;
}