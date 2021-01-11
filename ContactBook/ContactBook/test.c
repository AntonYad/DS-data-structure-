#include "ContactBooke.h"
void Test1()
{
	ContactBook cb;
	ContactInit(&cb);
	Contact ct2 = { "杭哥", 30, "888888888", "西安" };
	Contact ct1 = { "A", 1, "7777777777", "科大楼" };
	ContactAdd(&cb, ct1);
	ContactAdd(&cb, ct2);
	/*char name[100];
	printf("请输入要查找人的名字:");
	scanf("%s", name);
	Contact* pct = ContactSearch(&cb, name);
	if (pct == NULL)
	{
		printf("无此联系人\n");
	}
	else
	{
		printf("姓名：%s\n", pct->name);
		printf("年龄：%d\n", pct->age);
		printf("电话：%s\n", pct->tel);
		printf("地址：%s\n", pct->addr);
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
	Contact ct1 = { "A", 1, "7777777777", "科大楼" };
	Contact ct2 = { "杭哥", 30, "888888888", "西安" };
	ContactAdd(&cb, ct1);
	ContactAdd(&cb, ct2);
	char name[NAME_MAX];
	int input;
	do{
		printf("********************************************\n");
		printf("1、添加联系人 2、查找联系人\n");
		printf("3、删除联系人 4、修改联系人\n");
		printf("5、展示通讯录 6、排序联系人\n");
		printf("0、退出\n");
		printf("请选择：");
		scanf("%d", &input);
		printf("********************************************\n");
		switch (input)
		{
		case ADD:
			printf("请依次输入姓名 年龄 电话号码 地址：\n");
			scanf("%s", &ct.name);
			scanf("%d", &ct.age);
			scanf("%s", &ct.tel);
			scanf("%s", &ct.addr);
			ContactAdd(&cb, ct);
			     break;
		case SEARCH:
			printf("请输入要查找人的名字:");
			scanf("%s", name);
			Contact* pct = ContactSearch(&cb, name);
			if (pct == NULL)
			{
				printf("无此联系人\n");
			}
			else
			{
				printf("姓名：%s\n", pct->name);
				printf("年龄：%d\n", pct->age);
				printf("电话：%s\n", pct->tel);
				printf("地址：%s\n", pct->addr);
			}
			break;
		case DEL:
			printf("请输入要删除人的名字:");
			scanf("%s", name);
			ContactDel(&cb, name);
			break;
		case UPDATE:
			printf("1、更新电话\n");
			printf("2、更新年龄\n");
			printf("3、更新地址\n");
			printf("请选择：");
			scanf("%d", &input);
			if (input == 1)
			{
				char name[NAME_MAX];
				char tel[TEL_MAX];
				printf("请输入你要更新名字及电话:\n");
				scanf("%s", name);
				scanf("%s", tel);
				ContactUpdateTel(&cb, name, tel);
			}
			if (input == 2)
			{
				char name[NAME_MAX];
				short age;
				printf("请输入你要更新名字及年龄：\n");
				scanf("%s", name);
				scanf("%d",&age);
				ContactUpdateAge(&cb, name, age);
			}
			if (input == 3)
			{
				char name[NAME_MAX];
				char addr[ADDR_MAX];
				printf("请输入你要更新名字及地址\n");
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
			printf("没有此选项，请重新选择\n");
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