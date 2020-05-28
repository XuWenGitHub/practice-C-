#include "MineSweep.h"


//确定mineBoard[row][lie]不是炸弹，返回他周围炸弹的个数，但是是字符。
char isNunmber(char mineBoard[][LIE], int row, int lie){
	if (row >=1 && row <= 10 && lie >=1 && lie <= 10){
		char ch = mineBoard[row - 1][lie - 1] + mineBoard[row - 1][lie] + mineBoard[row - 1][lie + 1] + mineBoard[row][lie - 1] + mineBoard[row][lie + 1] + mineBoard[row + 1][lie - 1] + mineBoard[row + 1][lie] + mineBoard[row + 1][lie + 1] - 7 * '0';
		return ch;
	}
}

//判断玩家选的位置是否是炸弹,返回1，则是炸弹，返回0则不是炸弹
int judgeMine(char mineBoard[][LIE], int row, int lie){
	if (mineBoard[row][lie] == '1'){
		return 1;
	}
	else{
		return 0;
	}
}

//显示面板
void printBoard(char mineBoard[][LIE], int row, int lie){
	printf("   ");
	for (int i = 1; i <= lie - 2; i++){
		if (i != lie - 2){
			printf(" | %2d", i);
		}
		else{
			printf(" | %2d |", i);
		}
	}
	printf("\n");
	printf("-------------------------------------------------------\n");

	for (int i = 1; i <=lie-2; i++){
		if (i != 10){
			printf("%2d ", i);
		}
		else{
			printf("%2d ", i);
		}
		for (int j = 1; j <= row-2; j++){
			if (j != row - 2){
				printf(" | %2c", mineBoard[i][j]);
			}
			else{
				printf(" | %2c |", mineBoard[i][j]);
			}
		}
		printf("\n");
		printf("-------------------------------------------------------\n");
	}
}

//给面板初始化	最后一个形参为把面板初始化为什么‘字符’
void boardInit(char mineBoard[][LIE], int row, int lie,char ch)	{
	for (int i = 0; i < row; i++){
		for (int j = 0; j < lie; j++){
			mineBoard[i][j] = ch;
		}
	}
}

//给存放地雷的面板，随机存放20颗地雷,字符1代表是地雷，字符0代表无地雷
void landMines(char mineBoard[][LIE], int row, int lie){

	//产生[1,10]之间的随机数字，因为只用有最外面一圈，我们不用
	//k=rand()%(Y-X+1)+X;	这是一个公式，可产生[x,y]之间的随机数
	int count = MINE;
	while (count>0){
		row = rand() % (10 - 1 + 1) + 1;
		lie = rand() % (10 - 1 + 1) + 1;
		//printf("%d %d\n", row,lie);
		if (mineBoard[row][lie] == '0'){
			mineBoard[row][lie] = '1';
			count--;
		}
		else{
			continue;
		}
	}
}	

//可自动展示无雷区，然后把如果点到'0'，周围都打开，并且，如果周围也有'0',周围也自动打开
void voluntarily(char board[][LIE], char mineBoard[][LIE], int row, int lie){
	//先判断row和lie是否越界
	if (row >= 1 && row <= 10 && lie >= 1 && lie <= 10){
		if (isNunmber(mineBoard, row, lie) == '0'){
			if (board[row][lie] == '*'){

				board[row][lie] = '0';	//先给当前位置赋值为'0'，把周围八个位置全部递归,递归出口:(1)越界(2)周围不再有无雷区

				voluntarily(board, mineBoard, (row - 1), (lie - 1));
				voluntarily(board, mineBoard, (row - 1), (lie));
				voluntarily(board, mineBoard, (row - 1), (lie + 1));
				voluntarily(board, mineBoard, (row), (lie - 1));
				voluntarily(board, mineBoard, (row), (lie + 1));
				voluntarily(board, mineBoard, (row + 1), (lie - 1));
				voluntarily(board, mineBoard, (row + 1), (lie));
				voluntarily(board, mineBoard, (row + 1), (lie + 1));

			}
		}
		else{
			board[row][lie] = isNunmber(mineBoard, row, lie);
		}
	}
}

//判断还剩下多少*位置,就可以知道玩家什么时候胜利，知道剩下格子数减去炸弹数，但是我们有两行两列，是不用的，所以我们只统计[1-（row-2）]之间的'*'
int determine(char board[][LIE], int row, int lie){
	int count = 0;
	for (int i = 1; i <= row-2; i++){
		for (int j = 1; j <= lie-2; j++){
			if (board[i][j] == '*'){
				count++;
			}
		}
	}
	return count;
}

void mineSweepGame(){
	/*先定义两个相同大小的二维数组，行列都定义为12
	定义为12×12，但是我们只用10×10,因为扫雷边角的那些，
	都不需要判断周围8个那么多，但是我们行列都多定义了两行就可以，把用的每个都判断周围8个
	*/
	char board[ROW][LIE];	//给玩家展示的面板
	char mineBoard[ROW][LIE];	//存放地雷的面板
	
	boardInit(board,ROW,LIE,'*');	//给玩家展示的面板初始化
	boardInit(mineBoard, ROW, LIE, '0');	//给玩家展示的面板初始化

	srand((unsigned int)(time(NULL)));	//种下随机数的种子
	landMines(mineBoard,ROW,LIE);	//给存放地雷的面板，随机存放地雷

	int count = determine(board, ROW, LIE);	//记录还剩下多少个'*'
	
	while (count>MINE){
		system("cls");
		printBoard(board, ROW, LIE);	//显示面板
		//printBoard(mineBoard, ROW, LIE);	//显示地雷面板
		int row = 0;
		int lie = 0;
		printf("请输入一个位置的坐标=>:");
		scanf("%d %d",&row,&lie);

		//判断输入位置是否正确
		if (row >= 1 && row <= 10 && lie >= 1 && lie <= 10&&board[row][lie]=='*'){
			int judge = judgeMine(mineBoard, row, lie);	//判断玩家输入的位置是否为炸弹，如果是炸弹返回1，如果不是返回0；
			if (judge){
				break;
			}
			else{
				voluntarily(board, mineBoard, row, lie);	//递归实现可自动显示无雷区
			}
		}
		else{
			printf("您输入坐标有误，请重新输入!!\n");
			Sleep(1000);
		}

		count = determine(board, ROW, LIE);	//更新'*'的数量
	}

	if (count>MINE){
		printf("########################################\n");
		printf("##            您被炸死了:<            ##\n");
		printf("########################################\n");
		printBoard(mineBoard, ROW, LIE);	//显示面板
	}
	else{
		printf("########################################\n");
		printf("##          恭喜你，胜利了:>          ##\n");
		printf("########################################\n");
		printBoard(mineBoard, ROW, LIE);	//显示面板
	}
}