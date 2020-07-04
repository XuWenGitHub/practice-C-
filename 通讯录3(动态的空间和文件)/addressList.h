#ifndef _ADDRESSLIST_H_
#define _ADDRESSLIST_H_

#include<stdio.h>
#include<Windows.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#pragma once

typedef struct person{
	char name[20];
	char sex[10];
	char age[5];
	char phone[20];
	char address[50];
}Person;
typedef struct List{
	Person* num;	//通讯录		//本来是Person num[1000];
	int count;	//统计人员，从0开始
}list;
// 添加一个函数，在通讯录打开的时候，可以把文件中的信息加载到通讯录中
void load_File(const char* fileName, list* p);
//在退出通讯录的时候把信息到保存到文件中
void save_File(const char* fileName, list* p);
//添加联系人
void add(list *p);
//删除联系人
void del(list *p);
//查找联系人，找到后返回在数组里的下标
int find(list *p, char* name);
//修改联系人
void update(list *p);
//显示所有联系人信息
void show(list *p);
//删除所有联系人
int delAll(list *p);
//查找人,输出信息
void findName(list *p);
//以名字排序所有联系人
void sortName(list *p);
int cmp(const void* str, const void* str2);
#endif