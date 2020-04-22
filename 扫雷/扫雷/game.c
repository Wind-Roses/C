#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

void PutBomb(char board[ROWS][COLS])
{
	int count = BOMB;

	while (count)
	{
		int x = rand() % 9 + 1;
		int y = rand() % 9 + 1;

		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int BombNum(char board[ROWS][COLS], int x, int y)
{
	return (board[x - 1][y]
		+ board[x - 1][y - 1]
		+ board[x][y - 1]
		+ board[x + 1][y - 1]
		+ board[x + 1][y]
		+ board[x + 1][y + 1]
		+ board[x][y + 1]
		+ board[x - 1][y + 1]) - 8 * '0';
}

void FindBomb(char real_board[ROWS][COLS], char show_board[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int count = 0;
	
	while (count < row * col - BOMB)
	{
		printf("���ѡ��");
		scanf("%d%d", &x, &y);

		if ((x >= 1 && x <= 9) || (y >= 1 && y <= 9))
		{
			if (real_board[x][y] != '1')
			{
				int ret = BombNum(real_board, x, y);
				show_board[x][y] = ret + '0';
				PrintBoard(show_board, ROW, COL);
				count++;
			}
			else
			{
				printf("BOOM����Ϸʧ�ܣ�\n");
				PrintBoard(real_board, ROW, COL);
				break;
			}
		}
		else
		{
			printf("��������������������\n");
		}
	}

	if (count == row * col - BOMB)
	{
		printf("��ϲ�㣬���ɨ�ף�\n");
	}
}

void PrintBoard(char board[ROWS][COLS], int row, int col)
{
	printf("=======================================\n");

	for (int i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}

	printf("=======================================\n");

}