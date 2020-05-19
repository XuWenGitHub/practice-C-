#pragma warning(disable:4996)
#include<stdio.h>
#include<math.h>
int main(){
	int number, a, b, c;
    printf("水仙花树是一个三位数其个位数字的立方和等于该数本身。\n例如：3*3*3+7*7*7+0*0*0=370\n我们来求出所有的水仙花数\n");
	printf("\n");
	for (number = 100; number <= 999; number++){
		a = number / 100;
		b = (number / 10) % 10;
		c = number % 10;
		if (number == pow(a, 3) + pow(b, 3) + pow(c, 3))
			printf("水仙花数：%d\n", number);
	}
	printf("\n");

		system("pause");
		return 0;
}