#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

int myStrlen(const char* str);

/*
myStrcpyʵ��,�ַ����ĸ��ƣ�����'\0'
scr��Ϊ����Դ
dest��ΪĿ�ĵ�
*/
char *myStrcpy(const char* src, char* dest);

/*��������ʹ����ȫ����λ��ż��ǰ�档

��Ŀ��
����һ���������飬ʵ��һ��������
�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
����ż��λ������ĺ�벿�֡�
*/
void adjustBasi(int *arr, int len);
#endif