#include "Queue.h"

void QueueInit(Queue* q) {
	assert(q);
	q->_front = NULL;
	q->_rear = NULL;
}

void QueuePush(Queue* q, Datatype x) {
	assert(q);

	QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
	newNode->_data = x;
	newNode->_next = NULL;

	if (q->_front == NULL) {
		q->_front = q->_rear = newNode;
	}
	else {
		q->_rear->_next = newNode;
		q->_rear = q->_rear->_next;
	}
}

void QueuePop(Queue* q) {
	assert(q);
	if (q->_front) {
		QueueNode* next = q->_front->_next;
		free(q->_front);
		q->_front = next;
		if (q->_front == NULL) 	q->_rear = NULL;
	}
}

Datatype QueueFront(Queue* q) {
	assert(q);
	return q->_front->_data;
}

Datatype QueueBack(Queue* q) {
	assert(q);
	return q->_rear->_data;
}

int QueueEmpty(Queue* q) {
	assert(q);
	if (q->_front==NULL) return 1;
	else return 0;
}

void QueueDestroy(Queue* q) {
	assert(q);
	QueueNode* cur = q->_front;
	while (cur) {
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	q->_front = q->_rear = NULL;
}

int QueueSize(Queue* q) {
	int n = 0;
	QueueNode* cur = q->_front;
	while (cur) {
		++n;
		cur = cur->_next;
	}
	return n;
}
void QueuePrint(Queue* q) {
	assert(q);
	QueueNode* cur = q->_front;
	while (cur) {
		printf("%d ", cur->_data);
		cur=cur->_next;
	}
	printf("\n");
}

void test() {
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePrint(&q);
	QueueDestroy(&q);
}

int main() {
	test();
	system("pause");
	return 0;
}
































