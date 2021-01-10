#define _CRT_SECURE_NO_WARNINGS 1
typedef struct  ListNode ListNode;
struct ListNode* insertionSortList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	ListNode* sorthead = head;
	ListNode* cur = head->next;
	sorthead->next = NULL;
	while (cur)
	{
		ListNode* next = cur->next;
		if (cur->val <= sorthead->val)
		{
			cur->next = sorthead;
			sorthead = cur;
		}
		else
		{
			ListNode* sortprev = sorthead;
			ListNode* sortcur = sortprev->next;
			while (sortcur)
			{
				if (cur->val <= sortcur->val)
				{
					sortprev->next = cur;
					cur->next = sortcur;
					break;
				}
				else
				{
					sortprev = sortcur;
					sortcur = sortcur->next;
				}
			}
			if (sortcur == NULL)
			{
				sortprev->next = cur;
				cur->next == NULL;
			}
		}
		cur = next;
	}
	return sorthead;
}