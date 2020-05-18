#define _CRT_SECURE_NO_WARNINGS         //说scanf语句不安全的治理方法（error c4996)
#pragma warning(disable:4996)           //处理printf显示未定义标识符
#include<stdio.h>
#include<math.h>
int main(){
	int num, i;
	printf("只能被1或者自身整数的数为素数\n");
	printf("请输入一个整数: \n");
	scanf("%d", &num);
	if (num <= 1)
		printf("%d不是素数\n", num);
	else{
		for (i = 2; i <= sqrt(num); i++){
			if (num%i == 0) break;
		}
		if (i > sqrt(num))
			printf("%d是素数\n", num);
		else
			printf("%d不是素数\n", num);   
	}
		system("pause"); //显示屏停顿
		return 0;
	
}