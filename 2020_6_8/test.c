#include"test.h"

/*
ģ��ʵ��strcat	�ַ�����ƴ��
�������ַ�����������,���շ������Ӻ��ַ������׵�ַ.

������
	A���Ȱ�dest�ַ������׵�ַ��������
	B���Ƚ�destָ�������ѭ��������'\0'�Ĳ���
	C����srcָ�������ѭ��������dest,����src�����'\0'
*/
char* myStrcat(char* dest, const char* src){
	char* ret = dest;
	assert(dest);
	assert(src);

	//�Ƚ�destָ�������ѭ��������'\0'�Ĳ���
	while (*dest){
		dest++;
	}

	//��src���ݸ�����dest֮��
	while (*src){
		*dest = *src;
		dest++;
		src++;
	}
	//�����dest����׷��'\0'
	*dest = '\0';
	return ret;
}

/*
ģ��ʵ��strcmp
�ַ����ıȽϣ����ַ����ĳ����޹�
*/
int myStrcmp(const char* str1, const char* str2){
	assert(str1);
	assert(str2);

	
	while (*str1&&*str2 && (*str1 == *str2)){
		str1++;
		str2++;
	}

	return *str1 - *str2;
}

/*
ģ��ʵ��strcpy
�ַ������ƣ���src���Ƶ�dest
*/
char* myStrcpy(char* dest, const char* src){
	char* ret = dest;
	assert(dest);
	assert(dest);
	
	while (*src){
		*dest = *src;
		src++;
		dest++;
	}

	//����ٰ�'\0'Ū��dest�����
	*dest = '\0';

	//��󷵻��ʼ�����dest�ĵ�ַ
	return ret;
}

/*
ģ��ʵ��strlen
*/
//����1��ͨ�����ü�����
int myStrlen1(const char* str){
	assert(str);
	int count = 0;
	while (*str){
		count++;
		str++;
	}
	return count;
}
//����2��ͨ���ݹ�ʵ��
int myStrlen2(const char* str){
	assert(str);
	if (*str){
		return (1 + myStrlen2(str + 1));
	}

	//��*strΪ'\0'�ͽ���
	return 0;
}
//����3��ͨ����ָ�����Ϊ����������Ԫ�ظ���ʵ��
int myStrlen3(const char* str){
	const char* end = str;
	assert(str);

	//��endָ��'\0'
	while (*end){
		end++;
	}

	return (end - str);
}