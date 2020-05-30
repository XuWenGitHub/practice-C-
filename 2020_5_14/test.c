#include"test.h"

/*喝汽水，1瓶汽水1元，2个空瓶可以换一瓶汽水，给20元，可以多少汽水（编程实现）*/
int drinkSoda(int money){
	int countSoda = 0;	//可以喝多少瓶汽水
	int count = 0;	//	统计空瓶

	//只要money不为0，就一直循环，然后money每次循环减少1元
	while (money){
		money--;		//花一元买一瓶汽水，所以要减1
		countSoda++;	//每花一元钱，买一瓶汽水，那么countSoda+1
		count++;		//喝完了一瓶汽水，空瓶也要加一

		if (2==count){
			//如果有两个空瓶可以换一瓶汽水
			countSoda++;

			//然后把count空瓶数清0
			count = 0;

			//但是两个空瓶换了一瓶汽水后，喝完了,又会有一个空瓶子
			count++;
		}	
	}

	//最后一定能剩下一个空瓶，因为你喝了最后一瓶汽水后，就会留下一个空瓶，不够2个空瓶换不了
	printf("剩余瓶子：%d\n", count);

	return countSoda;
}