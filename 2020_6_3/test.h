#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

/*
杨氏矩阵
有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
要求：时间复杂度小于O(N);
*/
int findYangArray(int array[4][4], int row, int col, int value);

#endif