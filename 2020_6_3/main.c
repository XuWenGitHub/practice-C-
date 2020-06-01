#include"test.h"


int main(){
	/*
	ÑîÊÏ¾ØÕó
	1  2  8   9
	2  4  9   12
	4  7  10  13
	6  8  11  15

	²éÕÒ7
	*/
	int array[4][4] = {  1, 2, 8, 9 ,2, 4, 9, 12 , 4, 7, 10, 13 , 6, 8, 11, 15  };
	int select = findYangArray(array, 4, 4, 15);
	printf("%d\n", select);
	system("pause");
}