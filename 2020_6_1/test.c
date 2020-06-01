#include"test.h"
//char�������ͱȽ�
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

//byte�������ͱȽ�
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

//short�������ͱȽ�
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

//int�������ݱȽ�
int compareInt(const void*vx,const void*vy){
	int *x = (int*)vx;
	int *y = (int*)vy;

	//vx,vy������������Ԫ�صĵ�ַ��*x��*y���κ�����Ԫ��
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

//double�������ͱȽ�
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
/*ģ��qsort�Ĺ���ʵ��һ��ͨ�õ�ð������*/
void myBubbleSort(void* base, int num, int size, int(*compare)(const void*, const void*)){
	//��ֹҰָ��
	assert(base);
	assert(compare);
	char* p = (char*)base;	//��char* p������
	for (int i = 0; i < num - 1; i++){
		int count = 0;	//���һ��ѭ����һ�ν�����û�У�˵������Ԫ�أ�����ֱ��break

		for (int j = 0; j < num -1- i; j++){
			/*
			result=1	//��ʾarray[j]>array[j+1}������Ҫ����
			result=0	//��ʾarray[j]=array[j+1}������Ҫ������ֱ��continue
			result=-1	//��ʾarray[j]<array[j+1},Ҳ����Ҫ������ֱ��continue
			*/
			int result = (*compare)((p + size*j), (p + size*(j + 1)));	//�ص�����
			if (1==result){
				swap((p + size*j), (p + size*(j + 1)),size);	//�������ֽ�������Ϊ��֪��ʲô���ͣ�������Ҫsize
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

//ʵ�ֽ���
void swap(char* px, char* py, int size){
	
	for (int i = 0; i < size; i++){
		*px^= *py;
		*py^= *px;
		*px^= *py;
		px++;
		py++;
	}
}