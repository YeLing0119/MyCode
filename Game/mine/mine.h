#ifndef __MINE_H__
#define __MINE_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>

#pragma warning (disable:4996)

#define ROW 12
#define COL 12
#define MINE_NUM 20

//void Init(char mine[][COL], char show[][COL], int _row, int _col);
void Click(char mine[][COL], char  show[][COL]);
void PrintBoard(char board[][COL], int _row, int _col);
void CreateMine(char mine[][COL], int _row, int _col);
int AroundMine(char mine[][COL], int x, int y);
int GetRandomNum(int _start, int _end);
void Mine();

#endif