#include "test.h"

/*������A��������B ����С��������ָ �ܱ�A��B��������С��������ֵ�����һ���㷨��������A��B����С��������*/
/*������
	A��������������С����������ô��С�Ĺ�������һ�����������д����һ��
	B��������Ŀ������ҳ��������д����һ������һ��whileѭ����һֱ������ֱ�����ҵ��ܱ�A��B���������Ǹ���
*/
int leastCommonMultiple(int a, int b){
	if (a == 0 || b == 0){
		return;
	}
	int max = a > b ? a : b;
	
	
	while (1){
		if (max%a == 0 && max%b == 0){
			return max;
		}
		else{
			max++;
		}
	}
}

/*�������ַ�������һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing. �����������Ϊ��beijing. like I ����������*/
//���Ѿ����ַ�����������
void convertString(char* start,char* end){
	while (start <= end){
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}

//����ÿ������
//.gnijieb ekil I
void convertWord(char* start){
	char* head = start;
	char* tail = start;
	
	while (*tail != ' '){
		tail++;
	}
	convertString(head, tail - 1);

	head = tail + 1;
	while (*head != ' '){
		head++;
	}
	convertString(tail+1, head - 1);

	tail = head + 1;
	while (*tail != '\0'){
		tail++;
	}
	convertString(head + 1, tail - 1);
}
//����ÿ������
//.gnijieb ekil I
void convertWord2(char* start,int len){
	//Ŀǰ��������ָ��.
	char* head = start-1;	
	char* tail = start;

	//�������ָ������һ��ָ����'\0'�����Ǹ�����ô���˳�
	while (head != start + len&&tail != start + len){
		while (*tail != ' '&&*tail!='\0'){
			tail++;
		}
		//ѭ���˳���headָ���˵��ʵ���ߣ�tail��ָ���˵��ʵ��ұ�
		convertString(head + 1, tail - 1);	//����һ�����ַ������򣬴�head+1����tail-1֮�䣬����
		
		//��ָ�򵥴ʵ�ͷָ�룬ָ�� ��
		head = tail;
		//ָ�򵥴ʵ�βָ�룬��ǰ��һ��
		tail++;
	}
}
	
