#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#include<assert.h>
#define NAME_SIZE 30

typedef struct student {
	char name[NAME_SIZE];
	int grade;
}Student;
typedef struct MailList {
	Student *data;
}MailList;
void InitMailList(MailList *ml) {
	int i;
	ml->data = (Student*)malloc(sizeof(Student)*20);
	
	printf("����20��ѧ����Ϣ,�������ɼ��ո����\n");
	for (i = 0; i < 20; i++)
	{
		scanf("%s %d", ml->data[i].name, &ml->data[i].grade);
	}

}



int menu() 
{
	int tmp, ret;
	printf("��ӭʹ��ѧ����Ϣ����ϵͳ\n");
	printf("=================================\n");
	printf("1.�����ɸߵ�������\n");
	printf("2.����������ѧ���ɼ�\n");
	printf("3.�óɼ�����ѧ������\n");
	printf("0.�˳�\n");
	printf("����Ҫ��������\n");
	ret = scanf("%d", &tmp);
	return ret ? tmp : -1;
}


void BubleSort(MailList* ml) {//ð������
	int i, j;
	Student temp;
	assert(ml != NULL);
	for (i = 0; i < 20; i++) 
	{
		for (j = 0; j < 19; j++) 
		{
			if (ml->data[j].grade < ml->data[j + 1].grade )
			{
				temp = ml->data[j];
				ml->data[j] = ml->data[j + 1];
				ml->data[j + 1] = temp;
			}
		}
	}
}

int FindMax(MailList* ml,int n)//ѡ��n�����λ�����ɼ���λ��
{
	int x=n;
	for (n; n < 19; n++)
	{
		if (ml->data[x].grade < ml->data[n + 1].grade)
		{
			x=n + 1;
		}
	}
	return x;
}
void StraightSort(MailList* ml)//ֱ������
{
	int i;
	int n=0;
	Student temp;
	for (i = 0; i < 19; i++)
	{
		n = FindMax(ml, i);
		temp = ml->data[i];
		ml->data[i] = ml->data[n];
		ml->data[n] = temp;
	}
}

void Show(MailList* ml) 
{
	int i;
	assert(ml != NULL);
	printf("%15s %4s\n", "����", "�ɼ�");
	for (i = 0; i < 20; i++) {
		printf("%15s %2d\n", ml->data[i].name, ml->data[i].grade);
	}
}
void FindName(MailList* ml, char name[NAME_SIZE])
{
	int i;
	for (i = 0; i < 20; i++)
	{
		if (strcmp(ml->data[i].name ,name)==0)
		{
			printf("%s�ķ���Ϊ%d\n", ml->data[i].name,ml->data[i].grade);
		}
	}
}
void FindGrade(MailList* ml, int grade)
{
	int i;
	for (i = 0; i < 20; i++)
	{
		if (ml->data[i].grade == grade)
		{
			printf("�ɼ�Ϊ%d��ѧ����%s\n", ml->data[i].grade,ml->data[i].name);
		}
	}
}
int main()
{
	int op;
	char name[NAME_SIZE];
	int grade;
	MailList ml;
	InitMailList(&ml);
	while(1)
	{
		op=menu();
		switch (op)
		{
		case 1:
			StraightSort(& ml);
			Show(&ml);
			break;
		case 2:
			printf("������Ҫ���ҵ�ѧ������\n");
			scanf("%s",name);
			FindName(&ml,name);
			break;
		case 3:
			printf("������Ҫ���ҵ�ѧ���ɼ�\n");
			scanf("%d", &grade);
			FindGrade(&ml,grade);
			break;
		case 0:
			printf("�˳�\n");
			free(ml.data);
			break;
		default:
			printf("�������ݲ����ڣ�����������\n");
			break;
		}
		printf("\n");
	} 
}