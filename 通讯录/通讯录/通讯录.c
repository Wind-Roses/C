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
	int capacity;  //����
}AddressBook;

void Realloc(AddressBook* address_book)
{
	//1.��realloc
	address_book->capacity += NEW_SIZE;
	address_book->persons = (PersonInfo*)realloc(address_book->persons, address_book->capacity * sizeof(PersonInfo));

	////2.�ֶ�����
	//address_book->capacity += NEW_SIZE;
	////�����µ��ڴ�
	//PersonInfo* newpersons = (PersonInfo*)malloc(sizeof(PersonInfo) * address_book->capacity);
	////��ԭ�������ݿ������µ��ڴ�ռ���
	//memcpy(newpersons, address_book->persons, sizeof(PersonInfo) * address_book->size);
	////�ͷ�ԭ�����ڴ�
	//free(address_book->persons);
	////�µ��ڴ�ռ�ָ��
	//address_book->persons = newpersons;
}

void Save(AddressBook* addr_book)
{
	FILE* fp = fopen("f:/ͨѶ¼.txt", "w");
	if (fp == NULL)
	{
		perror("���ļ�ʧ��!\n");
		return;
	}

	for (int i = 0; i < addr_book->size; i++)
	{
		fwrite(&addr_book->persons[i], sizeof(PersonInfo), 1, fp);
	}

	fclose(fp);
	printf("����ɹ���\n");
}

void Load(AddressBook* addr_book)
{
	FILE* fp = fopen("f:/ͨѶ¼.txt", "r");
	if (fp == NULL)
	{
		perror("��ʧ�ܣ�\n");
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
	printf("0.�˳�ͨѶ¼\n");
	printf("1.�����ϵ��\n");
	printf("2.ɾ����ϵ��\n");
	printf("3.�޸���ϵ��\n");
	printf("4.������ϵ��\n");
	printf("5.��ʾ������ϵ��\n");
	printf("6.���������ϵ��\n");
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
	printf("������ϵ��\n");

	if (address_book->size >= address_book->capacity)
	{
		//��ϵ�����ˣ���Ҫ����
		Realloc(address_book);
	}

	PersonInfo* info = &address_book->persons[address_book->size];
	printf("������ϵ��������");
	scanf("%s", info->name);
	printf("������ϵ���Ա�");
	scanf("%s", info->sex);
	printf("������ϵ�����䣺");
	scanf("%s", info->age);
	printf("������ϵ�˵绰��");
	scanf("%s", info->phone);
	printf("������ϵ�˵�ַ��");
	scanf("%s", info->address);

	address_book->size++;

	Sort(address_book);

	printf("������ϵ�˳ɹ�\n");
}

void Delete(AddressBook* address_book)
{
	int num = 0;

	printf("��������Ҫɾ������ţ�");
	scanf("%d", &num);

	if (num < 1 || num > address_book->size)
	{
		printf("�������\n");
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
		printf("ͨѶ¼Ϊ��\n");
		return;
	}

	printf("��������Ҫ�޸ĵ���ţ�");
	scanf("%d", &num);

	if (num < 1 || num >= address_book->size)
	{
		printf("�������\n");
		return;
	}

	PersonInfo* info = &address_book->persons[num - 1];
	
	printf("���޸����֣�*���޸ģ�\n");
	char name[100] = { 0 };
	scanf("%s", name);
	if (strcmp(name, "*") != 0)
	{
		strcpy(info->name, name);
	}

	printf("���޸��Ա�*���޸ģ�\n");
	char sex[10] = { 0 };
	scanf("%s", sex);
	if (strcmp(sex, "*") != 0)
	{
		strcpy(info->sex, sex);
	}

	printf("���޸����䣨*���޸ģ�\n");
	char age[10] = { 0 };
	scanf("%s", age);
	if (strcmp(age, "*") != 0)
	{
		strcpy(info->age, age);
	}

	printf("���޸ĵ绰��*���޸ģ�\n");
	char phone[10] = { 0 };
	scanf("%s", phone);
	if (strcmp(phone, "*") != 0)
	{
		strcpy(info->phone, phone);
	}

	printf("���޸ĵ�ַ��*���޸ģ�\n");
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

	printf("����������ҵ����֣�");
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
			printf("δ��ѯ������\n");
		}
	}
}

void Show(AddressBook* address_book)
{
	printf("ȫ����ϵ�ˣ�\n");

	if (address_book->size == 0)
	{
		printf("��\n");
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

	printf("��ȷ��Ҫ�����Y/N\n");
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
		printf("��ѡ��:\n");
		scanf("%d", &choice);

		if (choice < 0 || choice >= sizeof(table) / sizeof(table[0]))
		{
			printf("����������������\n");
			continue;
		}
		if (choice == 0)
		{
			Save(&address_book);
			printf("�˳�\n");
			break;
		}

		table[choice](&address_book);
	}

	system("pause");
	return 0;
}