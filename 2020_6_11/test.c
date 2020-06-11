#include"test.h"

/*
ģ��ʵ��memcpy
��char* ָ��ǿת��dest��src����Ϊchar������һ�ֽ�
*/
void* myMemcpy(void* dest, const void* src, size_t size){
	assert(dest);
	assert(src);
	char* dst = (char*)dest;
	char* sc = (char*)src;
	for (int i = 0; i < size; i++){
		*dst = *sc;
		dst++;
		sc++;
	}
}

/*
ģ��ʵ��strstr
������
��������ָ�룺startָ����������str1�к�str2�ַ���һ�����ַ������׵�ַ
				endָ������ɨ��str1
				pָ������ɨ��str2
A��endȥɨ��str1����str1��Ѱ�Һ�str2��һ���ַ���ͬ���ַ�λ�ã��ҵ�λ�ã���startҲȥָ���λ�ã�Ȼ��break
B��Ȼ���ж��Ƿ���str1���ҵ���λ��
		�ҵ�����startҲȥָ���λ�ã�Ȼ��break��Ȼ����ȥ��pɨ��str2������λ�ú����ַ���str2һ����
															һ����return start��
															��һ��������p����ָ��str2��һ���ַ�����endָ��start����һ��
		û���ҵ���break������null��˵��str1��û��str2��
*/

char* myStrstr(const char* str1, const char* str2){
	assert(str1);
	assert(str2);
	char* start = str1;	//������str2�ַ���һ�����׵�ַ
	char* end = str1;	//����ɨ��str1
	char* p = str2;	//����ɨ��str2

	
	while (1){
		//end���ɨ�裬�ҵ���һ����str2�е�һ���ַ�һ����
		while (*end){
			if (*end == *p){
				start = end;	//��startҲ�Ƶ���ͬ�ط�
				break;
			}
			end++;
		}
		//���end�����ɨ�裬����str1ɨ�����ˣ���û�ҵ��Ļ�����ô���˳�����󷵻�null
		if (*end == '\0'){
			break;
		}else{
			//�ж�endλ����������ַ����Ƿ��str2��ͬ
			while (*p){
				if (*p == *end){
					p++;
					end++;
				}
				else{
					break;
				}
			}
			//�������ѭ���˳���p�ǵ�'\0'�˳�����ô��ʾ�ҵ���
			if (!(*p)){
				return start;
			}
			else{
				//���p����'\0'����ô��p��ˢ��һ��,endҲָ��start����һ��
				p = str2;
				end = start + 1;
			}
		}
	}
	return NULL;
}