#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int exchange(int* a, int* b) {
	int tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
int main() {
	int a = 0;
	int b = 0;
	scanf("%d %d", &a, &b);
	printf("a = %d , b = %d\n", a, b);
	exchange(&a, &b);
	printf("a = %d , b = %d\n", a, b);
	system("pause");
	return 0;
}