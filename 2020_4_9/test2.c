#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

//����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵ����ӡ�����
void result(){
	double sum = 0; //���ӷ����ۼ���
	int sign = 1; //���ű仯

	for (int i = 1; i < 101; i++){
		sum = sum + sign*1.0/i; ////�����1.0���ã���Ϊsum�Ǹ�����
		sign = -sign;
	}

	printf("����1/1-1/2+1/3-1/4+1/5 ���� + 1/99 - 1/100 ��ֵΪ%lf\n",sum);
}

//double result2(){
//	double result = 0.00; //���ӷ����ۼ���
//	int sign = -1; //���ű仯
//
//	for (int i = 2; i < 101; i++){
//		result = result +( (1 / i)*(sign));
//		sign = -sign;
//	}
//
//	return result+1;
//}

//int main(){
//	//printf("%lf\n", result());
//	//printf("%f\n", result2());
//	result();
//	system("pause");
//}