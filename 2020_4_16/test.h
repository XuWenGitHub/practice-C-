#ifndef _TEST_H
#define _TEST_H

#include<stdio.h>
#include<Windows.h>
#include<math.h>
#pragma warning(disable:4996)

//ʵ��һ���������ж�һ�����ǲ���������
//��������ʵ�ֵĺ�����ӡ100��200֮���������
void isPrime(int a,int b);

//ʵ�ֺ����ж�year�ǲ�������
int ifLeapYear(int year);

//ʵ��һ�������������������������ݡ�
void exchange(int *a, int *b);

//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��
//�磺����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���
void mulTips(int a);

//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
void printInt(int a);

//�ݹ�ʵ����n�Ľ׳ˣ���������������⣩
int factorial(int n);

//�ǵݹ�ʵ����n�Ľ׳ˣ���������������⣩
int factorial2(int n);

//�ݹ�ʵ��strlen
int myStrlen(char *str);

//�ǵݹ�ʵ��strlen
int myStrlen2(char array[]);


/*��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
ʵ�֣��������ַ����е��ַ��������С�
Ҫ�󣺲���ʹ��C�������е��ַ�������������*/
void reverse_string(char * string); //�ݹ�ʵ��ֱ����������ַ���
void reverse_string2(char * string); //�ǵݹ�ʵ����һ���ַ�������
void reverse_string3(char * string); //�ݹ�ʵ���ַ�������  ���署��

void reverse_string4(char * string);//�ݹ�ʵ���ַ�������,���Լ���˼·

/*дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
���磬����DigitSum(1729)����Ӧ�÷���1+7+2+9�����ĺ���19
���룺1729�������19
*/
int DigitSum(int a);

//��дһ������ʵ��n��k�η���ʹ�õݹ�ʵ��
int nPowerK(int n, int k);

/*�ݹ�ʵ�����n��쳲�������
���磺
���룺5  �����5
���룺10�� �����55
���룺2�� �����1
*/
int n_Fibonacci(int n);

/*�ǵݹ�ʵ�����n��쳲�������
���磺
���룺5  �����5
���룺10�� �����55
���룺2�� �����1
*/
int n_Fibonacci2(int n);

/*
�ݹ�ʵ�ֺ�ŵ������
n��ʾ��ŵ���Ĳ���
a��ʾ�������Բ�̵�����
b��ʾ����ת���õ�����
c��ʾ��Ҫ�ƶ�����Ŀ������
*/
void hanNuo(int n, char a, char b, char c);
#endif