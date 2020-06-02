#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

//这个方法写的有一点长，为了提高方法的健壮性

//打印1000年到2000年之间的闰年

/*

如果不能被4整除，则不是闰年

如果能被4整除，且不能被100整除，则为闰年

如果能被100整除，且能被400整除，则为闰年

如果能被100整除，但不能被400整除，则不是闰年

上面四句话，百度搜的，因为我也不知道什么是闰年。



*/

void printfLeapYear(int a, int b){

	while (1){

		//这里一直while循环，但是如果满足下面如果条件，最后有一个break，跳出while循环，如果不满足这个要求，就一直让客户重新输入正确的数

		if (b > a && a>0 && b>0){
			for (int i = b; i >= a; i--){
				//如果不能被4整除，则不是闰年
				if (i % 4 == 0){
					if (i % 100 != 0){
						//如果能被4整除，且不能被100整除，则为闰年
						printf("%d为闰年\n", i);
					}
					else{
						//如果能被100整除，且能被400整除，则为闰年
						if (i % 400 == 0){
							printf("%d为闰年\n", i);
						}
					}
				}
			}



			break;

		}
		else{

			printf("输入数字有误！！！\n");

			printf("请重新输入一个数后按空格再输入另一个数，最后按下回车！！！\n\n");

			printf("请重新输入a和b的值( b>a 且 a和b>0 ):");

			scanf("%d %d", &a, &b);

		}

	}

}
//void main(){
//	printfLeapYear(1000, 2000);
//	system("pause");
//}