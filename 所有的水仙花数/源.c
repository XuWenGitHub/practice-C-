#pragma warning(disable:4996)
#include<stdio.h>
#include<math.h>
int main(){
	int number, a, b, c;
    printf("ˮ�ɻ�����һ����λ�����λ���ֵ������͵��ڸ�������\n���磺3*3*3+7*7*7+0*0*0=370\n������������е�ˮ�ɻ���\n");
	printf("\n");
	for (number = 100; number <= 999; number++){
		a = number / 100;
		b = (number / 10) % 10;
		c = number % 10;
		if (number == pow(a, 3) + pow(b, 3) + pow(c, 3))
			printf("ˮ�ɻ�����%d\n", number);
	}
	printf("\n");

		system("pause");
		return 0;
}