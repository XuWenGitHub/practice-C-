#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)

//��������Ϸ
void guessNumber(){
	//������������ӣ�����һ��1-100�������
	srand((time(NULL)));
	int x = 1 + (rand() % 100);
	
	printf("������Ҳ�һ��1-100���������ֻ�ܲ²�5�Σ�ף������\n\n");
	int count = 1;
	//һ��ֻ���������5�Σ��´�����ʧ��
	while (count<=6){
		//��Ҽ���¼��һ������
		printf("��һ����1-100����������\n");
		int a = 0;
		scanf("%d", &a);

		if (a > x){
			printf("��%d�β²⣺���µ�����%d����\n",count, a);
			count++;
		}
		else if (a < x){
			printf("��%d�β²⣺���µ�����%dС��\n",count, a);
			count++;
		}
		else{
			printf("��ϲ�㣬%d�ξͲ�����\n\n",count);
			break;
		}

		if (count == 6){
			printf("������˼�����Ѿ��´�5�Σ�gameover\n\n");
			break;
		}

	}

	//�ж�����Ƿ�����һ��
	printf("���Ƿ�����һ�ѣ�����һ������1,����������0��\n");
	int choose = 0;
	scanf("%d", &choose);
	if (choose == 1){
		//������һ����������
		system("cls");
		//������һ���ݹ飬�ÿ�����Ƿ�����һ��
		guessNumber();
	}
}
//int main(){
//	
//	guessnumber();
//	system("pause");
//}