#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include<Windows.h>
#include<assert.h>
#pragma warning(disable:4996)

/*ģ��qsort�Ĺ���ʵ��һ��ͨ�õ�ð������*/
void myBubbleSort(void* base, int num, int size, int(*compare)(const void*, const void*));

int compareInt(const void*, const void*);

void swap(char* px, char* py, int size);

int compareDouble(const void*vx, const void*vy);

//byte�������ͱȽ�
int compareByte(const void*vx, const void*vy);

//short�������ͱȽ�
int compareShort(const void*vx, const void*vy);

int compareChar(const void*vx, const void *vy);
#endif