#define _CRT_SECURE_NO_WARNINGS 1
#define MAX_SIZE 200
#define NEW_SIZE 20
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct PersonInfo
{
	char name[100];
	char sex[10];
	char age[10];
	char phone[20];
	char address[200];
}PersonInfo;

typedef struct AddressBook
{
	PersonInfo* persons;
	int size;
	int capacity;  //容量
}AddressBook;

void Realloc(AddressBook* address_book)
{
	//1.用realloc
	address_book->capacity += NEW_SIZE;
	address_book->persons = (PersonInfo*)realloc(address_book->persons, address_book->capacity * sizeof(PersonInfo));

	////2.手动扩容
	//address_book->capacity += NEW_SIZE;
	////申请新的内存
	//PersonInfo* newpersons = (PersonInfo*)malloc(sizeof(PersonInfo) * address_book->capacity);
	////把原来的内容拷贝到新的内存空间中
	//memcpy(newpersons, address_book->persons, sizeof(PersonInfo) * address_book->size);
	////释放原来的内存
	//free(address_book->persons);
	////新的内存空间指向
	//address_book->persons = newpersons;
}

void Save(AddressBook* addr_book)
{
	FILE* fp = fopen("f:/通讯录.txt", "w");
	if (fp == NULL)
	{
		perror("打开文件失败!\n");
		return;
	}

	for (int i = 0; i < addr_book->size; i++)
	{
		fwrite(&addr_book->persons[i], sizeof(PersonInfo), 1, fp);
	}

	fclose(fp);
	printf("保存成功！\n");
}

void Load(AddressBook* addr_book)
{
	FILE* fp = fopen("f:/通讯录.txt", "r");
	if (fp == NULL)
	{
		perror("打开失败！\n");
		return;
	}

	PersonInfo tmp = { 0 };
	while (1)
	{
		int n = fread(&tmp, sizeof(PersonInfo), 1, fp);
		if (n < 1)
		{
			break;
		}

		if (addr_book->size >= addr_book->capacity)
		{
			Realloc(addr_book);
		}

		addr_book->persons[addr_book->size] = tmp;
		addr_book->size++;
	}
	fclose(fp);
}

void Init(AddressBook* addr)
{
	addr->persons = (PersonInfo*)malloc(sizeof(PersonInfo) * MAX_SIZE);
	addr->capacity = MAX_SIZE;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		strcpy(addr->persons[i].name, "");
		strcpy(addr->persons[i].sex, "");
		strcpy(addr->persons[i].age, "");
		strcpy(addr->persons[i].phone, "");
		strcpy(addr->persons[i].address, "");
	}

	addr->size = 0;
}

void Menu()
{
	printf("========================\n");
	printf("0.退出通讯录\n");
	printf("1.添加联系人\n");
	printf("2.删除联系人\n");
	printf("3.修改联系人\n");
	printf("4.查找联系人\n");
	printf("5.显示所有联系人\n");
	printf("6.清空所有联系人\n");
	printf("========================\n");
}

void Sort(AddressBook* address_book)
{
	for (int i = 1; i < address_book->size; i++)
	{
		for (int j = i; j > 0 ; j--)
		{
			if (strcmp(&address_book->persons[j], &address_book->persons[j - 1]) < 0)
			{
				PersonInfo tmp = { 0 };

				tmp = address_book->persons[j];
				address_book->persons[j] = address_book->persons[j - 1];
				address_book->persons[j - 1] = tmp;
			}
		}
	}
}

void Add(AddressBook* address_book)
{
	printf("新增联系人\n");

	if (address_book->size >= address_book->capacity)
	{
		//联系人满了，需要扩容
		Realloc(address_book);
	}

	PersonInfo* info = &address_book->persons[address_book->size];
	printf("输入联系人姓名：");
	scanf("%s", info->name);
	printf("输入联系人性别：");
	scanf("%s", info->sex);
	printf("输入联系人年龄：");
	scanf("%s", info->age);
	printf("输入联系人电话：");
	scanf("%s", info->phone);
	printf("输入联系人地址：");
	scanf("%s", info->address);

	address_book->size++;

	Sort(address_book);

	printf("新增联系人成功\n");
}

void Delete(AddressBook* address_book)
{
	int num = 0;

	printf("输入你想要删除的序号：");
	scanf("%d", &num);

	if (num < 1 || num > address_book->size)
	{
		printf("输入错误\n");
		return;
	}
	for (int i = 0; i < address_book->size; i++)
	{
		if (num == i + 1)
		{
			for (int j = i; j < address_book->size; j++)
			{
				address_book->persons[j] = address_book->persons[j + 1];
			}
		}
	}

	address_book->size--;
}

void Modify(AddressBook* address_book)
{
	int num = 0;

	if (address_book->size < 1)
	{
		printf("通讯录为空\n");
		return;
	}

	printf("输入你需要修改的序号：");
	scanf("%d", &num);

	if (num < 1 || num >= address_book->size)
	{
		printf("输入错误\n");
		return;
	}

	PersonInfo* info = &address_book->persons[num - 1];
	
	printf("请修改名字（*不修改）\n");
	char name[100] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "*") != 0)
	{
		strcpy(info->name, name);
	}

	printf("请修改性别（*不修改）\n");
	char sex[10] = { 0 };
	scanf("%s", sex);
	if (strcmp(sex, "*") != 0)
	{
		strcpy(info->sex, sex);
	}

	printf("请修改年龄（*不修改）\n");
	char age[10] = { 0 };
	scanf("%s", age);
	if (strcmp(age, "*") != 0)
	{
		strcpy(info->age, age);
	}

	printf("请修改电话（*不修改）\n");
	char phone[10] = { 0 };
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0)
	{
		strcpy(info->phone, phone);
	}

	printf("请修改地址（*不修改）\n");
	char address[10] = { 0 };
	scanf("%s", address);
	if (strcmp(address, "*") != 0)
	{
		strcpy(info->address, address);
	}
}

void Find(AddressBook* address_book)
{
	char name[100] = { 0 };

	printf("输入你想查找的名字：");
	scanf("%s", name);
	for (int i = 0; i < address_book->size; i++)
	{
		PersonInfo* info = &address_book->persons[i];
		if (strcmp(name, info->name) == 0)
		{
			printf("[%d] %s %s %s %s %s\n", i + 1, info->name, info->sex, info->age, info->phone, info->address);
		}
		else
		{
			printf("未查询到此人\n");
		}
	}
}

void Show(AddressBook* address_book)
{
	printf("全部联系人：\n");

	if (address_book->size == 0)
	{
		printf("空\n");
	}
	else
	{
		for (int i = 0; i < address_book->size; i++)
		{
			PersonInfo info = address_book->persons[i];
			printf("[%d] %s %s %s %s %s\n", i + 1, info.name, info.sex, info.age, info.phone, info.address);
		}
	}
}

void Clear(AddressBook* address_book)
{
	char choice[10] = { 0 };

	printf("您确定要清空吗？Y/N\n");
	scanf("%s", &choice);
	if (strcmp(choice, "Y") == 0)
	{
		address_book->size = 0;
	}
	else
	{
		return;
	}
}

int main()
{
	AddressBook address_book;

	Init(&address_book);
	Load(&address_book);

	typedef void(*Func)(AddressBook*);
	Func table[] = {
		NULL,
		Add,
		Delete,
		Modify,
		Find,
		Show,
		Clear,
	};

	while (1)
	{
		int choice = 0;
		Menu();
		printf("请选择:\n");
		scanf("%d", &choice);

		if (choice < 0 || choice >= sizeof(table) / sizeof(table[0]))
		{
			printf("输入有误，重新输入\n");
			continue;
		}
		if (choice == 0)
		{
			Save(&address_book);
			printf("退出\n");
			break;
		}

		table[choice](&address_book);
	}

	system("pause");
	return 0;
}