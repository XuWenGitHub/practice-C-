#include"test.h"

#include<string.h>

/*
该方法为求一个字符串的长度,返回-1，表示实参为NULL
*/
int myStrlen(const char* str){
	/*因为是求字符串的长度，所以const修饰*，表示不能通过该指针去修改指向的目标，也给其他程序员表示意思，该指针指向的目标不要改*/
	
	int len = 0;	//统计字符串的长度，最后返回len

	//遇到指针，就要判断，指针是否为空
	if (NULL == str){
		return -1;
	}

	//对str解引用，字符串最后都是以'\0'结尾，如果str不为'\0'，那么便一直循环，指针变量str再往后移一个
	while (*str != '\0'){
		str++;	//str一开始指向的字符串的第一个字符
		len++;
	}

	return len;
}

/*
myStrcpy实现:字符串的复制，包含'\0'
scr：为数据源
dest：为目的地
*/
char* myStrcpy(const char* src, char* dest){
	//因为把src为数据源，所以就const修饰*,这样，就不能通过指针src通过解引用去修改数据源
	if (src == NULL){
		return;
	}

	while ('\0' != *src){
		*dest = *src;
		src++;
		dest++;
	}

	*dest = '\0';
}

/*调整数组使奇数全部都位于偶数前面。

题目：
输入一个整数数组，实现一个函数，
来调整该数组中数字的顺序使得数组中,
所有的奇数位于数组的前半部分，
所有偶数位于数组的后半部分。
*/
/*
分析：这个要两层循环，外循环，遍历到每一个元素，然后判断该元素是基数还是偶数？
		如果是基数：
			continue，跳出本次循环，进入下一次循环
		如果是偶数：
			则从外层循环遍历该偶数的下一个数，开始循环
			判断后面有无基数？
				有基数：
					就把第一个基数和外层循环找的偶数调换位置,然后break
				无基数：
					那就说明该偶数后面，也全部都是偶数，便可以return
*/
void adjustBasi(int array[], int len){
	for (int i = 0; i < len; i++){
		if (1 == array[i] % 2){
			//continue，跳出本次循环，进入下一次循环
			continue;
		}
		else{
			int j = 0;
			//则从外层循环遍历该偶数的下一个数，开始循环,判断后面有无基数？

			for (j = i+1; j < len; j++){
				if (1 == array[j] % 2){
					//后面有基数，把基数和外层循环找到的偶数交换位置,然后break
					int temp = array[i];
					array[i] = array[j];
					array[j] = temp;
					break;
				}
			}

			if (j == len ){
				//那就说明该偶数后面，也全部都是偶数，便可以return
				return;
			}

		}		
	}
}