//������10Ԫ��������20Ԫ��������50Ԫ��������100Ԫ�������������1000Ԫ��һ���ж������鷨,ÿ�����鷨��һ��
#pragma  warning(disable:4996)
#include<stdio.h>
#include<math.h>
int main(){
	int count = 0;         //count��¼ÿ��һ�ַ������ͼ�¼һ��//
	int i, j, k, m;       //i��ʾ10Ԫ��j��ʾ20Ԫ��k��ʾ50Ԫ��m��ʾ100Ԫ//
	for (i = 0; i <= 100; i++){
		for (j = 0; j <= 50; j++){
			for (k = 0; k <= 20; k++){
				for (m = 0; m <= 10; m++){
					if (i * 10 + j * 20 + k * 50 + m * 100 == 1000){
						count++;
                        printf("%d��ʮԪ\t%d�Ŷ�ʮԪ\t%d����ʮԪ\t%d��һ��Ԫ\n", i, j, k, m);
						if (count % 5 == 0)
							printf("\n");
						
					}	 
				}
			}
		}
	}
	printf("һ����%d���鷨\n", count);
	system("pause");
	return 0;
}


