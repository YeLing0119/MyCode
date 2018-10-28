#include "mine.h"

int GetRandomNum(int _start, int _end){
	return rand() % (_end - _start + 1) + 1;
}

void CreateMine(char mine[][COL], int _row, int _col){
	int row = 0;
	int col = 0;
	srand((unsigned int)time(NULL));
	int number = MINE_NUM;
	while (number){
		row = GetRandomNum(1, _col - 2);
		col = GetRandomNum(1, _col - 2);
		//printf("row = %d  col =%d\n", row, col);
		if (mine[row][col] == '0'){
			mine[row][col] = '1';
			//printf("row = %d  col =%d\n", row, col);
			number--;
		}
	}
}

void PrintBoard(char board[][COL], int _row, int _col){
	printf("   ");
	for (int i = 1; i < 11; i++){
		printf("   %d   ", i);
	}
	printf("\n");
	printf("  ");
	for (int i = 0; i < 10; i++){
		if (i == 0){
			printf("┌──────┬");
			continue;
		}
		if (i == 9){
			printf("──────┐");
			continue;
		}
		printf("──────┬");
	}
	printf("\n");
	for (int i = 1; i <= _row - 2; i++){
		for (int count = 0; count < 10; count++){
			if (count == 0){
				printf("  │");
			}
			printf("      │");
		}
		printf("\n");
		printf("%2d", i);
		for (int j = 1; j <= _col - 2; j++){
			if (j == 1){
				printf("│");
			}
			printf("   %c  │", board[i][j]);
		}
		printf("\n");
		for (int count = 0; count < 10; count++){
			if (count == 0){
				printf("  │");
			}
			printf("      │");
		}
		printf("\n");
		if (i != 10){
			for (int j = 0; j < 10; j++){
				if (j == 0){
					printf("  ├──────┼");
					continue;
				}
				if (j == 9){
					printf("──────┤");
					continue;
				}
				printf("──────┼");
			}
			printf("\n");
		}
	}
	for (int i = 0; i < 10; i++){
		if (i == 0){
			printf("  └──────┴");
			continue;
		}
		if (i == 9){
			printf("──────┘");
			continue;
		}
		printf("──────┴");
	}
	printf("\n");
	printf("请输入要点击的坐标<1~10>:\n");
}

void Click(char mine[][COL], char show[][COL]){
	//int count_input = 0;		//记录用户正确输入的次数
	int is_win = 0;		//记录没有踩到雷的个数
	int x = 0;
	int y = 0;
	while (1){
		scanf("%d %d", &x, &y);
		if (x < 1 || x > 10 || y < 1 || y > 10){
			printf("你的输入有误,请重新输入：\n");
			fflush(stdin);
			continue;
		}
		fflush(stdin);
		if (is_win == 0){
			mine[x][y] = 'f';
			CreateMine(mine, ROW, COL);
			int mine_num = AroundMine(mine, x, y);
			if (mine_num == 0){
				show[x][y] = ' ';
			}
			else{
				show[x][y] = mine_num + '0';
			}
			is_win++;
			CheckAround(mine, show, x, y, &is_win);
			system("cls");
			PrintBoard(mine, ROW, COL);
			PrintBoard(show, ROW, COL);
			continue;
		}
		if (show[x][y] != '*'){
			printf("该位置已经是数字！\n");
			continue;
		}
		if (mine[x][y] == '1'){
			printf("很遗憾，你点到雷了!\n");
			printf("游戏结束!\n");
			break;
		}
		int mine_num = AroundMine(mine, x ,y);
		if (mine_num == 0){
			show[x][y] = ' ';
		}else{
			show[x][y] = mine_num + '0';
		}
		is_win++; 
		if (show[x][y] == ' '){
			CheckAround(mine, show, x, y, &is_win);
		}
		if ((100 - is_win) == MINE_NUM){		//如果条件成立，说明玩家已经赢了
			printf("你赢了\n");
			break;
		}
		system("cls");
		PrintBoard(mine, ROW, COL);
		PrintBoard(show, ROW, COL);
	}
}

int CheckAround(char mine[][ROW], char show[][COL], int x, int y, int *is_win){
	int mine_num = -1;
	if (x < 1 || x>10 || y < 1 || y > 10){
		return 0;
	}
	for (int i = x - 1; i <= x + 1; i++){
		for (int j = y - 1; j <= y + 1; j++){
			//不检测超过棋盘范围和其本身
			if ((i == x && j == y) || i > 10 || i < 1 || j > 10 || j < 1){
				continue;
			}
			//不检测已经被点击过或者展开过的
			if (show[i][j] != '*'){
				continue;
			}
			//剩下的本身周围是没有被展开过的
			if (AroundMine(mine, i, j) == 0){
				show[i][j] = ' ';
				(*is_win)++;
				CheckAround(mine, show ,i, j,is_win);
			}
		}
	}
	return 0;
}

int AroundMine(char mine[][COL],int x,int y){
	int count = 0;
	for (int i = x - 1; i <= x + 1; i++){
		for (int j = y - 1; j <= y + 1; j++){
			if (mine[i][j] == '1'){
				count++;
			}
		}
	}
	return count;
}

void Mine(){

	//1、定义雷盘和显示盘
	char mine_board[ROW][COL];
	char show_board[ROW][COL];
	
	//2、初始化
	memset(mine_board, '0', sizeof(mine_board));
	memset(show_board, '*', sizeof(show_board));

	//Init(mine_board, show_board, ROW, COL);

	//测试
	system("cls");
	//PrintBoard(mine_board, ROW, COL);
	PrintBoard(show_board, ROW, COL);

	//用户输入
	Click(mine_board,show_board);
}
