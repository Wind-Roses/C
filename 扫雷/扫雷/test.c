#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void Game()
{
	char real_board[ROWS][COLS];
	char show_board[ROWS][COLS];

	//初始化棋盘
	InitBoard(real_board, ROWS, COLS, '0');
	InitBoard(show_board, ROWS, COLS, '*');

	//放雷
	PutBomb(real_board);
	//排雷
	PrintBoard(show_board, ROW, COL);
	FindBomb(real_board, show_board, ROW, COL);
}

void Menu()
{
	printf("*******************************\n");
	printf("******      1. play      ******\n");
	printf("******      0. exit      ******\n");
	printf("*******************************\n");
}

int main()
{
	int input = 0;
	srand((size_t)time(NULL));

	do
	{
		Menu();
		printf("输入序号：");
		scanf("%d", &input);
		
		switch (input)
		{
		case 0:
			printf("游戏结束");
			break;
		case 1:
			printf("游戏开始\n");
			Game();
			break;
		default:
			printf("输入错误，重新输入\n");
			break;
		}
	} while (input);

	return 0;
}