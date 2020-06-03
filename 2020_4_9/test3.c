#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
void xuanZe_Sort(int array[]);
void maxNumber();
void chaRu_Sort(int array[]);

//求10 个整数中最大值
void maxNumber(){
	int array[10]; //存储10个整数的数组
	int choose = 0;//供用户选择
	printf("请输入10个整数：\n");
	for (int i = 0; i < 10; i++){
		scanf("%d",&array[i]);
	}
	int len = (sizeof(array) / sizeof(array[0])); //数组的长度

	while (1){
		//这次来选择排序，插入排序(冒泡排序，上次写过了)
		printf("*****************************\n");
		printf("***********请选择************\n");
		printf("*********(1)选择排序*********\n");
		printf("*********(2)插入排序*********\n");
		printf("*****************************\n");
		scanf("%d", &choose);
		switch (choose){
		case(1) :
			xuanZe_Sort(array,len);
			printf("从小到大排序完毕\n");
			break;
		case(2) :
			chaRu_Sort(array,len);
			printf("从小到大排序完毕\n");
			break;
		default:
			printf("输入有误，请重新选择\n");

		}

		if (choose == 1 || choose == 2){
			break;
		}
	}

	printf("10 个整数中最大值为：%d\n", array[9]);
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