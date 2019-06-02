#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int fib2(int n)
{
	if (n <= 2)
	{
		return 1;
	}
	return fib2(n - 1) + fib2(n - 2);
}
int main()
{
	int i = 1;
	int num = 0;
	scanf("%d", &num);
	for (i = 1; i <= num; i++) {
		printf("%d\n", fib2(i));
	}
	system("pause");
	return 0;
}