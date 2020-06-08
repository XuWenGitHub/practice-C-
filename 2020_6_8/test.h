#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include<Windows.h>

#include<assert.h>
#pragma warning(disable:4996)

//模拟实现strcat	字符串的拼接
char* myStrcat(char* dest, const char* src);
int myStrcmp(const char* str1, const char* str2);
char* myStrcpy(char* dest, const char* src);
char* myStrcpy(char* dest, const char* src);
int myStrlen3(const char* str);
int myStrlen2(const char* str);
int myStrlen1(const char* str);
#endif