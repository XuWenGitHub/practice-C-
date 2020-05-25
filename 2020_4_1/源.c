#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

//写一个方法将三个数按从大到小输出
void sortNumberPrintf(int number1,int number2,int number3){
	//定义一个数组，先把三个数，存进一个数组里
	int array[] = { number1, number2, number3 };
	
	//对数组进行一个遍历
	printf("没有排序前：\n");
	printf("[");
	for (int i = 0; i < (sizeof(array) / sizeof(array[0])); i++){
		if (i == (sizeof(array) / sizeof(array[0]) - 1)){
			printf("%d]", array[sizeof(array) / sizeof(array[0]) - 1]);
		}
		else{
			printf("%d ,", array[i]);
		}
	}
	printf("\n");
	
	//再对数组进行排序（选择，冒泡，插入，快排...）我就写一个简单的冒泡排序(降序)
	for (int i = 1; i <= (sizeof(array) / sizeof(array[0]) - 1); i++){
		for (int j = 0; j < (sizeof(array) / sizeof(array[0])) - i; j++){
			if (array[j + 1]>array[j]){
				int temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
			}
		}
	}

	//然后再遍历排序后的数组
	printf("从大到小排序后：\n");
	printf("[");
	for (int i = 0; i < (sizeof(array) / sizeof(array[0])); i++){
		if (i == (sizeof(array) / sizeof(array[0]) - 1)){
			printf("%d]", array[sizeof(array) / sizeof(array[0]) - 1]);
		}
		else{
			printf("%d ,", array[i]);
		}
	}
	printf("\n");
}

//这里第二种方法，我是用的是选择语句来做的
void threeNumberPrintf(){
	int temp,a,b,c;
	printf("请输入三个数：\n");
	scanf("%d%d%d", &a, &b, &c);
	if (a < b){
		temp = a;
		a = b;
		b = temp;
	}
	if (a < c){
		temp = a;
		a = c;
		c = temp;
	}
	if (b < c){
		temp = b;
		b = c;
		c = temp;
	}
	printf("从大到小为:%d %d %d\n", a, b, c);
}

//写一个代码打印1-100之间所有3的倍数的数字	
void multipleOf3(){
	int start = 0;
	int end = 0;
	printf("			温馨小提示：（输入一个数,然后空格，再输入另一个数,再回车。）\n\n");
	printf("请输入您想在多少之间找出所有3的倍数的数字：");
	scanf("%d %d", &start, &end);
	//printf("（输入一个数,然后空格，再输入另一个数,再回车。）\n");
	while (start<=end)
	{
		if (start %3==0){
			printf("%d,", start);
			start++;
		}
		else{
			
		}
		start++;
	}
	printf("\n");
}

int main(){
	//sortNumberPrintf(1, 2, 3);
	//threeNumberPrintf();
	multipleOf3();
	system("pause");
}