#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void Game()
{
	char real_board[ROWS][COLS];
	char show_board[ROWS][COLS];

	//��ʼ������
	InitBoard(real_board, ROWS, COLS, '0');
	InitBoard(show_board, ROWS, COLS, '*');

	//����
	PutBomb(real_board);
	//����
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
		printf("������ţ�");
		scanf("%d", &input);
		
		switch (input)
		{
		case 0:
			printf("��Ϸ����");
			break;
		case 1:
			printf("��Ϸ��ʼ\n");
			Game();
			break;
		default:
			printf("���������������\n");
			break;
		}
	} while (input);

	return 0;
}