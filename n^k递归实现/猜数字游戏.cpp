#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
int main()
{
	srand((unsigned int)time(NULL));
	int r = rand() % 100;//�������λ����
	int n = -1;
	while (n != r)
	{
		while (!scanf("%d", &n))//��������ַ�scanf����ֵΪ0����getchar�Ե�
		{
			getchar();
		}
		if (n > r)
		{
			printf("�´���\n");
		}
		if (n < r)
		{
			printf("��С��\n");
		}
	}
	printf("�¶���\n");
	system("pause");
	return 0;
}