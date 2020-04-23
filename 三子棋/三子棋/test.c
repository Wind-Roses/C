#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void Game()
{
	char board[ROW][COL] = { 0 };
	char ret = 0;

	srand((unsigned)time(NULL));

	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);

	while (1)
	{
		PlayerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = JudgeWin(board, ROW, COL);
		if (ret != 'G')
			break;

		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		ret = JudgeWin(board, ROW, COL);
		if (ret != 'G')
			break;
	}

	if (ret == '*')
		printf("玩家赢\n");
	else if (ret == '#')
		printf("电脑赢\n");
	else
		printf("平局\n");
}

void Menu()
{
	printf("****************************\n");
	printf("****       1. play      ****\n");
	printf("****       0. exit      ****\n");
	printf("****************************\n");
}

int main()
{
	int input = 0;
	
	do
	{
		Menu();
		printf("请选择：");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Game();
			break;
		case 0:
			break;
		default:
			printf("输入有误，重新输入！\n");
			break;
		}
	} while (input);

	return 0;
}