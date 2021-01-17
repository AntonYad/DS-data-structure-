#define _CRT_SECURE_NO_WARNINGS 1
typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
//�½�������
ListNode* BuyListNode(LTDataType x)
{
	Listnode* cur = (ListNode*)malloc(sizeof(ListNode));
	cur->next = NULL;
	cur->prev = NULL;
	cur->data = x;
	return cur;
}

// �������������ͷ���.
ListNode* ListCreate();
{
	Listnode* node = (ListNode*)malloc(sizeof(ListNode));
	head->prev = head;
	head->next = head;
	head->data = NULL;
	return head;
}
// ˫������������ͷ���
void ListDestory(ListNode* pHead);
{
	ListNode* cur = pHead;
	while (cur != pHead)
	{
		ListNode* next = cur->next;
		free(cur);
		cur = cur->next;
	}
	return pHead;
}
// ˫�������ӡ
void ListPrint(ListNode* pHead);
{
	ListNode* cur = pHead->next;
	while (cur!=pHead)//ѭ������
	{
		printf("%d", pHead->data);
		pHead = pHead->next;
	}
}
// ˫������β��
void ListPushBack(ListNode* pHead, LTDataType x);
{
	ListNode* cur = BuyListNode(x);
	ListNode* tail = pHead->prev;
	tail->next = cur;
	cur->prev = tail;
	cur->next = pHead;
	pHead->prev = cur;
}
// ˫������βɾ
void ListPopBack(ListNode* pHead);
{
	ListNode* tail = pHead->prev;
	ListNode* tailprev = tail->prev;
	pHead->prev =tailprev;
	tailprev->next = pHead;
	free(tail);
	tail = tailprev;
}
// ˫������ͷ��
void ListPushFront(ListNode* pHead, LTDataType x);
{
	ListNode* newnode = BuyListNode(x);
	ListNode* next = pHead->next;
	pHead->next = newnode;
	newnode->next = next;
	newnode->prev = pHead;
	next->prev = newnode;
}
// ˫������ͷɾ
void ListPopFront(ListNode* pHead);
{
	ListNode* cur = pHead->next;
	if (cur == NULL)
	{
		return NULL;
	}
	ListNode* next = cur->next;
	pHead->next = next;
	next->prev = pHead;
	free(cur);
}
// ˫���������
ListNode* ListFind(ListNode* pHead, LTDataType x);
{
	ListNode* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->val == x)
		{
			return cur;
			break;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}
// ˫��������pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);
{
	ListNode* prev = pos->prev;
	ListNode* newnode = BuyListNode(x);
	newnode->next = pos;
	prev->next = newnode;
	newnode->prev = prev;
	pos->prev = newnode;
}
// ˫������ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);
{
	ListNode* next = pos->next;
	ListNode* prev = pos->prev;
	prev->next = next;
	next->prev = prev;
	free(pos);
}