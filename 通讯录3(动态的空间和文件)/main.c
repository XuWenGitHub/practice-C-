#include"addressList.h"
/*
��һ��д���˿��Թ�1000���˴洢��ͨѶ¼����Ϊ��̬�������ռ�
����������һ��ȫ�ֱ���spaceSize�����ڳ�ʼֵΪ10��Ȼ����main�������ʼ��p.num��ʼ������10**sizeof(Person)���ֽڴ�С�Ŀռ�
�����ϵ��ʱ�����count==spaceSize����ô�����10���ռ䣬
ɾ����ϵ�˺����count==(spaceSize-10)��˵�������ڶ���10���ռ䣬��ô����10���ռ䣬
���������ϵʱ��������ѡ������գ���պ��ְѿռ��Ϊ��ʼ��10����С
*/
/*
ʵ��һ��ͨѶ¼��
ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ�������������Ա����䡢�绰��סַ
�ṩ������
�����ϵ����Ϣ
ɾ��ָ����ϵ����Ϣ
����ָ����ϵ����Ϣ
�޸�ָ����ϵ����Ϣ
��ʾ������ϵ����Ϣ
���������ϵ��
����������������ϵ��
*/
/*
˼·��
A���ȶ���һ��Person�ṹ�����ͣ�������ÿ���˵���Ϣ���ٶ���һ��list�ṹ�����ͣ�����ͨѶ¼���ͣ��������num�ṹ�����飬װ��ͨѶ¼ÿ���ˣ�����count����ʾͨѶ¼�������
B��Ҫ����һ��ȫ�ֱ����������������ͨѶ¼��list p
C: ��ɾ�Ĳ飬��ʾ����գ���������ʵ����list* p�����ܣ�ʵ�δ�p�ĵ�ַ����Ϊ�ṹ��̫�󣬽ṹ�崫��ÿ�β�������ά��ֵ���������д���ַ����ָ�����
D�����ӣ����ж�ͨѶ¼�Ƿ�Ϊ����¼������������Ϣ��Ȼ��浽ͨѶ�p->num[p->count].����...	�����һ��Ҫ�ǵã�p->count++;
��ע�ͣ�����дһ��find������ͨ�����֣���ͨѶ¼���Ӧ�����±꣬����ҵ��ͷ��ض�Ӧ�����±꣬����Ҳ����ͷ���-1��
E��ɾ�����ж�ͨѶ���Ƿ�Ϊ�գ����������������Ȼ��ͨ��find�������ж��ҵ�û�У�����ҵ��ˣ��Ͱ�num�����ص��±�+1---count��֮���Ԫ����ǰ�ƣ������ˣ�ɾ����Ԫ��
F���ģ���find�������ҵ��ˣ����������ѡ���ʲô���ԣ�Ȼ��һ�ľ�OK������ܼ�
G���飺���ж�ͨѶ¼�Ƿ�Ϊ�գ����������������Ȼ��find����������ҵ��ˣ���ӡ�±�Ԫ�أ�
H����ʾ����0��count���������δ������
J����գ�ֱ����count=0�����ɣ���ʹ�������滹�������ݣ����Ǳ��˿�����
K��������qsort�������ɣ�����ͨѶ¼���飬����count����С sizeof(p->num[0]),�Լ��ٸ��ݹ���дһ��cmp����ʾ��cmp����ֱ����strcmp���Ϳ����жϴ�С
*/

list p;	//ͨѶ¼
//��ʼ��̬���ٵĴ�С,
//�����ϵ��ʱ�����count==spaceSize����ô�����10���ռ䣬
//ɾ����ϵ��ʱ�����count==(spaceSize-10)����ô����10���ռ䣬
//���������ϵʱ��������ѡ������գ���պ��ְѿռ��Ϊ��ʼ��10����С
int spaceSize = 10;
void menu(){
	printf("#####################################\n");
	printf("############0.�˳�ͨѶ¼ ############\n");
	printf("############1.�����ϵ����Ϣ ########\n");
	printf("############2.ɾ��ָ����ϵ����Ϣ ####\n");
	printf("############3.����ָ����ϵ����Ϣ ####\n");
	printf("############4.�޸�ָ����ϵ����Ϣ ####\n");
	printf("############5.��ʾ������ϵ����Ϣ ####\n");
	printf("############6.���������ϵ�� ########\n");
	printf("############7.����������������ϵ�� ##\n");
	printf("#####################################\n");
}
int main(){
	p.count = 0;	//��count��ʼ��Ϊ0
	p.num = (Person*)malloc(spaceSize*sizeof(Person));	//�ȸ�p��numһ��person�ṹ��Ĵ�С,�����Ҫ�����ϵ�ˣ����p.num��realloc�������ı䶯̬�����ڴ��СΪ(count+1)

	if (p.num == NULL){
		printf("malloc ERROR!\n");
		return -1;
	}
	int load_FILE_Flag = 1;
	printf("��ѡ���Ƿ��ȡ��һ�δ�����ϵ�˵��ļ���\n");	//���û���ļ���Ҫ�Լ�����Ŀ·���´���������ѡ��0����һ�ι����Զ������ļ�
	printf("####### 1.yes           0.no #######\n");
	scanf("%d", &load_FILE_Flag);
	if (load_FILE_Flag){
		//��Ҫ��ȡ�ļ����ж��ٸ�/n��Ȼ�����6�����>=10��
		//��zeroCount/=6��Ȼ������%10==0���������0����zeroCount++��
		//����ٰ�spaceSize=zeroCount��Ȼ���ٸ�p���ٸ���Ŀռ�
		FILE* fp = fopen("messege.txt", "r");
		int zeroCount = 0;	//���з�������
		char ch;
		while ((ch=fgetc(fp)) != -1){
			if (ch == '\n'){
				zeroCount += 1;
			}
		}
		if ((zeroCount = zeroCount / 6) >= 10){
			//����zeroCount��֪���ļ�����˼���Person�����ˣ�Ȼ��������%10==0
			while ((zeroCount % 10) != 0){
				zeroCount += 1;
			}
			spaceSize =zeroCount;
			//���ڿ��ٿռ�
			Person* temp = (Person*)realloc(p.num, spaceSize*sizeof(Person));
			if (temp == NULL){
				printf("numû�иı��ڴ��С�ɹ�\n");
				return;
			}
			p.num = temp == NULL ? p.num : temp;
		}
		fclose(fp);
		load_File("messege.txt", &p);
	}
	int flag = 1;
	int choose = -1;
	while (flag){
		menu();
		printf("��ѡ��=>");
		scanf("%d", &choose);
		switch (choose){
		case 0:
			flag = 0;
			break;
		case 1:
			if (spaceSize == p.count){
				//��count��spaceSize��ȣ���ô��spaceSize+=10,�ı�num���ڴ涯̬��С
				spaceSize += 10;
				Person* temp = (Person*)realloc(p.num, spaceSize*sizeof(Person));
				if (temp == NULL){
					printf("numû�иı��ڴ��С�ɹ�\n");
					return;
				}
				p.num = temp == NULL ? p.num : temp;
			}
			add(&p);
			//printf("����num�Ķ�̬���ٵĴ�С��%d\n", sizeof(p.num));
			break;
		case 2:
			del(&p);
			//ɾ���������ְ�num�Ķ�̬���ٵ��ڴ��С��������
			if (p.count == (spaceSize - 10)){
				spaceSize -= 10;
				Person* temp = (Person*)realloc(p.num, spaceSize*sizeof(Person));
				if (temp == NULL){
					printf("numû�иı��ڴ��С�ɹ�\n");
				}
				p.num = temp == NULL ? p.num : temp;
			}
			//printf("����num�Ķ�̬���ٵĴ�С��%d\n", sizeof(p.num));
			break;
		case 3:
			//printf("����count��%d\n", p.count);
			findName(&p);
			break;
		case 4:
			update(&p);
			break;
		case 5:
			show(&p);
			break;
		case 6:
			if (delAll(&p)){
				//ɾ���������ְ�num�Ķ�̬���ٵ��ڴ��С��������
				spaceSize = 10;
				Person* temp = (Person*)realloc(p.num, spaceSize*sizeof(Person));
				if (temp == NULL){
					printf("numû�иı��ڴ��С�ɹ�\n");
					return;
				}
				p.num = temp == NULL ? p.num : temp;
			}
			break;
		case 7:
			sortName(&p);
			break;
		default:
			printf("������������������!!!\n");
			break;
		}
	}
	printf("�ټ�\n");
	save_File("messege.txt", &p);
	free(p.num);
	system("pause");
	return 0;
}