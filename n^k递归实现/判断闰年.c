#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int run_nian(int num) {
	if ((num % 4 == 0 && num % 100 != 0) || num % 400 == 0)
		return 1;
	else
		return 0;
}
int main() {
	int num = 0;
	scanf("%d", &num);
	if (run_nian(num)) 
		printf("是闰年\n");
	else
		printf("不是闰年\n");
	system("pause");
	return 0;
}