#define _CRT_SECURE_NO_WARNINGS 1
// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x)
{
	assert��**pplist����//�п�
	int* newnode = (int*)malloc(sizeof(int));
	if (*pplist == NULL)//��������ֱ�ӽ�ͷ���ָ�����ڵ�
	{
		*pplist = newnode;
	}
	else
	{
		newnode->next = *pplist;//���������nextָ��ͷ���
		*pplist = newnode;//��ʱ����������Ϊͷ��㽫�������ͷ���
	}
}
// ������ͷɾ
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