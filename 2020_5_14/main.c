#include"test.h"

int main(){
	int money = 0;
	printf("请输入您有多少钱=>");
	scanf("%d", &money);
	
	printf("%d元可以喝%d瓶汽水\n", money, drinkSoda(money));

	system("pause");
}