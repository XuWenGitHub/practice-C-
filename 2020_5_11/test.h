#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include<Windows.h>
#include<math.h>
#pragma warning(disable:4996)

/*求出0～100000之间的所有“水仙花数”并输出。
“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如:153＝1^3＋5^3＋3^3，则153是一个“水仙花数”。*/
void daffodilNumber(int start, int end);

/*用C语言在屏幕上输出以下图案：
	打印菱形
*/
void printRhombus();
#endif