#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void reverse_string(char*start, char*end) {
	//同一个字符串里指针可以比较大小
	char tmp = *start;
	*start = *end;
	*end = tmp;
	if (start+1 <= end-1) {
		reverse_string(start + 1, end - 1);
	}
}
int myStrlen(char*str)
{
	if (*str == 0)
	{
		return 0;
	}
	return 1 + myStrlen(str + 1);
}
int main() {
	char str[10] = "bitekeji";
	printf("%d\n", myStrlen(str));
	reverse_string(str, str + strlen(str) - 1);
	puts(str);//自动打印回车
	system("pause");
	return 0;
}


