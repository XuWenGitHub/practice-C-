#include<stdio.h>
#include<Windows.h>
#include<math.h>
#pragma warning(disable:4996)

void printfLeapYear1(int a, int b){

	while (1){

		//����һֱwhileѭ���������������������������������һ��break������whileѭ����������������Ҫ�󣬾�һֱ�ÿͻ�����������ȷ����

		if (b > a && a > 0 && b > 0){
			for (int i = b; i >= a; i--){
				if ((i % 4 != 0) || (i % 100 == 0 && i % 400 != 0)){

					printf("%d�겻������", i);
				}
				else{

					printf("%d��������", i);

				}
				break;
			}
		}
		else{
			printf("�����������󣡣���\n");

			printf("����������һ�����󰴿ո���������һ����������»س�������\n\n");

			printf("����������a��b��ֵ( b>a �� a��b>0 ):");

			scanf("%d %d", &a, &b);

		}
	}
}
//void main(){
//	printfleapyear1(-100, 1000);
//	system("pause");
//}