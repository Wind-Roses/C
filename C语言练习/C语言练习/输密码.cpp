#include<stdio.h>
#include<Windows.h>

int main() {
	int i = 0;
	char passward[20] = { 0 };
	for (i = 0; i < 3; i++) {
		printf("���������룺");
		scanf("%s", passward);
		if (0 == strcmp(passward, "123456")) {
			break;
		}
		else {
			printf("��������ٴ����룺");
		}
	}
	if (i < 3)
		printf("��¼�ɹ�");
	else
		printf("�˳�����");

	return 0;
}