#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

//���ֲ���
//��д������һ���������������в��Ҿ����ĳ����
//Ҫ���ҵ��˾ʹ�ӡ�������ڵ��±꣬�Ҳ�����������Ҳ�����
//��ʽ����lenth Ϊ����ĳ��ȣ�value1Ϊ���ҵ�����
void lookup(int array[], int lenth, int value){
	int start = 0;
	int end = lenth-1;
	//printf("%d,%d", start, end);  ���������һ�£��������ǵ�ֵ
	int mid = (start+end)/2;
	//printf("%d", mid);

	while (start<=end){
		if (value < array[mid]){
			end = mid - 1;
			mid = (start + end) / 2;
		}
		else if (value>array[mid]){
			start = mid + 1;
			mid = (start + end) / 2;
		}
		else{
			printf("%d���±�Ϊ%d\n", value, mid);
			break;
		}
	}

	if (start>end){
		printf("�Ҳ���\n");
	}
}

int main(){
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int lenth = sizeof(array) / sizeof(array[0]);
	//printf("%d", lenth);
	int value = 0;
	printf("������������ҵ�ֵ��");
	scanf("%d", &value);
	lookup(array, lenth, value);
	system("pause");
}