#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define N 8
#include "D:\2020_code\顺序表的增删查改\顺序表的增删查改\type.h"
#include "D:\2020_code\顺序表的增删查改\顺序表的增删查改\link.h"

void DelKeyNode(ElemSN *, int);
void InsertKeyNode(ElemSN *, int);
int main(void)
{
	int a[N] = { 3, 5, 7, 9, 11, 13, 15, 17 }, key;
	ElemSN * head;
	//创建带表头的BALA
	head = CreateLink(a);
	PrintLink(head);
	//查找删除
	//printf("关键字:");
	//scanf("%d",&key);
	//DelKeyNode(head,key);
	//PrintLink(head);
	//查找插入
	printf("关键字:");
	scanf("%d", &key);
	InsertKeyNode(head, key);
	PrintLink(head);
	return 0;
}

void DelKeyNode(ElemSN * h, int key)
{
	ElemSN * q, *p;
	for (q = h; q->next &&q->next->data - key; q = q->next);
	if (!q->next){
		printf("Not Found!\n");
	}
	else{
		p = q->next;
		q->next = p->next;
		free(p);
		p = NULL;
	}
}

void InsertKeyNode(ElemSN * h, int key)
{
	ElemSN * Ins, *q;
	Ins = (ElemSN *)malloc(sizeof(ElemSN));
	Ins->data = key;
	for (q = h; q->next && q->next->data <key; q = q->next);
	Ins->next = q->next;
	q->next = Ins;
}

