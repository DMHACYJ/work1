#define CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int datatype;
typedef struct SingLeListNode {
	datatype _data;
	struct SingLeListNode* _next;
}SingLeListNode;

typedef struct SingLeList {
	SingLeListNode* _head;
}SingLeList;

void SingLeListInit(SingLeList* sl);
SingLeListNode* CreateNode(datatype x);
void SingLeListPushBack(SingLeList* sl, datatype x);
void SingLeListPrint(SingLeList* sl);
void SingLeListPopBack(SingLeList* sl);
void SingLeListPushFront(SingLeList* sl, datatype x);
void SingLeListPopFront(SingLeList* sl);
void SingLeListInsertAfter(SingLeListNode* pos, datatype x);
void SingLeListEraseAfter(SingLeListNode* pos);
