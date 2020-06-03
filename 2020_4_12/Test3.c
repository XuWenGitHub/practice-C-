#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

//二分查找
//编写代码在一个整形有序数组中查找具体的某个数
//要求：找到了就打印数字所在的下标，找不到则输出：找不到。
//形式参数lenth 为数组的长度，value1为查找的数。
void lookup(int array[], int lenth, int value){
	int start = 0;
	int end = lenth-1;
	//printf("%d,%d", start, end);  这里调试了一下，看看它们的值
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
			printf("%d的下标为%d\n", value, mid);
			break;
		}
	}

	if (start>end){
		printf("找不到\n");
	}
}

int main(){
	int array[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int lenth = sizeof(array) / sizeof(array[0]);
	//printf("%d", lenth);
	int value = 0;
	printf("请输入您想查找的值：");
	scanf("%d", &value);
	lookup(array, lenth, value);
	system("pause");
}