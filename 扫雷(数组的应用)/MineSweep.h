#ifndef _MINESWEEP_H_
#define _MINESWEEP_H_

#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

#define ROW 12	//��
#define LIE 12	//��
#define MINE 20	//���׸���

int determine(char board[][LIE], int row, int lie);	//�жϻ�ʣ�¶���*λ��,�Ϳ���֪�����ʲôʱ��ʤ����֪��ʣ�¸�������ȥը�����������������������У��ǲ��õģ���������ֻͳ��[1-��row-2��]֮���'*'
void voluntarily(char board[][LIE], char mineBoard[][LIE], int row, int lie);	//���Զ�չʾ��������Ȼ�������㵽'0'����Χ���򿪣����ң������ΧҲ��'0',��ΧҲ�Զ���
void boardInit(char mineBoard[][LIE], int row, int lie, char ch);	//������ʼ��	���һ���β�Ϊ������ʼ��Ϊʲô���ַ���
char isNunmber(char mineBoard[][LIE], int row, int lie);	//ȷ��mineBoard[row][lie]����ը������������Χը���ĸ������������ַ���
int judgeMine(char mineBoard[][LIE], int row, int lie);	//�ж����ѡ��λ���Ƿ���ը��,����1������ը��������0����ը��
void printBoard(char mineBoard[][LIE], int row, int lie);	//��ʾ���
void landMines(char mineBoard[][LIE],int row,int lie);	//����ŵ��׵���壬������20�ŵ���,�ַ�1�����ǵ��ף��ַ�0�����޵���
void mineSweepGame();	//ɨ����Ϸ

#endif