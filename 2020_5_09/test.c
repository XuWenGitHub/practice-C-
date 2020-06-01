#include"test.h"

//字符串逆序
void stringInverted(char *str,int len){
	char *start = str;
	char *end = str + len-1;

	while (start < end){
		int temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}

}

/*求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，
例如：2+22+222+2222+22222*/
int plusResult(int a,int n){
	int result=0;//累加器
	int sn=0;
	for (int i = 0; i < n; i++){
		sn = sn * 10 + 2;
		printf("%d\n", sn);
		result += sn;
	}
	return result;
}