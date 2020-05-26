#include"test.h"
#include<string.h>;

int main(){

	//printf("%d", leastCommonMultiple(5, 7));
	char str[2000];
	//scanf("%s", str);
	gets(str);
	
	int len = strlen(str);
	//printf("%d", len);
	printf("start：%s\n", str);
	//这已经将字符串整体逆序
	convertString(str, str + len - 1);
	printf("end：%s\n", str);
	convertWord2(str,len);
	printf("end：%s\n", str);
	system("pause");

	
}