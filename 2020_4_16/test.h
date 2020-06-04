#ifndef _TEST_H
#define _TEST_H

#include<stdio.h>
#include<Windows.h>
#include<math.h>
#pragma warning(disable:4996)

//实现一个函数，判断一个数是不是素数。
//利用上面实现的函数打印100到200之间的素数。
void isPrime(int a,int b);

//实现函数判断year是不是润年
int ifLeapYear(int year);

//实现一个函数来交换两个整数的内容。
void exchange(int *a, int *b);

//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
//如：输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。
void mulTips(int a);

//递归方式实现打印一个整数的每一位
void printInt(int a);

//递归实现求n的阶乘（不考虑溢出的问题）
int factorial(int n);

//非递归实现求n的阶乘（不考虑溢出的问题）
int factorial2(int n);

//递归实现strlen
int myStrlen(char *str);

//非递归实现strlen
int myStrlen2(char array[]);


/*编写一个函数 reverse_string(char * string)（递归实现）
实现：将参数字符串中的字符反向排列。
要求：不能使用C函数库中的字符串操作函数。*/
void reverse_string(char * string); //递归实现直接输出逆序字符串
void reverse_string2(char * string); //非递归实现让一个字符串逆序
void reverse_string3(char * string); //递归实现字符串逆序  蛋哥讲的

void reverse_string4(char * string);//递归实现字符串逆序,我自己的思路

/*写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
例如，调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19
输入：1729，输出：19
*/
int DigitSum(int a);

//编写一个函数实现n的k次方，使用递归实现
int nPowerK(int n, int k);

/*递归实现求第n个斐波那契数
例如：
输入：5  输出：5
输入：10， 输出：55
输入：2， 输出：1
*/
int n_Fibonacci(int n);

/*非递归实现求第n个斐波那契数
例如：
输入：5  输出：5
输入：10， 输出：55
输入：2， 输出：1
*/
int n_Fibonacci2(int n);

/*
递归实现汉诺塔问题
n表示汉诺塔的层数
a表示最初承载圆盘的柱子
b表示起到中转作用的柱子
c表示需要移动到的目标柱子
*/
void hanNuo(int n, char a, char b, char c);
#endif