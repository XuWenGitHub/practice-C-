#include"test.h"

int main(){
	//unsigned long pulArray[] = { 6, 7, 8, 9, 10 };
	//unsigned long *pulPtr;
	//pulPtr = pulArray;
	//*(pulPtr + 3) += 3;	//*(pulPtr + 3) = *(pulPtr + 3)+3;
	//printf("%d, %d\n", *pulPtr, *(pulPtr + 3));

	char str[]= "abc";
	//int len = sizeof(str) / sizeof(str[0]);
	printf("%s\n", str);

	stringInverted(str, strlen(str));

	printf("%s\n", str);

	printf("%d\n", plusResult(2,5));
	printf("%d\n", 2 + 22 + 222 + 2222 + 22222);

	system("pause");
}