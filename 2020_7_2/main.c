#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
//先分组再每个组直接插入
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
//快排 每次取出中间索引的值，然后排序，让它左边都比他小，右边都比它大，然后左右递归
void quickSort(int arr[], int left, int right){
	int l = left;	//第一个元素的索引
	int r = right;	//最后一个元素的索引
	int key = arr[(left + right) / 2];	//中间值
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
		//判断arr[l]和arr[r]有没有和key值相等，如果相等，另一边往其靠拢
		if (arr[l] == key){
			r--;
		}
		if (arr[r] == key){
			l++;
		}
	}
	//当退出后，看l和r是否相等，如果相等的话，那么将其错开，方便后面递归
	if (l == r){
		l++;
		r--;
	}
	//左递归
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