#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
//��д������һ�� 1�� 100 �����������г��ֶ��ٸ�����9
/*
	������1-9��ֱ�Ӷ�9ȡ������10-99���ÿ������ÿһλ����ȡ������Ȼ���Ƿ��9��ȣ���һ��count����9�ĸ�����100����û��9	
*/
int nineNumber(){
	//1-9��ֻ��9�������֪��100����û��9��ֱ��Ū10��99������count����Ϊ1��ʼ
	int count = 1; //ͳ��9�ĸ���
	for (int i = 10; i < 100; i++){
		int j, k; //�ֱ����Ÿ�λ��ʮλ����
		j = i % 10;//i1��ʾ��λ����
		k = (i / 10) % 10;//i2��ʾʮλ����
		if (9 == j){
			count++;
		}
		if (9 == k){
			count++;
		}
	}

	return count;
}
//int main(){
//	int nine = nineNumber();
//	printf("1��100�����������г���%d������9\n", nine);
//	printf("%d\n", nine);
//
//	
//	system("pause");
//}