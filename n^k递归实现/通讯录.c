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
	MODIFY,//修改
	SEARCH,
	SORT,//pai序
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
	memset(ml->data, 0, MAX * sizeof(Student));//数组名不能等号赋值,可直接用calloc
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
		printf("通讯录已满\n");
		return;
	}*/
	if (ml->size >= ml->capacity&&IncCapacity(ml)) {
		printf("已满");
		return;
	}
	
	printf("请输入姓名，性别，年龄，住址，电话：\n");
	scanf("%s", ml->data[ml->size].name);
	scanf("%s", ml->data[ml->size].sex);
	scanf("%d", &ml->data[ml->size].age);//数组赋地址
	scanf("%s", ml->data[ml->size].addr);
	scanf("%s", ml->data[ml->size].tel);
	++ml->size;
}
void Show(MailList* ml) {
	int i;
	assert(ml != NULL);
	printf("%15s %5s %5s %10s %12s\n", "姓名", "性别", "年龄", "住址", "电话");
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
			if (ml->data[j].name, ml->data[j + 1].name > 0) {//结构体可以直接交换，数组不行
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
		printf("通讯录为空\n");
		return;
	}
	printf("请输入要删除学生的姓名\n");
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

	
	printf("%15s %5s %5s %10s %12s\n", "姓名", "性别", "年龄", "住址", "电话");
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
		printf("通讯录为空\n");
		return;
	}
	printf("请输入要修改学生的姓名\n");
	scanf("%s", name);
	int n = FindName(ml, name);
	if (n == -1)
		return;
	printf("请输新的姓名，性别，年龄，住址，电话：\n");
	scanf("%s", ml->data[n].name);
	scanf("%s", ml->data[n].sex);
	scanf("%d", &ml->data[n].age);//数组赋地址
	scanf("%s", ml->data[n].addr);
	scanf("%s", ml->data[n].tel);
}
void Test() {
	int input;
	MailList ml;
	char sex[SEX_SIZE];
	InitMailList(&ml);
	//scanf("%d", &input);//scanf返回int，如果输入字符，不显示东西，直接退出来
	do {
		menu();
		printf("请输入要实现的功能：\n");
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
			printf("请输入要查找的性别：\n");
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
			printf("退出\n");
			break;
		default:
			printf("输入数据不存在，请重新输入\n");
			break;
		}
	} while (input);
}
int main() {
	Test();
	system("pause");
	return 0;
}





////动态内存分配(指针)
////只要不是程序员开辟的空间就不是动态的
////电脑开辟的固定空间存贮在栈中，程序员开辟的动态空间存储在堆中
//const int n=10;//c中是只读变量，cpp中是常量
////内存泄漏
////野指针
////int main() {
////	int* p = NULL;//如果没有赋值或者置空，则是野指针。所以声明时不知道赋什么值必须置空
////	p = (int*)malloc(sizeof(int));
////	*p = 8;
////	printf("%d\n", *p);
////	free(p);//把p这段内存还给电脑存储空间，不代表p就是空指针了。不能释放固定空间
////	p = NULL;//如果没有置空，也是野指针。所以释放后必须置空
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
//	//指针可以随意加减，要注意当前指针的位置，要记住指针首地址
//	for (i = 0; i < N; i++) {
//		printf("%d", p[i]);
//	}
//	free( p);
//	q = (int*)malloc(sizeof(int)*N);
//	strcpy(q, "123456");
//	printf(q);//可用
//	free(q);
//	return 0;
//}
////数组没有初始化，输出烫
////指针没有初始化（只开辟空间，未赋值），输出屯。要memset(p,0,100),100是长度
//
//
////calloc初始化     void* calloc (size_t num, size_t size)
////函数的功能是为 num 个大小为 size 的元素开辟一块空间，并且把空间的每个字节初始化为0。
////与函数 malloc 的区别只在于 calloc 会在返回地址之前把申请的空间的每个字节初始化为全0。
//int main()
//{
//	int *p = calloc(10, sizeof(int));
//	if (NULL != p)
//	{
//		//使用空间
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}

//void* realloc(void* ptr, size_t size);
//有时会我们发现过去申请的空间太小了，有时候我们又会觉得申请的空间过大了，那为了合理的时候内存，
//ptr 是要调整的内存地址
//size 调整之后新大小
//返回值为调整之后的内存起始位置
//这个函数调整原内存空间大小的基础上，还会将原来内存中的数据移动到 新 的空间。

//尽量不要返回指向栈空间的指针