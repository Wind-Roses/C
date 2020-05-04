#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>

int main()
{
	//打开方式："r"读打开，"w"写打开（内容被写到文件开头），"a"追加打开（内容写到文件末尾）
	//FILE是结构体
	//打开失败，返回NULL
	FILE* fp = fopen("f:/test.txt", "r");
	if (fp == NULL)
	{

		//printf("文件打开失败! %s\n", strerror(errno));
		perror("打开文件失败！");
		system("pause");
		return 0;
	}

	//int c;
	
	//fgetc读一个字符，fputc写一个字符
	//fgets读一行,fputs写一行
	//stdin标准输入，stdout标准输出,stderr标准错误
	/*while ((c = fgetc(fp)) != EOF)
	{
		fputc(c, stdout);
	}*/

	//char buf[1024] = { 0 };

	////返回值为 NULL 表示读到了 EOF
	//while (fgets(buf, sizeof(buf) - 1, fp) != NULL)
	//{
	//	fputs(buf, stdout);
	//}

	//fread读取n个字节，fwrite写入n个字节
	char buf[1024] = { 0 };
	//返回值的含义表示实际读取到元素的个数
	int n = fread(buf, 1, sizeof(buf) - 1, fp);
	fwrite(buf, 1, strlen(buf), stdout);

	fclose(fp);

	system("pause");
	return 0;
}