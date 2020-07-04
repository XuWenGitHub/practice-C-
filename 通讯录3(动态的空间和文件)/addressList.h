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
	Person* num;	//ͨѶ¼		//������Person num[1000];
	int count;	//ͳ����Ա����0��ʼ
}list;
// ���һ����������ͨѶ¼�򿪵�ʱ�򣬿��԰��ļ��е���Ϣ���ص�ͨѶ¼��
void load_File(const char* fileName, list* p);
//���˳�ͨѶ¼��ʱ�����Ϣ�����浽�ļ���
void save_File(const char* fileName, list* p);
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
int delAll(list *p);
//������,�����Ϣ
void findName(list *p);
//����������������ϵ��
void sortName(list *p);
int cmp(const void* str, const void* str2);
#endif