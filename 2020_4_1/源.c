#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

//дһ�����������������Ӵ�С���
void sortNumberPrintf(int number1,int number2,int number3){
	//����һ�����飬�Ȱ������������һ��������
	int array[] = { number1, number2, number3 };
	
	//���������һ������
	printf("û������ǰ��\n");
	printf("[");
	for (int i = 0; i < (sizeof(array) / sizeof(array[0])); i++){
		if (i == (sizeof(array) / sizeof(array[0]) - 1)){
			printf("%d]", array[sizeof(array) / sizeof(array[0]) - 1]);
		}
		else{
			printf("%d ,", array[i]);
		}
	}
	printf("\n");
	
	//�ٶ������������ѡ��ð�ݣ����룬����...���Ҿ�дһ���򵥵�ð������(����)
	for (int i = 1; i <= (sizeof(array) / sizeof(array[0]) - 1); i++){
		for (int j = 0; j < (sizeof(array) / sizeof(array[0])) - i; j++){
			if (array[j + 1]>array[j]){
				int temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
		}
	}

	//Ȼ���ٱ�������������
	printf("�Ӵ�С�����\n");
	printf("[");
	for (int i = 0; i < (sizeof(array) / sizeof(array[0])); i++){
		if (i == (sizeof(array) / sizeof(array[0]) - 1)){
			printf("%d]", array[sizeof(array) / sizeof(array[0]) - 1]);
		}
		else{
			printf("%d ,", array[i]);
		}
	}
	printf("\n");
}

//����ڶ��ַ����������õ���ѡ�����������
void threeNumberPrintf(){
	int temp,a,b,c;
	printf("��������������\n");
	scanf("%d%d%d", &a, &b, &c);
	if (a < b){
		temp = a;
		a = b;
		b = temp;
	}
	if (a < c){
		temp = a;
		a = c;
		c = temp;
	}
	if (b < c){
		temp = b;
		b = c;
		c = temp;
	}
	printf("�Ӵ�СΪ:%d %d %d\n", a, b, c);
}

//дһ�������ӡ1-100֮������3�ı���������	
void multipleOf3(){
	int start = 0;
	int end = 0;
	printf("			��ܰС��ʾ��������һ����,Ȼ��ո���������һ����,�ٻس�����\n\n");
	printf("�����������ڶ���֮���ҳ�����3�ı��������֣�");
	scanf("%d %d", &start, &end);
	//printf("������һ����,Ȼ��ո���������һ����,�ٻس�����\n");
	while (start<=end)
	{
		if (start %3==0){
			printf("%d,", start);
			start++;
		}
		else{
			
		}
		start++;
	}
	printf("\n");
}

int main(){
	//sortNumberPrintf(1, 2, 3);
	//threeNumberPrintf();
	multipleOf3();
	system("pause");
}