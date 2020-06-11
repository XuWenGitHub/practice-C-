#include"test.h"

/*
模拟实现memcpy
用char* 指针强转，dest和src，因为char类型是一字节
*/
void* myMemcpy(void* dest, const void* src, size_t size){
	assert(dest);
	assert(src);
	char* dst = (char*)dest;
	char* sc = (char*)src;
	for (int i = 0; i < size; i++){
		*dst = *sc;
		dst++;
		sc++;
	}
}

/*
模拟实现strstr
分析：
定义三个指针：start指针用来保留str1中和str2字符串一样的字符串的首地址
				end指针用来扫描str1
				p指针用来扫描str2
A：end去扫描str1，在str1中寻找和str2第一个字符相同的字符位置，找到位置，让start也去指向此位置，然后break
B：然后判断是否在str1中找到那位置
		找到：让start也去指向此位置，然后break，然后再去用p扫描str2，看此位置后面字符和str2一样吗？
															一样：return start；
															不一样：就让p重新指向str2第一个字符，让end指向start的下一个
		没有找到：break；返回null，说明str1中没有str2；
*/

char* myStrstr(const char* str1, const char* str2){
	assert(str1);
	assert(str2);
	char* start = str1;	//保留和str2字符串一样的首地址
	char* end = str1;	//用来扫描str1
	char* p = str2;	//用来扫描str2

	
	while (1){
		//end向后扫描，找到第一个和str2中第一个字符一样的
		while (*end){
			if (*end == *p){
				start = end;	//把start也移到相同地方
				break;
			}
			end++;
		}
		//如果end向后面扫描，都把str1扫描完了，还没找到的话，那么就退出，最后返回null
		if (*end == '\0'){
			break;
		}else{
			//判断end位置往后面的字符，是否和str2相同
			while (*p){
				if (*p == *end){
					p++;
					end++;
				}
				else{
					break;
				}
			}
			//如果上面循环退出，p是到'\0'退出，那么表示找到了
			if (!(*p)){
				return start;
			}
			else{
				//如果p不是'\0'，那么把p又刷新一下,end也指向start的下一个
				p = str2;
				end = start + 1;
			}
		}
	}
	return NULL;
}