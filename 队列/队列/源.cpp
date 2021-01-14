#define _CRT_SECURE_NO_WARNINGS 1
// ��ʽ�ṹ����ʾ���� 
typedef int QDataType;
typedef struct QListNode
{
	struct QListNode* _next;
	QDataType _data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// ��ʼ������ 
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
// ��β����� 
void QueuePush(Queue* q, QDataType data);
{
	if (q->rear == NULL)
	{
		q->front = q->rear = cur;
	}
	q->rear->next = cur;
	cur = q->rear;
}
// ��ͷ������ 
void QueuePop(Queue* q);
{	
	QNode* tmp = q->front->next;
	printf("%d",front->data);
	free(front);
	q->front = tmp;
}
// ��ȡ����ͷ��Ԫ�� 
QDataType QueueFront(Queue* q);
{
	return q->front->data;
}
// ��ȡ���ж�βԪ�� 
QDataType QueueBack(Queue* q);
{
	return q->rear->data;
}
// ��ȡ��������ЧԪ�ظ��� 
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
// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);
{
	return q->front == 0? 1 : 0;

}
// ���ٶ��� 
void QueueDestroy(Queue* q);
{
	while (q->front)
	{
		QListNode* tmp = q->front->next;
		free(front);
		q->front = tmp;
	}
}

