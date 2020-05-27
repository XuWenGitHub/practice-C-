#include "chess.h"

void menu(){
	printf("##############################\n");
	printf("## 欢迎来到我的三子棋游戏室 ##\n");
	printf("##############################\n");
	printf("## 1.Paly            2.Exit ##\n");
	printf("##############################\n");
	printf("Please Enter Select:>");
}
void menu2(){
	printf("##############################\n");
	printf("####### 请选择电脑级别 #######\n");
	printf("##############################\n");
	printf("######### 1.初级电脑 #########\n");
	printf("######### 2.中级电脑 #########\n");
	printf("######### 3.高级电脑 #########\n");
	printf("##############################\n");
	printf("Please Enter Select:>");
}
int main(){
	int quit = 0;
	while (!quit){
		int select = 0;
		menu();
		scanf("%d", &select);

		switch (select){//选择是否玩游戏
		case 1:
			system("cls");//清屏操作
			while (1){	 //循环里面，只有选择正确了，才会break。
				menu2();
				int choose = 0;//选择高级or初级电脑
				scanf("%d", &choose);
				if (choose == 1 || choose == 2||choose==3){	//判断玩家是否选择正确，如果不正确重新选择
					game(choose);
					break;
				}
				else{
					system("cls");
					printf("您输入有误，请重新输入！！！\n");
					Sleep(1000);
				}
			}
			break;
		case 2:	
			quit = 1;
			break;
		default:
			system("cls");
			printf("Enter Error!\n");
			//printf("请重新选择!!!!!\n");
			break;
		}
	}

	system("pause");
}