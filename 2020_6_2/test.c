#include"test.h"

int compareString(char* newStr, char* str){
	assert(newStr);
	assert(str);
	char* start = newStr;
	char* start2 = str;
	for (;*start != '\0'&&*start2 != '\0'; start++, start2++){
		if (*start == *start2){
			continue;
		}
		else{
			return 0;
		}
	}

	return 1;
}

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
	A:Ūһ�������ԭ�ַ���װ����
*/
int stringRotation(char* str, char* compStr, int((*comparestring)(char* str, char* compstr))){
	char* start = str;	//ָ��A

	//����ת
	for (int i = 0; i < 5; i++){
		//ÿ��ѭ����һ�����һ���µ��ַ���

		char frist = *start;	//ÿ�α����һ���ַ�����������������ȥ
		for (int j = 1; j < 5; j++){
			start[j - 1] = start[j];	//�ѳ��˵�һ��������Ķ���ǰ��һ��
		}
		start[4] = frist;	//Ȼ���ٰѵ�һ���ŵ����һ��ȥ

		
		//Ȼ����Ҫ�Ƚϵ��ַ���������ת��ıȽϣ����Ƿ�һ�������һ������1�������һ������0
		if ((*compareString)(str,compStr)==1){
			return 1;
		}
		else{
			continue;
		}
	}

	//����ת
	for (int i = 0; i < 5; i++){
		//ÿ��ѭ����һ�����һ���µ��ַ���

		char last = *(start+4);	//ÿ�α������һ���ַ���������ŵ���ͷȥ
		for (int j = 0; j<4; j++){
			start[j + 1] = start[j];	//�ѳ������һ����ǰ��Ķ�������һ��
		}
		start[0] = last;	//Ȼ���ٰ����һ���ŵ���һ��ȥ


		//Ȼ����Ҫ�Ƚϵ��ַ���������ת��ıȽϣ����Ƿ�һ�������һ������1�������һ������0
		if ((*compareString)(str, compStr) == 1){
			return 1;
		}
		else{
			continue;
		}
	}

	return 0;
}

/*
ʵ��һ�����������������ַ����е�k���ַ���
���磺
ABCD����һ���ַ��õ�BCDA
ABCD���������ַ��õ�CDAB
*/
/*
������
	A��ABCD -> BCDA->CDAB
	B�����ֹ��ɣ�ÿ�ΰѵ�һ���ַ�������ַ�������'\0'������ǰ��һ�£��ٰѵ�һ���ַ����ŵ������ȥ
	C���������һ���ַ�����ֻ��Ҫѭ��һ�Σ��������2���ַ�����ֻ��Ҫѭ��2��
*/
//str�Ǵ��������齵ά�ɵ�ָ�룬len�ַ����ĳ��ȣ�number����Ҫ��ת�����ַ�
void stringRotation2(char* str,int len,int number){
	//���ѭ���������������ַ�
	for (int i = 0; i < number; i++){
		//ÿ��ѭ�����Ȱѵ�һ���ַ���������
		char frist = *str;
		
		for (int i = 1; i < len; i++){
			str[i - 1] = str[i];	//�ӵڶ����ַ���ʼ����'\0'������������ǰ��һ��
		}

		//����ٰѿ�ʼ��ĵ�һ���ַ����ŵ��ַ���������һ���ַ�λ��ȥ
		*(str + len - 1) = frist;
	}
}

