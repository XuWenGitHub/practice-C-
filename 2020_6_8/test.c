#include"test.h"

/*
模拟实现strcat	字符串的拼接
将两个字符串连接起来,最终返回连接后字符串的首地址.

分析：
	A：先把dest字符串的首地址保存起来
	B：先将dest指向的内容循环遍历到'\0'的部分
	C：将src指向的内容循环拷贝给dest,包括src后面的'\0'
*/
char* myStrcat(char* dest, const char* src){
	char* ret = dest;
	assert(dest);
	assert(src);

	//先将dest指向的内容循环遍历到'\0'的部分
	while (*dest){
		dest++;
	}

	//将src内容复制在dest之后
	while (*src){
		*dest = *src;
		dest++;
		src++;
	}
	//最后在dest后面追加'\0'
	*dest = '\0';
	return ret;
}

/*
模拟实现strcmp
字符串的比较，跟字符串的长度无关
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
模拟实现strcpy
字符串复制，把src复制到dest
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

	//最后再把'\0'弄在dest最后面
	*dest = '\0';

	//最后返回最开始保存的dest的地址
	return ret;
}

/*
模拟实现strlen
*/
//方法1：通过设置计数器
int myStrlen1(const char* str){
	assert(str);
	int count = 0;
	while (*str){
		count++;
		str++;
	}
	return count;
}
//方法2：通过递归实现
int myStrlen2(const char* str){
	assert(str);
	if (*str){
		return (1 + myStrlen2(str + 1));
	}

	//当*str为'\0'就结束
	return 0;
}
//方法3：通过两指针相减为所经历过的元素个数实现
int myStrlen3(const char* str){
	const char* end = str;
	assert(str);

	//让end指向'\0'
	while (*end){
		end++;
	}

	return (end - str);
}