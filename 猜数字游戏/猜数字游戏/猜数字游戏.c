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
	red = rand() % 100 + 1;        //生成1-100的随机数
	while (1) {
		printf("请猜数字：");
		scanf("%d", &num);
		if (num == red) {
			printf("成功猜中！\n");
			break;
		}
		else if (num > red)
			printf("所猜数字过大\n");
		else if (num < red)
			printf("所猜数字过小\n");
	}
}
int main() {
	int input = 0;
	srand((unsigned int)time(NULL));       //使用rand()函数前需要调用此函数
	do {
		Mune();
		printf("请输入：");
		scanf("%d", &input);
		switch (input) {
		case 1:
			Game();
			break;
		case 0:
			break;
		default:
			printf("输入有误，重新输入\n");
		}
	} while (input);

	return 0;
}