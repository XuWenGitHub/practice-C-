#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

//���������������в�ͬλ�ĸ���
int binaryDifference(int a, int b);

//��ӡ���������Ƶ�����λ��ż��λ
void printBinary(int a);

//ͳ�ƶ�������1�ĸ���
int binaryOne(int a);

//����������������������ʱ������
void temp(int *a, int *b);

//ʹ��ָ���ӡ��������
/*дһ��������ӡarr��������ݣ���ʹ�������±꣬ʹ��ָ�롣
arr��һ������һά���顣*/
void printArray(int *arr,int len);

#endif