#include "test.h"

/*编写一个函数 reverse_string(char * string)（递归实现）
实现：将参数字符串中的字符反向排列。
要求：不能使用C函数库中的字符串操作函数。
*/
void reverse_string(char * string){
	char *start = string;
	char *end = string + strlen(string) - 1;
	char temp = *start;
	*start = *end;
	*end = '\0';
	if (strlen(string) >2) {
		reverse_string(string + 1);
	}
	*end = temp;
}


//将数组A中的内容和数组B中的内容进行交换。（数组一样大）
void exchange(int *arrayA, int *arrayB, int len){
	for (int i = 0; i < len; i++){
		int temp = arrayA[i];
		arrayA[i] = arrayB[i];
		arrayB[i] = temp;
	}
}


//实现reverse()  函数完成数组元素的逆置。
void reverse(int *array, int len){
	for (int i = 0, j = len - 1; i <= j; i++, j--){
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

void printArray(int *array, int len){
	printf("[");
	for (int i = 0; i < len; i++){
		printf("%d ,", array[i]);
	}
	printf("]\n");
}

void bubblingSort(int *array, int len){

	for (int i = 0; i < len - 1; i++){
		int flag = 1;
		for (int j = 0; j < len - 1 - i; j++){
			if (array[j]>array[j + 1]){
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				flag = 0;
			}
		}
		if (flag){
			break;
		}
	}
}

void init(int *array, int len){
	for (int i = 0; i < len; i++){
		array[i] = 0;
	}
}