#include"addressList.h"
/*
把一个写好了可以供1000个人存储的通讯录，改为动态的增长空间
分析：定义一个全局变量spaceSize给它在初始值为10，然后在main函数里，开始给p.num初始化开辟10**sizeof(Person)个字节大小的空间
	  添加联系人时，如果count==spaceSize，那么再添加10个空间，
      删除联系人后，如果count==(spaceSize-10)，说明，现在多了10个空间，那么减少10个空间，
      清空所有联系时，如果玩家选择了清空，清空后，又把空间变为初始的10个大小
*/
/*
实现一个通讯录；
通讯录可以用来存储1000个人的信息，每个人的信息包括：姓名、性别、年龄、电话、住址
提供方法：
添加联系人信息
删除指定联系人信息
查找指定联系人信息
修改指定联系人信息
显示所有联系人信息
清空所有联系人
以名字排序所有联系人
*/
/*
思路：
A：先定义一个Person结构体类型，里面是每个人的信息，再定义一个list结构体类型，代表通讯录类型，里面变量num结构体数组，装的通讯录每个人，变量count，表示通讯录里的人数
B：要定义一个全局变量，这个变量就是通讯录：list p
C: 增删改查，显示，清空，排序，我们实参用list* p来接受，实参传p的地址，因为结构体太大，结构体传参每次不发生降维，值拷贝，所有传地址，用指针接受
D：增加：先判断通讯录是否为满，录好玩家输入的信息，然后存到通讯里，p->num[p->count].姓名...	，最后一定要记得，p->count++;
（注释：我们写一个find方法，通过名字，找通讯录里对应名字下标，如果找到就返回对应名字下标，如果找不到就返回-1）
E：删：先判断通讯里是否为空，让玩家输入姓名，然后通过find方法，判断找到没有，如果找到了，就把num（返回的下标+1---count）之间的元素往前移，覆盖了，删除的元素
F：改：用find方法，找到了，就再让玩家选择改什么属性，然后一改就OK，这个很简单
G：查：先判断通讯录是否为空，让玩家输入姓名，然后find方法，如果找到了，打印下标元素，
H：显示：从0到count遍历，依次打出即可
J：清空：直接让count=0；即可，即使数组里面还是有数据，但是别人看不到
K：排序，用qsort方法即可，传入通讯录数组，个数count，大小 sizeof(p->num[0]),自己再根据规则写一下cmp，提示：cmp里面直接用strcmp，就可以判断大小
*/

list p;	//通讯录
//起始动态开辟的大小,
//添加联系人时，如果count==spaceSize，那么再添加10个空间，
//删除联系人时，如果count==(spaceSize-10)，那么减少10个空间，
//清空所有联系时，如果玩家选择了清空，清空后，又把空间变为初始的10个大小
int spaceSize = 10;	
void menu(){
	printf("#####################################\n");
	printf("############0.退出通讯录 ############\n");
	printf("############1.添加联系人信息 ########\n");
	printf("############2.删除指定联系人信息 ####\n");
	printf("############3.查找指定联系人信息 ####\n");
	printf("############4.修改指定联系人信息 ####\n");
	printf("############5.显示所有联系人信息 ####\n");
	printf("############6.清空所有联系人 ########\n");
	printf("############7.以名字排序所有联系人 ##\n");
	printf("#####################################\n");
}
int main(){
	p.count = 0;	//给count初始化为0
	p.num = (Person*)malloc(spaceSize*sizeof(Person));	//先给p的num一个person结构体的大小,如果需要添加联系人，便把p.num用realloc函数，改变动态开辟内存大小为(count+1)

	if (p.num == NULL){
		printf("malloc ERROR!\n");
		return -1;
	}
	int flag = 1;
	int choose = -1;
	while (flag){
		menu();
		printf("请选择=>");
		scanf("%d", &choose);
		switch (choose){
		case 0:
			flag = 0;
			break;
		case 1:
			if (spaceSize == p.count){
				//当count和spaceSize相等，那么把spaceSize+=10,改变num的内存动态大小
				spaceSize += 10;
				Person* temp = (Person*)realloc(p.num, spaceSize*sizeof(Person));
				if (temp == NULL){
					printf("num没有改变内存大小成功\n");
					return;
				}
				p.num = temp == NULL ? p.num : temp;
			}
			add(&p);
			//printf("现在num的动态开辟的大小：%d\n", sizeof(p.num));
			break;
		case 2:
			del(&p);
			//删除结束后，又把num的动态开辟的内存大小重新设置
			if (p.count == (spaceSize - 10)){
				spaceSize -= 10;
				Person* temp = (Person*)realloc(p.num, spaceSize*sizeof(Person));
				if (temp == NULL){
					printf("num没有改变内存大小成功\n");
				}
				p.num = temp == NULL ? p.num : temp;
			}
			//printf("现在num的动态开辟的大小：%d\n", sizeof(p.num));
			break;
		case 3:
			//printf("现在count：%d\n", p.count);
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
				//删除结束后，又把num的动态开辟的内存大小重新设置
				spaceSize = 10;
				Person* temp = (Person*)realloc(p.num, spaceSize*sizeof(Person));
				if (temp == NULL){
					printf("num没有改变内存大小成功\n");
					return;
				}
				p.num = temp == NULL ? p.num : temp;
			}
			break;
		case 7:
			sortName(&p);
			break;
		default:
			printf("输入有误，请重新输入!!!\n");
			break;
		}
	}
	printf("再见\n");
	free(p.num);
	system("pause");
	return 0;
}