#include"test.h"

/*
���Ͼ���
��һ�����־��󣬾����ÿ�д������ǵ����ģ�������ϵ����ǵ����ģ����д�����������ľ����в���ĳ�������Ƿ���ڡ�
Ҫ��ʱ�临�Ӷ�С��O(N);
*/
/*
���Ͼ���
1  2  8   9
2  4  9   12
4  7  10  13
6  8  11  15
˼·�������Ͻ��Ǹ�����������������ִ���value��˵����һ�ж�û��
	  ���������С��value��˵����һ�ж�û��
*/
int findYangArray(int array[][4], int row, int col, int value){
	int newRow = 0;
	int newCol = col - 1;
	/*
	ѭ���������ǣ�
	newRow�����ӣ����Ǳ���ҪС��row������������0��ʼ
	newCol�ڼ��٣����Ǳ���Ҫ���ڵ���0������������0��ʼ
	*/
	while (newRow<row&&newCol>=0){
		if (value > array[newRow][newCol]){
			newRow++;	//���ҵ����ִ������Ͻ���һ����˵����һ��û��
		}
		else if (value<array[newRow][newCol]){
			newCol--;	//���ҵ�����С�����Ͻ���һ����˵����һ�ж�û��
		}
		else if (value == array[newRow][newCol]){
			return 1;	//˵���ҵ���
		}
	}
	return 0;	//ѭ����������û���ҵ���˵����value�����ڣ�����0
}

