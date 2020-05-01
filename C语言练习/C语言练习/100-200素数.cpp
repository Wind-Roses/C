//#include<stdio.h>
//#include<math.h>
//
//int is_prime(int n) {
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++) {
//		if (n % j == 0)
//			return 0;
//	}
//	return 1;
//}
//
//int main() {
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++) {
//		if (1 == is_prime(i)) {
//			printf("%d\n", i);
//			count++;
//		}
//	}
//	printf("count = %d\n", count);
//
//	return 0;
//}


#include<stdio.h>

void Change(int *a, int *b)
{
	int *tmp;

	tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int a = 10, b = 20;
	int *pa = &a, *pb = &b;

	Change(pa, pb);
	printf("a = %d  b = %d", *pa, *pb);

	return 0;
}