#include "test.h"

//int i;
int main(){

	//printf("%d\n", binaryDifference(1999, 2299));
	//printBinary(2299);
	//printf("%d\n", binaryOne(-1));

	/*int a = 10;
	int b = 20;
	printf("after: a=%d,b=%d\n", a, b);
	temp(&a, &b);
	printf("end: a=%d,b=%d\n", a, b);*/
	

	/*int i = 1;
	int ret = (++i) + (++i) + (++i);
	printf("ret = %d\n", ret);*/

	/*i--;
	if (i > sizeof(i))
	{
		printf(">\n");
	}
	else
	{
		printf("<\n");
	}*/
	
	/*int arr[] = { 1, 2, 3, 4, 5 };
	short *p = (short*)arr;
	int i = 0;
	for (i = 0; i<4; i++)
	{
		*(p + i) = 0;
	}

	for (i = 0; i<5; i++)
	{
		printf("%d ", arr[i]);
	}*/


	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int len = sizeof(array) / sizeof(array[0]);
	printArray(array,len);
	

	system("pause");
}