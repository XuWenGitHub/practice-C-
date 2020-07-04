#include"addressList.h"
// 添加一个函数，在通讯录打开的时候，可以把文件中的信息加载到通讯录中
void load_File(const char* fileName, list* p){
	
	FILE* fp = fopen(fileName, "r");
	if (fp == NULL){
		printf("FILE LOAD ERREO!!\n");
		return;
	}

	//定义一个count，表示遇到的第几个\n
	//一次读取一个字符,然后保存到一个字符数组里，
	//如果读到字符为\n，如果count%6==1，就把字符串放入，name里面
	//如果读到字符为\n，如果count%6==0,那么就把p指向的count++
	char c;
	int count = 0;
	char str[50] = { '\0' };
	int i = 0;	//str下标

	while ((c = fgetc(fp)) != -1){
		if (c != '\n'){
			str[i] = c;
			i++;
		}
		else{
			str[i] = '\0';	//就算遇到/0,也要添加到str，不然录取姓名为徐文文，年龄就变成20文
			i++;
			count++;
			if (count % 6 == 1){
				strcpy(p->num[p->count].name, str);	//结构体变量的内容的修改，如果是字符串，必须用strcpy修改
				i = 0;	//清空
			}
			else if (count % 6 == 2){
				strcpy(p->num[p->count].age, str);
				i = 0;	//清空
			}
			else if (count % 6 == 3){
				strcpy(p->num[p->count].sex, str);
				i = 0;	//清空
			}
			else if (count % 6 == 4){
				strcpy(p->num[p->count].phone, str);
				i = 0;	//清空
			}
			else if (count % 6 == 5){
				strcpy(p->num[p->count].address, str);
				i = 0;	//清空
			}
			else if (count % 6 == 0){
				p->count += 1;
				i = 0;	//清空
			}
			else{
				printf("load error!\n");
				return;
			}
		}
	}
	fclose(fp);
	printf("读取成功，欢迎光临(:\n");
}
//在退出通讯录的时候把信息到保存到文件中
void save_File(const char* fileName,list* p){
	FILE* fp = fopen(fileName, "w+");
	if (fp == NULL){
		printf("FILE OPEN ERREO!!\n");
		return;
	}
	//每个人通讯录人的每个属性都存一行，一个人存5行，再存个换行
	for (int i = 0; i < p->count; i++){
		fprintf(fp,"%s\n",p->num[i].name);	//存姓名
		fprintf(fp,"%s\n",p->num[i].age);	//存年龄
		fprintf(fp,"%s\n",p->num[i].sex);	//存性别
		fprintf(fp,"%s\n",p->num[i].phone);	//存电话
		fprintf(fp,"%s\n",p->num[i].address);	//存地址
		fprintf(fp, "\n");
		fflush(fp);
	}
	fclose(fp);
}

//查找人,输出信息
void findName(list *p){
	char findName[20] = { 0 };
	int i = 0;
	printf("请输入查找的联系人的姓名：\n");
	scanf("%s", findName);
	i = find(p, findName);
	if (i != -1){
		printf("姓名=%s 性别=%s 年龄=%s 电话=%s 地址=%s\n", p->num[i].name, p->num[i].sex, p->num[i].age, p->num[i].phone, p->num[i].address);
	}
	else if (i == 0){
		printf("bug\n");
	}
	else{
		printf("您查找的联系人，通讯录不存在\n");
	}
}
int cmp(const void* str, const void* str2){
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
int delAll(list *p){
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
		return result;
	}
	else{
		printf("删除失败\n");
		return result;
	}
}
//显示所有联系人信息
void show(list *p){
	if (p->count == 0){
		printf("通讯录为空\n");
		return;
	}
	for (int i = 0; i < p->count; i++){
		printf("姓名=%s 性别=%s 年龄=%s 电话=%s 地址=%s\n", p->num[i].name, p->num[i].sex, p->num[i].age, p->num[i].phone, p->num[i].address);
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
				scanf("%d", &(p->num[result].name));
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
	scanf("%s", &(p->num[p->count].age));
	printf("请输入您要添加联系人的电话:\n");
	scanf("%s", p->num[p->count].phone);
	printf("请输入您要添加联系人的地址:\n");
	scanf("%s", p->num[p->count].address);
	printf("添加成功\n");
	p->count++;
}