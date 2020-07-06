#include<stdio.h>
#include<Windows.h>
#include<math.h>
#pragma warning(disable:4996)
/*
²åÖµ²éÕÒ·¨
*/
int insertValueSearch(int arr[], int left,int right,int findValue){
	if (left > right || findValue<arr[0] || findValue>arr[99]){
		return -1;
	}
	int mid = left + (right - left)*(findValue - arr[left]) / (arr[right] - arr[left]);
	int midValue = arr[mid];
	if (findValue > midValue){
		return insertValueSearch(arr, mid + 1, right, findValue);
	}
	else if (findValue < midValue){
		return insertValueSearch(arr, left, mid - 1, findValue);
	}
	else{
		return mid;
	}
}
int main(){
	int* arr = malloc(sizeof(int)* 100);
	
	
	for (int i = 0; i < 100; i++){
		arr[i] = i + 1;
	}
	printf("%d\n", insertValueSearch(arr,0,99,1));
	system("pause");
	return 0;
}