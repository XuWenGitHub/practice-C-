#include"test.h"


int main(){
	char str1[] = "1234abcd";
	char str2[] = "abcd1234";
	int len = strlen(str1);
	int num = 3;
	
	//��̬�����ڴ���÷�
	//stdlib.hͷ�ļ�  malloc����
	//void* malloc(size_t size);	
	char *double_mem = (char*)malloc(2 * len + 1);	//����˫�������ڴ�
	if (double_mem == NULL){
		return -1;
	}
	strcpy(double_mem, str1);	//�ַ�������
	strcat(double_mem, str1);	//�ַ���ƴ��
	printf("%s\n", double_mem);
	//char* strcat(char* destination,const char* source);	�ַ���ƴ�ӣ�Ĭ��Ҳ�����\0

	//�ж�һ���ַ������Ƿ�Ϊ��һ���ַ������Ӵ�
	if (strstr(double_mem, str2) != NULL){
		printf("yes\n");
	}
	else{
		printf("no\n");
	}
	free(double_mem);
	
	//int i = 0;
	//for (i = 0; i < len; i++){
	//	if (0 == strcmp(str1, str2)){
	//		printf("yes!\n");
	//		break;
	//	}
	//	
	//	LeftRotate(str1, len, 1);	//����1
	//	LeftRotate2(str1, len, 3);	//����2
	//}
	//if (i == len){
	//	printf("no\n");
	//}
	

	//printf("before:%s\n", str1);
	////����2����
	//LeftRotate2(str1, len, 3);
	//printf("end:%s\n", str1);
	system("pause");
}