#include "chess.h"

void menu(){
	printf("##############################\n");
	printf("## ��ӭ�����ҵ���������Ϸ�� ##\n");
	printf("##############################\n");
	printf("## 1.Paly            2.Exit ##\n");
	printf("##############################\n");
	printf("Please Enter Select:>");
}
void menu2(){
	printf("##############################\n");
	printf("####### ��ѡ����Լ��� #######\n");
	printf("##############################\n");
	printf("######### 1.�������� #########\n");
	printf("######### 2.�м����� #########\n");
	printf("######### 3.�߼����� #########\n");
	printf("##############################\n");
	printf("Please Enter Select:>");
}
int main(){
	int quit = 0;
	while (!quit){
		int select = 0;
		menu();
		scanf("%d", &select);

		switch (select){//ѡ���Ƿ�����Ϸ
		case 1:
			system("cls");//��������
			while (1){	 //ѭ�����棬ֻ��ѡ����ȷ�ˣ��Ż�break��
				menu2();
				int choose = 0;//ѡ��߼�or��������
				scanf("%d", &choose);
				if (choose == 1 || choose == 2||choose==3){	//�ж�����Ƿ�ѡ����ȷ���������ȷ����ѡ��
					game(choose);
					break;
				}
				else{
					system("cls");
					printf("�������������������룡����\n");
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
			//printf("������ѡ��!!!!!\n");
			break;
		}
	}

	system("pause");
}