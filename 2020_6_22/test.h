#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>
#include<string.h>
#pragma warning(disable:4996)

//把一个字符串转成一个int类型的整数，遇到'\0'或者不是数字字符结束，如果字符串中第一个都不是数字字符，那么直接返回0
int myAtoi(char* str);

//模拟实现strncat
char* myStrncat(char* dest, const char* src, size_t num);

//模拟实现strncpy
char* myStrcpy(char* dest, const char* src, size_t num);

/*一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
编写一个函数找出这两个只出现一次的数字。*/
void findSingleDog(int **singleDog, int arr[], int len);
#endif