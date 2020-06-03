#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

//猜数字游戏
void guessNumber(){
	//种下随机数种子，产生一个1-100的随机数
	srand((time(NULL)));
	int x = 1 + (rand() % 100);
	
	printf("规则：玩家猜一个1-100的数，最多只能猜测5次，祝您好运\n\n");
	int count = 1;
	//一共只让玩家最多猜5次，猜错误则失败
	while (count<=6){
		//玩家键盘录入一个整数
		printf("猜一个（1-100）的整数：\n");
		int a = 0;
		scanf("%d", &a);

		if (a > x){
			printf("第%d次猜测：您猜的数字%d大了\n",count, a);
			count++;
		}
		else if (a < x){
			printf("第%d次猜测：您猜的数字%d小了\n",count, a);
			count++;
		}
		else{
			printf("恭喜你，%d次就猜中了\n\n",count);
			break;
		}

		if (count == 6){
			printf("不好意思，您已经猜错5次，gameover\n\n");
			break;
		}

	}

	//判断玩家是否再来一次
	printf("您是否再来一把，再来一把输入1,不玩了输入0。\n");
	int choose = 0;
	scanf("%d", &choose);
	if (choose == 1){
		//这里是一个清屏操作
		system("cls");
		//这里是一个递归，让看玩家是否再来一次
		guessNumber();
	}
}
//int main(){
//	
//	guessnumber();
//	system("pause");
//}