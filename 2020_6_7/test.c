#include"test.h"

/*
дһ���������ж�һ���ַ����Ƿ�Ϊ����һ���ַ�����ת֮����ַ�����
���磺����s1 =AABCD��s2 = BCDAA������1
����s1=abcd��s2=ACBD������0.
AABCD����һ���ַ��õ�ABCDA
AABCD���������ַ��õ�BCDAA
AABCD����һ���ַ��õ�DAABC
*/
/*
������
A��ʵ���������������
B������ν���������Ȼ�󲻶Ͻ��бȽ�
*/





//����1��ʵ���������������
//Ȼ��������������ַ�����Ȼ�����Ҫ�Ƚϵ��ַ������бȽ�
//ʵ��һ���ַ����������������
void LeftRotate(char* str, int len, int num){
	assert(str);
	assert(len > 0);
	assert(num >= 0);

	num %= len;	//ȥ�ظ�����Ϊ��һ���ַ�������Ϊ3���������Σ��ֱ�ɱ�����

	while (num){
		char temp = str[0];
		for (int i = 1; i < len; i++){
			str[i - 1] = str[i];	//���˵�һ��������������һ��
		}
		str[len - 1] = temp;
		num--;
	}
}



//����2���Ȼ����ַ���(���ֳ������ַ�������һ���ַ����ĳ��Ⱦ���num(�ַ�����Ҫ���õĴ���),�ڶ����ַ�������ʣ�µ�)
//�ַ������ú���
//���磺abcd1234	Ҫ����4��
//		dcba4321	����n�£��Ͱ�ǰn���ַ�����һ�£�����ʣ���������һ��
//		1234abcd	����������һ�£��ͱ��������4��
void LeftRotate2(char* str, int len, int num){
	assert(str);
	assert(len > 0);
	assert(num >= 0);

	num %= len;	//ȥ�ظ�����Ϊ��һ���ַ�������Ϊ3���������Σ��ֱ�ɱ�����
	//����2
	//���ֵ������ַ����ķֱ�����
	Reverse(str, 0, num - 1);
	Reverse(str, num, len - 1);

	//�������ַ���������
	Reverse(str, 0, len - 1);
}

//�ַ�����һ��������
void Reverse(char *str, int start, int end){
	assert(str);
	while (start < end){
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}



//����3		�����ռ�����ȡʱ��
//������е���ת��,ֻҪstr2��str1��˫�������Ӵ�����OK
//�Ȱ�һ���ַ������һ��˫����
//���� 1234abcd -> 1234abcd1234abcd
//�����תһ�Σ��ʹӵ�2���ַ�����9���ַ�
void LeftRotate3(char* str, int len, int num){
	assert(str);
	assert(len > 0);
	assert(num >= 0);

	num %= len;	//ȥ�ظ�����Ϊ��һ���ַ�������Ϊ3���������Σ��ֱ�ɱ�����




}