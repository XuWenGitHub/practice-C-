#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值，打印出结果
void result(){
	double sum = 0; //做加法的累加器
	int sign = 1; //符号变化

	for (int i = 1; i < 101; i++){
		sum = sum + sign*1.0/i; ////这里的1.0设置，因为sum是浮点数
		sign = -sign;
	}

	printf("计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值为%lf\n",sum);
}

//double result2(){
//	double result = 0.00; //做加法的累加器
//	int sign = -1; //符号变化
//
//	for (int i = 2; i < 101; i++){
//		result = result +( (1 / i)*(sign));
//		sign = -sign;
//	}
//
//	return result+1;
//}

//int main(){
//	//printf("%lf\n", result());
//	//printf("%f\n", result2());
//	result();
//	system("pause");
//}