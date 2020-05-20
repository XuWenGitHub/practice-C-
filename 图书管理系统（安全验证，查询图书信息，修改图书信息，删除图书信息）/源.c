#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define Pquantity 3
#define MAX 1000
#define N 5
int k = 0;
/*结构体类型*/
typedef struct
{
	int num;/*编号*/
	char name[20];/*书名*/
	char author[20];/*作者*/
	char press[20];/*出版社*/
	float price;/*价格*/
	int quantity;/*数量*/


}STUDENTS;

int read_file(STUDENTS stu[])//读取文件//
{
	FILE *fp;//FILE 是变量类型，实际上是C语言定义的标准数据结构，用于文件。FILE *fp 是声明，声明fp是指针，用来指向FILE类型的对象。
	int i = 0;
	if ((fp = fopen("stu.txt", "rt")) == NULL)//"r" = "rt" 打开一个文本文件，文件必须存在，只允许读打开一个文本文件，文件必须存在，只允许读
	{
		printf("\n\n—————库存文件不存在！请创");
		return 0;
	}
	while (feof(fp) != 1)/*feof是个函数,用来测试是否到文件的结尾*/
	{
		fread(&stu[i], sizeof(STUDENTS), 1, fp); /*读取成功时：当读取的数据量正好是sizeof(STUDENTS)个Byte时，返回值为1(即count)
			否则返回值为0(读取数据量小于sizeof(buf))*/
		if (stu[i].num == 0)
			break;
		else
			i++;
	}
	fclose(fp);/*前面曾把打开文件（用fopen函数）时函数返回的指针赋给了fp，现在把fp指向的文件夹关闭，此后fp不再指向该文件夹*/
	return i;
}

void save_file(STUDENTS stu[], int sum)//保存文件//
{
	FILE*fp;
	int i;
	if ((fp = fopen("stu.txt", "wb")) == NULL)//"wb" 新建一个二进制文件，已存在的文件将被删除，只允许写
	{
		printf("写文件错误!\n");
		return;
	}
	for (i = 0; i<sum; i++)
	if (fwrite(&stu[i], sizeof(STUDENTS), 1, fp) != 1)//fwrite()  C语言函数，向文件写入一个数据块
		printf("写文件错误!\n");
	fclose(fp);
}


/*创建图书信息*/
int input(STUDENTS stu[])
{
	int i, x;
	for (i = 0; i<1000; i++)
	{
		system("cls");/*system()函数是调用dos命令.
		而cls是dos命令中的清屏命令(clear screen的简写).
			合起来就是清屏.*/
		printf("\n\n                 录入图书信息  (最多%d本)\n", MAX);
		printf("               ----------------------------\n");

		printf("\n                     第%d本图书", k + 1);
		printf("\n 请输入图书的编号:");
		scanf("%d", &stu[k].num);
		printf("\n 请输入图书的书名:");
		scanf("%s", stu[k].name);
		printf("\n 请输入图书的作者:");
		scanf("%s", stu[k].author);
		printf("\n 请输入图书的出版社:");
		scanf("%s", stu[k].press);
		printf("\n 请输入图书的价格:");
		scanf("%f", &stu[k++].price);
		printf("\n 请输入图书的数量:");
		scanf("%d", &stu[i].quantity);
		printf("\n 请按1键返回菜单或按0键继续创建");
		scanf("%d", &x);
		if (x)
			break;
	}

	return k;
}


/*删除图书信息*/
void deletel(STUDENTS stu[])
{
	system("cls");
	char Stuname2[20];
	int i, j;
	printf("请输入图书书名：");
	scanf("%s", Stuname2);
	printf("\n");
	for (i = 0; i<k; i++)
	if (strcmp(stu[i].name, Stuname2) == 0)
	for (j = 0; j<20; j++)
		stu[i].name[j] = stu[i + 1].name[j];
	k--;


	printf("删除成功\n");
	printf("按任意键加回车返回主菜单!");
	scanf("%d", &i);
	getchar();
}

/*打印图书信息*/
void output(STUDENTS stu[])
{
	system("cls");
	int i;
	for (i = 0; i<k; i++)
		printf("编号：%d,书名：%s,作者：%s,出版社：%s,价格: %.2f,数量：%d\n", stu[i].num, stu[i].name,
		stu[i].author, stu[i].press, stu[i].price, stu[i].quantity);
	printf("按任意键加回车返回主菜单!");
	scanf("%d", &i);
	getchar();
}

/*查询图书信息*/
void inquire(STUDENTS stu[])
{
	int i;
	char name[20];
	system("cls");
	printf("     \n\n请输入您要查找的图书的书名：");
	scanf("%s", &name);
	for (i = 0; i<k; i++)
	if (strcmp(name, stu[i].name) == 0)
		printf("\n\n\n编号：%d,书名：%s,作者：%s,出版社：%s,价格: %.2f,数量：%d\n", stu[i].num, stu[i].name,
		stu[i].author, stu[i].press, stu[i].price, stu[i].quantity);
	printf("按任意键加回车返回主菜单!");
	scanf("%d", &i);
	getchar();
}


/*修改图书信息*/
void change(STUDENTS stu[])
{
	int num, i, choice;
	system("cls");
	printf("\n\n\n      请输入您要修改的图书的编号");
	scanf("%d", &num);
	for (i = 0; i<k; i++)
	{
		if (num == stu[i].num)
			printf("\n编号：%d,书名：%s,作者：%s,出版社：%s,价格: %.2f,数量：%d\n", stu[i].num, stu[i].name,
			stu[i].author, stu[i].press, stu[i].price, stu[i].quantity);

		printf("\n\n\n     ********请输入您想要修改的数据********\n\n");
		printf("                1. 编号\n\n");
		printf("                2. 书名\n\n");
		printf("                3. 作者\n\n");
		printf("                4. 出版社\n\n");
		printf("                5. 价格\n\n");
		printf("                6. 数量\n\n");
		printf("                 请选择（1-6）:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:{
				   printf("\n   请输入你改的新编号");
				   scanf("%d", &stu[i].num);
				   break;
		}
		case 2:{
				   printf("\n   请输入你改的新书名");
				   scanf("%s", stu[i].name);
				   break;
		}
		case 3:{
				   printf("\n   请输入你改的新作者");
				   scanf("%s", stu[i].author);
				   break;
		}
		case 4:{
				   printf("\n   请输入你改的新出版社");
				   scanf("%s", stu[i].press);
				   break;
		}
		case 5:{
				   printf("\n   请输入你改的新价格");
				   scanf("%f", &stu[i].price);
				   break;
		case 6:{
				   printf("\n   请输入你改的新数量");
				   scanf("%d", &stu[i].quantity);
				   break;
		}
		}
		}

		printf("编号：%d,书名：%s,作者：%s,出版社：%s,价格: %.2f,数量：%d\n", stu[i].num, stu[i].name,
			stu[i].author, stu[i].press, stu[i].price, stu[i].quantity);
		printf("按任意键加回车返回主菜单!");
		scanf("%d", &i);
		break;
	}
}


/*图书价格信息排名*/
void sort(STUDENTS stu[])
{
	int i, j, n = 1, x;
	system("cls");
	int t;
	for (i = 0; i<k - 1; i++)
	for (j = i + 1; j<k; j++)
	if (stu[i].price<stu[j].price)
	{
		t = stu[i].price;
		stu[i].price = stu[j].price;
		stu[j].price = t;
		t = stu[i].num;
		stu[i].num = stu[j].num;
		stu[j].num = t;

	}
	for (i = 0; i<k; i++)
		printf("排名    编号    价格\n %d       %d       %.2f\n", n++, stu[i].num, stu[i].price);
	printf("按任意键加回车返回主菜单!");
	scanf("%d", &x);
	getchar();
}


/*图书管理系统界面*/
void pquantitydis()
{
	printf(" \n\n\n                   **********************************\n");
	printf("                   *                                *\n");
	printf("                   *                                *\n");
	printf("                   *                                *\n");
	printf("                   *     欢迎进入图书信息管理系统   *\n");
	printf("                   *                                *\n");
	printf("                   *                                *\n");
	printf("                   *                                *\n");
	printf("                   **********************************\n");

}


/*用户验证*/
void check()
{
	char userName[5];/*用户名*/
	char userPWD[5];/*密码*/
	int i, sum;
	system("color 0B");//颜色代码 1蓝色 2绿色 1为第一个背景，2为第二个前景
	for (i = 1; i < 4; i++)
	{
		/*用户名和密码均为abcde;*/
		printf("                         (用户名和密码均为abcde)\n\n");
		printf("\n       请输入您的用户名:");
		gets(userName);

		printf("\n       请输入您的密码:");
		gets(userPWD);

		if ((strcmp(userName, "abcde") == 0) && (strcmp(userPWD, "abcde") == 0))/*验证用户名和密码*/
		{
			printf("\n                      *用户名和密码正确，显示主菜单*");
			return;
		}
		else
		{
			if (i < 3)
			{
				printf("用户名或密码错误，提示用户重新输入");
				printf("用户名或密码错误，请重新输入!");
			}
			else
			{
				printf("连续3次输错用户名或密码，退出系统。");
				printf("您已连续3次将用户名或密码输错，系统将退出!");
				exit(1);/*便于程序员找出错误地方*/
			}
		}
	}

}


/*菜单*/
void menu()
{
	STUDENTS stu[20];
	int choice, k, sum;
	sum = read_file(stu);
	if (sum == 0)
	{
		printf("首先录入基本库存信息！按回车后进入—————\n");
		getch();/*c++中从控制台读取一个字符，但不显示在屏幕上*/
		sum = input(stu);
	}

	do
	{
		system("cls");
		printf("\n\n\n               ********图书信息管理系统********\n\n");
		printf("                      1. 创建图书信息\n\n");
		printf("                      2. 打印图书信息\n\n");
		printf("                      3. 查询图书信息\n\n");
		printf("                      4. 修改图书信息\n\n");
		printf("                      5. 删除图书信息\n\n");
		printf("                      6. 图书价格信息排名\n\n");
		printf("                      0. 退出系统\n\n");
		printf("                       请选择（0-6）:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1: k = input(stu); break;/*创建图书信息*/
		case 2: output(stu); break;/*打印图书信息*/
		case 3: inquire(stu); break;/*查询图书信息*/
		case 4: change(stu); break;/*修改图书信息*/
		case 5: deletel(stu); break;/*删除图书信息*/
		case 6: sort(stu); break;/*图书价格信息排名*/
		case 0: break;
		}
	} while (choice != 0);
	save_file(stu, sum);
}


/*主函数*/
int main()
{
	int i, sum;
	pquantitydis();
	check();
	menu();
}