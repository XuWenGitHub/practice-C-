#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>
#include<string.h>
#pragma warning(disable:4996)

//��һ���ַ���ת��һ��int���͵�����������'\0'���߲��������ַ�����������ַ����е�һ�������������ַ�����ôֱ�ӷ���0
int myAtoi(char* str);

//ģ��ʵ��strncat
char* myStrncat(char* dest, const char* src, size_t num);

//ģ��ʵ��strncpy
char* myStrcpy(char* dest, const char* src, size_t num);

/*һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
��дһ�������ҳ�������ֻ����һ�ε����֡�*/
void findSingleDog(int **singleDog, int arr[], int len);
#endif