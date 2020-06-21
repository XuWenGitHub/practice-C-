#ifndef _ADDRESSLIST_H_
#define _ADDRESSLIST_H_

#include<stdio.h>
#include<Windows.h>
#include<string.h>
#pragma warning(disable:4996)

typedef struct person{
	char name[20];
	char sex[10];
	int age;
	char phone[10];
	char address[50];
}Person;
typedef struct List{
	Person num[1000];	//ͨѶ¼
	int count;	//ͳ����Ա����-1��ʼ
}list;

//�����ϵ��
void add(list *p);
//ɾ����ϵ��
void del(list *p);
//������ϵ�ˣ��ҵ��󷵻�����������±�
int find(list *p, char* name);
//�޸���ϵ��
void update(list *p);
//��ʾ������ϵ����Ϣ
void show(list *p);
//ɾ��������ϵ��
void delAll(list *p);
//������,�����Ϣ
void findName(list *p);
//����������������ϵ��
void sortName(list *p);
int cmp(const void* str, const void* str2);
#endif