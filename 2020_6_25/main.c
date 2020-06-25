#include<stdio.h>
#include<Windows.h>
#include<assert.h>
#include<stdlib.h>
#pragma warning(disable:4996)
//寻找单身狗,寻找两个单身狗，用^方式，如果在数组里面，只有一个单身狗的话，那么就数组里元素整体^一下就最后的结果就是那个单身狗
void findSingleDog(int arr[],int len,int* a,int* b){
	assert(arr);
	assert(len > 0);
	assert(a);
	assert(b);
	//先对整个数组进行异或,两个相同数异或，就直接抵消了，所有最后只剩下44^33
	int result = arr[0];
	for (int i = 1; i < len; i++){
		result ^= arr[i];
	}


	//先找找result所对应二进制，从低向高找，找到第一个1的位置
	//例如：	result：01100
	// pos 通过下面那一步，要找到第一个1, pos=00100
	int pos = 1;
	while (1){
		if (result&pos){
			break;
		}
		pos <<= 1;
	}
	
	*a = 0;	//这里一定要把a和b初始化为0，因为只有这个，任何数^0都是自己
	*b = 0;
	//找到pos位置后，对数组进行划分
	//两个相同的数一定在一起，在哪一组不重要
	//那两个单身狗，一定不在一个组
	//最后*a一定等于= 相同的数在一起^为0，最后异或其中一个单身狗，
	//最后*b一定等于= 相同的数在一起^为0，最后异或另外一个单身狗，
	for (int i = 0; i < len; i++){
		if (arr[i] & pos){
			*a ^= arr[i];
		}
		else{
			*b ^= arr[i];
		}
	}
}
int error = 0;	//字符串转成int类型数字，如果是超过int类型了，返回1，然后里面掺杂不是数字字符，返回2，如果什么问题都没有则返回0
int myAtoi(const char* str){
	assert(str);
	int flag = 1;	//表示正数还是负数
	long long result = 0;	//存储最后的结果,因为数据不确定性，int类型可能越界，所有定义为longlong类型,如果越界，修改error，然后强转成int类型，返回
	//跳过空格字符
	if (*str == ' '){
		str++;
	}
	//跳过空格字符后，再判断是否有正负号
	if (*str == '-'){
		flag = -1;
		str++;
	}
	else if (*str == '+'){
		str++;
	}

	while (*str){
		if (isdigit(*str)){
			result = result * 10 + (flag*(*str - '0'));
			if (result<INT_MIN || result>INT_MAX){
				error = 1;
				break;
			}
		}
		else{
			error = 2;
			break;
		}
		str++;
	}
	return (int)result;
}

int main(){
	//printf("%d\n", LONG LONG_MAX);
	char* str = "122144";
	int result = myAtoi(str);
	printf("error:%d  result:%d\n", error, result);





	/*int arr[] = { 1, 2, 3, 4, 5, 6, 7 ,123, 45, 1, 2, 3, 4, 5, 6, 7 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int a = 0;
	int b = 0;
	findSingleDog(arr, len, &a, &b);
	printf("%d %d\n", a, b);*/
	system("pause");
	return 0;
}