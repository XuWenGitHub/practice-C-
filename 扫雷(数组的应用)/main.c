#include "MineSweep.h"

void menu(){
	printf("########################################\n");
	printf("############��ӭ����ɨ����Ϸ############\n");
	printf("########################################\n");
	printf("## 1.Play #################### 2.Exit ##\n");
	printf("########################################\n");
	printf("Please Player Choice=>:");

}
int main(){
	int selet=0;	//����whileѭ����
	
	while (!selet){
		menu();
		int choose=0;	//�����ѡ�������Ϸ�����˳�
		scanf("%d", &choose);
		setbuf(stdin, NULL);	//������������ĸ��Ҳ�������
		switch (choose){
		case 1:
			mineSweepGame();
			printf("�����Ƿ�����һ�ѣ�\n");
			Sleep(500);
			break;
		case 2:
			printf("��ӭ�´�������\n");
			selet = 1;
			break;
		default:
			printf("������������������!!!\n");
			Sleep(500);
			break;
		}

		
	}

	system("pause");
}