#include"test.h"

int main(){
	/*int a, b;
	printf("请输入您想求多少到多少的素数：(输入格式为：a b回车)");
	scanf("%d %d", &a, &b);
	isprime(a, b);*/

	/*for (int i = 1; i < 2001; i++){
		if (isLeapYear(i)){
			printf("%d ", i);
		}
	}*/

	/*int a = 10;
	int b = 20;
	exchange(&a, &b);
	printf("a=%d,b=%d\n", a, b);*/

	/*mulTips(9);*/

	/*printInt(1234);*/

	/*printf("5的阶乘为：%d\n", factorial(5));
	printf("5的阶乘为：%d\n", factorial2(5));*/

	/*printf("abcd 1234的长度为：%d\n", myStrlen("abcd 1234"));
	printf("abcd 1234的长度为：%d\n", myStrlen2("abcd 1234"));*/

	/*reverse_string("1234567890 abcd");*/

	/*printf("12345 :%d", DigitSum(1729));*/

	/*printf("2的3次方：%d\n", nPowerK(2, 3));*/

	/*for (int i = 1; i <= 10; i++){
		
		printf("第%d个斐波那列数为：%d %d\n",i, n_Fibonacci(i), n_Fibonacci2(i));
	}*/

	char str[] = "abcd1234";
	//printf("after:%s\n", str);
	//reverse_string2(str);
	reverse_string4(str);
	printf("end:%s\n", str);

	//reverse_string(str);

	//printf("after:%s\n", str);
	//reverse_string3(str);
	//printf("end:%s\n", str);

	system("pause");
}