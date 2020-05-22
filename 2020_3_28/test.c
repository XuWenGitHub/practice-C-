#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
#include<windows.h>

//这是一个两个整型的数，求其中最大值的函数

//函数名：maxNumber

/*形式参数：

compareNumberOne是第一个参与比较的数

compareNumberTwo是第二个参与比较的数*/


void maxNumber(){
	int compareNumberOne;
	int compareNumberTwo;
	printf("请输入第一个数：\n");
	scanf("%d", &compareNumberOne);
	printf("请输入第二个数：\n");
	scanf("%d", &compareNumberTwo);
	//printf("请输入两个数：\n");
	//scanf("%d %d", &compareNumberOne, &compareNumberTwo);
	int maxNumber = 0; //给最大值初始化

	if (compareNumberOne>compareNumberTwo){

		maxNumber = compareNumberOne;

	}
	else{

		maxNumber = compareNumberTwo;

	}
	
	printf("%d和%d中最大值为：%d\n", compareNumberOne, compareNumberTwo, maxNumber);
}
int main(){
	/*char array[] = { 'b', 'i', 't' };
	printf("%d\n", strlen(array));
	printf("%d\n", strlen("c:\test\121"));*/
	
	maxNumber();
	system("pause");
	return 0;		 
}