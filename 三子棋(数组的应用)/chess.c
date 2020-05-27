#include "chess.h"

//初始化棋盘
void InitBoard(char board[][COL], int row, int col){
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			board[i][j] = ' ';
		}
	}
}

//人走一步
int playerMove(char board[][COL], int row, int col){
	int x = 0;
	int y = 0;
	printf("Pllease Enter Your Pos<x, y># ");
	scanf("%d %d", &x, &y);
	if (x >= 1 && x <= 3 && y >= 1 && y <= 3){
		if (board[x - 1][y - 1] != ' '){
			return 2;	//用户坐标被占了
		}
		board[x - 1][y - 1] = BLACK_PIECE;	//把旗子添加到棋盘中
		return 0;
	}
	return 1;	//用户输入坐标有误
}

//显示棋盘面板
void showBoard(char board[][COL], int row, int col){
	printf("   | 1 | 2 | 3 |\n");
	for (int i=1; i<=row; i++){
		printf("----------------\n");
		printf(" %d | %c | %c | %c |\n", i, board[i-1][0], board[i-1][1], board[i-1][2]);
	}
	printf("----------------\n");
}

//用户赢了	BLACK_PIECE	'×'
//电脑赢了	WHITE_PIECE	'○'
//平局	'E'
//都没赢，继续	'N'
char JudgeResult(char board[][COL], int row, int col){
	//判断行是否相等
	for (int i = 0; i < row; i++){
		if (board[i][0]!=' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
			return board[i][0];
		}
	}

	//判断列是否相等
	for (int i = 0; i < col; i++){
		if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
			return board[0][i];
		}
	}

	//判断对角线是否相等
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]){
		return board[0][0];
	}
	if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]){
		return board[0][2];
	}

	//判断是否没有结果
	for (int i = 0; i < row; i++){
		for (int j = 0; j < col; j++){
			if (board[i][j] == ' '){
				return 'N';
			}
		}
	}

	return 'E';
}

//初级电脑走一步
void ComputerMove(char board[][COL], int row, int col){
	while (1){
		int i = rand() % row;	// 0-2之间
		int j = rand() % col;	// 0-2之间

		if (board[i][j] == ' '){
			board[i][j] = WHITE_PIECE;
			break;
		}
	}
	printf("Computer ... Done\n");
	Sleep(1000);
}

//算法判断
//difference区分中级和高级电脑
int algorithm(char board[][COL], int row, int col, int difference){
	if (difference){
		//先要判断自己能否获胜
		//判断行
		for (int i = 0; i < 3; i++){
			if (board[i][0] == WHITE_PIECE && board[i][1] == WHITE_PIECE){
				if (board[i][2] == ' '){
					board[i][2] = WHITE_PIECE;
					return 1;
				}
			}
			else if (board[i][0] == WHITE_PIECE && board[i][2] == WHITE_PIECE){
				if (board[i][1] == ' '){
					board[i][1] = WHITE_PIECE;
					return 1;
				}
			}
			else if (board[i][1] == WHITE_PIECE && board[i][2] == WHITE_PIECE){
				if (board[i][0] == ' '){
					board[i][0] = WHITE_PIECE;
					return 1;
				}
			}
		}

		//判断列
		for (int i = 0; i < 3; i++){
			if (board[0][i] == WHITE_PIECE && board[1][i] == WHITE_PIECE){
				if (board[2][i] == ' '){
					board[2][i] = WHITE_PIECE;
					return 1;
				}
			}
			else if (board[0][i] == WHITE_PIECE && board[2][i] == WHITE_PIECE){
				if (board[1][i] == ' '){
					board[1][i] = WHITE_PIECE;
					return 1;
				}
			}
			else if (board[1][i] == WHITE_PIECE && board[2][i] == WHITE_PIECE){
				if (board[0][i] == ' '){
					board[0][i] = WHITE_PIECE;
					return 1;
				}
			}
		}

		//判断对角线
		if (board[0][0] == WHITE_PIECE&&board[1][1] == WHITE_PIECE){
			if (board[2][2] == ' '){
				board[2][2] = WHITE_PIECE;
				return 1;
			}
		}
		else if (board[0][0] == WHITE_PIECE&&board[2][2] == WHITE_PIECE){
			if (board[1][1] == ' '){
				board[1][1] = WHITE_PIECE;
				return 1;
			}
		}
		else if (board[1][1] == WHITE_PIECE&&board[2][2] == WHITE_PIECE){
			if (board[0][0] == ' '){
				board[0][0] = WHITE_PIECE;
				return 1;
			}
		}
		//判断对角线
		if (board[0][2] == WHITE_PIECE&&board[1][1] == WHITE_PIECE){
			if (board[2][0] == ' '){
				board[2][0] = WHITE_PIECE;
				return 1;
			}
		}
		else if (board[0][2] == WHITE_PIECE&&board[2][0] == WHITE_PIECE){
			if (board[1][1] == ' '){
				board[1][1] = WHITE_PIECE;
				return 1;
			}
		}
		else if (board[2][0] == WHITE_PIECE&&board[1][1] == WHITE_PIECE){
			if (board[0][2] == ' '){
				board[0][2] = WHITE_PIECE;
				return 1;
			}
		}
	}

	//如果是高级机器人，判断自己不能获胜后，再判断自己是否需要堵住玩家
	//判断行
	for (int i = 0; i < 3; i++){
		if (board[i][0] == BLACK_PIECE && board[i][1] == BLACK_PIECE){
			if (board[i][2] == ' '){
				board[i][2] = WHITE_PIECE;
				return 1;
			}
		}
		else if (board[i][0] == BLACK_PIECE && board[i][2] == BLACK_PIECE){
			if (board[i][1] == ' '){
				board[i][1] = WHITE_PIECE;
				return 1;
			}
		}
		else if (board[i][1] == BLACK_PIECE && board[i][2] == BLACK_PIECE){
			if (board[i][0] == ' '){
				board[i][0] = WHITE_PIECE;
				return 1;
			}
		}
	}

	//判断列
	for (int i = 0; i < 3; i++){
		if (board[0][i] == BLACK_PIECE && board[1][i] == BLACK_PIECE){
			if (board[2][i] == ' '){
				board[2][i] = WHITE_PIECE;
				return 1;
			}
		}
		else if (board[0][i] == BLACK_PIECE && board[2][i] == BLACK_PIECE){
			if (board[1][i] == ' '){
				board[1][i] = WHITE_PIECE;
				return 1;
			}
		}
		else if (board[1][i] == BLACK_PIECE && board[2][i] == BLACK_PIECE){
			if (board[0][i] == ' '){
				board[0][i] = WHITE_PIECE;
				return 1;
			}
		}
	}

	//判断对角线
	if (board[0][0] == BLACK_PIECE&&board[1][1] == BLACK_PIECE){
		if (board[2][2] == ' '){
			board[2][2] = WHITE_PIECE;
			return 1;
		}
	}
	else if (board[0][0] == BLACK_PIECE&&board[2][2] == BLACK_PIECE){
		if (board[1][1] == ' '){
			board[1][1] = WHITE_PIECE;
			return 1;
		}
	}
	else if (board[1][1] == BLACK_PIECE&&board[2][2] == BLACK_PIECE){
		if (board[0][0] == ' '){
			board[0][0] = WHITE_PIECE;
			return 1;
		}
	}
	//判断对角线
	if (board[0][2] == BLACK_PIECE&&board[1][1] == BLACK_PIECE){
		if (board[2][0] == ' '){
			board[2][0] = WHITE_PIECE;
			return 1;
		}
	}
	else if (board[0][2] == BLACK_PIECE&&board[2][0] == BLACK_PIECE){
		if (board[1][1] == ' '){
			board[1][1] = WHITE_PIECE;
			return 1;
		}
	}
	else if (board[2][0] == BLACK_PIECE&&board[1][1] == BLACK_PIECE){
		if (board[0][2] == ' '){
			board[0][2] = WHITE_PIECE;
			return 1;
		}
	}

	//如果行列对角线都不满足，返回0，就随机找值
	return 0;
}

//中级电脑走一步
void middleComputerMove(char board[][COL], int row, int col){
	//算法判断，如果要堵住玩家，立即堵住玩家，返回1，如果不需要，就随机放一颗
	int flag = algorithm(board, ROW, COL,0);

	//先让电脑判断，有没有哪一行或列或对角线是有两颗BLACK_PIECE，如果有，返回1，如果没有，就返回-1，便在那一行或列或对角线堵住。
	if (flag){
			
	}

	while (!flag){
		int i = rand() % row;	//0-2之间
		int j = rand() % col;	//0-2之间

		

		if (board[i][j] == ' '){
			board[i][j] = WHITE_PIECE;
			break;
		}
	}
	printf("Computer ... Done\n");
	Sleep(1000);
}

//高级电脑走一步
void seniorComputerMove(char board[][COL], int row, int col){
	//算法判断，先判断自己能否获胜，再判断是否需要堵住玩家，立即堵住玩家，返回1，如果不需要，就随机放一颗
	int flag = algorithm(board, ROW, COL, 1);

	//先让电脑判断，有没有哪一行或列或对角线是有两颗BLACK_PIECE，如果有，返回1，如果没有，就返回-1，便在那一行或列或对角线堵住。
	if (flag){

	}

	while (!flag){
		int i = rand() % row;	//0-2之间
		int j = rand() % col;	//0-2之间



		if (board[i][j] == ' '){
			board[i][j] = WHITE_PIECE;
			break;
		}
	}
	printf("Computer ... Done\n");
	Sleep(1000);
}

void game(int choose){
	int count = 1;	//让电脑第一步占领4个角其中一个,那样困难电脑攻无不克
	char board[ROW][COL];
	InitBoard(board,ROW,COL);	//初始化棋盘

	char result = 'N';	//判断是否有人胜利
	srand((unsigned long)time(NULL));	//随机数种子

	while (1){
		showBoard(board, ROW, COL);	//给玩家看到面板
		//人走一步
		int type=playerMove(board, ROW, COL);	
		if (1 == type){
			printf("您输入的坐标有误，请重新输入！\n");
			continue;
		}
		else if(2==type){
			printf("您输入的坐标已经被占用了，请重新输入！\n");
			continue;
		}
		else{
			printf("Player ... Done!\n");
		}

		result = JudgeResult(board, ROW, COL);//判定结果
		if (result != 'N'){
			break;
		}

		//根据玩家选择的难度，电脑分别走出一步
		if (choose == 1){
			//初级电脑走一步
			ComputerMove(board, ROW, COL);
		}
		else if (choose == 2){
			//中级电脑走一步
			middleComputerMove(board, ROW, COL);
		}
		else if (choose == 3){
			//高级电脑走一步
			if (count == 1){
				//高级电脑第一步要占领四个角其中一个
				if (board[0][0] == ' '){
					board[0][0] = WHITE_PIECE;
					count++;
				}
				else if (board[0][2] == ' '){
					board[0][2] = WHITE_PIECE;
					count++;
				}
				else if (board[2][0] == ' '){
					board[2][0] = WHITE_PIECE;
					count++;
				}
				else{
					board[2][2] = WHITE_PIECE;
					count++;
				}
			}
			else{
				seniorComputerMove(board, ROW, COL);
			}
		}
		else{
			printf("buf");	//出现bug
		}

		result = JudgeResult(board, ROW, COL);//判定结果
		if (result != 'N'){
			break;
		}
	}

	showBoard(board, ROW, COL);	//给玩家看到面板
	//赢了or输了or平局
	switch (result){
	case 'E':
		printf("恭喜你，你和电脑打了一个平手！\n");
		break;
	case BLACK_PIECE:
		printf("恭喜你，你赢了！\n");
		break;
	case WHITE_PIECE:
		printf("You Lost，电脑赢了！\n");
		break;
	default:
		printf("出现bug\n");
		//bug!
		break;
	}
	//printf("%c\n", result);
}