#include "SingLeList.h"
//无头单向非循环
void SingLeListInit(SingLeList* sl) {
	assert(sl);
	sl -> _head = NULL;
}

void SingLeListPrint(SingLeList* sl) {//打印
	assert(sl);
	SingLeListNode* cur = sl->_head;
	printf("%d", cur->_data);
	cur = cur->_next;
	while (cur) {
		printf("->%d", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void SingLeListPushFront(SingLeList* sl, datatype x) {//头插
	assert(sl);
	SingLeListNode* cur = sl->_head;
	SingLeListNode* newNode = CreateNode(x);
	newNode->_next = cur;
	sl->_head = newNode;
}

void SingLeListPopFront(SingLeList* sl) {//头删
	assert(sl);
	if (sl->_head == NULL) {
		return;
	}
	SingLeListNode* cur = sl->_head;
	SingLeListNode* next = sl->_head->_next;
	free(cur);
	cur = NULL;
	sl->_head = next;
}

void SingLeListPopBack(SingLeList* sl) {//尾删
	assert(sl);
	SingLeListNode* cur = sl->_head;
	if (cur == NULL) return;
	SingLeListNode* prev = NULL;
	while (cur->_next) {
		prev = cur;
		cur = cur->_next;
	}
	free(cur);
	cur = NULL;
	if (prev == NULL) {
		sl->_head = NULL;
	}
	else
		prev->_next = NULL;
}

void SingLeListPushBack(SingLeList* sl, datatype x) {//尾插
	assert(sl);
	if (sl -> _head == NULL) {
		sl->_head = CreateNode(x);
	} else {
		SingLeListNode* cur = sl->_head;
		while (cur->_next) {
			cur = cur->_next;
		}
		cur->_next = CreateNode(x);
	}
}

SingLeListNode* CreateNode(datatype x) {//开辟节点
	SingLeListNode* newnode = (SingLeListNode*)malloc(sizeof(SingLeListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	return newnode;
}

void SingLeListInsertAfter(SingLeListNode* pos, datatype x) {//指定节点的后面插
	assert(pos);
	SingLeListNode* newNode = CreateNode(x);
	SingLeListNode* next = pos->_next;
	pos->_next = newNode;
	newNode->_next = next;
}

void SingLeListEraseAfter(SingLeListNode* pos) {//删除指定位置的后一个节点
	assert(pos);
	SingLeListNode* next = pos->_next;
	if (next == NULL) {
		return;
	} else {
		SingLeListNode* next2 = next->_next;
		pos->_next = next2;
		free(next);
		next = NULL;
	}
}

void SingLeListRemove(SingLeList* sl, datatype x) {//删除指定数
	SingLeListNode* cur = sl->_head;
	SingLeListNode* prev=NULL;
	while (cur) {
		if (cur->_data == x) {
			if (prev == NULL) {
				sl->_head = cur->_next;
			}
			else {
				prev->_next = cur->_next;
			}
			free(cur);
			cur = NULL;
		}
		else {
			prev = cur;
			cur = cur->_next;
		}
	}
}

void SingLeListRemoveAll(SingLeList* sl, datatype* x) {//删除所有指定元素
	SingLeListNode* prev, *cur;
	SingLeListNode* head = sl->_head;
	if (head == NULL) {
		return;
	}
	prev = NULL;
	cur = head;
	while (cur) {
		if (cur->_data == x) {
			SingLeListNode* next = cur->_next;
			if (prev == NULL) {
				head = next;
			}
			else prev->_next = next;
			free(cur);
			cur = next;
		}
		else {
			prev = cur;
			cur = cur->_next;
		}
	}
}

void SingLeListDestroy(SingLeList* sl) {//销毁
	assert(sl);
	SingLeListNode* cur = sl->_head;
	while (cur) {
		SingLeListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	sl->_head = NULL;
}

SingLeListNode* SingLeListGetMid(SingLeList* sl) {//找到中间位置
	SingLeListNode* slow = sl->_head;
	SingLeListNode* fast = sl->_head;
	while (fast->_next) {
		slow = slow->_next;
		fast = fast->_next->_next;
	}
	return slow;
}

SingLeListNode* SingLeListGetBackk(SingLeList* sl,unsigned int k) {//找倒数第k个位置
	SingLeListNode* slow = sl->_head;
	SingLeListNode* fast = sl->_head;
	while (--k) {
		fast = fast->_next;
	}
	while (fast->_next) {
		slow = slow->_next;
		fast = fast->_next;
	}
	return slow;
}
int main() {
	SingLeList sl;
	SingLeListInit(&sl);
	SingLeListPushBack(&sl, 1);
	SingLeListPushBack(&sl, 2);
	SingLeListPushBack(&sl, 3);
	SingLeListPushBack(&sl, 4);
	SingLeListPushFront(&sl, 5);
	SingLeListInsertAfter(sl._head->_next->_next, 33);
	SingLeListPrint(&sl);
	SingLeListPopBack(&sl);
	SingLeListPopFront(&sl);
	SingLeListRemove(&sl, 33);
	SingLeListPrint(&sl);
	system("pause");
	return 0;
}
