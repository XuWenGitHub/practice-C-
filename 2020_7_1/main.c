#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
mergeSort(int arr[], int left, int right, int temp[]){
	if (left < right){
		int mid = (left + right) / 2;
		//����ݹ�
		mergeSort(arr, left, mid, temp);
		//���ҵݹ�
		mergeSort(arr, mid + 1, right, temp);
		//�ϲ�
		merge(arr, left, mid, right, temp);
	}
}
//�������кϲ���left��ʾ�����е���Ԫ�أ�mid��ʾ�����е�βԪ�أ�right��ʾ�����е�βԪ��,temp��ʾ��ת����
merge(int arr[], int left, int mid, int right, int temp[]){
	int i = left;	//�����е��±�
	int j = mid + 1;	//�����е��±�
	int t = 0;	//��ת������±�
	//�������бȽ�
	while (i <= mid&&j <= right){
		if (arr[i] < arr[j]){
			temp[t] = arr[i];
			t += 1;
			i += 1;
		}
		else{
			temp[t] = arr[j];
			t += 1;
			j += 1;
		}
	}
	//��ʣ���һ������ȫ��ӵ�temp����
	while (i <= mid){
		temp[t] = arr[i];
		t += 1;
		i += 1;
	}
	while (j <= right){
		temp[t] = arr[j];
		t += 1;
		j += 1;
	}

	//��temp������ŵ�ת��arr��,����Ϊ�ݹ飬ÿ��ת�ĸ�����һ������һ��0��1	�ڶ���2,3	������0,3
	t = 0;
	int tempLeft = left;
	while (tempLeft <= right){
		arr[tempLeft] = temp[t];
		tempLeft += 1;
		t += 1;
	}
}
int main(){
	int arr[] = { 3, 5, 2, 6, 7,-1, 8, 9, 1, 0 };
	int* temp = malloc(sizeof(arr));
	int len = sizeof(arr) / sizeof(arr[0]);
	mergeSort(arr, 0, len - 1, temp);
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}