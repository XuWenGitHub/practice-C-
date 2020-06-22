#include"test.h"

/*一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。
编写一个函数找出这两个只出现一次的数字。*/
void findSingleDog(int **singleDog,int arr[], int len){		//第一个参数，传过来int类型指针的地址，第二个就是数组，第三个就是数组元素个数

	//给传过来singleDog指向的int类型的指针p动态开辟位置，存放两个单身狗,在主函数里面，用完，一定记得free(p)
	*singleDog = (int*)malloc(2 * sizeof(int));
	//判断动态开辟内存，是否成功
	if (*singleDog == NULL){
		printf("mallocERROR\n");
	}
	
	int count = 0;	//单身狗数组的下标
	int flag = 0;	//表示没有出现过，如果i和j不相等的情况下，arr[i],arr[j]相等，flag变成1
	for (int i = 0; i < len; i++){
		int temp = arr[i];	//一个一个找
		for (int j = 0; j < len; j++){
			if (j != i&&arr[j] == temp){
				flag = 1;
				break;	//flag变成1，那么说明temp不是单身狗，就可以去判断下一个temp了
			}
		}
		if (!flag){
			//如果flag等于0，那么说明，flag没有变成1，说明该temp是单身狗，就可以存入singleDog[2]数组里
			(*singleDog)[count] = temp;
			count++;
		}
		else{
			//如果temp不是单身狗，那么重置flag为0，判断下一个temp
			flag = 0;
		}
	}
	
	
}

//模拟实现strncpy	把src后面num个字节复制到dest里面，最后不会带上'\0'
char* myStrcpy(char* dest, const char* src, size_t num){
	assert(dest);
	assert(src);
	char* p = dest;	//保存dest的首地址
	for (int i = 0; i < num; i++){
		*dest = *src;
		dest++;
		src++;
	}
	return p;
}

//模拟实现strncat	把src后面num个字节拼接到dest后面，最后会带上'\0'
char* myStrncat(char* dest, const char* src, size_t num){
	assert(dest);
	assert(src);
	char* p = dest;	//这个保存dest字符串的首地址，最后返回它
	//先找到dest的'\0'处
	while (*dest){
		dest++;
	}
	//现在dest指向自己'\0'处，然后把src的num个字节拼接到dest后面，最后再补上一个'\0'
	for (int i = 0; i < num; i++){
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return p;
}




//把一个字符串转成一个int类型的整数，遇到'\0'或者不是数字字符结束，如果字符串中第一个都不是数字字符，那么直接返回0
int myAtoi(char* str){
	assert(str);
	int result = 0;	//保存结果，初始值为0，如果字符串第一个都不是数字字符，那么就直接返回0
	int len = 0;	//计算出字符串中从第一个字符开始判断是否是数字字符，到不是数字字符的长度,然后再从字符串中取出一个字符数字，就知道该乘以几个10了，例如：len=3，取出第一个数就乘（len-1）个10，当len=0，就不乘
	char* cur = str;	//遍历string，算出len
	while (*cur >= '0'&&*cur <= '9'){
		len++;
		cur++;
	}
	
	while (*str >= '0'&&*str <= '9'){
		int temp = (int)(*str - 48);	//取出来的数，转成对应的int类型数
		if (len != 1){
			//如果不是最后一个数，就要把取出来的数，乘10的(len-1)次方
			temp = temp*pow(10, (len - 1));
		}
		result += temp;
		//更新len和str
		len--;
		str++;
	}
	return result;
}
