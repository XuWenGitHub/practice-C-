#include"test.h"

/*
5位运动员参加了10米台跳水比赛，有人让他们预测比赛结果：
A选手说：B第二，我第三；
B选手说：我第二，E第四；
C选手说：我第一，D第二；
D选手说：C最后，我第三；
E选手说：我第四，A第一；
比赛结束后，每位选手都说对了一半，请编程确定比赛的名次。
*/
/*
分析：
	A：每个选手都有五种可能性，第一至第五
	B：我们先把每一种可能性都遍历到
	C：然后我们再判断每一个条件，全部打印出来看看
	D：最后发现，abcde不能有相同的，五个数乘积要==1*2*3*4*5==120
	
*/
void jumpWater(){
	int a = 0, b = 0, c = 0, d = 0, e = 0;
	for (a = 1; a <= 5; a++){
		for (b = 1; b <= 5;b++){
			for (c = 1; c <= 5; c++){
				for (d = 1; d <= 5; d++){
					for (e = 1; e <= 5; e++){

						if ((2 == b && 3 != a) || (2 != b && 3 == a)){
							if ((2 == b && 4 != e) || (2 != b && 4 == e)){
								if ((1 == c && 2 != d) || (1 != c && 2 == d)){
									if ((5 == c && 3 != d) || (5 != c && 3 == d)){
										if ((4 == e && 1 != a) || (4 != e && 1 == a)){

											//这样打印出来abcde有相同名次，但是不符合实际，所有要判断都彼此不相等
											//printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
//											if ((a != b) && (a != c) && (a != d) && (a != e) && (b != c) && (b != d) && (b != e) && (c != d) && (c != e) && (d != e)){
//												printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
//											}

											if (120 == a*b*c*d*e){
												printf("a=%d,b=%d,c=%d,d=%d,e=%d\n", a, b, c, d, e);
											}

										}
									}
								}
							}
						}

					}
				}
			}
		}
	}
	
}


/*
日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个嫌疑犯的一个。
以下为4个嫌疑犯的供词:
A说：不是我。
B说：是C。
C说：是D。
D说：C在胡说
已知3个人说了真话，1个人说的是假话。
现在请根据这些信息，写一个程序来确定到底谁是凶手
*/
/*
分析：
	（1）A说假话：A=1 C=1 D=1 D=0
	（2）B说假话：A=0 C=0 D=1 D=0
	（3）C说假话：A=0 C=1 D=0 D=0
	（4）D说假话：A=0 C=1 D=1 D=1
*/
void guessKiller(){
	int A = 0, B = 0, C = 0, D = 0;
	int FD;//因为c和d对立

	for (int i = 0; i < 4; i++){
		//A说假话
		if (i == 0){
			A = 0; C = 0; FD = 1; D = 0;
		}

		//B说假话
		if (i == 1){
			A = 0; C = 1; FD = 0; D = 0;
		}

		//C说假话
		if (i == 2){
			A = 0; C = 1; FD = 1; D = 1;
		}

		//D说假话
		if (i == 3){
			A = 1; C = 1; FD = 1; D = 0;
		}

		//判断，ABCD加起来==1，并且FD要和D相等
		if ((A + B + C + D) == 1 && FD == D){
			printf("1代表是凶手，0代表不是\n");
			printf("A=%d B=%d C=%d D=%d\n", A, B, C, D);
		}
	}
}

//第二种简单方式
void guessKiller2(){
	char killer = 'A';
	for (; killer <= 'D'; killer++){
		if (((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D'))==3){
			printf("found you! : %c\n", killer);
		}
	}
}

/*在屏幕上打印杨辉三角。
1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
*/
/*
分析：
	A：每一行的第一个和最后一个都是1
	B：每一行的个数就是行数
	C：其他每个数都是上面那个数，加上上面左边那个数
*/
void printDelta(int line){
	int array[100][100];

	//给杨辉三角全赋值为1
	for (int i = 0; i < line; i++){
		for (int j = 0; j <= i; j++){
			array[i][j] = 1;
		}
	}
	
	//从第三行开始，给除了第一列，最后一列，其他数赋值
	for (int i = 2; i <= line; i++){
		for (int j = 1; j <i; j++){
			array[i][j] = array[i - 1][j - 1] + array[i - 1][j];
		}
	}


	//遍历三角
	for (int i = 0; i < line; i++){
		for (int j = 0; j <=i; j++){
			printf("%d ", array[i][j]);
		}
		printf("\n");
	}

}


