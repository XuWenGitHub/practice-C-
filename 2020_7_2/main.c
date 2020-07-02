#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
//�ȷ�����ÿ����ֱ�Ӳ���
void shellSort(int arr[], int len){
	for (int group = len / 2; group > 0; group /= 2){
		for (int i = group; i < len; i++){
			int temp = arr[i];
			int j;
			for (j = i - group; j >= 0; j -= group){
				if (arr[j]>temp){
					arr[j + group] = arr[j];
				}
				else{
					break;
				}
			}
			arr[j + group] = temp;
		}
	}
}
//���� ÿ��ȡ���м�������ֵ��Ȼ������������߶�����С���ұ߶�������Ȼ�����ҵݹ�
void quickSort(int arr[], int left, int right){
	int l = left;	//��һ��Ԫ�ص�����
	int r = right;	//���һ��Ԫ�ص�����
	int key = arr[(left + right) / 2];	//�м�ֵ
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
		//�ж�arr[l]��arr[r]��û�к�keyֵ��ȣ������ȣ���һ�����俿£
		if (arr[l] == key){
			r--;
		}
		if (arr[r] == key){
			l++;
		}
	}
	//���˳��󣬿�l��r�Ƿ���ȣ������ȵĻ�����ô��������������ݹ�
	if (l == r){
		l++;
		r--;
	}
	//��ݹ�
	if (left < r){
		quickSort(arr, left, r);
	}
	if (right>l){
		quickSort(arr, l, right);
	}
}
void merge(int arr[], int left, int mid, int right, int temp[]){
	int i = left;
	int j = mid + 1;
	int t = 0;
	while (i <= mid&&j <= right){
		if (arr[i] <= arr[j]){
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

	t = 0;
	int tempLeft = left;
	while (tempLeft <= right){
		arr[tempLeft] = temp[t];
		t += 1;
		tempLeft += 1;
	}
}
void mergeSort(int arr[], int left, int right, int temp[]){
	if (left < right){
		int mid = (left + right) / 2;
		mergeSort(arr, left, mid, temp);
		mergeSort(arr, mid + 1, right, temp);
		merge(arr, left, mid, right, temp);
	}
}
int main(){
	int arr[] = { 2, 5, 3, 1, 6, 4, 9, 7, 8 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int* temp = malloc(sizeof(arr));
	//shellSort(arr, len);
	//quickSort(arr, 0, len - 1);
	mergeSort(arr, 0, len - 1, temp);
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}