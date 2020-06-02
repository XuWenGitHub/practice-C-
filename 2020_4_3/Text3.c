#include<stdio.h>
#include<Windows.h>
#include<math.h>
#pragma warning(disable:4996)

//写一个代码：打印100~200之间的素数
/*
	素数：只能被1和本身整除的数字
	一个数，能被整除的话，一定最大被除的数，应该是本身开更号，提高了效率
*/
void printfPrimeNumber(int a, int b){
	int i,j;
	if (b>=a){
		for (i = a; i <= b; i++){

			//如果a为负数的话，那么也可以执行，挺高了代码的健壮性
			//因为素数为大于1的数嘛
			if (i > 1){
				//一个数，能被整除的话，一定最大被除的数，应该是本身开更号，提高了效率
				for (j = 2; j <= sqrt(i); j++){
					if (i%j == 0){
						break;
					}
				}

				if (j > sqrt(i)){
					printf("%d是素数\n", i);
				}
			}

		}
	}
	else{
		printf("数据有误\n");
		printf("(b>a)!!!!!!");
	}
}
//void main(){
//	printfPrimeNumber(-100, 1000);
//	system("pause");
//}