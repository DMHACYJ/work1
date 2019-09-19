#define CRT_SECURE_NO_WARININGS 1
#include"List.h"
#include<assert.h>

void ListInit(List* lst) {
	assert(lst);
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	lst->_head = newNode;
	lst->_head->_next = lst->_head;
	lst->_head->_prev = lst->_head;
	lst->_head->_data = NULL;
}

void ListPrint(List* lst) {
	assert(lst);
	ListNode*cur = lst->_head->_next;
	while (cur != lst->_head) {
		printf("%d->", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void ListPushBack(List* lst, Datatype x) {
	assert(lst);
	ListNode* tail;
	ListNode* newNode = CreateListNode(x);
	tail = lst->_head->_prev;

	tail->_next = newNode;
	newNode->_prev = tail;
	newNode->_next = lst->_head;
	lst->_head->_prev = newNode;
}

void ListPushFront(List* lst, Datatype x) {
	assert(lst);
	ListNode* next;
	ListNode* newNode = CreateListNode(x);
	next = lst->_head->_next;

	lst->_head->_next = newNode;
	newNode->_prev = lst->_head;
	newNode->_next = next;
	next->_prev = newNode;
}

void ListPopBack(List* lst) {
	assert(lst);
	if (lst->_head == lst->_head->_next)  return;
	ListNode* tail = lst->_head->_prev;
	ListNode* prev = tail->_prev;

	prev->_next = lst->_head;
	lst->_head->_prev = tail;
	free(tail);
	tail = NULL;
}

void ListPopFront(List* lst) {
	if (lst->_head == lst->_head->_next) return;
	ListNode* next = lst->_head->_next;
	ListNode* nextnext = lst->_head->_next->_next;

	lst->_head->_next = nextnext;
	nextnext->_prev = lst->_head;

	free(next);
	next = NULL;
}

void ListInsert(List* lst, ListNode* pos,Datatype x) {//指定节点的前面插入新的节点
	assert(lst&&pos);
	ListNode*prev = pos->_prev;
	ListNode* newNode = CreateListNode(x);
	newNode->_next = pos;
	pos->_prev = newNode;
	newNode->_prev = prev;
	prev->_next = newNode;
}

void ListErase(List* lst,ListNode* pos) {//删除任意位置节点
	assert(lst && pos);
	if (lst->_head == pos) return;
	ListNode* prev = pos->_prev;
	ListNode* next = pos->_next;

	prev->_next = next;
	next->_prev = prev;
	free(pos);
	pos = NULL;
}

void ListDestory(List* lst) {
	assert(lst);
	ListNode* cur = lst->_head->_next;
	while (cur != lst->_head) {
		ListNode*next = cur->_next;
		free(cur);
		cur = next;
	}
	free(lst->_head);
}

ListNode* CreateListNode(Datatype x) {
	ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
	newNode->_data = x;
	newNode->_next = newNode->_prev = NULL;
	return newNode;
}

int main() {
	List lst;
	ListInit(&lst);
	ListPushBack(&lst, 1);
	ListPushBack(&lst, 2);
	ListPushBack(&lst, 3);
	ListPushBack(&lst, 4);
	ListPushBack(&lst, 5);
	ListPrint(&lst);
	system("pause");
	return 0;
}