#include"test.h"

/*用C语言在屏幕上输出以下图案：
打印菱形
*/
void printRhombus(){
	int line = 0;  //菱形的边长，也是上边三角形的行数
	printf("请选择打印菱形的边长为=>");
	scanf("%d", &line);

	//如果输入数据为1，直接报错
	if (line == 1){
		printf("输入数据有误\n");
		return -1;
	}
/*  
	  *
     ***
    *****
   *******
  *********
 ***********
*************
 ***********
  *********
   *******
    *****
     ***
      *
*/
	/*
	上面是一个菱形，我们要打印菱形，先观察分析
	这个菱形边长为7，我们先打印上半部分,行数为line
	1.上半部分7行，和菱形边长一样，用一个最外层的循环，控制行数
	2.打印每一行的空格，找规律，第一行有6个空格，第二行有5个空格，每一行逐个递减
	3.打印每一行的*，找规律：1,3,5,7,9...  规律：需要打印的*个数为（行数×2+1）
	*/
	
	//打印上半部分
	for (int i = 0; i <line; i++){		//控制每一行的循环

		for (int j = 0; j < line - 1 - i; j++){		//打印每一行的空格
			printf(" ");
		}

		for (int k = 0; k <=2*i; k++){	//打印每一行的*		因为从0开始，且行数也是从0开始,所以就不需要+1了，并且判断要取<=号，不然第一行，不满足
			printf("*");
		}

		printf("\n");	//每一行结束换行一下
	}

	/*
	打印下半部分分析：
	打印下半部分，行数为line
	下半部分为6行，比菱形边长的大小小1，用一个最外层循环，控制行数
	打印每一行的空格，找规律：1,2,3,4....6
	打印每一行的*，找规律：11,9,7,5....1
	*/

	//打印下半部分
	for (int i = 0; i < line - 1; i++){		//控制每一行的循环

		for (int j = 0; j <= i; j++){		//打印每一行的空格
			printf(" ");
		}

		for (int k = 0; k < line * 2 - 3 - 2 * i; k++){		//打印每一行的*
			printf("*");
		}

		printf("\n");	//每一行结束换行一下
	}
}




/*求出0～100000之间的所有“水仙花数”并输出。
“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，如:153＝1^3＋5^3＋3^3，则153是一个“水仙花数”。*/
void daffodilNumber(int start, int end){
	//做判断,start<=end,start>=0,不满足，就是输入数据有误
	if (start <= end&&start>=0){

		//遍历到每一个数字
		for (int i = start; i <= end; i++){
			//先判断数有多少位
			int count = 0;	//统计一个数字有多少位
			for (int j = i; j != 0; j /= 10){
				count++;
			}

			//这是把每一位的n次方累加到compare里
			int compare = 0;//最后要做比较的数字
			int temp = i;
			for (int k = 0; k < count; k++){

				compare = compare + pow((temp % 10), count);	//把数字每一位的count次方存入compare
				temp /= 10;
			}

			//作比较
			if (compare == i){
				printf("%d为水仙花数\n", i);
			}
		}

	}
	else{
		printf("输入数据有误！！！\n");
	}
}