#include "ContactBooke.h"
void Test1()
{
	ContactBook cb;
	ContactInit(&cb);
	Contact ct2 = { "����", 30, "888888888", "����" };
	Contact ct1 = { "A", 1, "7777777777", "�ƴ�¥" };
	ContactAdd(&cb, ct1);
	ContactAdd(&cb, ct2);
	/*char name[100];
	printf("������Ҫ�����˵�����:");
	scanf("%s", name);
	Contact* pct = ContactSearch(&cb, name);
	if (pct == NULL)
	{
		printf("�޴���ϵ��\n");
	}
	else
	{
		printf("������%s\n", pct->name);
		printf("���䣺%d\n", pct->age);
		printf("�绰��%s\n", pct->tel);
		printf("��ַ��%s\n", pct->addr);
	}*/
}
enum Option
{
	QUIT = 0,
	ADD,
	SEARCH,
	DEL,
	UPDATE,
	SHOW,
	SORT,
};
void ContackBookMenu()
{
	Contact ct;
	ContactBook cb;
	ContactInit(&cb);
	Contact ct1 = { "A", 1, "7777777777", "�ƴ�¥" };
	Contact ct2 = { "����", 30, "888888888", "����" };
	ContactAdd(&cb, ct1);
	ContactAdd(&cb, ct2);
	char name[NAME_MAX];
	int input;
	do{
		printf("********************************************\n");
		printf("1�������ϵ�� 2��������ϵ��\n");
		printf("3��ɾ����ϵ�� 4���޸���ϵ��\n");
		printf("5��չʾͨѶ¼ 6��������ϵ��\n");
		printf("0���˳�\n");
		printf("��ѡ��");
		scanf("%d", &input);
		printf("********************************************\n");
		switch (input)
		{
		case ADD:
			printf("�������������� ���� �绰���� ��ַ��\n");
			scanf("%s", &ct.name);
			scanf("%d", &ct.age);
			scanf("%s", &ct.tel);
			scanf("%s", &ct.addr);
			ContactAdd(&cb, ct);
			     break;
		case SEARCH:
			printf("������Ҫ�����˵�����:");
			scanf("%s", name);
			Contact* pct = ContactSearch(&cb, name);
			if (pct == NULL)
			{
				printf("�޴���ϵ��\n");
			}
			else
			{
				printf("������%s\n", pct->name);
				printf("���䣺%d\n", pct->age);
				printf("�绰��%s\n", pct->tel);
				printf("��ַ��%s\n", pct->addr);
			}
			break;
		case DEL:
			printf("������Ҫɾ���˵�����:");
			scanf("%s", name);
			ContactDel(&cb, name);
			break;
		case UPDATE:
			printf("1�����µ绰\n");
			printf("2����������\n");
			printf("3�����µ�ַ\n");
			printf("��ѡ��");
			scanf("%d", &input);
			if (input == 1)
			{
				char name[NAME_MAX];
				char tel[TEL_MAX];
				printf("��������Ҫ�������ּ��绰:\n");
				scanf("%s", name);
				scanf("%s", tel);
				ContactUpdateTel(&cb, name, tel);
			}
			if (input == 2)
			{
				char name[NAME_MAX];
				short age;
				printf("��������Ҫ�������ּ����䣺\n");
				scanf("%s", name);
				scanf("%d",&age);
				ContactUpdateAge(&cb, name, age);
			}
			if (input == 3)
			{
				char name[NAME_MAX];
				char addr[ADDR_MAX];
				printf("��������Ҫ�������ּ���ַ\n");
				scanf("%s", name);
				scanf("%s", addr);
				ContactUpdateAddr(&cb, name, addr);
			}
			break;
		case QUIT:
			break;
		case SHOW:
			ContactBookPrint(&cb);
			break;
		case SORT:
		    Sort_contact(&cb);
			break;
		default:
			printf("û�д�ѡ�������ѡ��\n");
			break;
		}
	} while (input != 0);
}
int main()
{
	//Test1();
	ContackBookMenu();
	return 0;
}