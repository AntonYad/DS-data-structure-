#define _CRT_SECURE_NO_WARNINGS 1
// 链式结构：表示队列 
typedef int QDataType;
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// 队列的结构 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// 初始化队列 
void BuyQueque(QDataType x);
{
	QNode* cur = (QDataType*)malloc(sizeof(QDataType));
	cur->data = x;
	cur->next = NULL;
}
void QueueInit(Queue* q);
{
	q->front = NULL;
	q->rear = NULL;
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data);
{
	if (q->rear == NULL)
	{
		q->front = q->rear = cur;
	}
	q->rear->next = cur;
	cur = q->rear;
}
// 队头出队列 
void QueuePop(Queue* q);
{	
	QNode* tmp = q->front->next;
	printf("%d",front->data);
	free(front);
	q->front = tmp;
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q);
{
	return q->front->data;
}
// 获取队列队尾元素 
QDataType QueueBack(Queue* q);
{
	return q->rear->data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q);
{
	int count = 0;
	while (q -> front)
	{
		count++
		q->front = q->front->next;
	}
	return count;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q);
{
	return q->front == 0? 1 : 0;

}
// 销毁队列 
void QueueDestroy(Queue* q);
{
	while (q->front)
	{
		QListNode* tmp = q->front->next;
		free(front);
		q->front = tmp;
	}
}

