#define _CRT_SECURE_NO_WARNINGS 1
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k)
{
	//˼·��ָ������K��Ȼ�����ָ���������ֱ��fastָ��NULL����slow��λ��
	struct ListNode* fast = pListHead; //��������ָ��
	struct ListNode* slow = pListHead;
	while (k--)
	{
		if (fast == NULL)//���K�ĳ��ȴ���������
		{
			return NULL;
		}
		else//ָ����һ��
		{
			fast = fast->next;
		}
	}
	while (fast)//
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
	// write code here
}