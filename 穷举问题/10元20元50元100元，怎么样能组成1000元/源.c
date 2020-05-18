//多少张10元，多少张20元，多少张50元，多少张100元，加起来能组成1000元，一共有多少种组法,每五种组法空一行
#pragma  warning(disable:4996)
#include<stdio.h>
#include<math.h>
int main(){
	int count = 0;         //count记录每有一种方法，就记录一次//
	int i, j, k, m;       //i表示10元，j表示20元，k表示50元，m表示100元//
	for (i = 0; i <= 100; i++){
		for (j = 0; j <= 50; j++){
			for (k = 0; k <= 20; k++){
				for (m = 0; m <= 10; m++){
					if (i * 10 + j * 20 + k * 50 + m * 100 == 1000){
						count++;
                        printf("%d张十元\t%d张二十元\t%d张五十元\t%d张一百元\n", i, j, k, m);
						if (count % 5 == 0)
							printf("\n");
						
					}	 
				}
			}
		}
	}
	printf("一共有%d种组法\n", count);
	system("pause");
	return 0;
}


