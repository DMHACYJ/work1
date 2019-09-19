#define CRT_SECURE_NO_WARININGS 1
#include<stdio.h>
#include<stdlib.h>
typedef int Datatype;
typedef struct ListNode {
	Datatype _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;

typedef struct List {
	ListNode* _head;
}List;

void ListInit(List* lst);
void ListDestroy(List* lst);
void ListPushBack(List* lst, Datatype x);
void ListPushFront(List* lst, Datatype x);
void ListPopBack(List* lst);
void ListPopFront(List* lst);
void ListInsert(List* lst, ListNode* pos, Datatype x);
void ListErase(List* lst, ListNode* pos);
ListNode* CreateListNode(Datatype x);
void ListPrint(List* lst);
