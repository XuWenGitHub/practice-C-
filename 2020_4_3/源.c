#include<stdio.h>
#include<Windows.h>
#include<math.h>
#pragma warning(disable:4996)

void printfLeapYear1(int a, int b){

	while (1){

		//这里一直while循环，但是如果满足下面如果条件，最后有一个break，跳出while循环，如果不满足这个要求，就一直让客户重新输入正确的数

		if (b > a && a > 0 && b > 0){
			for (int i = b; i >= a; i--){
				if ((i % 4 != 0) || (i % 100 == 0 && i % 400 != 0)){

					printf("%d年不是闰年", i);
				}
				else{

					printf("%d年是闰年", i);

				}
				break;
			}
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
//	printfleapyear1(-100, 1000);
//	system("pause");
//}