#include<stdio.h>
#include<Windows.h>
#include<math.h>
#pragma warning(disable:4996)

//дһ�����룺��ӡ100~200֮�������
/*
	������ֻ�ܱ�1�ͱ�������������
	һ�������ܱ������Ļ���һ����󱻳�������Ӧ���Ǳ������ţ������Ч��
*/
void printfPrimeNumber(int a, int b){
	int i,j;
	if (b>=a){
		for (i = a; i <= b; i++){

			//���aΪ�����Ļ�����ôҲ����ִ�У�ͦ���˴���Ľ�׳��
			//��Ϊ����Ϊ����1������
			if (i > 1){
				//һ�������ܱ������Ļ���һ����󱻳�������Ӧ���Ǳ������ţ������Ч��
				for (j = 2; j <= sqrt(i); j++){
					if (i%j == 0){
						break;
					}
				}

				if (j > sqrt(i)){
					printf("%d������\n", i);
				}
			}

		}
	}
	else{
		printf("��������\n");
		printf("(b>a)!!!!!!");
	}
}
//void main(){
//	printfPrimeNumber(-100, 1000);
//	system("pause");
//}