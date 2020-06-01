#include"test.h"

int compareString(char* newStr, char* str){
	assert(newStr);
	assert(str);
	char* start = newStr;
	char* start2 = str;
	for (;*start != '\0'&&*start2 != '\0'; start++, start2++){
		if (*start == *start2){
			continue;
		}
		else{
			return 0;
		}
	}

	return 1;
}

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
	A:弄一个数组把原字符串装起来
*/
int stringRotation(char* str, char* compStr, int((*comparestring)(char* str, char* compstr))){
	char* start = str;	//指向A

	//左旋转
	for (int i = 0; i < 5; i++){
		//每次循环出一个变成一个新的字符串

		char frist = *start;	//每次保存第一个字符，待会儿放在最后面去
		for (int j = 1; j < 5; j++){
			start[j - 1] = start[j];	//把除了第一个，后面的都往前移一个
		}
		start[4] = frist;	//然后再把第一个放到最后一个去

		
		//然后需要比较的字符串，与旋转后的比较，看是否一样，如果一样返回1，如果不一样返回0
		if ((*compareString)(str,compStr)==1){
			return 1;
		}
		else{
			continue;
		}
	}

	//右旋转
	for (int i = 0; i < 5; i++){
		//每次循环出一个变成一个新的字符串

		char last = *(start+4);	//每次保存最后一个字符，待会儿放到最头去
		for (int j = 0; j<4; j++){
			start[j + 1] = start[j];	//把除了最后一个，前面的都往后移一个
		}
		start[0] = last;	//然后再把最后一个放到第一个去


		//然后需要比较的字符串，与旋转后的比较，看是否一样，如果一样返回1，如果不一样返回0
		if ((*compareString)(str, compStr) == 1){
			return 1;
		}
		else{
			continue;
		}
	}

	return 0;
}

/*
实现一个函数，可以左旋字符串中的k个字符。
例如：
ABCD左旋一个字符得到BCDA
ABCD左旋两个字符得到CDAB
*/
/*
分析：
	A：ABCD -> BCDA->CDAB
	B：发现规律，每次把第一个字符后面的字符，除了'\0'，都往前移一下，再把第一个字符，放到最后面去
	C：如果左旋一个字符，就只需要循环一次，如果左旋2个字符，就只需要循环2次
*/
//str是传过来数组降维成的指针，len字符串的长度，number是需要旋转几个字符
void stringRotation2(char* str,int len,int number){
	//外层循环控制左旋几个字符
	for (int i = 0; i < number; i++){
		//每次循环，先把第一个字符给存起来
		char frist = *str;
		
		for (int i = 1; i < len; i++){
			str[i - 1] = str[i];	//从第二个字符开始，到'\0'，结束，都往前移一下
		}

		//最后再把开始存的第一个字符，放到字符数组的最后一个字符位置去
		*(str + len - 1) = frist;
	}
}

