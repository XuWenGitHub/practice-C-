#ifndef _CHESS_H_
#define _CHESS_H_

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

#pragma warning(disable:4996)

#define ROW 3	//行
#define COL 3	//列

#define BLACK_PIECE 'X'	//黑旗
#define WHITE_PIECE 'O'	//白棋


void game(int choose);	//choose来判断玩家选择难度
void InitBoard(char board[][COL],int row,int col);	//初始化棋盘
void showBoard(char board[][COL], int row, int col);	//给玩家看到面板
int playerMove(char board[][COL], int row, int col);	//人走一步
void ComputerMove(char board[][COL], int row, int col);	//初级电脑走一步
void middleComputerMove(char board[][COL], int row, int col);//中级电脑走一步
void seniorComputerMove(char board[][COL], int row, int col);//高级电脑走一步
int algorithm(char board[][COL], int row, int col);//算法判断
char JudgeResult(char board[][COL], int row, int col);	//判断有没有胜利



#endif