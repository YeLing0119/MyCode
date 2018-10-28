#ifndef __MINE_H__
#define __MINE_H__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


#define ROW 12
#define COL 12
#define MINE_NUM 2

void Click(char mine[][COL], char  show[][COL]);
void PrintBoard(char board[][COL], int _row, int _col);
void CreateMine(char mine[][COL], int _row, int _col);
int AroundMine(char mine[][COL], int x, int y);
int CheckAround(char mine[][ROW], char show[][COL], int x, int y, int *is_win);
int GetRandomNum(int _start, int _end);
void Mine();

#endif
