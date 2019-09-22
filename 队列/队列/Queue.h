#define _CRT_SECURE_NO_WARININGS 1
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int Datatype;

typedef struct QueueNode {
	Datatype _data;
	struct QueueNode* _next;
}QueueNode;

typedef struct Queue {
	QueueNode* _front;
	QueueNode* _rear;
}Queue;

void QueueInit(Queue* q);
void QueueDestroy(Queue* q);
void QueuePush(Queue* q, Datatype x);
void QueuePop(Queue* q);
int QueueEmpty(Queue* q);