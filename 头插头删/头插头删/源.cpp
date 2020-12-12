#define _CRT_SECURE_NO_WARNINGS 1
// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert（**pplist）；//判空
	int* newnode = (int*)malloc(sizeof(int));
	if (*pplist == NULL)//若无数组直接将头结点指向插入节点
	{
		*pplist = newnode;
	}
	else
	{
		newnode->next = *pplist;//将插入结点的next指向头结点
		*pplist = newnode;//此时插入的链表就为头结点将链表结点给头结点
	}
}
// 单链表头删
void SListPopFront(SListNode** pplist)
{
	SListNode* first = *pplist;
	if (*first==NULL)
	{
		free(*pplist);
	}
	else if (*first->next == NULL)
	{
		free(first);
		*pplist == NULL;
	}
	else if (*first->next != NULL)
	{
		SListNode* next = first->next;
		free(first);
		*pplist = SListNode* next
	}
}