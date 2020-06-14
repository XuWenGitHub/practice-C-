#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<assert.h>
#pragma warning(disable:4996)

/*ģ��ʵ��memmove������ڴ��ص�����*/
void* myMemove(void* destination, const void* source,size_t size){
	assert(destination);
	assert(source);
	assert(size >= 0);
	char* dest = (char*)destination;
	char* src = (char*)source;
	/*
	dest��src�ڴ��ص��ͳ���:����ڴ��ص��������жϴ������ң����Ǵ�������
	*/
	/*for (int i = 0; i < size; i++){
		*dest = *src;
		dest++;
		src++;
	}*/
	if (dest > src && dest < src + size){
		//��������
		dest = dest + size - 1;
		src = src + size - 1;
		for (int i = 0; i < size; i++){
			*dest = *src;
			dest--;
			src--;
		}
	}
	else{
		//��������
		for (int i = 0; i < size; i++){
			*dest = *src;
			dest++;
			src++;
		}
	}
	return destination;
}

int main(){
	char str[32] = { "hello world" };
	char str2[32];
	printf("begin:%s\n", str);
	myMemove(str+1, str, strlen(str) + 1);
	printf("last:%s\n", str);
	printf("last:%s\n", str2);
	system("pause");
	return 0;
}