#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


char g_chess_board[3][3] = { 0 };

void Init(){
	for (int row = 0; row < 3; row++){
		for (int col = 0; col < 3; col++){
			g_chess_board[row][col] = ' '; 
		}
	}
}

void PrintBoard(){
	printf("┌──────┬──────┬──────┐\n");
	for (int count = 0; count < 3; count++){
		printf("│      │      │      │\n");
		printf("│  %c   │   %c  │   %c  │\n", g_chess_board[count][0],
			g_chess_board[count][1], g_chess_board[count][2]);
		printf("│      │      │      │\n");
		if (count != 2)
			printf("├──────┼──────┼──────┤\n");
	}
	printf("└──────┴──────┴──────┘\n");
}

void UserPlay(){
	while (1){
		int row = -1;
		int col = -1;
		printf("请输入落子位置!\n");
		fflush(stdin);
		scanf("%d %d", &row, &col);
		if (row < 0 || row > 2 || col < 0 || col > 2){
			printf("你的输入有误，请重新输入\n");
			continue;
		}
		else if (g_chess_board[row][col] != ' '){
			printf("该位置已经有棋子，请重新输入!\n");
			continue;
		}else{	
			g_chess_board[row][col] = 'X';
			break;
		}
	}
}

void ComputerPlay(){
	int row, col;
	printf("电脑落子中...\n");
	sleep(2);
	while (1){
		srand((unsigned int)time(NULL));
		row = rand() % 3;
		col = rand() % 3;
		if (g_chess_board[row][col] == ' '){
			g_chess_board[row][col] = 'O';
			break;
		}
	}	
}

int IsFull(){
	for (int row = 0; row < 3; row++){
		for (int col = 0; col < 3; col++)
			if (g_chess_board[row][col] == ' '){
				//printf("未满，返回0\n");
				//sleep(1);
				return 0;
			}
	}
	//printf("满了，返回1\n");
	return 1;
}

char CheckWinner(){
	char return_char;
	
	//1.检查行是否都一样
	for (int row = 0 ; row <= 2; row++){
		if (g_chess_board[row][0] == g_chess_board[row][1]
				&& g_chess_board[row][0] == g_chess_board[row][2] 
				&& g_chess_board[row][0] != ' '){
			return g_chess_board[row][0];
		}
	}
	//2.检查列是否都一样
	for (int col = 0 ; col <= 2; col++){
		if (g_chess_board[0][col] == g_chess_board[1][col]
				&& g_chess_board[0][col] == g_chess_board[2][col]
				&& g_chess_board[0][col] != ' '){
			return g_chess_board[0][col];
		}
	}
	//3.检查两个对角线是否都一样
	//3.1正对角线
	if (g_chess_board[1][1] == g_chess_board[0][0]
		&& g_chess_board[1][1] == g_chess_board[2][2]
		&& g_chess_board[1][1] != ' '){
		return g_chess_board[1][1];
	}
	//3.2反对角线
	if(g_chess_board[1][1] == g_chess_board[0][2]
		&& g_chess_board[1][1] == g_chess_board[2][0]
		&& g_chess_board[1][1] != ' '){
		return g_chess_board[1][1];
	}

	//4.检查是否和棋
	if (IsFull()){
		return 'H';
	}
	//5、没有以上情况返回N
	return 'N';
}

void RefreshSrceen(){
	system("clear");
	PrintBoard();
	sleep(2);
}

int main(){
	system("clear");
	//1.初始化
	Init();
	while (1){
		char winner_tags;
		// 2 .打印棋盘
		PrintBoard();
		// 3. 用户落子
		UserPlay();
		RefreshSrceen();
		// 检查是否有赢家或者和棋
		winner_tags = CheckWinner();
		//printf("winner_tags = %c\n", winner_tags);
		//sleep(2);
		if (winner_tags == 'X'){
			printf("Congratulation!\n玩家赢！\n");
			break;
		}else if (winner_tags == 'O'){
			printf("Congratulation!\n电脑赢！\n");
			break;
		}else if (winner_tags == 'H'){
			printf("Equal in influence and power!\n和棋！\n");
			break;
		}
		// 4. 电脑落子
		ComputerPlay();
		RefreshSrceen();
		winner_tags = CheckWinner();
		//printf("winner_tags = %c\n", winner_tags);
		//sleep(2);
		if (winner_tags == 'X'){
			printf("Congratulation!\n玩家赢！\n");
			break;
		}
		else if (winner_tags == 'O'){
			printf("Congratulation!\n电脑赢！\n");
			break;
		}
		else if (winner_tags == 'H'){
			printf("Equal in influence and power!\n和棋！\n");
			break;
		}
		system("clear");
	}
	exit(0);
}
