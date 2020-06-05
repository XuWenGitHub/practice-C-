#include "test.h"

//求两个数二进制中不同位的个数
/*编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
输入例子:
1999 :0111 1100 1111 
2299 :1000 1111 1011‬
输出例子:7*/
int binaryDifference(int a, int b){
	//先把a,b两个数^得到一个新的数,相同为0，不同为1，然后再求新的数字里面有多少个1
	int number = a^b;
	//再求number中有多少个1
	int count = 0;	//统计有多少个1,1的个数就是a,b两个数二进制表达中，多少个bit位不同
	while (number){
		number &= (number - 1);
		count++;
	}
	return count;
}

//打印整数二进制的奇数位和偶数位
/*获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列*/
void printBinary(int n){
	printf("偶数位：");
	for (int i = 31; i >0; i -= 2){
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
	printf("奇数位：");
	for (int i = 30; i >=0; i -= 2){
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
}

//统计二进制中1的个数
/*写一个函数返回参数二进制中 1 的个数。
比如： 15    0000 1111    4 个 1
*/
int binaryOne(int a){
	int count = 0;
	while (a){
		a &= (a - 1);
		count++;
	}
	return count;
}

//交换两个变量（不创建临时变量）
/*不允许创建临时变量，交换两个整数的内容*/
void temp(int *a, int *b){
	//通过我们知道a^b^a等于b
	*a = *b^*a;
	*b = *a^*b;
	*a = *b^*a;
}

//使用指针打印数组内容
/*写一个函数打印arr数组的内容，不使用数组下标，使用指针。
arr是一个整形一维数组。*/
void printArray(int *arr,int len){
	for (int i = 0; i < len; i++){
		printf("%d ", *arr);
		arr++;
	}
}