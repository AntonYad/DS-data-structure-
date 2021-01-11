#define _CRT_SECURE_NO_WARNINGS 1
class Solution
{
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == NULL || pHead->next == NULL)
		{
			return pHead;
		}
		ListNode* prev = NULL;
		ListNode* cur = pHead;
		ListNode* next = pHead->next;
		while (next)
		{
			if (cur->val != next->val)
			{
				prev = cur;
				cur = next;
				next = next->next;
			}
			else
			{
				while (next&&cur->val == next->val)
				{
					next = next->next;
				}
				if (prev == NULL)
				{
					pHead = next;
				}
				else
				{
					prev->next = next;
				}
				while (cur != next)
				{
					ListNode* del = cur;
					cur = cur->next;
					free(del);
				}
				if (cur)
				{
					next = cur->next;
				}
			}
		}
		return pHead;
	}
};