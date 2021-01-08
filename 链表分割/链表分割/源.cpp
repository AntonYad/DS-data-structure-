#define _CRT_SECURE_NO_WARNINGS 1
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x)
	{
		//��Xλ�û���Ϊ���� С�ķ�һ�� ��ķ�һ��Ȼ������
		ListNode* lesshead, *lesstail, *greaterhead, *greatertail;
		ListNode* cur = pHead;
		lesshead = lesstail = (ListNode*)malloc(sizeof(ListNode*));//�ڱ�
		greaterhead = greatertail = (ListNode*)malloc(sizeof(ListNode*));
		lesstail->next = NULL;//��ֹ���ֵ
		greatertail->next = NULL;
		while (cur != NULL)//��ֹ����
		{
			if (cur->val<x)
			{
				lesstail->next = cur;//����ʱ��ֵ����С�ļ�����
				lesstail = cur;//Ȼ��β��ָ���ʱ��ֵ
			}
			else
			{
				greatertail->next = cur;
				greatertail = cur;
			}
			cur = cur->next;//���������ж�
		}
		lesstail->next = greaterhead->next;//������һ��
		greatertail->next = NULL;//�����һ����ΪNULL
		pHead = lesshead->next;//��ͷָ��ָ��С�ĵ�һ�����
		free(lesshead);
		free(greaterhead);
		return pHead;
	}
};