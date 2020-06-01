#include"test.h"
//char数据类型比较
int compareChar(const void*vx, const void *vy){
	char* x = (char*)vx;
	char* y = (char*)vy;

	if (*x > *y){
		return 1;
	}
	else if (*x < *y){
		return -1;
	}
	else{
		return 0;
	}
}

//byte数据类型比较
int compareByte(const void*vx, const void*vy){
	byte *x = (byte*)vx;
	byte *y = (byte*)vy;

	if (*x > *y){
		return 1;
	}
	else if (*x < *y){
		return -1;
	}
	else{
		return 0;
	}
}

//short数据类型比较
int compareShort(const void*vx, const void*vy){
	short *x = (short*)vx;
	short *y = (short*)vy;

	if (*x > *y){
		return 1;
	}
	else if (*x < *y){
		return -1;
	}
	else{
		return 0;
	}
}

//int类型数据比较
int compareInt(const void*vx,const void*vy){
	int *x = (int*)vx;
	int *y = (int*)vy;

	//vx,vy代表任意两个元素的地址，*x，*y，任何两个元素
	if (*x > *y){
		return 1;
	}
	else if (*x < *y){
		return -1;
	}
	else{
		return 0;
	}
	
}

//double数据类型比较
int compareDouble(const void*vx, const void*vy){
	double *x = (double*)vx;
	double *y = (double*)vy;

	if (*x > *y){
		return 1;
	}
	else if (*x<*y){
		return -1;
	}
	else{
		return 0;
	}
}
/*模仿qsort的功能实现一个通用的冒泡排序*/
void myBubbleSort(void* base, int num, int size, int(*compare)(const void*, const void*)){
	//防止野指针
	assert(base);
	assert(compare);
	char* p = (char*)base;	//用char* p来接受
	for (int i = 0; i < num - 1; i++){
		int count = 0;	//如果一次循环后，一次交换都没有，说明数组元素，有序，直接break

		for (int j = 0; j < num -1- i; j++){
			/*
			result=1	//表示array[j]>array[j+1}，就需要交换
			result=0	//表示array[j]=array[j+1}，不需要交换，直接continue
			result=-1	//表示array[j]<array[j+1},也不需要交换，直接continue
			*/
			int result = (*compare)((p + size*j), (p + size*(j + 1)));	//回调函数
			if (1==result){
				swap((p + size*j), (p + size*(j + 1)),size);	//两个数字交换，因为不知道什么类型，所有需要size
				count++;
			}
			else if (-1 == result){
				continue;	
			}
			else{
				continue;
			}
		}

		if (count == 0){
			break;
		}
	}

}

//实现交换
void swap(char* px, char* py, int size){
	
	for (int i = 0; i < size; i++){
		*px^= *py;
		*py^= *px;
		*px^= *py;
		px++;
		py++;
	}
}