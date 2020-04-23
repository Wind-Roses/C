#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
		}
		printf("\n");
	}
}

void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	while (1)
	{
		printf("玩家请落子（1-3）：");
		scanf("%d%d", &x, &y);

		if ((x <= row && x >= 1) && (y <= col && y >= 1))
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("该位置已有棋子，重新落子：");
			}
		}
		else
			printf("落子无效，重新落子：");
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;

	printf("电脑落子：\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;

		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

static int JudgeTie(char board[ROW][COL], int row, int col)
{
	int i = 0; 
	int j = 0;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}

	return 1;
}

char JudgeWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;

	//判断横
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col - 1; j++)
		{
			if ((board[i][j] == board[i][j + 1]) && board[i][j] != ' ')
			{
				count++;
			}
		}
		if (count == col - 1)
			return board[0][0];

		count = 0;
	}
	count = 0;

	//判断列
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row - 1; j++)
		{
			if ((board[j][i] == board[j][i + 1]) && board[j][i] != ' ')
			{
				count++;
			}
		}
		if (count == row - 1)
			return board[0][0];

		count = 0;
	}
	count = 0;

	//判断斜的
	for (i = 0; i < row - 1; i++)
	{
		j = i;
		if ((board[i][j] == board[i + 1][j + 1]) && board[i][j] != ' ')
		{
			count++;
		}
	}
	if (count == row - 1)
		return board[0][0];
	count = 0;

	for (i = row - 1; i >= 0; i--)
	{
		j = col - 1 - i;
		if ((board[i][j] == board[i - 1][j + 1]) && board[i][j] != ' ')
		{
			count++;
		}
		
	}
	if (count == row - 1)
		return board[row - 1][0];

	//平局
	if (JudgeTie(board, row, col) == 1)
	{
		return 'T';
	}

	return 'G';
}
