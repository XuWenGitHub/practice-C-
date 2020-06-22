#include"test.h"

/*һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
��дһ�������ҳ�������ֻ����һ�ε����֡�*/
void findSingleDog(int **singleDog,int arr[], int len){		//��һ��������������int����ָ��ĵ�ַ���ڶ����������飬��������������Ԫ�ظ���

	//��������singleDogָ���int���͵�ָ��p��̬����λ�ã������������,�����������棬���꣬һ���ǵ�free(p)
	*singleDog = (int*)malloc(2 * sizeof(int));
	//�ж϶�̬�����ڴ棬�Ƿ�ɹ�
	if (*singleDog == NULL){
		printf("mallocERROR\n");
	}
	
	int count = 0;	//����������±�
	int flag = 0;	//��ʾû�г��ֹ������i��j����ȵ�����£�arr[i],arr[j]��ȣ�flag���1
	for (int i = 0; i < len; i++){
		int temp = arr[i];	//һ��һ����
		for (int j = 0; j < len; j++){
			if (j != i&&arr[j] == temp){
				flag = 1;
				break;	//flag���1����ô˵��temp���ǵ������Ϳ���ȥ�ж���һ��temp��
			}
		}
		if (!flag){
			//���flag����0����ô˵����flagû�б��1��˵����temp�ǵ������Ϳ��Դ���singleDog[2]������
			(*singleDog)[count] = temp;
			count++;
		}
		else{
			//���temp���ǵ�������ô����flagΪ0���ж���һ��temp
			flag = 0;
		}
	}
	
	
}

//ģ��ʵ��strncpy	��src����num���ֽڸ��Ƶ�dest���棬��󲻻����'\0'
char* myStrcpy(char* dest, const char* src, size_t num){
	assert(dest);
	assert(src);
	char* p = dest;	//����dest���׵�ַ
	for (int i = 0; i < num; i++){
		*dest = *src;
		dest++;
		src++;
	}
	return p;
}

//ģ��ʵ��strncat	��src����num���ֽ�ƴ�ӵ�dest���棬�������'\0'
char* myStrncat(char* dest, const char* src, size_t num){
	assert(dest);
	assert(src);
	char* p = dest;	//�������dest�ַ������׵�ַ����󷵻���
	//���ҵ�dest��'\0'��
	while (*dest){
		dest++;
	}
	//����destָ���Լ�'\0'����Ȼ���src��num���ֽ�ƴ�ӵ�dest���棬����ٲ���һ��'\0'
	for (int i = 0; i < num; i++){
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return p;
}




//��һ���ַ���ת��һ��int���͵�����������'\0'���߲��������ַ�����������ַ����е�һ�������������ַ�����ôֱ�ӷ���0
int myAtoi(char* str){
	assert(str);
	int result = 0;	//����������ʼֵΪ0������ַ�����һ�������������ַ�����ô��ֱ�ӷ���0
	int len = 0;	//������ַ����дӵ�һ���ַ���ʼ�ж��Ƿ��������ַ��������������ַ��ĳ���,Ȼ���ٴ��ַ�����ȡ��һ���ַ����֣���֪���ó��Լ���10�ˣ����磺len=3��ȡ����һ�����ͳˣ�len-1����10����len=0���Ͳ���
	char* cur = str;	//����string�����len
	while (*cur >= '0'&&*cur <= '9'){
		len++;
		cur++;
	}
	
	while (*str >= '0'&&*str <= '9'){
		int temp = (int)(*str - 48);	//ȡ����������ת�ɶ�Ӧ��int������
		if (len != 1){
			//����������һ��������Ҫ��ȡ������������10��(len-1)�η�
			temp = temp*pow(10, (len - 1));
		}
		result += temp;
		//����len��str
		len--;
		str++;
	}
	return result;
}
