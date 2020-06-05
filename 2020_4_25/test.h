#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

//求两个数二进制中不同位的个数
int binaryDifference(int a, int b);

//打印整数二进制的奇数位和偶数位
void printBinary(int a);

//统计二进制中1的个数
int binaryOne(int a);

//交换两个变量（不创建临时变量）
void temp(int *a, int *b);

//使用指针打印数组内容
/*写一个函数打印arr数组的内容，不使用数组下标，使用指针。
arr是一个整形一维数组。*/
void printArray(int *arr,int len);

#endif