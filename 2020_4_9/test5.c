#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

int main(){
	char input[50] = { 0 };
	system("shutdown -s -t 180");
	printf("电脑将在1分钟内关机，如果输入：廉佳佳是猪，就取消关机！");
	while (1){
		printf("\n请输入：>");
		scanf("%s", input);
		if (0 == strcmp(input, "廉佳佳是猪")){
			system("shutdown -a");
			printf("解除关机成功\n");
			break;
		}
		else{
			printf("输入错误，再给你一次机会\n");
		}
	}

	system("pause");
}