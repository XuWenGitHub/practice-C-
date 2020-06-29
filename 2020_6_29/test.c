#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
//希尔排序(移位法）
void shellSort(int arr[], int len){
	//先不断的对arr进行分组，直到/2==0结束
	for (int step = len / 2; step > 0; step /= 2){
		for (int i = step; i < len; i++){
			//现在对arr[i]进行插入
			int temp = arr[i];
			int j;
			for (j = i - step; j >= 0; j -= step){
				if (arr[j]>temp){
					//temp后移step个位置
					arr[j + step] = arr[j];
				}
				else{
					break;	//找到插入位置，在j+step这个位置
				}
			}
			arr[j + step] = temp;
		}
	}
}
int main(){

	int arr[] = { 35, 3, 2, 4, 5, 6, -1, 0, 10, 1 };
	int len = sizeof(arr) / sizeof(arr[0]);
	shellSort(arr, len);
	for (int i = 0; i < len; i++){
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}