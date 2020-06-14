#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<assert.h>
#pragma warning(disable:4996)

/*模拟实现memmove，解决内存重叠问题*/
void* myMemove(void* destination, const void* source,size_t size){
	assert(destination);
	assert(source);
	assert(size >= 0);
	char* dest = (char*)destination;
	char* src = (char*)source;
	/*
	dest和src内存重叠就出错:解决内存重叠，就是判断从左向右，还是从右向左
	*/
	/*for (int i = 0; i < size; i++){
		*dest = *src;
		dest++;
		src++;
	}*/
	if (dest > src && dest < src + size){
		//从右向左
		dest = dest + size - 1;
		src = src + size - 1;
		for (int i = 0; i < size; i++){
			*dest = *src;
			dest--;
			src--;
		}
	}
	else{
		//从左向右
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