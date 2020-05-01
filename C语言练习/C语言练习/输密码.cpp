#include<stdio.h>
#include<Windows.h>

int main() {
	int i = 0;
	char passward[20] = { 0 };
	for (i = 0; i < 3; i++) {
		printf("请输入密码：");
		scanf("%s", passward);
		if (0 == strcmp(passward, "123456")) {
			break;
		}
		else {
			printf("输入错误，再次输入：");
		}
	}
	if (i < 3)
		printf("登录成功");
	else
		printf("退出程序");

	return 0;
}