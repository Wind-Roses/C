#include<stdio.h>
#include<string.h>
#include<Windows.h>

int main() {
	char arr1[] = { "I am superman!!!" };
	char arr2[] = { "################" };
	int left = 0;
	int right = strlen(arr1) - 1;

	while (left <= right) {
		arr2[left] = arr1[left];
		arr2[right] = arr1[right];
		printf("%s\n", arr2);
		Sleep(500);                 //0.5秒执行一次
		system("cls");              //清屏
		left++;
		right--;
	}

	return 0;
}