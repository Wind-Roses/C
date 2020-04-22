#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 9
#define COL 9
#define ROWS ROW+2
#define COLS COL+2
#define BOMB 9

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

void PutBomb(char board[ROWS][COLS]);

void PrintBoard(char board[ROWS][COLS], int row, int col);

void FindBomb(char real_board[ROWS][COLS], char show_board[ROWS][COLS], int row, int col);