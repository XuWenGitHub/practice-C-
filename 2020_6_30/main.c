#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
/*
���ŷ�����
	����һ���м�ֵ�����м�ֵ�������ߵĽ��������ﵽ���м�ֵ��߱��м�ֵС���м�ֵ�ұ߱��м�ֵ��
	Ȼ����ͨ���ݹ飬�ٰ��м�ֵ��߿�Ϊһ�飬�м�ֵ�ұ��ҿ�Ϊһ�飬�ظ�
*/
void quickSort(int arr[], int left, int right){
	int l = left;
	int r = right;
	int key = arr[(left + right) / 2];
	while (l < r){
		while (arr[l] < key){
			l++;
		}
		while (arr[r]>key){
			r--;
		}
		if (l >= r){
			break;
		}
		arr[l] ^= arr[r];
		arr[r] ^= arr[l];
		arr[l] ^= arr[r];
		//�������ж��Ƿ��к�keyֵ��ͬ�����֣�����У�������һ�߿�£
		if (arr[l] == key){
			r--;
		}
		if (arr[r] == key){
			l++;
		}
	}
	//����˳�ѭ����������ȣ��������
	if (l == r){
		l++;
		r--;
	}
	//��ݹ�
	if (left < r){
		quickSort(arr, left, r);
	}
	//�ҵݹ�
	if (right>l){
		quickSort(arr, l, right);
	}
}
int main(){
	int arr[] = { 5, 2, 1, 3, 5, -1, 0, 35, 123,-10,10000,2,1,2 };
	int len = sizeof(arr) / sizeof(arr[0]);
	quickSort(arr, 0,len-1);
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}

	system("pause");
	return 0;
}