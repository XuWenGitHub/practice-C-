#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

//给定两个数，求这两个数的最大公约数
/*
	分析：
		A：正数才有约数(如果两个数有一个为负数，则返回-1)
		B：两个数的最大公约数，肯定比两个数中小的那一个数小或者相等。
		C：先判断两个数，谁小或者相等
				a小或b小：用for循环，给i初始值为a，b中小的那个，循环条件：i>0，i--，然后再判断a，b对i取余，如果都为0，返回最大公约数i
				a和b相等：那么他们之间最大的公约数就是为：他们本身
*/
int greatestCommonDivisor( int a, int b ){
	//正数才有约数,且不为0
	if(a > 0 && b > 0){

		//两个数的最大公约数，肯定比两个数中小的那一个数小或者相等。
		//先判断两个数，谁小或者相等
		if (a > b){
			for (int i = b; i > 0; i--){
				if (a%i == 0 && b%i==0){
					return i;
				}
			}
		}
		else if (a < b){
			for (int i = a; i>0; i--){
				if (b%i == 0 && a%i==0){
					return i;
				}
			}
		}
		else{
			//两个数相等，最大公约数，为本身
			return a;
		}

	}
	
	//如果两个数任意一个为负数，则没有公约数，返回-1；
	return -1;
}

//辗转相减法，因为a和b都可以看成n个最大公约数之和
int greatestCommonDivisor2(int a, int b){
	while (1){
		if (a > b){
			a -= b;
		}
		else if(b>a){
			b -= a;
		}
		else{
			break;
		}
	}

	return a;
}

//辗转求余法，每一次大的被小的求余，余数赋给大的，然后循环，直到其中一个变为0，那么另一个就是两个数的最大公约数
int greatestCommonDivisor3(int a, int b){
	while (a*b != 0){
		if (a > b){
			a %= b;
		}
		else if (b > a){
			b %= a;
		}
		else{
			break;
		}
	}

	return a == 0 ? b : a;
}
void main(){
	printf("%d\n", greatestCommonDivisor(14, 7));
	printf("%d\n", greatestCommonDivisor2(50, 20));
	printf("%d\n", greatestCommonDivisor3(122, 2));
	system("pause");
}