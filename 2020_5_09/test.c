#include"test.h"

//�ַ�������
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

/*��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮�ͣ�����a��һ�����֣�
���磺2+22+222+2222+22222*/
int plusResult(int a,int n){
	int result=0;//�ۼ���
	int sn=0;
	for (int i = 0; i < n; i++){
		sn = sn * 10 + 2;
		printf("%d\n", sn);
		result += sn;
	}
	return result;
}