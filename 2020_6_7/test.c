#include"test.h"

/*
写一个函数，判断一个字符串是否为另外一个字符串旋转之后的字符串。
例如：给定s1 =AABCD和s2 = BCDAA，返回1
给定s1=abcd和s2=ACBD，返回0.
AABCD左旋一个字符得到ABCDA
AABCD左旋两个字符得到BCDAA
AABCD右旋一个字符得到DAABC
*/
/*
分析：
A：实现任意次数的左旋
B：再逐次进行左旋，然后不断进行比较
*/





//方法1：实现任意次数的左旋
//然后再用左旋后的字符串，然后和需要比较的字符串进行比较
//实现一个字符串任意次数的左旋
void LeftRotate(char* str, int len, int num){
	assert(str);
	assert(len > 0);
	assert(num >= 0);

	num %= len;	//去重复，因为当一个字符串长度为3，左旋三次，又变成本身了

	while (num){
		char temp = str[0];
		for (int i = 1; i < len; i++){
			str[i - 1] = str[i];	//除了第一个，其他的左移一下
		}
		str[len - 1] = temp;
		num--;
	}
}



//方法2：先划分字符串(划分成两个字符串，第一个字符串的长度就是num(字符串需要逆置的次数),第二个字符串就是剩下的)
//字符串逆置函数
//例如：abcd1234	要左旋4下
//		dcba4321	左旋n下，就把前n个字符逆置一下，后面剩余的再逆置一下
//		1234abcd	再整体逆置一下，就变成了左旋4下
void LeftRotate2(char* str, int len, int num){
	assert(str);
	assert(len > 0);
	assert(num >= 0);

	num %= len;	//去重复，因为当一个字符串长度为3，左旋三次，又变成本身了
	//方法2
	//划分的两个字符串的分别逆置
	Reverse(str, 0, num - 1);
	Reverse(str, num, len - 1);

	//再整体字符串的逆置
	Reverse(str, 0, len - 1);
}

//字符串的一部分逆置
void Reverse(char *str, int start, int end){
	assert(str);
	while (start < end){
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}



//方法3		牺牲空间来换取时间
//穷举所有的旋转串,只要str2是str1的双倍串的子串，就OK
//先把一个字符串变成一个双倍串
//例如 1234abcd -> 1234abcd1234abcd
//如果旋转一次，就从第2个字符到第9个字符
void LeftRotate3(char* str, int len, int num){
	assert(str);
	assert(len > 0);
	assert(num >= 0);

	num %= len;	//去重复，因为当一个字符串长度为3，左旋三次，又变成本身了




}