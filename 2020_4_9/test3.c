#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void xuanZe_Sort(int array[]);
void maxNumber();
void chaRu_Sort(int array[]);

//��10 �����������ֵ
void maxNumber(){
	int array[10]; //�洢10������������
	int choose = 0;//���û�ѡ��
	printf("������10��������\n");
	for (int i = 0; i < 10; i++){
		scanf("%d",&array[i]);
	}
	int len = (sizeof(array) / sizeof(array[0])); //����ĳ���

	while (1){
		//�����ѡ�����򣬲�������(ð�������ϴ�д����)
		printf("*****************************\n");
		printf("***********��ѡ��************\n");
		printf("*********(1)ѡ������*********\n");
		printf("*********(2)��������*********\n");
		printf("*****************************\n");
		scanf("%d", &choose);
		switch (choose){
		case(1) :
			xuanZe_Sort(array,len);
			printf("��С�����������\n");
			break;
		case(2) :
			chaRu_Sort(array,len);
			printf("��С�����������\n");
			break;
		default:
			printf("��������������ѡ��\n");

		}

		if (choose == 1 || choose == 2){
			break;
		}
	}

	printf("10 �����������ֵΪ��%d\n", array[9]);
}

void xuanZe_Sort(int array[],int len){
	//int len =( sizeof(array) / sizeof(array[0]));
	int i, j, temp;
	for (i = 0; i < len - 1; i++){
		for (j = i + 1; j < len; j++){
			if (array[j] < array[i]){
				temp = array[j];
				array[j] = array[i];
				array[i] = temp;
			}
		}
	}
}
void chaRu_Sort(int array[],int len){
	//int len =( sizeof(array) / sizeof(array[0]));
	int i, j, temp;
	for (int i = 1; i < len; i++){
		temp = array[i];

		for (j = i - 1; j >= 0; j--){
			if (temp < array[j]){
				array[j + 1] = array[j];
			}
			else{
				break;
			}
		}

		array[j + 1] = temp;
	}
}
//int main(){
//
//	maxNumber();
//
//	system("pause");
//}