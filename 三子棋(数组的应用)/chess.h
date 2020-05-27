#ifndef _CHESS_H_
#define _CHESS_H_

#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

#pragma warning(disable:4996)

#define ROW 3	//��
#define COL 3	//��

#define BLACK_PIECE 'X'	//����
#define WHITE_PIECE 'O'	//����


void game(int choose);	//choose���ж����ѡ���Ѷ�
void InitBoard(char board[][COL],int row,int col);	//��ʼ������
void showBoard(char board[][COL], int row, int col);	//����ҿ������
int playerMove(char board[][COL], int row, int col);	//����һ��
void ComputerMove(char board[][COL], int row, int col);	//����������һ��
void middleComputerMove(char board[][COL], int row, int col);//�м�������һ��
void seniorComputerMove(char board[][COL], int row, int col);//�߼�������һ��
int algorithm(char board[][COL], int row, int col);//�㷨�ж�
char JudgeResult(char board[][COL], int row, int col);	//�ж���û��ʤ��



#endif