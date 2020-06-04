#include"test.h"

//实现一个函数，判断一个数是不是素数。
//利用上面实现的函数打印100到200之间的素数。
void isPrime(int a, int b){//a,b为传过来的区间
	int i, j;
	printf("%d-%d之间的素数为：",a,b);
	for (j = a; j < b + 1; j++){

		for (i=2; i <= sqrt(j); i++){
			if (j%i == 0){
				break;
			}
		}

		if (i>sqrt(j)){
			printf("%d ", j);
		}

	}
	printf("\n");
}

//实现函数判断year是不是润年
//返回1为闰年，返回0则不是闰年
int isLeapYear(int year){ 
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
		return 1;
	}
	else{
		return 0;
	}
}

//实现一个函数来交换两个整数的内容。
//实参传入的时候，要加&（取地址符）
void exchange(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//实现一个函数，打印乘法口诀表，口诀表的行数和列数自己指定
//如：输入9，输出9 * 9口诀表，输出12，输出12 * 12的乘法口诀表。
void mulTips(int a){//a为乘法口诀表的行和列
	for (int i = 1; i <= a; i++){
		for (int j = 1; j <= i; j++){
			printf("%d*%d=%d  ", j, i, i*j);
		}
		printf("\n");
	}
}

//递归方式实现打印一个整数的每一位
void printInt(int a){
	if (a > 9){
		printInt(a / 10);
	}

	printf("%d ", a % 10);
}

//递归实现求n的阶乘（不考虑溢出的问题）
int factorial(int n){
	if (n == 1){
		return 1;
	}

	return n*factorial(n - 1);
}

//非递归实现求n的阶乘（不考虑溢出的问题）
int factorial2(int n){
	int result = 1;
	for (int i = n; i > 1; i--){
		result *= i;
	}

	return result;
}

//递归实现strlen
int myStrlen(char *str){
	if (*str == '\0'){
		return 0;
	}
	
	return 1 + myStrlen(str + 1);
}

//非递归实现strlen
int myStrlen2(char array[]){
	int len = 0;
	for (int i=0; array[i] != '\0'; i++){
		len += 1;
	}

	return len;
}

/*编写一个函数 reverse_string(char * string)（递归实现）
实现：将参数字符串中的字符反向排列。
要求：不能使用C函数库中的字符串操作函数。*/
void reverse_string(char * string){
	if (*string != '\0'){
		reverse_string(string + 1);
	}

	if (*string != '\0'){
		printf("%c", *string);
	}
}

/*
不是递归实现，把一个字符串逆序.
*/
void reverse_string2(char * string){
	char *start = string;
	char *end = string + strlen(string) - 1;

	while (start < end){
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

//递归实现字符串逆序,我自己的思路
void reverse_string4(char * string){
	char *start = string;
	char *end = string + strlen(string) - 1;
	char temp = *start;
	*start = *end;
	*end = '\0';
	if (strlen(string ) >= 2){
		reverse_string4(string + 1);
	}
	*end = temp;
}

//递归实现字符串逆序
void reverse_string3(char * string){
	char *start = string;
	char *end = string + strlen(string) - 1;
	char temp = *start;
	*start = *end;
	*end = '\0';
	if (strlen(string + 1) >= 2){
		reverse_string3(string + 1);
	}
	*end = temp;
}


/*写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和
例如，调用DigitSum(1729)，则应该返回1+7+2+9，它的和是19
输入：1729，输出：19
*/
int DigitSum(int a){
	
	if (a > 9){
		return a%10+DigitSum(a / 10);
	}
	return a;
}

//编写一个函数实现n的k次方，使用递归实现
int nPowerK(int n, int k){
	if (k > 0){
		return n*nPowerK(n, --k);
	}
	return 1;
}

/*递归实现求第n个斐波那契数
例如：
输入：5  输出：5
输入：10， 输出：55
输入：2， 输出：1
*/
int n_Fibonacci(int n){
	if (n == 1 || n == 2){
		return 1;
	}
	return n_Fibonacci(n - 1) + n_Fibonacci(n - 2);
}

/*非递归实现求第n个斐波那契数
例如：
输入：5  输出：5
输入：10， 输出：55
输入：2， 输出：1
*/
int n_Fibonacci2(int n){
	int one = 1;
	int two = 1;
	int three = 1;
	while (n-3>=0){
		one = two;
		two = three;
		three = one + two;
		n--;
	}
	return three;
}

/*
n表示汉诺塔的层数
a表示最初承载圆盘的柱子
b表示起到中转作用的柱子
c表示需要移动到的目标柱子
*/
void hanNuo(int n, char a, char b, char c){
	if (n == 1){

	}
}