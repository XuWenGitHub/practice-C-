#include "MineSweep.h"

void menu(){
	printf("########################################\n");
	printf("############欢迎来到扫雷游戏############\n");
	printf("########################################\n");
	printf("## 1.Play #################### 2.Exit ##\n");
	printf("########################################\n");
	printf("Please Player Choice=>:");

}
int main(){
	int selet=0;	//控制while循环，
	
	while (!selet){
		menu();
		int choose=0;	//供玩家选择进入游戏或者退出
		scanf("%d", &choose);
		setbuf(stdin, NULL);	//如果玩家输入字母，也不会出错
		switch (choose){
		case 1:
			mineSweepGame();
			printf("请问是否再来一把？\n");
			Sleep(500);
			break;
		case 2:
			printf("欢迎下次再来玩\n");
			selet = 1;
			break;
		default:
			printf("输入有误，请重新输入!!!\n");
			Sleep(500);
			break;
		}

		
	}

	system("pause");
}