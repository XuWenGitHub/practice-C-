#include "test.h"

int main(){
	int array[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 10 };
	int array2[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int len = sizeof(array) / sizeof(array[0]);
	//printf("%d", len);
	//init(array, len);
	//printArray(array,len);

	//exchange(array, array2,len);
	//reverse(array,len);
	//bubblingSort(array, len);

	//printArray(array, len);
	//printArray(array2,len);
	char array3[] = "abcd12";
	printf("start: %s\n", array3);
	reverse_string(array3);
	printf("end: %s\n", array3);
	system("pause");
}