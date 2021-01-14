#define _CRT_SECURE_NO_WARNINGS 1
typedef struct {
	int a[1000];
	int front, rear;
} MyStack;


/** Initialize your data structure here. */


MyStack* myStackCreate() {
	MyStack *cur = (MyStack*)calloc(1, sizeof(MyStack));
	cur->front = 0;
	cur->rear = -1;
	return cur;
}


/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
	obj->a[++(obj->rear)] = x;
}


/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
	int x = obj->a[(obj->rear)--];
	return x;
}


/** Get the top element. */
int myStackTop(MyStack* obj) {
	return obj->a[obj->rear];
}


/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
	return obj->rear == -1;
}


void myStackFree(MyStack* obj) {
	free(obj);
}