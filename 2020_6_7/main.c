#include"test.h"


int main(){
	char str1[] = "1234abcd";
	char str2[] = "abcd1234";
	int len = strlen(str1);
	int num = 3;
	
	//动态申请内存的用法
	//stdlib.h头文件  malloc函数
	//void* malloc(size_t size);	
	char *double_mem = (char*)malloc(2 * len + 1);	//代表双倍串的内存
	if (double_mem == NULL){
		return -1;
	}
	strcpy(double_mem, str1);	//字符串拷贝
	strcat(double_mem, str1);	//字符串拼接
	printf("%s\n", double_mem);
	//char* strcat(char* destination,const char* source);	字符串拼接，默认也会加上\0

	//判断一个字符串，是否为另一个字符串的子串
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
	//	LeftRotate(str1, len, 1);	//方法1
	//	LeftRotate2(str1, len, 3);	//方法2
	//}
	//if (i == len){
	//	printf("no\n");
	//}
	

	//printf("before:%s\n", str1);
	////方法2测试
	//LeftRotate2(str1, len, 3);
	//printf("end:%s\n", str1);
	system("pause");
}