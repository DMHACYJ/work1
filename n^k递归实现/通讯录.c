#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
#include<malloc.h>
enum menu {
	EXIT,
	ADD,
	DEL,
	MODIFY,//�޸�
	SEARCH,
	SORT,//pai��
	EMPTY,
	SHOW
};
#define NAME_SIZE 30
#define SEX_SIZE 5
#define ADDR_SIZE 20
#define TEL_SIZE 12
#define MAX 100
typedef struct student {
	char name[NAME_SIZE];
	char sex[SEX_SIZE];
	int age;
	char addr[ADDR_SIZE];
	char tel[TEL_SIZE];
}Student;
typedef struct MailList {
	//Student data[MAX];//student *data
	Student *data;
	int capacity;
	int size;
}MailList;
void menu() {
	printf("***********************************\n");
	printf("*****1.add                      2.del           *****\n"); 
	printf("*****3.modify                4.search      *****\n");
	printf("*****5.sort                     6.empty       *****\n");
	printf("*****7.show                   0.exit          *****\n");
	printf("***********************************\n");
}
void InitMailList(MailList *ml) {
	assert(ml != NULL);
	ml->capacity = MAX;
	ml->size = 0;
	ml->data = (Student*)malloc(sizeof(Student)*ml->capacity);
	memset(ml->data, 0, MAX * sizeof(Student));//���������ܵȺŸ�ֵ,��ֱ����calloc
}
int IncCapacity(MailList* ml) {
	Student *temp=NULL;
	assert(ml != NULL);
	ml->capacity = ml->capacity + MAX;
	temp = realloc(ml->data, sizeof(Student)*ml->capacity);
	if (temp != NULL) {
		ml->data = temp;
		return 1;
	}
	else
		return 0;
}
void AddMailListInfo(MailList* ml) {
	assert(ml != NULL);
	/*if (ml->size >= MAX) {
		printf("ͨѶ¼����\n");
		return;
	}*/
	if (ml->size >= ml->capacity&&IncCapacity(ml)) {
		printf("����");
		return;
	}
	
	printf("�������������Ա����䣬סַ���绰��\n");
	scanf("%s", ml->data[ml->size].name);
	scanf("%s", ml->data[ml->size].sex);
	scanf("%d", &ml->data[ml->size].age);//���鸳��ַ
	scanf("%s", ml->data[ml->size].addr);
	scanf("%s", ml->data[ml->size].tel);
	++ml->size;
}
void Show(MailList* ml) {
	int i;
	assert(ml != NULL);
	printf("%15s %5s %5s %10s %12s\n", "����", "�Ա�", "����", "סַ", "�绰");
	for (i = 0; i < ml->size;i++) {
		printf("%15s %5s %5d %10s %12s\n", ml->data[i].name, ml->data[i].sex, ml->data[i].age, ml->data[i].addr, ml->data[i].tel);
	}
}
void Sort(MailList* ml) {
	int i, j;
	Student temp;
	assert(ml != NULL);
	for (i = 0; i < ml->size; i++) {
		for (j = 0; j < ml->size - 1 - i; j++) {
			if (ml->data[j].name, ml->data[j + 1].name > 0) {//�ṹ�����ֱ�ӽ��������鲻��
				temp = ml->data[j];
				ml->data[j] = ml->data[j + 1];
				ml->data[j + 1] = temp;
			}
		}
	}
}
int FindName(MailList* ml,char* name) {
	int i;
	for (i = 0; i < ml->size; i++) {
		if (strcmp(ml->data[i].name, name)==0)
			return 1;
	}
	return 0;
}
int IsEmpty(MailList* ml) {
	return ml->size == 0 ? 1 : 0;
}
void DelMailListInfo(MailList* ml) {
	char name[NAME_SIZE];
	int i;
	assert(ml != NULL);
	if (IsEmpty(ml)) {
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	printf("������Ҫɾ��ѧ��������\n");
	scanf("%s", name);
	int n = FindName(ml, name);
	if (n == -1) 
		return;
	for (i = n; i < ml->size - 1; i++) {
		ml->data[i] = ml->data[i + 1];
	}
	ml->size--;
}
void SearchMailListInfo(MailList* ml,char* sex) {
	int i;

	
	printf("%15s %5s %5s %10s %12s\n", "����", "�Ա�", "����", "סַ", "�绰");
	for (i = 0; i < ml->size; i++) {
		if (strcmp(ml->data[i].sex, sex) == 0 ){
			printf("%15s %5s %5d %10s %12s\n", ml->data[i].name, ml->data[i].sex, ml->data[i].age, ml->data[i].addr, ml->data[i].tel);
		}
	}
}
void ModifyMailListInfo(MailList* ml) {
	char name[NAME_SIZE];
	assert(ml != NULL);
	if (IsEmpty(ml)) {
		printf("ͨѶ¼Ϊ��\n");
		return;
	}
	printf("������Ҫ�޸�ѧ��������\n");
	scanf("%s", name);
	int n = FindName(ml, name);
	if (n == -1)
		return;
	printf("�����µ��������Ա����䣬סַ���绰��\n");
	scanf("%s", ml->data[n].name);
	scanf("%s", ml->data[n].sex);
	scanf("%d", &ml->data[n].age);//���鸳��ַ
	scanf("%s", ml->data[n].addr);
	scanf("%s", ml->data[n].tel);
}
void Test() {
	int input;
	MailList ml;
	char sex[SEX_SIZE];
	InitMailList(&ml);
	//scanf("%d", &input);//scanf����int����������ַ�������ʾ������ֱ���˳���
	do {
		menu();
		printf("������Ҫʵ�ֵĹ��ܣ�\n");
		scanf("%d", &input);
		
		switch (input) {
		case 1:
			AddMailListInfo(&ml);
			break;
		case 2:
			DelMailListInfo(&ml);
			break;
		case 3:
			ModifyMailListInfo(&ml);
			break;
		case 4:
			printf("������Ҫ���ҵ��Ա�\n");
			scanf("%s",sex);
			SearchMailListInfo(&ml,sex);
			break;
		case 5:
			Sort(&ml);
			break;
		case 6:
			free(ml.data);
			InitMailList(&ml);
			//memset(ml.data,0, MAX *sizeof(Student));
			break;
		case 7:
			Show(&ml);
			break;
		case 0:
			printf("�˳�\n");
			break;
		default:
			printf("�������ݲ����ڣ�����������\n");
			break;
		}
	} while (input);
}
int main() {
	Test();
	system("pause");
	return 0;
}





////��̬�ڴ����(ָ��)
////ֻҪ���ǳ���Ա���ٵĿռ�Ͳ��Ƕ�̬��
////���Կ��ٵĹ̶��ռ������ջ�У�����Ա���ٵĶ�̬�ռ�洢�ڶ���
//const int n=10;//c����ֻ��������cpp���ǳ���
////�ڴ�й©
////Ұָ��
////int main() {
////	int* p = NULL;//���û�и�ֵ�����ÿգ�����Ұָ�롣��������ʱ��֪����ʲôֵ�����ÿ�
////	p = (int*)malloc(sizeof(int));
////	*p = 8;
////	printf("%d\n", *p);
////	free(p);//��p����ڴ滹�����Դ洢�ռ䣬������p���ǿ�ָ���ˡ������ͷŹ̶��ռ�
////	p = NULL;//���û���ÿգ�Ҳ��Ұָ�롣�����ͷź�����ÿ�
////	system("pause");
////	return 0;
////}
//
//int main() {
//	int *p = NULL;
//	int *q = NULL;
//	int i = 0;
//	p= (int*)malloc(sizeof(int)*N);
//	for (i = 0; i < N; i++) {
//		*(p + i) = i;
//	}
//	//ָ���������Ӽ���Ҫע�⵱ǰָ���λ�ã�Ҫ��סָ���׵�ַ
//	for (i = 0; i < N; i++) {
//		printf("%d", p[i]);
//	}
//	free( p);
//	q = (int*)malloc(sizeof(int)*N);
//	strcpy(q, "123456");
//	printf(q);//����
//	free(q);
//	return 0;
//}
////����û�г�ʼ���������
////ָ��û�г�ʼ����ֻ���ٿռ䣬δ��ֵ��������͡�Ҫmemset(p,0,100),100�ǳ���
//
//
////calloc��ʼ��     void* calloc (size_t num, size_t size)
////�����Ĺ�����Ϊ num ����СΪ size ��Ԫ�ؿ���һ��ռ䣬���Ұѿռ��ÿ���ֽڳ�ʼ��Ϊ0��
////�뺯�� malloc ������ֻ���� calloc ���ڷ��ص�ַ֮ǰ������Ŀռ��ÿ���ֽڳ�ʼ��Ϊȫ0��
//int main()
//{
//	int *p = calloc(10, sizeof(int));
//	if (NULL != p)
//	{
//		//ʹ�ÿռ�
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//void* realloc(void* ptr, size_t size);
//��ʱ�����Ƿ��ֹ�ȥ����Ŀռ�̫С�ˣ���ʱ�������ֻ��������Ŀռ�����ˣ���Ϊ�˺����ʱ���ڴ棬
//ptr ��Ҫ�������ڴ��ַ
//size ����֮���´�С
//����ֵΪ����֮����ڴ���ʼλ��
//�����������ԭ�ڴ�ռ��С�Ļ����ϣ����Ὣԭ���ڴ��е������ƶ��� �� �Ŀռ䡣

//������Ҫ����ָ��ջ�ռ��ָ��