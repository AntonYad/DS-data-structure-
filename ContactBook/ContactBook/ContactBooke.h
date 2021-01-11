#pragma once
#include <stdio.h>
#include <string.h>
#include <assert.h>
#define NAME_MAX 20
#define TEL_MAX 20
#define ADDR_MAX 100
#define CTARRAY_MAX 500
typedef struct Contact
{
	char name[NAME_MAX];
	short age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}Contact;
typedef struct ContactBook
{
	Contact contactArray[CTARRAY_MAX];
	int size;
}ContactBook;
void ContactInit(ContactBook* pcb);
void ContactAdd(ContactBook* pcb, Contact ct);
void ContactDel(ContactBook* pcb, const char* name);
Contact* ContactSearch(ContactBook* pcb, const char* name);
void ContactUpdateTel(ContactBook* pcb, char* name, char* tel);
void ContactUpdateAge(ContactBook* pcb, char* name, short age);
void ContactUpdateAddr(ContactBook* pcb, char* name, char* addr);
void ContactBookPrint(ContactBook* pcb);
void Sort_contact(ContactBook* pcb);