#include "test.h"

/*��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
ʵ�֣��������ַ����е��ַ��������С�
Ҫ�󣺲���ʹ��C�������е��ַ�������������
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


//������A�е����ݺ�����B�е����ݽ��н�����������һ����
void exchange(int *arrayA, int *arrayB, int len){
	for (int i = 0; i < len; i++){
		int temp = arrayA[i];
		arrayA[i] = arrayB[i];
		arrayB[i] = temp;
	}
}


//ʵ��reverse()  �����������Ԫ�ص����á�
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