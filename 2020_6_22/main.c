#include"test.h"


int main(){

	int arr[] = { 1, 6, 3, 3, 1, 4, 5, 4, 5, 6,10,20 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int* p = NULL;
	findSingleDog(&p, arr, len);
	printf("µ•…Ìπ∑£∫%d %d\n", p[0], p[1]);
	free(p);





	//char str1[50] = {"word"};
	//char str2[50] = { "hello world" };
	//myStrcpy(str1, str2, 3);
	//printf("%s\n", str1);



	//int a;
	//char str[] = { "12321a31" };
	//a = myAtoi(str);
	//printf("%d\n", a);
	//int b = (int)('0'-48);
	//printf("%d\n", b);


	system("pause");
	return 0;
}