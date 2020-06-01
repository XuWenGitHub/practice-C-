#include"test.h"

/*
杨氏矩阵
有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序在这样的矩阵中查找某个数字是否存在。
要求：时间复杂度小于O(N);
*/
/*
杨氏矩阵
1  2  8   9
2  4  9   12
4  7  10  13
6  8  11  15
思路，从右上角那个数字来，如果该数字大于value，说明那一列都没有
	  如果该数字小于value，说明那一行都没有
*/
int findYangArray(int array[][4], int row, int col, int value){
	int newRow = 0;
	int newCol = col - 1;
	/*
	循环条件就是：
	newRow在增加，但是必须要小于row，数组索引从0开始
	newCol在减少，但是必须要大于等于0，数组索引从0开始
	*/
	while (newRow<row&&newCol>=0){
		if (value > array[newRow][newCol]){
			newRow++;	//查找的数字大于右上角那一个，说明这一行没有
		}
		else if (value<array[newRow][newCol]){
			newCol--;	//查找的数字小于右上角那一个，说明这一列都没有
		}
		else if (value == array[newRow][newCol]){
			return 1;	//说明找到了
		}
	}
	return 0;	//循环结束，还没有找到，说明该value不存在，返回0
}

