#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
//����Ļ�����9*9�˷��ھ���
void nn_Multiply(int a){
	for (int i = 1; i <= a; i++){
		for (int j = 1; j <= i; j++){
			int mul = i*j;
			printf("%d*%d==%d\t", j, i, mul);
		}
		printf("\n");
	}
}
//int main(){
//	nn_Multiply(9);
//
//	system("pause");
//}