#include<stdio.h>
#include<Windows.h>
//дһ���꣬���Խ�һ�������ֵ�����λ��ż��λ����
//��n�Ķ�����������λ��ż��λ�����������n������λ����һλ���ұ���n��ż��λ����һλ������|�����������
#define CHANGE(n) (((n&(0x55555555))<<1)|((n&(0xAAAAAAAA))>>1))
/*
дһ���꣬����ṹ����ĳ����������׵�ַ��ƫ�ƣ�������˵��(offsetof��)
*/
/*
structur���ṹ������ĵ�ַ��Ҳ�����׵�ַ	����ṹ�����p�����δ�&p
variable����Ҫ��ṹ����ĳ����	����ṹ�����p�����δ�&p.�ṹ����ĳ������
������������ַ��ǿת��char*���ͣ�Ȼ��(char*)variable-(char*)structur,������variable��ƫ����
*/
#define OFFSETOF(variable,structur) (((char*)variable)-((char*)structur))
typedef struct Person{
	char a;
	int b;
	double c;
}person;
int main(){
	person p;
	printf("ƫ����Ϊ��%d\n", OFFSETOF(&p.c, &p));
	int a =100;
	printf("%d\n", CHANGE(a));

	system("pause");
	return 0;//110 0100		
			// 110 0010
}