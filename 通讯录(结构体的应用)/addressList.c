#include"addressList.h"
//������,�����Ϣ
void findName(list *p){
	char findName[20] = { 0 };
	int i = 0;
	printf("��������ҵ���ϵ�˵�������\n");
	scanf("%s", findName);
	i = find(p, findName);
	if (i != -1){
		printf("����=%s �Ա�=%s ����=%d �绰=%s ��ַ=%s\n", p->num[i].name, p->num[i].sex, p->num[i].age, p->num[i].phone, p->num[i].address);
	}
	else if (i == 0){
		printf("bug\n");
	}
	else{
		printf("�����ҵ���ϵ�ˣ�ͨѶ¼������\n");
	}
}
int cmp(const void* str,const void* str2){
	return strcmp((*(Person*)str).name, (*(Person*)str2).name);
}
//����������������ϵ��
void sortName(list *p){
	if (p->count == 0){
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	qsort(p->num, p->count, sizeof(p->num[0]), &cmp);
	printf("�������\n");
}
//ɾ��������ϵ��
void delAll(list *p){
	if (p->count == 0){
		printf("ͨѶ¼Ϊ��");
		return;
	}
	int result = -1;
	printf("��ȷ��Ҫɾ��������ϵ�ˣ�\n");
	printf("ɾ���밴1����ɾ���밴0\n");
	scanf("%d", &result);
	if (result){
		p->count = 0;
		printf("ɾ���ɹ�\n");
	}
	else{
		printf("ɾ��ʧ��\n");
	}
}
//��ʾ������ϵ����Ϣ
void show(list *p){
	if (p->count == 0){
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	for (int i = 0; i < p->count; i++){
		printf("����=%s �Ա�=%s ����=%d �绰=%s ��ַ=%s\n", p->num[i].name, p->num[i].sex, p->num[i].age, p->num[i].phone, p->num[i].address);
	}
}
//�޸���ϵ��
void update(list *p){
	char name[20] = { 0 };
	printf("����������Ҫ�޵���ϵ�˵�����\n");
	scanf("%s", name);
	int result = find(p, name);	//ȥ������Ҫ�޸ĵ���ϵ�ˣ�����з���1�����û���ҵ�����-1
	int flag = 1;	//�������޸���ϣ����0������ѭ��
	if (result != -1){
		while (flag){
			int choose = -1;	//�����ѡ���޸�ʲô
			printf("#######ѡ���޸ĵ�����#######\n");
			printf("##########0.exit ###########\n");
			printf("##########1.name ###########\n");
			printf("##########2.sex ############\n");
			printf("##########3.age ############\n");
			printf("##########4.phone ##########\n");
			printf("##########5.address ########\n");
			scanf("%d", &choose);
			switch (choose){
			case 0:
				flag = 0;
				break;
			case 1:
				printf("������׼���޸ĵ������֣�\n");
				scanf("%s", p->num[result].name);
				break;
			case 2:
				printf("������׼���޸ĵ����Ա�\n");
				scanf("%s", p->num[result].name);
				break;
			case 3:
				printf("������׼���޸ĵ������䣺\n");
				scanf("%d",&(p->num[result].name));
				break;
			case 4:
				printf("������׼���޸ĵ����ֻ��ţ�\n");
				scanf("%s", p->num[result].name);
				break;
			case 5:
				printf("������׼���޸ĵ���סַ��\n");
				scanf("%s", p->num[result].name);
				break;
			}
		}
		printf("�޸ĳɹ�\n");
	}
	else{
		printf("����ϵ�˲����ڣ��޸�ʧ��\n");
	}
}
//ɾ����ϵ��
void del(list *p){
	char name[20] = { 0 };
	printf("������Ҫɾ���˵�����:\n");
	scanf("%s", name);
	int result = find(p, name);	//��Ϊ�����p�Ѿ���list���͵�ָ�룬p��ŵľ���ͨѶ¼�ĵ�ַ
	int n = -1;
	if (result != -1){
		printf("��ȷ��Ҫɾ������ϵ�ˣ�\n");
		printf("ɾ���밴1����ɾ���밴0\n");
		scanf("%d", &n);
		if (n){
			//���Ҫɾ������ϵ�ˣ���Ѻ������ȫ����ǰ��
			for (int i = result; i < p->count; i++){
				p->num[i] = p->num[i + 1];
			}
			p->count--;
			printf("ɾ���ɹ�\n");
		}
		else{
			printf("ɾ��ʧ��\n");
		}
	}
	else{
		printf("��Ҫɾ������ϵ�˲�����\n");
	}
}
//������ϵ�ˣ��ҵ��󷵻�����������±�
int find(list *p, char* name){
	for (int i = 0; i < p->count; i++){
		if (strcmp(p->num[i].name, name) == 0){
			return i;	//���������ͬ���ͷ���������±�
		}
	}
	return -1;
}

//�����ϵ��
void add(list *p){
	//���ж��Ƿ�ͨѶ¼��
	if (p->count == 1000){
		printf("ͨѶ¼�������������\n");
		return;
	}
	printf("��������Ҫ�����ϵ�˵�����:\n");
	scanf("%s", p->num[p->count].name);
	printf("��������Ҫ�����ϵ�˵��Ա�:\n");
	scanf("%s", p->num[p->count].sex);
	printf("��������Ҫ�����ϵ�˵�����:\n");
	scanf("%d", &(p->num[p->count].age));
	printf("��������Ҫ�����ϵ�˵ĵ绰:\n");
	scanf("%s", p->num[p->count].phone);
	printf("��������Ҫ�����ϵ�˵ĵ�ַ:\n");
	scanf("%s", p->num[p->count].address);
	printf("��ӳɹ�\n");
	p->count++;
}