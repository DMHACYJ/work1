#define _CRT_SECURE_NO_WARNINGS 1
#include<stdlib.h>
#include<stdio.h>
int mul(int n)
{
	if ( n== 0)
	{
		return 1;
	}
	return n*mul(n-1);
}
int PrintSum(int n)
{
	if (n == 0)
	{
		return 0;
	}
	PrintSum(n / 10);
	printf("%d", n % 10);
}
int main() {
	int n;
	scanf("%d", &n);
	printf("打印每一位：");
	PrintSum(n);
	printf("\n");
	printf("阶乘：%d",mul(n));
	system("pause");
	return 0;
}