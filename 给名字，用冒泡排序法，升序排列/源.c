#include<stdio.h>
#define MIXSIZE 10
#include<string.h>
#define Namenum 7                      //NamenumΪ���ֵĸ���
#pragma warning(disable:4996)
char maopao_sort(char a[][MIXSIZE], int b);
char shuchu_function(char a[][MIXSIZE], int b);
int main(){
	char name[][MIXSIZE] = { "tom", "jeff", "bob", "jone", "mary", "appo","iphone"};        //����һ����ά���飬����Щ��������
	//�����������
	shuchu_function(name,Namenum);
	printf("\n");
	//����
	maopao_sort(name, Namenum);
	//�������˺�������һ���������
	shuchu_function(name, Namenum);
	system("pause");
}
char maopao_sort(char a[][MIXSIZE], int b){          //bΪ���ֵĸ��� 5
	char temp[MIXSIZE];
	int i, j;
	for (i = 1; i <= b - 1; i++){
		for (j = 0; j < b - i; j++){
			if (strcmp(a[j], a[j + 1])>0){
				strcpy(temp, a[j]);
				strcpy(a[j], a[j + 1]);
				strcpy(a[j + 1], temp);
			    }
			}
		}
	}
char shuchu_function(char a[][MIXSIZE],int b){
	int i;
	for (i = 0; i < b; i++){
		printf("%s\n", a[i]);
	}
}