#include<stdio.h>
#define MUL(x, y) ((x) * (y))
#define M(x, y) (x * y)
#define Max 1000
#define S "บวบว"
#define MIN for(int i = 0; i < 3; i++){printf("hehe\n");}

int main() {
	int a = 1, b = 2, c;
	printf("%d\n", MUL(1 + 2, 1 + 2));
	printf("%d\n", M(1 + 2, 1 + 2));
	printf("%s\n", S);
	c = Max;
	printf("%d\n", c);
	MIN;
	return 0;
}