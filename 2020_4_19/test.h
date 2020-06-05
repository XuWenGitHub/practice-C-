#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

void printArray(int *array, int len);
void bubblingSort(int *array, int len);
//实现函数init() 初始化数组为全0
void init(int *array, int len);
//实现reverse()  函数完成数组元素的逆置。
void reverse(int *array, int len);
//将数组A中的内容和数组B中的内容进行交换。（数组一样大）
void exchange(int *arrayA, int *arrayB, int len);
/*编写一个函数 reverse_string(char * string)（递归实现）
实现：将参数字符串中的字符反向排列。
要求：不能使用C函数库中的字符串操作函数。
*/
void reverse_string(char * string);
#endif