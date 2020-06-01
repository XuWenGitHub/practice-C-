#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include<Windows.h>
#include<assert.h>
#include<string.h>
/*
写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
例如：给定s1 =AABCD和s2 = BCDAA，返回1
给定s1=abcd和s2=ACBD，返回0.
AABCD左旋一个字符得到ABCDA
AABCD左旋两个字符得到BCDAA
AABCD右旋一个字符得到DAABC
*/
int stringRotation(char* str, char* compStr);
int compareString(char* newStr, char* str);

/*
实现一个函数，可以左旋字符串中的k个字符。
例如：
ABCD左旋一个字符得到BCDA
ABCD左旋两个字符得到CDAB
*/
void stringRotation2(char* str,int len, int number);
#endif