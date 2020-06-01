#ifndef _TEST_H_
#define _TEST_H_

#include<stdio.h>
#include<Windows.h>
#pragma warining(disable:4996)

//字符串逆序
void stringInverted(char *str, int len);

/*求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，
例如：2+22+222+2222+22222*/
int plusResult(int a,int n);
#endif