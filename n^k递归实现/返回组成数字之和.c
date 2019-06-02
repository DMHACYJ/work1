#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int DigitSum(int n,int result) {
	if ((n % 10 != 0) && ((n /10) == 0)) {
		return result + n;
	}
	else if ((n /= 10) != 0 ) {
		result += n % 10;
		return DigitSum(n, result);
	}
}
int main() {
	int n = 0;
	int a = 0;
	int sum = 0;
	int result = 0;
	scanf("%d", &n);
	a = n;
	sum=DigitSum(n,result);
	while((a / 10) != 0) {
		a = a / 10;
	}
	printf("%d", sum-a);
	system("pause");
	return 0;
}