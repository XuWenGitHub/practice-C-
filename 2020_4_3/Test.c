#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

//���������������������������Լ��
/*
	������
		A����������Լ��(�����������һ��Ϊ�������򷵻�-1)
		B�������������Լ�����϶�����������С����һ����С������ȡ�
		C�����ж���������˭С�������
				aС��bС����forѭ������i��ʼֵΪa��b��С���Ǹ���ѭ��������i>0��i--��Ȼ�����ж�a��b��iȡ�࣬�����Ϊ0���������Լ��i
				a��b��ȣ���ô����֮�����Ĺ�Լ������Ϊ�����Ǳ���
*/
int greatestCommonDivisor( int a, int b ){
	//��������Լ��,�Ҳ�Ϊ0
	if(a > 0 && b > 0){

		//�����������Լ�����϶�����������С����һ����С������ȡ�
		//���ж���������˭С�������
		if (a > b){
			for (int i = b; i > 0; i--){
				if (a%i == 0 && b%i==0){
					return i;
				}
			}
		}
		else if (a < b){
			for (int i = a; i>0; i--){
				if (b%i == 0 && a%i==0){
					return i;
				}
			}
		}
		else{
			//��������ȣ����Լ����Ϊ����
			return a;
		}

	}
	
	//�������������һ��Ϊ��������û�й�Լ��������-1��
	return -1;
}

//շת���������Ϊa��b�����Կ���n�����Լ��֮��
int greatestCommonDivisor2(int a, int b){
	while (1){
		if (a > b){
			a -= b;
		}
		else if(b>a){
			b -= a;
		}
		else{
			break;
		}
	}

	return a;
}

//շת���෨��ÿһ�δ�ı�С�����࣬����������ģ�Ȼ��ѭ����ֱ������һ����Ϊ0����ô��һ�����������������Լ��
int greatestCommonDivisor3(int a, int b){
	while (a*b != 0){
		if (a > b){
			a %= b;
		}
		else if (b > a){
			b %= a;
		}
		else{
			break;
		}
	}

	return a == 0 ? b : a;
}
void main(){
	printf("%d\n", greatestCommonDivisor(14, 7));
	printf("%d\n", greatestCommonDivisor2(50, 20));
	printf("%d\n", greatestCommonDivisor3(122, 2));
	system("pause");
}