#include "test.h"

/*正整数A和正整数B 的最小公倍数是指 能被A和B整除的最小的正整数值，设计一个算法，求输入A和B的最小公倍数。*/
/*分析：
	A：求两个数的最小公倍数，那么最小的公倍数，一定是两个数中大的那一个
	B：先用三目运算符找出两个数中大的那一个，来一个while循环，一直递增，直到，找到能被A和B都整除的那个数
*/
int leastCommonMultiple(int a, int b){
	if (a == 0 || b == 0){
		return;
	}
	int max = a > b ? a : b;
	
	
	while (1){
		if (max%a == 0 && max%b == 0){
			return max;
		}
		else{
			max++;
		}
	}
}

/*【倒置字符串】将一句话的单词进行倒置，标点不倒置。比如 I like beijing. 经过函数后变为：beijing. like I 输入描述：*/
//这已经将字符串整体逆序
void convertString(char* start,char* end){
	while (start <= end){
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

//逆序每个单词
//.gnijieb ekil I
void convertWord(char* start){
	char* head = start;
	char* tail = start;
	
	while (*tail != ' '){
		tail++;
	}
	convertString(head, tail - 1);

	head = tail + 1;
	while (*head != ' '){
		head++;
	}
	convertString(tail+1, head - 1);

	tail = head + 1;
	while (*tail != '\0'){
		tail++;
	}
	convertString(head + 1, tail - 1);
}
//逆序每个单词
//.gnijieb ekil I
void convertWord2(char* start,int len){
	//目前这两个都指向.
	char* head = start-1;	
	char* tail = start;

	//如果两个指针其中一个指向了'\0'后面那个，那么就退出
	while (head != start + len&&tail != start + len){
		while (*tail != ' '&&*tail!='\0'){
			tail++;
		}
		//循环退出，head指向了单词的左边，tail，指向了单词的右边
		convertString(head + 1, tail - 1);	//这是一个，字符串逆序，从head+1，到tail-1之间，逆序
		
		//把指向单词的头指针，指向‘ ’
		head = tail;
		//指向单词的尾指针，向前移一下
		tail++;
	}
}
	
