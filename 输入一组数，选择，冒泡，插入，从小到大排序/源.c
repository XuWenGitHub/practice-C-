#pragma warning(disable:4996)
#include<stdio.h>
#include<windows.h>
#define MIXSIZE 4
void shuchu_function(int array[], int lenth);
void xuanze_sort(int array[], int lenth);
void maopao_sort(int array[], int lenth);
void charu_sort(int array[], int lenth);
int main(){
	int num[MIXSIZE];
	int i ;
	printf("������%d����:\n", MIXSIZE);
	for (i = 0; i < MIXSIZE; i++){
		scanf("%d", &num[i]);
	}
	printf("������������ǣ�\n");

	//�����������
	shuchu_function(num, MIXSIZE);

	int a,j;
	printf("\n");
	
	
	for (j = 1; j < 4; j++){
		    printf("\n");
            printf("��ѡ�����򷽷���\n1ѡ������\n2ð������\n3��������\n");
			scanf("%d", &a);
			if (a == 3 || a == 2 || a == 1){
				switch (a){
				case 1:xuanze_sort(num, MIXSIZE); break;
				case 2:maopao_sort(num, MIXSIZE); break;
				case 3:charu_sort(num, MIXSIZE); break;
				}
                printf("��С�����������Ϊ��\n");
				break;
			}
			else{
				if (j <= 2){
					printf("����������,����������\n");
				}
				else
					printf("���Ѿ���������Σ��޷�Ϊ������\n");
			}
		if (j == 2){
			printf("����ٴ�������󣬽�������\n");
		}
	}
	
	if (j < 4){
		shuchu_function(num, MIXSIZE);
	}
	
	system("pause");
}
void shuchu_function(int array[],int lenth){          //aΪ����ĸ���
	int i;
	for (i = 0; i < lenth; i++){
		printf("%d\t", array[i]);
	}
}
void xuanze_sort(int array[], int lenth){
	int i, j, temp;
	for (i = 0; i < lenth - 1; i++){
		for (j = i + 1; j < lenth; j++){
			if (array[i]>array[j]){
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
			}
		}
	}
}
void maopao_sort(int array[], int lenth){
	int i, j, temp;
	for (i = 1; i < lenth; i++){
		for (j = 0; j < lenth - i; j++){
			if(array[j]>array[j + 1]){
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}
void charu_sort(int array[], int lenth){
	int i, j;
	int temp;
	for (i = 1; i < lenth; i++){
		temp = array[i];
		for (j = i - 1; j >= 0; j--){
			if (temp<array[j]){
				array[j + 1] = array[j];
			}
			else{
				break;
			}
		}
		array[j + 1] = temp;
	}
}