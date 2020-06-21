#include"addressList.h"
//查找人,输出信息
void findName(list *p){
	char findName[20] = { 0 };
	int i = 0;
	printf("请输入查找的联系人的姓名：\n");
	scanf("%s", findName);
	i = find(p, findName);
	if (i != -1){
		printf("姓名=%s 性别=%s 年龄=%d 电话=%s 地址=%s\n", p->num[i].name, p->num[i].sex, p->num[i].age, p->num[i].phone, p->num[i].address);
	}
	else if (i == 0){
		printf("bug\n");
	}
	else{
		printf("您查找的联系人，通讯录不存在\n");
	}
}
int cmp(const void* str,const void* str2){
	return strcmp((*(Person*)str).name, (*(Person*)str2).name);
}
//以名字排序所有联系人
void sortName(list *p){
	if (p->count == 0){
		printf("通讯录为空\n");
		return;
	}
	qsort(p->num, p->count, sizeof(p->num[0]), &cmp);
	printf("排序完成\n");
}
//删除所有联系人
void delAll(list *p){
	if (p->count == 0){
		printf("通讯录为空");
		return;
	}
	int result = -1;
	printf("您确定要删除所有联系人？\n");
	printf("删除请按1，不删除请按0\n");
	scanf("%d", &result);
	if (result){
		p->count = 0;
		printf("删除成功\n");
	}
	else{
		printf("删除失败\n");
	}
}
//显示所有联系人信息
void show(list *p){
	if (p->count == 0){
		printf("通讯录为空\n");
		return;
	}
	for (int i = 0; i < p->count; i++){
		printf("姓名=%s 性别=%s 年龄=%d 电话=%s 地址=%s\n", p->num[i].name, p->num[i].sex, p->num[i].age, p->num[i].phone, p->num[i].address);
	}
}
//修改联系人
void update(list *p){
	char name[20] = { 0 };
	printf("请输入与您要修的联系人的姓名\n");
	scanf("%s", name);
	int result = find(p, name);	//去查找需要修改的联系人，如果有返回1，如果没有找到返回-1
	int flag = 1;	//如果玩家修改完毕，变成0，控制循环
	if (result != -1){
		while (flag){
			int choose = -1;	//让玩家选择修改什么
			printf("#######选择修改的属性#######\n");
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
				printf("请输入准备修改的新名字：\n");
				scanf("%s", p->num[result].name);
				break;
			case 2:
				printf("请输入准备修改的新性别：\n");
				scanf("%s", p->num[result].name);
				break;
			case 3:
				printf("请输入准备修改的新年龄：\n");
				scanf("%d",&(p->num[result].name));
				break;
			case 4:
				printf("请输入准备修改的新手机号：\n");
				scanf("%s", p->num[result].name);
				break;
			case 5:
				printf("请输入准备修改的新住址：\n");
				scanf("%s", p->num[result].name);
				break;
			}
		}
		printf("修改成功\n");
	}
	else{
		printf("该联系人不存在，修改失败\n");
	}
}
//删除联系人
void del(list *p){
	char name[20] = { 0 };
	printf("请输入要删除人的姓名:\n");
	scanf("%s", name);
	int result = find(p, name);	//因为这里的p已经是list类型的指针，p里放的就是通讯录的地址
	int n = -1;
	if (result != -1){
		printf("您确定要删除该联系人？\n");
		printf("删除请按1，不删除请按0\n");
		scanf("%d", &n);
		if (n){
			//如果要删除该联系人，则把后面的人全部往前移
			for (int i = result; i < p->count; i++){
				p->num[i] = p->num[i + 1];
			}
			p->count--;
			printf("删除成功\n");
		}
		else{
			printf("删除失败\n");
		}
	}
	else{
		printf("您要删除的联系人不存在\n");
	}
}
//查找联系人，找到后返回在数组里的下标
int find(list *p, char* name){
	for (int i = 0; i < p->count; i++){
		if (strcmp(p->num[i].name, name) == 0){
			return i;	//如果名字相同，就返回数组的下标
		}
	}
	return -1;
}

//添加联系人
void add(list *p){
	//先判断是否通讯录满
	if (p->count == 1000){
		printf("通讯录已满，不能添加\n");
		return;
	}
	printf("请输入您要添加联系人的姓名:\n");
	scanf("%s", p->num[p->count].name);
	printf("请输入您要添加联系人的性别:\n");
	scanf("%s", p->num[p->count].sex);
	printf("请输入您要添加联系人的年龄:\n");
	scanf("%d", &(p->num[p->count].age));
	printf("请输入您要添加联系人的电话:\n");
	scanf("%s", p->num[p->count].phone);
	printf("请输入您要添加联系人的地址:\n");
	scanf("%s", p->num[p->count].address);
	printf("添加成功\n");
	p->count++;
}