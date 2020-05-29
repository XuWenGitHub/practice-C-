#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

int myStrlen(const char* str);

/*
myStrcpy实现,字符串的复制，包含'\0'
scr：为数据源
dest：为目的地
*/
char *myStrcpy(const char* src, char* dest);

/*调整数组使奇数全部都位于偶数前面。

题目：
输入一个整数数组，实现一个函数，
来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
所有偶数位于数组的后半部分。
*/
void adjustBasi(int *arr, int len);
#endif