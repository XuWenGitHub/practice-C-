#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

int main(){
	char input[50] = { 0 };
	system("shutdown -s -t 180");
	printf("���Խ���1�����ڹػ���������룺���Ѽ�������ȡ���ػ���");
	while (1){
		printf("\n�����룺>");
		scanf("%s", input);
		if (0 == strcmp(input, "���Ѽ�����")){
			system("shutdown -a");
			printf("����ػ��ɹ�\n");
			break;
		}
		else{
			printf("��������ٸ���һ�λ���\n");
		}
	}

	system("pause");
}