#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

/*把数组里偶数全部放到基数前面*/
void arraySort(int* array, int len){
	int* start = array;
	int* end = array + len - 1;
	while (1){
		while (*start % 2 == 0){
			start++;
		}
		while (*end % 2 == 1){
			end--;
		}
		if (start >= end){
			break;
		}
		*start ^= *end;
		*end ^= *start;
		*start ^= *end;
	}
}
int main(){
	int array[] = { 1, 2, 3, 4, 5, 6 };
	int len = sizeof(array) / sizeof(array[0]);
	for (int i = 0; i < len; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	arraySort(array, len);
	for (int i = 0; i < len; i++){
		printf("%d ", array[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}