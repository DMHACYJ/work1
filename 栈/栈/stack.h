#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>
typedef int DataType;
typedef struct Stack
{
	DataType* _a;
	size_t _top;
	size_t _capacity;
}Stack;

typedef struct MinStack {
	Stack normStack;
	Stack minStack;
}MinStack;

typedef struct MyQueue {
	Stack _popSt;
	Stack _pushSt;
}MyQueue;