#include "ContactBooke.h"
void ContactInit(ContactBook* pcb)
{
	memset(pcb->contactArray, 0, sizeof(Contact)*CTARRAY_MAX);
	pcb->size = 0;
}

void ContactAdd(ContactBook* pcb, Contact ct)
{
	assert(pcb);
	strcpy(pcb->contactArray[pcb->size].name, ct.name);
	strcpy(pcb->contactArray[pcb->size].addr, ct.addr);
	strcpy(pcb->contactArray[pcb->size].tel, ct.tel);
	pcb->contactArray[pcb->size].age = ct.age;
	pcb->size++;
}

Contact* ContactSearch(ContactBook* pcb, const char* name)
{
	assert(pcb);

	for (int i = 0; i < pcb->size; ++i)
	{
		if (strcmp(pcb->contactArray[i].name, name) == 0)
		{
			return &(pcb->contactArray[i]);
		}

		if (strstr(pcb->contactArray[i].name, name))
		{
			return &(pcb->contactArray[i]);
		}//子串
	}

	return NULL;
}

void ContactDel(ContactBook* pcb, const char* name)
{
	for (int i = 0; i < pcb->size; ++i)
	{
		if (strcmp(pcb->contactArray[i].name, name) == 0)
		{
			memmove(pcb->contactArray + i, pcb->contactArray + i + 1, sizeof(Contact)*(pcb->size - (i + 1)));
			memset(pcb->contactArray + pcb->size - 1, 0, sizeof(Contact));//memmove覆盖
			break;
		}
	}
	pcb->size--;
}

void ContactUpdateTel(ContactBook* pcb, char* name, char* tel)
{
	Contact* pct = ContactSearch(pcb, name);
	if (pct == NULL)
	{
		printf("输入的人名不存在,无法更新\n");
	}

	strcpy(pct->tel, tel);
}

void ContactUpdateAge(ContactBook* pcb, char* name, short age)
{
	Contact* pct = ContactSearch(pcb, name);
	if (pct == NULL)
	{
		printf("输入的人名不存在,无法更新\n");
	}
	pct->age = age;
}

void ContactUpdateAddr(ContactBook* pcb, char* name, char* addr)
{
	Contact* pct = ContactSearch(pcb, name);
	if (pct == NULL)
	{
		printf("输入的人名不存在,无法更新\n");
	}
	strcmp(pct->addr, addr);
}

void ContactBookPrint(ContactBook* pcb)
{
	for (int i = 0; i < pcb->size; ++i)
	{
		printf("姓名：%s\n", pcb->contactArray[i].name);
		printf("年龄：%d\n", pcb->contactArray[i].age);
		printf("电话：%s\n", pcb->contactArray[i].tel);
		printf("地址：%s\n", pcb->contactArray[i].addr);
		printf("\n\n");
	}
}
void Sort_contact(ContactBook* pcb)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < pcb->size - 1; i++)
	{
		for (j = 0; j < pcb->size - 1 - i; j++)
		{
			if (strcmp(pcb->contactArray[j].name, pcb->contactArray[j + 1].name)>0);
			{
				Contact tmp = pcb->contactArray[j];
				pcb->contactArray[j] = pcb->contactArray[j + 1];
				pcb->contactArray[j + 1] = tmp; 
			}
		}
	}
}