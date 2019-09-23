#include "Stack.h"

void StackInit(Stack* st)
{
	assert(st);
	st->_a = NULL;
	st->_top = st->_capacity = 0;
}

void StackPush(Stack* st, DataType x)
{
	assert(st);
	if (st->_top == st->_capacity)
	{
		size_t newC = st->_capacity == 0 ? 10 : 2 * st->_capacity;
		st->_a = (DataType*)realloc(st->_a, newC * sizeof(st->_capacity));
		st->_capacity = newC;
	}
	st->_a[st->_top++]=x;
}

void StackPop(Stack* st)
{
	assert(st);
	if (st->_top)
		--st->_top;
}

DataType StackTop(Stack* st)
{
	assert(st);
	return st->_a[st->_top - 1];
}

int StackEmpty(Stack* st)
{
	assert(st);
	return st->_top == 0 ? 1 : 0;
}

void StackPrint(Stack* st)
{
	assert(st);
	while (StackEmpty(st) != 1)
	{
		printf("%d ", StackTop(st));
		StackPop(st);
	}
	printf("\n");
}

size_t StackSize(Stack* st)
{
	return st->_top;
}

void StackDestroy(Stack* sl) {
	assert(sl);
	if (sl->_a)
	{
		free(sl->_a);
		sl->_a = NULL;
		sl->_capacity = sl->_top = 0;
	}
}
//最小栈
MinStack* minStackCreate() {
	MinStack*  S;
	S = (MinStack*)malloc(sizeof(MinStack));
	StackInit(&S->normStack);
	StackInit(&S->minStack);
	return S;
}
void minStackPush(MinStack* obj, DataType x) {
	StackPush(&obj->normStack, x);
	if (!StackSize(&obj->normStack))  StackPush(&obj->minStack, x);
	else if (x <= StackTop(&obj->minStack)) StackPush(&obj->minStack, x);
}
void minStackPop(MinStack* obj) {
	if (!StackEmpty(&obj->normStack)) {
		if(StackTop(&obj->minStack)==StackTop(&obj->normStack))
			StackPop(&obj->minStack);
		StackPop(&obj->normStack);
	}
}
int minStackTop(MinStack* obj) {
	if (!StackEmpty(&obj->normStack)) return StackTop(&obj->normStack);
	return 0;
}
int minStackGetMin(MinStack* obj) {
	if (!StackEmpty(&obj->minStack)) return StackTop(&obj->minStack);
	return 0;
}
void  minStackFree(MinStack* obj) {
	StackDestroy(&obj->normStack);
	StackDestroy(&obj->minStack);
	free(obj);
}
//两个栈实现一个队列
void myQueueCreate(MyQueue *mq ) {
	StackInit(&mq->_pushSt);
	StackInit(&mq->_popSt);
}
void myQueuePush(MyQueue* obk, int x) {
	StackPush(&obk->_pushSt, x);
}
int myQueuePop(MyQueue* obk) {
	while (!StackEmpty(&obk->_pushSt)) {
		StackPush(&obk->_popSt, StackTop(&obk->_pushSt));
		StackPop(&obk->_pushSt);
	}
	int top = StackTop(&obk->_popSt);
	StackPop(&obk->_popSt);
	return top;
}
bool myQueueEmpty(MyQueue* obk) {
	return StackEmpty(&obk->_popSt) && StackEmpty(&obk->_pushSt);
}
void myQueuePeek(MyQueue* obk) {
	while (!myQueueEmpty(obk)) {
		int top = myQueuePop(obk);
		printf("%d ", top);
	}
}
void myQueueDestroy(MyQueue* obk) {
	StackDestroy(&obk->_popSt);
	StackDestroy(&obk->_pushSt);
	free(obk);
}

void test()
{
	MyQueue mq;
	myQueueCreate(&mq);
	myQueuePush(&mq, 1);
	myQueuePush(&mq, 2);
	myQueuePush(&mq, 3);
	myQueuePush(&mq, 4);
	myQueuePeek(&mq);
	myQueueDestroy(&mq);
}
int main()
{
	test();
	system("pause");
	return 0;
}