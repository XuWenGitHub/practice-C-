#define _CRT_SECURE_NO_WARNINGS         //˵scanf��䲻��ȫ����������error c4996)
#pragma warning(disable:4996)           //����printf��ʾδ�����ʶ��
#include<stdio.h>
#include<math.h>
int main(){
	int num, i;
	printf("ֻ�ܱ�1����������������Ϊ����\n");
	printf("������һ������: \n");
	scanf("%d", &num);
	if (num <= 1)
		printf("%d��������\n", num);
	else{
		for (i = 2; i <= sqrt(num); i++){
			if (num%i == 0) break;
		}
		if (i > sqrt(num))
			printf("%d������\n", num);
		else
			printf("%d��������\n", num);   
	}
		system("pause"); //��ʾ��ͣ��
		return 0;
	
}