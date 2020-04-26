#define _CRT_SECURE_NO_WARNINGS 1
#include"parse.h"
#include"add.h"
#include"sub.h"
#include"mul.h"

#define IN 1
#define OUT 0

typedef int (FUNC)(int, int);

FUNC* p_fun = NULL;
char op;

struct expr_t
{
	FUNC* pFun;  // add(int, int);
	char* name;  // add sub
	char op;    // + -	
};
struct expr_t expr[] =
{
	{ add, "add", '+' },
	{ sub, "sub", '-' },
	{ mul, "mul", '*' },
	{ NULL, NULL, 0 }
};

void do_action(int argc, char* argv[])
{
	int left = atoi(argv[1]);    //������
	int right = atoi(argv[2]);   //��������

	int ret = p_fun(left, right);
	printf("%s%c%s=%d\n", argv[1], op, argv[2], ret);
}

void main_math(int argc, char* argv[])
{
	int i;

	p_fun = NULL;
	for (i = 0; ; i++)
	{
		if (expr[i].op == 0)
		{
			printf("%s�������\n", argv[0]);
			return;
		}
		if (strcmp(expr[i].name, argv[0]) == 0)
		{
			p_fun = expr[i].pFun;
			op = expr[i].op;
			break;
		}
	}

	do_action(argc, argv);
}

void parse(char* buf)
{
	int i;
	int argc = 0;
	char* argv[8] = { 0 };
	int flag = 0;

	for (i = 0; buf[i] != 0; i++)
	{
		//�ڵ������棬���ҵ�ǰλ�ò���
		if (flag == OUT && !isspace(buf[i]))
		{
			argv[argc++] = buf + i;
			flag = IN;
		}
		//��ȡ����ʱ�������ַ�������ǰ�ַ�����,��������ȡ
		if (flag == IN && isspace(buf[i]))
		{
			buf[i] = '\0';
			flag = OUT;
		}
	}

	main_math(argc, argv);
}
