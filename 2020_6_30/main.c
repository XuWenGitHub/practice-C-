#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
/*
快排分析：
	定义一个中间值，让中间值左右两边的交换，最后达到，中间值左边比中间值小，中间值右边比中间值大
	然后再通过递归，再把中间值左边看为一组，中间值右边右看为一组，重复
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
		//交换后，判断是否有和key值相同的数字，如果有，就让另一边靠拢
		if (arr[l] == key){
			r--;
		}
		if (arr[r] == key){
			l++;
		}
	}
	//如果退出循环后，两个相等，便错开它们
	if (l == r){
		l++;
		r--;
	}
	//左递归
	if (left < r){
		quickSort(arr, left, r);
	}
	//右递归
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