#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)
//ϣ������(��λ����
void shellSort(int arr[], int len){
	//�Ȳ��ϵĶ�arr���з��飬ֱ��/2==0����
	for (int step = len / 2; step > 0; step /= 2){
		for (int i = step; i < len; i++){
			//���ڶ�arr[i]���в���
			int temp = arr[i];
			int j;
			for (j = i - step; j >= 0; j -= step){
				if (arr[j]>temp){
					//temp����step��λ��
					arr[j + step] = arr[j];
				}
				else{
					break;	//�ҵ�����λ�ã���j+step���λ��
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