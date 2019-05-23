#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
int Power(int num, int power) { 
	if (power == 1) { 
		return num; 
	} 
	if (power % 2 == 0) { 
		return Power(num, power / 2) * Power(num, power / 2); 
	} 
	else { 
		return num * Power(num, power / 2) * Power(num, power / 2); 
	} 
}

int main() {
	printf("%d",Power(2,3));
	system("pause");
	return 0;
}