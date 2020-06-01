#include"test.h"


int main(){
	char array[10] = {'d','a','b','c','d','e','f','g','A'};
	int num = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < num; i++){
		printf("%c ", array[i]);
	}
	printf("\n");
	//qsort(array, num, 4,compareInt);
	//myBubbleSort(array, num, sizeof(double), compareDouble);
	qsort(array, num, sizeof(char), compareChar);
	for (int i = 0; i < num; i++){
		printf("%c ", array[i]);
	}

	system("pause");
}