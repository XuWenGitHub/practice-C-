#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#pragma warning(disable:4996)

/*正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。*/
int leastCommonMultiple(int a, int b);

/*【倒置字符串】将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I 输入描述：*/
void convertString(char* start, char* end);
#endif