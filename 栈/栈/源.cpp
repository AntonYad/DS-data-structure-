#define _CRT_SECURE_NO_WARNINGS 1
// ֧�ֶ�̬������ջ
typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// ջ��
	int _capacity;  // ���� 
}Stack;
// ��ʼ��ջ 
void checkcapacity(Stack* ps)
{
	if (ps->size>=ps->_capacity)
	ps->capacity == 0 ? 4 : 2 * ps->capacity;
	ps->_a = (STDataType)realloc(ps->_a,sizeof(STDataType)*capacity)
}
void StackInit(Stack* ps);
{
	memset(&ps, 0, sizeof(ps->a));
	ps->top = 0;
	ps->capacity = 0;
}
// ��ջ 
void StackPush(Stack* ps, STDataType data);
{
	ps->[top++] = data;
}
// ��ջ 
void StackPop(Stack* ps);
{
	ps->top--;
}
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps);
{
	return ps->a[--top];
}
// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps);
{
	return ps->[top]
}
// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps);
{
	return top == 0 ? 0 : 1;
}
// ����ջ 
void StackDestroy(Stack* ps);
{
	free(ps->a)
	ps->top =ps-> capacity = 0;
}
