#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
#include<windows.h>

//����һ���������͵��������������ֵ�ĺ���

//��������maxNumber

/*��ʽ������

compareNumberOne�ǵ�һ������Ƚϵ���

compareNumberTwo�ǵڶ�������Ƚϵ���*/


void maxNumber(){
	int compareNumberOne;
	int compareNumberTwo;
	printf("�������һ������\n");
	scanf("%d", &compareNumberOne);
	printf("������ڶ�������\n");
	scanf("%d", &compareNumberTwo);
	//printf("��������������\n");
	//scanf("%d %d", &compareNumberOne, &compareNumberTwo);
	int maxNumber = 0; //�����ֵ��ʼ��

	if (compareNumberOne>compareNumberTwo){

		maxNumber = compareNumberOne;

	}
	else{

		maxNumber = compareNumberTwo;

	}
	
	printf("%d��%d�����ֵΪ��%d\n", compareNumberOne, compareNumberTwo, maxNumber);
}
int main(){
	/*char array[] = { 'b', 'i', 't' };
	printf("%d\n", strlen(array));
	printf("%d\n", strlen("c:\test\121"));*/
	
	maxNumber();
	system("pause");
	return 0;		 
}