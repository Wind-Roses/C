#define _CRT_SECURE_NO_WARNINGS 1
#include"parse.h"

int main()
{
	char buf[512] = { 0 };

	while (1)
	{
		printf("¼ÆËãÆ÷£º");
		memset(buf, 0x00, sizeof(buf));
		scanf("%[^\n]%*c", buf);

		parse(buf);
	}

	return 0;
}