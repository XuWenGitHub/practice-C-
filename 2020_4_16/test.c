#include"test.h"

//ʵ��һ���������ж�һ�����ǲ���������
//��������ʵ�ֵĺ�����ӡ100��200֮���������
void isPrime(int a, int b){//a,bΪ������������
	int i, j;
	printf("%d-%d֮�������Ϊ��",a,b);
	for (j = a; j < b + 1; j++){

		for (i=2; i <= sqrt(j); i++){
			if (j%i == 0){
				break;
			}
		}

		if (i>sqrt(j)){
			printf("%d ", j);
		}

	}
	printf("\n");
}

//ʵ�ֺ����ж�year�ǲ�������
//����1Ϊ���꣬����0��������
int isLeapYear(int year){ 
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
		return 1;
	}
	else{
		return 0;
	}
}

//ʵ��һ�������������������������ݡ�
//ʵ�δ����ʱ��Ҫ��&��ȡ��ַ����
void exchange(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//ʵ��һ����������ӡ�˷��ھ����ھ���������������Լ�ָ��
//�磺����9�����9 * 9�ھ������12�����12 * 12�ĳ˷��ھ���
void mulTips(int a){//aΪ�˷��ھ�����к���
	for (int i = 1; i <= a; i++){
		for (int j = 1; j <= i; j++){
			printf("%d*%d=%d  ", j, i, i*j);
		}
		printf("\n");
	}
}

//�ݹ鷽ʽʵ�ִ�ӡһ��������ÿһλ
void printInt(int a){
	if (a > 9){
		printInt(a / 10);
	}

	printf("%d ", a % 10);
}

//�ݹ�ʵ����n�Ľ׳ˣ���������������⣩
int factorial(int n){
	if (n == 1){
		return 1;
	}

	return n*factorial(n - 1);
}

//�ǵݹ�ʵ����n�Ľ׳ˣ���������������⣩
int factorial2(int n){
	int result = 1;
	for (int i = n; i > 1; i--){
		result *= i;
	}

	return result;
}

//�ݹ�ʵ��strlen
int myStrlen(char *str){
	if (*str == '\0'){
		return 0;
	}
	
	return 1 + myStrlen(str + 1);
}

//�ǵݹ�ʵ��strlen
int myStrlen2(char array[]){
	int len = 0;
	for (int i=0; array[i] != '\0'; i++){
		len += 1;
	}

	return len;
}

/*��дһ������ reverse_string(char * string)���ݹ�ʵ�֣�
ʵ�֣��������ַ����е��ַ��������С�
Ҫ�󣺲���ʹ��C�������е��ַ�������������*/
void reverse_string(char * string){
	if (*string != '\0'){
		reverse_string(string + 1);
	}

	if (*string != '\0'){
		printf("%c", *string);
	}
}

/*
���ǵݹ�ʵ�֣���һ���ַ�������.
*/
void reverse_string2(char * string){
	char *start = string;
	char *end = string + strlen(string) - 1;

	while (start < end){
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

//�ݹ�ʵ���ַ�������,���Լ���˼·
void reverse_string4(char * string){
	char *start = string;
	char *end = string + strlen(string) - 1;
	char temp = *start;
	*start = *end;
	*end = '\0';
	if (strlen(string ) >= 2){
		reverse_string4(string + 1);
	}
	*end = temp;
}

//�ݹ�ʵ���ַ�������
void reverse_string3(char * string){
	char *start = string;
	char *end = string + strlen(string) - 1;
	char temp = *start;
	*start = *end;
	*end = '\0';
	if (strlen(string + 1) >= 2){
		reverse_string3(string + 1);
	}
	*end = temp;
}


/*дһ���ݹ麯��DigitSum(n)������һ���Ǹ����������������������֮��
���磬����DigitSum(1729)����Ӧ�÷���1+7+2+9�����ĺ���19
���룺1729�������19
*/
int DigitSum(int a){
	
	if (a > 9){
		return a%10+DigitSum(a / 10);
	}
	return a;
}

//��дһ������ʵ��n��k�η���ʹ�õݹ�ʵ��
int nPowerK(int n, int k){
	if (k > 0){
		return n*nPowerK(n, --k);
	}
	return 1;
}

/*�ݹ�ʵ�����n��쳲�������
���磺
���룺5  �����5
���룺10�� �����55
���룺2�� �����1
*/
int n_Fibonacci(int n){
	if (n == 1 || n == 2){
		return 1;
	}
	return n_Fibonacci(n - 1) + n_Fibonacci(n - 2);
}

/*�ǵݹ�ʵ�����n��쳲�������
���磺
���룺5  �����5
���룺10�� �����55
���룺2�� �����1
*/
int n_Fibonacci2(int n){
	int one = 1;
	int two = 1;
	int three = 1;
	while (n-3>=0){
		one = two;
		two = three;
		three = one + two;
		n--;
	}
	return three;
}

/*
n��ʾ��ŵ���Ĳ���
a��ʾ�������Բ�̵�����
b��ʾ����ת���õ�����
c��ʾ��Ҫ�ƶ�����Ŀ������
*/
void hanNuo(int n, char a, char b, char c){
	if (n == 1){

	}
}