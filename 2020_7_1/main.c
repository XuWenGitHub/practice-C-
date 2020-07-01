#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
mergeSort(int arr[], int left, int right, int temp[]){
	if (left < right){
		int mid = (left + right) / 2;
		//向左递归
		mergeSort(arr, left, mid, temp);
		//向右递归
		mergeSort(arr, mid + 1, right, temp);
		//合并
		merge(arr, left, mid, right, temp);
	}
}
//两个序列合并，left表示左序列的首元素，mid表示做序列的尾元素，right表示右序列的尾元素,temp表示中转数组
merge(int arr[], int left, int mid, int right, int temp[]){
	int i = left;	//左序列的下标
	int j = mid + 1;	//右序列的下标
	int t = 0;	//中转数组的下标
	//两个序列比较
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
	//把剩余的一个序列全添加到temp后面
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

	//把temp中排序号的转到arr中,但因为递归，每次转的个数不一样，第一次0，1	第二次2,3	第三次0,3
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