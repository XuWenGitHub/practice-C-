#include<stdio.h>
#include<Windows.h>
//写一个宏，可以将一个整数字的奇数位和偶数位交换
//把n的二进制中奇数位和偶数位互换，左边是n的奇数位左移一位，右边是n的偶数位右移一位，两者|，便是最后结果
#define CHANGE(n) (((n&(0x55555555))<<1)|((n&(0xAAAAAAAA))>>1))
/*
写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明(offsetof宏)
*/
/*
structur：结构体变量的地址，也就是首地址	例如结构体变量p，传参传&p
variable：需要求结构体中某变量	例如结构体变量p，传参传&p.结构体中某变量名
把上面两个地址，强转成char*类型，然后(char*)variable-(char*)structur,便可算出variable的偏移量
*/
#define OFFSETOF(variable,structur) (((char*)variable)-((char*)structur))
typedef struct Person{
	char a;
	int b;
	double c;
}person;
int main(){
	person p;
	printf("偏移量为：%d\n", OFFSETOF(&p.c, &p));
	int a =100;
	printf("%d\n", CHANGE(a));

	system("pause");
	return 0;//110 0100		
			// 110 0010
}