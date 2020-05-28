#ifndef _MINESWEEP_H_
#define _MINESWEEP_H_

#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

#define ROW 12	//行
#define LIE 12	//列
#define MINE 20	//地雷个数

int determine(char board[][LIE], int row, int lie);	//判断还剩下多少*位置,就可以知道玩家什么时候胜利，知道剩下格子数减去炸弹数，但是我们有两行两列，是不用的，所以我们只统计[1-（row-2）]之间的'*'
void voluntarily(char board[][LIE], char mineBoard[][LIE], int row, int lie);	//可自动展示无雷区，然后把如果点到'0'，周围都打开，并且，如果周围也有'0',周围也自动打开
void boardInit(char mineBoard[][LIE], int row, int lie, char ch);	//给面板初始化	最后一个形参为把面板初始化为什么‘字符’
char isNunmber(char mineBoard[][LIE], int row, int lie);	//确定mineBoard[row][lie]不是炸弹，返回他周围炸弹的个数，但是是字符。
int judgeMine(char mineBoard[][LIE], int row, int lie);	//判断玩家选的位置是否是炸弹,返回1，则是炸弹，返回0则不是炸弹
void printBoard(char mineBoard[][LIE], int row, int lie);	//显示面板
void landMines(char mineBoard[][LIE],int row,int lie);	//给存放地雷的面板，随机存放20颗地雷,字符1代表是地雷，字符0代表无地雷
void mineSweepGame();	//扫雷游戏

#endif