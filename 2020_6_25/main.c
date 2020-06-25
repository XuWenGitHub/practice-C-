#include<stdio.h>
#include<Windows.h>
#include<assert.h>
#include<stdlib.h>
#pragma warning(disable:4996)
//Ѱ�ҵ���,Ѱ��������������^��ʽ��������������棬ֻ��һ�������Ļ�����ô��������Ԫ������^һ�¾����Ľ�������Ǹ�����
void findSingleDog(int arr[],int len,int* a,int* b){
	assert(arr);
	assert(len > 0);
	assert(a);
	assert(b);
	//�ȶ���������������,������ͬ����򣬾�ֱ�ӵ����ˣ��������ֻʣ��44^33
	int result = arr[0];
	for (int i = 1; i < len; i++){
		result ^= arr[i];
	}


	//������result����Ӧ�����ƣ��ӵ�����ң��ҵ���һ��1��λ��
	//���磺	result��01100
	// pos ͨ��������һ����Ҫ�ҵ���һ��1, pos=00100
	int pos = 1;
	while (1){
		if (result&pos){
			break;
		}
		pos <<= 1;
	}
	
	*a = 0;	//����һ��Ҫ��a��b��ʼ��Ϊ0����Ϊֻ��������κ���^0�����Լ�
	*b = 0;
	//�ҵ�posλ�ú󣬶�������л���
	//������ͬ����һ����һ������һ�鲻��Ҫ
	//������������һ������һ����
	//���*aһ������= ��ͬ������һ��^Ϊ0������������һ��������
	//���*bһ������= ��ͬ������һ��^Ϊ0������������һ��������
	for (int i = 0; i < len; i++){
		if (arr[i] & pos){
			*a ^= arr[i];
		}
		else{
			*b ^= arr[i];
		}
	}
}
int error = 0;	//�ַ���ת��int�������֣�����ǳ���int�����ˣ�����1��Ȼ��������Ӳ��������ַ�������2�����ʲô���ⶼû���򷵻�0
int myAtoi(const char* str){
	assert(str);
	int flag = 1;	//��ʾ�������Ǹ���
	long long result = 0;	//�洢���Ľ��,��Ϊ���ݲ�ȷ���ԣ�int���Ϳ���Խ�磬���ж���Ϊlonglong����,���Խ�磬�޸�error��Ȼ��ǿת��int���ͣ�����
	//�����ո��ַ�
	if (*str == ' '){
		str++;
	}
	//�����ո��ַ������ж��Ƿ���������
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