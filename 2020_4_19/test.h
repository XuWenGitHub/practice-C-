#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

void printArray(int *array, int len);
void bubblingSort(int *array, int len);
//ʵ�ֺ���init() ��ʼ������Ϊȫ0
void init(int *array, int len);
//ʵ��reverse()  �����������Ԫ�ص����á�
void reverse(int *array, int len);
//������A�е����ݺ�����B�е����ݽ��н�����������һ����
void exchange(int *arrayA, int *arrayB, int len);
/*��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
ʵ�֣��������ַ����е��ַ��������С�
Ҫ�󣺲���ʹ��C�������е��ַ�������������
*/
void reverse_string(char * string);
#endif