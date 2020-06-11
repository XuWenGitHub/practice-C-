#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<assert.h>
#pragma warning(disable:4996)

/*
模拟实现strstr
*/
char* myStrstr(const char* str1, const char* str2);


/*
模拟实现memcpy
*/
void* myMemcpy(void* dest, const void* src, size_t size);


#endif