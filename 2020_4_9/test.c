#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
//编写程序数一下 1到 100 的所有整数中出现多少个数字9
/*
	分析：1-9里直接对9取余数，10-99里把每个数的每一位单独取出来，然后看是否和9相等，来一个count来计9的个数，100里面没有9	
*/
int nineNumber(){
	//1-9里只有9，可想而知，100里面没有9，直接弄10到99，所以count个数为1开始
	int count = 1; //统计9的个数
	for (int i = 10; i < 100; i++){
		int j, k; //分别来放个位和十位的数
		j = i % 10;//i1表示个位的数
		k = (i / 10) % 10;//i2表示十位的数
		if (9 == j){
			count++;
		}
		if (9 == k){
			count++;
		}
	}

	return count;
}
//int main(){
//	int nine = nineNumber();
//	printf("1到100的所有整数中出现%d个数字9\n", nine);
//	printf("%d\n", nine);
//
//	
//	system("pause");
//}