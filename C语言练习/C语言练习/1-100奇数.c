#include<stdio.h>

int main() {
	int i = 0;

	/*for (i = 1; i <= 100; i++) {
		if (1 == i % 2)
			printf("%d\n", i);
	}*/

	for (i = 1; i <= 100; i += 2)
		printf("%d\n", i);

	return 0;
}